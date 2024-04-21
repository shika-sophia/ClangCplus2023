/*
2. fopen()�̃��[�h�u"w"�v�ŏ������ݗp�̃t�@�C���Ƃ��ĊJ����B
�R�}���h���C�������̂P�ԖڂɃR�s�[���A2�ԖڂɃR�s�[��̃t�@�C�����w�肵�āA
�R�s�[�����s����v���O�����B


*/

#include <stdio.h>

int main(int argc, char* argv[])
{
    if (argc != 3) {
        puts("<!> give filenames");
        return 1;
    }//if

    FILE *f = fopen(argv[1], "r");
    FILE *g = fopen(argv[2], "w");

    int ch;
    while ((ch = fgetc(f)) != EOF) {
        fputc(ch, g);
    }//while

    fclose(f);
    fclose(g);
    puts("copy end");
    return 0;
}//main

/*
>ch06_01q_02
<!> give filenames

>ch06_01q_02 ch06_01q_02.c cho6_w_01.txt
copy end

�y�l�@�z
�R�s�[����Ă��Ȃ��B"rb", "wb"�ɂ��Ă����l�B
�𓚂́uint ch�v�ɂȂ��Ă���Bint�ɂ��Ă����l�B(������)

*/