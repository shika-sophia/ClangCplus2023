/*
最初のプログラム
*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) 
{
    if (argc == 1) {
        puts("hello world!");
    }
    else {
        int sum = 0;
        //インデックス0は無視する
        for (int i = 1; i < argc; i++) {
            sum += atoi(argv[i]);
        }//for

        printf("sum = %d\n", sum);
    }//if,else
    return 0;
}//main