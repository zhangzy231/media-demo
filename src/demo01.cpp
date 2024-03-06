// #include <stdio.h>
#include <iostream>
// #include <stdlib.h>
// #include <winsock2.h>
// #include <ws2tcpip.h>
#include <string>
#include <cstring>
// #include <unordered_map>
#include <memory>

using namespace std;
 


int main(int argc, char* argv[]) { 

    // sockaddr_in addr;
    // memset(&addr, 0, sizeof(addr));

    // addr.sin_family = AF_INET;
    // addr.sin_port = htons(9617);
    // inet_pton(AF_INET, "10.91.26.111", &addr.sin_addr);

    // char ipbuffer[INET_ADDRSTRLEN] = {};
    // inet_ntop(AF_INET, &addr.sin_addr, ipbuffer, sizeof(ipbuffer));
    // printf("ip: %s, port: %d\n", ipbuffer, ntohs(addr.sin_port));
    // const char* s = "hello world.";
    // cout << s << endl;      /* hello world. */
    // cout << *s << endl;     /* h */
    // cout << &s << endl;     /* 0xFFFFFFFF */

    const char *str = "SETUP rtsp://example.com/media/stream RTSP/1.0 \r\n" \
                    "CSeq: 1\r\n" \
                    "Transport: RTP/AVP;unicast;client_port=1234-1235\r\n" \
                    "\r\n";
    cout << "str: " << str << endl;
    auto next_line = strchr(str, '\n');
    if (*(next_line- 1 ) == '\r') {
        cout << string(str, next_line - str) << endl;
    }
 
    // 自增 result，否则我们将找到相同位置的目标

    return 0;
}
