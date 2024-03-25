/*
◆練習問題3.8 p77
1. 16ビットの整数xを「-10」で初期化し、それを32ビットの整数yに代入する。
それぞれをコンソールに表示するプログラム
*/
#include <stdio.h>
#include <stdint.h>

int main(void)
{
    int16_t x = -10;
    int32_t y = x;
    printf("int16_t: x = %d\n", x);
    printf("int32_t; y = %d\n", y);

    return 0;
}//main

/*
>ch03_08q_01
int16_t: x = -10
int32_t; y = -10
*/