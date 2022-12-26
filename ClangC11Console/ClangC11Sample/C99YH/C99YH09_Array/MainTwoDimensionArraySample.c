/**
*@directory ClangC11Console / ClanC11Sample / C99YH / C99YH09_Array
*@fileName  MainTwoDimensionArraySample.c
*@reference C99YH  結城 浩 『C言語プログラミングレッスン [入門編] 第３版』SB Creative, 2019
*@reference CAnsi  結城 浩 『C言語プログラミングレッスン [文法編] 新版』  SB Creative, 2006
*@reference C11DS  arton  『独習 C 新版』翔泳社, 2018
*
*@content C99YH 第９章 配列 | Chapter 9  Array / List 9-8 / p270
*@summary MainTwoDimensionArraySample.c
*
*@English [英] dimension:  次元
*         [英] square:     ２次元
*         [英] individual: 個人的な
*         [英] row:        行
*         [英] column:     列
* 
*@subject 2-Dimention Array
* 
*         [Format]
*         ＊Definition (Intialization)
*         Type  (arrayName)[int row][int column];
*         Type  (arrayName)[int row][int column] = {
*             { column0, column1,,, },  // row 0
*             { column0, column1,,, },  // row 1
              { column0, column1,,, },  // row 2
*         };
*
*         ＊Get element values
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