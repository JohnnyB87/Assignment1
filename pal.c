//
// Created by John on 06/03/2018.
//

#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <time.h>
#include "usefull.h"

void displayState(int* pListOfNumbers, int  positionOfCursor, int numberOfDigits, int numberOfGoes)
{
    printf("\n\nGame State: < ");
    char spaces[] = "              ";
    char src[25];
    char cursor[] = "^";
    int i = 0;

    strcpy(src, spaces);
    for(i; i < numberOfDigits; i++){
        printf("%d",*pListOfNumbers);
        pListOfNumbers = pListOfNumbers + 1;
        if(i < positionOfCursor) {
            strcat(src, " ");
        }
    }

    strcat(src, cursor);
    printf(" > Cursor at: %d Goes: %d\n%s\n"
            , positionOfCursor, numberOfGoes, src);
}

void moveCursorRight( int* pPosOfCursor, int max)
{
    int num = *pPosOfCursor;
    if(num == max-1){
        num = 0;
    }
    else{
        num = num + 1;
    }
    *pPosOfCursor = num;
}

void moveCursorLeft( int* pPosOfCursor, int max)
{
    int num = *pPosOfCursor;
    if(num == 0){
        num = max - 1;
    }
    else{
        num = num - 1;
    }
    *pPosOfCursor = num;
}

void incrementDigitInListAtPos(int* pListOfNumbers, int  positionOfCursor){
    if((*(pListOfNumbers + positionOfCursor)) < 9) {
        *(pListOfNumbers + positionOfCursor) = (*(pListOfNumbers + positionOfCursor)) + 1;
    }
    else{
        *(pListOfNumbers + positionOfCursor) = 0;
    }
}

void decrementDigitInListAtPos(int* pListOfNumbers, int  positionOfCursor){
    if((*(pListOfNumbers + positionOfCursor)) > 0) {
        *(pListOfNumbers + positionOfCursor) = (*(pListOfNumbers + positionOfCursor)) - 1;
    }
    else{
        *(pListOfNumbers + positionOfCursor) = 9;
    }
}

boolean isPalindrome(int* plistOfNumbers, int size){
    int half = size/2;
    int i = 0;
    while(i < half){
        int nFront = *(plistOfNumbers + i);
        int nBack = *(plistOfNumbers + (size - (i+1)));

        if(nBack != nFront){
            return False;
        }
        i++;
    }
    return True;
}

char getCommand(){
    char validCharacters[] = {'a','d','w','x'};
    int size = sizeof(validCharacters)/ sizeof(char);
    char choice;

    printf("\nEnter choice: (a, d, w, x)\n");
    while(True) {
        choice = myGetChar();
        for (int i = 0; i < size; i = i + 1) {
            if (choice == validCharacters[i]) {
                return choice;
            }
        }
        printf("\nEnter valid choice: (a, d, w, x)\n");
    }
}

void processCommand(int* pList, int size, int* pPositionOfCursor, char command){
    if(command == 'a'){
        moveCursorLeft(pPositionOfCursor,size);
    }
    else if(command == 'd'){
        moveCursorRight(pPositionOfCursor,size);
    }
    else if(command == 'w'){
        incrementDigitInListAtPos(pList, *pPositionOfCursor);
    }
    else{
        decrementDigitInListAtPos(pList,*pPositionOfCursor);
    }
}

int length(int numbers){
    int counter = 1;

    while(numbers > 9){
        numbers = numbers/10;
        counter++;
    }

    return counter;
}

void initialiseArray(int** pNumbers ,int numbers, int size){
    //int size = getArraySize(numbers);

    *pNumbers = malloc(sizeof(int)*(size));

    for(size; size > 0; size--){
        int n = (numbers % 10);
        (*pNumbers)[size-1] = n;

        numbers = numbers/10;

        printf("list[%d]: %d   n: %d    OAddress: %p     Address: %p\n",
               size-1,
               (*pNumbers)[size-1], n, pNumbers, (pNumbers + (size-1)));
    }
}

int generateCursorPosition(int size){
    srand(time(0));
    int r = rand() % size;

    return r;

}

int generateNumber(){
    srand(time(0));
    int r = rand() * rand();
    int d = rand() % (RAND_MAX-1) + 1;
    printf("r = %d, d = %d, r/d : %d\n",r,d,r/d);

    int n = (10000000001 % r);

    return n;

}

int getUserInput(){
    printf("Enter a Number: ");
    while(True) {

        int num;
        int res = scanf("%d", &num);

        if (res != 1) {
            printf("Enter a Valid Number: ");
//            if (res == EOF) {
//
//            }
            if (res == 0) {
                while (fgetc(stdin) != '\n');
            }
        } else {
            getchar();
            return num;
        }
        printf("\n");

    }
}

void startGame(int initialNumber){

    int *listOfNumbers;
    int numberOfDigits = length(initialNumber);
    initialiseArray(&listOfNumbers, initialNumber, numberOfDigits);
    int positionOfCursor = generateCursorPosition(numberOfDigits);
    int numberOfGoes = 0;

    while(!isPalindrome(listOfNumbers,numberOfDigits)){
        displayState(listOfNumbers,positionOfCursor,numberOfDigits,numberOfGoes);
        char command = getCommand();
        processCommand(listOfNumbers,numberOfDigits,&positionOfCursor,command);
        numberOfGoes++;
    }

    printf("\n\n-------CONGRATULATIONS-------");
    displayState(listOfNumbers,positionOfCursor,numberOfDigits,numberOfGoes);

    free(listOfNumbers);
}

