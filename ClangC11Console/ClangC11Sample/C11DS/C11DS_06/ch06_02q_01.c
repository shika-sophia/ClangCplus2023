/*
2. 1から 10を表示するプログラム。ループ本体は「printf("%i\n", i)」の1行のみ
(1) for 文で作成
*/

#include <stdio.h>

int main(void)
{
    for (int i = 1; i <= 10; i++) {
        printf("%i\n", i);
    }//for

    return 0;
}//main

/*
>ch06_02q_01
1
2
3
4
5
6
7
8
9
10
*/