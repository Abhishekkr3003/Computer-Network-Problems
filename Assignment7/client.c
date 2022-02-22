/*
    Abhishek Kumar
    19ucs241
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main()
{
    int sock;
    struct sockaddr_in servAddr;

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Socket creation error \n");
        return -1;
    }

    servAddr.sin_family = AF_INET;
    servAddr.sin_port = htons(9001);
    servAddr.sin_addr.s_addr = INADDR_ANY;

    int connectStatus = connect(sock, (struct sockaddr *)&servAddr, sizeof(servAddr));

    if (connectStatus == -1)
    {
        printf("\nConnection Failed \n");
        return -1;
    }
    else
    {
        char strData[2048];
        recv(sock, strData, sizeof(strData), 0);
        printf("Message: %s\n", strData);
        close(sock);
    }
    return 0;
}