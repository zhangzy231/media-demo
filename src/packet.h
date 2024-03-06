#ifndef __PACKET_H__
#define __PACKET_H__

#include <string>


#define PACKET_MAX_SIZE 4096

class Packet {

    enum {};

public:
    Packet();
    Packet()
    ~Packet();

    void analysis() {

    }

private:
    std::string __method;
    std::string __url;
    std::string __protocol;
    std::string __content;
    std::string __params;
    
};

#endif /* __PACKET_H__ */