/*
2. 1���� 10��\������v���O�����B���[�v�{�̂́uprintf("%i\n", i)�v��1�s�̂�
(1) for ���ō쐬
=>�ʎ� ch06_02q_01.c

(2) while ���ō쐬
=>�ʎ� ch06_02q_02.c

(3) do ���ō쐬
*/
#include <stdio.h>

int main(void)
{
    int i = 1;

    do {
        printf("%i\n", i);
    } while (++i <= 10);
    
    return 0;
}//main

/*
>ch06_02q_03
1
2
3
4
5
6
7
8
9
10
*/