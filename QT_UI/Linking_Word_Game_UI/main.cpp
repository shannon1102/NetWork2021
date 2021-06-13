#include "loginscreen.h"
#include "homescreen.h"
#include "playscreen.h"

#include <QApplication>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <thread>

int sockfd;
pthread_t send_msg_thread;
pthread_t recv_msg_thread;
char nickname[1024] = {};

void* send_msg_handler(void*){
//        char message[1024] = {};
//        while (1) {
////            str_overwrite_stdout();
//            while (fgets(message, 1024, stdin) != NULL) {
////                str_trim_lf(message, 1024);
//                if (strlen(message) == 0) {
//                  /*  str_overwrite_stdout()*/;
//                } else {
//                    break;
//                }
//            }
//            send(sockfd, message, 1024, 0);
//            if (strcmp(message, "exit") == 0) {
//                break;
//            }
//        }

 }
void* recv_msg_handler(void*) {
    char receiveMessage[1024] = {};
    while (1) {
        int receive = recv(sockfd, receiveMessage, 1024, 0);
        if (receive > 0) {
            printf("\r%s\n", receiveMessage);
        } else if (receive == 0) {
            break;
        } else {
            // -1
        }
    }
}


int main(int argc, char *argv[])
{

        // Create socket
        sockfd = socket(AF_INET , SOCK_STREAM , 0);
        if (sockfd == -1) {
            printf("Fail to create a socket.");
            exit(EXIT_FAILURE);
        }
        struct sockaddr_in server_info, client_info;
           int s_addrlen = sizeof(server_info);
           int c_addrlen = sizeof(client_info);
           memset(&server_info, 0, s_addrlen);
           memset(&client_info, 0, c_addrlen);
           server_info.sin_family = AF_INET;
           server_info.sin_addr.s_addr = inet_addr("127.0.0.1");
           server_info.sin_port = htons(5000);

           int err = connect(sockfd, (struct sockaddr *)&server_info, s_addrlen);
             if (err == -1) {
                 printf("Connection to Server error!\n");
                 exit(EXIT_FAILURE);
             }
             char test[1024]= {};
//             for(int i=0;i<5;i++){
//                 send(sockfd,"LOGIN van",1024,0);

//                 recv(sockfd,test,1024,0);
//                  printf("%s\n",test);
//             }
//              send(sockfd,"GAMES",1024,0);
//              recv(sockfd,test,1024,0);
              printf("%s\n",test);


//               pthread_create(&send_msg_thread,NULL,&(send_msg_handler),NULL);


//               pthread_create(&recv_msg_thread,NULL,&(recv_msg_handler),NULL);
//             pthread_create()

//             pthread_attr_init(&send_msg_thread);

//            if (pthread_create(&send_msg_thread, nullptr, (void *) send_msg_handler, nullptr) != 0) {
//                   printf ("Create pthread error!\n");
//                   exit(EXIT_FAILURE);
//               }

//             thread funcTest1(send_msg_thread);
//             funcTest1.join();



    QApplication a(argc, argv);
    LoginScreen w;
//    HomeScreen w;
//    PlayScreen w;


    w.show();
    return a.exec();
}
