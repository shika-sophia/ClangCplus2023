/*
�Eextern�̗p�@
*/

#include <stdio.h>

extern int ex2(int x, int y);

extern int ex1(int x, int y)
{
    printf("ex1: %i\n", x + y);
    return x + y;
}//ex1

int main()
{
    ex1(2, 3);
    ex2(5, 6);
}

/*
�y�R���p�C���E�G���[�z
�������̊O���V���{�� _ex2 ���֐� _main �ŎQ�Ƃ���܂���
ch09_01.exe : fatal error LNK1120: 1 ���̖������� �O���Q��

>ch09_01
ex2: 30
*/