/*
�����K���3.8 p77
1. 16�r�b�g�̐���x���u-10�v�ŏ��������A�����32�r�b�g�̐���y�ɑ������B
���ꂼ����R���\�[���ɕ\������v���O����
*/
#include <stdio.h>
#include <stdint.h>

int main(void)
{
    int16_t x = -10;
    int32_t y = x;
    printf("int16_t: x = %d\n", x);
    printf("int32_t; y = %d\n", y);

    return 0;
}//main

/*
>ch03_08q_01
int16_t: x = -10
int32_t; y = -10
*/