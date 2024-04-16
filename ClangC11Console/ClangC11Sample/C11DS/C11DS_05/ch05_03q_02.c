/*
2. int型の変数をINT_MAXで初期化し、コマンドライン引数で除算し続ける。
 もし コマンドライン引数が 0 ならエラーを出す。最終的な結果を表示するプログラム。
 if文は1回だけ利用。break文を使うとは限らない。for文の条件式は argc と i を比較する。
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char* argv[])
{
    int x = INT_MAX;

    if (argc == 1) {
        puts("number!");
        return 1;
    }

    for (int i = 1; i < argc; i++) {

        if (atoi(argv[i]) == 0) {
            puts("<!> divisor is 0.");
            return 2;
        }

        x /= atoi(argv[i]);
    }//for

    printf("result = %d\n", x);
   
    return 0;
}//main

/*
>ch05_03q_02
number!

>ch05_03q_02 3 6 9
result = 13256071

>ch05_03q_02 3 5 0 9
<!> divisor is 0.

>ch05_03q_02 300 500 900
result = 15
*/