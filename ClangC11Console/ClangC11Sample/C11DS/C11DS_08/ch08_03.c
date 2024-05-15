/*
・関係演算子で代入するプログラム。
*/

#include <stdio.h>
#include <stdint.h>

int main(void)
{
    int32_t x = 891;
    int32_t* xptr = &x;
    *xptr = 321;
    printf("x = %i, *xptr = %i\n", x, *xptr);

    char y = 'a';
    char* yptr = &y;
    *yptr = 'x';
    printf("y = %c, *yptr = %c\n", y, *yptr);
}//main

/*
>ch08_03
x = 321, *xptr = 321
y = x, *yptr = x
*/