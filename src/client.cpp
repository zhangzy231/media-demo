#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <memory>
#include <string.h>
// #include <windows.h>

using namespace std;

int main(int argc, char* argv[]) {


    WSAData wd;
    if (WSAStartup(MAKEWORD(2, 2), &wd) != 0) {
        cout << "network initialication failed." << endl;
        return -1;
    }

    SOCKET client = INVALID_SOCKET;
    sockaddr_in cliaddr;

    client = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    if (INVALID_SOCKET == client) {
        cout << "create socket failed." << endl;
        WSACleanup();
        return -2;
    }

    memset(&cliaddr, 0, sizeof(cliaddr));
    int clilen = sizeof(cliaddr);
    cliaddr.sin_family = AF_INET;
    cliaddr.sin_port = htons(9617);
    inet_pton(AF_INET, "10.91.26.111", &cliaddr.sin_addr);

    int ret = connect(client, (sockaddr*)&cliaddr, sizeof(cliaddr));

    if (ret == -1) {
        cout << "connect services failed." << endl;
        closesocket(client);
        WSACleanup();
        return -3;
    }

    char buffer[2048] = {};
    int number = 0;
    const char* quitcode = "quit";
    while(1) {
        memset(buffer, 0, sizeof(buffer));
        std::cin.getline(buffer, sizeof(buffer));
        if (!strcmp(buffer, quitcode))
            break;
        send(client, buffer, strlen(buffer), 0);
        memset(buffer, 0, sizeof(buffer));
        ret = recv(client, buffer, 2048, 0);
        cout << "server say: " << buffer << endl;
        if (ret == 0) {
            cout << "disconnect form server..." << endl;
            break;
        }
    }

    closesocket(client);
    WSACleanup();
    return 0;
} 