/**
*@directory ClangC11Console / ClanC11Sample / C99YH / C99YH10_Struct
*@fileName  PracticeC99YH10.c
*@reference C99YH  åãèÈ ç_ ÅwCåæåÍÉvÉçÉOÉâÉ~ÉìÉOÉåÉbÉXÉì [ì¸ñÂï“] ëÊÇRî≈ÅxSB Creative, 2019
*@reference CAnsi  åãèÈ ç_ ÅwCåæåÍÉvÉçÉOÉâÉ~ÉìÉOÉåÉbÉXÉì [ï∂ñ@ï“] êVî≈Åx  SB Creative, 2006
*@reference C11DS  arton  Åwì∆èK C êVî≈Åx„ƒâjé–, 2018
*
*@content C99YH ëÊ10èÕ ç\ë¢ëÃ / ó˚èKñ‚ëË | Chapter 10 Struct / Practice / List - / p331
*@subject Practice 10-1  Complete List E10-1 to show individual Total score.
*         
*         [My Answer] ÅkbelowÅl
* 
*         [Book Answer] Another Solution: 
*         In case that Function argument is Array element, 
*         Should use Pointer as like '*mateP', 
*         because arument of array value as like 'array[i]', yields the copy of itself in memory,
*         that is not efficient of memory and over-head (= operation of CPU).
*         
*         => List A10-1bÅkbelowÅl
* 
*@subject Practice 10-2  Complete List E10-2 to show Total score & Average of each subjects.
*         => ÅkbelowÅl
* 
*@subject Practice 10-3  Complete List E10-3 to show caluculated Rectangle Area value.
*         => ÅkMainCalculateRectangleArea.cÅl
* 
*@see
*@author shika
*@date 2022-12-30
*/

#include <stdio.h>

//====== Define Directive ======
#define NAME_MAX 50
#define MATE_MAX 4

//====== Struct Declaration ======
typedef struct Schoolmate {
    int id;
    char name[NAME_MAX];
    int japanese;
    int mathematics;
    int english;
} MATE;

struct Schoolmate mateAry[] = {
    {1, "åãèÈç_", 65, 90, 100},
    {2, "à¢î{òaîn", 82, 73, 63},
    {3, "à…ì°åıàÍ", 74, 31, 41},
    {4, "ç≤ì°ÇﬂÇÆÇ›", 100, 95, 98},
}; 

//====== Global Variable ======
int totalJapnanese = 0;
int totalMathematics = 0;
int totalEnglish = 0;
int mateCount = 0;

//====== Prototype Declaration ======
void showTotalIndividual(MATE);
void showTotalIndividualForPointer(MATE*);
void generateTotalEachSubject(MATE);

//====== Funcion Definition ======
//int main(void) {
int mainPracticeC99YH10(void) {

    //---- Practice 10-1  Argument of Array value Version ----
    for (int i = 0; i < MATE_MAX; i++) {
        showTotalIndividual(mateAry[i]);
    }//for
    printf("\n");

    //---- List A10-1b  Argument of Pointer Version ----
    for (int i = 0; i < MATE_MAX; i++) {
        showTotalIndividualForPointer(&mateAry[i]);
    }//for
    printf("\n");

    //---- Practice 10-2 ----
    for (int i = 0; i < MATE_MAX; i++) {
        generateTotalEachSubject(mateAry[i]);
    }//for

    return 0;
}//main()

//---- Practice 10-1 Argument of Array value Version ----
void showTotalIndividual(MATE mate) {
    int totalIndividual = mate.japanese + mate.mathematics + mate.english;

    printf("%-11s Total (individual): %3d\n", &mate.name[0], totalIndividual);
}//showTotalIndividual()

//---- List A10-1b Argument of Pointer Version ----
void showTotalIndividualForPointer(MATE* mateP) {
    int totalIndividual = mateP->japanese + mateP->mathematics + mateP->english;
    
    printf("%-11s Total (individual): %3d\n", mateP->name, totalIndividual);
}//showTotalIndividualForPointer()

//---- Practice 10-2 ----
void generateTotalEachSubject(MATE mate) {
    totalJapnanese += mate.japanese;
    totalMathematics += mate.mathematics;
    totalEnglish += mate.english;

    mateCount++;

    if (mateCount == MATE_MAX) {
        printf("Japanse     Total (Subject): %3d, Average %.2f \n",
            totalJapnanese, (double)totalJapnanese / MATE_MAX);
        printf("Mathematics Total (Subject): %3d, Average %.2f \n",
            totalMathematics, (double)totalMathematics / MATE_MAX);
        printf("English     Total (Subject): %3d, Average %.2f \n",
            totalEnglish, (double)totalEnglish / MATE_MAX);
        printf("\n");
    }
}//generateTotalEachSubject()

/*
//====== Result ======
//---- Practice 10-1  Argument of Array value Version ----
åãèÈç_      Total (individual): 255
à¢î{òaîn    Total (individual): 218
à…ì°åıàÍ    Total (individual): 146
ç≤ì°ÇﬂÇÆÇ›  Total (individual): 293

//---- List A10-1b  Argument of Pointer Version ----
åãèÈç_      Total (individual): 255
à¢î{òaîn    Total (individual): 218
à…ì°åıàÍ    Total (individual): 146
ç≤ì°ÇﬂÇÆÇ›  Total (individual): 293

//---- Practice 10-2 ----
Japanse     Total (Subject): 321, Average 80.25
Mathematics Total (Subject): 289, Average 72.25
English     Total (Subject): 302, Average 75.50

*/