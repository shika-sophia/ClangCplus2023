/*
�H3. �R�}���h���C�������ŗ^����ꂽ�P����\�[�g���ĕ\������v���O�����B
(�𓚂����ċL�q)
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(const void* p0, const void* p1)
{
    return strcmp(*(char**)p0, * (char**)p1);
}//compare

int main(int argc, char* argv[])
{
    if (argc < 2) {
        puts("<!> arguments!");
        return 1;
    }

    char array[argc - 1];
    for (int i = 1; i < argc; i++) {
        array[i - 1] = array[i];
    }//for

    qsort(array, argc - 1, sizeof(char*), compare);
    for (int i = 0; i < argc - 1; i++) {
        puts(array[i]);
    }
}//main

/*
�y�R���p�C���E�G���[�z
�萔�����K�v�ł��B
error C2466: �T�C�Y�� 0 �̔z�� �����蓖�Ă܂��͐錾���悤�Ƃ��܂����B
*/