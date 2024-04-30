/*
2. 0から 9までを出力する do文を使ったプログラム。数の加算は do文の条件式内で、
 定数は 0, 10 のみ。
*/

#include <stdio.h>

int main(void)
{
    int i = 0;
    do {
        printf("%i, ", i);
    } while (++i < 10);

    return 0;
}//main

/*
>ch07_00q_02
0, 1, 2, 3, 4, 5, 6, 7, 8, 9,

*/