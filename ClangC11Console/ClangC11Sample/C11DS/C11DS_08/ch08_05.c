/*
・関数にアドレスを渡すプログラム。
*/

#include <stdio.h>
#include <stdint.h>

void swap(int32_t* x, int32_t* y)
{
    int32_t temp = *x;
    *x = *y;
    * y = temp;
}//swap

int main(void)
{
    int32_t a = -99;
    int32_t b = 999;
    printf("a = %i, b = %i\n", a, b);

    swap(&a, &b);
    printf("a = %i, b = %i\n", a, b);
}//main

/*
>ch08_05
a = -99, b = 999
a = 999, b = -99
*/