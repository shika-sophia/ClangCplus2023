/*
���|�C���^�[�ϐ� p192
 �E�|�C���^�[�ϐ����w���A�h���X���o�͂���v���O�����B
*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(void)
{
    int32_t x = 891;
    int32_t* xptr = &x;
    printf("x = %i, xptr = %p\n", x, xptr);

    char y = 'a';
    char* yptr = &y;
    printf("y = %c, yptr = %p\n", y, yptr);
}//main

/*
>ch08_01
x = 891, xptr = 012FFAE0
y = a, yptr = 012FFAE7
*/