/**
*@directory ClangC11Console / ClanC11Sample / C99YH / C99YH09_Array
*@fileName  MainCharArraySample.c
*@reference C99YH  ���� �_ �wC����v���O���~���O���b�X�� [�����] ��R�ŁxSB Creative, 2019
*@reference CAnsi  ���� �_ �wC����v���O���~���O���b�X�� [���@��] �V�Łx  SB Creative, 2006
*@reference C11DS  arton  �w�ƏK C �V�Łx�ĉj��, 2018
*
*@content C99YH ��X�� �z�� | Chapter 9  Array / List 9-5, 9-6 / p264
*@summary Array of Char
*
*@English [�p] express:  �\������A�\��
*         [�p] expression:  [��] ���A�\��
*         [�p] represent:   �\���A��\����
*         [�p] indicate:    �����A�w������
*         [�p] indicator:   �w�W
*         [�p] iterate:     �J��Ԃ���������
*         [�p] character:   ����
*         [�p] string:      ������ (= text)�A��
* 
*@subject array[i] != '\0': conditional expression in 'for' sentence
*         �E'\0': NUL Character: It is a character which indicates the end of string text.
*         �EThis [Example] below represents an Iteration from first to end of string text.
* 
*         [Example]
*         for (int i = 0; array[i] != '\0'; i++) { ... }
* 
*@subject operator '&': Address operator
*         �EIt get not the value but the adderss on memory.
*         => as datial in�kChapter 11 Pointer�l
* 
*         �EThis [Example] below shows whole elements of 'textAry' as 'char' type array.
*           as same 'for for (int i = 0; array[i] != '\0'; i++)' above.
* 
*         [Example] 
*         printf("%s", &textAry[0]);
*
*@subject unsigned char
*         �EIn this case, the element of 'char' array treat as 'unsigned char' type,
*           so that 'sign-expand' will not appear.
*         �EIf it is defined as 'char' type, Compiler recognized the most digit as 'sign bit',
*           so that 'sign-expand' changes showing '8C 8B 8F E9 8D 5F' to 'FFFFFF8C FFFFFF8B FFFFFF8F FFFFFFE9 FFFFFFF8D 5F'.
*         �EIt can use 2 bytes character as like '����_'.
*
*@subject definition of string text
*         �EWhen Array is defined, it can be substituted the string by "",
*           in this case, it is not necessary '\0' NUL Character, 
*           '\0' is automatically inserted by Compiler.
* 
*         [Example]
*         unsigned char textAry[] = "ABC 123 ����_";
* 
*@see
*@author shika
*@date 2022-12-25
*/

#include <stdio.h>

//int main(void) {
int mainCharArraySample(void) {
    //---- List 9-5 ----
    char textAry[7];

    textAry[0] = 'H';
    textAry[1] = 'e';
    textAry[2] = 'l';
    textAry[3] = 'l';
    textAry[4] = 'o';
    textAry[5] = '\n';   // line feed
    textAry[6] = '\0';   // Nall Cahracter

    printf("CharArray:  ");
    for (int i = 0; textAry[i] != '\0'; i++) {
        printf("%c", textAry[i]);
    }//for
    printf("\n");

    printf("&-Operator: %s\n", &textAry[0]);

    //---- List 9-6 -----
    unsigned char name[] = "ABC 123 ����_";

    printf("IntArray:   ");
    for (int i = 0; name[i] != '\0'; i++) {
        printf("%2X ", name[i]);
    }//for
    printf("\n");

    printf("CharArray:  ");
    for (int i = 0; name[i] != '\0'; i++) {
        printf("%c", name[i]);
    }//for
    printf("\n");

    printf("&-Operator: %s\n", &name[0]);

    return 0;
}//main()

/*
//====== Result ======
//---- List 9-5 ----
CharArray:  Hello.
&-Operator: Hello.

//---- List 9-6 ----
IntArray:   41 42 43 20 31 32 33 20 8C 8B 8F E9 8D 5F // Shift-JIS (= Windows-31J, CP932)
CharArray:  ABC 123 ����_
&-Operator: ABC 123 ����_

*/