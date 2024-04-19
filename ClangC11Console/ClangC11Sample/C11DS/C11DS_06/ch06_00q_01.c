/*
2.要素が10個ある配列を宣言し、for 文を2回使って、奇数番目の要素はインデックスの10 倍、
偶数番目の要素はインデックスの2倍。最初の要素は0。
配列の全ての要素を表示するプログラム。
*/

#include <stdio.h>
#define LENGTH 10

int main(void)
{
    int a[LENGTH] = { 0, };

    for (int i = 1; i < LENGTH; i++) {
        if (i % 2 == 0) {
            a[i] = i * 2;
        }
        else {
            a[i] = i * 10;
        }
    }//for

    printf("a[10] = {");
    for (int i = 0; i < LENGTH; i++) {
        printf("%i, ", a[i]);
    }//for
    puts("}\n");
}//main

/*
>ch06_00q_01
a[10] = {0, 10, 4, 30, 8, 50, 12, 70, 16, 90, }
*/