/**
*@directory ClangC11Console / ClanC11Sample / C99YH / C99YH11_Pointer
*@fileName  MainPointerOfPointerSample.c
*@reference C99YH  結城 浩 『C言語プログラミングレッスン [入門編] 第３版』SB Creative, 2019
*@reference CAnsi  結城 浩 『C言語プログラミングレッスン [文法編] 新版』  SB Creative, 2006
*@reference C11DS  arton  『独習 C 新版』翔泳社, 2018
*
*@content C99YH 第11章 Pointer | Chapter 11  Pointer of Pointer / List - / p362
*@summary MainPointerOfPointerSample.c
*@English [E] define:      定義する
*         [E] substitute:  交代する、代入する
*         [E] assign:      代入する、割り当てる
*         [E] refer:       参照する
*         [E] storage:     格納する
*         [E] indicate:    指し示す
* 
*@subject Pointer of Pointer
*         [Example]
*         ＊Definition
*         int x;     define int type variable 'x'.
*         int *p;    define Pointer 'p' which storage the address of int type variable 'x'.
*         int **pp;  define Pointer 'pp' which storage the address of Pointer 'p' which storage the address of int type variable 'x'.
*
*         [Example]
*         ＊Assignment
*         x = 100;   // It assign value '100' to 'x'.
*         p = &x;    // It assign address of 'x' to 'p'.
*         pp = &p;   // It assign address of 'p' to 'pp'.
*
*         [Example]
*         ＊Reference
*         printf("x:    %d \n", x);    // It show value of variable 'x'.
*         printf("p:    %p \n", p);    // It show address of variable which Pointer 'p' is storaging.
*         printf("*p:   %d \n", *p);   // It show value of variable which Pointer 'p' indicate.
*         printf("pp:   %p \n", pp);   // It show address of Pointer which Pointer of Pointer 'pp' is storaging.
*         printf("*pp:  %p \n", *pp);  // It show address of variable which Pointer 'p' is storaging, which Pointer of Pointer 'pp' is storaging.
*         printf("**pp: %d \n", **pp); // It show value of variable which Pointer 'p' indicate, which Pointer of Pointer 'pp' is storaging.
*
*         => copy to 〔CAnsiYH06_Pointer\Reference_CAnsiPointer.txt〕
* 
*@see　CAnsiYH06_Pointer\Reference_CAnsiPointer.txt
*@author shika
*@date 2023-01-01
*/

#include <stdio.h>

//int main(void) {
int mainPointerOfPointerSample(void) {
    int x = 100;
    int* p = &x;
    int** pp = &p;

    printf("x:    %d \n", x);
    printf("p:    %p \n", p);
    printf("*p:   %d \n", *p);
    printf("pp:   %p \n", pp);
    printf("*pp:  %p \n", *pp);
    printf("**pp: %d \n", **pp);

    return 0;
}//main()

/*
//====== Result ======
x:    100
p:    010FF728  // show address of variable which Pointer 'p' indicate.
*p:   100                 ||  same address
pp:   010FF71C            || 
*pp:  010FF728  // show address of variable which Pointer 'p' indicate, which Pointer of Pointer 'pp' indicate.
**pp: 100

*/