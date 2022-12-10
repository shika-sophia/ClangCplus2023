/**
*@directory ClangC11Console / ClanC11Sample / C99YH / C99YH03_Valiable
*@fileName  MainNumericTypeRange.c
*@reference C99YH  結城 浩 『C言語プログラミングレッスン [入門編] 第３版』SB Creative, 2019
*@reference CAnsi  結城 浩 『C言語プログラミングレッスン [文法編] 新版』  SB Creative, 2006
*@reference C11DS  arton  『独習 C 新版』翔泳社, 2018
*
*@content C99YH 第２章 計算 / List 2-7 / p49
*         数値型の有効範囲を表示
* 
*@English [英] numeric:  数値の
*         [英] range:    範囲
* 
*@subject <limits.h>  数値型の有効範囲を定義 (コンパイラによって異なる)
*            CHAR_MAX, CHAR_MIN,
*            INT_MAX, INT_MIN, 
*            LONG_MAX, LONG_MIN,
*            LLONG_MAX, LLONG_MIN
* 
*         ◆Range of Numeric Type (in this Compiler)
*         ＊char  : -128 ～ 127
*         ＊int   : -2147483648 ～ 2147483647
*         ＊long  : -2147483648 ～ 2147483647
*         ＊llong : -9223372036854775808 ～ 9223372036854775807
*
*@see
*@author shika
*@date 2022-12-10
*/

#include <stdio.h>
#include <limits.h>

//int main(void) {
int mainNumericTypeRange(void) {
    printf("◆Range of Numeric Type (in this Compiler)\n");
    printf("＊char  : %d ～ %d\n", CHAR_MIN, CHAR_MAX);
    printf("＊int   : %d ～ %d\n", INT_MIN, INT_MAX);
    printf("＊long  : %ld ～ %ld\n", LONG_MIN, LONG_MAX);
    printf("＊llong : %lld ～ %lld\n", LLONG_MIN, LLONG_MAX);
    
    return 0;
}//main()

/*
//====== Result ======
◆Range of Numeric Type (in this Compiler)
＊char  : -128 ～ 127
＊int   : -2147483648 ～ 2147483647
＊long  : -2147483648 ～ 2147483647
＊llong : -9223372036854775808 ～ 9223372036854775807

*/
