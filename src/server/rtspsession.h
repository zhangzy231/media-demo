#ifndef __RTSPSESSION_H__
#define __RTSPSESSION_H__

class RTSPSession {
public:
    RTSPSession();
    ~RTSPSession();
    
private:
    void handleReqOption(const Parser& parser);
    void handleReqDescribe(const Parser& parser);
    void handleReqSetup(const Parser& parser);
    void handleReqRecord(const Parser& parser);
    void handleReqRedirect(const Parser& parser);

    void handleReqPlay(const Parser& parser);
    void handleReqPause(const Parser& parser);
    void handleReqAnnounce(const Parser& parser);
    void handleReqGetParam(const Parser& parser);
    void handleReqSetParam(const Parser& parser);
    void handleReqTeardown(const Parser& parser);

private:
    size_t __session_id;
};


#endif /* __RTSPSESSION_H__ */