#ifndef __RTSPPARSER_H__
#define __RTSPPARSER_H__


class RTSPParser {
public:
    RTSPParser();
    ~RTSPParser();

    void parse(const char* buf, size_t size);

    const std::string& method() const;
    const std::string& fullurl() const;
    const std::string& url() const;
    const std::string& params() const;
    const std::string& protocol() const;
    const std::string& status() const;
    const std::string& statusStr() const;

    void clear();

private:
    std::string _method;
    std::string _url;
    std::string _params;
    std::string _protocol;
    std::string _status;
    std::string _content;


};


#endif /* __RTSPPARSER_H__ */