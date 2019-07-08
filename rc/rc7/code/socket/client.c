//
// Created by liu on 19-4-6.
//

#include "vg101_socket.h"


int main(int argc, char *argv[]) {

    char host[] = "127.0.0.1";
    int port = 10101;
    
    vg101_address server_address;
    vg101_generate_address(&server_address, host, port);

    char message[1024];
	char response[1024];
	while (1) {
		fgets(message, 1024, stdin);
		vg101_send_message(&server_address, message, strlen(message));
		if (strcmp(message, "quit\n") == 0) {
			break;
		}
		vg101_get_response(&server_address, response, 1024);
		printf("response: %s", response);
	}
    
    return 0;
}
