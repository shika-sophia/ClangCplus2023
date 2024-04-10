/*
2. コマンドライン引数が３個で受付ける、switch文を使ったプログラム。
   ・最初の引数が 0 なら、2番目と3番目の和を求める。
   ・最初の引数が 1 なら、2番目と3番目の差を求める。
   ・最初の引数が 2 なら、2番目と3番目の積を求める。
   ・最初の引数が 3 なら、2番目と3番目の商を求める。
   ・最初の引数が上記以外なら、「1st argument should be 0 to 3.」を表示して、2を返す。
   ・変数は2個まで
   =>別紙 ch04_06q_01.c
   ・求めた解を表示し、0 を返す。
*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    if (argc == 4) {
        int x = atoi(argv[2]);
        int y = atoi(argv[3]);

        switch (atoi(argv[1])) {
        case 0:
            printf("和： %d", x + y);
            return 0;
            break;

        case 1:
            printf("差： %d", x - y);
            return 0;
            break;

        case 2:
            printf("積： %d", x * y);
            return 0;
            break;

        case 3:
            printf("商： %d", x / y);
            return 0;
            break;

        default:
            puts("1st argument should be 0 to 3.");
            return 2;
            break;
        }//switch
    }//if
    else {
        puts("実行時に３つの引数が必要です。");
    }//if-else
}//main

/*
コンパイルエラー
error C2143: 構文エラー: ')' が '{' の前にありません。

=>原因不明、解答を見て主旨は正解。
=>switch(atoi(argv[1]))の「)」がひとつ抜けていた。解決。

>ch04_06q_01
実行時に３つの引数が必要です。

>ch04_06q_01 0 10 5
和： 15

>ch04_06q_01 1 10 5
差： 5

>ch04_06q_01 2 10 5
積： 50

>ch04_06q_01 3 10 5
商： 2

>ch04_06q_01 6 10 5
1st argument should be 0 to 3.
*/