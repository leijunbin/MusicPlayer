#ifndef CONNECTION_H
#define CONNECTION_H

#include "headerfile.h"

static bool CreatConnection(){
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("mymusic.db");
    if(!db.open()){
        return false;
    }
    QSqlQuery query;
    query.exec(QString("create table LocalMusic (id int,MusicName varchar,FileName varchar,falg int,primary key(id,MusicName,FileName))"));//本地音乐数据列表
    query.exec(QString("create table LikeMusic (id int,MusicName varchar,FileName varchar,falg int,primary key(id,MusicName,FileName))"));//我的喜欢数据列表
    query.exec(QString("create table CollectMusic (id int,MusicName varchar,FileName varchar,falg int,primary key(id,MusicName,FileName))"));//我的收藏数据列表
    query.exec(QString("create table WallpaperData(FileName varchar primary key)"));
    query.exec(QString("create table TransparencyData(double primary key)"));
    return true;
}

#endif // CONNECTION_H
