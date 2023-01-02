/**
*@directory ClangC11Console / ClanC11Sample / C99YH / C99YH09_Array
*@fileName  MainCalculateStatsFromFileViewer.c
*@reference C99YH  åãèÈ ç_ ÅwCåæåÍÉvÉçÉOÉâÉ~ÉìÉOÉåÉbÉXÉì [ì¸ñÂï“] ëÊÇRî≈ÅxSB Creative, 2019
*@reference CAnsi  åãèÈ ç_ ÅwCåæåÍÉvÉçÉOÉâÉ~ÉìÉOÉåÉbÉXÉì [ï∂ñ@ï“] êVî≈Åx  SB Creative, 2006
*@reference C11DS  arton  Åwì∆èK C êVî≈Åx„ƒâjé–, 2018
*
*@content C99YH ëÊÇXèÕ îzóÒ | Chapter 9  Array / List 9-11 / p272
*@summary MainCalculateStatsFromFileViewer.c
*         This Program load from a stats file by standard input,
*         and caluculate summary, average and seek maximum, minimum, medium values,
*         and show these values.
* 
*         [Prepare] 
*         Deploy a stats file '09stats-input.txt' in same directory.
*         The file can be copied from Sample Program of the Book Appendix, downloadable from web page of Publisher.
* 
*         [Execute] Windows Command Prompt
*         > cd (current directory)
*         > cl MainCalculateStatsFromFileViewer.c
*         > MainCalculateStatsFromFileViewer < 09stats-input.txt
* 
*@English [âp] stats:      ìùåv
*         [âp] calculate:  åvéZÇ∑ÇÈ
*         [âp] sort:       ï¿Ç◊ë÷Ç¶ÇÈ
*         [âp] ascending:  è∏èá  <-> descending ç~èá
*         [âp] algorithm:  ÉAÉãÉSÉäÉYÉÄ, évçléËèá
*
*@subject <stdio.h> 
*            Ñ§ #define stdin
*            Ñ§ fgets(char* buffer, int maxCount, FILE *_Stream)
* 
*@subject <stdlib.h>
*            Ñ§ void  exit(int _Code)   //to terminate the execution of a program
*                Ñ§ [Argument] 0:  correctly terminate
*                             1:  uncorrectly terminate
*                            -1: Åishould not)
* 
*              => ÅkReferenceDocument\Article_exitFunction.txtÅl
* 
*@subject Algorithm to seek Maximum value in array
*@subject Algorithm to seek Minimum value in array
*         ÅEAt first, initialize max, min.
*         ÅEget value of whole elements by 'for' sentence
*         ÅEcheck higher or lower than max, min.
*         ÅEIf higher, set max the value. If lower, set min the value.
* 
*         [Example]
*         if (dataSize > 0) {
*            max = dataAry[0];
*            min = dataAry[0];
*         }
*
*         for (int i = 0; i < dataSize; i++) {
*            if (max < dataAry[i]) {
*               max = dataAry[i];
*            }
*
* 
*            if (dataAry[i] < min) {
*               min = dataAry[i];
*            }
*         }//for
*
*@subject Algorithm to exchange values each other
*         Values in two variable cannot exchange directly.
*         because when substitute one to the other, the other value is absolutely deleted by the substitution.
*         [Å~][Example] When a == 2, b == 3  ->  Substitute a = b (as same a = 3) & b = a (b = a == 3 ['a' has already substituted 3])  ->  a == 3, b == 3  [Å~] not exchange 
* 
*         Therefore, when exchange values each other, prepare a temporary variable as same type.
*         At first, one value substitute to the temporary variable, 
*         and the other value do to the former (= one) variable,
*         and then temp value do to the later (= the other) variable, as [Example] below.
* 
*         [Example]
*         int temp = a;
*         a = b;
*         b = temp;
* 
*         =>ÅkC99YH11_Pointer\MainExchangeValueEachOther.cÅl
* 
*@subject Algorithm to sort array values as ascending
*         ÅEmedium value: central value of the array
* 
*         ÅEAt first, sort array values as ascending.
*         ÅEGet value of index 'i' and next value of index 'j'.
*           ('for i' iteration continues until 'dataSize - 1' so that 'for i' is not over index range.)          
*         
*         ÅEComparing dataAry[i] and dataAry[j], if [i] is higher than [j],
*           exchange the values (= exchange the indexes), using Algorithm to exchange ÅkaboveÅl.
* 
*         ÅETo continue to check that whole elements, the sort as ascending is completed.
*         ÅEAnd then, get the medium value at 'dataSize / 2'.
*           Array index is required 'int' type, 
*           and the divide calculation is done by both int types, so it returns int type.
*           (Therefore, actually it is not necessary to change type cast '(int)'.)
*           (But because I wanted to express that the value is obviously 'int' type, I added '(int)'.)
* 
*         [Example]
*         for (int i = 0; i < dataSize - 1; i++) {
*            for (int j = i + 1; j < dataSize; j++) {
*                if (dataAry[i] > dataAry[j]) {
*                    double temp = dataAry[i];       <- Algorithem to exchange ÅkaboveÅl
*                    dataAry[i] = dataAry[j];
*                    dataAry[j] = temp;
*                }
*            }//for j
*         }//for i
*
*         medium = dataAry[(int)(dataSize / 2)];
* 
*@see
*@author shika
*@date 2022-12-26
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//====== Define Directive ======
#define BUFFER_SIZE 256
#define MAX_DATA 500

//====== Global Variables ======
double dataAry[MAX_DATA];
int dataSize = 0;
double sum;
double average;
double max;
double min;
double medium;

//====== Prototype Declarations ======
//int main(void);
int mainCalculateStatsFromFileViewer(void);
void inputData(void);
void calcData(void);
void outputData(void);

//====== Function Definitions ======
//int main(void) {
int mainCalculateStatsFromFileViewer(void) {
    inputData();
    calcData();
    outputData();
    return 0;
}//main()

void inputData(void) {
    char buffer[BUFFER_SIZE];

    while (fgets(buffer, BUFFER_SIZE, stdin) != NULL) {
        if (dataSize >= MAX_DATA) {
            printf("<ÅI> Beyond the capacity of operatable range [ %d ].", MAX_DATA);
            exit(-1);
        }

        if (isdigit(buffer[0]) || buffer[0] == '.') {  //case numeric: chage type to 'double' and set dataAry
            dataAry[dataSize] = (double)atof(buffer);
            dataSize++;
        }
        else {                                         //case not numeric: show as char* type and don't set dataAry
            printf("%s", buffer);
        }
    }//while
}//inputData()

void calcData(void) {
    //---- calculate sum ----
    sum = 0.0;

    for (int i = 0; i < dataSize; i++) {
        sum += dataAry[i];
    }//for

    //---- calculate average ----
    average = (double)sum / dataSize;

    //---- seek max, min ----
    if (dataSize > 0) {
        max = dataAry[0];
        min = dataAry[0];
    }

    for (int i = 0; i < dataSize; i++) {
        if (max < dataAry[i]) {
            max = dataAry[i];
        }

        if (dataAry[i] < min) {
            min = dataAry[i];
        }
    }//for

    //---- sort array values as ascending and seek medium ----
    for (int i = 0; i < dataSize - 1; i++) {
        for (int j = i + 1; j < dataSize; j++) {
            if (dataAry[i] > dataAry[j]) {
                double temp = dataAry[i];
                dataAry[i] = dataAry[j];
                dataAry[j] = temp;
            }
        }//for j
    }//for i

    medium = dataAry[(int)(dataSize / 2)];
}//calcData()

void outputData(void) {
    printf("Data Size: %d \n", dataSize);
    printf("Summary:   %0.1f \n", sum);
    printf("Average:   %0.1f \n", average);
    printf("Maximum:   %0.1f \n", max);
    printf("Minimum:   %0.1f \n", min);
    printf("Medium:    %0.1f \n", medium);
}//outputData()

/*
//###### Appendix ######
//====== 09stats-input.txt =====
3.1
4.15
92.6
5.35
89.79
3.23
84.3
26.4
33.3
83.2
79.0
[EOF]

//====== Windows Command Prompt Execution ======
>cd C:\...\ClangC11Console\ClangC11Sample\C99YH\C99YH09_Array

>cl MainCalculateStatsFromFileViewer.c
/out:MainCalculateStatsFromFileViewer.exe
MainCalculateStatsFromFileViewer.obj

>MainCalculateStatsFromFileViewer < 09stats-input.txt

//====== Result ======
Data Size: 11
Summary:   504.4
Average:   45.9
Maximum:   92.6
Minimum:   3.1
Midium:    33.3
*/