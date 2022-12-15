/**
*@directory ClangC11Console / ClanC11Sample / C99YH / C99YH03_Variable
*@fileName  MainMultipleQuestViewer.c
*@reference C99YH  結城 浩 『C言語プログラミングレッスン [入門編] 第３版』SB Creative, 2019
*@reference CAnsi  結城 浩 『C言語プログラミングレッスン [文法編] 新版』  SB Creative, 2006
*@reference C11DS  arton  『独習 C 新版』翔泳社, 2018
*
*@content C99YH 第３章 Variable / List 3-7 / p85
*@summary MainMultipleQuestViewer
*         ランダムな１桁どうしの掛け算を10問出題し、回答を求め、正答率を出すViewer
*
*@subject <stdio.h>
*           └ #define stdin
*           └ char*   fgets(char* _Buffer, int _MaxCount, FILE _Stream)
*           └ #define stdout
*           └ void    fflush(FILE _Stream)  即時出力を促す。入力待機で出力遅延するのを防ぐ
* 
*@subject <stdlib.h>
*           └ int     atoi(char*)  ASCII to Integer 〔MainConsoleInputSample.c〕
*           └ #define RAND_MAX 32767 
*           └ int     rand(void)  [0 ~ RAND_MAX] の疑似乱数を生成
*                       rand() % 9 + 1  =>  [1 ~ 9] の疑似乱数
*           └ void    srand(unsigned int _Seed)  
*                       乱数の種 random seed: 固定値を入れると、いつも同じ順の疑似乱数となる。
*                                            固定値は Debug の際に利用する
* 
*@subject <time.h>
*           └ time_t  time(time_t const _Time)
*             llong   time(NULL) => 1670910756  現在時刻の UNIX時間
*                       UNIX Time (= epoch seconds): 1970 / 01 / 01  00:00:00 からの経過通算秒
*
*@NOTE【Consideration】C++ ?
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
    
    printf("◆Multiple Quest %d\n", MAX_QUEST);

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

    printf("《 Q %2d 》 %d ＊ %d = ", i + 1, x, y);
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
◆Multiple Quest 10
《 Q  1 》 7 ＊ 5 = 35
Correct! answer is 35

《 Q  2 》 8 ＊ 8 = 64
Correct! answer is 64

《 Q  3 》 2 ＊ 6 = 12
Correct! answer is 12

《 Q  4 》 9 ＊ 8 = 27
Wrong. correct answer is 72

《 Q  5 》 7 ＊ 3 = 20
Wrong. correct answer is 21

《 Q  6 》 9 ＊ 3 = 27
Correct! answer is 27

《 Q  7 》 7 ＊ 6 = 40
Wrong. correct answer is 42

《 Q  8 》 4 ＊ 9 = 26
Wrong. correct answer is 36

《 Q  9 》 3 ＊ 8 = 24
Correct! answer is 24

《 Q 10 》 6 ＊ 8 = 48
Correct! answer is 48

---- Result ----
correct answer: 6 / 10
correct rate:   60.00%

*/