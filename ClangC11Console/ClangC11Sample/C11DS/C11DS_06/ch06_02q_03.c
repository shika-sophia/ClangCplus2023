/*
2. 1から 10を表示するプログラム。ループ本体は「printf("%i\n", i)」の1行のみ
(1) for 文で作成
=>別紙 ch06_02q_01.c

(2) while 文で作成
=>別紙 ch06_02q_02.c

(3) do 文で作成
*/
#include <stdio.h>

int main(void)
{
    int i = 1;

    do {
        printf("%i\n", i);
    } while (++i <= 10);
    
    return 0;
}//main

/*
>ch06_02q_03
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