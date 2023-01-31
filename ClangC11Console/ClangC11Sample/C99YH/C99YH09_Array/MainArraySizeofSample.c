/**
*@directory ClangC11Console / ClanC11Sample / C99YH / C99YH09_Array
*@fileName  MainArraySizeofSample.c
*@reference C99YH  結城 浩 『C言語プログラミングレッスン [入門編] 第３版』SB Creative, 2019
*@reference CAnsi  結城 浩 『C言語プログラミングレッスン [文法編] 新版』  SB Creative, 2006
*@reference C11DS  arton  『独習 C 新版』翔泳社, 2018
*
*@content C99YH 第９章 配列 | Chapter 9  Array / List 9-7 / p267
*@summary MainArraySizeofSample
*         ◆Array Definition
*         (1) Array Definition
*         (2) Array Definition with Initialize
* 
*         ◆Operator 'sizeof()'
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
          [P] initializer (n):    初期化子 { }
          [P] Wide-Character (n): 全角文字

*@subject ◆ Array Definition 〔p267〕
*         (1) [Array Definition]
*             The definition of Array is required the argument of array length with bracket '[]'.
*         
*         (2) [Array Definition with Initialize]
*             Array can be defined with initial elements of the same Type, when it is defined with using initializer '{ }' only.
*             In this case, the array length is automatically caluculated from the number of elements,
*             so that '[]' can be empty still.
* 
*         ・【Detail Annotation】
*            We need put ';' after '{ ... }'.
*            We need delimit elemants by ',' -- if elements are multiple.
* 
*         [Format] Array Defininition
*         (1) Type arrayName[int arrayLength]; 
*         (2) Type arrayName[] = { ... }; 
* 
*         [Example]
*         char name[NAME_MAX];               // asumming 'NAME_MAX' is defined as 'int' Type before there.
*         int  pointAry[] = { 65, 90, 72, }; // Initialize case
*
*@subject ◆Operator 'sizeof()' 〔C99YH p267〕〔CAnsiYH p53〕
*         Operator 'sizeof()': It returns 'int' value of how bytes the Variable given by argument 'Type' occupy in Memory.
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
*         => copy from〔CAnsiYH03_Type\MainOperatorSizeofSample.c〕
* 
*@see MainArrayAverageSample.c
*@see CAnsiYH03_Type\MainOperatorSizeofSample.c
*@author shika
*@date 2022-12-25
*/

#include <stdio.h>

//int main(void) {
int mainArraySizeofSample(void) {
    int pointAry[] = { 65, 90, 72, };
    int sum = 0;
    int length = sizeof(pointAry) / sizeof(pointAry[0]);
    double average = 0.0;

    printf("Points:  ");
    for (int i = 0; i < length; i++) {
        sum += pointAry[i];
        printf("%d, ", pointAry[i]);
    }//for
    printf("\n");

    average = (double)sum / length;

    printf("Summary: %d\n", sum);
    printf("Average: %.2f\n", average);
    printf("\n");
    printf("Array Bytes:   %d\n", sizeof(pointAry));
    printf("Element Bytes: %d\n", sizeof(pointAry[0]));
    printf("Array Length:  %d\n", length);

    return 0;
}//main()

/*
//====== Result =======
Points:  65, 90, 72,
Summary: 227
Average: 75.67

Array Bytes:   12
Element Bytes: 4
Array Length:  3
*/