#include "vg101_socket.h"

int main(int argc, char *argv[]) {
    int port = 10101;

    vg101_address server_address;
    vg101_generate_address(&server_address, NULL, port);

    vg101_server server = vg101_create_server(&server_address);
    while(1) {
        char buffer[1024] = {0};
        vg101_receive_message(server, &server_address, buffer, 1024);
        printf("%s", buffer);
		if (strcmp(buffer, "quit\n") == 0) {
			puts("Quit server.\n");
			break;
		}
		vg101_send_response(server, &server_address, buffer, 1024);
        // break;
    }

    return vg101_close_server(server);
}