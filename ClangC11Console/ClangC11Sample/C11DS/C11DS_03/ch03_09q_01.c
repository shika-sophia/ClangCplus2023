/*
�����K���3.9 p81
1.�R�[�h�C���O
=>�ʎ� ch03_09q_01.c

1.�R�[�h�C����
=>�ʎ� ch03_09q_02.c
*/
#include <stdio.h>
#include <limits.h>

int main(void)
{
    long long value = LLONG_MAX;
    printf("%%i = %i\n", value);

    return 0;
}//main

/*
>ch03_09q_01
%i = -1

�y�x���z
 warning C4477: 'printf' : ���� ������ '%i' �ɂ́A�^ 'int' �̈������K�v�ł����A�� �ό��� 1 �͌^ '__int64' �ł�
ch03_09q_01.c(15): note: ����������� '%lli' ���g �p���邱�Ƃ������߂��܂�
ch03_09q_01.c(15): note: ����������� '%I64i' ���g�p���邱�Ƃ������߂��܂�
*/
