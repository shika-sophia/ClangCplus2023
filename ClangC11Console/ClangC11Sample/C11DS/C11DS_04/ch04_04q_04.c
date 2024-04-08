/*
4. コマンドライン引数が３の倍数であれば「Fiz」、５の倍数であれば「Baz」、
   15の倍数であれば「FizBaz」、コマンドライン引数がなければ「no argument」を表示して 1 を返すプログラム

*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2) {
        puts("no argment.");
        return 1;
    }
    else {
        int x = atoi(argv[1]);

        if (x % 15 == 0) {
            puts("FizBaz");
        }
        else if (x % 5 == 0) {
            puts("Baz");
        }
        else if (x % 3 == 0) {
            puts("Fiz");
        }
    }
    return 0;
}//main

/*
>ch04_04q_04
no argment.

>ch04_04q_04 5
Baz

>ch04_04q_04 6
Fiz

>ch04_04q_04 30
FizBaz
*/