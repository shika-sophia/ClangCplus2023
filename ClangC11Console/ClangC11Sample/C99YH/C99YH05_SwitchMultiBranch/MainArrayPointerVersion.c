/**
*@directory ClangC11Console / ClanC11Sample / C99YH / C99YH05_SwitchMultiBranch
*@fileName  MainArrayPointerVersion.c
*@based     PracticeC99YH05.c
*@reference C99YH  åãèÈ ç_ ÅwCåæåÍÉvÉçÉOÉâÉ~ÉìÉOÉåÉbÉXÉì [ì¸ñÂï“] ëÊÇRî≈ÅxSB Creative, 2019
*@reference CAnsi  åãèÈ ç_ ÅwCåæåÍÉvÉçÉOÉâÉ~ÉìÉOÉåÉbÉXÉì [ï∂ñ@ï“] êVî≈Åx  SB Creative, 2006
*@reference C11DS  arton  Åwì∆èK C êVî≈Åx„ƒâjé–, 2018
*
*@content C99YH ëÊÇTèÕ Switch | Chapter 5 Practice 5-1 / List A5-1c / p151
*@summary Practice 5-1 ArrayPointer Version
*         It uses Array and Pointer instead of switch() in [Book Answer] Practice 5-1
*         -> Array   ÅkChapter  9Ål
*         -> Pointer ÅkChapter 11Ål
* 
*@subject Array
*         char* week[] = {
*            "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday",
*         };
*         
*         Å¶ When it is defined in Field, it should be described 
*           'char *week[] = { ... };'.
*           I don't find the reason yet.
* 
*@see PracticeC99YH05.c
*@author shika
*@date 2022-12-17
*/

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 256

void consoleInput(char*, int);

//int main(void) {
int mainArrayPointerVersion(void) {
    char buffer[BUFFER_SIZE];
    int canInput = 0; // as boolean (default false)
    int input;
    int min = 1;
    int max = 7;

    char* week[] = {
        "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday",
    };

    //---- Loop Question ----
    while (!canInput) {
        printf("ÅüPlease input in range [ %d - %d ] > ", min, max);
        consoleInput(buffer, BUFFER_SIZE);
        input = atoi(buffer);

        //---- Validate Input ----
        if (min <= input && input <= max) {
            canInput = 1;  // to break while()
        }
        else {
            printf("<ÅI> It should be input in range [ %d - %d ].\n", min, max);
            continue;
        }
    }//while

    printf("%d: %s\n", input, week[input - 1]);  // Array index start from 0.

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
ÅüPlease input in range [ 1 - 7 ] > 1  // Array index: 0
1: Sunday
ÅüPlease input in range [ 1 - 7 ] > 2  // Array index: 1
2: Monday
     :
ÅüPlease input in range [ 1 - 7 ] > 7  // Array index: 6
7: Saturday

//---- Test of invalid input ----
ÅüPlease input in range [ 1 - 7 ] > 0
<ÅI> It should be input in range [ 1 - 7 ].
ÅüPlease input in range [ 1 - 7 ] > 8
<ÅI> It should be input in range [ 1 - 7 ].
ÅüPlease input in range [ 1 - 7 ] > Number
<ÅI> It should be input in range [ 1 - 7 ].
ÅüPlease input in range [ 1 - 7 ] > î‘çÜ
<ÅI> It should be input in range [ 1 - 7 ].
ÅüPlease input in range [ 1 - 7 ] > 99999999999999999999999999999999999999999999
<ÅI> It should be input in range [ 1 - 7 ].
ÅüPlease input in range [ 1 - 7 ] > 2.5
2: Monday  // [Å~] unexpected result
ÅüPlease input in range [ 0 - 8 ] > 8   // Array index: 7
8: (null)  // when max value is 8, It seems to throw ArrayIndexOutOfRangeException in [Java, C#].

ÅyAnalysisÅz
 Array index start from 0. 
 Though min value had better be 0, it is wrong.
 Because Not-numeric input is changed 0 by 'atoi()'
 and validating input need use 0 value,
 min value must be 1.
*/