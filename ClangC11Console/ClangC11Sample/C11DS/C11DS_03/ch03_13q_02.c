/*
���͖����
1.INT_MAX��2����R���\�[���ɕ\������v���O�����B
(1)�������q�� INT_MAX �𗘗p���� long long�^�̕ϐ����P�g��
=>�ʎ� ch03_13q_01.c

(2)�ϐ��𗘗p���Ȃ�(main����1�s)
=>�ʎ� ch03_13q_02.c
*/
#include <stdio.h>
#include <limits.h>

int main(void)
{
    printf("INT_MAX ^ 2 = %lli\n", (long long)INT_MAX * INT_MAX);
}//main

/*
>ch03_13q_02
INT_MAX ^ 2 = 4611686014132420609

*/