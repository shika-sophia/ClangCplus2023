/*
3. ���̔z��錾���g���āA2�����z���v�f�̕��я��ʂ�ɏo�͂���v���O�����B
 int a[][3] = { 1, 2, 3, 4, 5, 6, 7, 8, 9};
*/

#include <stdio.h>

int main(void)
{
    int a[][3] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    printf("a[][3] = {");
    for (int i = 0; i < 3 ; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%i, ", a[i][j]);
        }//for j
    }//for i
    printf("}\n");
}//main

/*
>ch07_00q_03
a[][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9, }

*/