/**
*@directory ClangC11Console / ClanC11Sample / CAnsiYH / CAnsiYH05_Array
*@fileName  Practice_CAnsiYH05.c
*@reference C99YH    結城 浩 『C言語プログラミングレッスン [入門編] 第３版』SB Creative, 2019
*@reference CAnsiYH  結城 浩 『C言語プログラミングレッスン [文法編] 新版』  SB Creative, 2006
*@reference C11DS    arton  『独習 C 新版』翔泳社, 2018
*
*@content CAnsiYH Chapter 5  Array | Practice / List - / p99
*@summary Practice_CAnsiYH05.c
*@English
*@subject Practice 1:
*         Define Function 'void sort_data(void)' which sort the elements of Array 'int data[MAX_DATA]' as ascending,
*         asumming that '#define MAX_DATA' has already defined, and that the elements are different each other.
*
*         [My Answer] -> code below
* 
*@subject Practice 2:
*         Define Function 'void count_data(int *evenp, int *oddp, int *zerop)'
*         which count each numbers 'even, odd, zero' of Array 'data[]' as same as above,
*         however return them to each Pointer '*evenp *oddp, *zerop'.
* 
*         [My Answer] -> code below
* 
*@subject Practice 3:
*         Define Function 'void pAry_reverse(void)' 
*         which reverse the order of characters in Array 'char *pAry[PA_SIZE]',
*         assuming that '#define PA_SIZE' has already defined.
* 
*         [My Answer] -> code below
* 
*@see
*@author  shika
*@date    2023-02-05
*/

#include <stdio.h>

#define MAX_DATA 5
#define PA_SIZE 7

void sort_dataCAnsiYH05(void);
void count_dataCAnsiYH05(int*, int*, int*);
void pAry_reverseCAnsiYH05(void);

int dataCAsiYH05[MAX_DATA] = { 3, 5, 0, 9, 2 };
char* pAryCAnsiYH05[PA_SIZE] = { "Sophia" };

int main(void) {
//int mainPractice_CAnsiYH05(void) {
    //---- Practice 1 ----
    printf("Before Sort of data[]: ");
    for (int i = 0; i < MAX_DATA; i++) {
        printf("%d, ", dataCAsiYH05[i]);
    }
    printf("\n");

    sort_dataCAnsiYH05();

    printf("After  Sort of data[]: ");
    for (int i = 0; i < MAX_DATA; i++) {
        printf("%d, ", dataCAsiYH05[i]);
    }
    printf("\n");

    //---- Practice 2 ----
    int even = 0;
    int odd = 0;
    int zero = 0;

    count_dataCAnsiYH05(&even, &odd, &zero);

    printf("Even: %d \n", even);
    printf("Odd : %d \n", odd);
    printf("Zero: %d \n", zero);
    printf("\n");

    //---- Practice 3 ----
    printf("pAry (before): %s \n", *pAryCAnsiYH05);
    pAry_reverseCAnsiYH05();
    printf("pAry (after) : %s \n", *pAryCAnsiYH05);
    printf("\n");

    printf("EXIT_SUCCESS \n");
    return 0;
}//main()

//---- Practice 1 ----
void sort_dataCAnsiYH05(void) {
    for (int i = 0; i < MAX_DATA - 1; i++) {
        for (int j = i + 1; j < MAX_DATA; j++) {
            if (dataCAsiYH05[i] > dataCAsiYH05[j]) {
                int temp = dataCAsiYH05[i];
                dataCAsiYH05[i] = dataCAsiYH05[j];
                dataCAsiYH05[j] = temp;
            }
        }// for j
    }//for i
}//sort_dataCAnsiYH05()

//---- Practice 2 ----
void count_dataCAnsiYH05(int* evenp, int* oddp, int* zerop) {
    for (int i = 0; i < MAX_DATA; i++) {
        if (dataCAsiYH05[i] == 0) {
            (*zerop)++;
            continue;
        }

        if (dataCAsiYH05[i] % 2 == 0) {
            (*evenp)++;
        }
        else {
            (*oddp)++;
        }
    }//for
}//count_dataCAnsiYH05()

//---- Practice 3 ----
void pAry_reverseCAnsiYH05() {
    char* pAryReversed[PA_SIZE] = { "" };

    for (int i = 0; i < PA_SIZE - 2; i++) {
        char c = pAryCAnsiYH05[i];

        for (int j = PA_SIZE - 2; j > 0; j--) {
            *pAryReversed[i] = c;
        }//for j
    }//for i
    *pAryReversed[PA_SIZE - 1] = '\0';
    printf("pAryReversed: %s \n", *pAryReversed);

    *pAryCAnsiYH05 = *pAryReversed;
}//pAry_reverseCAnsiYH05

/*
//====== Result ======
//---- Practice 1 ----
Before Sort of data[]: 3, 5, 0, 9, 2,
After  Sort of data[]: 0, 2, 3, 5, 9,

//---- Practice 2 ----
Even: 1
Odd : 3
Zero: 1

//---- Practice 3 ----
pAry (before): Sophia
ClangC11Console.exe (プロセス 5388) は、コード -1073741819 で終了しました。

(Give up)

*/
