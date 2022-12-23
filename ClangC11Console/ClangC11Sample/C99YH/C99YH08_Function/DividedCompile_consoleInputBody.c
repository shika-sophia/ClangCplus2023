/**
*@directory ClangC11Console / ClanC11Sample / C99YH / C99YH08_Function
*@fileName  DividedCompile_consoleInputBody.c
*@see       consoleInput.h
*@see       MainDividedCompileSample.c
*@copyFrom  C99YH03_Variable / MainConsoleInputSample.c
*@author shika
*@date 2022-12-24
*/

#include <stdio.h>
#include "consoleInput.h"

void consoleInput(char* buffer, int bufferSize) {
    char* inputAry = fgets(buffer, bufferSize, stdin);

    if (inputAry == NULL) {
        buffer[0] = '\0';
        return;
    }

    for (int i = 0; i < bufferSize; i++) {
        if (buffer[i] == '\n') {
            buffer[i] = '\0';
            return;
        }
    }//for
}//consoleInput()