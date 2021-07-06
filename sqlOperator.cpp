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
    query.exec("select * from WallPaperData");
    query.first();
    return QString(query.value(0).toString());
}

QString sqlOperator::transparencyDate(){
    query.exec("select * from TransparencyData");
    query.first();
    return QString(query.value(0).toString());
}

QString sqlOperator::MusicData(int currentIndex,int falg){
    model->setTable(QString("%1").arg(sqldata[falg]));
    model->select();
    return QDir::toNativeSeparators(model->data(model->index(currentIndex,2)).toString());
}

QString sqlOperator::MusicName(int currentIndex, int falg){
    model->setTable(QString("%1").arg(sqldata[falg]));
    model->select();
    return model->data(model->index(currentIndex,1)).toString();
}

int sqlOperator::getMusicFalg(int currentIndex,int falg){
    model->setTable(QString("%1").arg(sqldata[falg]));
    model->select();
    return model->data(model->index(currentIndex,3)).toInt();
}

void sqlOperator::tempFuntion(){
    query.exec("select * from LocalMusic");
    query.exec(QString("insert into LocalMusic values (1,'放課後ティータイム - ふわふわ時間','D:/music/放課後ティータイム - ふわふわ時間.mp3',0)"));
}

void sqlOperator::setMusicFalg(int currentIndex,int falg,int list){
    QList<int> result1 = searchMusic(MusicName(currentIndex,list),1,2);
    QList<int> result2 = searchMusic(MusicName(currentIndex,list),3,2);
    QList<int> *result[3] = {NULL,&result1,&result2};

    for(int j=1;j<3;j++){
        int temp1 = (j==1)?1:3;
        query.exec(QString("select * from %1").arg(sqldata[temp1]));
        int size1 = result[j]->size();
        query.first();
        for(int i=0;i<size1;i++){
            int count = (*result[j])[i];
            int temp = 0;
            while(temp<count){
                query.next();
                temp++;
            }
            int id = query.value(0).toInt();
            query.exec(QString("update %3 set falg = %1 where id = %2").arg(falg).arg(id).arg(sqldata[temp1]));
        }
    }
}

void sqlOperator::clearMusicFalg(){
    for(int i=1;i<4;i++){
        query.exec(QString("select * from %1").arg(sqldata[i]));
        query.exec(QString("update %1 set falg = 0").arg(sqldata[i]));
    }
}

QList<int> sqlOperator::searchMusic(QString Name, int falg, int funtions){
    QSqlQuery query;
    query.exec(QString("select * from %1").arg(sqldata[falg]));
    QList<int> searchResult;
    int count = 0;
    std::string name = Name.toStdString();
    while(query.next()){
        QString name_query = query.value(1).toString();
        std::string name_query_s = name_query.toStdString();
        const char *name2 = name.c_str();
        const char *name_query_s2 = name_query_s.c_str();
        if(funtions==1&&strstr(name2,name_query_s2)){
            qDebug()<<1;
            searchResult.push_back(count);
        }
        else if(funtions==2&&!strcmp(name2,name_query_s2)){
            searchResult.push_back(count);
        }
        count++;
    }
    return searchResult;
}
