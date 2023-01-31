/**
*@directory ClangC11Console / ClanC11Sample / CAnsiYH / CAnsiYH03_Type
*@fileName  MainOperatorSizeofSample.c
*@based on  C99YH09_Array\MainArraySizeofSample.c
*@reference C99YH    Œ‹é _ wCŒ¾ŒêƒvƒƒOƒ‰ƒ~ƒ“ƒOƒŒƒbƒXƒ“ [“ü–å•Ò] ‘æ‚R”ÅxSB Creative, 2019
*@reference CAnsiYH  Œ‹é _ wCŒ¾ŒêƒvƒƒOƒ‰ƒ~ƒ“ƒOƒŒƒbƒXƒ“ [•¶–@•Ò] V”Åx  SB Creative, 2006
*@reference C11DS    arton  w“ÆK C V”ÅxãÄ‰jĞ, 2018
*
*@content CAnsiYH Chapter 3  Type | Operator 'sizeof()' / List - / p53
*@summary MainOperatorSizeofSample.c
* 
*@English [E] occupy    (v):      è‚ß‚é
          [E] specification (n):  w’èAd—lA‹KŠi
          [E] moderate  (adj):    “K“–, ‚â‚â, ŠÉ‚â‚©, ’†’ö“x, ’ö‚æ‚­ =:= arbitrary (adj) <-> strict (adj), subtle (adj)
          [E] arbitrary (adj):    ”CˆÓ, ˆÓ, œ“ˆÓ“I
          [E] strict    (adj):    Œµ–§, Œµ‚µ‚­, ŒÅ‚­, ŒµŠi, Œµd, ‚ ‚­‚Ü‚Å
          [E] subtle    (adj):    ”÷–­, ‘@×, I–­, ±× subtlety (n)  subtly (adv)
          [E] abbreviate (v):     È—ª‚·‚éA’Zk‚·‚é  abbreviation (n) È—ªŒ`
          [E] allocate   (v):     Š„‚è“–‚Ä‚éA”z•ª‚·‚éAêŠ‚ğŒˆ‚ß‚é

          [P] operator  (n):      ‰‰Zq
          [P] Wide-Character (n): ‘SŠp•¶š
   
*@subject ŸOperator 'sizeof()' kC99YH p267lkCAnsiYH p53l
*         Operator 'sizeof()': It returns 'int' value of how bytes the Variable given by argument 'Type' occupy in Memory.
*         EHow bytes each Types occupy in Memory, is only moderately defined by specification of C language.
*         ETherefore, it is necessary to use 'sizeof', when we must specify how bytes the Type occupy in Memory,
*           such as a program of Memory management.
* 
*         [Format]
*         unsigned int  sizeof( expression )   // including Literal value.
*         unsigned int  sizeof( Type )   
*
*         EArray length:  calculated from '(whole array bytes) / (one element bytes)' as below [Example]
*
*         EyAnnotationzin the case of including Wide-Character such as Japanese:
*            The size of one element can be variable.
*            Therefore, Array Length cannot be calculated correctly by above expression.
*
*         [Example]
*         int length = sizeof(pointAry) / sizeof(pointAry[0]);
*
*         => copy tokC99YH09_Array\MainArraySizeofSample.cl
*
*@subject [Example 1] kCAnsi p54l
*         The program shows how bytes these Primitive Types occupy in Memory, as below code.
* 
*         //====== Result ====
*        yAnnotationzThe result depends on this Compiler [Clang-C11 of Visual Studio 2019].
*         The unit is 'Byte'.
* 
*         char : 1
*         char*: 4
*         short: 2
*         int  : 4
*         long : 4
*         long long: 8
* 
*         float: 4
*         double: 8
*         long double: 8
* 
*@subject [Example 2]
*         The program is that measure the necessary size in Memory, by using 'sizeof',
*         and give it to argument of Function 'malloc(size_t)'.
*         
*        yMy Considerationz
*         But according to Result below, the size of 'mateP' is 4,
*         I cannot judge which the result is correct or wrong, yet.
* 
*         //====== Result ======
*         MATE : 80
*         MATE Memory: 800
*         mateP: 4
* 
*@subject [Example 3] as similar as Array Length above.
* 
*@subject ŸFunction malloc() => more detailkCAnsiYH p331l
*         malloc(): The Function which allocate memory-space in Memory, as much as size given by argument,
*                   and return General Pointer 'void*' to be used by Cast (= Type Change) to arbitrary Type.
*         "malloc" = abbreviation of "Memory allocate" ?
* 
*         [Format]
*         void* malloc(size_t)  // kCAnsiYH p331l
*        (int   malloc(void)    // kVisual Studiol)
* 
*@see     C99YH09_Array\MainArraySizeofSample.c
*@author  shika
*@date    2023-01-24
*/

#include <stdio.h>

typedef struct SchoolMate {
    int id;
    char name[50];
    int scoreAry[5];
    long totalIndividual;
} MATE;

//int main(void) {
int mainOperatorSizeofSample(void) {
    //---- [Example 1] ----
    printf("char : %u \n", sizeof(char));
    printf("char*: %u \n", sizeof(char*));
    printf("short: %u \n", sizeof(short));
    printf("int  : %u \n", sizeof(int));
    printf("long : %u \n", sizeof(long));
    printf("long long: %u \n", sizeof(long long));
    printf("float: %u \n", sizeof(float));
    printf("double: %u \n", sizeof(double));
    printf("long double: %u \n", sizeof(long double));
    printf("\n");
    
    //---- [Example 2] ----
    MATE *mateP;
    mateP = (MATE*)malloc(sizeof(MATE) * 10);

    printf("MATE : %u \n", sizeof(MATE));
    printf("MATE Memory: %u \n", sizeof(MATE) * 10);
    printf("mateP: %u \n", sizeof(mateP));

    return 0;
}//main()

/*
//====== Result ======
//---- [Example 1] ----
char : 1
char*: 4
short: 2
int  : 4
long : 4
long long: 8
float: 4
double: 8
long double: 8

//---- [Example 2] ----
MATE : 80
MATE Memory: 800
mateP: 4

*/