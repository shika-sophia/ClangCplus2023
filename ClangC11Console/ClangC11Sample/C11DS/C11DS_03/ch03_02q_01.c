/*
���K���3.2 p63
1.�R�}���h���C�������̍���\������v���O����
*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    int diff;
    if (argc == 3) {
        diff = atoi(argv[1]) - atoi(argv[2]);
        printf("diff = %d\n", diff);
    }//if

    return 0;
}//main

/*
�y���s���z
�E�f�X�N�g�b�v�ɃR�s�[
�E�����J�[���J�����g�f�B���N�g���ɃR�s�[
�E�R���p�C���́ucl�v�ōs���B�uclang�v���ƃ����J�[�������Ȃ��B

>ch03_02q_01 30 2
 diff = 28
 */