/**
*@directory ClangC11Console / ClanC11Sample / CAnsiYH / CAnsiYH03_Type
*@fileName  MainOperatorSizeofSample.c
*@based on  C99YH09_Array\MainArraySizeofSample.c
*@reference C99YH    結城 浩 『C言語プログラミングレッスン [入門編] 第３版』SB Creative, 2019
*@reference CAnsiYH  結城 浩 『C言語プログラミングレッスン [文法編] 新版』  SB Creative, 2006
*@reference C11DS    arton  『独習 C 新版』翔泳社, 2018
*
*@content CAnsiYH Chapter 3  Type | Operator 'sizeof()' / List - / p53
*@summary MainOperatorSizeofSample.c
* 
*@English [E] occupy    (v):      占める
          [E] specification (n):  指定、仕様、規格
          [E] moderate  (adj):    適当, やや, 緩やか, 中程度, 程よく =:= arbitrary (adj) <-> strict (adj), subtle (adj)
          [E] arbitrary (adj):    任意, 随意, 恣意的
          [E] strict    (adj):    厳密, 厳しく, 固く, 厳格, 厳重, あくまで
          [E] subtle    (adj):    微妙, 繊細, 巧妙, 些細 subtlety (n)  subtly (adv)
          [E] abbreviate (v):     省略する、短縮する  abbreviation (n) 省略形
          [E] allocate   (v):     割り当てる、配分する、場所を決める

          [P] operator  (n):      演算子
          [P] Wide-Character (n): 全角文字
   
*@subject ◆Operator 'sizeof()' 〔C99YH p267〕〔CAnsiYH p53, p93〕
*         Operator 'sizeof()': 
*         ・It returns 'int' value of how bytes the Variable given by argument 'Type' occupy in Memory.
*         ・The return-value is how bytes the Type is occuping, not the Pointer which indicate Variable of the Tyoe. 〔CAnsiYH p93〕
*         ・How bytes each Types occupy in Memory, is only moderately defined by specification of C language.
*         ・Therefore, it is necessary to use 'sizeof', when we must specify how bytes the Type occupy in Memory,
*           such as a program of Memory management.
* 
*         [Format]
*         unsigned int  sizeof( expression )   // including Literal value.
*         unsigned int  sizeof( Type )   
*
*         ・Array length:  calculated from '(whole array bytes) / (one element bytes)' as below [Example]
*
*         ・【Annotation】in the case of including Wide-Character such as Japanese:
*            The size of one element can be variable.
*            Therefore, Array Length cannot be calculated correctly by above expression.
*
*         [Example]
*         int length = sizeof(pointAry) / sizeof(pointAry[0]);
*
*         ＊Array length  〔CAnsiYH p93〕
*         ・Argument of 'sizeof()' can be given whole of Array exceptionally,
*           in this case, the return-value is how bytes the whole of Array is occuping in Memory.
*         ・Identifier of Array can be recognaized as
*           constant value of Pointer which indicate first element of Array.
*         ・The return-value is how bytes the Type is occuping, 
*           not the Pointer which indicate Variable of the Tyoe.
* 
*         => copy to   〔C99YH09_Array\MainArraySizeofSample.c〕
*         => copy from 〔CAnsiYH05_Array\Rererence_CAnsiArray.txt〕
* 
*@subject [Example 1] 〔CAnsi p54〕
*         The program shows how bytes these Primitive Types occupy in Memory, as below code.
* 
*         //====== Result ====
*        【Annotation】The result depends on this Compiler [Clang-C11 of Visual Studio 2019].
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
*        【My Consideration】
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
*@subject ◆Function malloc() => more detail〔CAnsiYH p331〕
*         malloc(): The Function which allocate memory-space in Memory, as much as size given by argument,
*                   and return General Pointer 'void*' to be used by Cast (= Type Change) to arbitrary Type.
*         "malloc" = abbreviation of "Memory allocate" ?
* 
*         [Format]
*         void* malloc(size_t)  // 〔CAnsiYH p331〕
*        (int   malloc(void)    // 〔Visual Studio〕)
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