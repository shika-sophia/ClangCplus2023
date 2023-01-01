/**
*@directory ClangC11Console / ClanC11Sample / C99YH / C99YH11_Pointer
*@fileName  MainPointerArraySample.c
*@reference C99YH  ���� �_ �wC����v���O���~���O���b�X�� [�����] ��R�ŁxSB Creative, 2019
*@reference CAnsi  ���� �_ �wC����v���O���~���O���b�X�� [���@��] �V�Łx  SB Creative, 2006
*@reference C11DS  arton  �w�ƏK C �V�Łx�ĉj��, 2018
*
*@content C99YH ��11�� Pointer | Chapter 11 / List - / p357
*@summary MainPointerArraySample.c
*@English [�p] quantity:  ��
* 
*@subject Pointer as one of Array Element
*        
*         [Example]
*         int a[3];
*         int *p;
*         p = &a[0];
*         
*@subject Array with 'for'-Iteration
*         
*         [Example]
*         int a[3];
*         for (int i = 0; i < 3; i++) {
*              a[i] = i * i;
*         }
* 
*@subject Pointer of Array with 'for'-Iteration
*         �E'p++': Pointer indicates the memory address of the indicating variable.
*                  'p++' means not increment [+1] of address, but increase address to quantity of 'sizeof(int)'.
*                  It automatically calculate the necessary quantity of memory size of this type.
*                  In this case: 'p = &a[0]', Pointer 'p' seems to indicate only one of Array element: 'a[0]'.
*                  But increased the address by 'p++', Pointer indicates the next element too.
*                  Of course, in 'p--' case, Pointer indicates the previous element unless array range over.
* 
*         [Example]
*         int a[3];
*         int *p;
*         p = &a[0];
*         
*         for (int i = 0; i < 3; i++) {
*             *p = i * i;
*             p++;
*         }
* 
*@see
*@author shika
*@date 2023-01-01
*/

#include <stdio.h>

#define ELEMENT_MAX 3

//int main(void) {
int mainPointerArraySample(void) {
    int array[ELEMENT_MAX];
    int* p;
    p = &array[0];

    for (int i = 0; i < ELEMENT_MAX; i++) {
        *p = i * i;
        p++;
    }//for

    //---- Show array[] ----
    printf("array[i]: ");
    for (int i = 0; i < ELEMENT_MAX; i++) {
        printf("%d, ", array[i]);
    }//for
    printf("\n");

    printf("p: ");
    for (int i = 0; i < ELEMENT_MAX; i++) {
        printf("%p, ", p);
        p++;
    }//for
    printf("\n");

    printf("*p: ");
    for (int i = 0; i < ELEMENT_MAX; i++) {
        printf("%d, ", *p);
        p++;
    }//for
    printf("\n");

    return 0;
}//main()

/*
//====== Result ======
array[i]: 0, 1, 4,                  (array element)
p:  005EFA40, 005EFA44, 005EFA48,   (address)
*p: -858993460, 520942796, 19921340, // unexpected result

*/