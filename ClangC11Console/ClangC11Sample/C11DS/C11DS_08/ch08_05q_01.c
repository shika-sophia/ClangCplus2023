/*
5. �R�}���h���C�������ŗ^����ꂽ�����~���Ń\�[�g���ĕ\������v���O�����B
(�𓚂����ċL�q)*/

#include <stdio.h>
#include <stdlib.h>

int compare(void* p0, void* p1)
{
    return (int *)p1 - (int *)p0;
}//compare

int main(int argc, char* argv[])
{
    if (argc < 2) {
        puts("<!> arguments!");
        return 1;
    }
    int array[argc - 1];

    for (int i = 1; i < argc; i++) {
        array[i - 1] = atoi(argv[i]);
    }//for

    qsort(array, argc - 1, sizeof(int), compare);

    for (int i = 0; i < argc - 1; i++) {
        printf("%i\n", array[i]);
    }//for 
}//main

/*
�y�R���p�C���E�G���[�z
�z��̐錾�ɂ͒萔�����K�v�ł��B

*/