/*
◆練習問題4.4 p104
1.コマンドライン引数を2個にした場合に「Bingo!」、それ以外の場合は「Opps!」
と表示するプログラム
*/
#include <stdio.h>

int main(int argc, char* argv[])
{
    if (argc == 3) {
        puts("Bingo!");
    }
    else {
        puts("Opps!");
    }

    return 0;
}//main

/*
>ch04_04q_01
Opps!

>ch04_04q_01 5 10
Bingo!
*/