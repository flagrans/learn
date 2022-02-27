#include <algorithm>
#include <iostream>


#include <socket_wrapper/socket_headers.h>
#include <socket_wrapper/socket_wrapper.h>
#include <socket_wrapper/socket_class.h>


// Trim from end (in place).
static inline std::string& rtrim(std::string& s)
{
    s.erase(std::find_if(s.rbegin(), s.rend(), [](int c) { return !std::isspace(c); }).base());
    return s;
}


int main(int argc, char const *argv[])
{

    if (argc != 3)
    {
        std::cout << "Usage: " << argv[0] << "<IP adress> <port>" << std::endl;
        return EXIT_FAILURE;
    }

    socket_wrapper::SocketWrapper sock_wrap;
    const std::string address { argv[1] };
    const int port { std::stoi(argv[2]) };

    socket_wrapper::Socket sock = {AF_INET, SOCK_DGRAM, IPPROTO_UDP};

    std::cout << "Starting UDP client to the address " << address << ":" << port << "...\n";

    if (!sock)
    {
        std::cerr << sock_wrap.get_last_error_string() << std::endl;
        return EXIT_FAILURE;
    }

    sockaddr_in addr =
    {
        .sin_family = AF_INET,
        .sin_port = htons(port),
    };
    socklen_t addrSize = sizeof(addr);

    inet_pton(AF_INET, address.c_str(), &(addr.sin_addr));
    int maxLen = 256;
    char buffer[maxLen];
    std::string tempString;
    ssize_t recv_len = 0;

    while (true) {
        std::cout << "Enter message(<= " << maxLen << " symbols):" << std::endl;
        std::cin >> tempString;

        if (tempString == "exit") { // Если передаем exit - то отправляем его на сервер(чтобы сервер тоже завершил свою работу) и завершаем программу
            std::cout << "Enter \"exit\" command, received command to shutdown UDP server. Client shutdown." << std::endl;
            sendto(sock, tempString.c_str(), tempString.size(), 0, reinterpret_cast<const sockaddr *>(&addr), sizeof(addr));
            shutdown(sock, 2);
            return 0;
        }
        if (tempString.size() > maxLen) { // Если размер больше максимального, то запрашиваем данные повторно
            std::cout << "Message have is very big size > " << maxLen
                      << " symbols. Enter message again." << std::endl;
            continue;
        }
        sendto(sock, tempString.c_str(), tempString.size(), 0, reinterpret_cast<const sockaddr *>(&addr), sizeof(addr));

        recv_len = recvfrom(sock, buffer, sizeof(buffer) - 1, 0, reinterpret_cast<sockaddr *>(&addr), &addrSize);

        if (recv_len > 0) {
            buffer[recv_len] = '\0';

            std::cout << "Received data from the server: " << buffer
                      << std::endl
                      << std::endl;
        } else {
            std::cout << "recv failed" << std::endl;
            close(sock);
            return 1;
        }
    }

    return EXIT_SUCCESS;
}

