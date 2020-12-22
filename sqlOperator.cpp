#include "headerfile.h"
#include "sqlOperator.h"

sqlOperator::sqlOperator(){
    model = new QSqlTableModel;
}

void sqlOperator::saveWallPaperData(QString& dataPath){
    query.exec("select * from WallpaperData");
    query.exec(QString("delete from WallpaperData"));
    query.exec(QString("insert into WallpaperData values('%1')").arg(dataPath));
}

void sqlOperator::saveTransparencyData(double &data){
    query.exec("select * from TransparencyData");
    query.exec(QString("delete from TransparencyData"));
    query.exec(QString("insert into TransparencyData values(%1)").arg(data));
}

QString sqlOperator::wallPaperDate(){
    query.exec("select * from TransparencyData");
    query.next();
    return QString(query.value(0).toString());
}

QString sqlOperator::transparencyDate(){
    query.exec("select * from WallpaperData");
    query.next();
    return QString(query.value(0).toString());
}

QString sqlOperator::MusicData(int currentIndex,int falg){
    if(falg==1)
        model->setTable("LocalMusic");
    else if(falg==2)
        model->setTable("LikeMusic");
    else if(falg==3)
        model->setTable("CollectMusic");
    model->select();
    return QDir::toNativeSeparators(model->data(model->index(currentIndex,2)).toString());
}

QString sqlOperator::MusicName(int currentIndex, int falg){
    if(falg==1)
        model->setTable("LocalMusic");
    else if(falg==2)
        model->setTable("LikeMusic");
    else if(falg==3)
        model->setTable("CollectMusic");
    model->select();
    return model->data(model->index(currentIndex,1)).toString();
}

int sqlOperator::getMusicFalg(int currentIndex,int falg){
    if(falg==1)
        model->setTable("LocalMusic");
    else if(falg==2)
        model->setTable("LikeMusic");
    else if(falg==3)
        model->setTable("CollectMusic");
    model->select();
    return model->data(model->index(currentIndex,3)).toInt();
}

void sqlOperator::tempFuntion(){
    query.exec("select * from LocalMusic");
    query.exec(QString("insert into LocalMusic values (1,'放課後ティータイム - ふわふわ時間','D:/music/放課後ティータイム - ふわふわ時間.mp3',0)"));
}

void sqlOperator::setMusicFalg(int currentIndex,int falg){
    QList<int> result1 = searchMusic(MusicName(currentIndex,1),1);
    QList<int> result2 = searchMusic(MusicName(currentIndex,1),3);

    query.exec("select * from LocalMusic");
    int size1 = result1.size();
    for(int i=0;i<size1;i++){
        int count = result1[i];
        int temp = 0;
        while(temp<count){
            query.next();
            temp++;
        }
        query.exec(QString("update LocalMusic set falg = %1").arg(falg));
    }

    query.exec("select * from CollectMusic");
    int size2 = result2.size();
    for(int i=0;i<size2;i++){
        int count = result1[i];
        int temp = 0;
        while(temp<count){
            query.next();
            temp++;
        }
        query.exec(QString("update LocalMusic set falg = %1").arg(falg));
    }
}

QList<int> sqlOperator::searchMusic(QString Name, int falg){
    QSqlQuery query;
    switch(falg){
        case 1:
            query.exec(QString("select * from LocalMusic"));
            break;
        case 2:
            query.exec(QString("select * from LikeMusic"));
            break;
        case 3:
            query.exec(QString("select * from CollectMusic"));
    }
    QList<int> searchResult;
    int count = 0;
    std::string name = Name.toStdString();
    while(query.next()){
        QString name_query = query.value(1).toString();
        std::string name_query_s = name_query.toStdString();
        const char *name2 = name.c_str();
        const char *name_query_s2 = name_query_s.c_str();
        if(strstr(name2,name_query_s2)){
            searchResult.push_back(count);
        }
        count++;
    }
    return searchResult;
}

QList<int> sqlOperator::equalMusic(QString Name, int falg){
    QSqlQuery query;
    switch(falg){
        case 1:
            query.exec(QString("select * from LocalMusic"));
            break;
        case 2:
            query.exec(QString("select * from LikeMusic"));
            break;
        case 3:
            query.exec(QString("select * from CollectMusic"));
    }
    QList<int> searchResult;
    int count = 0;
    std::string name = Name.toStdString();
    while(query.next()){
        QString name_query = query.value(1).toString();
        std::string name_query_s = name_query.toStdString();
        const char *name2 = name.c_str();
        const char *name_query_s2 = name_query_s.c_str();
        if(!strcmp(name2,name_query_s2)){
            searchResult.push_back(count);
        }
        count++;
    }
    return searchResult;
}

