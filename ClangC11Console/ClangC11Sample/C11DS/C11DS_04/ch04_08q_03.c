/*
3.コマンドライン引数が５で割って余り１なら「ONE」、余り２なら「TWO」
  余り3なら「THREE」余り4なら「FOUR」、割り切れたら「ZERO」
  コマンドライン引数が１個以外なら「speicify a number.」を表示するプログラム。
*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    if (argc != 2) {
        puts("specify a number");
        return 2;
    }

    int x = atoi(argv[1]);

    switch (x % 5) {
    case 0:
        puts("ZERO");
        break;

    case 1:
        puts("ONE");
        break;

    case 2:
        puts("TWO");
        break;

    case 3:
        puts("THREE");
        break;

    case 4:
        puts("FOUR");
        break;

    default:
        puts("default");
    }//switch

    return 0;
}//main
/*
>ch04_08q_03
specify a number

>ch04_08q_03 5
ZERO

>ch04_08q_03 6
ONE

>ch04_08q_03 7
TWO

>ch04_08q_03 8
THREE

>ch04_08q_03  9
FOUR

>ch04_08q_03 0
ZERO
*/