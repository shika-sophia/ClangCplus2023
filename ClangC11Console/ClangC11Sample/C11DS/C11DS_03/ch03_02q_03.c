/*
���K���3.2 p63
3. �R�}���h���C�������̏��Ə�]��\������v���O����
*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc == 3) {
        int x = atoi(argv[1]);
        int y = atoi(argv[2]);
        int quot = x / y;
        int rest = x % y;
        printf("quot = %d, \nrest = %d\n", quot, rest);
    }//if

    return 0;
}//main

/*
>ch03_02q_03 10 3
quot = 3,
rest = 1
*/