/*
�����K���7.2 p173
1. ���̐錾�����ϐ� a �̕��������R���\�[���ɕ\������v���O�����B
char a[] = "This is a string.";
*/

#include <stdio.h>

int main(void) {
    char a[] = "This is a string.";

    int i = 0;
    while (a[i] != '\0') {
        i++;
    }//while

    printf("%i\n", i + 1);
}//main

/*
>ch07_02q_01
18

�y�l�@�z
�i�𓚂̉���j�i�������u'\0'�v�͐����� 0�ƂȂ�A�U�ƂȂ�B
����āA�������́ua[i]�v�����ł悢�B
*/