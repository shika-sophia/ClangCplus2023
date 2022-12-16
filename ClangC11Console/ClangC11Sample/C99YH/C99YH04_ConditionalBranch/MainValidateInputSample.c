/**
*@directory ClangC11Console / ClanC11Sample / C99YH / C99YH04_ConditionalBranch
*@fileName  MainValidateInputSample.c
*@reference C99YH  結城 浩 『C言語プログラミングレッスン [入門編] 第３版』SB Creative, 2019
*@reference CAnsi  結城 浩 『C言語プログラミングレッスン [文法編] 新版』  SB Creative, 2006
*@reference C11DS  arton  『独習 C 新版』翔泳社, 2018
*
*@content C99YH 第４章 if文 | Chapter 4 ConditionalBranch 条件分岐 / List 4-3 / p109
*@summary ValidateInputSample.c
*         Validate input / 入力値の検証
* 
*@English [英] conditional branch:  条件分岐
*         [英] validate:    検証する
*         [英] expression:  式, 表現
*         [英] operator:    演算子
* 
*@subject if sentence
*         ・if () { }
*         ・if - else
*         ・if - else if - else
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
*@subject Logical operator  論理演算子
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
*@see
*@author shika
*@date 2022-12-15
*/

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 256

void consoleInput(char*, int);

//int main(void) {
int mainValidateInputSample(void) {
    char buffer[BUFFER_SIZE];
    int rainRate;
    
    printf("◆Please input rain rate > \n");
    consoleInput(buffer, BUFFER_SIZE);
    rainRate = atoi(buffer);

    if (rainRate < 0 || 100 < rainRate) {
        printf("<！> Error: Rain rate should input in range [ 0 - 100 ].\n");
    }
    else if (rainRate >= 50) {
        printf("You should bring umbrella.\n");
    }
    else {
        printf("You need not bring umbrella.\n");
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
◆Please input rain rate >
50
You should bring umbrella.

◆Please input rain rate >
0
You need not bring umbrella.

◆Please input rain rate >
1500
<！> Error: Rain rate should input in range [ 0 - 100 ].

◆Please input rain rate >
-1
<！> Error: Rain rate should input in range [ 0 - 100 ].

◆Please input rain rate >
降水確率
You need not bring umbrella.

【Analysis】
 Success of Validatation input, when user input numeric.
 Failure that, when user input except of numeric.
 In this case, it cannot validate. 
 The not-numeric input character is changed to 0 by 'atoi()'.
 It need check 'buffer' values are numeric or not.

*/