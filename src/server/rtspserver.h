/**
服务器
    会话
    数据包
*/

#ifndef __RTSPSERVER_H__
#define __RTSPSERVER_H__



class RTSPServer {
public:
    enum RTSPReqFunc {
        OPTIONS = 0,    /* 查询服务器支持的请求方法 */
        DESCRIBE        /* 请求媒体对象的描述信息 */
        SETUP,          /* 设置传输参数并建立会话 */
        RECORD,         /* 开始录制媒体流 */
        REDIRECT        /* 通知客户端资源位置已更改 */
        PLAY,           /* 开始播放媒体流 */
        PAUSE,          /* 暂停播放媒体 */
        ANNOUNCE,       /* 更新媒体对象的描述对象 */
        GET_PARAMETER,  /* 获取会话或媒体对象的参数 */
        SET_PARAMETER,  /* 设置会话或媒体对象的参数 */
        TEARDOWN,       /* 关闭会话并释放资源 */
    };

    ~RTSPServer();
    RTSPServer& Instance();

    void createSession();
    void destorySession();

private:
    RTSPServer();

    std::
};

#endif /* __RTSPSERVER_H__ */