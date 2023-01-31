/**
*@directory ClangC11Console / ClanC11Sample / C99YH / C99YH07_WhileIteration
*@fileName  MainWhileCharTypeValidation.c
*@reference C99YH  ���� �_ �wC����v���O���~���O���b�X�� [�����] ��R�ŁxSB Creative, 2019
*@reference CAnsi  ���� �_ �wC����v���O���~���O���b�X�� [���@��] �V�Łx  SB Creative, 2006
*@reference C11DS  arton  �w�ƏK C �V�Łx�ĉj��, 2018
*
*@content C99YH ��V�� WhileIteration | Chapter 7 / List 7-5 / p202
*@summary MainWhileCharTypeValidation
*         judge 'char' type state like alphabet, digit, upper case or lower case.
*
*@subject <ctype.h>  judge 'char' type state
*            �� int  isalpha(int c)   Is the argument 'int c' if alphabet or not.
*            �� int  isupper(int c)   upper case or not
*            �� int  islower(int c)   lower case or not
*            �� int  isdigit(int c)   decimal(=10�i��) or not
*            �� int  isxdigit(int c)  hexa-decimal(=16�i��) or not
*            �� int  isalnum(int c)   (isalpha() or isdigit() is 1 ture) or not
*            �� int  isspace(int c)   white-space or not (including line feed or tab)
*            �� int  isprint(int c)   an already shown character or not
*            �� int  ispunct(int c)   delimiter character or not
*            �� int  toupper(int c)   if lower case, change it to upper case
*            �� int  tolower(int c)   if upper case, change it to lower case
* 
*         �yAnnotation�z
*         �EC99 defined ASCII character as 1 byte character only, not 2 byte character like Japanese.
*           So the above functions can judge value [ 0 - 255 ] or EOF [-1] only.
* 
*@see
*@author shika
*@date 2022-12-22
*/

#include <stdio.h>
#include <ctype.h>

//int main(void) {
int mainWhileCharTypeValidation(void) {
    int c;

    printf("> ");

    //�yAnnotation�zThis need be finished by [Ctrl] + [C].
    while ((c = getchar()) != EOF) {
        if (isupper(c)) {
            c = tolower(c);
        }

        putchar(c);
    }//while 

    return 0;
}//main()

/*
//====== Result ======
> This is Japan. That is USA.
this is japan. that is usa.

^c

*/