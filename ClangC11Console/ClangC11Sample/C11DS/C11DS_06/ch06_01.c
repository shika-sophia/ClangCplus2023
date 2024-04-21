/*
�����6.1 p144
�E�R�}���h���C�������ŗ^����ꂽ�t�@�C�����J���A���̓��e��\������v���O�����B

<stdio.h> �kCAnsiYH87�l
tyoedef ... FILE �X�g���[����\������^

FILE *fopen(const char *filename, const char *mode)
���� filename �J���t�@�C����
     mode ���[�h

char *fgetc(FILE *stream)

int fputc(int c, FILE* stream)���� c�� stream�ɏ�������

int fclose(FILE *stream)
�߂�l ���� 0
      �ُ� EOF

#define EOF ...�t�@�C���̏I�[������
*/

#include <stdio.h>

int main(int argc, char* argv[])
{
    if (argc != 2) {
        puts("<!> give filename");
        return 1;
    }//if

    FILE* f = fopen(argv[1], "r");
    char ch;
    while ((ch = fgetc(f)) != EOF) {
        fputc(ch, stdout);
    }//while

    fclose(f);

    return 0;
}//main

/*
>ch06_01
<!> give filename

>ch06_01 ch06_01.c ch06_01.c
/*
�����6.1 p144
�E�R�}���h���C�������ŗ^����ꂽ�t�@�C�����J���A���̓��e��\������v���O�����B

<stdio.h> �kCAnsiYH87�l
tyoedef ... FILE �X�g���[����\������^

FILE *fopen(const char *filename, const char *mode)
���� filename �J���t�@�C����
     mode ���[�h

char *fgetc(FILE *stream)

int fclose(FILE *stream)
�߂�l ���� 0
      �ُ� EOF

#define EOF ...�t�@�C���̏I�[������


#include <stdio.h>

int main(int argc, char* argv[])
{
    if (argc != 2) {
        puts("<!> give filename");
        return 1;
    }//if

    FILE* f = fopen(argv[1], "r");
    char ch;
    while ((ch = fgetc(f)) != EOF) {
        fputc(ch, stdout);
    }//while

    fclose(f);

    return 0;
}//main
*/