#include <algorithm>
#include <arpa/inet.h>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sys/socket.h>
#include <unistd.h>

/* Buffer size as required not to exceed 255 symbols */
constexpr int MAX_BUFFER_SIZE = 256;
/*
this Function is used to reverse the characters of a C-style string in-place.
It modifies the original string directly without creating a new string.
*/
void reverse_String(char *str)
{
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++)
    {
        std::swap(str[i], str[len - i - 1]);
    }
    str[len] = '\r';
    str[len + 1] = '\n';
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << " <port>" << std::endl;
        return 1;
    }

    int port = std::atoi(argv[1]);
    if (port <= 0)
    {
        std::cerr << "Invalid port number." << std::endl;
        return 1;
    }

    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket < 0)
    {
        std::cerr << "Failed to create server socket." << std::endl;
        return 1;
    }

    sockaddr_in serverAddress{};
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(port);
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    /* binding application to socket server */
    if (bind(serverSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) < 0)
    {
        std::cerr << "Failed to bind server socket." << std::endl;
        close(serverSocket);
        return 1;
    }

    if (listen(serverSocket, 1) < 0)
    {
        std::cerr << "Failed to listen on server socket." << std::endl;
        close(serverSocket);
        return 1;
    }

    std::cout << "Waiting for connection..." << std::endl;

    while (true)
    {
        sockaddr_in clientAddress{};
        socklen_t clientAddressLength = sizeof(clientAddress);

        int clientSocket = accept(serverSocket, (struct sockaddr *)&clientAddress, &clientAddressLength);
        if (clientSocket < 0)
        {
            std::cerr << "Failed to accept client connection." << std::endl;
            close(serverSocket);
            return 1;
        }

        std::cout << "Client connected: " << inet_ntoa(clientAddress.sin_addr) << std::endl;

        const char *welcomeMsg = "Welcome to POCO TCP server. Enter your string:\n";
        send(clientSocket, welcomeMsg, strlen(welcomeMsg), 0);

        char buffer[MAX_BUFFER_SIZE];
        memset(buffer, 0, sizeof(buffer));

        int bytesRead = recv(clientSocket, buffer, sizeof(buffer) - 1, 0);
        /* Received Input String from Client */
        if (bytesRead > 0)
        {
            reverse_String(buffer); // Reverse string
            /* Send back Reverse String to Client */
            send(clientSocket, buffer, strlen(buffer), 0);
        }

        /* close the socket */
        close(clientSocket);
    }

    close(serverSocket);
    return 0;
}
