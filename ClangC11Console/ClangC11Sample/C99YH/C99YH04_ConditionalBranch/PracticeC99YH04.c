/**
*@directory ClangC11Console / ClanC11Sample / C99YH / C99YH04_ConditinalBranch
*@fileName  PracticeC99YH04.c
*@reference C99YH  åãèÈ ç_ ÅwCåæåÍÉvÉçÉOÉâÉ~ÉìÉOÉåÉbÉXÉì [ì¸ñÂï“] ëÊÇRî≈ÅxSB Creative, 2019
*@reference CAnsi  åãèÈ ç_ ÅwCåæåÍÉvÉçÉOÉâÉ~ÉìÉOÉåÉbÉXÉì [ï∂ñ@ï“] êVî≈Åx  SB Creative, 2006
*@reference C11DS  arton  Åwì∆èK C êVî≈Åx„ƒâjé–, 2018
*
*@content C99YH ëÊÇSèÕ ó˚èKñ‚ëË | Chapter 4 Practice / List A4-2 / p124
* 
*@English [âp] conditional branch:  èåèï™äÚ
*         [âp] expression:  éÆ, ï\åª
*         [âp] proposition: ñΩëË
*         [âp] substitute:  ë„ì¸Ç∑ÇÈ
*         [âp] appropriate: ìKêÿÇ»
* 
*@subject Practice 4-1  True or False
*         ÅZ (1) When n value is 3, Proposition 'n > 3' is false.
*             -> True
*         Å~ (2) Proposition 'n is equal or over 0, under 20' can be described '0 <= n < 20' as conditional expression.
*             -> False, Compile Error.
*                It should be describe '0 <= n || n < 20'.
*             => Correctly '0 <= n && n < 20' 
*         ÅZ (3) Proposition 'n value equals 3.14' is described 'n = 3.14' as conditional expression.
*             -> False, it means substitute 3.14 to n value.
*             It should be described 'n == 3.14'.
* 
*@subject Practice 4-2
*         ÅüGreeting Program
*         It asks user 'What o'clock?', 
*         it shows appropriate greeting with condition below.
* 
*         [Input Range]  0 - 23
*         [Condition]
*         ÅEbefore noon: 0 - 11
*         ÅEnoon:        12
*         ÅEafter noon:  13 - 18
*         ÅEnight:       19 - 23
* 
*@subject Practice 4-3
*         '0 is false, not 0 is true' in C language.
*         Are these same operation, below ?
*         variable x is int type and has value.
*         (1)  if ( x ) { operation... }
*         (2)  if ( x == 1 ) { operation... }
* 
*         -> [My Answer]
*            No, I dont't think so. because...
*            when x == 0, both are false: do no operation.
*            when x == 1, both are true:  do the operation.
*            when x == 123, (1) is true, (2) is false. these are different moves. 
* 
*         => According to [Book Answer] p128, 
*            ÅE<stdbool.h> define 'true', 'false'.
*            ÅE[Å~] Don't compare between boolean values,
*                  for example 'if (x == true)' or '#define TRUE 1  if (x == TRUE)',
*                  because it is not safe:
*                  When x == 2 were true value, these expression is false.
* 
*@see
*@author shika
*@date 2022-12-16
*/

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 256
void consoleInput(char*, int);

//int main(void) {
int mainPracticeC99YH04(void) {
    char buffer[BUFFER_SIZE];
    int canInput = 0; // as boolean (default false)
    int hour;

    printf("ÅüGreeting Program\n");
    
    //---- Loop Question ----
    while (!canInput) {
        printf("ÅñWhat o'clock ? > ");
        consoleInput(buffer, BUFFER_SIZE);
        hour = atoi(buffer);

        //---- Validate Input ----
        if (0 <= hour && hour <= 23) {
            canInput = 1;  // to break while()
        }
        else {
            printf("<ÅI> The o'clock should be input in range [ 0 - 23 ].\n");
            continue;
        }
    }//while

    //---- Conditinal Branch & show Greeting ----
    if (0 <= hour && hour <= 11) {
        printf("Good Morning.\n");
    }
    else if (hour == 12) {
        printf("Let's take lunch.\n");
    }
    else if (13 <= hour && hour <= 18) {
        printf("Good Afternoon.\n");
    }
    else if (19 <= hour && hour <= 23) {
        printf("Good Night.\n");
    }

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
ÅüGreeting Program
ÅñWhat o'clock ? > 8
Good Morning.

ÅüGreeting Program
ÅñWhat o'clock ? > 12
Let's take lunch.

ÅüGreeting Program
ÅñWhat o'clock ? > 18
Good Afternoon.

ÅüGreeting Program
ÅñWhat o'clock ? > 22
Good Night.

ÅüGreeting Program
ÅñWhat o'clock ? > -1
<ÅI> The o'clock should be input in range [ 0 - 23 ].
ÅñWhat o'clock ? > 24
<ÅI> The o'clock should be input in range [ 0 - 23 ].
ÅñWhat o'clock ? > éûä‘
Good Morning.  // (unsolved problem)

ÅyAnalysisÅz
 The asking loop in case of invalid input, successed.
 It leaves '(unsolved problem)' that it should validate in case of not-numeric input.
*/