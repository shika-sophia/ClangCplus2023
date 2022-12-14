/**
*@directory ClangC11Console / ClanC11Sample / C99YH / C99YH09_Array
*@fileName  MainTwoDimensionArraySample.c
*@reference C99YH  é _ wC¾êvO~ObX [üåÒ] æRÅxSB Creative, 2019
*@reference CAnsi  é _ wC¾êvO~ObX [¶@Ò] VÅx  SB Creative, 2006
*@reference C11DS  arton  wÆK C VÅxãÄjÐ, 2018
*
*@content C99YH æXÍ zñ | Chapter 9  Array / List 9-8 / p270
*@summary MainTwoDimensionArraySample.c
*
*@English [p] dimension:  ³
*         [p] square:     Q³
*         [p] individual: ÂlIÈ
*         [p] row:        s
*         [p] column:     ñ
* 
*@subject 2-Dimention Array
* 
*         [Format]
*         Definition (Intialization)
*         Type  (arrayName)[int row][int column];
*         Type  (arrayName)[int row][int column] = {
*             { column0, column1,,, },  // row 0
*             { column0, column1,,, },  // row 1
              { column0, column1,,, },  // row 2
*         };
*
*         Get element values
*         for(int i = 0; i < rowLength; i++){
*             for(int j = 0; j < columnLength; j++){
*                 value = array[i][j];
*             }//for j
*         }//for i
* 
*@see
*@author shika
*@date 2022-12-26
*/

#include <stdio.h>

#define SUBJECT_NUM 5
#define STUDENT_NUM 3

//int main(void) {
int mainTwoDimensionArraySample(void) {
    int examinPointAry[STUDENT_NUM][SUBJECT_NUM] = {
        { 64, 90, 75, 45, 80 },
        { 85, 100, 95, 82, 90 },
        { 100, 100, 100, 100, 99 },
    };
    int sumWhole = 0;
    double averageWhole = 0.0;

    for (int i = 0; i < STUDENT_NUM; i++) {
        int sumIndividual = 0;
        double averageIndividual = 0.0;

        for (int j = 0; j < SUBJECT_NUM; j++) {
            sumIndividual += examinPointAry[i][j];
            printf("%3d ", examinPointAry[i][j]);
        }//for j

        averageIndividual = (double)sumIndividual / SUBJECT_NUM;

        printf(" -> Sum: %3d | Average: %.2f \n", sumIndividual, averageIndividual);

        sumWhole += sumIndividual;
    }//for i

    averageWhole = (double)sumWhole / (SUBJECT_NUM * STUDENT_NUM);

    printf("Class Average: %.2f", averageWhole);
    return 0;
}//main()

/*
//====== Result ======
 64  90  75  45  80  -> Sum: 354 | Average: 70.80
 85 100  95  82  90  -> Sum: 452 | Average: 90.40
100 100 100 100  99  -> Sum: 499 | Average: 99.80
Class Average: 87.00

*/