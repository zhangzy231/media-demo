#include <iostream>
#include <winsock2.h>
#include <Ws2tcpip.h>
#include <memory>
#include <sstream>

using namespace std;

int main(int argc, char* argv[]) {


    WSAData wd;
    if (WSAStartup(MAKEWORD(2, 2), &wd) != 0) {
        cout << "network initialication failed." << endl;
        return -1;
    }

    SOCKET server = INVALID_SOCKET;
    sockaddr_in seraddr;

    server = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    if (INVALID_SOCKET == server) {
        cout << "create socket failed." << endl;
        WSACleanup();
        return -2;
    }
    memset(&seraddr, 0, sizeof(seraddr));
    seraddr.sin_family = AF_INET;
    seraddr.sin_port = htons(9617);
    seraddr.sin_addr.s_addr = INADDR_ANY;

    int ret = bind(server, (sockaddr*)&seraddr, sizeof(seraddr));

    if (ret == -1) {
        cout << "bind address failed." << endl;
        closesocket(server);
        WSACleanup();
        return -3;
    }

    ret = listen(server, 10);
    if (ret == -1) {
        cout << "listen client failed." << endl;
        closesocket(server);
        WSACleanup();
        return -4;
    }

    cout << "startup successed. wait connecting..." << endl;

    SOCKET client;
    sockaddr_in cliaddr;
    int clilen = sizeof(cliaddr);
    client = accept(server, (sockaddr*)&cliaddr, &clilen);

    if (client == INVALID_SOCKET) {
        cout << "client connect failed." << endl;
        closesocket(server);
        WSACleanup();
        return -5;
    }
    stringstream ss;
    ss << "CLIENT IP: " << inet_ntoa(cliaddr.sin_addr) << ", PROT: " << cliaddr.sin_port << " connected..";
    cout << ss.str() << endl;

    char recvbuffer[2048] = {};
    while(1) {
        ret = recv(client, recvbuffer, 2048, 0);
        if (ret == 0) {
            char ipbuffer[INET_ADDRSTRLEN] = {};
            inet_ntop(AF_INET, &cliaddr.sin_addr, ipbuffer, sizeof(ipbuffer));
            cout << "ip: " << ipbuffer << ", port: " << ntohs(cliaddr.sin_port) << " disconnected..";
            break;
        }
        cout << "receive from client: " << recvbuffer << endl;
        memset(recvbuffer, 0 , sizeof(recvbuffer));
        snprintf(recvbuffer, sizeof(recvbuffer), "hello client, how are you?");
        send(client, recvbuffer, 2048, 0);
        memset(recvbuffer, 0 , sizeof(recvbuffer));
    }

    closesocket(server);
    WSACleanup();
    return 0;
} 