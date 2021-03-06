#include "headerfile.h"
#include "styleSheet.h"
#include "musicControl.h"
#include "sqlOperator.h"
#include "widget.h"
#include "ui_widget.h"

void widget::setPlayPauseIcon(){
    if(music->musicState()){//判断音乐正在播放状态
        ui->pushButton_10->setIcon(QIcon(":/image/image/image_normal/pause.png"));
        ui->pushButton_10->setStyleSheet(stylesheet->PauseStyle());
        ui->pushButton_10->setToolTip("播放");
        music->musicPause();//音乐暂停
    }
    else{
        ui->pushButton_10->setIcon(QIcon(":/image/image/image_normal/play.png"));
        ui->pushButton_10->setStyleSheet(stylesheet->PlayStyle());
        ui->pushButton_10->setToolTip("暂停");
        music->musicPlay();//音乐播放
    }
}

void widget::setQProgressDialogLoadingMusic(QProgressDialog *progressdialog,QPushButton *button,int size){
    progressdialog->setWindowModality(Qt::WindowModal);//强制锁定用户交互界面
    progressdialog->resize(400,120);
    progressdialog->setMinimumSize(400,120);
    progressdialog->setMaximumSize(400,120);
    progressdialog->setMinimumDuration(100);
    progressdialog->setWindowTitle(("添加歌曲"));
    progressdialog->setLabelText(("正在添加，请稍后."));

    button->setStyleSheet(stylesheet->ButtonStyle());
    button->setText(("关闭"));

    progressdialog->setCancelButton(button);
    progressdialog->setRange(0,size-1);
    progressdialog->setStyleSheet(stylesheet->ProgressDialogStyle());
}

void widget::setLikeMusicicon(int falg){
    if(falg==1){
        ui->pushButton_19->setStyleSheet(stylesheet->LikeMusicStyle());
    }
    else if(falg==0){
        ui->pushButton_19->setStyleSheet(stylesheet->NoLikeMusicStyle());
    }
}

void widget::addHistoryMusic(){
    int current = music->getMusicCurrentIndex();
    int list = music->getMusicList();

    QString fileName = sqloperator->MusicName(current,list);

    int count = music->music_historyCount;
    for(int i = 0;i < count;i++){
        QString name = ui->listWidget_5->item(i)->text();
        if(fileName==name){
            return;
        }
    }

    music->addHistoryMusic(current,list);

    QListWidgetItem *item = new QListWidgetItem;
    item->setText(fileName);
    item->setToolTip(fileName);
    ui->listWidget_5->addItem(item);
}

widget::widget(QWidget *parent):QWidget(parent),ui(new Ui::widget){
    ui->setupUi(this);
    setAutoFillBackground(true);

    ui->lineEdit->setPlaceholderText(("请输入歌曲"));//设置输入框内隐藏字符

    setWindowFlag(Qt::FramelessWindowHint);//对话框自带的边框去除，使用自定义的边框。
    setAttribute(Qt::WA_TranslucentBackground);//使透明效果生效

    QGraphicsDropShadowEffect *effect = new QGraphicsDropShadowEffect;//实例化阴影对象
    effect->setOffset(1,1);//阴影偏移
    effect->setColor(QColor(0,0,0,100));//阴影颜色
    effect->setBlurRadius(15);//阴影半径

    ui->frame->setGraphicsEffect(effect);//对frame使用实例化阴影对象
    ui->frame->setAutoFillBackground(true);

    stylesheet = new styleSheet_byslef();
    music = new musicControl();
    sqloperator = new sqlOperator();

    currentFileName.push_back("D:/");//初始化QString的Vector路径
    currentFileName.push_back("D:/");
    currentFileName.push_back("D:/");
    currentFileName.push_back("D:/");

    init_else();//初始化其他项
    init_tooltip();//初始化图标文字提示
    init_action();//对相应按钮活动进行初始化
    init_connect();//初始化按键连接
    init_icon();//初始化界面图标样式
}

inline void widget::init_else(){
    ui->listWidget->setFrameShape(QListWidget::NoFrame);//设置无边框
    ui->listWidget_2->setFrameShape(QListWidget::NoFrame);
    ui->listWidget_3->setFrameShape(QListWidget::NoFrame);
    ui->listWidget_4->setFrameShape(QListWidget::NoFrame);
    ui->listWidget_5->setFrameShape(QListWidget::NoFrame);

    ui->listWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//关闭水平滚动条
    ui->listWidget_2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->listWidget_3->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->listWidget_4->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->listWidget_5->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    ui->listWidget->verticalScrollBar()->setCursor(Qt::PointingHandCursor);//初始化绘制listWidget滚动条样式:1鼠标样式
    ui->listWidget_2->verticalScrollBar()->setCursor(Qt::PointingHandCursor);
    ui->listWidget_3->verticalScrollBar()->setCursor(Qt::PointingHandCursor);
    ui->listWidget_4->verticalScrollBar()->setCursor(Qt::PointingHandCursor);
    ui->listWidget_4->verticalScrollBar()->setCursor(Qt::PointingHandCursor);

    ui->listWidget->verticalScrollBar()->setStyleSheet(stylesheet->listWidgetStyle());//初始化绘制listWidget滚动条样式:2美化滚动条样式
    ui->listWidget_2->verticalScrollBar()->setStyleSheet(stylesheet->listWidgetStyle());
    ui->listWidget_3->verticalScrollBar()->setStyleSheet(stylesheet->listWidgetStyle());
    ui->listWidget_4->verticalScrollBar()->setStyleSheet(stylesheet->listWidgetStyle());
    ui->listWidget_4->verticalScrollBar()->setStyleSheet(stylesheet->listWidgetStyle());

    QString value=sqloperator->transparencyDate();
    if(value.isEmpty())
        transparency=0;
    else
        transparency=value.toDouble();
    ui->frame->setWindowOpacity(transparency);


    QString FileName1=":/image/image/background/bg1.jpg";
    QString FileName;
    FileName=sqloperator->wallPaperDate();
    if(FileName.isEmpty())
        FileName=FileName1;
    ui->frame->setStyleSheet(QString("QFrame#frame{border-radius:5px;border-image: url(%1);}").arg(FileName));//读取壁纸主题数据

    ui->stackedWidget->setCurrentIndex(0);//初始化列表页
    pushButtonStyle_4();

    sqloperator->tempFuntion();

    for(int i = 1;i < 4;i++){
        music->init_playList(i);
        int musicTotalCount = music->getMusicCount(i);
        for(int j = 0;j < musicTotalCount;j++){
            QListWidgetItem *item = new QListWidgetItem;
            item->setText(sqloperator->MusicName(j,i));
            item->setToolTip(sqloperator->MusicName(j,i));
            switch(i){
                case 1:
                    ui->listWidget_2->addItem(item);
                    break;
                case 2:
                    ui->listWidget_3->addItem(item);
                    break;
                case 3:
                    ui->listWidget_4->addItem(item);
            }
        }
    }
    ui->label_2->setText("00:00/00:00");
}

inline void widget::init_tooltip(){
    ui->pushButton->setToolTip("最小化");
    ui->pushButton_2->setToolTip("最大化");
    ui->pushButton_3->setToolTip("关闭");
    ui->pushButton_4->setToolTip("更多");
    ui->pushButton_5->setToolTip("设置");
    ui->pushButton_6->setToolTip("更换主题");
    ui->pushButton_7->setToolTip("添加本地歌曲");
    ui->pushButton_8->setToolTip("退出");
    ui->pushButton_9->setToolTip("上一首");
    ui->pushButton_11->setToolTip("下一首");
    ui->pushButton_12->setToolTip("本地音乐");
    ui->pushButton_13->setToolTip("我的喜欢");
    ui->pushButton_14->setToolTip("我的收藏");
    ui->pushButton_15->setToolTip("最近播放");
    ui->pushButton_16->setToolTip("隐藏播放列表");
    ui->pushButton_17->setToolTip("音量");
    ui->pushButton_18->setToolTip("播放模式");
    ui->pushButton_19->setToolTip("我的喜欢");
    ui->pushButton_20->setToolTip("定位");

    ui->horizontalSlider->setToolTip("播放进度");
}//设置指针移动到图标上的文字提示

inline void widget::init_action(){
    //创建主题菜单

    action1 = new QAction(this);
    action1_1 = new QAction(this);
    action1_2 = new QAction(this);
    action1_3 = new QAction(this);
    action1_4 = new QAction(this);//设置活动，详情见定义文件

    action1->setText("设置主题");
    action1_1->setText("绿色");
    action1_2->setText("动漫");
    action1_3->setText("怀旧");
    action1_4->setText("自定义");

    QMenu *ChangeBackGroundMenu = new QMenu(this);//创建主题设置菜单
    ChangeBackGroundMenu->addAction(action1_1);
    ChangeBackGroundMenu->addAction(action1_2);
    ChangeBackGroundMenu->addAction(action1_3);
    ChangeBackGroundMenu->addAction(action1_4);

    ChangeBackGroundMenu->setStyleSheet(stylesheet->MenuStyle());
    action1->setMenu(ChangeBackGroundMenu);
    ui->pushButton_6->setMenu(ChangeBackGroundMenu);

    //创建透明度菜单

    action2 = new QAction(this);
    action2_1 = new QAction(this);
    action2_2 = new QAction(this);

    action2->setText("设置透明度");
    action2_1->setText("+5%");
    action2_2->setText("-5%");

    QMenu *setTransparency = new QMenu(this);
    setTransparency->addAction(action2_1);
    setTransparency->addAction(action2_2);

    setTransparency->setStyleSheet(stylesheet->MenuStyle());
    action2->setMenu(setTransparency);

    //创建添加菜单

    action3 = new QAction(this);
    action3_1 = new QAction(this);
    action3_2 = new QAction(this);

    action3->setText("添加音乐");
    action3_1->setText("添加至本地音乐");
    action3_2->setText("添加至我的收藏");

    QMenu *addMusicMenu = new QMenu(this);
    addMusicMenu->addAction(action3_1);
    addMusicMenu->addAction(action3_2);

    addMusicMenu->setStyleSheet(stylesheet->MenuStyle());

    ui->pushButton_7->setMenu(addMusicMenu);

    action3->setMenu(addMusicMenu);
    //创建清除菜单

    action4 = new QAction(this);
    action4_1 = new QAction(this);
    action4_2 = new QAction(this);
    action4_3 = new QAction(this);
    action4_4 = new QAction(this);

    action4->setText("清除音乐");
    action4_1->setText("清除本地音乐列表");
    action4_2->setText("清除喜欢音乐列表");
    action4_3->setText("清除收藏音乐列表");
    action4_4->setText("清除历史音乐列表");

    QMenu *clearMusic = new QMenu(this);
    clearMusic->addAction(action4_1);
    clearMusic->addAction(action4_2);
    clearMusic->addAction(action4_3);
    clearMusic->addAction(action4_4);

    clearMusic->setStyleSheet(stylesheet->MenuStyle());

    action4->setMenu(clearMusic);

    //创建主菜单

    QMenu *mainMenu = new QMenu(this);
    mainMenu->addAction(action2);
    mainMenu->addAction(action1);
    mainMenu->addAction(action4);

    mainMenu->setStyleSheet(stylesheet->MenuStyle());
    ui->pushButton_5->setMenu(mainMenu);

    //设置右键菜单
    action5_1 = new QAction;
    action5_2 = new QAction;
    action5_3 = new QAction;
    action5_4 = new QAction;
    action5_5 = new QAction;

    action6 = new QAction;
    action6_1 = new QAction;
    action6_2 = new QAction;
    action6_3 = new QAction;

    //action7 = new QAction;
    //action8 = new QAction;
    //action9 = new QAction;
}

void widget::init_connect(){
    connect(action1_1,&QAction::triggered,this,&widget::action1_1_slot);//默认主题1
    connect(action1_2,&QAction::triggered,this,&widget::action1_2_slot);//默认主题2
    connect(action1_3,&QAction::triggered,this,&widget::action1_3_slot);//默认主题3
    connect(action1_4,&QAction::triggered,this,&widget::action1_4_slot);//自定义主题
    connect(action2_1,&QAction::triggered,this,&widget::action2_1_slot);//透明度+5%
    connect(action2_2,&QAction::triggered,this,&widget::action2_2_slot);//透明度-5%
    connect(action3_1,&QAction::triggered,this,&widget::action3_1_slot);//添加本地音乐
    connect(action3_2,&QAction::triggered,this,&widget::action3_2_solt);//添加我的收藏
    connect(action4_1,&QAction::triggered,this,&widget::action4_1_solt);//清除本地音乐
    connect(action4_2,&QAction::triggered,this,&widget::action4_2_solt);//清除我的喜欢列表
    connect(action4_3,&QAction::triggered,this,&widget::action4_3_solt);//清除我的收藏列表
    connect(action4_4,&QAction::triggered,this,&widget::action4_4_solt);//清除历史记录列表
    connect(action5_1,&QAction::triggered,this,&widget::action5_1_solt);//右键菜单相关
    connect(action5_2,&QAction::triggered,this,&widget::action5_2_solt);//右键菜单相关
    connect(action5_3,&QAction::triggered,this,&widget::action5_3_solt);//右键菜单相关
    connect(action5_4,&QAction::triggered,this,&widget::action5_4_solt);//右键菜单相关
    connect(action5_5,&QAction::triggered,this,&widget::action5_5_solt);//右键菜单相关
    connect(action6_1,&QAction::triggered,this,&widget::action6_1_solt);//右键菜单相关
    connect(action6_2,&QAction::triggered,this,&widget::action6_2_solt);//右键菜单相关
    connect(action6_3,&QAction::triggered,this,&widget::action6_3_solt);//右键菜单相关
    //connect(action7,&QAction::triggered,this,&widget::action7_solt);
    //connect(action8,&QAction::triggered,this,&widget::action8_solt);
    //connect(action9,&QAction::triggered,this,&widget::action9_solt);
    connect(music->getMusicProgress(),&QMediaPlayer::positionChanged,this,&widget::updatePosition);//更新进度条
    connect(music->getMusicProgress(),&QMediaPlayer::durationChanged,this,&widget::updateDuration);//更新音乐长度
    connect(music->getMusicProgress(),&QMediaPlayer::metaDataAvailableChanged,this,&widget::updateLabel_3);//更新音乐数据
    connect(ui->horizontalSlider,&QSlider::sliderMoved,music->getMusicProgress(),&QMediaPlayer::setPosition);//进度条移动，更新音乐播放位置
    connect(ui->verticalSlider,&QSlider::valueChanged,this,&widget::updateVolume);//音量拖动条位置的改变，更新音乐音量
    connect(ui->verticalSlider,&QSlider::sliderMoved,music->getMusicProgress(),&QMediaPlayer::setVolume);//更新音乐音量，改变音量拖动条
    connect(music->getMusicProgressList(1),&QMediaPlaylist::currentIndexChanged,this,&widget::updateListWidget_2);//更新listwidget_2数据
    connect(music->getMusicProgressList(2),&QMediaPlaylist::currentIndexChanged,this,&widget::updateListWidget_3);//更新listwidget_3数据
    connect(music->getMusicProgressList(3),&QMediaPlaylist::currentIndexChanged,this,&widget::updateListWidget_4);//更新listwidget_4数据
    connect(music->getMusicProgressList(4),&QMediaPlaylist::currentIndexChanged,this,&widget::updateListWidget_5);//更新listwidget_5数据
}

inline void widget::init_icon(){

    ui->pushButton_10->setIcon(QIcon(":/image/image/image_normal/pause.png"));//播放按键初始化
    ui->pushButton_10->setStyleSheet(stylesheet->PauseStyle());
    ui->pushButton_10->setToolTip("播放");

    ui->pushButton_17->setStyleSheet(stylesheet->VoiceStyle());//音量按键初始化
    ui->verticalSlider->hide();
    ui->verticalSlider->setValue(50);

    ui->pushButton_18->setStyleSheet(stylesheet->LoopStyle());//音乐播放模式切换初始化
    music->setPlaylistMode(1);

    if(sqloperator->getMusicFalg(music->getMusicCurrentIndex(),music->getMusicList())==1)
        setLikeMusicicon(1);//设置我的喜欢按钮样式
    else
        setLikeMusicicon(0);

    ui->pushButton_16->setStyleSheet(stylesheet->HideListStyle());//隐藏/显示播放列表

}

widget::~widget()
{
    delete ui;
}

void widget::on_pushButton_clicked(){
    showMinimized();//最小化窗口
}//最小化应用窗口

void widget::on_pushButton_3_clicked(){
    QCoreApplication::quit();//退出
}//推出应用窗口

void widget::on_pushButton_4_clicked(){
    QPropertyAnimation *a = new QPropertyAnimation(ui->pushButton_5,"geometry");
    QPropertyAnimation *a1 = new QPropertyAnimation(ui->pushButton_6,"geometry");
    QPropertyAnimation *a2 = new QPropertyAnimation(ui->pushButton_7,"geometry");
    QPropertyAnimation *a3 = new QPropertyAnimation(ui->pushButton_8,"geometry");

    a->setDuration(150);//设置动画播放时间
    a1->setDuration(140);
    a2->setDuration(130);
    a3->setDuration(120);

    //从上到下
    if(ui->pushButton_5->y()==-32){
        a->setStartValue(QRect(1020,-32,32,32));//设置动画开始位置
        a->setEndValue(QRect(1020,20,32,32));//设置动画结束位置
        a->setEasingCurve(QEasingCurve::InBounce);//设置动画类型

        a1->setStartValue(QRect(968,-32,32,32));
        a1->setEndValue(QRect(968,20,32,32));
        a1->setEasingCurve(QEasingCurve::InBounce);

        a2->setStartValue(QRect(916,-32,32,32));
        a2->setEndValue(QRect(916,20,32,32));
        a2->setEasingCurve(QEasingCurve::InBounce);

        a3->setStartValue(QRect(864,-32,32,32));
        a3->setEndValue(QRect(864,20,32,32));
        a3->setEasingCurve(QEasingCurve::InBounce);
    }
    //从下到上
    else{
        a->setStartValue(QRect(1020,20,32,32));
        a->setEndValue(QRect(1020,-32,32,32));
        a->setEasingCurve(QEasingCurve::InBounce);

        a1->setStartValue(QRect(968,20,32,32));
        a1->setEndValue(QRect(968,-32,32,32));
        a1->setEasingCurve(QEasingCurve::InBounce);

        a2->setStartValue(QRect(916,20,32,32));
        a2->setEndValue(QRect(916,-32,32,32));
        a2->setEasingCurve(QEasingCurve::InBounce);

        a3->setStartValue(QRect(864,20,32,32));
        a3->setEndValue(QRect(864,-32,32,32));
        a3->setEasingCurve(QEasingCurve::InBounce);
    }

    QSequentialAnimationGroup *sequentialAnimationGroup = new QSequentialAnimationGroup;

    sequentialAnimationGroup->addAnimation(a);
    sequentialAnimationGroup->addAnimation(a1);
    sequentialAnimationGroup->addAnimation(a2);
    sequentialAnimationGroup->addAnimation(a3);

    sequentialAnimationGroup->start();//开始动画
}

void widget::on_pushButton_8_clicked(){
    on_pushButton_3_clicked();
}

void widget::on_pushButton_9_clicked(){
    if(ui->listWidget->count()==0&&ui->listWidget_2->count()==0&&ui->listWidget_3->count()==0&&ui->listWidget_4->count()==0&&ui->listWidget_5->count()==0)
        return;
    int currentIndex = music->musicLastNext(1);
    ui->listWidget_2->scrollToItem(ui->listWidget_2->item(currentIndex));

    if(sqloperator->getMusicFalg(music->getMusicCurrentIndex(),music->getMusicList())==1)//设置我的喜欢按钮样式
        setLikeMusicicon(1);
    else
        setLikeMusicicon(0);

    if(!music->musicState()){
        setPlayPauseIcon();
        music->musicPlay();
    }
    addHistoryMusic();
}

void widget::on_pushButton_10_clicked(){
    if(ui->listWidget->count()==0&&ui->listWidget_2->count()==0&&ui->listWidget_3->count()==0&&ui->listWidget_4->count()==0&&ui->listWidget_5->count()==0)
        return;

    if(sqloperator->getMusicFalg(music->getMusicCurrentIndex(),music->getMusicList())==1)//设置我的喜欢按钮样式
        setLikeMusicicon(1);
    else
        setLikeMusicicon(0);

    setPlayPauseIcon();
    addHistoryMusic();
}

void widget::on_pushButton_11_clicked(){
    if(ui->listWidget->count()==0&&ui->listWidget_2->count()==0&&ui->listWidget_3->count()==0&&ui->listWidget_4->count()==0&&ui->listWidget_5->count()==0)
        return;
    int currentIndex = music->musicLastNext(2);
    ui->listWidget_2->scrollToItem(ui->listWidget_2->item(currentIndex));

    if(sqloperator->getMusicFalg(music->getMusicCurrentIndex(),music->getMusicList())==1)//设置我的喜欢按钮样式
        setLikeMusicicon(1);
    else
        setLikeMusicicon(0);

    if(!music->musicState()){
        setPlayPauseIcon();
        music->musicPlay();
    }
    addHistoryMusic();
}

void widget::on_pushButton_12_clicked(){
    ui->listWidget_2->setSelectionMode(QListWidget::SingleSelection);//设置选择模式：单选
    ui->stackedWidget->setCurrentIndex(1);
    pushButtonStyle();
}

void widget::on_pushButton_13_clicked(){
    ui->listWidget_3->setSelectionMode(QListWidget::SingleSelection);//设置选择模式：单选
    ui->stackedWidget->setCurrentIndex(2);
    pushButtonStyle_1();
}

void widget::on_pushButton_14_clicked(){
    ui->listWidget_4->setSelectionMode(QListWidget::SingleSelection);
    ui->stackedWidget->setCurrentIndex(3);
    pushButtonStyle_2();
}

void widget::on_pushButton_15_clicked(){
    ui->listWidget_5->setSelectionMode(QListWidget::SingleSelection);
    ui->stackedWidget->setCurrentIndex(4);
    pushButtonStyle_3();
}

void widget::on_pushButton_16_clicked(){
        QPropertyAnimation *AnimationForPushButton1 = new QPropertyAnimation(ui->pushButton_12,"geometry");
        QPropertyAnimation *AnimationForPushButton2 = new QPropertyAnimation(ui->pushButton_13,"geometry");
        QPropertyAnimation *AnimationForPushButton3 = new QPropertyAnimation(ui->pushButton_14,"geometry");
        QPropertyAnimation *AnimationForPushButton4 = new QPropertyAnimation(ui->pushButton_15,"geometry");
        QPropertyAnimation *AnimationForPushButton5 = new QPropertyAnimation(ui->pushButton_16,"geometry");

        AnimationForPushButton1->setDuration(200);
        AnimationForPushButton2->setDuration(200);
        AnimationForPushButton3->setDuration(200);
        AnimationForPushButton4->setDuration(200);
        AnimationForPushButton5->setDuration(300);


        QSequentialAnimationGroup *sequentialAnimationGroup = new QSequentialAnimationGroup;

        if(ui->stackedWidget->isHidden()){
            ui->pushButton_16->setStyleSheet(stylesheet->HideListStyle());
            ui->pushButton_16->setToolTip(("隐藏播放列表"));
            ui->stackedWidget->show();

            AnimationForPushButton1->setStartValue(QRect(-32,60,32,32));
            AnimationForPushButton1->setEndValue(QRect(10,60,32,32));
            AnimationForPushButton1->setEasingCurve(QEasingCurve::InBounce);

            AnimationForPushButton2->setStartValue(QRect(-32,60,32,32));
            AnimationForPushButton2->setEndValue(QRect(80,60,32,32));
            AnimationForPushButton2->setEasingCurve(QEasingCurve::InBounce);

            AnimationForPushButton3->setStartValue(QRect(-32,60,32,32));
            AnimationForPushButton3->setEndValue(QRect(160,60,32,32));
            AnimationForPushButton3->setEasingCurve(QEasingCurve::InBounce);

            AnimationForPushButton4->setStartValue(QRect(-32,60,32,32));
            AnimationForPushButton4->setEndValue(QRect(240,60,32,32));
            AnimationForPushButton4->setEasingCurve(QEasingCurve::InBounce);

            AnimationForPushButton5->setStartValue(QRect(10,60,32,32));
            AnimationForPushButton5->setEndValue(QRect(320,60,32,32));
            AnimationForPushButton5->setEasingCurve(QEasingCurve::InBounce);

            sequentialAnimationGroup->addAnimation(AnimationForPushButton5);
            sequentialAnimationGroup->addAnimation(AnimationForPushButton4);
            sequentialAnimationGroup->addAnimation(AnimationForPushButton3);
            sequentialAnimationGroup->addAnimation(AnimationForPushButton2);
            sequentialAnimationGroup->addAnimation(AnimationForPushButton1);
        }
        else{
            ui->pushButton_16->setToolTip(("显示播放列表"));
            ui->pushButton_16->setStyleSheet(stylesheet->ShowListStyle());
            ui->stackedWidget->hide();

            AnimationForPushButton1->setStartValue(QRect(10,60,32,32));
            AnimationForPushButton1->setEndValue(QRect(-32,60,32,32));
            AnimationForPushButton1->setEasingCurve(QEasingCurve::InBounce);

            AnimationForPushButton2->setStartValue(QRect(80,60,32,32));
            AnimationForPushButton2->setEndValue(QRect(-32,60,32,32));
            AnimationForPushButton2->setEasingCurve(QEasingCurve::InBounce);

            AnimationForPushButton3->setStartValue(QRect(160,60,32,32));
            AnimationForPushButton3->setEndValue(QRect(-32,60,32,32));
            AnimationForPushButton3->setEasingCurve(QEasingCurve::InBounce);

            AnimationForPushButton4->setStartValue(QRect(240,60,32,32));
            AnimationForPushButton4->setEndValue(QRect(-32,60,32,32));
            AnimationForPushButton4->setEasingCurve(QEasingCurve::InBounce);

            AnimationForPushButton5->setStartValue(QRect(320,60,32,32));
            AnimationForPushButton5->setEndValue(QRect(10,60,32,32));
            AnimationForPushButton5->setEasingCurve(QEasingCurve::InBounce);

            sequentialAnimationGroup->addAnimation(AnimationForPushButton1);
            sequentialAnimationGroup->addAnimation(AnimationForPushButton2);
            sequentialAnimationGroup->addAnimation(AnimationForPushButton3);
            sequentialAnimationGroup->addAnimation(AnimationForPushButton4);
            sequentialAnimationGroup->addAnimation(AnimationForPushButton5);
        }
        sequentialAnimationGroup->start();
}

void widget::on_pushButton_17_clicked(){
    if(ui->verticalSlider->isHidden())
        ui->verticalSlider->show();
    else
        ui->verticalSlider->hide();
}

void widget::on_pushButton_18_clicked(){
    if(ui->pushButton_18->styleSheet()==stylesheet->LoopStyle()){
        ui->pushButton_18->setStyleSheet(stylesheet->RandomStyle());
        music->setPlaylistMode(2);
    }
    else if(ui->pushButton_18->styleSheet()==stylesheet->RandomStyle()){
        ui->pushButton_18->setStyleSheet(stylesheet->LoopOneStyle());
        music->setPlaylistMode(3);
    }
    else{
        ui->pushButton_18->setStyleSheet(stylesheet->LoopStyle());
        music->setPlaylistMode(1);
    }
}

void widget::on_pushButton_19_clicked(){
    if(ui->listWidget->count()==0&&ui->listWidget_2->count()==0&&ui->listWidget_3->count()==0&&ui->listWidget_4->count()==0&&ui->listWidget_5->count()==0)
        return;
    int row = music->getMusicCurrentIndex();
    int list =  music->getMusicList();
    int falg = sqloperator->getMusicFalg(row,list);
    if(falg==0){
        setLikeMusicicon(1);
        QString MusicName;
        if(list==1)
            MusicName = ui->listWidget_2->item(row)->text();
        else if(list==3)
            MusicName = ui->listWidget_3->item(row)->text();
        if(!sqloperator->searchMusic(MusicName,2,2).isEmpty())
            return;
        QListWidgetItem* tempItem = new QListWidgetItem;
        tempItem->setText(MusicName);
        tempItem->setToolTip(MusicName);
        ui->listWidget_3->addItem(tempItem);
        music->addLikeMusic(row,list);
        sqloperator->setMusicFalg(row,1,list);
    }
    else{
        if(music->getMusicList()!=2)
            QMessageBox::information(this,("提示"),("该歌曲已添加."),QMessageBox::Yes);
        else{
            setLikeMusicicon(0);
            sqloperator->setMusicFalg(row,0,list);
            music->deleteMusic(row,2);
            QListWidgetItem* tempItem = ui->listWidget_3->item(row);
            delete tempItem;
        }
    }
}

void widget::on_pushButton_20_clicked(){
    if(ui->listWidget->count()==0&&ui->listWidget_2->count()==0&&ui->listWidget_3->count()==0&&ui->listWidget_4->count()==0&&ui->listWidget_5->count()==0)
        return;
    ui->stackedWidget->setCurrentIndex(1);
    pushButtonStyle();
    ui->listWidget_2->item(music->getMusicCurrentIndex())->setSelected(true);
    ui->listWidget_2->scrollToItem(ui->listWidget_2->item(music->getMusicCurrentIndex()));
}

void widget::on_pushButton_21_clicked(){
    QString text = ui->lineEdit->text();
    if(!text.isEmpty()){
        ui->listWidget->clear();
        QList<int> result = sqloperator->searchMusic(text,1,1);
        int size = result.size();
        for(int i=0;i<size;i++){
            QString fileName = sqloperator->MusicName(result[i],1);
            QListWidgetItem *item = new QListWidgetItem;
            item->setText(fileName);
            item->setToolTip(fileName);
            ui->listWidget->addItem(item);
        }
    }
    ui->stackedWidget->setCurrentIndex(0);
    pushButtonStyle_4();
}

void widget::on_listWidget_2_doubleClicked(const QModelIndex &index){
    if(!music->musicState())
        setPlayPauseIcon();
    music->setPlaylist(1);
    int currentIndex = index.row();
    music->setPlaylistIndex(currentIndex,1);

    if(sqloperator->getMusicFalg(music->getMusicCurrentIndex(),music->getMusicList())==1)//设置我的喜欢按钮样式
        setLikeMusicicon(1);
    else
        setLikeMusicicon(0);

    music->musicPlay();
    addHistoryMusic();
}

void widget::on_listWidget_3_doubleClicked(const QModelIndex &index){
    if(!music->musicState())
        setPlayPauseIcon();
    music->setPlaylist(2);
    int currentIndex = index.row();
    music->setPlaylistIndex(currentIndex,2);

    if(sqloperator->getMusicFalg(music->getMusicCurrentIndex(),music->getMusicList())==1)//设置我的喜欢按钮样式
        setLikeMusicicon(1);
    else
        setLikeMusicicon(0);

    music->musicPlay();
    addHistoryMusic();
}

void widget::on_listWidget_4_doubleClicked(const QModelIndex &index){
    if(!music->musicState())
        setPlayPauseIcon();
    music->setPlaylist(3);
    int currentIndex = index.row();
    music->setPlaylistIndex(currentIndex,3);

    if(sqloperator->getMusicFalg(music->getMusicCurrentIndex(),music->getMusicList())==1)//设置我的喜欢按钮样式
        setLikeMusicicon(1);
    else
        setLikeMusicicon(0);

    music->musicPlay();
    addHistoryMusic();
}

void widget::on_listWidget_5_doubleClicked(const QModelIndex &index){
    if(!music->musicState())
        setPlayPauseIcon();
    music->setPlaylist(4);
    int currentIndex = index.row();
    music->setPlaylistIndex(currentIndex,4);

    if(sqloperator->getMusicFalg(music->getMusicCurrentIndex(),music->getMusicList())==1)//设置我的喜欢按钮样式
        setLikeMusicicon(1);
    else
        setLikeMusicicon(0);

    music->musicPlay();
}

void widget::action1_1_slot(){
    QString FileName1=":/image/image/background/bg1.jpg";
    ui->frame->setStyleSheet(QString("QFrame#frame{border-radius:5px;border-image: url(%1);}").arg(FileName1));//设置壁纸主题
    sqloperator->saveWallPaperData(FileName1);
}

void widget::action1_2_slot(){
    QString FileName1=":/image/image/background/bg2.jpg";
    ui->frame->setStyleSheet(QString("QFrame#frame{border-radius:5px;border-image: url(%1);}").arg(FileName1));//设置壁纸主题
    sqloperator->saveWallPaperData(FileName1);
}

void widget::action1_3_slot(){
    QString FileName1=":/image/image/background/bg3.jpg";
    ui->frame->setStyleSheet(QString("QFrame#frame{border-radius:5px;border-image: url(%1);}").arg(FileName1));//设置壁纸主题
    sqloperator->saveWallPaperData(FileName1);
}

void widget::action1_4_slot(){
    QString FileName=QFileDialog::getOpenFileName(this,("文件"),currentFileName[0],("图片文件(*jpg *png)"));//打开文件管理器，选择文件
    if(!FileName.isEmpty()){
        QString file1=QDir::toNativeSeparators(FileName);//处理得到文件路径
        QString file=FileName.split("\\").last();//以“/”拆分路径并返回最后一块字母
        currentFileName[0]=file1.remove(file);//删除最后一块字母
        ui->frame->setStyleSheet(QString("QFrame#frame{border-radius:5px;border-image: url(%1);}").arg(FileName));
    }
    sqloperator->saveWallPaperData(FileName);
}//自定义主题

void widget::action2_1_slot(){
    if(transparency<1.0){
        transparency += 0.05;
    }
    ui->frame->setWindowOpacity(transparency);
    sqloperator->saveTransparencyData(transparency);
}

void widget::action2_2_slot(){
    if(transparency>0.4){
        transparency -= 0.05;
    }
    ui->frame->setWindowOpacity(transparency);
    sqloperator->saveTransparencyData(transparency);
}

void widget::action3_1_slot(){
    ui->stackedWidget->setCurrentIndex(1);
    pushButtonStyle();

    QStringList list = QFileDialog::getOpenFileNames(this,("文件"),currentFileName[1],("音频文件(*.mp3)"));

    QProgressDialog *progressdialog = new QProgressDialog(this);
    QPushButton *button = new QPushButton(this);
    setQProgressDialogLoadingMusic(progressdialog,button,list.size());

    if(!list.isEmpty()){
        int musicNumber = list.size();
        for(int i=0;i<musicNumber;i++){
            if(!progressdialog->wasCanceled())
                progressdialog->setValue(i);
            else
                progressdialog->close();
            if(i==musicNumber-1)
                progressdialog->close();

            QString FileName=QDir::toNativeSeparators(list.at(i));
            if(!FileName.isEmpty()){
                QString file=FileName.split("\\").last();
                QString file1=file;
                file=file.remove(".mp3");
                if(!sqloperator->searchMusic(file,1,2).isEmpty()){
                    continue;
                }
                music->addLCMusic(FileName,1);
                currentFileName[1]=FileName.remove(file1);
                QListWidgetItem *item = new QListWidgetItem;
                item->setText(file);
                item->setToolTip(file);
                ui->listWidget_2->addItem(item);
            }
        }
    }
    delete button;
    delete progressdialog;
}

void widget::action3_2_solt(){
    ui->stackedWidget->setCurrentIndex(3);
    pushButtonStyle_2();

    QStringList list = QFileDialog::getOpenFileNames(this,("文件"),currentFileName[2],("音频文件(*.mp3)"));

    QProgressDialog *progressdialog = new QProgressDialog(this);
    QPushButton *button = new QPushButton(this);
    setQProgressDialogLoadingMusic(progressdialog,button,list.size());

    if(!list.isEmpty()){
        int musicNumber = list.size();
        for(int i=0;i<musicNumber;i++){
            if(!progressdialog->wasCanceled())
                progressdialog->setValue(i);
            else
                progressdialog->close();
            if(i==musicNumber-1)
                progressdialog->close();

            QString FileName=QDir::toNativeSeparators(list.at(i));
            if(!FileName.isEmpty()){
                QString file=FileName.split("\\").last();
                QString file1=file;
                file=file.remove(".mp3");
                if(!sqloperator->searchMusic(file,3,2).isEmpty()){
                    continue;
                }
                music->addLCMusic(FileName,3);
                currentFileName[2]=FileName.remove(file1);
                QListWidgetItem *item = new QListWidgetItem;
                item->setText(file);
                item->setToolTip(file);
                ui->listWidget_4->addItem(item);
            }
        }
    }
    delete button;
    delete progressdialog;
}

void widget::action4_1_solt(){
    int value = QMessageBox::information(this,("清除本地音乐列表"),("确定清除本地音乐列表?"),QMessageBox::Yes|QMessageBox::No,QMessageBox::No);
    if(value==QMessageBox::Yes){
        music->clearAllMusic(1);
        ui->listWidget_2->clear();
        ui->listWidget_5->clear();
    }
}

void widget::action4_2_solt(){
    int value = QMessageBox::information(this,("清除喜欢音乐列表"),("确定清除喜欢音乐列表?"),QMessageBox::Yes|QMessageBox::No,QMessageBox::No);
    if(value==QMessageBox::Yes){
        music->clearAllMusic(2);
        ui->listWidget_3->clear();
    }
    sqloperator->clearMusicFalg();
    setLikeMusicicon(0);
}

void widget::action4_3_solt(){
    int value = QMessageBox::information(this,("清除收藏音乐列表"),("确定清除收藏音乐列表?"),QMessageBox::Yes|QMessageBox::No,QMessageBox::No);
    if(value==QMessageBox::Yes){
        music->clearAllMusic(3);
        ui->listWidget_4->clear();
    }
}

void widget::action4_4_solt(){
    int value = QMessageBox::information(this,("清除历史音乐列表"),("确定清除历史音乐列表?"),QMessageBox::Yes|QMessageBox::No,QMessageBox::No);
    if(value==QMessageBox::Yes){
        music->clearAllMusic(4);
        ui->listWidget_5->clear();
    }
}

void widget::action5_1_solt(){
    on_pushButton_9_clicked();
}

void widget::action5_2_solt(){
    on_pushButton_11_clicked();
}

void widget::action5_3_solt(){
    on_pushButton_10_clicked();
}

void widget::action5_4_solt(){
    on_pushButton_20_clicked();
}

void widget::action5_5_solt(){
    on_pushButton_3_clicked();
}

void widget::action6_1_solt(){
    ui->pushButton_18->setStyleSheet(stylesheet->LoopStyle());
    music->setPlaylistMode(1);
}

void widget::action6_2_solt(){
    ui->pushButton_18->setStyleSheet(stylesheet->RandomStyle());
    music->setPlaylistMode(2);
}

void widget::action6_3_solt(){
    ui->pushButton_18->setStyleSheet(stylesheet->LoopOneStyle());
    music->setPlaylistMode(3);
}

void widget::updateLabel_3(){
    ui->label_3->setText(music->musicData());
}

void widget::updatePosition(qint64 position){
     ui->horizontalSlider->setValue(position);
     ui->label_2->setText(music->normalizeTime(position)+"/"+music->getTotalMusicPosition());
}

void widget::updateDuration(qint64 duration){
    ui->horizontalSlider->setRange(0,duration);
    ui->horizontalSlider->setEnabled(duration>0);
    ui->horizontalSlider->setPageStep(duration/10);
}

void widget::updateListWidget_2(int value){
    if(ui->listWidget_2->selectionMode()==QListWidget::SingleSelection)
        ui->listWidget_2->item(value)->setSelected(true);
}

void widget::updateListWidget_3(int value){
    if(ui->listWidget_3->selectionMode()==QListWidget::SingleSelection)
        ui->listWidget_3->item(value)->setSelected(true);
}

void widget::updateListWidget_4(int value){
    if(ui->listWidget_4->selectionMode()==QListWidget::SingleSelection)
        ui->listWidget_4->item(value)->setSelected(true);
}

void widget::updateListWidget_5(int value){
    if(ui->listWidget_5->selectionMode()==QListWidget::SingleSelection)
        ui->listWidget_5->item(value)->setSelected(true);
}

void widget::updateVolume(int value){
    if(value==0)
        ui->pushButton_17->setStyleSheet(stylesheet->NoVoiceStyle());
    else
        ui->pushButton_17->setStyleSheet(stylesheet->VoiceStyle());
    music->setVolume(value);
}

void widget::pushButtonStyle(){
    ui->pushButton_12->setStyleSheet(stylesheet->pushButton_12_hoverStyle());
    ui->pushButton_13->setStyleSheet(stylesheet->pushButton_13_normalStyle());
    ui->pushButton_14->setStyleSheet(stylesheet->pushButton_14_normalStyle());
    ui->pushButton_15->setStyleSheet(stylesheet->pushButton_15_normalStyle());
}

void widget::pushButtonStyle_1(){
    ui->pushButton_12->setStyleSheet(stylesheet->pushButton_12_normalStyle());
    ui->pushButton_13->setStyleSheet(stylesheet->pushButton_13_hoverStyle());
    ui->pushButton_14->setStyleSheet(stylesheet->pushButton_14_normalStyle());
    ui->pushButton_15->setStyleSheet(stylesheet->pushButton_15_normalStyle());
}

void widget::pushButtonStyle_2(){
    ui->pushButton_12->setStyleSheet(stylesheet->pushButton_12_normalStyle());
    ui->pushButton_13->setStyleSheet(stylesheet->pushButton_13_normalStyle());
    ui->pushButton_14->setStyleSheet(stylesheet->pushButton_14_hoverStyle());
    ui->pushButton_15->setStyleSheet(stylesheet->pushButton_15_normalStyle());
}

void widget::pushButtonStyle_3(){
    ui->pushButton_12->setStyleSheet(stylesheet->pushButton_12_normalStyle());
    ui->pushButton_13->setStyleSheet(stylesheet->pushButton_13_normalStyle());
    ui->pushButton_14->setStyleSheet(stylesheet->pushButton_14_normalStyle());
    ui->pushButton_15->setStyleSheet(stylesheet->pushButton_15_hoverStyle());
}

void widget::pushButtonStyle_4(){
    ui->pushButton_12->setStyleSheet(stylesheet->pushButton_12_normalStyle());
    ui->pushButton_13->setStyleSheet(stylesheet->pushButton_13_normalStyle());
    ui->pushButton_14->setStyleSheet(stylesheet->pushButton_14_normalStyle());
    ui->pushButton_15->setStyleSheet(stylesheet->pushButton_15_normalStyle());
}

void widget::mousePressEvent(QMouseEvent *event){
    offset=event->globalPos()-pos();//求解鼠标点击位置在窗口上的相对坐标
    event->accept();//改变点击事件数据在类之间传递性质，一般为ignore
    setFocus();//设置Widge焦点
    if(event->button()==Qt::LeftButton)//如果是左键点击
        setCursor(Qt::OpenHandCursor);//改变鼠标样式——拖拽手
}

void widget::mouseMoveEvent(QMouseEvent *event){
    move(event->globalPos()-offset);//move函数原点位于窗口左上角，故移动距离为现鼠标桌面位置-窗口左上角位置-上一鼠标相对位置
    event->accept();//改变点击事件数据在类之间传递性质，一般为ignore
    setCursor(Qt::ClosedHandCursor);//改变鼠标样式——关闭拖拽手
}

void widget::mouseReleaseEvent(QMouseEvent *event){
    offset=QPoint();//清空offset数据
    event->accept();//改变点击事件数据在类之间传递性质，一般为ignore
    setCursor(Qt::ArrowCursor);//改变鼠标样式——指针
}

void widget::contextMenuEvent(QContextMenuEvent *){
    if(music->musicState()==1)
        action5_3->setText("暂停");
    else
        action5_3->setText("播放");
    action5_1->setText("上一首");
    action5_2->setText("下一首");
    action5_4->setText("定位");
    action5_5->setText("退出");

    QMenu *setPlaylistMode = new QMenu(this);
    setPlaylistMode->setStyleSheet(stylesheet->MenuStyle());
    action6_1->setText("列表循环");
    action6_2->setText("随机循环");
    action6_3->setText("单曲循环");

    setPlaylistMode->addAction(action6_1);
    setPlaylistMode->addAction(action6_2);
    setPlaylistMode->addAction(action6_3);

    action6->setMenu(setPlaylistMode);
    action6->setText("播放模式");

    QMenu *menu = new QMenu(this);
    menu->setStyleSheet(stylesheet->MenuStyle());

    menu->addAction(action3);
    menu->addAction(action5_1);
    menu->addAction(action5_2);
    menu->addAction(action5_3);
    menu->addAction(action6);
    menu->addAction(action1);
    menu->addAction(action4);
    menu->addAction(action5_4);
    menu->addAction(action5_5);

    menu->exec(QCursor::pos());
}

