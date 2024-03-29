/**
*@directory ClangC11Console / ClanC11Sample / C99YH / C99YH03_Valiable
*@fileName  MainNumericTypeRange.c
*@reference C99YH  結城 浩 『C言語プログラミングレッスン [入門編] 第３版』SB Creative, 2019
*@reference CAnsi  結城 浩 『C言語プログラミングレッスン [文法編] 新版』  SB Creative, 2006
*@reference C11DS  arton  『独習 C 新版』翔泳社, 2018
*
*@content C99YH 第２章 計算, 第３章 変数 / List 2-7, 7-7 / p49, p67, p206
*         This program shows the effective range of numeric Types.
* 
*@English [E] numeric:   (adj)  数値の
*         [E] range:     (n)    範囲
*         [M] precision: (n)    精度、桁数
*         [P] define     (v):      定義する
*         [P] declarate  (v):      宣言する
*         [P] transplantable (adj):  移植性がある  =:= portable  運びやすい

*@directory ClangC11Console / ClanC11Sample / C99YH / C99YH03_Valiable
*@fileName  MainNumericTypeRange.c
*@subject IEC 60559 (= International Electrotechnical Commission) 〔C99YH p49, p67〕
*         ＊char:         8 bit = 2 ^  8 = 256
*         ＊short:       16 bit = 2 ^ 16 = 65536
*         ＊int:         32 bit = 2 ^ 32 = 4294967296
*         ＊long long:   64 bit = 2 ^ 64 = 18446744073709551617
*         ＊float:       Single-Precision Floating-Point Number:   effective precision:  6 | value range: -3.4 * 10 ^ 38 〜 3.4 * 10 ^ 38
*         ＊double:      Double-Precision Floating-Point Number:   effective precision: 15 | value range: -1.7 * 10 ^ 308 〜 1.7 * 10 ^ 308
*         ＊long double: Extended-Precision Floating-Point Number: effective precision: 19 | value range: -1.1 * 10 ^ 4932 〜 1.1 * 10 ^ 4932
*
*@subject <limits.h> 〔CAnsi p39, p272〕〔C99YH 10 | p49, p206〕
          ・This is a Standard Header File default-defined by specification of C language.
          ・It define the maximum and minimum constant value of Primitive Types.
          ・Because they depend on Compiler, they are sometimes different.
          ★By using these constant values defined in it, a program is to be more transplantable.

          【Annotation】in this Compiler case:  (Compiler is Clang-C11 of Visual Studio 2019)
           It is no difference between 'int' and 'long'. (= the same range)

           => copy from 〔CAnsiYH03_Type\Reference_CAnsiType.txt〕

*         <limits.h>
*         #define
*           └ char:           CHAR_MIN, CHAR_MAX
*           └ short:          SHRT_MIN, SHRT_MAX
*           └ int:            INT_MIN, INT_MAX
*           └ long int:       LONG_MIN, LONG_MAX
*           └ long long int:  LLONG_MIN, LLONG_MAX,
*
*         ◆Range of Integer Type (in this Compiler [Clang-C11 of Visual Studio 2019])
*         ＊char  : -128 〜 127
*         ＊short : -32768 〜 32767
*         ＊int   : -2147483648 〜 2147483647
*         ＊long  : -2147483648 〜 2147483647
*         ＊llong : -9223372036854775808 〜 9223372036854775807
*
*@subject <stdint.h> 〔C11DS p76〕
*         It define the maximum and minimum constant values of Integer Types,
*         depending on Compiler.
*
*         [Example]
*         printf("%d", T value)
*           -> %d: int / %lld: long long / %f: float
*           -> %i: int / %lli: long long / %u: uint / %llu: unsiged long long
*
*         It shows -1, if value is beyond the Type range.
*         The minimum of unsigned Types is not defined, because its value is obviously 0.
*
*         <stdint.h>
*         #define
*           └ int8_t:   INT8_MIN, INT8_MAX
*           └ uint8_t:  UINT8_MAX
*           └ int16_t:  INT16_MIN, INT16_MAX
*           └ uint16_t: UINT16_MAX
*           └ int32_t:  INT32_MIN, INT32_MAX
*           └ uint32_t: UINT32_MAX
*           └ int64_t:  INT64_MIN, INT64_MAX
*           └ uint64_t: UINT64_MAX
*
*         ◆Range of Integer Types defined by <stdint.h>, in case of [Clang-C11 of Visual Studio 2019]
*         ＊int8_t  : -128 〜 127
*         ＊uint8_t : 0    〜 255
*         ＊int16_t : -32768 〜 32767
*         ＊uint16_t: 0      〜 65535
*         ＊int32_t : -2147483648 〜 2147483647
*         ＊uint32_t: 0           〜 4294967295
*         ＊int64_t : -9223372036854775808 〜  9223372036854775807
*         ＊uint64_t: 0                    〜 18446744073709551616
*
*@subject <float.h> 〔C99YH p68〕
*         It define the maximum and minimum constant values of Floating-Point Number Types,
*         depending on Compiler.
*
*        【Annotation】In this Compiler case: (Compiler is Clang-C11 of Visual Studio 2019)
*         It is no difference between 'double' and 'long double'. (= the same range)
*
*         <float.h>
*         #define
*           └ float:       FLT_MIN, FLT_MAX
*           └ double:      DBL_MIN, DBL_MAX
*           └ long double: LDBL_MIN, LDBL_MAX
*
*         ◆Value Range of Floating-Point Number Types (in this Compiler [Clang-C11 of Visual Studio 2019]
*         ＊float : 0.0000000000000000000000000000000000000118 〜 340282346638528859811704183484516925440.000000
*         ＊float :  1.17549435082228750797e-38 〜 3.40282346638528859812e+38
*         ＊double: 0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000223
*                  〜 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000
*         ＊double:  2.22507385850720138309e-308 〜 1.79769313486231570815e+308
*         ＊long double: 0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000223
*                  〜 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000
*         ＊long double:  2.22507385850720138309e-308 〜 1.79769313486231570815e+308
*
*@copyTo ReferenceDocument\ReferenceNumericTypeRange.txt
*@author shika
*@date 2022-12-10, 2023-01-20
*/

#include <stdio.h>
#include <limits.h>
#include <stdint.h>
#include <float.h>

//int main(void) {
int mainNumericTypeRange(void) {
    printf("◆Range of Integer Type (in this Compiler)\n");
    printf("＊char  : %d 〜 %d\n", CHAR_MIN, CHAR_MAX);
    printf("＊short : %d 〜 %d\n", SHRT_MIN, SHRT_MAX);
    printf("＊int   : %d 〜 %d\n", INT_MIN, INT_MAX);
    printf("＊long  : %li 〜 %li\n", LONG_MIN, LONG_MAX);
    printf("＊llong : %lli 〜 %lli\n", LLONG_MIN, LLONG_MAX);
    printf("\n");

    printf("◆Range of Unsigned Integer defined by <stdint.h>\n");
    printf("＊int8_t: %d 〜 %d\n", INT8_MIN, INT8_MAX);
    printf("＊uint8_t: %d 〜 %d\n", 0, UINT8_MAX);
    printf("＊int16_t: %d 〜 %d\n", INT16_MIN, INT16_MAX);
    printf("＊uint16_t: %d 〜 %d\n", 0, UINT16_MAX);
    printf("＊int32_t: %d 〜 %d\n", INT32_MIN, INT32_MAX);
    printf("＊uint32_t: %d 〜 %u\n", 0, UINT32_MAX);
    printf("＊int64_t: %lld 〜 %lld\n", INT64_MIN, INT64_MAX);
    printf("＊uint64_t: %d 〜 %llu\n", 0, UINT64_MAX);
    printf("\n");

    printf("◆Range of Float Double (in this Compiler)\n");
    printf("＊float : %.40f \n        〜 %f\n", FLT_MIN, FLT_MAX);
    printf("＊float : %.20e 〜 %.20e\n", FLT_MIN, FLT_MAX);
    printf("＊double: %.310f\n        〜 %f\n", DBL_MIN, DBL_MAX);
    printf("＊double: %.20e 〜 %.20e\n", DBL_MIN, DBL_MAX);
    printf("＊long double: %.310f\n              〜 %f\n", LDBL_MIN, LDBL_MAX);
    printf("＊long double: %.20e 〜 %.20e\n", LDBL_MIN, LDBL_MAX);

    return 0;
}//main()

/*
//====== Result ======
◆Range of Integer Type (in this Compiler)
＊char  : -128 〜 127
＊short : -32768 〜 32767
＊int   : -2147483648 〜 2147483647
＊long  : -2147483648 〜 2147483647
＊llong : -9223372036854775808 〜 9223372036854775807

◆Range of Unsigned Integer defined by <stdint.h> 
＊int8_t: -128 〜 127
＊uint8_t: 0 〜 255
＊int16_t: -32768 〜 32767
＊uint16_t: 0 〜 65535
＊int32_t: -2147483648 〜 2147483647
＊uint32_t: 0 〜 4294967295
＊int64_t: -9223372036854775808 〜 9223372036854775807
＊uint64_t: 0 〜 18446744073709551616

◆Range of Float Double (in this Compiler)
＊float : 0.0000000000000000000000000000000000000118 〜 340282346638528859811704183484516925440.000000
＊float :  1.17549435082228750797e-38 〜 3.40282346638528859812e+38
＊double: 0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000223
          〜 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000
＊double:  2.22507385850720138309e-308 〜 1.79769313486231570815e+308
＊long double: 0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000223
          〜 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000
＊long double:  2.22507385850720138309e-308 〜 1.79769313486231570815e+308


*/
