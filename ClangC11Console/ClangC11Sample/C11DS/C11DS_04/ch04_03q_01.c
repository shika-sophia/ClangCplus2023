/*
◆練習問題4.3 p101
1. コマンドライン引数を2個与えたときに「two!」と表示されるプログラム

*/

#include <stdio.h>

int main(int argc, char* argv[])
{
    if (argc - 3) {
        puts("not two\n");
    } 
    else {
        puts("two!");
    }

    return 0;
}//main

/*
>ch04_03q_01
not two

>ch04_03q_01 5 10
two!
*/