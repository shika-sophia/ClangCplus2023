/*
���͖���� p153
1. 9���� 0 �܂ł��o�͂���v���O�����B�������A���[�v�{�̂�
�uprintf("%i\n", i);�v��1�s�̂�

(1) for ���ō쐬
=>�ʎ� ch06_04q_01.c

(2) while ���ō쐬
=>�ʎ� ch06_04q_02.c

(3) do ���ō쐬
*/

#include <stdio.h>

int main(void)
{
    int i = 9;
    do {
        printf("%i\n", i);
    } while (--i >= 0);

    return 0;
}//main

/*
>ch06_04q_03
9
8
7
6
5
4
3
2
1
0
*/