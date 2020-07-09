#include "goban.h"

static char goban_my_stone;
static char goban_peer_stone;

static char goban_plane[6][7]={
             "+1234+",
			       "a....|",
			       "b....|",
			       "c....|",
             "d....|",
			       "+----+"};

static int goban_soc;

void goban_init(int soc,char my_stone,char peer_stone)
{
  goban_soc=soc;
  goban_my_stone=my_stone;
  goban_peer_stone=peer_stone;
}

void init(){
  int i,j;
  for(i=0;i<6;i++){
    for(j=0;j<7;j++){
      if(goban_plane[i][j]=='x'||goban_plane[i][j]=='o'){
        goban_plane[i][j]='.';
      }
    }
  }
}
void goban_show(){
  int i;
  for(i=0;i<6;i++){
    printf("%s\n",goban_plane[i]);
  }
}

int goban_peer_turn(){
  char data[10];
  int x,y;

  read(goban_soc,data,10);

  if(data[0]=='q')return -1;

  y=(int)data[0]-(int)'a'+1;
  x=(int)data[1]-(int)'0';

  goban_plane[y][x]=goban_peer_stone;
  Judge();

  return 1;
}

int goban_my_turn(){
  char data[10];
  int x,y;
 int count=0;
 int i,j;


  while(1){
    fgets(data,10,stdin);
    if(data[0]=='q')
      {
	while(goban_soc,data,1);
	return -1;}
    if(data[0]<'a'||data[0]>'d'||data[1]<'1'||data[1]>'4')
      continue;
    break;
  }

  y=(int)data[0]-(int)'a'+1;
  x=(int)data[1]-(int)'0';
  goban_plane[y][x]=goban_my_stone;

  write(goban_soc,data,10);
  Judge();

  return 1;
}
//勝敗判定
void Judge(){
   int finish=0;
  int i,j;
  int count=0;
  char data[10];
   int soc;
  char my_stone='o';
  char peer_stone='x';
  //サーバ側の勝利判定
  //横判定
  for(i=1;i<5;i++){
    for(j=1;j<5;j++){
      if(goban_plane[i][j]=='o'){
        count++;
      }
      
      }
      if(count>=4){
        printf("サーバーの勝ちです\n");
        finish=1;
    }
    count=0;
  }
  //縦判定
  for(i=1;i<5;i++){
    for(j=1;j<5;j++){
      if(goban_plane[j][i]=='o'){
        count++;
      }
      
      }
      if(count>=4){
        printf("サーバーの勝ちです\n");
         finish=1;
    }
    count=0;
  }
//斜め判定
for(i=1;i<5;i++){
      if(goban_plane[i][i]=='o'){
        count++;
      }
      if(count>=4){
        printf("サーバーの勝ちです\n");
         finish=1;
    }
  }
    count=0;
    for(i=1;i<5;i++){
      if(goban_plane[i][5-i]=='o'){
        count++;
      }
      if(count>=4){
        printf("サーバーの勝ちです\n");
         finish=1;
    }
  }
    count=0;

  //クライアント側の勝利判定
  //横判定
  for(i=1;i<5;i++){
    for(j=1;j<5;j++){
      if(goban_plane[i][j]=='x'){
        count++;
      }
      
      }
      if(count>=4){
        printf("クライアントの勝ちです\n");
         finish=1;
    }
    count=0;
  }
  //縦判定
  for(i=1;i<5;i++){
    for(j=1;j<5;j++){
      if(goban_plane[j][i]=='x'){
        count++;
      }
      
      }
      if(count>=4){
        printf("クライアントの勝ちです\n");
         finish=1;
    }
    count=0;
  }
//斜め判定
for(i=1;i<5;i++){
      if(goban_plane[i][i]=='x'){
        count++;
      }
      if(count>=4){
        printf("クライアントの勝ちです\n");
         finish=1;
    }
  }
    count=0;
    for(i=1;i<5;i++){
      if(goban_plane[i][5-i]=='x'){
        count++;
      }
      if(count>=4){
        printf("クライアントの勝ちです\n");
         finish=1;
    }
  }
    count=0;

if(finish==1){
  printf("ゲームが終了しました\nもう一回：a  終了:q\n");
  while(1){
    fgets(data,10,stdin);
    if(data[0]=='q')
      {
        return -1;
      }
  if(data[0]=='a'){
     finish=0;
     init();
     return -1;
  }
    if(data[0]!='a'||data[0]!='q')
      continue;
    break;
  }
  return 1;
}

}
void goban_destroy(){
  close(goban_soc);
}
