#include "loginscreen.h"
#include "homescreen.h"
#include "playscreen.h"

#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>
#include "string.h"

#include <QApplication>
int sockfd;

void send_msg_handler() {
    char message[LENGTH_MSG] = {};
    while (1) {
        while (fgets(message, LENGTH_MSG, stdin) != NULL) {
            str_trim_lf(message, LENGTH_MSG);
            if (strlen(message) == 0) {

            } else {
                break;
            }
        }
        send(sockfd, message, LENGTH_MSG, 0);
        if (strcmp(message, "exit") == 0) {
            break;
        }
    }
}
int main(int argc, char *argv[])
{
    sockfd = socket(AF_INET , SOCK_STREAM , 0);
        if (sockfd == -1) {
            printf("Fail to create a socket.");
            exit(EXIT_FAILURE);
        }

        // Socket information
        struct sockaddr_in server_info, client_info;
        int s_addrlen = sizeof(server_info);
        int c_addrlen = sizeof(client_info);
        memset(&server_info, 0, s_addrlen);
        memset(&client_info, 0, c_addrlen);
        server_info.sin_family = AF_INET;
        server_info.sin_addr.s_addr = inet_addr("127.0.0.1");
        server_info.sin_port = htons(5000);

        // Connect to Server
        int err = connect(sockfd, (struct sockaddr *)&server_info, s_addrlen);
        if (err == -1) {
            printf("Connection to Server error!\n");
            exit(EXIT_FAILURE);
        }
        char message[100] ={};
        strcpy(message,"Aloooo tooo");

        send(sockfd, message, strlen(message), 0);


    QApplication a(argc, argv);
    LoginScreen w;
//    HomeScreen w;
//    PlayScreen w;
    w.show();
    return a.exec();
}
