#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080

int main() {
    int client;
    struct sockaddr_in addr;
    char buffer[1024];

    client = socket(AF_INET, SOCK_STREAM, 0);
    if (client < 0) {
        perror("Socket failed");
        return 1;
    }

    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &addr.sin_addr);

    if (connect(client, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("Connection failed");
        close(client);
        return 1;
    }

    printf("Connected to server!\n");

    while (1) {
        printf("Client: ");

        if (fgets(buffer, sizeof(buffer), stdin) == NULL)
            break;

        if (send(client, buffer, strlen(buffer), 0) <= 0)
            break;

        if (strncmp(buffer, "exit", 4) == 0)
            break;

        memset(buffer, 0, sizeof(buffer));

        if (recv(client, buffer, sizeof(buffer)-1, 0) <= 0)
            break;

        printf("Server: %s", buffer);
    }

    close(client);
    return 0;
}

