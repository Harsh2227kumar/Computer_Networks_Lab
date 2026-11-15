
#include <stdio.h>
#include <string.h>
#include <winsock2.h>
#pragma comment(lib, "ws2_32.lib")

#define PORT 8080

int main() {
    WSADATA wsa;
    SOCKET server, client;
    struct sockaddr_in addr;
    char buffer[1024] = {0};
    char *msg = "Hello from TCP Server!";

    WSAStartup(MAKEWORD(2,2), &wsa);

    // Socket creation
    server = socket(AF_INET, SOCK_STREAM, 0);

    // Address configuration
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(PORT);

    // Bind
    bind(server, (struct sockaddr *)&addr, sizeof(addr));

    // Listen
    listen(server, 3);
    printf("Server listening on port %d...\n", PORT);

    // Accept connection
    client = accept(server, NULL, NULL);

    // Data transfer
    recv(client, buffer, sizeof(buffer)-1, 0);
    printf("Client: %s\n", buffer);

    send(client, msg, strlen(msg), 0);
    printf("Response sent!\n");

    // Closing
    closesocket(client);
    closesocket(server);
    WSACleanup();

    return 0;
}
