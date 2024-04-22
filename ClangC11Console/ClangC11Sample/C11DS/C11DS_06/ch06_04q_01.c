/*
■章末問題 p153
1. 9から 0 までを出力するプログラム。ただし、ループ本体は
「printf("%i\n", i);」の1行のみ

(1) for 文で作成
*/

#include <stdio.h>

int main(void)
{
    for (int i = 9; i >= 0; i--) {
        printf("%i\n", i);
    }//for
    
    return 0;
}//main

/*
>ch06_04q_01
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