/*
4. �R�}���h���C�������� 10 �ȉ��Ȃ�utoo small�v�A20 ���傫����΁utoo large�v�A
   15�Ȃ�ugood�v�A����ȊO�Ȃ�uOK�v�A�R�}���h���C���������P�ȊO�Ȃ�uspecify a number.�v��\������v���O�����B
*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    if (argc != 2){
        puts("specify a number.");
        return 2;
    }

    int x = atoi(argv[1]);

    if (x == 15) {
        puts("good");
    }
    else if (x <= 10) {
        puts("too small");
    }
    else if (x > 20) {
        puts("too large");
    }
    else {
        puts("OK");
    }

    return 0;
}//main

/*
>ch04_08q_04
specify a number.

>ch04_08q_04 1
too small

>ch04_08q_04 15
good

>ch04_08q_04 25
too large

>ch04_08q_04 14
OK
*/