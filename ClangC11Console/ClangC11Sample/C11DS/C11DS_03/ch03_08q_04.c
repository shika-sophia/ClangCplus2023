/*
4.3.32ビットの整数xを「-10」で初期化し、それを16ビットの整数yに代入する。
それぞれを表示するプログラム。xの値を「65526」、yの値を「-10」にする。
*/
#include <stdio.h>
#include <stdint.h>

int main(void)
{
    uint32_t x = (uint16_t)-10;
    int16_t y = (int16_t)x;
    printf("uint32: x = %d\n", x);
    printf("int16: y = %d\n", y);

    return 0;
}//main

/*
>ch03_08q_04
uint32: x = -10
int16: y = -10

【考察】
キャストなしだと上記の結果。16ビットにキャストすると、下記の結果を得る。

>ch03_08q_04
uint32: x = 65526
int16: y = -10

*/