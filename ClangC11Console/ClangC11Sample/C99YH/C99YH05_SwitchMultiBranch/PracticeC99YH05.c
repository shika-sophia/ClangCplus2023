/**
*@directory ClangC11Console / ClanC11Sample / C99YH / C99YH05_SwitchMultiBranch
*@fileName  PracticeC99YH05.c
*@reference C99YH  åãèÈ ç_ ÅwCåæåÍÉvÉçÉOÉâÉ~ÉìÉOÉåÉbÉXÉì [ì¸ñÂï“] ëÊÇRî≈ÅxSB Creative, 2019
*@reference CAnsi  åãèÈ ç_ ÅwCåæåÍÉvÉçÉOÉâÉ~ÉìÉOÉåÉbÉXÉì [ï∂ñ@ï“] êVî≈Åx  SB Creative, 2006
*@reference C11DS  arton  Åwì∆èK C êVî≈Åx„ƒâjé–, 2018
*
*@content C99YH ëÊÇTèÕ ó˚èKñ‚ëË | Chapter 5 / List A5-1 / p145
*@subject Practice 5-1  Make the program below.
*         It ask integer in range [1 - 6].
*         It show 1: Sunday, 2: Monday, ...
*         
*         -> [My Answer] below
*         -> [Book Answer] ArrayPointer Version
*            seeÅkMainArrayPointerVersion.cÅl
* 
*@subject Practice 5-2
*         What does it output, when executed 'n = 1; switch(2 * n + 1) { ... }' ?
* 
*         -> [My Answer] Compile Error: 
               because switch argument should be constant value.
*              '2 * n + 1' is not constant, but variable in any case.
*         => Å~ Wrong
*         => [Book Answer] It outputs '3'.
*              because '2 * n + 1' is constant value, at just time when compiled.
* 
*@subject Practice 5-3
*         What does it output, when n = -1; switch (n * n + 1) { case 2: if(n > 0){ C } else { D } }
*         
*         -> [My Answer] It outputs 'D'.
*         => ÅZ Correct
*
*@subject Practice 5-4  Seek 4 Wrong point.
*         Row    Å~ Wrong                   -> ÅZ Correct
*         16,17: Label termination is ';'  -> ':'
*         19:    not exist 'break;'        -> break;
*         20:    'a' is duplicated         -> 'b'
*         25:    'defoult'                 -> 'default'
*         => ÅZ Correct all
* 
*@see
*@author shika
*@date 2022-12-18
*/

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 256

void consoleInput(char*, int);

//int main(void) {
int mainPracticeC99YH05(void) {
    char buffer[BUFFER_SIZE];
    char* message;
    int canInput = 0; // as boolean (default false)
    int input;
    int min = 1;
    int max = 7;

    //---- Loop Question ----
    while (!canInput) {
        printf("ÅüPlease input in range [ 1 - 7 ] > ");
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

    switch (input) {
    case 1:
        message = "Sunday";
        break;
    case 2:
        message = "Monday";
        break;
    case 3:
        message = "Tuesday";
        break;
    case 4:
        message = "Wednesday";
        break;
    case 5:
        message = "Thursday";
        break;
    case 6:
        message = "Friday";
        break;
    case 7:
        message = "Saturday";
        break;
    default:  //NOT REACHED
        message = "<ÅI> Program Error in 'input' value.";
    }//switch

    printf("%d: %s \n", input, message);

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
ÅüPlease input in range [ 1 - 7 ] > 1
1: Sunday
ÅüPlease input in range [ 1 - 7 ] > 2
2: Monday
ÅüPlease input in range [ 1 - 7 ] > 3
3: Tuesday
     :

//---- Test of invalid input ----
ÅüPlease input in range [ 1 - 7 ] > 0
<ÅI> It should be input in range [ 1 - 7 ].
ÅüPlease input in range [ 1 - 7 ] > 8
<ÅI> It should be input in range [ 1 - 7 ].
ÅüPlease input in range [ 1 - 7 ] > Number
<ÅI> It should be input in range [ 1 - 7 ].
ÅüPlease input in range [ 1 - 7 ] > 999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999
<ÅI> It should be input in range [ 1 - 7 ].
ÅüPlease input in range [ 1 - 7 ] > 1.5
1: Sunday   // [Å~] unexpected result
ÅüPlease input in range [ 1 - 7 ] > 0
0: <ÅI> Program Error in 'input' value.  // when min value change to 0, and input 0

*/