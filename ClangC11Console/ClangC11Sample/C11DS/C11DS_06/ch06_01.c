/*
◆例題6.1 p144
・コマンドライン引数で与えられたファイルを開き、その内容を表示するプログラム。

<stdio.h> 〔CAnsiYH87〕
tyoedef ... FILE ストリームを表現する型

FILE *fopen(const char *filename, const char *mode)
引数 filename 開くファイル名
     mode モード

char *fgetc(FILE *stream)

int fputc(int c, FILE* stream)文字 cを streamに書き込む

int fclose(FILE *stream)
戻り値 正常 0
      異常 EOF

#define EOF ...ファイルの終端を示す
*/

#include <stdio.h>

int main(int argc, char* argv[])
{
    if (argc != 2) {
        puts("<!> give filename");
        return 1;
    }//if

    FILE* f = fopen(argv[1], "r");
    char ch;
    while ((ch = fgetc(f)) != EOF) {
        fputc(ch, stdout);
    }//while

    fclose(f);

    return 0;
}//main

/*
>ch06_01
<!> give filename

>ch06_01 ch06_01.c ch06_01.c
/*
◆例題6.1 p144
・コマンドライン引数で与えられたファイルを開き、その内容を表示するプログラム。

<stdio.h> 〔CAnsiYH87〕
tyoedef ... FILE ストリームを表現する型

FILE *fopen(const char *filename, const char *mode)
引数 filename 開くファイル名
     mode モード

char *fgetc(FILE *stream)

int fclose(FILE *stream)
戻り値 正常 0
      異常 EOF

#define EOF ...ファイルの終端を示す


#include <stdio.h>

int main(int argc, char* argv[])
{
    if (argc != 2) {
        puts("<!> give filename");
        return 1;
    }//if

    FILE* f = fopen(argv[1], "r");
    char ch;
    while ((ch = fgetc(f)) != EOF) {
        fputc(ch, stdout);
    }//while

    fclose(f);

    return 0;
}//main
*/