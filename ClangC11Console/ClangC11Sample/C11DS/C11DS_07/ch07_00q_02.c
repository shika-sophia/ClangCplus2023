/*
2. 0���� 9�܂ł��o�͂��� do�����g�����v���O�����B���̉��Z�� do���̏��������ŁA
 �萔�� 0, 10 �̂݁B
*/

#include <stdio.h>

int main(void)
{
    int i = 0;
    do {
        printf("%i, ", i);
    } while (++i < 10);

    return 0;
}//main

/*
>ch07_00q_02
0, 1, 2, 3, 4, 5, 6, 7, 8, 9,

*/