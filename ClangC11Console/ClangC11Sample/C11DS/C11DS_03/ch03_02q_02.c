/*
練習問題3.2 p63
2. コマンドライン引数の積を表示するプログラム
*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    int prod;
    if (argc == 3) {
        prod = atoi(argv[1]) * atoi(argv[2]);
        printf("prod = %d\n", prod);
    }//if

    return 0;
}//main

/*
>ch03_02q_02 30 5
prod = 150
*/