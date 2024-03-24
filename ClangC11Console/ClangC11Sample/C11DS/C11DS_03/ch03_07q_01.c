/*
◆練習問題3.7 p74
1. 16進数でA0にで初期化した後、10進数で表示するプログラム#
*/
#include <stdio.h>

int main(void)
{
    int x = 0xA0;
    printf("x = 0xA0 = %d\n", x);

    return 0;
}//main

/*
>ch03_07q_01
x = 0xA0 = 160
*/