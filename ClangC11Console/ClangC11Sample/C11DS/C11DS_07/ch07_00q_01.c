/*
◆前章の復習 p156
 1. 1から 10を出力するプログラム。数の加算は while文内で、
 定数は 0, 10のみ。
*/

#include <stdio.h>

int main(void)
{
    int i = 0;
    while (++i <= 10) {
        printf("%i, ", i);
    }//while

    return 0;
}//main

/*
>ch07_00q_01
1, 2, 3, 4, 5, 6, 7, 8, 9, 10,

*/