/**
*@directory ClangC11Console / ClanC11Sample / C99YH / C99YH08_Function
*@fileName  PracticeC99YH08.c
*@reference C99YH  ���� �_ �wC����v���O���~���O���b�X�� [�����] ��R�ŁxSB Creative, 2019
*@reference CAnsi  ���� �_ �wC����v���O���~���O���b�X�� [���@��] �V�Łx  SB Creative, 2006
*@reference C11DS  arton  �w�ƏK C �V�Łx�ĉj��, 2018
*
*@content C99YH ��W�� ���K��� | Chapter 8 Practice / List E8-4 / p242
*@subject Practice 8-1  Seek the reason of Compile Error:
*         Using List 8-3, someone wants to output ten '*' and describes 'Print_graph(10)';'.
*         Then it was thrown Compile Error. Why?
*         
*         [My Answer] 
*         Because of lack 'Definition of the Function' and 'Prototype declaration'.
*         It probably is described another file of List 8-3,
*         therefore the defintion of the function is not exist in this file.
*         It need do Divided Compile or copy the defintion of the function with Prototype declaration.
* 
*         => Correct
* 
*         [Book Answer] 
*         Because the function name 'Print_graph(10)' is wrong with correctly 'print_graph(10)'.
*         These names are distinguished upper case and lower case by Compiler.
* 
*@subject Practice 8-2  What behavior is the function 'foo' below.
*         [Example] foo()
* 
*         int foo(int n) {
*             if (n > 0) {
*                 return n;
*             } else { 
*                 return -n;
*             }
*          }//foo()
* 
*          [My Answer] It returns an absolute value of argument 'n'.
* 
*@subject Practice 8-3  What behavior is the function 'baa' below.
*         [Example] baa()
* 
*         void baa(int x, char c) {
*            for (int i = 0; i < x; i++) {
*                printf("%c", c);
*            }//for
*            printf("\n");
*         }//baa()
* 
*         [My Answer] It shows 'x' pieces of character 'c'.
* 
*@subject Practice 8-4  Seek wrong point in List E8-4
*         �Z Row  3:  [�~] lack of ';' -> �Z add ';' 
*         �Z Row  7:  [�~] definition the function is described ';' -> �Z delete ';'
*         �Z Row 13:  [�~] retarn  -> �Z return
* 
*@subject Practice 8-5
*         void  drawSqureGraph(int min, int max)
*           =>�kC99YH06_ForIteratation\PracticeC99YH06.c�lor below
*         
*         [My Answer] 
*         It can execute and call the function defined another file.
*         In this file, it need 'Prototype Declraration' and call 'drawSqureGraph()' only.
*         The result is as below.
* 
*         => Correct
* 
*         [Book Answer] another answer
          Using 'print_graph()' and 'get_power()', of course with these declarations, 
          it call as like 'print_graph(get_power(base, power)'.
* 
*@see C99YH06_ForIteratation\PracticeC99YH06.c
*@author shika
*@date 2022-12-24
*/

#include <stdio.h>

void drawSqureGraph(int, int);  // =>�kC99YH06_ForIteratation\PracticeC99YH06.c�lor below

//int main(void) {
int mainPracticeC99YH08(void) {
    int min = -8;
    int max = 8;

    drawSqureGraph(min, max);

    return 0;
}//main()

////====== already dedined in C99YH06_ForIteratation\PracticeC99YH06.c ======
//void drawSqureGraph(int min, int max) {
//    if (max < min) {
//        int temp = min;
//        min = max;
//        max = temp;
//    }
//
//    for (int i = min; i <= max; i++) {
//        printf("%3d: ", i);
//
//        for (int j = 0; j < (i * i); j++) {
//            printf("*");
//        }//for j
//
//        printf("\n");
//    }//for i
//}//drawSqureGraph()

/*
//====== Result ======
 -8: ****************************************************************
 -7: *************************************************
 -6: ************************************
 -5: *************************
 -4: ****************
 -3: *********
 -2: ****
 -1: *
  0:
  1: *
  2: ****
  3: *********
  4: ****************
  5: *************************
  6: ************************************
  7: *************************************************
  8: ****************************************************************

*/