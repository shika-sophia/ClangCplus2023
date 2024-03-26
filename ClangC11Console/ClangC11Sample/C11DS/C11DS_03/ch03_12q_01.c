/*
◆練習問題3.12 p91
1. 例3.11-2の結果をキャスト式を使わず、変数を用いて同じ結果となるプログラム
*/
#include <stdio.h>

int main(void)
{
    double d = 321.253;
    int i = d;
    printf("d = %.3f\n", d);
    printf("i = %i\n", i);

    return 0;
}//main
/*
>ch03_12q_01
d = 321.253

>ch03_12q_01
d = 321.253
i = 321
*/