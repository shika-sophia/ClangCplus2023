/*
�E�Ԑډ��Z�q�Œl���o�͂���v���O�����B
*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(void)
{
    int32_t x = 891;
    int32_t* xptr = &x;
    printf("x = %i, *xptr = %i\n", x, *xptr);

    char y = 'a';
    char* yptr = &y;
    printf("y = %c, *yptr = %c\n", y, *yptr);
}//main

/*
>ch08_02
x = 891, *xptr = 891
y = a, *yptr = a

*/