//
// Created by John on 06/03/2018.
//

#ifndef PAL_H_INCLUDED
#define PAL_H_INCLUDED
#include "usefull.h"
#define number generateNumber()

void displayState(int* pListOfNumbers,  int  positionOfCursor, int numberOfDigits, int numberOfGoes);
void moveCursorRight( int* pPosOfCursor, int max);
void moveCursorLeft( int* pPosOfCursor, int max);
void incrementDigitInListAtPos(int* pListOfNumbers, int  positionOfCursor);
void decrementDigitInListAtPos(int* pListOfNumbers, int  positionOfCursor);
boolean isPalindrome(int* plistOfNumbers, int size);
char getCommand();
void processCommand(int* pList, int size, int* pPositionOfCursor, char command);
void startGame(int initialNumber);
int initialiseArray(int **pNumbers ,int numbers);
int generateCursorPosition(int size);
int generateNumber();
#endif // PAL_H_INCLUDED