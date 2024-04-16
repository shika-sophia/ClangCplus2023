/*
1 からコマンドライン引数で指定した数までの総和を表示するプログラム。

*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    if (argc != 2) {
        puts("number!");
        return 2;
    }

    int x = atoi(argv[1]);
    int total = 0;

    for (int i = 1; i <= x; i++) {
        total += i;
    }//for

    printf("total = %i\n", total);
    
}//main

/*
>ch05_02q_01
number!

>ch05_02q_01 4
total = 10

>ch05_02q_01 9
total = 45

>ch05_02q_01 10
total = 55

*/