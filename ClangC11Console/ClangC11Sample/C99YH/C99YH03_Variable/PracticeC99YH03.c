/**
*@directory ClangC11Console / ClanC11Sample / C99YH / C99YH00_
*@fileName  Main.c
*@reference C99YH  結城 浩 『C言語プログラミングレッスン [入門編] 第３版』SB Creative, 2019
*@reference CAnsi  結城 浩 『C言語プログラミングレッスン [文法編] 新版』  SB Creative, 2006
*@reference C11DS  arton  『独習 C 新版』翔泳社, 2018
*
*@content C99YH 第３章 練習問題 / List 3-8 / p91
*@subject Practice 3-1  True or False
*         〇 (1) A variable name 'i' is usually int type. 
*                  -> false: 'i' should be defined as int or else.
*                  variable name is not concerned with the variable type.
*         〇 (2) When int x = 3, x value after executing 'x = x + 1;' is 4. 
*                 -> true: calculator '=' means 'substitute. 
*                    It is no problem that variable 'x' exist both side of '='.
*         〇 (3) I wanted that value of int n would be 0, I described 'n = "0"; '.  
*                  -> wrong: compile error.
*                     The double quatation["] express string value.
*                     So "0" cannot substitute into int n. you should describe 'int n = 0'.
*         〇 (4) I tried to verify that m value equals n value, I described 'm = n'.
*                  -> wrong: calculator '=' means 'substitute', calculator '==' means 'equal'.
*                     So you should describe 'm == n'.
*            
*@subject Practice 3-2  Make Program as below
*         It ask two persons name and age.
*         It output the average of two person's ages.
* 
*@see
*@author shika
*@date 2022-12-14
*/

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 256

void consoleInput(char* buffer, int bufferSize);  //already definied in MainConsoleInputSample.c

//int main(void) {
int mainPracticeC99YH03(void) {
    char buffer[BUFFER_SIZE];
    char *name1;
    char *name2;
    int age1;
    int age2;
    double average;
    
    printf("◆Please tell me two person's name and age\n");
    printf("＊First person's name > ");
    consoleInput(buffer, BUFFER_SIZE);
    name1 = buffer;

    printf("＊First person's age > ");
    consoleInput(buffer, BUFFER_SIZE);
    age1 = atoi(buffer);

    printf("＊Second person's name > ");
    consoleInput(buffer, BUFFER_SIZE);
    name2 = buffer;

    printf("＊Second person's age > ");
    consoleInput(buffer, BUFFER_SIZE);
    age2 = atoi(buffer);

    average = (age1 + age2) / 2.0;

    printf("---- Result ----\n");
    printf("We preciate your corporation.\n");
    printf("The average of %s san and %s san ages is %.2f \n", name1, name2, average);

    return 0;
}//main()

//====== already definied in MainConsoleInputSample.c ======
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
//====== Command Prompt ======
>cl PracticeC99YH03.c
Microsoft(R) C/C++ Optimizing Compiler Version 19.29.30147 for x86
Copyright (C) Microsoft Corporation.  All rights reserved.

PracticeC99YH03.c
PracticeC99YH03.c(44): error C2059: 構文エラー: ' 型'
PracticeC99YH03.c(59): error C2065: 'name2': 定義 されていない識別子です。
PracticeC99YH03.c(59): warning C4047: '=': 間接参 照のレベルが 'int' と 'char *' で異なっています。
PracticeC99YH03.c(69): error C2065: 'name2': 定義 されていない識別子です。
PracticeC99YH03.c(69): warning C4477: 'printf' :  書式文字列 '%s' には、型 'char *' の引数が必要ですが、可変個引数 2 は型 'int' です

>cl PracticeC99YH03.c
Microsoft(R) C/C++ Optimizing Compiler Version 19.29.30147 for x86
Copyright (C) Microsoft Corporation.  All rights reserved.

PracticeC99YH03.c
/out:PracticeC99YH03.exe
PracticeC99YH03.obj

>PracticeC99YH03
◆Please tell me two person's name and age
＊First person's name > shika
＊First person's age > 50
＊Second person's name > sophia
＊Second person's age > 24

---- Result ----
We preciate your corporation.
The average of 24 san and 24 san ages is 37.00
*/