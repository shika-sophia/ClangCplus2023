/*
■章末問題
1.INT_MAXの2乗をコンソールに表示するプログラム。
(1)初期化子に INT_MAX を利用した long long型の変数を１つ使う
=>別紙 ch03_13q_01.c

(2)変数を利用しない(main内は1行)
=>別紙 ch03_13q_02.c
*/
#include <stdio.h>
#include <limits.h>

int main(void)
{
    printf("INT_MAX ^ 2 = %lli\n", (long long)INT_MAX * INT_MAX);
}//main

/*
>ch03_13q_02
INT_MAX ^ 2 = 4611686014132420609

*/