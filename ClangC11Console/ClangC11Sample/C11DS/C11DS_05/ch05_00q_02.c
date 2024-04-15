/*
3.条件演算子を使って、コマンドライン引数が指定されていなければ 0
そうでなければ 1 を表示するプログラム。
*/

#include <stdio.h>

int main(int argc, char* argv[])
{
    printf("%d", (argc == 1) ? 0 : 1);
}//main

/*
>ch05_00q_02
0

>ch05_00q_02 10
1
*/