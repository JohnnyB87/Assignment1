#include "pal.h"
#include <stdio.h>
#include <stdlib.h>

void startGame(int initialNumber){

    int *listOfNumbers;
    int numberOfDigits = getSize(initialNumber);
    initialiseArray(&listOfNumbers, initialNumber, numberOfDigits);
    int positionOfCursor = generateCursorPosition(numberOfDigits);
    int numberOfGoes = 0;
    char command;

    while(!isPalindrome(listOfNumbers,numberOfDigits)){
        displayState(listOfNumbers,positionOfCursor,numberOfDigits,numberOfGoes);
        command = getCommand(listOfNumbers,positionOfCursor,numberOfDigits,numberOfGoes);
        processCommand(listOfNumbers,numberOfDigits,&positionOfCursor,command);
        numberOfGoes++;
    }

    printf("\n\n-------CONGRATULATIONS-------");
    displayState(listOfNumbers,positionOfCursor,numberOfDigits,numberOfGoes);

    free(listOfNumbers);
}

int main()
{
    int initialNumber = getUserInput();
//    initialNumber = generateNumber();
    startGame(initialNumber);
    return 0;
}

