/*
練習問題3.2 p63
1.コマンドライン引数の差を表示するプログラム
*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    int diff;
    if (argc == 3) {
        diff = atoi(argv[1]) - atoi(argv[2]);
        printf("diff = %d\n", diff);
    }//if

    return 0;
}//main

/*
【実行環境】
・デスクトップにコピー
・リンカーもカレントディレクトリにコピー
・コンパイルは「cl」で行う。「clang」だとリンカーが働かない。

>ch03_02q_01 30 2
 diff = 28
 */