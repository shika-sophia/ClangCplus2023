/**
*@directory ClangC11Console / ClanC11Sample / C99YH / C99YH09_Array
*@fileName  MainArrayAverageSample.c
*@reference C99YH  結城 浩 『C言語プログラミングレッスン [入門編] 第３版』SB Creative, 2019
*@reference CAnsi  結城 浩 『C言語プログラミングレッスン [文法編] 新版』  SB Creative, 2006
*@reference C11DS  arton  『独習 C 新版』翔泳社, 2018
*
*@content C99YH 第９章 配列 | Chapter 9  Array / List 9-4 / p262
*@summary MainArrayAverageSample
*
*@subject constant value
*         ・A constant value should be used as named value, not as Literal Number.
*           It can be defined by directive '#xxxx' which is order to Pre-processor,
*           for example '#define MAX 10'.
* 
*         ・【Notation】When '#define', you describe name of constant value, white-space ,and the value only,
*            it is not necessary to describe Type, '=', ';' neither. 
* 
*         ・If name is none, other person won't understand the meaning of the number,
*           so such number is called 'Magic Number'.
* 
*         ・If name is none and you would want to change the value to something else, 
*           you need change multi parts of Literal Number as the same value.
* 
*         ・Therefore, a constant value should be named, 
*           for readablity, maintainability of program code.
*
*         [Example] in this case
*         #define MAX_LENGTH 5
* 
*@subject Array Size -- operator 'sizeof' => 〔List 9-7 | MainArraySizeofSample.c〕
          
*@see
*@author shika
*@date 2022-12-25
*/

#include <stdio.h>

#define MAX_LENGTH 5

//int main(void) {
int mainArrayAverageSample(void) {
    //====== List 9-4 ======
    int pointAry[MAX_LENGTH];
    int sum = 0;
    double average = 0.0;

    pointAry[0] = 65;
    pointAry[1] = 90;
    pointAry[2] = 75;
    pointAry[3] = 45;
    pointAry[4] = 82;

    //---- calc sum ----
    for (int i = 0; i < MAX_LENGTH; i++) {
        sum += pointAry[i];
    }//for

    //---- calc average ----
    average = (double)sum / MAX_LENGTH;

    //---- show pointAry, sum, average ----
    printf("◆Points of Examination\n");
    printf("Points:  ");
    for (int i = 0; i < MAX_LENGTH; i++) {
        printf("%d, ", pointAry[i]);
    }//for 
    printf("\n");

    printf("Summary: %3d\n", sum);
    printf("Average: %.2f\n", average);

    return 0;
}//main()

/*
//====== Result ======
//---- List 9-4 ----
◆Points of Examination
Points:  65, 90, 75, 45, 82,
Summary: 357
Average: 71.40

*/