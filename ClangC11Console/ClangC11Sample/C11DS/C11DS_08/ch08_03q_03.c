/*
コマンドライン引数で与えられる文字列を逆順で表示するプログラム。
？（解答を見て記述）
*/

#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
    if (argc < 2) {
        puts("<!> arguments!");
        return 1;
    }

    char* p = argv[1] + strlen(argv[1]) - 1;
    while (p >= argv[1]) {
        printf("%c", *p);
        p--;
    }//while
    puts("");
}//main

/*
>ch08_03q_03 "This is a pen."
.nep a si sihT
*/