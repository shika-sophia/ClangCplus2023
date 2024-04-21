/*
2. fopen()のモード「"w"」で書き込み用のファイルとして開ける。
コマンドライン引数の１番目にコピー元、2番目にコピー先のファイルを指定して、
コピーを実行するプログラム。


*/

#include <stdio.h>

int main(int argc, char* argv[])
{
    if (argc != 3) {
        puts("<!> give filenames");
        return 1;
    }//if

    FILE *f = fopen(argv[1], "r");
    FILE *g = fopen(argv[2], "w");

    int ch;
    while ((ch = fgetc(f)) != EOF) {
        fputc(ch, g);
    }//while

    fclose(f);
    fclose(g);
    puts("copy end");
    return 0;
}//main

/*
>ch06_01q_02
<!> give filenames

>ch06_01q_02 ch06_01q_02.c cho6_w_01.txt
copy end

【考察】
コピーされていない。"rb", "wb"にしても同様。
解答は「int ch」になっている。intにしても同様。(未解決)

*/