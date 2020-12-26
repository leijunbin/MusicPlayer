#ifndef STYLESHEET_H
#define STYLESHEET_H

#include "headerfile.h"

class styleSheet_byslef
{
public:
    styleSheet_byslef() = default;
    QString MenuStyle();//菜单样式
    QString PauseStyle();//音乐暂停时按钮样式
    QString PlayStyle();//音乐开始时按钮样式
    QString VoiceStyle();//音乐音量样式
    QString NoVoiceStyle();//音乐无音量样式
    QString listWidgetStyle();//滚动条样式

    QString HideListStyle();//隐藏按键按钮样式
    QString ShowListStyle();//显示按键按钮样式

    QString RandomStyle();//随机循环样式
    QString LoopStyle();//顺序循环样式
    QString LoopOneStyle();//单曲循环样式

    QString ButtonStyle();//按键样式
    QString ProgressDialogStyle();//进度条样式

    QString LikeMusicStyle();//喜欢音乐图标样式
    QString NoLikeMusicStyle();//不喜欢音乐图标样式

    QString pushButton_12_normalStyle();//我的音乐正常样式
    QString pushButton_12_hoverStyle();//我的音乐高亮样式

    QString pushButton_13_normalStyle();//我的喜欢正常样式
    QString pushButton_13_hoverStyle();//我的喜欢高亮样式

    QString pushButton_14_normalStyle();//我的收藏正常样式
    QString pushButton_14_hoverStyle();//我的收藏高亮样式

    QString pushButton_15_normalStyle();//历史记录正常样式
    QString pushButton_15_hoverStyle();//历史记录高亮样式
};

#endif // STYLESHEET_H
