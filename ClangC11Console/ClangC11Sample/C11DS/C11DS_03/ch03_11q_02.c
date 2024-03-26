/*
◆練習問題3.11 p90
2. #define を用いて記述量を減らすプログラム
(解答を見て記述）
*/
#include <stdio.h>
#include <stdlib.h>

#define P(o) printf("%i\n", x o y);

int main(int argc, char *argv[])
{
    int x = atoi(argv[1]);
    int y = atoi(argv[2]);
    P(+)
    P(-)
    P(*)
    P(/)
    P(%)

}//main

/*
>ch03_11q_02
(実行しても何も表示されない）
↑コマンドライン引数を忘れていた

>ch03_11q_02 10 3
13
7
30
3
1
*/