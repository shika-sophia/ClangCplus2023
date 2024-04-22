/*
■章末問題 p153
1. 9から 0 までを出力するプログラム。ただし、ループ本体は
「printf("%i\n", i);」の1行のみ

(1) for 文で作成
=>別紙 ch06_04q_01.c

(2) while 文で作成
*/

#include <stdio.h>

int main(void)
{
    int i = 10;
    while (--i >= 0) {
        printf("%i\n", i);
    }//while

    return 0;
}//main

/*
>ch06_04q_02
9
8
7
6
5
4
3
2
1
0
*/
