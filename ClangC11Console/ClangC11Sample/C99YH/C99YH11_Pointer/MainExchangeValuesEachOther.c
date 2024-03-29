/**
*@directory ClangC11Console / ClanC11Sample / C99YH / C99YH11_Pointer
*@fileName  MainExchangeValuesEachOther.c
*@reference C99YH  結城 浩 『C言語プログラミングレッスン [入門編] 第３版』SB Creative, 2019
*@reference CAnsi  結城 浩 『C言語プログラミングレッスン [文法編] 新版』  SB Creative, 2006
*@reference C11DS  arton  『独習 C 新版』翔泳社, 2018
*
*@content C99YH 第11章 Pointer | Chapter 11 / List 11-1 / p365
* 
*@summary self-defined Function to exchange values each other
*         -> Algorithm to exchange values each other
*         =>〔C99YH09_Array\MainCalculateStatsFromFileViewer.c〕
* 
*@English [Program] call by value:     値渡し   direct, pass by value
*         [Program] call by reference: 参照渡し indirect, pass by reference
*         [英] specification:    仕様 = 開発者が意図して、そのような挙動になるよう設定したもの
*         [英] hand:             渡す =:= pass 通過する, give　与える, deliver　配る
* 
@subject Function with Pointer Argument
*        ・[Call by Value]: Usually, before calling a function and after doing, 
*          the value given to argument, is not change, 
*          because the value given to argument is copied from original variable. 
* 
*          The specification of C language Function is usually [call by Value] behavior,
*          but [Function with Pointer Argument] is [Call by Reference] behavior.
*
*        ・[Call by Reference]: Though [Return] is 'void', operatation about Pointer in function, 
*          can be referred from origin of calling this function. It is specification of [Call by Reference].
*
*         ・Usually a function can return only one value,
*           but in this way, it can return operated-value as same number of Pointer inserted by argument,
*           correctly, because of [Return] void, not 'return' but 'can refer'.
*
*         -> Similar to the operator 'ref' in [C#]
* 
*@subject self-defined Function 
*         ＊Call the Function
*         [Example] in main()
*         int x = 123;
*         int y = 456;
* 
*         exchangeValuesEachOther(&x, &y); <- assign address '&x', '&y' of x, y to arguments of the function
* 
*         ＊Definition 
*         [Example]
*         void exchangeValuesEachOther(int* xPtr, int* yPtr) {  <- assigin address '&x' to value of 'xPtr', '&y' to value of yPtr
*             int temp;       // definition of int variable
*
*             temp = *xPtr;   // assign value '123' which Pointer 'xPtr' storaged in '&x', to int variable 'temp'
*             *xPtr = *yPtr;  // assign value '456' which Pointer 'yPtr' storaged in '&y', to value which Pointer 'xPtr is indicating to '&x'.
*             *yPtr = temp;   // assign value '123' of temp                                to value which Pointer 'yPtr' is indicating to '&y'.
*         }
* 
*@see
*@author shika
*@date 2023-01-02
*/

#include <stdio.h>

void exchangeValuesEachOther(int*, int*);  //self-defined

//int main(void) {
int mainExchangeValuesEachOther(void) {
    int x = 123;
    int y = 456;

    printf("Before Exchange: x = %d, y = %d \n", x, y);
    printf("Before Exchange: xPtr = %p, yPtr = %p \n", &x, &y);
    exchangeValuesEachOther(&x, &y);
    printf("After Exchange:  x = %d, y = %d \n", x, y);
    printf("Apter Exchange:  xPtr = %p, yPtr = %p \n", &x, &y);

    return 0;
}//main()

void exchangeValuesEachOther(int* xPtr, int* yPtr) {
    int temp;

    temp = *xPtr;
    *xPtr = *yPtr;
    *yPtr = temp;
}//exchangeValuesEachOther()

/*
//====== Result ======
Before Exchange: x = 123, y = 456
Before Exchange: xPtr = 00B5FDDC, yPtr = 00B5FDD0
After Exchange:  x = 456, y = 123
Apter Exchange:  xPtr = 00B5FDDC, yPtr = 00B5FDD0

【Analysis】
 It exchanged only values each other,
 not thier address (= address is still before),
 because of Pointer with '*' when assignment.
*/