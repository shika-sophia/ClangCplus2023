/**
*@directory ClangC11Console / ClanC11Sample / C99YH / C99YH08_Function
*@fileName  MainSelfDefinedFunctionSample.c
*@reference C99YH  ���� �_ �wC����v���O���~���O���b�X�� [�����] ��R�ŁxSB Creative, 2019
*@reference CAnsi  ���� �_ �wC����v���O���~���O���b�X�� [���@��] �V�Łx  SB Creative, 2006
*@reference C11DS  arton  �w�ƏK C �V�Łx�ĉj��, 2018
*
*@content C99YH ��W�� �֐� | Chapter 8 Function / List 8-2, 8-3, 8-4 / p221
*@summary MainSelfDefinedFunctionSample.c
*
*@subject List 8-2  Calculate addition
*         int  getAdd(int a, int b)     //self defined
*
*@subject List 8-3  Show '*' graph
*         void showGraph(int value)     //self defined
* 
*@subject List 8-4  Calculate the power
*         int  getPower(int base, int power)  //self defined
*                                             //return base ^ power
* 
*@see
*@author shika
*@date 2022-12-23
*/

#include <stdio.h>

int getAdd(int, int);
void showGraph(int);
int getPower(int, int);

//int main(void) {
int mainSelfDefinedFunctionSample(void) {
    //---- List 8-2 ----
    int a = 3;
    int b = 5;

    int result = getAdd(a, b);
    printf("%d + %d = %d\n", a, b, result);
    printf("\n");

    //----List 8-3 ----
    showGraph(result);
    printf("\n");

    //---- List 8-4 ----
    int base = 2;
    int power = 8;

    int poweredResult = getPower(base, power);

    if (poweredResult != -9999) {
        printf("%d ^ %d = %d\n", base, power, poweredResult);
    }
    printf("\n");

    return 0;
}//main()

int getAdd(int a, int b) {
    return a + b;
}//getAdd()

void showGraph(int value) {
    if (value < 0) {
        printf("%d (minus value)\n", value);
        return;
    }

    printf("%d ", value);
    for (int i = 0; i < value; i++) {
        putchar('*');
    }//for
    printf("\n");

}//showGraph()

int getPower(int base, int power) {
    int result = 1;

    if (power == 0) { return 1; }

    if (power < 0) {
        printf("<�I> minus power cannot calculate in this function.\n");
        return -9999;
    }

    if (base == 0) { return 0; } // case 'power == 0' return 1, above.

    for (int i = 0; i < power; i++) {
        result *= base;
    }//for

    return result;
}//getPower()

/*
//====== Result ======
//---- List 8-2 ----
3 + 5 = 8

//---- List 8-3 ----
8 ********

//---- List 8-4 ----
3 ^ 1 = 3
3 ^ 2 = 9
3 ^ 0 = 1
2 ^ 0 = 1
0 ^ 5 = 0
0 ^ 0 = 1
-1 ^ 5 = -1
2 ^ 8 = 256

(case 2 ^ -1)
<�I> minus power cannot calculate in this function.

*/