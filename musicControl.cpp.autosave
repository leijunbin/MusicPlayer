#include "musicControl.h"
#include "headerfile.h"

void musicControl::setSqlIndex(QSqlQuery* query,int &falg){
    switch(falg){
        case 1:
            query->exec(QString("select * from LocalMusic"));
            break;
        case 2:
            query->exec(QString("select * from LikeMusic"));
            break;
        case 3:
            query->exec(QString("select * from CollectMusic"));
    }
}

QMediaPlaylist* musicControl::setNowPlaylist(int falg){
    switch (falg){
        case 1:
            return playlist_localMusic;
        case 2:
            return playlist_likeMusic;
        case 3:
            return playlist_collectMusic;
        case 4:
            return playlist_historyMusic;
    }
    return NULL;
}

int musicControl::getPlayBackMode(QMediaPlaylist* temp){
    if(temp->playbackMode()==QMediaPlaylist::Random)
        return 1;
    return 0;
}

musicControl::musicControl(){
    music = new QMediaPlayer;

    playlist_localMusic = new QMediaPlaylist;
    playlist_likeMusic = new QMediaPlaylist;
    playlist_collectMusic = new QMediaPlaylist;
    playlist_historyMusic = new QMediaPlaylist;

    sqloperator = new sqlOperator;
}

QString musicControl::normalizeTime(qint64 time){
    qint64 second = time/1000;
    qint64 minutes = second/60;
    qint64 seconds = second-minutes*60;
    return QStringLiteral("%1:%2").arg(minutes, 2, 10, QLatin1Char('0')).arg(seconds, 2, 10, QLatin1Char('0'));
}

void musicControl::init_playList(int falg){
    QSqlQuery query;
    setSqlIndex(&query,falg);
    while(query.next()){
        QString fileName=QDir::toNativeSeparators(query.value(2).toString());
        setNowPlaylist(falg)->addMedia(QUrl::fromLocalFile(fileName));
    }
    music->setPlaylist(playlist_localMusic);
}

QString musicControl::getNowMusicPosition(){
    return normalizeTime(music->position());
}

QString musicControl::getTotalMusicPosition(){
    return normalizeTime(music->duration());
}

QString musicControl::musicData(){
    QString info;
    info=("正在播放: ");
    if(music->isMetaDataAvailable()){
        QString title=music->metaData(QStringLiteral("Title")).toString();
        if(!title.isEmpty()){
            info+=title;
        }
        else{
            info+=("未知歌曲");
        }
        info+='-';
        QString author=music->metaData(QStringLiteral("Author")).toString();
        if(!author.isEmpty())
            info+=author;
        else
            info+=("未知作者");
    }
    return info;
}

bool musicControl::musicState(){
    if(music->state()==QMediaPlayer::PlayingState)
        return true;
    else
        return false;
}

void musicControl::musicPlay(){
    music->play();
}

void musicControl::musicPause(){
    music->pause();
}

int musicControl::musicLastNext(int dir){
    int falg = getMusicList();
    int currentIndex;
    int row = getMusicCount(falg);
    if(getPlayBackMode(setNowPlaylist(falg))==1){
        currentIndex = qrand() % row;
    }
    else{
        currentIndex = setNowPlaylist(falg)->currentIndex();
        if(dir==1){
            currentIndex--;
            if(currentIndex<0)
                currentIndex = row - 1;
        }
        else{
            currentIndex++;
            if(currentIndex==row)
                currentIndex = 0;
        }
    }
    setNowPlaylist(falg)->setCurrentIndex(currentIndex);
    return currentIndex;
}

void musicControl::clearAllMusic(int falg){
    QSqlQuery query;
    setSqlIndex(&query,falg);
    if(falg==1)
        query.exec("delete from LocalMusic");
    else if(falg==2)
        query.exec("delete from LikeMusic");
    else if(falg==3)
        query.exec("delete from CollectMusic");
    setNowPlaylist(falg)->clear();
}

void musicControl::addLocalMusic(QString& path){
    QSqlQuery query;
    QString file1 = path.split("\\").last();
    QString name = file1.remove(".mp3");

    int id = qrand()%100000;

    query.exec("select * form LocalMusic");
    query.exec(QString("insert into LocalMusic values (%1,'%2','%3',%4)").arg(id).arg(name).arg(path).arg(0));
    playlist_localMusic->addMedia(QUrl::fromLocalFile(path));
}

void musicControl::addCollectMusic(QString& path){
    QSqlQuery query;
    QString file1 = path.split("\\").last();
    QString name = file1.remove(".mp3");

    int id = qrand()%100000;

    query.exec("select * form CollectMusic");
    query.exec(QString("insert into CollectMusic values (%1,'%2','%3',%4)").arg(id).arg(name).arg(path).arg(0));
    playlist_collectMusic->addMedia(QUrl::fromLocalFile(path));
}

void musicControl::addLikeMusic(int currentIndex,int falg){
    QSqlQuery query;

    QString name = sqloperator->MusicName(currentIndex,falg);
    QString path = sqloperator->MusicData(currentIndex,falg);

    int id = qrand()%100000;

    query.exec("select * form LikeMusic");
    query.exec(QString("insert into LikeMusic values (%1,'%2','%3',%4)").arg(id).arg(name).arg(path).arg(1));
    playlist_likeMusic->addMedia(QUrl::fromLocalFile(path));
}

void musicControl::setPlaylist(int falg){
    music->setPlaylist(setNowPlaylist(falg));
}

void musicControl::setPlaylistIndex(int currentIndex,int falg){
    setNowPlaylist(falg)->setCurrentIndex(currentIndex);
}

void musicControl::setVolume(int value){
    music->setVolume(value);
}

void musicControl::setPlaylistMode(int falg){
    for(int i=1;i<5;i++){
        switch (falg) {
            case 1:
                setNowPlaylist(i)->setPlaybackMode(QMediaPlaylist::Loop);
                break;
            case 2:
                setNowPlaylist(i)->setPlaybackMode(QMediaPlaylist::Random);
                break;
            case 3:
                setNowPlaylist(i)->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
        }
    }
}

int musicControl::getMusicList(){
    if(music->playlist()==playlist_localMusic)
        return 1;
    else if(music->playlist()==playlist_likeMusic)
        return 2;
    else if(music->playlist()==playlist_collectMusic)
        return 3;
    else
        return 4;
}

int musicControl::getMusicCurrentIndex(){
    return setNowPlaylist(getMusicList())->currentIndex();;
}

const QMediaPlayer* musicControl::getMusicProgress()const{
   return music;
}

QMediaPlaylist* musicControl::getMusicProgressList(int falg){
    return setNowPlaylist(falg);
}

int musicControl::getMusicCount(int falg){
    if(falg>0&&falg<4)
        return setNowPlaylist(falg)->mediaCount();
    else
        return -1;
}

QString musicControl::getMusicName(int falg, int &currentIndex){
    QSqlQuery query;
    setSqlIndex(&query,falg);
    QString info;
    for(int i = 0;i < currentIndex + 1;i++){
        query.next();
    }
    info = query.value(1).toString();
    return info;
}
