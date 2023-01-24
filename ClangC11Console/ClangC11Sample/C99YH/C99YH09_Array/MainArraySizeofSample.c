/**
*@directory ClangC11Console / ClanC11Sample / C99YH / C99YH09_Array
*@fileName  MainArraySizeofSample.c
*@reference C99YH  åãèÈ ç_ ÅwCåæåÍÉvÉçÉOÉâÉ~ÉìÉOÉåÉbÉXÉì [ì¸ñÂï“] ëÊÇRî≈ÅxSB Creative, 2019
*@reference CAnsi  åãèÈ ç_ ÅwCåæåÍÉvÉçÉOÉâÉ~ÉìÉOÉåÉbÉXÉì [ï∂ñ@ï“] êVî≈Åx  SB Creative, 2006
*@reference C11DS  arton  Åwì∆èK C êVî≈Åx„ƒâjé–, 2018
*
*@content C99YH ëÊÇXèÕ îzóÒ | Chapter 9  Array / List 9-7 / p267
*@summary MainArraySizeofSample
*         ÅüArray Definition
*         (1) Array Definition
*         (2) Array Definition with Initialize
* 
*         ÅüOperator 'sizeof()'
* 
*@English [P] operator  (n):      ââéZéq
*         [P] initializer (n):    èâä˙âªéq { }
*         [P] Wide-Character (n): ëSäpï∂éö

*@subject Åü Array Definition Åkp267Ål
*         (1) [Array Definition]
*             The definition of Array is required the argument of array length with bracket '[]'.
*         
*         (2) [Array Definition with Initialize]
*             Array can be defined with initial elements of the same Type, when it is defined with using initializer '{ }' only.
*             In this case, the array length is automatically caluculated from the number of elements,
*             so that '[]' can be empty still.
* 
*         ÅEÅyDetail NotationÅz
*            We need put ';' after '{ ... }'.
*            We need delimit elemants by ',' -- if elements are multiple.
* 
*         [Format] Array Defininition
*         (1) Type arrayName[int arrayLength]; 
*         (2) Type arrayName[] = { ... }; 
* 
*         [Example]
*         char name[NAME_MAX];               // asumming 'NAME_MAX' is defined as 'int' Type before there.
*         int  pointAry[] = { 65, 90, 72, }; // Initialze case
*
*@subject ÅüOperator 'sizeof()' ÅkC99YH p267Ål
*         int  sizeof( Type )    // It returns 'int' value of how bytes the argument Type have 
* 
*         ÅEArray length:  calculated from '(whole array bytes) / (one element bytes)' as below [Example]
* 
*         ÅEÅyNotationÅzin the case of including Wide-Character such as Japanese:
*            The size of one element can be variable.
*            Therefore, Array Length cannot be calculated correctly by above expression.
* 
*         [Example]
*         int length = sizeof(pointAry) / sizeof(pointAry[0]);
* 
*         => copy to ÅkCAnsiYH03_Type\MainOperatorSizeofSample.cÅl
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