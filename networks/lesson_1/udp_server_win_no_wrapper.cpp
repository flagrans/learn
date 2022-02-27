#include <cstring>
#include <iostream>
#include <stdio.h>
#include <winsock2.h>
#include <ws2tcpip.h>

int main() {
    WSADATA wsaData;
    SOCKET sendRecvSocket;
    sockaddr_in serverAddr;
    sockaddr_in clientAddr;
    char ip4[INET_ADDRSTRLEN];
    char hbuf[NI_MAXHOST];
    int err;
    int err2;
    int result;
    int maxLen = 512;
    int clientAddrSize = sizeof(clientAddr);
    char *recvBuf = new char[maxLen];
    std::string tempString;

    WSAStartup(MAKEWORD(2, 2), &wsaData);

    sendRecvSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(12345);

    err = bind(sendRecvSocket, (sockaddr *)&serverAddr, sizeof(serverAddr));
    if (err == SOCKET_ERROR) {
        std::cout << "bind failed: " << WSAGetLastError() << std::endl;
        closesocket(sendRecvSocket);
        WSACleanup();
        delete[] recvBuf;
        return 1;
    }
    while (true) {
        err = recvfrom(sendRecvSocket, recvBuf, maxLen, 0,
                       (sockaddr *)&clientAddr, &clientAddrSize);
        if (err > 0) {
            recvBuf[err] = '\0';
            tempString = recvBuf;
            if (tempString ==
                "exit") { // Если прислали exit - завершаем работу сервера
                std::cout << "\"exit\" command received, shutdown UDP server"
                          << std::endl;
                shutdown(sendRecvSocket, 2);
                return 0;
            }

            inet_ntop(AF_INET, &(clientAddr.sin_addr), ip4,
                      INET_ADDRSTRLEN); // Получение IP клиента

            err2 = getnameinfo((sockaddr *)&clientAddr, sizeof(sockaddr), hbuf,
                               sizeof(hbuf), nullptr, 0,
                               NI_NAMEREQD); // Получение имени хоста клиента

            std::cout << "From:" << std::endl;
            if (err2 != 0) {
                std::cout << "getnameinfo failed with error: "
                          << WSAGetLastError() << std::endl;
                return 1;
            } else {
                std::cout << "Hostname: " << hbuf << std::endl;
            }

            std::cout << "IP: " << ip4 << std::endl;
            std::cout << "Data: " << tempString << std::endl << std::endl;
            sendto(sendRecvSocket, recvBuf, std::strlen(recvBuf), 0,
                   (sockaddr *)&clientAddr, sizeof(clientAddr));
        } else {
            std::cout << "recv failed: " << WSAGetLastError() << std::endl;
            closesocket(sendRecvSocket);
            WSACleanup();
            delete[] recvBuf;
            return 1;
        }
    }

    std::cout << "Exit" << std::endl;
    delete[] recvBuf;
    return 0;
}
