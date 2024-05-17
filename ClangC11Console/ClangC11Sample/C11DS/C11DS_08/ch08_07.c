/*
・ポインター変数の加算は、配列の次の要素を指すプログラム。
*(p + i) = array[i]
*/

#include <stdio.h>
#include <stdint.h>

int main(void)
{
    int32_t array[] = { 1, 2, 3, 4 };
    int32_t *p = array;

    for (int i = 0; i < 4; i++) {
        printf("*(p + %i) = %i\n", i, *(p + i));
    }//for
}//main

/*
>ch08_07
*(p + 0) = 1
*(p + 1) = 2
*(p + 2) = 3
*(p + 3) = 4
*/