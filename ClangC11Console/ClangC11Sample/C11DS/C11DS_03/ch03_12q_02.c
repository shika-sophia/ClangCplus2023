/*
2. �L���X�g����p����INT_MIN �𐳐��Ƃ��ĕ\������v���O�����B
�������A printf()�̏����w��q�ɂ� �u%lli�v ���g�����ƁB
���ʂƂ��āu2147483648�v���o���B*/
#include <stdio.h>
#include <limits.h>

int main(void)
{
    int int_min = INT_MIN;
    long long int lli = (long long int)int_min;
    printf("%lli\n", -lli);

    return 0;
}//main
/*
>ch03_12q_02
2147483648

�y�l�@�z
�𓚂ł́uunsigned int�v�ɃL���X�g���āA������ulong long�v�ɃL���X�g���Ă���B

*/