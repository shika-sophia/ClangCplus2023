/**
*@directory ClangC11Console / ClanC11Sample / C99YH / C99YH03_Valiable
*@fileName  MainNumericTypeRange.c
*@reference C99YH  åãèÈ ç_ ÅwCåæåÍÉvÉçÉOÉâÉ~ÉìÉOÉåÉbÉXÉì [ì¸ñÂï“] ëÊÇRî≈ÅxSB Creative, 2019
*@reference CAnsi  åãèÈ ç_ ÅwCåæåÍÉvÉçÉOÉâÉ~ÉìÉOÉåÉbÉXÉì [ï∂ñ@ï“] êVî≈Åx  SB Creative, 2006
*@reference C11DS  arton  Åwì∆èK C êVî≈Åx„ƒâjé–, 2018
*
*@content C99YH ëÊÇQèÕ åvéZ, ëÊÇRèÕ ïœêî / List 2-7, 7-7 / p49, p67, p206
*         This program shows the effective range of numeric Types.
* 
*@English [E] numeric:   (adj)  êîílÇÃ
*         [E] range:     (n)    îÕàÕ
*         [M] precision: (n)    ê∏ìxÅAåÖêî
*         [P] define     (v):      íËã`Ç∑ÇÈ
*         [P] declarate  (v):      êÈåæÇ∑ÇÈ
*         [P] transplantable (adj):  à⁄êAê´Ç™Ç†ÇÈ  =:= portable  â^Ç—Ç‚Ç∑Ç¢

*@directory ClangC11Console / ClanC11Sample / C99YH / C99YH03_Valiable
*@fileName  MainNumericTypeRange.c
*@subject IEC 60559 (= International Electrotechnical Commission) ÅkC99YH p49, p67Ål
*         Åñchar:         8 bit = 2 ^  8 = 256
*         Åñshort:       16 bit = 2 ^ 16 = 65536
*         Åñint:         32 bit = 2 ^ 32 = 4294967296
*         Åñlong long:   64 bit = 2 ^ 64 = 18446744073709551617
*         Åñfloat:       Single-Precision Floating-Point Number:   effective precision:  6 | value range: -3.4 * 10 ^ 38 Å` 3.4 * 10 ^ 38
*         Åñdouble:      Double-Precision Floating-Point Number:   effective precision: 15 | value range: -1.7 * 10 ^ 308 Å` 1.7 * 10 ^ 308
*         Åñlong double: Extended-Precision Floating-Point Number: effective precision: 19 | value range: -1.1 * 10 ^ 4932 Å` 1.1 * 10 ^ 4932
*
*@subject <limits.h> ÅkCAnsi p39, p272ÅlÅkC99YH 10 | p49, p206Ål
          ÅEThis is a Standard Header File default-defined by specification of C language.
          ÅEIt define the maximum and minimum constant value of Primitive Types.
          ÅEBecause they depend on Compiler, they are sometimes different.
          ÅöBy using these constant values defined in it, a program is to be more transplantable.

          ÅyNotationÅzin this Compiler case:  (Compiler is Clang-C11 of Visual Studio 2019)
           It is no difference between 'int' and 'long'. (= the same range)

           => copy from ÅkCAnsiYH03_Type\Reference_Type.txtÅl

*         <limits.h>
*         #define
*           Ñ§ char:           CHAR_MIN, CHAR_MAX
*           Ñ§ short:          SHRT_MIN, SHRT_MAX
*           Ñ§ int:            INT_MIN, INT_MAX
*           Ñ§ long int:       LONG_MIN, LONG_MAX
*           Ñ§ long long int:  LLONG_MIN, LLONG_MAX,
*
*         ÅüRange of Integer Type (in this Compiler [Clang-C11 of Visual Studio 2019])
*         Åñchar  : -128 Å` 127
*         Åñshort : -32768 Å` 32767
*         Åñint   : -2147483648 Å` 2147483647
*         Åñlong  : -2147483648 Å` 2147483647
*         Åñllong : -9223372036854775808 Å` 9223372036854775807
*
*@subject <stdint.h> ÅkC11DS p76Ål
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
*           Ñ§ int8_t:   INT8_MIN, INT8_MAX
*           Ñ§ uint8_t:  UINT8_MAX
*           Ñ§ int16_t:  INT16_MIN, INT16_MAX
*           Ñ§ uint16_t: UINT16_MAX
*           Ñ§ int32_t:  INT32_MIN, INT32_MAX
*           Ñ§ uint32_t: UINT32_MAX
*           Ñ§ int64_t:  INT64_MIN, INT64_MAX
*           Ñ§ uint64_t: UINT64_MAX
*
*         ÅüRange of Integer Types defined by <stdint.h>, in case of [Clang-C11 of Visual Studio 2019]
*         Åñint8_t  : -128 Å` 127
*         Åñuint8_t : 0    Å` 255
*         Åñint16_t : -32768 Å` 32767
*         Åñuint16_t: 0      Å` 65535
*         Åñint32_t : -2147483648 Å` 2147483647
*         Åñuint32_t: 0           Å` 4294967295
*         Åñint64_t : -9223372036854775808 Å`  9223372036854775807
*         Åñuint64_t: 0                    Å` 18446744073709551616
*
*@subject <float.h> ÅkC99YH p68Ål
*         It define the maximum and minimum constant values of Floating-Point Number Types,
*         depending on Compiler.
*
*        ÅyNotationÅzIn this Compiler case: (Compiler is Clang-C11 of Visual Studio 2019)
*         It is no difference between 'double' and 'long double'. (= the same range)
*
*         <float.h>
*         #define
*           Ñ§ float:       FLT_MIN, FLT_MAX
*           Ñ§ double:      DBL_MIN, DBL_MAX
*           Ñ§ long double: LDBL_MIN, LDBL_MAX
*
*         ÅüValue Range of Floating-Point Number Types (in this Compiler [Clang-C11 of Visual Studio 2019]
*         Åñfloat : 0.0000000000000000000000000000000000000118 Å` 340282346638528859811704183484516925440.000000
*         Åñfloat :  1.17549435082228750797e-38 Å` 3.40282346638528859812e+38
*         Åñdouble: 0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000223
*                  Å` 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000
*         Åñdouble:  2.22507385850720138309e-308 Å` 1.79769313486231570815e+308
*         Åñlong double: 0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000223
*                  Å` 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000
*         Åñlong double:  2.22507385850720138309e-308 Å` 1.79769313486231570815e+308
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
    printf("ÅüRange of Integer Type (in this Compiler)\n");
    printf("Åñchar  : %d Å` %d\n", CHAR_MIN, CHAR_MAX);
    printf("Åñshort : %d Å` %d\n", SHRT_MIN, SHRT_MAX);
    printf("Åñint   : %d Å` %d\n", INT_MIN, INT_MAX);
    printf("Åñlong  : %li Å` %li\n", LONG_MIN, LONG_MAX);
    printf("Åñllong : %lli Å` %lli\n", LLONG_MIN, LLONG_MAX);
    printf("\n");

    printf("ÅüRange of Unsigned Integer defined by <stdint.h>\n");
    printf("Åñint8_t: %d Å` %d\n", INT8_MIN, INT8_MAX);
    printf("Åñuint8_t: %d Å` %d\n", 0, UINT8_MAX);
    printf("Åñint16_t: %d Å` %d\n", INT16_MIN, INT16_MAX);
    printf("Åñuint16_t: %d Å` %d\n", 0, UINT16_MAX);
    printf("Åñint32_t: %d Å` %d\n", INT32_MIN, INT32_MAX);
    printf("Åñuint32_t: %d Å` %u\n", 0, UINT32_MAX);
    printf("Åñint64_t: %lld Å` %lld\n", INT64_MIN, INT64_MAX);
    printf("Åñuint64_t: %d Å` %llu\n", 0, UINT64_MAX);
    printf("\n");

    printf("ÅüRange of Float Double (in this Compiler)\n");
    printf("Åñfloat : %.40f \n        Å` %f\n", FLT_MIN, FLT_MAX);
    printf("Åñfloat : %.20e Å` %.20e\n", FLT_MIN, FLT_MAX);
    printf("Åñdouble: %.310f\n        Å` %f\n", DBL_MIN, DBL_MAX);
    printf("Åñdouble: %.20e Å` %.20e\n", DBL_MIN, DBL_MAX);
    printf("Åñlong double: %.310f\n              Å` %f\n", LDBL_MIN, LDBL_MAX);
    printf("Åñlong double: %.20e Å` %.20e\n", LDBL_MIN, LDBL_MAX);

    return 0;
}//main()

/*
//====== Result ======
ÅüRange of Integer Type (in this Compiler)
Åñchar  : -128 Å` 127
Åñshort : -32768 Å` 32767
Åñint   : -2147483648 Å` 2147483647
Åñlong  : -2147483648 Å` 2147483647
Åñllong : -9223372036854775808 Å` 9223372036854775807

ÅüRange of Unsigned Integer defined by <stdint.h> 
Åñint8_t: -128 Å` 127
Åñuint8_t: 0 Å` 255
Åñint16_t: -32768 Å` 32767
Åñuint16_t: 0 Å` 65535
Åñint32_t: -2147483648 Å` 2147483647
Åñuint32_t: 0 Å` 4294967295
Åñint64_t: -9223372036854775808 Å` 9223372036854775807
Åñuint64_t: 0 Å` 18446744073709551616

ÅüRange of Float Double (in this Compiler)
Åñfloat : 0.0000000000000000000000000000000000000118 Å` 340282346638528859811704183484516925440.000000
Åñfloat :  1.17549435082228750797e-38 Å` 3.40282346638528859812e+38
Åñdouble: 0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000223
          Å` 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000
Åñdouble:  2.22507385850720138309e-308 Å` 1.79769313486231570815e+308
Åñlong double: 0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000223
          Å` 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000
Åñlong double:  2.22507385850720138309e-308 Å` 1.79769313486231570815e+308


*/
