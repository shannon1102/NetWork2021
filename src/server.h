/**
 * \file	server.h
 * \brief	Header for the server.c file.
 */


#ifndef _SERV_H
#define _SERV_H 1

// Includes
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <pthread.h>
#include <sys/types.h> 
#include <netinet/in.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>
#include <ctype.h>

static struct timeval startTime, now;

/**
 * \brief	Makes sure a system call don't fail
 */
#define CHECK(sts,msg) if ((sts) == -1){ perror(msg); exit(-1);  }

/**
 *	\brief	Maximum lenght of a request
 */
#define MAXBUFF 1024

/**
 * Maximum number of connected players.
 */
#define MAXPLAYER 404

/**
 * \brief	Maximum lenght for a name
 */

#define MAXROOM 20
#define MAXNAME 50
#define MAXPWD 50

/**
 * \brief	Maximum lenght for a password
 */
#define MAXPWD 50

/**
 * \brief	The player status
 * \details	
 */


#define OFFLINE 0  // Create  
#define ONLINE 1	 // 
#define INROOM 2
#define INGAME 3

/**
 * \brief	The Game status
 * \details	
*/
#define INITIAL -1 //Initial
#define WAITJOINER 0 // Onlyhost 
#define AVAILABLE 1 //More than (2 player include host)
#define GAMMING 2  //Game in progress


// Strutures

/**
 * \brief	Structure describing a player
 */
typedef struct player{
	struct sockaddr_in addr_d; //!< Client dialog socket address
	int sfd; //!<Dialog socket with the client
	int addr_len; //!< Lenght of the client's address
	int id;
	char name[MAXNAME]; //!< Player's nickname
	char pass[MAXPWD];
	int status; //!< Player's status
	// int mode; //!< Player's mode
}player;

typedef struct room{
	int id;
	player playerList[4];
	int gameState; // -1 , 0(1 host) , 1 (>=2 ng) ,3 INGAME	
	int currentTurn; //0,1,2,3 ung voi player[0,1,2,3];
	int playerTime[4];
	int numPlayer;
	char string[50]; //2 last words
	char lastWord[25];
	
}room;

// Prototypes
/**
 * \brief	Each client has its own thread.
 * \param	arg	Dummy argument, so the function signature matches a thread routine.
 * \return	Nothing, but has type void* for the same reason.
 */
void* routine_thread(void* );

#endif
