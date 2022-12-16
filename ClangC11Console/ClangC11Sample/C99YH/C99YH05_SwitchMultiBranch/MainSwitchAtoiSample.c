/**
*@directory ClangC11Console / ClanC11Sample / C99YH / C99YH05_SwitchMultiBranch
*@fileName  MainSwitchAtoiSample.c
*@reference C99YH  結城 浩 『C言語プログラミングレッスン [入門編] 第３版』SB Creative, 2019
*@reference CAnsi  結城 浩 『C言語プログラミングレッスン [文法編] 新版』  SB Creative, 2006
*@reference C11DS  arton  『独習 C 新版』翔泳社, 2018
*
*@content C99YH 第５章 Switch | Chapter 5 / List 5-1 / p136
*@summary switch
*         fgets()
*         atoi()
*
*@subject switch sentence
* 
*         [Format]
*         switch (expression of integer) {
*         case X:                    // Label, Value
*             //operation of case X
*             break;                 // to break out of this Label
*         case Y:
*             //operation of case Y
*             break;
*           :
*         default:                   // default Label
*             break;
*         }
* 
*@see MainSwitchGetcharSample.c
*@author shika
*@date 2022-12-17
*/

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 256

void consoleInput(char*, int);

//int main(void) {
int mainSwitchAtoiSample(void) {
    char buffer[BUFFER_SIZE];
    int canInput = 0; // as boolean (default false)
    int select;

    printf("◆Menu\n");
    printf("  1. Coffee\n");
    printf("  2. Milk\n");
    printf("  3. (neither)\n");
    printf("\n");

    //---- Loop Question ----
    while (!canInput) {
        printf("＊Please select your order > ");
        consoleInput(buffer, BUFFER_SIZE);
        select = atoi(buffer);

        //---- Validate Input ----
        if (1 <= select && select <= 3) {
            canInput = 1;  // to break while()
        }
        else {
            printf("<！> The select should be done in range [ 1 - 3 ].\n");
            continue;
        }
    }//while

    //---- switch & show confirmation ----
    switch (select) {
    case 1:
        printf("You selected Coffee.\n");
        break;

    case 2:
        printf("You selected Milk.\n");
        break;

    case 3:
        printf("You selected '(neither)'.\n");
        break;
    default:
        printf("<！> Program Error in 'select' value = %d\n", select);
        break;
    }//switch
    printf("\n");

    return 0;
}//main()

//====== already defined in C99YH03_Variable/MainConsoleInputSample.c ======
//void consoleInput(char* buffer, int bufferSize) {
//    char* inputAry = fgets(buffer, bufferSize, stdin);
//
//    if (inputAry == NULL) {
//        buffer[0] = '\0';
//        return;
//    }
//
//    for (int i = 0; i < bufferSize; i++) {
//        if (buffer[i] == '\n') {
//            buffer[i] = '\0';
//            return;
//        }
//    }//for
//}//consoleInput()

/*
//====== Result ======
◆Menu
  1. Coffee
  2. Milk
  3. (neither)

＊Please select your order > 1
You selected Coffee.

◆Menu
  1. Coffee
  2. Milk
  3. (neither)

＊Please select your order > 2
You selected Milk.

◆Menu
  1. Coffee
  2. Milk
  3. (neither)

＊Please select your order > 3
You selected '(neither)'.

＊Please select your order > 0
<！> Program Error in 'select' value = 0
【Analysis】
when validation condition is '0 <= select', input 0 can be through validation.
Correctly, it should be '0 < select' or '1 <= select'.

//---- Test of invalid input ----
＊Please select your order > 7
<！> The select should be done in range [ 1 - 3 ].
＊Please select your order > -1
<！> The select should be done in range [ 1 - 3 ].
＊Please select your order > 0.5
<！> The select should be done in range [ 1 - 3 ].
＊Please select your order > 999999999999999999999999999
<！> The select should be done in range [ 1 - 3 ].
＊Please select your order > select
<！> The select should be done in range [ 1 - 3 ].
＊Please select your order > Tea
<！> The select should be done in range [ 1 - 3 ].
＊Please select your order > 123
<！> The select should be done in range [ 1 - 3 ].
＊Please select your order > 1g
You selected Coffee.  //(unsolved problem)
＊Please select your order > 2.5
You selected Milk.    //(unsolved problem)

【Analysis】
 when user input '123', it correctly recognized as numeric 123.
 when user input '1g',  it unexpectedly recognaized '1', not Label 'default:'.
 This is "unsolved problem" yet.
*/