/**
*@directory ClangC11Console / ClanC11Sample / C99YH / C99YH03_Variable
*@fileName  PracticeC99YH03.c
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
*NOTE【Problem】エラー LNK2019
*     未解決の外部シンボル _main が関数 "int __cdecl invoke_main(void)" (?invoke_main@@YAHXZ) で参照されました
*     ClangCplus2023\ClangC11Console\MSVCRTD.lib(exe_main.obj)	1	
*
*     ↑ Prototype 'int main(void);'　を 前コード 'MainMultipleQuestViewer.c'で付記したところ、
*     以後のビルドで、このエラーが出て、新規コンパイルを受付なくなった。
*     コンパイルは通るが「.obj」「.exe」を生成せず。
*     新規ファイルに int main(void)があっても、それを認識せず、上記のエラーとなる。
*     これ以前にビルドしたファイル内に 空の int main(void) { } を用意すると、
*     上記エラーを抑制できるが、新規ファイルのビルドはできない。
*     仕方なく、[Windows Command Prompt for VS2019]でコンパイルし、実行〔下記〕
* 
*     => VSから、このファイルのビルドを除外されているので、
*        [このファイルのプロパティ] 
*        [全般] ビルドから除外:  はい     -> いいえ
*               種類:           テキスト -> C/C++コンパイラ
*        に変更すると、ビルド時に、このファイルも含まれ、VSで実行可能。
*        「.obj」も /Debug内に生成される。
*        (ただし [.c]ファイルではなく、[C++]ファイルとして認識されている)
* 
*     => ファイル作成時 [テキスト.txt]ではなく、
*        [C++ファイル.cpp] -> [.c]に変更して作成すれば、デフォルトで '種類: C/C++コンパイラ' になっている。
* 
*@see
*@author shika
*@date 2022-12-14
*/

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 256

//int main(void);
void consoleInput(char*, int);  //already definied in MainConsoleInputSample.c

//int main(void) {
int mainPracticeC99YH03(void) {
    char buffer[BUFFER_SIZE];
    char name1[BUFFER_SIZE];
    char name2[BUFFER_SIZE];
    int age1;
    int age2;
    double average;
    
    printf("◆Please tell me two person's name and age\n");
    printf("＊First person's name > ");
    consoleInput(name1, BUFFER_SIZE);

    printf("＊%s's age > ", name1);
    consoleInput(buffer, BUFFER_SIZE);
    age1 = atoi(buffer);

    printf("＊Second person's name > ");
    consoleInput(name2, BUFFER_SIZE);

    printf("＊%s's age > ", name2);
    consoleInput(buffer, BUFFER_SIZE);
    age2 = atoi(buffer);

    average = (age1 + age2) / 2.0;

    printf("---- Result ----\n");
    printf("We preciate your corporation.\n");
    printf("The average of %s and %s ages is %.2f \n", name1, name2, average);

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
>cd c:\ ... \C99YH\C99YH03_Variable
>cl PracticeC99YH03.c
Microsoft(R) C/C++ Optimizing Compiler Version 19.29.30147 for x86
Copyright (C) Microsoft Corporation.  All rights reserved.

PracticeC99YH03.c
/out:PracticeC99YH03.exe
PracticeC99YH03.obj

>PracticeC99YH03
◆Please tell me two person's name and age
＊First person's name > shika
＊shika's age > 50
＊Second person's name > sophia
＊sophia's age > 24
---- Result ----
We preciate your corporation.
The average of shika and sophia ages is 37.00

//====== VS Execution ======
◆Please tell me two person's name and age
＊First person's name > Mitoma
＊Mitoma's age > 25
＊Second person's name > Yuri
＊Yuri's age > 24
---- Result ----
We preciate your corporation.
The average of Mitoma and Yuri ages is 24.50
*/