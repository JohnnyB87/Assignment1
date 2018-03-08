//
// Created by John on 06/03/2018.
//

#include <stdio.h>
#include "usefull.h"

//--------------------------------------------------
// my_getchar
//--------------------------------------------------
char myGetChar() {
    //1. We create the output variable with the value the user has input by keyboard
    char res = getchar();

    //2. We discard any extra character the user has input by keyboard
    boolean finish = False;
    char dummy_char = res;

    while (finish == False) {
        if (dummy_char == '\n')
            finish = True;
        else
            dummy_char = getchar();
    }

    //3. We return the output variable
    return res;
}
