/**
*@directory ClangC11Console / ClanC11Sample / CAnsiYH / CAnsiYH02_Basic
*@fileName  Practice_CAnsiYH02.c
*@reference C99YH    結城 浩 『C言語プログラミングレッスン [入門編] 第３版』SB Creative, 2019
*@reference CAnsiYH  結城 浩 『C言語プログラミングレッスン [文法編] 新版』  SB Creative, 2006
*@reference C11DS    arton  『独習 C 新版』翔泳社, 2018
*
*@content CAnsiYH Chapter 2  Basic | Practice / p33
*@summary Practice_CAnsiYH02.c
*@English
*@subject Practice
*         1. Which is the following statement, Correct or Wrong in grammer ?
*         〇(a) A Function which shows "OK", is named "0k_print".
*         -> Wrong, numeric character cannot be use at top of Identifier.
* 
*         〇(b) A Variable which strage size of File, is named "size".
*         -> Correct, the name is appreciate with sense of the Variable value.
* 
*         〇(c) A Function which insert data into Database, is named "register".
*         -> Wrong, "register" is Reserved Word. It cannot be used for Identifier.
* 
*         〇(d) A Function which read data from file, is named "read-data".
*         -> Wrong, character '-' cannot be use for Identifier.
*
*         〇(e) A Variable which strage calculated result, is named "integer".
*         -> Correct, 'int' is Reserved Word, but it is not and can be use for Identifier.
*          
*         〇(f) A Function which convert Yen ¥ to Doller $, is named "convert$'.
*         -> Wrong, '$' cannot be use for Identifier.
*
*
*         2. Show in C code the String text:
*               The Character of Line Feed is expressed as \n.
*               Double Quote is expressed as \". 
*
*         〇[My Answer]
*         printf("The Character of Line Feed is expressed as \\n."
*             "Double Quote is expressed as \\\"."); 
*             
*
*         3. What type and how value is the following Constant Value,
*            assuming the Character code of '0' is 48.
* 
*         △(a) 0123     -> int 83
*           => The value is shown 123, if 'printf("%o', 0123);' as my answer.
*           => [Book Anawser] 〇 83
* 
*         〇(b) 0x255    -> int 0x255 = 2 * 16 * 16 + 5 * 16 + 5 
*         〇(c) -1L      -> long -1
*         ×(d) 1.23e-4F -> float -1230
*           => 'e' means "exponent", so 'e4' means powered 4, 'e-4' meanns powered -4.
*               1.23e-4 = 1,23 * ( 1 / 10000) = 0.000123
* 
*         △(e) '\0'     -> FILE* NULL
*           => Type is 'char', value is 0.
*           => [Book Answer] char 0
* 
*         △(f) '0'      -> char 48
*           => The value is shown 0, if 'printf("%c', '0');' as my answer.
*           => [Book Anawser] 〇 48
* 
*         4. Why is thrown the following code Compile Error ?
*          [Quest]
*          void foo(int x) {
*              int x;
*              int i;
*              
*              for (int i = 0; i < x; i++) {
*                  int x = i * i;
*                  baa(x);
*              }
*          }
* 
*          [My Answer]
*          △・int x already has been defined in Argument of Function 'foo',
*              the scope of 'x' is whole of 'foo' Block and same namespace.
*              nevertheless, x is defined else twice.
* 
*              => 〇 about top of the Block. 
*              => × 'for' statement is another inner Block of Function 'foo' Block,
*                 so twice definition is correct.
* 
*          ×・int i already has been defined in top of the Block,
*             the scope of whole of 'foo' Block.
*             But it is defined again in 'for' statement.
* 
*             => 'for' statement is another inner Block of Function 'foo' Block,
*                so twice definition is correct.

*          〇・Function 'baa(int)' is not defined here, 
*              and qualifier 'extern' is not existed, either.
* 
*          5. Explain what these bracket use for in C language:
*          ×(a) ( ) -> Argument of Function
* 
*              => [Book Answer] in addition above
*              ・Operator cast
*              ・Chamge the priority of Operator
*              ・The Conditional Experession of 'if', 'switch, 'for', 'while' statement.
*
*          △(b) { } -> ・Block of Function or Struct, 
*                     ・For gathering multi statements to one, recognized by Compiler.
*                     ・Initializer which initalize array elements or struct members.
*
*                => [Book Answer] in additional above
*                ・Block of 'enum'
* 
*          〇(c) [ ] -> Index or size of Array. 
*          〇(d) < > -> When '#include', it express Standard Header File, default-defined by specification of C language.
* 
*@see
*@author  shika
*@date    2023-01-19
*/

#include <stdio.h>

int main(void) {
//int mainPractice_CAnsiYH02(void) {
    //---- Practice 2 ----
    printf("The Character of Line Feed is expressed as \\n. \n"
        "Double Quote is expressed as \\\". \n");

    //---- Practice 3 ----
    printf("0123 (8) -> (10): %d \n", 0123);  // %o: 0123
    printf("0x255(16)-> (10): %d \n", 0x255); // %x: 255
    printf("-1L:        long  %d \n", -1L);
    printf("1.23e-4F:   float %f \n", 1.23e-4F);
    printf("\'\\0\':    FILE* %d \n", '\0');
    printf("\'0\':      char  %d \n", '0');   // %c: 0
    
    return 0;
}//main()

/*
//====== Result ======
//----- Practice 2 ----
The Character of Line Feed is expressed as \n.
Double Quote is expressed as \".

//----- Practice 3 ----
0123 (8) -> (10): 83
0x255(16)-> (10): 597
-1L:        long  -1
1.23e-4F:   float 0.000123
'\0':    FILE* 00000000
'0':      char   48

*/