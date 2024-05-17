/*
8.3 �|�C���^�[���Z p204
�E�|�C���^�[�ϐ���1, 2, 3, ...�Ɖ��Z���Ă����ƁA
���̃A�h���X�����̌^�̕������������Ă����v���O�����B
*/

#include <stdio.h>
#include <stdint.h>

int main(void)
{
    int32_t array[] = { 1, 2, 3, 4, };
    int32_t* p = array;//�z�񖼂����ŁA�擪�ʒu�̃A�h���X���w���B

    for (int i = 0; i < 4; i++) {
        printf("array[%i] = %i, &array[%i] = %p, p + %i = %p\n",
            i, array[i], i, &array[i], i, p + i
        );
    }//for
}//main

/*
>ch08_06
array[0] = 1, &array[0] = 010FFC70, p + 0 = 010FFC70
array[1] = 2, &array[1] = 010FFC74, p + 1 = 010FFC74
array[2] = 3, &array[2] = 010FFC78, p + 2 = 010FFC78
array[3] = 4, &array[3] = 010FFC7C, p + 3 = 010FFC7C
*/