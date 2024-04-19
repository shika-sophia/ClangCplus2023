/*
4.�R�}���h���C��������S�ď悶������\������v���O�����B
�������R�}���h���C���������u0�v�̏ꍇ�͖������A
�r����INT_MAX�𒴂����ꍇ�́uoverflow!�v�A
�R�}���h���C���������Ȃ��ꍇ�́uno arguments�v��\�����Amain�֐��̖߂�l�� 1 �Ƃ���B
*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char* argv[])
{
    if (argc == 1) {
        puts("no argumrnts");
        return 1;
    }

    int multipul = 1;

    for (int i = 0; i < argc; i++) {
        int x = atoi(argv[i]);

        if (x == 0) {
            continue;
        }

        if (multipul * x > INT_MAX) {
            puts("<!> overflow!");
            break;
        }

        multipul *= x;
    }//for

    printf("multipul = %i\n", multipul);

    return 0;
}//main

/*
>ch06_00q_03
no argumrnts

>ch06_00q_03 2 3 4
multipul = 24

>ch06_00q_03 2 3 0 4
multipul = 24

>ch06_00q_03 10000000 20000000 3000000 40000000
multipul = -1073741824

>ch06_00q_03 ch06_00q_03 999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999 999999999999999999999999999999999999999999999999999999999999999
multipul = 1
�y�l�@�z
INT_MAX�𒴂��܂���B�uoverflow!�v���o�܂���B
=> INT_MAX�� if ���͉𓚂Ɠ����B




*/
