/*
2.�R�}���h���C�������œ��͂������� 123 �̂Ƃ��́uBingo!�v
123���傫���ꍇ�́ugreater�v�A�������ꍇ�́uless�v�A�R�}���h���C���������Ȃ��ꍇ�́uspecify a number�v
��\������v���O����
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    if (argc != 2) {
        puts("specify a number");
    }
    else {
        int x = atoi(argv[1]);
        if (x == 123) {
            puts("Bingo!");
        }
        else if (x > 123) {
            puts("greater");
        }
        else if (x < 123) {
            puts("less");
        }
    }//else

    return 0;
}//main

/*
>ch04_04q_02 5
less

>ch04_04q_02 123
Bingo!

>ch04_04q_02 200
greater

>ch04_04q_02
specify a number

�y�l�@�z�R�}���h���C���������Ȃ��ꍇ������ɓ��삵�Ă��Ȃ��B
       x = atoi(argv[1]); ���@if-else ���̒��ɓ��ꂽ������B
 */