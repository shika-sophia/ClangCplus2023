/*
2. 16�r�b�g�̐���x���u-10�v�ŏ��������A32�r�b�g�̐���y�ɑ������B
���ꂼ����R���\�[���ɕ\������v���O�����B�������u65526�v�ɂ���B
*/
#include <stdio.h>
#include <stdint.h>

int main(void)
{
    uint16_t x = -10;
    uint32_t y = x;
    printf("uint16: x = %d\n", x);
    printf("uint32: y = %d\n", y);

    return 0;
}//main

/*
\C11DS_03>ch03_08q_02
uint16: x = 65526
uint32: y = 65526

�y�l�@�z
�����Ȃ�int�ɑ�����邱�Ƃŕ����g�����N�����Ă���̂ŁA
1.�Ƃ͈Ⴄ���ʂɂȂ�B
*/