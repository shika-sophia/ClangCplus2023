/*
2.�R�}���h���C�������� 10 �Ŋ���؂ꂽ��uA�v�A3�Ŋ���؂ꂽ��uB�v
  30�Ŋ���؂ꂽ��uC�v�A����ȊO�Ȃ�uD�v��\������B
  �R�}���h���C���������Ȃ���΁uspecify a number.�v��\������v���O����
*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    if (argc == 1) {
        puts("specify a number");
        return 2;
    }

    int x = atoi(argv[1]);

    if (x % 30 == 0) {
        puts("C");
    }
    else if (x % 10 == 0) {
        puts("A");
    }
    else if (x % 3 == 0) {
        puts("B");
    }
    else {
        puts("D");
    }

    return 0;
}//main

/*
>ch04_08q_02
specify a number

>ch04_08q_02 30
C

>ch04_08q_02 6
B

>ch04_08q_02 60
C

>ch04_08q_02 20
A

>ch04_08q_02 23
D
*/