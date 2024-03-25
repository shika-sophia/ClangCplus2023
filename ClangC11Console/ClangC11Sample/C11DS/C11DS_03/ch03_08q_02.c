/*
2. 16ビットの整数xを「-10」で初期化し、32ビットの整数yに代入する。
それぞれをコンソールに表示するプログラム。答えを「65526」にする。
*/
#include <stdio.h>
#include <stdint.h>

int main(void)
{
    uint16_t x = -10;
    uint32_t y = x;
    printf("uint16: x = %d\n", x);
    printf("uint32: y = %d\n", y);

    return 0;
}//main

/*
\C11DS_03>ch03_08q_02
uint16: x = 65526
uint32: y = 65526

【考察】
符号なしintに代入することで符号拡張を起こしているので、
1.とは違う結果になる。
*/