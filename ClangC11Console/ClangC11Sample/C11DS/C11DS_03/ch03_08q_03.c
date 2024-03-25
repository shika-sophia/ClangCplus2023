/*
3.32ビットの整数xを「-10」で初期化し、それを16ビットの整数yに代入する。
それぞれを表示するプログラム。xの値を「-10」、yの値を「65526」にする。
*/
#include <stdio.h>
#include <stdint.h>

int main(void)
{
    int32_t x = -10;
    uint16_t y = x;
    printf("int32: x = %d\n", x);
    printf("uint16: y = %d\n", y);

    return 0;
}//main

/*
>ch03_08q_03
int32: x = -10
uint16: y = 65526
*/