/*
�R�}���h���C�������ŗ^�����镶������t���ŕ\������v���O�����B
�H�i�𓚂����ċL�q�j
*/

#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
    if (argc < 2) {
        puts("<!> arguments!");
        return 1;
    }

    char* p = argv[1] + strlen(argv[1]) - 1;
    while (p >= argv[1]) {
        printf("%c", *p);
        p--;
    }//while
    puts("");
}//main

/*
>ch08_03q_03 "This is a pen."
.nep a si sihT
*/