/*
���͖����
1.INT_MAX��2����R���\�[���ɕ\������v���O�����B
(1)�������q�� INT_MAX �𗘗p���� long long�^�̕ϐ����P�g��
*/
#include <stdio.h>
#include <limits.h>

int main(void)
{
    long long lli = (long long)INT_MAX * INT_MAX;
    printf("INT_MAX ^ 2 = %lli\n", lli);

    return 0;
}//main

/*
>ch03_13q_01
INT_MAX ^ 2 = 4611686014132420609
*/