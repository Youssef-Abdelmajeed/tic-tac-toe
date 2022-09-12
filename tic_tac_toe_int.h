/**
 * @file tic_tac_toe_int.h
 * @author Youssef Abdelmajeed (youssefabdelmajeed77@gmail.com)
 * @brief tic tac toe game interface file 
 * @version 0.1
 * @date 2022-07-8
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef __TIC_H_
#define __TIC_H_

#include<stdio.h> 
#include<stdlib.h>
/**
 * @brief store the empty char  in element of the board array of type char  
 * depends
 *  global 
 *      char board[10]  
 */
void restBoard(void); 

/**
 * @brief print the board array elements and the board drawing it
 *  ,depends
 *      global 
 *       char board[10]  
 *       int boardpos[10] 
 */
void drawBoard(void); // draw the board and the played games

/**
 * @brief checks if the played game position is valid 
 * 
 * @param index which holds the player played postion
 * @return _Bool indcate whither the played potion is valid 1 or not 0
 */
_Bool checkValidGame(short index); 

/**
 * @brief gets the played postion and checks if this postion is valid using  checkValidGame() if valid porceed with next turn 
 * 
 * @param player which holds current player number probably 1 - 2
 * @return _Bool indcate whither to proceed to the next turn 1 or not 0 
 */
_Bool turn(short player); 

/**
 * @brief  checks all winning conditions of the game (vertical-horizontal-cross)
 * 
 * @return _Bool bool to indcate if there is a winner 1 or not 0
 */
_Bool checkWinner(void) ;  

#endif