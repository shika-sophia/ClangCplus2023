/**
*@directory ClangC11Console / ClanC11Sample / C99YH / C99YH09_Array
*@fileName  MainArraySizeofSample.c
*@reference C99YH  結城 浩 『C言語プログラミングレッスン [入門編] 第３版』SB Creative, 2019
*@reference CAnsi  結城 浩 『C言語プログラミングレッスン [文法編] 新版』  SB Creative, 2006
*@reference C11DS  arton  『独習 C 新版』翔泳社, 2018
*
*@content C99YH 第９章 配列 | Chapter 9  Array / List 9-7 / p267
*@summary MainArraySizeofSample
*         ・Initialize Array
*         ・operator 'sizeof()'
* 
*@subject Initialize Array
*         ・(1) need the argument of arrayLength.
*         ・(2) can define initial elements of the same type as defined, when it is initialized only.
*           It is automatically caluculated array length from the number of elements,
*           so that '[]' can be empty still.
*         ・【Detail Notation】
*            It need be put ';' after '{ ... }'.
*            It can be delimited by ',' -- if elements are multiple.
* 
*         [Format] Initialize Array
*         (1) Type  (arrayName)[int  arrayLength]; 
*         (2) Type  (arrayName)[] = { ... }; 
* 
*         [Example]
*         int  pointAry[] = { 65, 90, 72, };
*
*@subject operator 'sizeof()'
*         int  sizeof( T )    return int how bytes the argument T has 
* 
*         ・Array length:  calculated from '(whole array bytes) / (one element bytes)' as below [Example]
*         
*         [Example]
*         int length = sizeof(pointAry) / sizeof(pointAry[0]);
* 
*@see MainArrayAverageSample.c
*@author shika
*@date 2022-12-25
*/

#include <stdio.h>

//int main(void) {
int mainArraySizeofSample(void) {
    int pointAry[] = { 65, 90, 72, };
    int sum = 0;
    int length = sizeof(pointAry) / sizeof(pointAry[0]);
    double average = 0.0;

    printf("Points:  ");
    for (int i = 0; i < length; i++) {
        sum += pointAry[i];
        printf("%d, ", pointAry[i]);
    }//for
    printf("\n");

    average = (double)sum / length;

    printf("Summary: %d\n", sum);
    printf("Average: %.2f\n", average);
    printf("\n");
    printf("Array Bytes:   %d\n", sizeof(pointAry));
    printf("Element Bytes: %d\n", sizeof(pointAry[0]));
    printf("Array Length:  %d\n", length);

    return 0;
}//main()

/*
//====== Result =======
Points:  65, 90, 72,
Summary: 227
Average: 75.67

Array Bytes:   12
Element Bytes: 4
Array Length:  3
*/