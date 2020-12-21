#include "headerfile.h"
#include "sqlOperator.h"

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

void sqlOperator::tempFuntion(){
    query.exec("select * from LocalMusic");
    query.exec(QString("insert into LocalMusic values (1,'放課後ティータイム - ふわふわ時間','D:/music/放課後ティータイム - ふわふわ時間.mp3',0)"));
}
