/*
4.3.32�r�b�g�̐���x���u-10�v�ŏ��������A�����16�r�b�g�̐���y�ɑ������B
���ꂼ���\������v���O�����Bx�̒l���u65526�v�Ay�̒l���u-10�v�ɂ���B
*/
#include <stdio.h>
#include <stdint.h>

int main(void)
{
    uint32_t x = (uint16_t)-10;
    int16_t y = (int16_t)x;
    printf("uint32: x = %d\n", x);
    printf("int16: y = %d\n", y);

    return 0;
}//main

/*
>ch03_08q_04
uint32: x = -10
int16: y = -10

�y�l�@�z
�L���X�g�Ȃ����Ə�L�̌��ʁB16�r�b�g�ɃL���X�g����ƁA���L�̌��ʂ𓾂�B

>ch03_08q_04
uint32: x = 65526
int16: y = -10

*/