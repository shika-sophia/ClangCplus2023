/**
*@directory ClangC11Console / ClanC11Sample / C99YH / C99YH09_Array
*@fileName  PracticeC99YH09.c
*@reference C99YH  åãèÈ ç_ ÅwCåæåÍÉvÉçÉOÉâÉ~ÉìÉOÉåÉbÉXÉì [ì¸ñÂï“] ëÊÇRî≈ÅxSB Creative, 2019
*@reference CAnsi  åãèÈ ç_ ÅwCåæåÍÉvÉçÉOÉâÉ~ÉìÉOÉåÉbÉXÉì [ï∂ñ@ï“] êVî≈Åx  SB Creative, 2006
*@reference C11DS  arton  Åwì∆èK C êVî≈Åx„ƒâjé–, 2018
*
*@content C99YH ëÊÇXèÕ îzóÒ ó˚èKñ‚ëË| Chapter 9  Array Practice / List - / p281
*@English [êî] arithmetic progression:  ìôç∑êîóÒ
*
*@subject Practice 9-1  True or False about [Example] below.
*         [Example] 
*         When an Array is defined 'int a[100];',
*         you can use 100 elements in range a[1] - a[100].
* 
*         [My Answer] False.
*         It is true that the Array has 100 elements. 
*         It can use range of a[0] - a[99].
*
*         => Correct
* 
*@subject Practice 9-2  What will the [Example] program show? 
*         [Example]
*         int main(void) {
*             int a[10];
*             for (int i = 0; i < 10; i++) {
*                 a[i] = i * i;
*             }//for
* 
*             printf("%d\n", a[5]);
*             return 0;
*          }//main()
* 
*          [My Answer] 36.  
*          index:  0, 1, 2, 3,  4,  5, ...
*          value:  0, 1, 4, 9, 25, 36, ...
* 
*          => Wrong
* 
*          [Book Answer] 25.    Å´ lack of 16
*          index:  0, 1, 2, 3,  4,  5,  6, ...
*          value:  0, 1, 4, 9, 16, 25, 36, ...
* 
*@subject Practice 9-3  What will the [Example] program show? 
*         [Example]
*         int main(void) {
*             int a[10];
*             for (int i = 0; i < 10; i++) {
*                 if (i == 0) {
*                     a[i] = 0;
*                 } else {
*                     a[i] = a[i - 1] + i;
*                 } 
*             }//for
* 
*             printf("%d\n", a[5]);
*             return 0;
*          }//main()
* 
*          [My Answer] 15, because it shows (previous value) + (this index).
*          index:  0, 1, 2, 3,  4,  5, ...
*          value:  0, 1, 3, 6, 10, 15, ...
* 
*          => Correct
* 
*          [Book Anawer] a[i] value is Summary of [ 0 -> i ].
* 
*@subject Practice 9-4  
*         Modify wrong point of the program [Example] below.
*         Someone want to make an Array which has element values is Summary of [0 -> index].
*         he or she wrote the program [Example], but it showed unexpected values, Failure.
* 
*         [Example]
*         int main(void) {
*             int a[10];
*             for (int i = 0; i <= 10; i++) {
*                 a[i] = a[i - 1] + i;
*             }//for
*
*             for (int i = 0; i <= 10; i++) {
*                 printf("%d\n", a[i]);
*             }//for
* 
*             return 0;
*          }//main()
* 
*          [My Answer] below
*          [Å~] i <= 10  -> ÅZ i < 10
*          [Å~] when index is 0, the expression 'a[i] = a[i - 1] + i;' has minus index,
*              -> ÅZ It should be added 'if(i == 0) { a[0] = 0; }'.
*          
*          If still before, these will be thrown 'ArrayOutOfRangeException' in [Java, C#].
* 
*          => Correct
* 
*          [Book Answer] Another Solution
*          [Formula] Summary of Arithmetic Progression | ìôç∑êîóÒÇÃòa
*          S = É∞ [k = 0 -> n] n * (n + 1) / 2 
*              
*          [Example] in this case
*          for (int i = 0; i < 10; i++) {
*              a[i] = i * (i + 1) / 2;
*          }
* 
*@subject Practice 9-5  Max Value
          Complete the program that it seek max value in array data.
*         [My Answer] below
* 
*         => Correct
*         
*@subject Practice 9-6  Sort as ascending
*         Complete the program that it sort as ascending of array data.
*         [My Answer] below
* 
*         => Correct
* 
*@see
*@author shika
*@date 2022-12-27
*/

#include <stdio.h>

//int main(void) {
int mainPracticeC99YH09(void) {
    //---- Practice 9-4 ----
    int a[10];
    for (int i = 0; i < 10; i++) {
        if (i == 0) {
            a[0] = 0;
        }
        else {
            a[i] = a[i - 1] + i;
        }
    }//for
    
    for (int i = 0; i < 10; i++) {
        printf("%d\n", a[i]);        
    }//for
    printf("\n");
    
    //---- Practice 9-5 Max Value ----
    int dataAry[] = { 31, 41, 59, 26, 53, 58, 97, 93, 23, 84, };
    int dataLength = (int)(sizeof(dataAry) / sizeof(dataAry[0]));
    int max = dataAry[0];

    printf("dataAry:   ");
    for (int i = 0; i < dataLength; i++) {
        printf("%d, ", dataAry[i]);

        if (max < dataAry[i]) {
            max = dataAry[i];
        }
    }//for
    printf("\n");

    printf("max value: %d \n", max);
    printf("\n");

    //---- List 9-6 Sort as ascending ----
    for (int i = 0; i < dataLength - 1; i++) {
        for (int j = i + 1; j < dataLength; j++) {
            if (dataAry[j] < dataAry[i]) {
                int temp = dataAry[j];
                dataAry[j] = dataAry[i];
                dataAry[i] = temp;
            }//for j
        }//for j
    }//for i

    printf("dataAry (Ascending): ");
    for (int i = 0; i < dataLength; i++) {
        printf("%d, ", dataAry[i]);
    }//for
    printf("\n");
    return 0;
}//main()

/*
//====== Result ======
//---- List 9-4 ----
0
1
3
6
10
15
21
28
36
45

//---- List 9-5 ----
dataAry:   31, 41, 59, 26, 53, 58, 97, 93, 23, 84,
max value: 97

//---- List 9-6 ----
dataAry (Ascending): 23, 26, 31, 41, 53, 58, 59, 84, 93, 97,

*/