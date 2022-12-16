/**
*@directory ClangC11Console / ClanC11Sample / C99YH / C99YH05_SwitchMultiBranch
*@fileName  MainSwitchGetcharSample.c
*@based     MainSwitchAtoiSample.c
*@reference C99YH  ���� �_ �wC����v���O���~���O���b�X�� [�����] ��R�ŁxSB Creative, 2019
*@reference CAnsi  ���� �_ �wC����v���O���~���O���b�X�� [���@��] �V�Łx  SB Creative, 2006
*@reference C11DS  arton  �w�ƏK C �V�Łx�ĉj��, 2018
*
*@content C99YH ��T�� Switch | Chapter 5 getchar() / List 5-2, 5-3 / p140
*@summary MainSwitchGetcharSample
*
*@subject <stdio.h>
*           �� int  getchar(void)  //can get user inputs without fgets(), definition of buffer, BUFFER_SIZE.
*                                 //see�yAnalysis�zbelow.
*
*@see MainSwitchAtoiSample.c
*@author shika
*@date 2022-12-17
*/

#include <stdio.h>

//int main(void) {
int mainSwitchGetcharSample(void) {
    char select;

    printf("��Menu\n");
    printf("  A. Coffee\n");
    printf("  B. Milk\n");
    printf("  C. (neither)\n");
    printf("\n");

    printf("��Please select your order > ");
    select = getchar();

    //---- switch & show confirmation ----
    switch (select) {
    case 'A': //FALL THROUGH
    case 'a':
        printf("You selected Coffee.\n");
        break;
    case 'B': //FALL THROUGH
    case 'b':
        printf("You selected Milk.\n");
        break;
    case 'C': //FALL THROUGH
    case 'c':
        printf("You selected '(neither)'.\n");
        break;
    default:
        printf("<�I> Program Error in 'select' value = %d\n", select);
        break;
    }//switch
    printf("\n");
}//main()

/*
//====== Result ======
��Menu
  A. Coffee
  B. Milk
  C. (neither)

��Please select your order > a
You selected Coffee.
��Please select your order > C
You selected '(neither)'.
��Please select your order > �` (= 2 byte character)
<�I> Program Error in 'select' value = -126
��Please select your order > 00
<�I> Program Error in 'select' value = 48
��Please select your order > ABC
You selected Coffee.            //(unexpected result)

�yAnalysis�z
 �Egetchar() can get user inputs without fgets(), definition of buffer, BUFFER_SIZE.
 �Egetchar() is more simple input method than fgets(), 
   but it cannot validate input and use question loop as�kMainSwitchAtoiSample.c�l
 �EBecause this program cannot completely exclude invalid input, 
   it is often thrown Label default: '<�I> Program Error',
   or output unexpected value in many cases.

*/