/**
*@directory ClangC11Console / ClanC11Sample / CAnsiYH / CAnsiYH05_Array
*@fileName  Practice_CAnsiYH05.c
*@reference C99YH    結城 浩 『C言語プログラミングレッスン [入門編] 第３版』SB Creative, 2019
*@reference CAnsiYH  結城 浩 『C言語プログラミングレッスン [文法編] 新版』  SB Creative, 2006
*@reference C11DS    arton  『独習 C 新版』翔泳社, 2018
*
*@content CAnsiYH Chapter 5  Array | Practice / p99-103
*@summary Practice_CAnsiYH05.c
*@English
*@subject Practice 1: Sort Ascending
*         Define Function 'void sort_data(void)' which sort the elements of Array 'int data[MAX_DATA]' as ascending,
*         asumming that '#define MAX_DATA' has already defined, and that the elements are different each other.
*
*         [My Answer] -> code below
*         => Correct
* 
*@subject Practice 2: Even, odd Number
*         Define Function 'void count_data(int *evenp, int *oddp, int *zerop)'
*         which count each numbers 'even, odd, zero' of Array 'data[]' as same as above,
*         however return them to each Pointer '*evenp *oddp, *zerop'.
* 
*         [My Answer] -> code below
*         => almost Correct
*            The '*evenp *oddp, *zerop' should be initialized in this Function,
*            as [Book Answer].
* 
*         => Modified.
* 
*@subject Practice 3: Reverse
*         Define Function 'void pAry_reverse(void)' 
*         which reverse the order of characters in Array 'char *pAry[PA_SIZE]',
*         assuming that '#define PA_SIZE' has already defined.
* 
*         [My Answer] -> Appendix below
*         => Give up
* 
*         => [Book Answer] 
*         The Function is written the original as [Book Answer],
*         but I may mistake the definition of 'char *pAry[PA_SIZE]' in main(), such as:
*            char *pAryCAnsiYH05[PA_SIZE] = { 'S', 'o', 'p', 'h', 'i', 'a', '\0' };
*         Result is Runtime Exception, such as:
*            warning C4047: in initialization: indirect levels are different, 'char *' and 'int'.
* 
*         => Give up and Comment out
* 
*@subject Practice 4: Matrix and Array
*         2-Dimension Array can be regarded as Matrix in Mathematics.
*         so that element of Array a[i][j] is assumed as aij of 2 * 2 Matrix, such as:
*            ┌　        ┐
*            | a00  a01 |
*            | a10  a11 |
*            └          ┘
* 
*         Define Function 'void multipleMatrix(int a[2][2], int b[2][2], int c[2][2])'
*         which caluculate multiple of two 2 * 2 Matrixes and the result is assigned to 'c[2][2]'.
*
*         [Hint] multiple of Matrixes as Mathematics Definition, such as:
*            ┌　    ┐   ┌      ┐    ┌                  ┐
*            | a  b |   | e  f |    | ae + bg  af + bh |
*            | c  d | * | g  h | =  | ce + dg  cf + dh |
*            └      ┘   └      ┘    └                  ┘
* 
*         [My Answer] -> code below
* 
*         => Correct, 
*            though [My answer] is the opposite Axis row and column of [Book Answer].
*      
*@subject Practice 5: Matrix General
*         Define Function as same as the previous, however for 5 * 5 Matrix.
* 
*         [My Answer] -> Apendix below -> Give up
* 
*         => [Book Answer] -> code below
*         It use for-statement i, j, k as triple nested !
*            
*         It is an Example that:
*           Because Program is made with general Argorithm,
*           it can be easily modified, comparing Functions 'multipleMatrix()' of Practice 4 and 5.
* 
*@see
*@author  shika
*@date    2023-02-05
*/

#include <stdio.h>

#define MAX_DATA 5
#define PA_SIZE 7
#define RANK 2

//====== Prototype Declaration ======
void sort_dataCAnsiYH05(void);
void count_dataCAnsiYH05(int*, int*, int*);
//void pAry_reverseCAnsiYH05(void);
void multipleMatrix(int a[2][2], int b[2][2], int c[2][2]);
void multipleMatrixGeneral(int formerAry[RANK][RANK], int laterAry[RANK][RANK], int resultAry[RANK][RANK]);

//====== Global Variable ======
int dataCAsiYH05[MAX_DATA] = { 3, 5, 0, 9, 2 };
//char *pAryCAnsiYH05[PA_SIZE] = { 'S', 'o', 'p', 'h', 'i', 'a', '\0' };
int c[2][2] = { {0, 0}, {0, 0} };
int resultAry[RANK][RANK];

//====== Definition Function ======
//int main(void) {
int mainPractice_CAnsiYH05(void) {
    //---- Practice 1 ----
    printf("Before Sort of data[]: ");
    for (int i = 0; i < MAX_DATA; i++) {
        printf("%d, ", dataCAsiYH05[i]);
    }
    printf("\n");

    sort_dataCAnsiYH05();

    printf("After  Sort of data[]: ");
    for (int i = 0; i < MAX_DATA; i++) {
        printf("%d, ", dataCAsiYH05[i]);
    }
    printf("\n");

    //---- Practice 2 ----
    int even = 0;
    int odd = 0;
    int zero = 0;

    count_dataCAnsiYH05(&even, &odd, &zero);

    printf("Even: %d \n", even);
    printf("Odd : %d \n", odd);
    printf("Zero: %d \n", zero);
    printf("\n");

    ////---- Practice 3 ----
    //printf("pAry (before): %s \n", *pAryCAnsiYH05);

    //pAry_reverseCAnsiYH05();

    //printf("pAry (after) : %s \n", *pAryCAnsiYH05);
    //printf("\n");

    //---- Practice 4 ----
    int a[2][2] = {
        { 1, 2 },
        { 3, 4 }
    };

    int b[2][2] = {
        { 1, 0 },
        { 0, 1 }
    };

    multipleMatrixGeneral(a, b, resultAry);

    printf("resultAry[%d][%d] = { \n", RANK, RANK);
    for (int i = 0; i < 2; i++) {
        printf("    { ");

        for (int j = 0; j < 2; j++) {
            printf("%d ", resultAry[i][j]);
        }

        printf("},\n");
    }//for i
    printf("};\n");
    printf("\n");

    //---- Practice 5 ----   
    int formerAry[RANK][RANK];
    int laterAry[RANK][RANK];

    multipleMatrixGeneral(formerAry, laterAry, resultAry);

    //printf("c[%d][%D] = { \n", ROW, COLUMN);
    //for (int i = 0; i < ROW; i++) {
    //    printf("    { ");

    //    for (int j = 0; j < COLUMN; j++) {
    //        printf("%d ", c[i][j]);
    //    }

    //    printf("},\n");
    //}//for i
    //printf("};\n");
    //printf("\n");

    printf("EXIT_SUCCESS \n");
    return 0;
}//main()

//---- Practice 1 ----
void sort_dataCAnsiYH05(void) {
    for (int i = 0; i < MAX_DATA - 1; i++) {
        for (int j = i + 1; j < MAX_DATA; j++) {
            if (dataCAsiYH05[i] > dataCAsiYH05[j]) {
                int temp = dataCAsiYH05[i];
                dataCAsiYH05[i] = dataCAsiYH05[j];
                dataCAsiYH05[j] = temp;
            }
        }// for j
    }//for i
}//sort_dataCAnsiYH05()

//---- Practice 2 ----
void count_dataCAnsiYH05(int* evenp, int* oddp, int* zerop) {
    *evenp = 0;
    *oddp = 0;
    *zerop = 0;

    for (int i = 0; i < MAX_DATA; i++) {
        if (dataCAsiYH05[i] == 0) {
            (*zerop)++;
            continue;
        }

        if (dataCAsiYH05[i] % 2 == 0) {
            (*evenp)++;
        }
        else {
            (*oddp)++;
        }
    }//for
}//count_dataCAnsiYH05()


////---- Practice 3 as [Book Answer] ----
//void pAry_reverseCAnsiYH05() {
//    for (int i = 0; i < (int)(PA_SIZE / 2); i++) {
//        char* temp = pAryCAnsiYH05[i];
//        pAryCAnsiYH05[i] = pAryCAnsiYH05[PA_SIZE - 1 - i];
//        pAryCAnsiYH05[PA_SIZE - 1 - i] = temp;
//    }//for
//}//pAry_reverseCAnsiYH05

//---- Practice 4 ----
void multipleMatrix(int a[2][2], int b[2][2], int c[2][2]) {
    c[0][0] = a[0][0] * b[0][0] + a[0][1] * b[1][0];
    c[0][1] = a[0][0] * b[0][1] + a[0][1] * b[1][1];
    c[1][0] = a[1][0] * b[0][0] + a[1][1] * b[1][0];
    c[1][1] = a[1][0] * b[0][1] + a[1][1] * b[1][1];
}//multipleMatrix();

//---- Practice 5 as [Book Answer] ----
void multipleMatrixGeneral(int formerAry[RANK][RANK], int laterAry[RANK][RANK], int resultAry[RANK][RANK]) {
    
    for (int i = 0; i < RANK; i++) {
        for (int j = 0; j < RANK; j++) {
            int sum = 0;
                
            for (int k = 0; k < RANK; k++) {
                sum += formerAry[i][k] * laterAry[k][j];
            }//for k

            resultAry[i][j] = sum;
        }//for j
    }//for i
    
}//mutipleMatrixGeneral()


/*
//====== Result ======
//---- Practice 1 ----
Before Sort of data[]: 3, 5, 0, 9, 2,
After  Sort of data[]: 0, 2, 3, 5, 9,

//---- Practice 2 ----
Even: 1
Odd : 3
Zero: 1

//---- Practice 3 ----
when the definiton is char *pAryCAnsiYH05[PA_SIZE] = { "Sophia" };
pAry (before): Sophia
pAry (After) : (null)

when the definiton is char *pAryCAnsiYH05[PA_SIZE] = { 'S', 'o', 'p', 'h', 'i', 'a', '\0' };

(Runtime Exception)
warning C4047: in initialization: indirect levels are different, 'char *' and 'int'.

(Give up the code as [My Answer] below) => [Book Answer]

//---- Practice 4 ----
c[2][2] = {
    { 1 2 },
    { 3 4 },
};

resultAry[2][2] = {
    { 1 2 },
    { 3 4 },
};


//---- Practice 5 ----

//====== Appendix ======
//---- Practice 3 as [My Answer] ----
char *pAryCAnsiYH05[PA_SIZE] = { "Sophia" };

void pAry_reverseCAnsiYH05() {
    char* pAryReversed[PA_SIZE] = { "" };

    for (int i = 0; i < PA_SIZE - 2; i++) {
        char c = pAryCAnsiYH05[i];

        for (int j = PA_SIZE - 2; j > 0; j--) {
            *pAryReversed[i] = c;
        }//for j
    }//for i
    *pAryReversed[PA_SIZE - 1] = '\0';
    printf("pAryReversed: %s \n", *pAryReversed);

    *pAryCAnsiYH05 = *pAryReversed;
}//pAry_reverseCAnsiYH05

//---- Practice 3 ----
pAry (before): Sophia
ClangC11Console.exe (process 5388) has finished by code -1073741819. (Runtime Exception)

//---- Practice 5 as [My Answer] ----
#define ROW 5
#define COLUMN 5

void multipleMatrixGeneral(int formerAry[ROW][COLUMN], int laterAry[ROW][COLUMN], int resultAry[ROW][COLUMN]) {
    int lastRow = ROW - 1;
    int lastColumn = COLUMN - 1;
    void multipleMatrixGeneral(int formerAry[ROW][COLUMN], int laterAry[ROW][COLUMN], int resultAry[ROW][COLUMN]);
    int resultAry[ROW][COLUMN];

    void multipleMatrixGeneral(int formerAry[ROW][COLUMN], int laterAry[ROW][COLUMN], int resultAry[ROW][COLUMN]);

    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COLUMN; j++) {
            if (i == lastRow) {
                resultAry[i][j] = formerAry[i][j] * laterAry[i][j] + formerAry[i][j + 1] * laterAry[i + 1][j];
                continue;
            }

            if (j == lastColumn) {
                resultAry[i][j] = formerAry[i][j] * laterAry[i][j] + formerAry[i][j + 1] * laterAry[i + 1][j];
                continue;
            }

            resultAry[i][j] = formerAry[i][j] * laterAry[i][j] + formerAry[i][j + 1] * laterAry[i + 1][j];
        }//for j
    }//for i

}//mutipleMatrixGeneral()
*/
