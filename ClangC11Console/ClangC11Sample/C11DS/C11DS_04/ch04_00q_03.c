/*
4. 8�r�b�g�̕����t���������`���A-1 �ŏ������B���� 16 �r�b�g�̕ϐ��A
   32�r�b�g�̕ϐ��A64�r�b�g�̕ϐ��ɑ���B���ꂼ���\������v���O����
*/
#include <stdio.h>
#include <stdint.h>

int main(void)
{
    int8_t int8 = -1;
    int16_t int16 = int8;
    int32_t int32 = int16;
    int64_t int64 = int32;

    printf("int8: %d\n", int8);
    printf("int16: %d\n", int16);
    printf("int32: %d\n", int32);
    printf("int64: %lli\n", int64);

    return 0;
}//main

/*
int8: -1
int16: -1
int32: -1
int64: -1
*/