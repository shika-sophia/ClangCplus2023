/*
2.定数0xffを利用してコンソールに「-2」を表示するプログラム。
(1)変数を１つ利用(解答を見て記述)
*/
#include <stdio.h>

int main(void)
{
    char ch = 0xff;
    printf("ch = %i\n", ch);
    printf("%i\n", ch + ch);
}//main

/*
>ch03_13q_03
ch = -1
-2

【考察】
なんでこれで「-2」になるのか？
chが「-1」になるのは char型のオーバーフローを起こしているからだろうか？
*/
