/**
*@directory ClangC11Console / ClanC11Sample / C99YH / C99YH03_Valiable
*@fileName  MainNumericTypeRange.c
*@reference C99YH  ���� �_ �wC����v���O���~���O���b�X�� [�����] ��R�ŁxSB Creative, 2019
*@reference CAnsi  ���� �_ �wC����v���O���~���O���b�X�� [���@��] �V�Łx  SB Creative, 2006
*@reference C11DS  arton  �w�ƏK C �V�Łx�ĉj��, 2018
*
*@content C99YH ��Q�� �v�Z / List 2-7 / p49
*         ���l�^�̗L���͈͂�\��
* 
*@English [�p] numeric:  ���l��
*         [�p] range:    �͈�
* 
*@subject <limits.h>  ���l�^�̗L���͈͂��` (�R���p�C���ɂ���ĈقȂ�)
*            CHAR_MAX, CHAR_MIN,
*            INT_MAX, INT_MIN, 
*            LONG_MAX, LONG_MIN,
*            LLONG_MAX, LLONG_MIN
* 
*         ��Range of Numeric Type (in this Compiler)
*         ��char  : -128 �` 127
*         ��int   : -2147483648 �` 2147483647
*         ��long  : -2147483648 �` 2147483647
*         ��llong : -9223372036854775808 �` 9223372036854775807
*
*@see
*@author shika
*@date 2022-12-10
*/

#include <stdio.h>
#include <limits.h>

//int main(void) {
int mainNumericTypeRange(void) {
    printf("��Range of Numeric Type (in this Compiler)\n");
    printf("��char  : %d �` %d\n", CHAR_MIN, CHAR_MAX);
    printf("��int   : %d �` %d\n", INT_MIN, INT_MAX);
    printf("��long  : %ld �` %ld\n", LONG_MIN, LONG_MAX);
    printf("��llong : %lld �` %lld\n", LLONG_MIN, LLONG_MAX);
    
    return 0;
}//main()

/*
//====== Result ======
��Range of Numeric Type (in this Compiler)
��char  : -128 �` 127
��int   : -2147483648 �` 2147483647
��long  : -2147483648 �` 2147483647
��llong : -9223372036854775808 �` 9223372036854775807

*/
