/*
���X�g7.14 p177
�E�R�}���h���C���������R�s�[���āA�啶���ŏo�͂���v���O�����B
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char* argv[]) {
    if (argc == 1) {
        puts("<!> arguments!");
        return 1;
    }

    if (argc == 2) {
        size_t len = strlen(argv[1]);
        char dest[len + 1];
        strcpy(dest, argv[1]);

        for (size_t i = 0;i < len; i++) {
            dest[i] = toupper(dest[i]);
        }//for

        printf("src=> %s, dest => %s\n", argv[1], dest);
    }//if
}//main

/*
�y�R���p�C���G���[�z
error C2057: �萔�����K�v�ł��B
ch07_11.c(16): error C2466: �T�C�Y�� 0 �̔z����� �蓖�Ă܂��͐錾���悤�Ƃ��܂����B
ch07_11.c(16): error C2133: 'dest': �T�C�Y���s���ł��B
*/