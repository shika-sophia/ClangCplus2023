/*
3. int�^�̔z���錾���A1�Ԗڂ̗v�f�� 9�A2�Ԗڂ̗v�f�� 8�A9�Ԗڂ̗v�f�� 0�ɂȂ�悤�Ȕz������B
�������񍀉��Z�q�u+�v�u-�v�͗��p���Ȃ��ŃJ���}���Z�q�u,�v�𗘗p����B
�z��̑S�Ă̗v�f��\������v���O�����B
*/

#include <stdio.h>
#define LENGTH 10

int main(void)
{
    int a[LENGTH];

    for (int i = 0, j = 9; i < LENGTH; i++, j--) {
        a[i] = j;
    }//for

    printf("a[10] = {");
    for (int i = 0; i < LENGTH; i++) {
        printf("%i, ", a[i]);
    }//for
    puts("}\n");
}//main

/*
>ch06_00q_02
a[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0, }
*/
