/*
���͖���� p114
1.�R�}���h���C����������Ȃ�uodd�v�A�����Ȃ�ueven�v��\������v���O�����B
�֐� bool odd(int n)��p���č쐬����B
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool odd(int);

bool odd(int n)
{
    return n % 2 == 1;
}

int main(int argc, char* argv[])
{
    if (argc != 2) {
        puts("���s���Ɉ�������t���ĉ������B");
        return 2;
    }

    int x = atoi(argv[1]);

    if (odd(x)) {
        puts("odd");
    }
    else {
        puts("even");
    }

}//main

/*
>ch04_08q_01
���s���Ɉ�������t���ĉ������B

>ch04_08q_01 8
even

>ch04_08q_01 7
odd



*/

