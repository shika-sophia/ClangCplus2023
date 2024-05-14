/*
リスト7.14 p177
・コマンドライン引数をコピーして、大文字で出力するプログラム。
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char* argv[]) {
    if (argc == 1) {
        puts("<!> arguments!");
        return 1;
    }

    if (argc == 2) {
        size_t len = strlen(argv[1]);
        char dest[len + 1];
        strcpy(dest, argv[1]);

        for (size_t i = 0;i < len; i++) {
            dest[i] = toupper(dest[i]);
        }//for

        printf("src=> %s, dest => %s\n", argv[1], dest);
    }//if
}//main

/*
【コンパイルエラー】
error C2057: 定数式が必要です。
ch07_11.c(16): error C2466: サイズが 0 の配列を割 り当てまたは宣言しようとしました。
ch07_11.c(16): error C2133: 'dest': サイズが不明です。
*/