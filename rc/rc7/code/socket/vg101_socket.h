#ifndef VG101_SOCKET_H
#define VG101_SOCKET_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>


typedef int vg101_server;
typedef struct sockaddr_in vg101_address;

int vg101_generate_address(vg101_address *address, const char *host, int port);

vg101_server vg101_create_server(vg101_address *address);

int vg101_close_server(vg101_server server);

int vg101_send_message(vg101_address *address, char *message, size_t len);

int vg101_receive_message(vg101_server server, vg101_address *address, char *buffer, size_t len);

int vg101_get_response(vg101_address *address, char *message, size_t len);

int vg101_send_response(vg101_server server, vg101_address *address, char *buffer, size_t len);

#endif //VG101_SOCKET_H