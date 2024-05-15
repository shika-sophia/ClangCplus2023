/*
・ポインター変数は他のポインター変数に代入できるプログラム。
*/
#include <stdio.h>
#include <stdint.h>

int main(void)
{
    int32_t x = 891;
    int32_t* xptr = &x;
    printf("x = %i, xptr = %p\n", x, xptr);

    int32_t* zptr = xptr;
    printf("*zptr = %i, zptr = %p\n",*zptr, zptr);
}//main

/*
>ch08_04
x = 891, xptr = 0077FA94
*zptr = 891, zptr = 0077FA94
*/