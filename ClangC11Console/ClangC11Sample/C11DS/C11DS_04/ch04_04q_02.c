/*
2.コマンドライン引数で入力した数が 123 のときは「Bingo!」
123より大きい場合は「greater」、小さい場合は「less」、コマンドライン引数がない場合は「specify a number」
を表示するプログラム
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    if (argc != 2) {
        puts("specify a number");
    }
    else {
        int x = atoi(argv[1]);
        if (x == 123) {
            puts("Bingo!");
        }
        else if (x > 123) {
            puts("greater");
        }
        else if (x < 123) {
            puts("less");
        }
    }//else

    return 0;
}//main

/*
>ch04_04q_02 5
less

>ch04_04q_02 123
Bingo!

>ch04_04q_02 200
greater

>ch04_04q_02
specify a number

【考察】コマンドライン引数がない場合が正常に動作していない。
       x = atoi(argv[1]); を　if-else 文の中に入れたら解決。
 */