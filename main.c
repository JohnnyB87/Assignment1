#include "pal.h"

int main()
{
    int initialNumber = getUserInput();
//    int initialNumber = generateNumber();
    startGame(initialNumber);
    return 0;
}
