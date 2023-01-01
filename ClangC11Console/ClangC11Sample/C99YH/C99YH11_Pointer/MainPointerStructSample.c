/**
*@directory ClangC11Console / ClanC11Sample / C99YH / C99YH11_Pointer
*@fileName  MainPointerStructSample.c
*@reference C99YH  ���� �_ �wC����v���O���~���O���b�X�� [�����] ��R�ŁxSB Creative, 2019
*@reference CAnsi  ���� �_ �wC����v���O���~���O���b�X�� [���@��] �V�Łx  SB Creative, 2006
*@reference C11DS  arton  �w�ƏK C �V�Łx�ĉj��, 2018
*
*@content C99YH ��11�� Pointer | Chapter 11 / List - / p361
*@summary MainPointerStructSample.c
*@English [�p] omit:       �ȗ�����A�E������
*         [�p] abbreviate: �ȗ�����A�Z�k����A�Ȗ񂷂�
*         [�p] brackets:   ����
*         [�p] priority:   �D��x
*         [��] superior:   �D���  <->  inferior: ���
* 
*@subject Pointer of Struct
* 
*         ��Define and Substitute
*         [Example]
*         struct Schoolmate mate;
*         struct Schoolmate *mateP;
*         mateP = &mate;
*
*         ��Refer to member in struct 
*         �E'(*p).memberName': The brackets '()' cannot be omited, because of the priority of operator.
*           The priority of Reference-operator '.' is more superior than Pointer's Redirect-operator '*',
*           therefore omited '*p.memberName' is unexpectedly recognized as different meaning '*(p.memberName)' by Compiler.
*               ||
*         �E'p->memberName': Abbreviated description: It is not necessary to write with '*', '.', '()'.
*           '(*p).memberName' and 'p->memberName' mean as same.
* 
*         [Example]
*         printf("ID:   %d \n", (*mateP).id);
*         printf("Name: %s \n", mateP->name);
* 
*         [�~] *mateP.id
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