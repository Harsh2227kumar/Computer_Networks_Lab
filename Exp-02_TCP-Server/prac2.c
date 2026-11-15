
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080

int main() {
    int server, client;
    struct sockaddr_in addr;
    char buffer[1024] = {0}, msg[1024];

    // Socket creation
    server = socket(AF_INET, SOCK_STREAM, 0);

    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(PORT);

    // Bind and Listen
    bind(server, (struct sockaddr *)&addr, sizeof(addr));
    listen(server, 3);

    printf("Server listening...\n");

    // Accept connection
    client = accept(server, NULL, NULL);
    printf("Client connected!\n");

    // Receive data
    recv(client, buffer, sizeof(buffer)-1, 0);
    printf("Client: %s\n", buffer);

    // Terminal input
    printf("Enter reply: ");
    fgets(msg, sizeof(msg), stdin);

    // Send data
    send(client, msg, strlen(msg), 0);

    // Close
    close(client);
    close(server);

    return 0;
}



//Connect from another terminal:
//nc 127.0.0.1 8080
