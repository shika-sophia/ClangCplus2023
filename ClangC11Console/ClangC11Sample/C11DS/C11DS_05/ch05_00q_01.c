/*
2.�R�}���h���C���������w�肳��Ă��Ȃ���΁uHello World!�v��
�@�w�肳��Ă���΁A�ŏ��̈�����\������v���O�����B
*/

#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc == 1) {
        puts("Hello World!");
    }
    else {
        puts(argv[1]);
    }

    return 0;
}//main

/*
>ch05_00q_01
Hello World!

>ch05_00q_01 10
10
*/