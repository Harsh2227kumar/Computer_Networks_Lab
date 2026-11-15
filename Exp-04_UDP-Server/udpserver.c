#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8081

int main() {
    int sockfd, len;
    char buffer[1024];
    struct sockaddr_in servaddr, cliaddr;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(PORT);

    bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

    printf("UDP Server listening...\n");

    while (1) {
        len = sizeof(cliaddr);

        memset(buffer, 0, sizeof(buffer));
        recvfrom(sockfd, buffer, sizeof(buffer)-1, 0,
                 (struct sockaddr *)&cliaddr, &len);

        printf("Client: %s", buffer);

        if (strncmp(buffer, "exit", 4) == 0)
            continue;

        printf("Server: ");
        fgets(buffer, sizeof(buffer), stdin);

        sendto(sockfd, buffer, strlen(buffer), 0,
               (struct sockaddr *)&cliaddr, len);
    }

    close(sockfd);
    return 0;
}


