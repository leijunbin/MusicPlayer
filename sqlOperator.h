#ifndef SQLOPERATOR_H
#define SQLOPERATOR_H

#include "headerfile.h"

class sqlOperator
{
public:
    sqlOperator();
    void saveWallPaperData(QString& dataPath);//储存壁纸
    void saveTransparencyData(double& data);//储存透明度
    QString wallPaperDate();//返回壁纸地址
    QString transparencyDate();//返回透明度数据

    QString MusicData(int currentIndex,int falg);//返回音乐地址
    QString MusicName(int currentIndex,int falg);//放回音乐名字
    int getMusicFalg(int currentIndex,int falg);//得到音乐是否喜欢

    QList<int> searchMusic(QString Name,int falg,int funtions);//按照歌曲名字在数据库中搜索

    void setMusicFalg(int currentIndex,int falg,int list);//设置歌曲标记
    void clearMusicFalg();//重置歌曲标记

    void tempFuntion();


private:
    QSqlQuery query;
    QSqlTableModel *model;
    QString sqldata[4]={"", "LocalMusic","LikeMusic","CollectMusic"};
};

#endif // SQLOPERATOR_H


