/**
*@directory ClangC11Console / ClanC11Sample / C99YH / C99YH02_Calculate
*@fileName  PracticeC99YH02.c
*@reference C99YH  結城 浩 『C言語プログラミングレッスン [入門編] 第３版』SB Creative, 2019
*@reference CAnsi  結城 浩 『C言語プログラミングレッスン [文法編] 新版』  SB Creative, 2006
*@reference C11DS  arton  『独習 C 新版』翔泳社, 2018
*
*@content C99YH 第２章 計算 / 練習問題 / p52 
*@subject Practice 2-1
*         0 × 0 ～ 10 × 10 の計算を表示せよ
*
*         for (int i = 0; i <= 10; i++) { }
* 
*@subject Practice 2-2
*         台形の面積を求める関数を作成せよ
*         [英] trapezoid 台形
* 
*         関数宣言: 利用する関数は 関数名, 引数型と個数, 戻り値型の宣言が必要 
*         関数定義: 引数を利用した計算・処理結果の内容を記述し、returnで戻り値を指定する
* 
*@see
*@author shika
*@date 2022-12-10
*/

#include <stdio.h>

double trapezoidSquare(int, int, int);

//int main(void) {
int mainPracticeC99YH02(void) {
    //---- Practice 2-1 ----
    for (int i = 0; i <= 10; i++) {
        printf("%2d * %2d = %3d\n", i, i, i * i);
    }//for
    printf("\n");

    //---- Practice 2-2 ----
    int upper = 2;
    int under = 3;
    int height = 4;

    double square = trapezoidSquare(upper, under, height);
    printf("Upper: %d\nUnder: %d\nHeight: %d\nSquare: %.2f\n",
        upper, under, height, square);
    printf("\n");

    return 0;
}//main()

double trapezoidSquare(int upper, int under, int height) {
    return (upper + under) * height / 2.0;
}

/*
//====== Result ======
//---- Practice 2-1 ----
 0 *  0 =   0
 1 *  1 =   1
 2 *  2 =   4
 3 *  3 =   9
 4 *  4 =  16
 5 *  5 =  25
 6 *  6 =  36
 7 *  7 =  49
 8 *  8 =  64
 9 *  9 =  81
10 * 10 = 100

//---- Practice 2-2 ----
Upper: 2
Under: 3
Height: 4
Square: 10.00

*/