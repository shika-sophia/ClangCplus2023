/*
�ŏ��̃v���O����
*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) 
{
    if (argc == 1) {
        puts("hello world!");
    }
    else {
        int sum = 0;
        //�C���f�b�N�X0�͖�������
        for (int i = 1; i < argc; i++) {
            sum += atoi(argv[i]);
        }//for

        printf("sum = %d\n", sum);
    }//if,else
    return 0;
}//main