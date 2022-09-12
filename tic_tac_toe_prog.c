/**
 * @file tic_tac_toe_prog.c
 * @author Youssef Abdelmajeed (youssefabdelmajeed77@gmail.com)
 * @brief tic tac toe implementaion file 
 * @version 0.1
 * @date 2022-07-8
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "tic_tac_toe_int.h"
// global variables 
char board[10]={} ; // stores the played character in the correct postion 0 not used 

short boardPos[10] = {//holds the numerical position of the board array 
                       0,
                       1,2,3,
                       4,5,6,
                       7,8,9};

void restBoard(void){
    for(short i =1 ;i<10;i++){
        board[i]=' ' ;
    }
    return ; 
}
void drawBoard(void){
    // the following block will clear the screen 

    //---------------------------------------------------
    #ifdef __unix__ // if the os is linux based 
    system("clear") ; //clears the screen 
    #elif defined(_WIN32) ||defined(WIN32) // if the os is windows 
    system("cls") ; //clears the screen 
    #endif
    //---------------------------------------------------

    printf("----------- tic tac toe -----------\n\n") ; 
    short index = 1 ; //counter for only the board elements  
    for(short i=1;i<=25;i++){ //is use to draw the board array + | sperating the board elements and  ___  
        if(i==2||i==4||i==12||i==14||i==22||i==24){ // this is responsible for displaying the board vertical separator
            printf("  |  ") ;
        }
        if((i>5&&i<11)||(i>15&&i<21)){
            printf((i%2==0)?" ___  ":"   ") ; // this is responsible for displaying the board horizontal separator   ___ 
            printf((i==10||i==20)?"\n\n":""); 
        }
        else if (i==1||i==3||i==5||i==11||i==13||i==15||i==21||i==23||i==25){
            if(board[index]==' '){ // if the board elemet was empty print the postion of the element 
                printf((index%3==0)?" %2hd\n":" %2hd ",boardPos[index]);
            }
            else{ // if not empty print the player charater  X or O 
                printf((index%3==0)?" %2c\n":" %2c ",board[index]); 
            }
            index++ ; //next board element 
        }
    }
    printf("\n");
    return ; 
}
_Bool turn(short player){
    short index = 0 ; 
    printf("player-%d Enter 1-9 to play> ",player) ;
    scanf("%hd",&index) ; 
    if(checkValidGame(index)){
        board[index]=(player==1)?'X':'O' ;    // if the game is valid store X or O in board array    
        return 1 ;
    } 
    else{
        return 0 ; 
    }
}
_Bool checkValidGame(short index){
    if(index>0&&index<10&&board[index]==' '){ //the game is considered valid if the number between 1-9 and the selected postion is empty 
        return 1 ;
    }
    else{
        return 0; 
    }
}
_Bool checkWinner(void){
  for(short i=0 ;i<=6;i+=3){ // 3 horizontal checks of the board 
    if((board[i+1]==board[i+2])&&(board[i+1]==board[i+3])&&(board[i+1]!=' ')){  
        return 1;  
    }
  }
  for(short i=0 ; i<3;i++){ // 3 vertical checks of the board 
    if((board[i+1]==board[i+4])&&(board[i+1]==board[i+7])&&(board[i+1]!=' ')){
        return 1;  
    }
  }
    //diagonal  checks of the board 
  if((board[1]==board[5])&&(board[1]==board[9])&(board[1]!=' ')){
    return 1;
  }
  if((board[3]==board[5])&&(board[3]==board[7])&&(board[3]!=' ')){
    return 1;
  }
  return 0 ;
}