#include <cstring>
#include <iostream>
#include <stdio.h>
#include <string>
#include <winsock2.h>
#include <ws2tcpip.h>

int main() {
    WSADATA wsaData;
    SOCKET sendRecvSocket;
    sockaddr_in serverAddr;
    int serverAddrSize = sizeof(serverAddr);
    int result;
    int maxLen = 512;
    std::string tempString;
    char *recvBuf = new char[maxLen];

    WSAStartup(MAKEWORD(2, 2), &wsaData);

    sendRecvSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(12345); // для простоты порт "зашиваем" в код
    inet_pton(
        AF_INET, "127.0.0.1",
        &(serverAddr.sin_addr)); // Для простоты берем localhost - 127.0.0.1

    while (true) {
        std::cout << "Enter message(<= " << maxLen << " symbols):" << std::endl;
        std::cin >> tempString;
        if (tempString ==
            "exit") { // Если передаем exit - то отправляем его на сервер(чтобы
                      // сервер тоже завершил свою работу) и завершаем программу
            sendto(sendRecvSocket, tempString.c_str(), tempString.size(), 0,
                   (sockaddr *)&serverAddr, sizeof(serverAddr));
            shutdown(sendRecvSocket, 2);
            delete[] recvBuf;
            return 0;
        }
        if (tempString.size() > maxLen) { // Если размер больше максимального,
                                          // то запрашиваем данные повторно
            std::cout << "Message have is very big size > " << maxLen
                      << " symbols. Enter message again." << std::endl;
            continue;
        }

        sendto(sendRecvSocket, tempString.c_str(), tempString.size(), 0,
               (sockaddr *)&serverAddr, sizeof(serverAddr));

        result = recvfrom(sendRecvSocket, recvBuf, maxLen, 0,
                          (sockaddr *)&serverAddr, &serverAddrSize);

        if (result > 0) {
            recvBuf[result] = '\0';

            std::cout << "Received data from the server: " << recvBuf
                      << std::endl
                      << std::endl;
        } else {
            std::cout << "recv failed: " << WSAGetLastError() << std::endl;
            closesocket(sendRecvSocket);
            WSACleanup();
            delete[] recvBuf;
            return 1;
        }
    }

    delete[] recvBuf;
    return 0;
}
