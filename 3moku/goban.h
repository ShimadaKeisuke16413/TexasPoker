#include<sys/types.h>
#include<stdlib.h>
#include"mylib.h"

#define PORT  (in_port_t)50001
#define HOSTNAME_LENGTH 64

extern void goban_init(int soc,char my_stone,char peer_stone);
extern void goban_show();
extern int goban_peer_turn();
extern int goban_my_turn();
extern void Judge();