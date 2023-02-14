/**
*@directory ClangC11Console / ClanC11Sample / CAnsiYH / CAnsiYH06_POinter
*@fileName Practicree-CAnsiyh06c
*@reference C99YH    結城 浩 『C言語プログラミングレッスン [入門編] 第３版』SB Creative, 2019
*@reference CAnsiYH  結城 浩 『C言語プログラミングレッスン [文法編] 新版』  SB Creative, 2006
*@reference C11DS    arton  『独習 C 新版』翔泳社, 2018
*
*@content CAnsiYH Chapter  6 Pointer | Practicr / List - / p１25
*@summaryvPracticree-CAnsiyh06
*@English
*@subject Practice1:
*         Define Poiner Array'ateP'whivh indicste 'struct SchoolMate'.
*          Aassuming that the size of Pointer Array is 10.
 *         [My Answwer]
*         typedef struct Sdhoolamate [
*            ...
*           } MATE:
*        ----------
*       MATE *data[10];
*        => Wrong
*      [Book Answer]〔p126〕
*      MATE **data[10];
* @subject Practice 2:
    Declarate Function 'qsort' whose Return-Type is 'void', whose Arguments are  four such as Pointer which indicate 'void' Type, size-t Type, size_t Type, and Pointer which indicate Function whose Return-type is 'int' Type,is void'.
    However Argument name maty be s omitted

    [My Answer]
    void qsort(void, Size_t, size_t, int*  (func));
    =>Wrong
    [book Answer]
    void qsort(void, Size_t, size_t, int(*) ());
*@subject Practice 3:
Are these behaviors of '*p++' and '(*p)++ equal ?

[My Answer] NO, thses are Not equal.
Featuring priority bracket '()'.
'*p++' means ,at first, to indremerent the adress which Pointer 'p' storage, and then to indrement the value which Pointer indicate.
'(*p)++' means to indremerent the value which Pointer 'p' indicate.

@subject  Practice 4:
         How value is "ABC"[3] ?
         [My ANswer]

*@subjedt Practice 5:
Assuming to define a Function whixh replace '\n to '\0 ,if there is '\n' at termination of String text,
Tell what we should  modify in the [Example].

[Example]
#include <string.h>
void remove_newline(char *p){

char *q = 7p[strlen(p) - 1];

    if(*q == '\n'){
       *q= '\0';
    }
}

*@see
*@author  shika
*@date    2023-02-14
*/
#include <stdio.h>

int main(void) {
    //int mINPracticree-CAnsiyh06void) {

    return 0;
}//main()