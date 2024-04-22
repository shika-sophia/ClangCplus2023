/*
2. do文を使って、コンソールに入力された文字を全て出力するプログラム。
3個目の改行でプログラムを終了する。
*/

#include <stdio.h>

int main(void)
{
    char ch;
    int count = 0;

    do {
        ch = getc(stdin);
        
        if (ch == '\n') {
            count++;
        }

        printf("%c", ch);
    } while (count < 3);
}//main

/*
>ch06_04q_04
how do you do?
how do you do?
fine thank you.
fine thank you.
and you?
and you?

*/