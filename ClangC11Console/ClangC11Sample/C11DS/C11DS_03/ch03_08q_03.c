/*
3.32�r�b�g�̐���x���u-10�v�ŏ��������A�����16�r�b�g�̐���y�ɑ������B
���ꂼ���\������v���O�����Bx�̒l���u-10�v�Ay�̒l���u65526�v�ɂ���B
*/
#include <stdio.h>
#include <stdint.h>

int main(void)
{
    int32_t x = -10;
    uint16_t y = x;
    printf("int32: x = %d\n", x);
    printf("uint16: y = %d\n", y);

    return 0;
}//main

/*
>ch03_08q_03
int32: x = -10
uint16: y = 65526
*/