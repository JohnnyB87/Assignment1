//
// Created by John on 06/03/2018.
//

#ifndef PAL_H_INCLUDED
#define PAL_H_INCLUDED
#include "usefull.h"

void displayState(int* pListOfNumbers,  int  positionOfCursor, int numberOfDigits, int numberOfGoes);
void moveCursorRight( int* pPosOfCursor, int max);
void moveCursorLeft( int* pPosOfCursor, int max);
void incrementDigitInListAtPos(int* pListOfNumbers, int  positionOfCursor);
void decrementDigitInListAtPos(int* pListOfNumbers, int  positionOfCursor);
boolean isPalindrome(int* plistOfNumbers, int size);
char getCommand();
void processCommand(int* pList, int size, int* pPositionOfCursor, char command);
void startGame(int initialNumber);
void initialiseArray(int **pNumbers ,int numbers, int size);
int generateCursorPosition(int size);
int generateNumber();
int getUserInput();
int getArraySize(int numbers);
#endif // PAL_H_INCLUDED
