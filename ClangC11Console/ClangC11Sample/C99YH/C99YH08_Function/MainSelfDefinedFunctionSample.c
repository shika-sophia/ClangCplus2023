/**
*@directory ClangC11Console / ClanC11Sample / C99YH / C99YH08_Function
*@fileName  MainSelfDefinedFunctionSample.c
*@reference C99YH  ���� �_ �wC����v���O���~���O���b�X�� [�����] ��R�ŁxSB Creative, 2019
*@reference CAnsi  ���� �_ �wC����v���O���~���O���b�X�� [���@��] �V�Łx  SB Creative, 2006
*@reference C11DS  arton  �w�ƏK C �V�Łx�ĉj��, 2018
*
*@content C99YH ��W�� �֐� | Chapter 8 Function / List 8-2, 8-3, 8-4 / p221
*@summary MainSelfDefinedFunctionSample.c
*         �EDeclaration Prototype
*         �EDefinition  Function
*         �EList 8-2, 8-3, 8-4
* 
*@English [�p] declare:  �錾����
*         [�p] define:   ��`����
*         [�p] notify:   �ʒm����
*         [�p] append:   �ǉ�����
*         [�p] reliability:     �M����
*         [�p] maintainability: �ێ琫
* 
*@subject Declaration Prototype:  
*           �EThe declaration is described return-type, function name, argument type on file-top under #directives,
*             not necessary argument name, because of notificaton to Compiler.
*                                 
*           �EIn case of using self-defined function, the declaration must be done,
*             if not, you are thrown Compile Error.
* 
*           �EIn case of using standard funcion, although it seems not to exist,
*             the declaration already has been done in Header file,
*             as like 'printf()' in <stdio.h>, 'atoi()' in <stdlib.h>.
*           
*           �EThe declaration of Prototype should be described at one place,
*             because of reliability, maintainability, and preventing conflicts of multi-place description.
* 
*           [Example]  int getAdd(int, int);
* 
*@subject Definition  Function:   
*           The definition is the body of function, 
*           which is described argument name, function operation, (return-value),
*           appending to the declaration above.
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