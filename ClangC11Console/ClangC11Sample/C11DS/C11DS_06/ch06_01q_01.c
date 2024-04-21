/*
◆練習問題6.1 p146
1. リスト6.3の内容を while文で記述せよ
*/

#include <stdio.h>

int main(int argc, char *argv[])
{
    int i = 0;
    while (i < argc) {
        puts(argv[i]);
        i++;
    }//while
}//main

/*
>ch06_01q_01 a b c
ch06_01q_01
a
b
c
*/