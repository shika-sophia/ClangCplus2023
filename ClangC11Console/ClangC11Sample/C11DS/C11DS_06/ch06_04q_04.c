/*
2. do�����g���āA�R���\�[���ɓ��͂��ꂽ������S�ďo�͂���v���O�����B
3�ڂ̉��s�Ńv���O�������I������B
*/

#include <stdio.h>

int main(void)
{
    char ch;
    int count = 0;

    do {
        ch = getc(stdin);
        
        if (ch == '\n') {
            count++;
        }

        printf("%c", ch);
    } while (count < 3);
}//main

/*
>ch06_04q_04
how do you do?
how do you do?
fine thank you.
fine thank you.
and you?
and you?

*/