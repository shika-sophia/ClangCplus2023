/*
◆練習問題3.10 p84
1.コマンドライン引数で与えた２つの浮動小数点数を double型に変換し、
加減乗除の結果を表示するプログラム
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    puts("◆浮動小数点数の加減乗除を表示するプログラム");

    if (argc == 1 || argc > 3) {
        puts("コマンドライン引数に２つの浮動小数点数を入れて実行してください。\n");
        puts("例：ch03_10q_01 12.2 2.0");
    }
    else if (argc == 3) {
        double x = atof(argv[1]);
        double y = atof(argv[2]);
        printf("(x, y) = (%f, %f)\n", x, y);
        printf("x + y = %f\n", x + y);
        printf("x - y = %f\n", x - y);
        printf("x * y = %f\n", x * y);
        printf("x / y = %f\n", x / y);
    }//if

    return 0;
}//main

/*
>ch03_10q_01
◆浮動小数点数の加減乗除を表示するプログラム
コマンドライン引数に２つの浮動小数点数を入れて実行してください。

例：ch03_10q_01 12.2 2.0

>ch03_10q_01 12.2 2.0
◆浮動小数点数の加減乗除を表示するプログラム
(x, y) = (12.200000, 2.000000)
x + y = 14.200000
x - y = 10.200000
x * y = 24.400000
x / y = 6.100000

*/