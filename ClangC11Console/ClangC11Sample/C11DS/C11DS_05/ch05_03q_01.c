/*
1. int�^�� 1 ����n�߂āA���̐���2�{�������邱�Ƃ��J��Ԃ����[�v���쐬���A
 �������ʂ� 0 ��菬�����Ȃ����烋�[�v�𔲂��čŏI�I�Ȓl��\������v���O�����B
*/

#include <stdio.h>

int main(void)
{
    int value = 1;

    for (;;) {
        value += value * 2;

        if (value < 0) {
            puts("break");
            break;
        }
    }//for

    printf("value = %d\n", value);
}//main

/*
>ch05_03q_01
break
value = -808182895
*/