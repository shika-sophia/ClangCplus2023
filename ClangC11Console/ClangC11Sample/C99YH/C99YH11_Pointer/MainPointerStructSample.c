/**
*@directory ClangC11Console / ClanC11Sample / C99YH / C99YH11_Pointer
*@fileName  MainPointerStructSample.c
*@reference C99YH  結城 浩 『C言語プログラミングレッスン [入門編] 第３版』SB Creative, 2019
*@reference CAnsi  結城 浩 『C言語プログラミングレッスン [文法編] 新版』  SB Creative, 2006
*@reference C11DS  arton  『独習 C 新版』翔泳社, 2018
*
*@content C99YH 第11章 Pointer | Chapter 11 / List - / p361
*@summary MainPointerStructSample.c
*@English [英] omit:       省略する、脱落する
*         [英] abbreviate: 省略する、短縮する、簡約する
*         [英] brackets:   括弧
*         [英] priority:   優先度
*         [羅] superior:   優れる  <->  inferior: 劣る
* 
*@subject Pointer of Struct
* 
*         ＊Define and Substitute
*         [Example]
*         struct Schoolmate mate;
*         struct Schoolmate *mateP;
*         mateP = &mate;
*
*         ＊Refer to member in struct 
*         ・'(*p).memberName': The brackets '()' cannot be omited, because of the priority of operator.
*           The priority of Reference-operator '.' is more superior than Pointer's Redirect-operator '*',
*           therefore omited '*p.memberName' is unexpectedly recognized as different meaning '*(p.memberName)' by Compiler.
*               ||
*         ・'p->memberName': Abbreviated description: It is not necessary to write with '*', '.', '()'.
*           '(*p).memberName' and 'p->memberName' mean as same.
* 
*         [Example]
*         printf("ID:   %d \n", (*mateP).id);
*         printf("Name: %s \n", mateP->name);
* 
*         [×] *mateP.id
* 
*@see
*@author shika
*@date 2023-01-01
*/

#include <stdio.h>

typedef struct Schoolmate {
    int id;
    char name[50];
    int japanese;
    int mathematics;
    int english;
} MATE;

//int main(void) {
int mainPointerStructSample(void) {
    MATE mate = { 1, "Sophia", 88, 90, 75 };
    MATE* mateP = &mate;

    printf("ID:   %d \n", (*mateP).id);
    printf("Name: %s \n", mateP->name);
    printf("Japanese:   %3d \n", mateP->japanese);
    printf("Mathmatics: %3d \n", mateP->mathematics);
    printf("English:    %3d \n", mateP->english);

    return 0;
}//main()

/*
//====== Result ======
ID:   1
Name: Sophia
Japanese:    88
Mathmatics:  90
English:     75

*/