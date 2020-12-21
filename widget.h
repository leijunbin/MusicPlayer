#ifndef WIDGET_H
#define WIDGET_H

#include "headerfile.h"
#include "styleSheet.h"
#include "musicControl.h"
#include "sqlOperator.h"

QT_BEGIN_NAMESPACE
namespace Ui { class widget; }
QT_END_NAMESPACE

class widget : public QWidget
{
    Q_OBJECT

public:
    widget(QWidget *parent = nullptr);
    inline void init_else();//初始化其他项
    inline void init_tooltip();//初始化图标文字提示
    inline void init_action();//对相应按钮活动进行初始化
    inline void init_connect();//初始化按键连接
    inline void init_icon();//初始化界面图标样式

    void pushButtonStyle();
    void pushButtonStyle_1();
    void pushButtonStyle_2();
    void pushButtonStyle_3();
    void pushButtonStyle_4();

    void mouseMoveEvent(QMouseEvent *event);//拖拽 移动窗口
    void mouseReleaseEvent(QMouseEvent *event);//拖拽 移动窗口
    void mousePressEvent(QMouseEvent *event);//拖拽 移动窗口

    ~widget();

private slots:
    void on_pushButton_clicked();//最小化
    void on_pushButton_3_clicked();//关闭窗口
    void on_pushButton_4_clicked();//点击菜单
    void on_pushButton_9_clicked();//上一首
    void on_pushButton_10_clicked();//音乐暂停、播放
    void on_pushButton_11_clicked();//下一首
    void on_pushButton_12_clicked();//本地音乐
    void on_pushButton_13_clicked();//自我喜欢
    void on_pushButton_14_clicked();//我的收藏
    void on_pushButton_15_clicked();//历史记录
    void on_pushButton_17_clicked();//音量按键

    void on_listWidget_2_doubleClicked(const QModelIndex &index);//双击播放playlist_2本地音乐列表
    void on_listWidget_3_doubleClicked(const QModelIndex &index);//双击播放playlist_3本地音乐列表
    void on_listWidget_4_doubleClicked(const QModelIndex &index);//双击播放playlist_4本地音乐列表
    void on_listWidget_5_doubleClicked(const QModelIndex &index);//双击播放playlist_5本地音乐列表

    void action1_1_slot();//默认主题1
    void action1_2_slot();//默认主题2
    void action1_3_slot();//默认主题3
    void action1_4_slot();//自定义主题
    void action2_1_slot();//透明度加5%
    void action2_2_slot();//透明度减5%
    void action3_1_slot();//添加本地音乐
    void action3_2_solt();//添加我的收藏


    void updateLabel_3();//更新歌曲详情信息
    void updateDuration(qint64 duration);//更新音乐进度条
    void updatePosition(qint64 position);//更新音乐播放时间
    void updateListWidget_2(int value);//更新listWidget_2
    void updateListWidget_3(int value);//更新listWidget_3
    void updateListWidget_4(int value);//更新listWidget_4
    void updateListWidget_5(int value);//更新listWidget_5
    void updateVolume(int value);//更新音乐音量

private:
    Ui::widget *ui;

    QPoint offset;//点

    QAction *action1;//设置主题
    QAction *action1_1;//默认主题1
    QAction *action1_2;//默认主题2
    QAction *action1_3;//默认主题3
    QAction *action1_4;//自定义主题
    QAction *action2;//设置透明度
    QAction *action2_1;//透明度加5%
    QAction *action2_2;//透明度减5%
    QAction *action3;//添加音乐
    QAction *action3_1;//添加本地音乐
    QAction *action3_2;//添加我的收藏


    styleSheet_byslef* stylesheet;//设计样式
    musicControl* music;//音乐控制相关
    sqlOperator* sqloperator;//数据库控制相关

    double transparency;//透明度

    QVector<QString> currentFileName;//存储上次浏览地址

    void setPlayPauseIcon();//改变播放停止图标
};
#endif // WIDGET_H
