/*
4. �R�}���h���C���������R�̔{���ł���΁uFiz�v�A�T�̔{���ł���΁uBaz�v�A
   15�̔{���ł���΁uFizBaz�v�A�R�}���h���C���������Ȃ���΁uno argument�v��\������ 1 ��Ԃ��v���O����

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