/*
■章末問題
1.INT_MAXの2乗をコンソールに表示するプログラム。
(1)初期化子に INT_MAX を利用した long long型の変数を１つ使う
*/
#include <stdio.h>
#include <limits.h>

int main(void)
{
    long long lli = (long long)INT_MAX * INT_MAX;
    printf("INT_MAX ^ 2 = %lli\n", lli);

    return 0;
}//main

/*
>ch03_13q_01
INT_MAX ^ 2 = 4611686014132420609
*/