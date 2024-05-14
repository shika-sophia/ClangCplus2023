/*
7.3 文字列操作 p174
 コマンドライン引数の文字列の長さを出力するプログラム。
*/
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
    if (argc == 1) {
        puts("<!> arguments!");
        return 1;
    }
    
    for (int i = 1; i < argc; i++) {
        size_t len = strlen(argv[i]);
        printf("%s => %zi\n", argv[i], len);
    }//for

}//main

/*
>ch07_10
<!> arguments!

>ch07_10 hello
hello => 5

*/