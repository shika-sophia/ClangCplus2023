/*
2. 1, 2, 3, ... �Ɗ|���Z���Ă����āA16bit�����t�������� 32bit�����t�������̍ő�l��
 �Ō�̏搔��\������v���O�����B
 (1) for��2�ō��
*/

#include <stdio.h>
#include <stdint.h>

int main(void)
{
    int16_t result16 = 1;
    int32_t result32 = 1;

    for (int i = 1; i <= INT16_MAX; i++) {
        if (result16 * i < 0 || result16 * i > INT16_MAX) {
            printf("16bit= %i last multiple= %i\n", result16, i - 1);
            break;
        }

        result16 *= i;
    }//for16

    for (int i = 1; i <= INT32_MAX; i++) {
        if (result32 * i < 0 || result32 * i > INT32_MAX) {
            printf("32bit= %i last multiple= %i\n", result32, i - 1);
            break;
        }

        result32 *= i;
    }//for32
}//main

/*
�o�͂��o�ė��Ȃ��E�E�E
break;�̏I�������Ɂu* i�v�������Ȃ��Ɖi�v���[�v�ɂȂ��Ă�������
���l�̏����������Ă���Əo�͂��o���B�i�i�v���[�v�����j

>ch05_06q_02
16bit= 5040 last multiple= 7
32bit= 2004189184 last multiple= 16

�T���v�����傫�Ȑ��ɂȂ��Ă���B


*/
