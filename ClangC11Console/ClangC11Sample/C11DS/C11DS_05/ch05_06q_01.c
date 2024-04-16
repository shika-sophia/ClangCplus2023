/*
■章末問題 p139
 1. 30～80の素数を全て表示するプログラム。
*/
#include <stdio.h>

int main(void)
{
    for (int i = 30; i <= 80; i++) {
        if (i % 2 == 0) {
            continue;
        }
        else if (i % 3 == 0) {
            continue;
        }
        else if (i % 5 == 0) {
            continue;
        }
        else if (i % 7 == 0) {
            continue;
        }
        else if (i % 11 == 0) {
            continue;
        }
        else if (i % 13 == 0) {
            continue;
        }
        else if (i % 17 == 0) {
            continue;
        }
        else if (i % 19 == 0) {
            continue;
        }
        else if (i % 23 == 0) {
            continue;
        }
        else if (i % 29 == 0) {
            continue;
        }

        printf("%i\n", i);
    }//for

    puts("end");
}//main

/*
>ch05_06q_01
31
37
41
43
47
53
59
61
67
71
73
79
end
*/