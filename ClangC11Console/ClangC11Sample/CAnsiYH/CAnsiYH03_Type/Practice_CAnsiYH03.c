/**
*@directory ClangC11Console / ClanC11Sample / CAnsiYH / CAnsiYH03_Type
*@fileName  Practice_CAnsiYH03.c
*@reference C99YH    åãèÈ ç_ ÅwCåæåÍÉvÉçÉOÉâÉ~ÉìÉOÉåÉbÉXÉì [ì¸ñÂï“] ëÊÇRî≈ÅxSB Creative, 2019
*@reference CAnsiYH  åãèÈ ç_ ÅwCåæåÍÉvÉçÉOÉâÉ~ÉìÉOÉåÉbÉXÉì [ï∂ñ@ï“] êVî≈Åx  SB Creative, 2006
*@reference C11DS    arton  Åwì∆èK C êVî≈Åx„ƒâjé–, 2018
*
*@content CAnsiYH Chapter 3  Type | Practice / List - / p66
*@summary
*@English [E] countermeasure (n): ëŒçÙ, ëŒçRéËíi, ëŒçRë[íu, ëŒçRçÙ
*         [E] prescription   (n): èàï˚‚≥
*         [E] solution       (n): âåàçÙ, [M] â  =:= resolution (n) âÒïúçÙ
*         [E] coincidently (adv): ãÙëRàÍívÇ∑ÇÈ
* 
*@subject Practice 1
*         Why do that the program below shows '-28672' executed by a Compiler ?
*         [Example]
*         long len = 100 * 1024;
*         printf("len: %ld \n", len);
* 
*         [My Answer]
*         Because the solution of the caluclation '100 * 1024', is returned as int value,
*         the value happen to be Overflow beyond int-range, and it change higest bit from 0 to 1: minus value. 
*         Even if the solution is assigned to long long Type, the value is as same as above.
*         
*         To solve this unexpected-value,
*         It should add the Suffix of experssing 'long' Literal, such as '100L'.
* 
*         => Correct
* 
*         [Book Answer]
*         Assuming that int-range is 2e4 = 16 bits in one Compiler,
*         100 * 1024 = 102400 (as 10-decimal) = 19000 (as 16-decimal)
*         the 19000(16) cannot be expressed by 16 bits, within 4 digits of 16-decimal,
*         so that the value is converted to 9000(16) within 4 digits of 16-decimal,
*         the convertion is called "Overflow".
* 
*         9000(16) = 1001 0000 0000 0000(2) 
*         The highest bit of Binary is 1, that means minus value.
* 
*@subject Practice 2
*         Is it correct to solve the problem ?
*         
*         [Example]
*         Assuming that:
*           int n;
*           struct SchoolMate mateP*;
* 
*         Then one write the assignment expression.
*           mateP = &n;
* 
*         It is thrown Compile Error.
*         To solve the problem, one prove that:
*           mateP = (struct SchoolMate*) &n;
* 
*         Then Compile go through, well.
* 
*         Is it correct to solve the problem ?
* 
*         [My Answer]
*         No, it is not correct, because Pointer 'mateP' is defined to storage address of struct,
*         the assignment 'mateP = &n;' is absolutely non-sense.
* 
*        ÅyConsiderationÅz
*         In [Java][C#], this Cast is thrown Compile Error such as InvalidCastException,
*         but in [C], Cast of different Types may be allowed.
* 
*         => Correct some degree.
* 
*         [Book Answer]
*         By this assignment 'mateP = (struct SchoolMate*) &n;',
*         Pointer 'mateP' is changed to indicate address of int-value,
*         so that Pointer 'mateP' does not indicate address of 'struct',
*         so that expression 'mateP->xxxx' cannot refer to member of struct.
* 
*         In this case, if we assign some value by using 'mateP->xxxx' expression,
*         that change value in different address, where is not address of 'stuct' in Memory.
*         (If there is only one int-member in sturct, that is not happened coincidently)
* 
*@subject Practice 3
*         Explain the differnce of bracket '()' below.
* 
*         [Example]
*         if ((p = (int*)malloc((m + n) * 10)) != NULL) {  }
*         
*         [My Answer]
*         if (xxx != NULL): conditional expression of if-statement
*         (p = ):           the priority of assignment is made superior than judge of conditional expression
*         (int*):           Cast Type-Change: int -> int*
*         malloc():         Argument of Function
*         (m + n):          the superior priority of caluclaton
*         
*         => Correct
* 
*@subject Practice 4
*         Assuming these definitions (1) - (9), which are the expessions in (a) - (i) thrown Compile Error ?
*         
*         [Definitions]
*         (1) int i = 123;
*         (2) const ci = 123;
*         (3) int const ic = 123;
*         (4) int *iP = &i;
*         (5) const int *ciP = &i;
*         (6) int const *icP = &i;
*         (7) int* const iPc = &i;
*         (8) const int* const ciPc = &i;
*         (9) int const *const icPc = &i;
*         
*         [Expessions]      // [My Answer] => [Book Answer]
*         (a) i = 256;      // ÅZ
*         (b) ci = 256;     // Å~: Compile Error, because 'ci' is defined as 'const' in (2).
*         (c) ic = 123;     // Å~: as same as previous in (3).
*         (d) *ciP = 789;   // Å~: Compile Error, because Pointer 'ciP' which indicate 'const int', as defined in (5).
*         (e) icP = 0;      // ÅZ: because the assignment is done to Pointer value, it can be done.
*                              => if '*icP = 0', Compile Error.
*         (f) iPc++;        // Å~: Compile Error, because the modification is done to 'const' Pointer value 'iPc', as defined in (7).
*                              => if '(*iPc)++;' OK.
*         (g) *iPc = 0;     // ÅZ: because the assignment is done to int-value which Pointer indicate, as defined in (7).
*         (h) *ciPc = 0;    // Å~: (h)(i) cannot be modified and assigned to Pointer value nor the value which Pointer indicate, neither.         
*         (i) icPc++;       // Å~: as previous.
* 
*         => Correct
*@see
*@author  shika
*@date    2023-01-28
*/

#include <stdio.h>

int main(void) {
//int mainPractice_CAnsiYH03(void) {
    //---- Practice 1 ----
    long long len = 100 * 1024;
    printf("len: %lld \n", len);
    
    long long len2 = 100LL * 1024LL;
    printf("len2: %lld \n", len2);
    return 0;
}//main()

/*
//---- Result ----
len:  102400
len2: 102400

ÅyConsiderationÅz
 Because the '102400' is within int-range in this Compiler [Clang-C11 of Visual Studio 2019]: 
 2e+8 = 32 bits = -2147483648 Å` 2147483647,
 it shows correctly without happening to be Overflow.

*/