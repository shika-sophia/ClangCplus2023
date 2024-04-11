/*
■章末問題 p114
1.コマンドライン引数が奇数なら「odd」、偶数なら「even」を表示するプログラム。
関数 bool odd(int n)を用いて作成せよ。
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool odd(int);

bool odd(int n)
{
    return n % 2 == 1;
}

int main(int argc, char* argv[])
{
    if (argc != 2) {
        puts("実行時に引数を一つ付けて下さい。");
        return 2;
    }

    int x = atoi(argv[1]);

    if (odd(x)) {
        puts("odd");
    }
    else {
        puts("even");
    }

}//main

/*
>ch04_08q_01
実行時に引数を一つ付けて下さい。

>ch04_08q_01 8
even

>ch04_08q_01 7
odd



*/

