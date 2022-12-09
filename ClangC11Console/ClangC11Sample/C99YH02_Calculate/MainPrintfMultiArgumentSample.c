/**
*@title ClangC11Console / ClanC11Sample / C99YH / C99YH02_Calculate
*@class MainPrintfMultiArgumentSample.c
*@reference C99YH  ���� �_ �wC����v���O���~���O���b�X�� [�����] ��R�ŁxSB Creative, 2019
*@reference CAnsi  ���� �_ �wC����v���O���~���O���b�X�� [���@��] �V�Łx  SB Creative, 2006
*@reference C11DS  arton  �w�ƏK C �V�Łx�ĉj��, 2018
*
*@content C99YH ��Q�� �v�Z p33 
*@summary �Eprintf("%d", value)
*           => �kC99YH01_ConsoleOutput\MainPrintfSample.c�l
*         �Emulti arguments
*             printf("%d, %d", value1, value2, ...)
*         �Ecalc order priority
*             ( )    High
*             * / %  
*             + -    Low
*             
*         �EShow �u%�v
*@subject 
*
*@see
*@author shika
*@date 2022-12-09
*/

#include <stdio.h>

//int main(void) {
int mainPrintfMultiArgumentSample(void) {
    //---- printf() %d ----
    int a = 5;
    int b = 2;

    printf("a = %d \n", a);
    printf("b = %d \n", b);
    printf("a + b = %d \n", a + b);
    printf("a - b = %d \n", a - b);
    printf("a * b = %d \n", a * b);
    printf("a / b = %d \n", a / b);

    //---- multi argument ----
    printf("%d + %d = %d \n", a, b, a + b);

    //---- calc order priority ----
    printf("1 + 2 * 3 - 4 / 2 = %d \n", 1 + 2 * 3 - 4 / 2);
    printf("(1 + 2) * 3 - (4 / 2) = %d \n", (1 + 2) * 3 - (4 / 2));

    //---- % ----
    printf("100%% \n");
    printf("%%%%:  %% \n");
    printf("%%c:  %c \n", '%');
    printf("%%s:  %s \n", "%");
    return 0;
}//main()

/*
//==== Result ====
//---- printf() %d ----
a = 5
b = 2
a + b = 7
a - b = 3
a * b = 10
a / b = 2

//---- multi argument ----
5 + 2 = 7

//---- calc order priority ----
1 + 2 * 3 - 4 / 2 = 5
(1 + 2) * 3 - (4 / 2) = 7

//---- % ----
100%
%%:  %
%c:  %
%s:  %
*/