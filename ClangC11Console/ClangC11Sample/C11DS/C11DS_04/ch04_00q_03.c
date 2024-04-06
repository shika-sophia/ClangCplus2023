/*
4. 8ビットの符号付き整数を定義し、-1 で初期化。次に 16 ビットの変数、
   32ビットの変数、64ビットの変数に代入。それぞれを表示するプログラム
*/
#include <stdio.h>
#include <stdint.h>

int main(void)
{
    int8_t int8 = -1;
    int16_t int16 = int8;
    int32_t int32 = int16;
    int64_t int64 = int32;

    printf("int8: %d\n", int8);
    printf("int16: %d\n", int16);
    printf("int32: %d\n", int32);
    printf("int64: %lli\n", int64);

    return 0;
}//main

/*
int8: -1
int16: -1
int32: -1
int64: -1
*/