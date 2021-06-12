/**
 * \brief	Contains functions for the host server.
 *
 */
#define NUM_CONN 5
#define PORT 5000

#include "server.h"

/*
 * A player's address is the address of his listening socket
 */

struct player player_tab[MAXPLAYER]; //!< Array of connected players

struct room room_list[MAXROOM]; // Array of room
int count_rooms;

void error(const char *msg)
{
    perror(msg);
    pthread_exit(NULL);
}

int getRoomIdFromPlayer(player *currPlayer);
void send_clients_in_a_room(int room_id, char tmp_buffer[]);

//For Checking speller function
int checkSpell(char *wordcheck);
void tolowerStr(char *str);
void load();
void freeList();
void updateTurn(int room_id);


typedef struct node
{
    char data[20];
    struct node *next;
} node;
node *rootWord, *curr;

int main(int argc, char *argv[])
{
    printf("ALoooooooooooo\n");
    //setup spell-checker
    rootWord = NULL, curr = NULL;
    load();
    // Variable declaration
    int serv_sockfd;
    struct sockaddr_in serv_addr;
    int countThread = 0;
    int port = 5000;
    pthread_t thread;

    //Setup initial rooms
    for (int i = 0; i < MAXROOM; i++)
    {
        room_list[i].id = i;
        room_list[i].gameState = INITIAL;
        room_list[i].currentTurn = -1; //NoOne
        room_list[i].numPlayer = 0;
    }

    // Construction of the Adress
    // TCP Protocol
    CHECK(serv_sockfd = socket(AF_INET, SOCK_STREAM, 0), "Error : socket"); /* if = -1 , perror msg*/
    // inet_aton("127.0.0.1", &(serv_addr.sin_addr));
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    memset(&serv_addr.sin_zero, 0, 8);

    // Bind listening socket with this address
    CHECK((bind(serv_sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr))), "Error : bind");

    // Listening
    CHECK(listen(serv_sockfd, NUM_CONN), "Error : listen");

    while (1)
    {
        // Waiting for receiving
        player_tab[countThread].addr_len = sizeof(player_tab[countThread].addr_d); //!\\ Initialization of each player
        CHECK(player_tab[countThread].sfd = accept(serv_sockfd, (struct sockaddr *)&(player_tab[countThread].addr_d),
                                                   &(player_tab[countThread].addr_len)),
              "Error : accept");
        // player_tab[i].status = CONNECTED;
        // Thread creation

        printf("You are Address : %s \t Port : %d \t connected \n", inet_ntoa(player_tab[countThread].addr_d.sin_addr), ntohs(player_tab[countThread].addr_d.sin_port));
   
        pthread_create(&thread, NULL, routine_thread, (void *)&(player_tab[countThread]));
        countThread++;
    }
    freeList();
    return 0;
}

void disconnectPlayer(struct player *player)
{
    for (int i = 0; i < MAXPLAYER; i++)
    {
        if (strlen(player_tab[i].name) != 0)
        {
            if (strcmp(player_tab[i].name, player->name) == 0)
            {
                player->status = OFFLINE;
                break;
            }
        }
    }
};

struct player *searchPlayer(player *pler)
{
    for (int i = 0; i < MAXPLAYER; ++i)
    {
        if (strcmp(pler->name, player_tab[i].name) == 0 && strcmp(pler->pass, player_tab[i].pass))
            return &player_tab[i];
    }

    return NULL;
}

void *routine_thread(void *arg)
{
    // Variable declaration
    player *arg_pl = (player *)arg;
    char buff[MAXBUFF];
    ssize_t sts;
    char cmd[50];
    char addr[50];
    int port;
    int mode; // 0. Host 1. Join
    char name[50];

    //password

    //char password[50];
    int i = 0;
    arg_pl->status = OFFLINE;
    printf(buff, "You are Address : %s \t Port : %d \t connected \n", inet_ntoa(arg_pl->addr_d.sin_addr), ntohs(arg_pl->addr_d.sin_port));
   
    sprintf(buff, "You are Address : %s \t Port : %d \t connected \n", inet_ntoa(arg_pl->addr_d.sin_addr), ntohs(arg_pl->addr_d.sin_port));
    CHECK(send(arg_pl->sfd, buff, strlen(buff) + 1, 0), "Error : write");

    while (1)
    {
        // Receiving a request
        CHECK(sts = recv(arg_pl->sfd, buff, MAXBUFF, 0), "Error : read");
        sscanf(buff, "%s", cmd);
        printf("%s\n", cmd);
        printf("Received : %s \n", buff);
        if (sts == 0)
        {
            printf("Player %s are exiting.\n", arg_pl->name);
            disconnectPlayer(arg_pl);
            pthread_exit(NULL);
        }
        // Compare the request and execute it
        if (!strcmp("LOGIN", cmd))
        {
            // Informations about the player
            sscanf(buff, "LOGIN %s %s", arg_pl->name, arg_pl->pass);

            struct player *temp = searchPlayer(arg_pl);
            if (temp != NULL)
            {
                if (temp->status != OFFLINE && (temp->addr_d.sin_addr.s_addr != arg_pl->addr_d.sin_addr.s_addr))
                {
                    // error same name online
                    printf("Login failed: same name online");
                    sprintf(buff, "LOGIN %s %s", "FAILED", "Login failed: same name online");
                    CHECK(send(arg_pl->sfd, buff, strlen(buff) + 1, 0), "Error : write");

                    arg_pl->status = OFFLINE;
                    pthread_exit(NULL);
                }
                else
                {
                    temp->sfd = arg_pl->sfd;
                    temp->addr_d = arg_pl->addr_d;
                    temp->addr_len = arg_pl->addr_len;
                    temp->status = arg_pl->status;
                    strcpy(temp->name, arg_pl->name);
                    arg_pl->status = ONLINE;
                    arg_pl = temp;
                }
            }

            arg_pl->status = ONLINE;
            sprintf(buff, "LOGIN %s %s %d %s ", arg_pl->name, "OK", arg_pl->status, "Login success");
            CHECK(send(arg_pl->sfd, buff, strlen(buff) + 1, 0), "Error : write");
            //** TEST **//
            printf("Name : %s \t Address : %s \t Port : %d \t  \n", arg_pl->name,
                   inet_ntoa(arg_pl->addr_d.sin_addr), ntohs(arg_pl->addr_d.sin_port));
            //** FIN TEST **//
        }
        else if (!strcmp("GAMES", cmd)) // Scan for games
        {
            printf("Name : %s \t Address : %s \t Port : %d  Status : %d \t  \n", arg_pl->name,
                   inet_ntoa(arg_pl->addr_d.sin_addr), ntohs(arg_pl->addr_d.sin_port), arg_pl->status);
            // Information about the other players
            //Check state
            if (arg_pl->status != ONLINE)
            {
                printf("Wrong state\n");
                pthread_exit(NULL);
            }

            for (i = 0; i < MAXROOM; i++)
            {
                if (arg_pl->status == ONLINE && room_list[i].gameState == INITIAL)
                {
                    printf("Vao games\n");
                    //Update Room
                    room_list[i].gameState = WAITJOINER; //state
                    room_list[i].numPlayer = 1;

                    //Add player ,Update player
                    arg_pl->status = INROOM;
                    room_list[i].playerList[0].sfd = arg_pl->sfd;
                    room_list[i].playerList[0].addr_d = arg_pl->addr_d;
                    room_list[i].playerList[0].addr_len = arg_pl->addr_len;
                    room_list[i].playerList[0].status = arg_pl->status;
                    strcpy(room_list[0].playerList[0].name, arg_pl->name);

                    //strcpy(addr, inet_ntoa(player_tab[i].addr_l.sin_addr));
                    printf("Message: %s\n", buff);
                    //CHECK(send(arg_pl->sfd, buff, strlen(buff) + 1, 0), "Error : write");
                    //CHECK(sts = recv(arg_pl->sfd, buff, MAXBUFF, 0), "Error : read"); //!\\ Synchronize
                    sprintf(buff, "You are: %s create the room with id: %d", arg_pl->name, i);
                    CHECK(send(arg_pl->sfd, buff, strlen(buff) + 1, 0), "Error : write");
                    break;
                }
            }
        }
        else if (!strcmp("JOIN", cmd))
        {
            int room_id;
            //  int room_id=-1;
            sscanf(buff, "%s %d", cmd, &room_id);
            printf("Name : %s \t Address : %s \t Port : %d  Status : %d \t  \n", arg_pl->name,
                   inet_ntoa(arg_pl->addr_d.sin_addr), ntohs(arg_pl->addr_d.sin_port), arg_pl->status);
            printf("Chua Vao roooom\n");

            if (arg_pl->status == ONLINE && (room_list[room_id].gameState != GAMMING && (room_list[room_id].numPlayer >= 1 && room_list[room_id].numPlayer <= 3)))
            {
                //Update Room
                printf("Vao roooom\n");
                //Add player ,Update player
                arg_pl->status = INROOM;
                room_list[room_id].playerList[room_list[room_id].numPlayer].sfd = arg_pl->sfd;
                room_list[room_id].playerList[room_list[room_id].numPlayer].addr_d = arg_pl->addr_d;
                room_list[room_id].playerList[room_list[room_id].numPlayer].addr_len = arg_pl->addr_len;
                room_list[room_id].playerList[room_list[room_id].numPlayer].status = arg_pl->status;
                strcpy(room_list[room_id].playerList[room_list[room_id].numPlayer].name, arg_pl->name);

                room_list[room_id].gameState = AVAILABLE; //start
                //Print server
                printf("Message: %s\n", buff);

                sprintf(buff, "%s join the room id: %d", arg_pl->name, room_id);
                room_list[room_id].numPlayer++;
                send_clients_in_a_room(room_id, buff);
            }
            //Run joinerloop()
        }
        else if (!strcmp("START", cmd)) //Cheack number 0
        {
            gettimeofday(&startTime, NULL);
            int room_id = getRoomIdFromPlayer(arg_pl);
            printf("Message: %s\n", buff);
            if (room_id == -1)
            {
                sprintf("start %s  \t  Status : %d is not in a nay room\n", arg_pl->name, arg_pl->status);
            }
            else
            {
                //Init game
                //String
                //First Turn
                room_list[room_id].gameState = GAMMING;
                strcpy(room_list[room_id].lastWord, "Hoaxinh");
                for (int i = 0; i < room_list[room_id].numPlayer; i++)
                {
                    room_list[room_id].playerList[i].status = INGAME;
                    room_list[room_id].playerTime[i] = 300;
                }
                printf("Room: %d Game start! Player: %s-Status: %d\n", room_id, arg_pl->name, arg_pl->status);
                sprintf(buff, "Room: %d Game start!", room_id);
                send_clients_in_a_room(room_id, buff);
            }
            arg_pl->status = INGAME;
            room_list[room_id].currentTurn = 0;
            room_list[room_id].gameState = GAMMING;
            printf("Current turn : %d --- youturn\n", room_list[room_id].currentTurn);
        }
        else if (!strcmp("PUSHWORD", cmd)) //state GAMMING , in game
        {
            printf("Vao PUSHWORD");
            printf("Message: %s\n", buff);
            char text[20];
            sscanf(buff, "%s %s", cmd, text);
            int room_id = getRoomIdFromPlayer(arg_pl);
            int playerTurn = getPlayerTurn(arg_pl, room_id);
            printf("Current turn : %d --- youturn: %d\n", room_list[room_id].currentTurn, playerTurn);
            if (room_list[room_id].currentTurn == playerTurn)
            {
                int check = checkSpell(text);
                //update  room :turn,allstring,last word
                //update time ????
                //check turn
                if (check == 1)
                {
                    if (checkValidWord(room_list[room_id].lastWord, text) == 1)
                    {
                        sprintf(buff, "%s : %s -%d\n", arg_pl->name, text, strlen(text));
                        gettimeofday(&now, NULL);
                        send_clients_in_a_room(room_id, buff);
                        //update room
                        updateTurn(room_id);
                        strcpy(room_list[room_id].lastWord,text);
                    }
                    else
                    {
                        sprintf(buff, "PUSHWORD  %s %s : %s %s", arg_pl->name, text, "FAILURE", "Word Not Valid");
                        CHECK(send(arg_pl->sfd, buff, strlen(buff) + 1, 0), "Error : write");
                    }
                }
                else
                {
                    sprintf(buff, "PUSHWORD  %s %s : %s %s", arg_pl->name, text, "FAILURE", "Word Not True");
                    CHECK(send(arg_pl->sfd, buff, strlen(buff) + 1, 0), "Error : write");
                }
            }
            else
            {
                sprintf(buff, "PUSHWORD  %s %s : %s %s", arg_pl->name, text, "FAILURE", "Waitting to your turn");
                CHECK(send(arg_pl->sfd, buff, strlen(buff) + 1, 0), "Error : write");
            }
        }
        else if (!strcmp("LEAVE", cmd)) //Check condition cannot in GAmming state, state of player is in room
        {                               //chang state to login
            //chang to online state
            printf("Vao LEAVE");
            printf("Message: %s\n", buff);
            int room_id = getRoomIdFromPlayer(arg_pl);

            printf("%d room", room_id);
            sprintf(buff, "%s Leave the room id: %d", arg_pl->name, i);
            send_clients_in_a_room(room_id, buff);
            int j;
            //room update

            //delete player from a room
            for (j = 0; j < room_list[room_id].numPlayer; j++)
            {
                if ((room_list[room_id].playerList[j].sfd == arg_pl->sfd) &&
                    strcmp(room_list[room_id].playerList[j].name, arg_pl->name) == 0)
                {
                    break;
                }
            }
            printf("Delete Player: %d th\n", j);
            for (int posDelet = j; posDelet < room_list[room_id].numPlayer - 1; posDelet++)
            {
                //room_list[room_id].playerList[posDelet] = room_list[room_id].playerList[posDelet];
                printf("j:%d Ơi : %s\n", j, room_list[room_id].playerList[j].name);
                room_list[room_id].playerList[posDelet].sfd = room_list[room_id].playerList[posDelet + 1].sfd;
                room_list[room_id].playerList[posDelet].addr_d = room_list[room_id].playerList[posDelet + 1].addr_d;
                room_list[room_id].playerList[posDelet].addr_len = room_list[room_id].playerList[posDelet + 1].addr_len;
                room_list[room_id].playerList[posDelet].status = room_list[room_id].playerList[posDelet + 1].status;
                strcpy(room_list[room_id].playerList[posDelet].name, room_list[room_id].playerList[posDelet + 1].name);
            }
            arg_pl->status = ONLINE;
            room_list[room_id].numPlayer--;
            printf("----%d----", room_list[room_id].numPlayer);
            //test
            printf("Room_id :%d\n", room_id);
            for (int i = 0; i < room_list[room_id].numPlayer; i++)
            {
                printf("Name : %s \t Address : %s \t Port : %d  Status : %d \t  \n", room_list[room_id].playerList[i].name,
                       inet_ntoa(room_list[room_id].playerList[i].addr_d.sin_addr), ntohs(room_list[room_id].playerList[i].addr_d.sin_port), room_list[room_id].playerList[i].status);
            }
        }
        else if (!strcmp("LOGOUT", cmd))
        {
            printf("Vao logout\n");
            printf("Message: %s\n", buff);
            //Change to offline state
            arg_pl->status = OFFLINE;
            sprintf(buff, "You are %s logouted", arg_pl->name);
            CHECK(send(arg_pl->sfd, buff, strlen(buff) + 1, 0), "Error : write");

            //test
            //** TEST **//
            printf("Name : %s \t Address : %s \t Port : %d Status: %d \t  \n", arg_pl->name,
                   inet_ntoa(arg_pl->addr_d.sin_addr), ntohs(arg_pl->addr_d.sin_port), arg_pl->status);
            //** FIN TEST **//
        }
    }
    pthread_exit(NULL);
}

void send_clients_in_a_room(int room_id, char *tmp_buffer)
{
    printf("Room_id :%d\n", room_id);
    for (int i = 0; i < room_list[room_id].numPlayer; i++)
    {
        CHECK(send(room_list[room_id].playerList[i].sfd, tmp_buffer, strlen(tmp_buffer) + 1, 0), "Error : write");
    }
}

int checkValidWord(char *lastword, char *newword)
{
    printf("%s--%d-----%s---%d\n", lastword, strlen(lastword), newword,strlen(newword));
    if (lastword[strlen(lastword) - 1] == newword[0])
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int getRoomIdFromPlayer(player *currPlayer)
{
    for (int i = 0; i < MAXROOM; i++)
    {
        for (int j = 0; j < room_list[i].numPlayer; j++)
        {
            if ((room_list[i].playerList[j].sfd == currPlayer->sfd)) //&&strcmp(room_list[i].playerList[j].name, currPlayer->name) == 0
            {
                return i;
            }
        }
    }
    return -1;
}

void displayRoom(int room_id)
{
    char buff[MAXBUFF];
    sprintf("Room: %d status: %d \n Lastword: %s\n currentTurn: %s",room_id,room_list[room_id].gameState,room_list[room_id].lastWord,room_list[room_id].playerList[room_list[room_id].currentTurn].name);
    send_clients_in_a_room(room_id,buff);
}
int getPlayerTurn(player *currPlayer, int room_id)
{

    for (int j = 0; j < room_list[room_id].numPlayer; j++)
    {
        if (strcmp(room_list[room_id].playerList[j].name, currPlayer->name) == 0) //&&strcmp(room_list[i].playerList[j].name, currPlayer->name) == 0
        {
            return j;
        }
    }
    return -1;
}
void updateTurn(int room_id)
{
    int curTurn;
    curTurn = room_list[room_id].currentTurn;
    int maxTurn;
    maxTurn = room_list[room_id].numPlayer - 1;
    if (curTurn == maxTurn)
    {
        curTurn = 0;
    }
    else
    {
        curTurn++;
    }
    room_list[room_id].currentTurn = curTurn;
}

//Function for help checking spell
void load() {
    FILE *f;
    char word[50];
    f = fopen("words.txt", "r");
    if (f == NULL)
    {
        printf("Error!");
        exit(1);
    }
    while (fscanf(f, "%s", word) != EOF)
    {
        node *new;
        new = (node *)malloc(sizeof(node));
        strcpy(new->data, word);
        new->next = NULL;
        if (rootWord == NULL)
        {
            rootWord = new;
            curr = rootWord;
        }
        else
        {
            curr->next = new;
            curr = curr->next;
            curr->next = NULL;
        }    
    };
     printf("Loading dictionanry done......\n");
    fclose(f);
}


void tolowerStr(char *str)
{
    for (int i = 0; str[i]; i++)
    {
        str[i] = tolower(str[i]);
    }
}
int checkSpell(char *wordcheck)
{
    printf("Checkspell\n....");
    tolowerStr(wordcheck);
    node *temp = rootWord;
    printf("\n\nList elements are - \n");
    while (temp != NULL)
    {
        if (strcmp(temp->data, wordcheck) == 0)
        {
            printf("%s----%d\n", temp->data, strlen(temp->data));
            return 1;
        }
        temp = temp->next;
    }
    return -1;
}
void freeList()
{
    struct node *tmp;

    while (rootWord != NULL)
    {
        tmp = rootWord;
        rootWord = rootWord->next;
        free(tmp);
    }
}

//Todo
// check checkSpell
// update time
// game end
//Check login
//Tim hieu them ve signal