/*
2.コマンドライン引数が指定されていなければ「Hello World!」を
　指定されていれば、最初の引数を表示するプログラム。
*/

#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc == 1) {
        puts("Hello World!");
    }
    else {
        puts(argv[1]);
    }

    return 0;
}//main

/*
>ch05_00q_01
Hello World!

>ch05_00q_01 10
10
*/