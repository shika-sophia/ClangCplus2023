/**
*@directory ClangC11Console / ClanC11Sample / CAnsiYH / CAnsiYH03_Type
*@fileName  MainOperatorSizeofSample.c
*@based on  C99YH09_Array\MainArraySizeofSample.c
*@reference C99YH    ���� �_ �wC����v���O���~���O���b�X�� [�����] ��R�ŁxSB Creative, 2019
*@reference CAnsiYH  ���� �_ �wC����v���O���~���O���b�X�� [���@��] �V�Łx  SB Creative, 2006
*@reference C11DS    arton  �w�ƏK C �V�Łx�ĉj��, 2018
*
*@content CAnsiYH Chapter 3  Type | Operator 'sizeof()' / List - / p53
*@summary MainOperatorSizeofSample.c
* 
*@English [P] operator  (n):      ���Z�q
*         [P] Wide-Character (n): �S�p����
* 
*@subject ��Operator 'sizeof()' �kC99YH p267�l
*         int  sizeof( Type )    // It returns 'int' value of how bytes the argument Type have
*
*         �EArray length:  calculated from '(whole array bytes) / (one element bytes)' as below [Example]
*
*         �E�yNotation�zin the case of including Wide-Character such as Japanese:
*            The size of one element can be variable.
*            Therefore, Array Length cannot be calculated correctly by above expression.
*
*         [Example]
*         int length = sizeof(pointAry) / sizeof(pointAry[0]);
*
*         => copy from �kC99YH09_Array\MainArraySizeofSample.c�l
*
*@subject ��Operator 'sizeof()' �kCAnsiYH p53�l
* 
*
*@see     C99YH09_Array\MainArraySizeofSample.c
*@author  shika
*@date    2023-01-24
*/

#include <stdio.h>

int main(void) {
//int mainXxxx(void) {

    return 0;
}//main()