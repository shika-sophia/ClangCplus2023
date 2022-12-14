/**
*@directory ClangC11Console / ClanC11Sample / C99YH / C99YH04_ConditionalBranch
*@fileName  MainValidateInputSample.c
*@reference C99YH  é _ wC¾êvO~ObX [üåÒ] æRÅxSB Creative, 2019
*@reference CAnsi  é _ wC¾êvO~ObX [¶@Ò] VÅx  SB Creative, 2006
*@reference C11DS  arton  wÆK C VÅxãÄjÐ, 2018
*
*@content C99YH æSÍ if¶ | Chapter 4 ConditionalBranch ðªò / List 4-3 / p109
*@summary ValidateInputSample.c
*         Validate input / üÍlÌØ
* 
*@English [p] conditional branch:  ðªò
*         [p] validate:    Ø·é
*         [p] expression:  ®, \»
*         [p] operator:    Zq
*         [p] boolean:     ^Ul
*         [p] credibility: M«
* 
*@subject if sentence
*         Eif () { }
*         Eif - else
*         Eif - else if - else
* 
*         [Format]
*         if (conditional expression) { operation of true case }
* 
*         if (conditional expression) {
*            operation of true case 
*         } else {
*            operation of false case
*         }
* 
*         if (conditional expression) {
*            operation of true case 
*         } else if (additonal conditional expression) {
*            operation of this case is true
*         }
*         else {
*            operation of all cases are false
*         }
* 
*@subject Logical operator  _Zq
*         ||: logical or
*         &&: logical and
*         ! : not
* 
*@subject True or False value in C language
*         true:   not 0
*         false:  0
*
*         if ( 1 )    <=>  if (true) 
*         if ( 123 )  <=>  if (true)  
*         if ( 0 )    <=>  if (false) 
* 
*@subject Should not compare both boolean values kC99YH p129, p391l
*         because conditional expression 'x == TRUE' can be false as below [Example].
*         EA if-statement recognize '0' as false and 'not 0' as true.
*           Conditional expression 'x == 0' can be false, though 'not 0' value should be true.
*         EGenerally, the code which verify to equal both boolean values, 
*           is to be low credibility.
* 
*         [~][Example]
*         #define TRUE 1
*         
*         int x = 2;
*         if (x == TRUE) { ... }  -> false, though 'not 0' value should be true.
* 
*         [~][Example]
*         int x = 2;
*         if (x == 0) { ... }     -> false, though 'not 0' value should be true.
* 
*@subject <stdbool.h>
*            ¤ #define true  !0
*            ¤ #define false 0
* 
*         [~][Example]
*         if (x == true) { ... }  -> dengerous code because above.
* 
*@see     
*@author shika
*@date 2022-12-15
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define BUFFER_SIZE 256

void consoleInput(char*, int);

//int main(void) {
int mainValidateInputSample(void) {
    char buffer[BUFFER_SIZE];
    int rainRate;
    
    printf("Please input rain rate > \n");
    consoleInput(buffer, BUFFER_SIZE);
    rainRate = atoi(buffer);

    if (rainRate < 0 || 100 < rainRate) {
        printf("<I> Error: Rain rate should input in range [ 0 - 100 ].\n");
    }
    else if (rainRate >= 50) {
        printf("You should bring umbrella.\n");
    }
    else {
        printf("You need not bring umbrella.\n");
    }

    return 0;
}//main()

//====== already defined in C99YH08_Function\DividedCompile_consoleInputBody.c ======
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
Please input rain rate >
50
You should bring umbrella.

Please input rain rate >
0
You need not bring umbrella.

Please input rain rate >
1500
<I> Error: Rain rate should input in range [ 0 - 100 ].

Please input rain rate >
-1
<I> Error: Rain rate should input in range [ 0 - 100 ].

Please input rain rate >
~m¦
You need not bring umbrella.

yAnalysisz
 Success of Validatation input, when user input numeric.
 Failure that, when user input except of numeric.
 In this case, it cannot validate. 
 The not-numeric input character is changed to 0 by 'atoi()'.
 It need check 'buffer' values are numeric or not.

*/