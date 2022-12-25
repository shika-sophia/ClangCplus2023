/**
*@directory ClangC11Console / ClanC11Sample / C99YH / C99YH09_Array
*@fileName  MainArraySizeofSample.c
*@reference C99YH  ���� �_ �wC����v���O���~���O���b�X�� [�����] ��R�ŁxSB Creative, 2019
*@reference CAnsi  ���� �_ �wC����v���O���~���O���b�X�� [���@��] �V�Łx  SB Creative, 2006
*@reference C11DS  arton  �w�ƏK C �V�Łx�ĉj��, 2018
*
*@content C99YH ��X�� �z�� | Chapter 9  Array / List 9-7 / p267
*@summary MainArraySizeofSample
*         �EInitialize Array
*         �Eoperator 'sizeof()'
* 
*@subject Initialize Array
* 
*         [Example]
*         int  pointAry[] = { 65, 90, 72, };
*
*@subject operator 'sizeof()'
* 
* 
*@see MainArrayAverageSample.c
*@author shika
*@date 2022-12-25
*/

#include <stdio.h>

//int main(void) {
int mainArraySizeofSample(void) {
    int pointAry[] = { 65, 90, 72, };
    int sum = 0;
    int length = sizeof(pointAry) / sizeof(pointAry[0]);
    double average = 0.0;

    printf("Points:  ");
    for (int i = 0; i < length; i++) {
        sum += pointAry[i];
        printf("%d, ", pointAry[i]);
    }//for
    printf("\n");

    average = (double)sum / length;

    printf("Summary: %d\n", sum);
    printf("Average: %.2f\n", average);

    return 0;
}//main()

/*
//====== Result =======
Points:  65, 90, 72,
Summary: 227
Average: 75.67

*/