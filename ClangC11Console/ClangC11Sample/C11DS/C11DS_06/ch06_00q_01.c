/*
2.�v�f��10����z���錾���Afor ����2��g���āA��Ԗڂ̗v�f�̓C���f�b�N�X��10 �{�A
�����Ԗڂ̗v�f�̓C���f�b�N�X��2�{�B�ŏ��̗v�f��0�B
�z��̑S�Ă̗v�f��\������v���O�����B
*/

#include <stdio.h>
#define LENGTH 10

int main(void)
{
    int a[LENGTH] = { 0, };

    for (int i = 1; i < LENGTH; i++) {
        if (i % 2 == 0) {
            a[i] = i * 2;
        }
        else {
            a[i] = i * 10;
        }
    }//for

    printf("a[10] = {");
    for (int i = 0; i < LENGTH; i++) {
        printf("%i, ", a[i]);
    }//for
    puts("}\n");
}//main

/*
>ch06_00q_01
a[10] = {0, 10, 4, 30, 8, 50, 12, 70, 16, 90, }
*/