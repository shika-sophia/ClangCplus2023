/*
1. int型の 1 から始めて、その数の2倍を加えることを繰り返すループを作成し、
 もし結果が 0 より小さくなったらループを抜けて最終的な値を表示するプログラム。
*/

#include <stdio.h>

int main(void)
{
    int value = 1;

    for (;;) {
        value += value * 2;

        if (value < 0) {
            puts("break");
            break;
        }
    }//for

    printf("value = %d\n", value);
}//main

/*
>ch05_03q_01
break
value = -808182895
*/