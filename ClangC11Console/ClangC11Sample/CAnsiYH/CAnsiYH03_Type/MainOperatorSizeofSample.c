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
*@English [P] operator  (n):      演算子
*         [P] Wide-Character (n): 全角文字
* 
*@subject ◆Operator 'sizeof()' 〔C99YH p267〕
*         int  sizeof( Type )    // It returns 'int' value of how bytes the argument Type have
*
*         ・Array length:  calculated from '(whole array bytes) / (one element bytes)' as below [Example]
*
*         ・【Notation】in the case of including Wide-Character such as Japanese:
*            The size of one element can be variable.
*            Therefore, Array Length cannot be calculated correctly by above expression.
*
*         [Example]
*         int length = sizeof(pointAry) / sizeof(pointAry[0]);
*
*         => copy from 〔C99YH09_Array\MainArraySizeofSample.c〕
*
*@subject ◆Operator 'sizeof()' 〔CAnsiYH p53〕
* 
*
*@see     C99YH09_Array\MainArraySizeofSample.c
*@author  shika
*@date    2023-01-24
*/

#include <stdio.h>

int main(void) {
//int mainXxxx(void) {

    return 0;
}//main()