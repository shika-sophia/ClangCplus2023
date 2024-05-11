/*
4. コマンドライン引数が英大文字なら、小文字を出力、英小文字なら、大文字を出力するプログラム。
*/
#include <stdio.h>
#include <ctype.h>

int main(int argc, char* argv[])
{
    if (argc == 1) {
        puts("<!> no argument!");
        return 1;
    }//if

    char ch = '\0';
    if (islower(*argv[1])) {
        ch = toupper(*argv[1]);
    }

    if (isupper(*argv[1])) {
        ch = tolower(*argv[1]);
    }

    printf("%c\n", ch);

    return 0;
}//main

/*
>ch07_01q_03
<!> no argument!

>ch07_01q_03 A
a

>ch07_01q_03 a
A
*/