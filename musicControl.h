#ifndef MUSICCONTROL_H
#define MUSICCONTROL_H

#include "headerfile.h"
#include "sqlOperator.h"

class musicControl{
public:
    musicControl();
    void init_playList(int falg);
    bool musicState();//音乐播放状态
    void musicPlay();//开始音乐
    void musicPause();//停止音乐
    int musicLastNext(int dir);//上一首、下一首
    void clearAllMusic(int falg);//清除音乐相关
    void addLCMusic(QString& path,int falg);//添加本地音乐
    void addLikeMusic(int currentIndex,int falg);//添加我的喜欢
    void addHistoryMusic(int currentIndex,int falg);//添加历史音乐
    void deleteMusic(int currentIndex,int falg);//删除音乐
    void setPlaylist(int falg);//设置播放mediaPlaylist
    void setPlaylistIndex(int currentIndex,int falg);//设置播放曲目
    void setVolume(int value);//设置播放音量
    void setPlaylistMode(int falg);//设置播放模式
    QString musicData();//返回正在播放音乐信息
    QString normalizeTime(qint64 time);//规范化QMediaPlayer中的时间
    QString getNowMusicPosition();//现在音乐播放位置
    QString getTotalMusicPosition();//音乐播放总时间
    int getMusicCount(int falg);//返回列表音乐数量
    int getMusicList();//返回播放列表
    int getMusicCurrentIndex();//返回播放音乐序号
    const QMediaPlayer* getMusicProgress() const;//返回QMdeiaPlayer对象指针
    QMediaPlaylist* getMusicProgressList(int falg);//返回QMediaPlaylist对象指针

    int music_historyCount = 0;

private:
    QMediaPlayer *music = NULL;

    QMediaPlaylist *playlist_localMusic = NULL;//本地音乐
    QMediaPlaylist *playlist_likeMusic =NULL;//我的喜欢
    QMediaPlaylist *playlist_collectMusic =NULL;//我的收藏
    QMediaPlaylist *playlist_historyMusic =NULL;//历史记录

    sqlOperator* sqloperator;

    QString sqldata[4]={"", "LocalMusic","LikeMusic","CollectMusic"};
    QMediaPlaylist *playlist[5];

    void setSqlIndex(QSqlQuery* query,int& falg);
    int getPlayBackMode(QMediaPlaylist* temp);
    QMediaPlaylist* setNowPlaylist(int falg);
};

#endif // MUSICCONTROL_H
