/**
*@directory ClangC11Console / ClanC11Sample / C99YH / C99YH05_SwitchMultiBranch
*@fileName  MainSwitchGetcharSample.c
*@based     MainSwitchAtoiSample.c
*@reference C99YH  結城 浩 『C言語プログラミングレッスン [入門編] 第３版』SB Creative, 2019
*@reference CAnsi  結城 浩 『C言語プログラミングレッスン [文法編] 新版』  SB Creative, 2006
*@reference C11DS  arton  『独習 C 新版』翔泳社, 2018
*
*@content C99YH 第５章 Switch | Chapter 5 getchar() / List 5-2, 5-3 / p140
*@summary MainSwitchGetcharSample
*
*@subject <stdio.h>
*           └ int  getchar(void)  //can get user inputs without fgets(), definition of buffer, BUFFER_SIZE.
*                                 //see【Analysis】below.
*
*@see MainSwitchAtoiSample.c
*@author shika
*@date 2022-12-17
*/

#include <stdio.h>

//int main(void) {
int mainSwitchGetcharSample(void) {
    char select;

    printf("◆Menu\n");
    printf("  A. Coffee\n");
    printf("  B. Milk\n");
    printf("  C. (neither)\n");
    printf("\n");

    printf("＊Please select your order > ");
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
        printf("<！> Program Error in 'select' value = %d\n", select);
        break;
    }//switch
    printf("\n");
}//main()

/*
//====== Result ======
◆Menu
  A. Coffee
  B. Milk
  C. (neither)

＊Please select your order > a
You selected Coffee.
＊Please select your order > C
You selected '(neither)'.
＊Please select your order > Ａ (= 2 byte character)
<！> Program Error in 'select' value = -126
＊Please select your order > 00
<！> Program Error in 'select' value = 48
＊Please select your order > ABC
You selected Coffee.            //(unexpected result)

【Analysis】
 ・getchar() can get user inputs without fgets(), definition of buffer, BUFFER_SIZE.
 ・getchar() is more simple input method than fgets(), 
   but it cannot validate input and use question loop as〔MainSwitchAtoiSample.c〕
 ・Because this program cannot completely exclude invalid input, 
   it is often thrown Label default: '<！> Program Error',
   or output unexpected value in many cases.

*/