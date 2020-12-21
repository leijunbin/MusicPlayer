#ifndef MUSICCONTROL_H
#define MUSICCONTROL_H

#include "headerfile.h"

class musicControl{
public:
    musicControl();
    void init_playList(int falg);
    bool musicState();//音乐播放状态
    void musicPlay();//开始音乐
    void musicPause();//停止音乐
    int musicLastNext(int dir);//上一首、下一首
    void addLocalMusic(QString& path);//添加本地音乐
    void addCollectMusic(QString& path);//添加我的收藏
    void setPlaylist(int falg);//设置播放mediaPlaylist
    void setPlaylistIndex(int currentIndex,int falg);//设置播放曲目
    void setVolume(int value);//设置播放音量
    QString musicData();//返回正在播放音乐信息
    QString normalizeTime(qint64 time);//规范化QMediaPlayer中的时间
    QString getNowMusicPosition();//现在音乐播放位置
    QString getTotalMusicPosition();//音乐播放总时间
    int getMusicCount(int falg);//返回列表音乐数量
    QString getMusicName(int falg,int& currentIndex);//返回对应列表音乐名字
    int getMusicList() const;//返回播放列表
    const QMediaPlayer* getMusicProgress() const;//返回QMdeiaPlayer对象指针
    QMediaPlaylist* getMusicProgressList(int falg);//返回QMediaPlaylist对象指针

private:
    QMediaPlayer *music = NULL;

    QMediaPlaylist *playlist_localMusic = NULL;//本地音乐
    QMediaPlaylist *playlist_likeMusic =NULL;//我的喜欢
    QMediaPlaylist *playlist_collectMusic =NULL;//我的收藏
    QMediaPlaylist *playlist_historyMusic =NULL;//历史记录

    void setSqlIndex(QSqlQuery* query,int& falg);
    int getPlayBackMode(QMediaPlaylist* temp);
    QMediaPlaylist* setNowPlaylist(int falg);
};

#endif // MUSICCONTROL_H
