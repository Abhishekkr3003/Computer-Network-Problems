/*
    Abhishek Kumar
    19ucs241
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main()
{
    char serverData[2048] = "Server Hello!";
    int server_fd, new_socket;
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in servAddr;
    servAddr.sin_family = AF_INET;
    servAddr.sin_port = htons(9001);
    servAddr.sin_addr.s_addr = INADDR_ANY;
    int opt = 1;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    if (bind(server_fd, (struct sockaddr *)&servAddr, sizeof(servAddr)) < 0)
    {
        perror("Oops! Bind failed.");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 1) < 0)
    {
        perror("Oops! Listen failed");
        exit(EXIT_FAILURE);
    }
    if ((new_socket = accept(server_fd, NULL, NULL)) < 0)
    {
        perror("Oops! Accept failed");
        exit(EXIT_FAILURE);
    }
    send(new_socket, serverData, sizeof(serverData), 0);
    close(server_fd);

    return 0;
}