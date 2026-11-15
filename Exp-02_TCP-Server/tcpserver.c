#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080

int main() {
    int server, client;
    struct sockaddr_in addr;
    char buffer[1024];

    server = socket(AF_INET, SOCK_STREAM, 0);
    if (server < 0) {
        perror("Socket failed");
        return 1;
    }

    int opt = 1;
    setsockopt(server, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(PORT);

    if (bind(server, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("Bind failed");
        close(server);
        return 1;
    }

    if (listen(server, 3) < 0) {
        perror("Listen failed");
        close(server);
        return 1;
    }

    printf("Server listening...\n");

    while (1) {
        client = accept(server, NULL, NULL);

        if (client < 0) {
            perror("Accept failed");
            continue;
        }

        printf("Client connected!\n");

        while (1) {
            memset(buffer, 0, sizeof(buffer));

            int n = recv(client, buffer, sizeof(buffer)-1, 0);

            if (n <= 0)
                break;

            printf("Client: %s", buffer);

            if (strncmp(buffer, "exit", 4) == 0)
                break;

            printf("Server: ");
            if (fgets(buffer, sizeof(buffer), stdin) == NULL)
                break;

            if (send(client, buffer, strlen(buffer), 0) <= 0)
                break;
        }

        close(client);
        printf("Client disconnected!\n");
    }

    close(server);
    return 0;
}

