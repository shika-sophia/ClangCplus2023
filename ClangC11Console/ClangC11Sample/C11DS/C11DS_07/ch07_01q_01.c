/*
2. コンソールにA～Zを表示するプログラム。

ASCIIコード 'A' は10進数の 65

*/
#include <stdio.h>

int main(void)
{
    char a = 'A';
     
    for (; a <= 90; a++) {
        printf("%c", a);
    }//for
}//main

/*
>ch07_01q_01
ABCDEFGHIJKLMNOPQRSTUVWXYZ
*/


