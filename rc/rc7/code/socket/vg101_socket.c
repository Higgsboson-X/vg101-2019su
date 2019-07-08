//
// Created by liu on 19-4-6.
//

#include "vg101_socket.h"

int vg101_generate_address(vg101_address *address, const char *host, int port) {
    address->sin_family = AF_INET;
    address->sin_port = htons(port);
    if (!host) {
        address->sin_addr.s_addr = INADDR_ANY;
    } else if (inet_pton(AF_INET, host, &address->sin_addr) <= 0) {
        return 0;
    }
    return 1;
}

vg101_server vg101_create_server(vg101_address *address) {
    int server_fd;
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        return 0;
    }
    int opt = 1;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        return 0;
    }
    if (bind(server_fd, (struct sockaddr *) address, sizeof(vg101_address)) < 0) {
        perror("bind failed");
        return 0;
    }
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        return 0;
    }
    return server_fd;
}

int vg101_close_server(vg101_server server) {
    return close(server);
}

int vg101_send_message(vg101_address *address, char *message, size_t len) {
    int client_fd = 0;
    if ((client_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket failed");
        return 0;
    }
    if (connect(client_fd, (struct sockaddr *) address, sizeof(vg101_address)) < 0) {
        perror("connection failed");
        return 0;
    }
    send(client_fd, message, len, 0);
    close(client_fd);
    return 1;
}

int vg101_receive_message(vg101_server server, vg101_address *address, char *buffer, size_t len) {
    int new_socket;
    int addrlen = sizeof(address);
    if ((new_socket = accept(server, (struct sockaddr *) &address, (socklen_t *) &addrlen)) < 0) {
        perror("accept");
        return 0;
    }
    read(new_socket, buffer, len);
    close(new_socket);
    return 1;
}


// response;

int vg101_get_response(vg101_address *address, char *message, size_t len) {
    int client_fd = 0;
    if ((client_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket failed");
        return 0;
    }
    if (connect(client_fd, (struct sockaddr *) address, sizeof(vg101_address)) < 0) {
        perror("connection failed");
        return 0;
    }
    recv(client_fd, message, len, 0);
    close(client_fd);
    return 1;
}

int vg101_send_response(vg101_server server, vg101_address *address, char *buffer, size_t len) {
    int new_socket;
    int addrlen = sizeof(address);
    if ((new_socket = accept(server, (struct sockaddr *) &address, (socklen_t *) &addrlen)) < 0) {
        perror("accept");
        return 0;
    }
	fgets(buffer, len, stdin);
    write(new_socket, buffer, len);
    close(new_socket);
    return 1;
}