/*
4. �R�}���h���C���������p�啶���Ȃ�A���������o�́A�p�������Ȃ�A�啶�����o�͂���v���O�����B
*/
#include <stdio.h>
#include <ctype.h>

int main(int argc, char* argv[])
{
    if (argc == 1) {
        puts("<!> no argument!");
        return 1;
    }//if

    char ch = '\0';
    if (islower(*argv[1])) {
        ch = toupper(*argv[1]);
    }

    if (isupper(*argv[1])) {
        ch = tolower(*argv[1]);
    }

    printf("%c\n", ch);

    return 0;
}//main

/*
>ch07_01q_03
<!> no argument!

>ch07_01q_03 A
a

>ch07_01q_03 a
A
*/