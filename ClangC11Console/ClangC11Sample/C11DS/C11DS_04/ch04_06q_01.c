/*
2. �R�}���h���C���������R�Ŏ�t����Aswitch�����g�����v���O�����B
   �E�ŏ��̈����� 0 �Ȃ�A2�Ԗڂ�3�Ԗڂ̘a�����߂�B
   �E�ŏ��̈����� 1 �Ȃ�A2�Ԗڂ�3�Ԗڂ̍������߂�B
   �E�ŏ��̈����� 2 �Ȃ�A2�Ԗڂ�3�Ԗڂ̐ς����߂�B
   �E�ŏ��̈����� 3 �Ȃ�A2�Ԗڂ�3�Ԗڂ̏������߂�B
   �E�ŏ��̈�������L�ȊO�Ȃ�A�u1st argument should be 0 to 3.�v��\�����āA2��Ԃ��B
   �E�ϐ���2�܂�
   =>�ʎ� ch04_06q_01.c
   �E���߂�����\�����A0 ��Ԃ��B
*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    if (argc == 4) {
        int x = atoi(argv[2]);
        int y = atoi(argv[3]);

        switch (atoi(argv[1])) {
        case 0:
            printf("�a�F %d", x + y);
            return 0;
            break;

        case 1:
            printf("���F %d", x - y);
            return 0;
            break;

        case 2:
            printf("�ρF %d", x * y);
            return 0;
            break;

        case 3:
            printf("���F %d", x / y);
            return 0;
            break;

        default:
            puts("1st argument should be 0 to 3.");
            return 2;
            break;
        }//switch
    }//if
    else {
        puts("���s���ɂR�̈������K�v�ł��B");
    }//if-else
}//main

/*
�R���p�C���G���[
error C2143: �\���G���[: ')' �� '{' �̑O�ɂ���܂���B

=>�����s���A�𓚂����Ď�|�͐����B
=>switch(atoi(argv[1]))�́u)�v���ЂƂ����Ă����B�����B

>ch04_06q_01
���s���ɂR�̈������K�v�ł��B

>ch04_06q_01 0 10 5
�a�F 15

>ch04_06q_01 1 10 5
���F 5

>ch04_06q_01 2 10 5
�ρF 50

>ch04_06q_01 3 10 5
���F 2

>ch04_06q_01 6 10 5
1st argument should be 0 to 3.
*/