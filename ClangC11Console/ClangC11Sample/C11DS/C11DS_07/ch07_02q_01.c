/*
◆練習問題7.2 p173
1. 次の宣言を持つ変数 a の文字数をコンソールに表示するプログラム。
char a[] = "This is a string.";
*/

#include <stdio.h>

int main(void) {
    char a[] = "This is a string.";

    int i = 0;
    while (a[i] != '\0') {
        i++;
    }//while

    printf("%i\n", i + 1);
}//main

/*
>ch07_02q_01
18

【考察】
（解答の解説）ナル文字「'\0'」は整数の 0となり、偽となる。
よって、条件式は「a[i]」だけでよい。
*/