/*
3. int型の配列を宣言し、1番目の要素は 9、2番目の要素は 8、9番目の要素は 0になるような配列を作る。
ただし二項演算子「+」「-」は利用しないでカンマ演算子「,」を利用する。
配列の全ての要素を表示するプログラム。
*/

#include <stdio.h>
#define LENGTH 10

int main(void)
{
    int a[LENGTH];

    for (int i = 0, j = 9; i < LENGTH; i++, j--) {
        a[i] = j;
    }//for

    printf("a[10] = {");
    for (int i = 0; i < LENGTH; i++) {
        printf("%i, ", a[i]);
    }//for
    puts("}\n");
}//main

/*
>ch06_00q_02
a[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0, }
*/
