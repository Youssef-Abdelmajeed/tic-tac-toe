/**
 * @file main.c
 * @author Youssef Abdelmajeed (youssefabdelmajeed77@gmail.com)
 * @brief simple tic tac toe game 
 * @version 0.1
 * @date 2022-07-8
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include"tic_tac_toe_int.h"

int main(int argc,char **argv){
    char playAgain ='y'  ; 
    while(playAgain=='y'){  // if the player want to play again 
        _Bool winner = 0 ; // set to be no winners 
        short player =1; // starts with player 1 
        restBoard();     // rest the board 
        while (!winner){ //while no winners 
            drawBoard(); //draw the board 
            if (player==10){ //checks if the game is draw after 9 turns 
                printf("draw\n") ; 
                break;
            }
            player += turn((player%2==0)?2:1); //get the next player if the played turn is valid  
           winner = checkWinner() ;  // check for winner
        }
        //if there is a winner 
        drawBoard(); // draw the board to show the last played game 
        printf("The winner is player: %hd\n",(player%2==0)?1:2) ; // print the winner of the game 
        printf("Do you want to play again ? y/n : ") ; 
        getchar() ; // get the newline  
        scanf( "%c", &playAgain ) ; // get the ans form the player 
    }
    return 0 ; 
}