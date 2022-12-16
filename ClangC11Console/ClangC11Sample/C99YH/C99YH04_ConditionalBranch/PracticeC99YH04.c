/**
*@directory ClangC11Console / ClanC11Sample / C99YH / C99YH04_ConditinalBranch
*@fileName  PracticeC99YH04.c
*@reference C99YH  ���� �_ �wC����v���O���~���O���b�X�� [�����] ��R�ŁxSB Creative, 2019
*@reference CAnsi  ���� �_ �wC����v���O���~���O���b�X�� [���@��] �V�Łx  SB Creative, 2006
*@reference C11DS  arton  �w�ƏK C �V�Łx�ĉj��, 2018
*
*@content C99YH ��S�� ���K��� | Chapter 4 Practice / List A4-2 / p124
* 
*@English [�p] conditional branch:  ��������
*         [�p] expression:  ��, �\��
*         [�p] proposition: ����
*         [�p] substitute:  �������
*         [�p] appropriate: �K�؂�
* 
*@subject Practice 4-1  True or False
*         �Z (1) When n value is 3, Proposition 'n > 3' is false.
*             -> True
*         �~ (2) Proposition 'n is equal or over 0, under 20' can be described '0 <= n < 20' as conditional expression.
*             -> False, Compile Error.
*                It should be describe '0 <= n || n < 20'.
*             => Correctly '0 <= n && n < 20' 
*         �Z (3) Proposition 'n value equals 3.14' is described 'n = 3.14' as conditional expression.
*             -> False, it means substitute 3.14 to n value.
*             It should be described 'n == 3.14'.
* 
*@subject Practice 4-2
*         ��Greeting Program
*         It asks user 'What o'clock?', 
*         it shows appropriate greeting with condition below.
* 
*         [Input Range]  0 - 23
*         [Condition]
*         �Ebefore noon: 0 - 11
*         �Enoon:        12
*         �Eafter noon:  13 - 18
*         �Enight:       19 - 23
* 
*@subject Practice 4-3
*         '0 is false, not 0 is true' in C language.
*         Are these same operation, below ?
*         variable x is int type and has value.
*         (1)  if ( x ) { operation... }
*         (2)  if ( x == 1 ) { operation... }
* 
*         -> [My Answer]
*            No, I dont't think so. because...
*            when x == 0, both are false: do no operation.
*            when x == 1, both are true:  do the operation.
*            when x == 123, (1) is true, (2) is false. these are different moves. 
* 
*         => According to [Book Answer] p128, 
*            �E<stdbool.h> define 'true', 'false'.
*            �E[�~] Don't compare between boolean values,
*                  for example 'if (x == true)' or '#define TRUE 1  if (x == TRUE)',
*                  because it is not safe:
*                  When x == 2 were true value, these expression is false.
* 
*@see
*@author shika
*@date 2022-12-16
*/

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 256
void consoleInput(char*, int);

//int main(void) {
int mainPracticeC99YH04(void) {
    char buffer[BUFFER_SIZE];
    int canInput = 0; // as boolean (default false)
    int hour;

    printf("��Greeting Program\n");
    
    //---- Loop Question ----
    while (!canInput) {
        printf("��What o'clock ? > ");
        consoleInput(buffer, BUFFER_SIZE);
        hour = atoi(buffer);

        //---- Validate Input ----
        if (0 <= hour && hour <= 23) {
            canInput = 1;  // to break while()
        }
        else {
            printf("<�I> The o'clock should be input in range [ 0 - 23 ].\n");
            continue;
        }
    }//while

    //---- Conditinal Branch & show Greeting ----
    if (0 <= hour && hour <= 11) {
        printf("Good Morning.\n");
    }
    else if (hour == 12) {
        printf("Let's take lunch.\n");
    }
    else if (13 <= hour && hour <= 18) {
        printf("Good Afternoon.\n");
    }
    else if (19 <= hour && hour <= 23) {
        printf("Good Night.\n");
    }

    return 0;
}//main()

//====== already defined in C99YH03_Variable/MainConsoleInputSample.c ======
//void consoleInput(char* buffer, int bufferSize) {
//    char* inputAry = fgets(buffer, bufferSize, stdin);
//
//    if (inputAry == NULL) {
//        buffer[0] = '\0';
//        return;
//    }
//
//    for (int i = 0; i < bufferSize; i++) {
//        if (buffer[i] == '\n') {
//            buffer[i] = '\0';
//            return;
//        }
//    }//for
//}//consoleInput()

/*
//====== Result ======
��Greeting Program
��What o'clock ? > 8
Good Morning.

��Greeting Program
��What o'clock ? > 12
Let's take lunch.

��Greeting Program
��What o'clock ? > 18
Good Afternoon.

��Greeting Program
��What o'clock ? > 22
Good Night.

��Greeting Program
��What o'clock ? > -1
<�I> The o'clock should be input in range [ 0 - 23 ].
��What o'clock ? > 24
<�I> The o'clock should be input in range [ 0 - 23 ].
��What o'clock ? > ����
Good Morning.  // (unsolved problem)

�yAnalysis�z
 The asking loop in case of invalid input, successed.
 It leaves '(unsolved problem)' that it should validate in case of not-numeric input.
*/