/**
*@directory ClangC11Console / ClanC11Sample / C99YH / C99YH02_Calculate
*@fileName  PracticeC99YH02.c
*@reference C99YH  ���� �_ �wC����v���O���~���O���b�X�� [�����] ��R�ŁxSB Creative, 2019
*@reference CAnsi  ���� �_ �wC����v���O���~���O���b�X�� [���@��] �V�Łx  SB Creative, 2006
*@reference C11DS  arton  �w�ƏK C �V�Łx�ĉj��, 2018
*
*@content C99YH ��Q�� �v�Z / ���K��� / p52 
*@subject Practice 2-1
*         0 �~ 0 �` 10 �~ 10 �̌v�Z��\������
*
*         for (int i = 0; i <= 10; i++) { }
* 
*@subject Practice 2-2
*         ��`�̖ʐς����߂�֐����쐬����
*         [�p] trapezoid ��`
* 
*         �֐��錾: ���p����֐��� �֐���, �����^�ƌ�, �߂�l�^�̐錾���K�v 
*         �֐���`: �����𗘗p�����v�Z�E�������ʂ̓��e���L�q���Areturn�Ŗ߂�l���w�肷��
* 
*@see
*@author shika
*@date 2022-12-10
*/

#include <stdio.h>

double trapezoidSquare(int, int, int);

//int main(void) {
int mainPracticeC99YH02(void) {
    //---- Practice 2-1 ----
    for (int i = 0; i <= 10; i++) {
        printf("%2d * %2d = %3d\n", i, i, i * i);
    }//for
    printf("\n");

    //---- Practice 2-2 ----
    int upper = 2;
    int under = 3;
    int height = 4;

    double square = trapezoidSquare(upper, under, height);
    printf("Upper: %d\nUnder: %d\nHeight: %d\nSquare: %.2f\n",
        upper, under, height, square);
    printf("\n");

    return 0;
}//main()

double trapezoidSquare(int upper, int under, int height) {
    return (upper + under) * height / 2.0;
}

/*
//====== Result ======
//---- Practice 2-1 ----
 0 *  0 =   0
 1 *  1 =   1
 2 *  2 =   4
 3 *  3 =   9
 4 *  4 =  16
 5 *  5 =  25
 6 *  6 =  36
 7 *  7 =  49
 8 *  8 =  64
 9 *  9 =  81
10 * 10 = 100

//---- Practice 2-2 ----
Upper: 2
Under: 3
Height: 4
Square: 10.00

*/