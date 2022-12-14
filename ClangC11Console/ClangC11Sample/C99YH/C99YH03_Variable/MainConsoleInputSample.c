/**
*@directory ClangC11Console / ClanC11Sample / C99YH / C99YH03_Variable
*@fileName  MainConsoleInputSample.c
*@reference C99YH  結城 浩 『C言語プログラミングレッスン [入門編] 第３版』SB Creative, 2019
*@reference CAnsi  結城 浩 『C言語プログラミングレッスン [文法編] 新版』  SB Creative, 2006
*@reference C11DS  arton  『独習 C 新版』翔泳社, 2018
*
*@content C99YH 第３章 変数 | Chapter 3 Variable / List 3-5 / p71
*@summary Console Input
*         ・#define 
*         ・<stdio.h>
*             └ stdin
*             └ Function fgets()
* 
*         ・<stdlib.h>
*             └ Function atoi()
*         ・Array
*
*@subject #define 
*           Directive: order to Preprocessor, which operate before Compile.
*                      it is described with prefix "#".
*           #define:   definition of constant value, 
*                      it is described as whole Upper case and under bar "_".
*          【NOTE】    not necessary: Type, "=", ";" (if existed, be thrown compile error)
* 
*           [Example]  #define BUFFER_SIZE 256
* 
*@subject <stdio.h>
*            └ stdin  (= Standard Input) 標準入力
*            └ char*  fgets(char *_Buffer, int _MaxCount, FILE _Stream)
*
*@subject <stdlib.h>
*            L int    atoi(const char *_String)
*
*@subject Function fgets()  File Get Strings
*           ・Standard Input (= Console Input as default)
*           ・if 'Redirect', the Standard Input can be changed to File Input. 〔Chapter 12 File〕
*           ・'\0': ナル文字: 文字列の終端を表す
*           ・NULL: 値が存在しないことを表す
* 
*         char*  fgets(char *_Buffer, int _MaxCount, FILE _Stream)
* 
*         [Example]
*         char* inputAry = fgets(buffer, bufferSize, stdin);
*         if
*
*@subject Function atoi()  ASCII to Integer 
*           ・It change Strings to Integer
* 
*         int    atoi(const char *_String)
* 
*@subject Array 〔Chapter 9〕
* 
*@see
*@author shika
*@date 2022-12-12
*/

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 256

void consoleInput(char* buffer, int bufferSize); //self defined

int mainConsoleInputSample(void) {
    char buffer[BUFFER_SIZE];
    int age;

    printf("Please input your name. > ");
    consoleInput(buffer, BUFFER_SIZE);
    printf("Hello, %s.\n", buffer);
    printf("\n");

    printf("Please input your age. > ");
    consoleInput(buffer, BUFFER_SIZE);
    age = atoi(buffer);
    printf("Now, you are %d years old, \nafter decade year, you will be %d.\n", age, age + 10);

    return 0;
}//main()

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

/*
//====== Result ======
Please input your name. > sophia
Hello, sophia.

Please input your age. > 24
Now, you are 24 years old,
after decade year, you will be 34.

//---- Trial of Invalid Input ----
Please input your name. >
Hello, .

Please input your age. > age
Now, you are 0 years old,
after decade year, you will be 10.

【Analysis】
 ・if name were empty input, it show user name as "" empty .
 ・if age were not numeric input, Function 'int  atoi(char*)' return 0.

 */