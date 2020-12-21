#ifndef SQLOPERATOR_H
#define SQLOPERATOR_H

#include "headerfile.h"

class sqlOperator
{
public:
    sqlOperator() = default;
    void saveWallPaperData(QString& dataPath);//储存壁纸
    void saveTransparencyData(double& data);//储存透明度
    QString wallPaperDate();//返回壁纸地址
    QString transparencyDate();//返回透明度数据

    void tempFuntion();

private:
    QSqlQuery query;
};

#endif // SQLOPERATOR_H
