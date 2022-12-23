/**
*@directory ClangC11Console / ClanC11Sample / C99YH / C99YH06_ForIteration
*@fileName  PracticeC99YH06.c
*@reference C99YH  Œ‹é _ wCŒ¾ŒêƒvƒƒOƒ‰ƒ~ƒ“ƒOƒŒƒbƒXƒ“ [“ü–å•Ò] ‘æ‚R”ÅxSB Creative, 2019
*@reference CAnsi  Œ‹é _ wCŒ¾ŒêƒvƒƒOƒ‰ƒ~ƒ“ƒOƒŒƒbƒXƒ“ [•¶–@•Ò] V”Åx  SB Creative, 2006
*@reference C11DS  arton  w“ÆK C V”ÅxãÄ‰jĞ, 2018
*
*@content C99YH ‘æ‚UÍ —ûK–â‘è | Chapter 6 Practice / List - / p176
* 
*@English [‰p] line feed: ‰üs
*         [‰p] revise:    ‰ü‚ß‚é
*         [‰p] verify:    ŒŸØ‚·‚é
*         [‰p] modify:    C³‚·‚é
*         [‰p] prevent:   –h‚®
*         [‰p] infinity loop: –³ŒÀƒ‹[ƒv
*         [‰p] behavior:  ‹““®, U•‘‚¢
*         [‰p] Multipication Table: ‹ã‹ã•\
*
*@subject Practice 6-1:  True or False about this 'for'-sentence below.
*           for(int i = 0; i < 3; i++){
*               printf("%d\n", i);
*           }//for
* 
*         Z (1) It shows '0 1 2 3' with line feed.
*               -> False: only '0 1 2'
*         Z (2) It judge 'i < 3' expression 3 times.
*               -> False: 4 times. When 0, it judge too.
*         Z (3) It judge 'i++' expession 3 times.
*               -> True: 0 -> 1 / 1 -> 2 / 2 -> 3 / break out 'for'
*         Z (4) Function 'printf()' is executed 3 times.
*               -> True: It shows '0 1 2'.
* 
*@subject Practice 6-2:
*         Refering List 6-3, List 6-4, Make a program that it draws the square function graph in range [0 - 9].
*         -> [My Answer] revise about range [-10 - 10] below.
* 
*@subject Practice 6-3:  Seek wrong point in List E6-3 which someone want to be like List 6-4.
*         Row 11: [~] 'for(i = 0; j < i; i++)' -> Z 'for(j = 0; j < i; j++)'
*         
*         => Correct
*         => List E6-3 can execute and do infinity loop as unexpected.
*            (It is not verified by C compiler.)
* 
*         => [Another Answer] from C99
*            The 'int i, j;' should be defined at initialize expression in 'for()'.
*            The modification can prevent that unexpected behavior.
* 
*@subject Practice 6-4:  Make a program that it shows Multipication Table.
*         => seekMainMultipleNestedForViewer.cl
* 
*@see
*@author shika
*@date 2022-12-20
*/

#include <stdio.h>

void drawSqureGraph(int, int);

//int main(void) {
int mainPracticeC99YH06(void) {
    int min = -10;
    int max = 10;

    drawSqureGraph(min, max);

    return 0;
}//main()

void drawSqureGraph(int min, int max) {
    if (max < min) {
        int temp = min;
        min = max;
        max = temp;
    }

    for (int i = min; i <= max; i++) {
        printf("%3d: ", i);

        for (int j = 0; j < (i * i); j++) {
            printf("*");
        }//for j

        printf("\n");
    }//for i
}//drawSqureGraph()

/*
//====== Result ======
-10: ****************************************************************************************************
 -9: *********************************************************************************
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
  9: *********************************************************************************
 10: ****************************************************************************************************

*/