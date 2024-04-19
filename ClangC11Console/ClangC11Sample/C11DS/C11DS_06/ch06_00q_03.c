/*
4.コマンドライン引数を全て乗じた数を表示するプログラム。
ただしコマンドライン引数が「0」の場合は無視し、
途中でINT_MAXを超えた場合は「overflow!」、
コマンドライン引数がない場合は「no arguments」を表示し、main関数の戻り値を 1 とする。
*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char* argv[])
{
    if (argc == 1) {
        puts("no argumrnts");
        return 1;
    }

    int multipul = 1;

    for (int i = 0; i < argc; i++) {
        int x = atoi(argv[i]);

        if (x == 0) {
            continue;
        }

        if (multipul * x > INT_MAX) {
            puts("<!> overflow!");
            break;
        }

        multipul *= x;
    }//for

    printf("multipul = %i\n", multipul);

    return 0;
}//main

/*
>ch06_00q_03
no argumrnts

>ch06_00q_03 2 3 4
multipul = 24

>ch06_00q_03 2 3 0 4
multipul = 24

>ch06_00q_03 10000000 20000000 3000000 40000000
multipul = -1073741824

>ch06_00q_03 ch06_00q_03 999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999 999999999999999999999999999999999999999999999999999999999999999
multipul = 1
【考察】
INT_MAXを超えません。「overflow!」が出ません。
=> INT_MAXの if 文は解答と同じ。




*/
