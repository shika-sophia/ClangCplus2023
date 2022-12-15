/**
*@directory ClangC11Console / ClanC11Sample / C99YH / C99YH03_Variable
*@fileName  MainMultipleQuestViewer.c
*@reference C99YH  ���� �_ �wC����v���O���~���O���b�X�� [�����] ��R�ŁxSB Creative, 2019
*@reference CAnsi  ���� �_ �wC����v���O���~���O���b�X�� [���@��] �V�Łx  SB Creative, 2006
*@reference C11DS  arton  �w�ƏK C �V�Łx�ĉj��, 2018
*
*@content C99YH ��R�� Variable / List 3-7 / p85
*@summary MainMultipleQuestViewer
*         �����_���ȂP���ǂ����̊|���Z��10��o�肵�A�񓚂����߁A���������o��Viewer
*
*@subject <stdio.h>
*           �� #define stdin
*           �� char*   fgets(char* _Buffer, int _MaxCount, FILE _Stream)
*           �� #define stdout
*           �� void    fflush(FILE _Stream)  �����o�͂𑣂��B���͑ҋ@�ŏo�͒x������̂�h��
* 
*@subject <stdlib.h>
*           �� int     atoi(char*)  ASCII to Integer �kMainConsoleInputSample.c�l
*           �� #define RAND_MAX 32767 
*           �� int     rand(void)  [0 ~ RAND_MAX] �̋^�������𐶐�
*                       rand() % 9 + 1  =>  [1 ~ 9] �̋^������
*           �� void    srand(unsigned int _Seed)  
*                       �����̎� random seed: �Œ�l������ƁA�����������̋^�������ƂȂ�B
*                                            �Œ�l�� Debug �̍ۂɗ��p����
* 
*@subject <time.h>
*           �� time_t  time(time_t const _Time)
*             llong   time(NULL) => 1670910756  ���ݎ����� UNIX����
*                       UNIX Time (= epoch seconds): 1970 / 01 / 01  00:00:00 ����̌o�ߒʎZ�b
*
*@NOTE�yConsideration�zC++ ?
*      The already defined Function saved Object File [Debug/xxxx.obj].
*      duplicate definitions in this file are thrown compile error.
* 
*@see
*@author shika
*@date 2022-12-13
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_QUEST 10
#define BUFFER_SIZE 256

int multipleQuest(int);        //self defined
void consoleInput(char*, int); //already defined in MainConsoleInputSample.c

//int main(void) {
int mainMultipleQuestViewer(void) {
    int correctNum = 0;
    double correctRate = 0.0;
    srand((unsigned int) time(NULL));
    
    printf("��Multiple Quest %d\n", MAX_QUEST);

    for (int i = 0; i < MAX_QUEST; i++) {
        correctNum += multipleQuest(i);
    }//for

    correctRate = ((double)correctNum / MAX_QUEST) * 100;
    printf("---- Result ----\n");
    printf("correct answer: %d / %d\n", correctNum, MAX_QUEST);
    printf("correct rate:   %.2f%%", correctRate);
    
    return 0;
}//main()

int multipleQuest(int i) {
    char buffer[BUFFER_SIZE];
    int x = rand() % 9 + 1;
    int y = rand() % 9 + 1;
    int answer = x * y;

    printf("�s Q %2d �t %d �� %d = ", i + 1, x, y);
    fflush(stdout);
    consoleInput(buffer, BUFFER_SIZE);
    int input = atoi(buffer);

    if (input == answer) {
        printf("Correct! answer is %d\n", answer);
        printf("\n");
        return 1;
    }
    else {
        printf("Wrong. correct answer is %d\n", answer);
        printf("\n");
        return 0;
    }
}//quest()

//====== already definied in MainConsoleInputSample.c ======
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
��Multiple Quest 10
�s Q  1 �t 7 �� 5 = 35
Correct! answer is 35

�s Q  2 �t 8 �� 8 = 64
Correct! answer is 64

�s Q  3 �t 2 �� 6 = 12
Correct! answer is 12

�s Q  4 �t 9 �� 8 = 27
Wrong. correct answer is 72

�s Q  5 �t 7 �� 3 = 20
Wrong. correct answer is 21

�s Q  6 �t 9 �� 3 = 27
Correct! answer is 27

�s Q  7 �t 7 �� 6 = 40
Wrong. correct answer is 42

�s Q  8 �t 4 �� 9 = 26
Wrong. correct answer is 36

�s Q  9 �t 3 �� 8 = 24
Correct! answer is 24

�s Q 10 �t 6 �� 8 = 48
Correct! answer is 48

---- Result ----
correct answer: 6 / 10
correct rate:   60.00%

*/