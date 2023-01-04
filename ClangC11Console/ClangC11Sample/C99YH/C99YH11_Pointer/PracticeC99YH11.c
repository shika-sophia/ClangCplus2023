/**
*@directory ClangC11Console / ClanC11Sample / C99YH / C99YH11_Pointer
*@fileName  PracticeC99YH11.c
*@reference C99YH    結城 浩 『C言語プログラミングレッスン [入門編] 第３版』SB Creative, 2019
*@reference CAnsiTH  結城 浩 『C言語プログラミングレッスン [文法編] 新版』  SB Creative, 2006
*@reference C11DS    arton  『独習 C 新版』翔泳社, 2018
*
*@content C99YH 第11章 Pointer | Chapter 11  Practice / List E11-1 / p376
*@summary PracticeC99YH11.c
*@English
*@subject Practice 11-1:  Read Behavior
*         What will it show to execute List E11-1 as below ?
* 
*         [My Answer]
*         main 1: A, B
*         quiz 1: A, B
*         quiz 2: C, P -> c, p are assigned new value in quizC99YH11()
*         main 2: A, P -> Though 'c' is assigned above, 'main()' does not refer 'c',
*                         because of [Call by Value] as C language specification.
*                         But it can do Pointer 'p' assignment, 
*                         because of [Call by Reference] in case of Pointer Argument.
* 
*         => Correct
*         
*@subject Practice 11-2:  Make Function
*         Make self-defined Function 'scanChar(char* p, char c)',
*         which verlify to include one character 'char c' in string 'char* p'.
*         If including, it shows the whole word.
*         If not including, it shows 'NULL'.
*         And it returns Pointer Address of 'char c' location.
* 
*         It is used as like 'q = scanChar("This is Japan", 'J');'.
*         q is assigned Pointer Address of 'J' location.
*         In this case, main() shows 'Japan' by using 'printf("%s \n", q)'.
* 
*         In another case, it is used as like 'q = scanChar("This is Japan", 'E');'.
*         q is assigned 'NULL'.
* 
*         [My Answer] below
* 
*@subject Practice 11-3:  Make Function
* 
*@see
*@author shika
*@date 2023-01-04
*/

#include <stdio.h>

//====== Prototype Declaration ======
void quizC99YH11(char, char*);
char* scanChar(char*, char);

//====== Function Definition ======
int main(void) {
//int PracticeC99YH11(void) {
    //---- Practice 11-1 (List E11-1) ----
    char a = 'A';
    char b = 'B';

    printf("main 1: %c, %c \n", a, b);
    quizC99YH11(a, &b);
    printf("main 2: %c, %c \n", a, b);

    //---- Practice 11-2 ----
    char str[] = "This is Japan";
    char* strP = &str;
    char searchChar = 'J';
    char* q = scanChar(strP, searchChar);
    
    if (q == NULL) {
        printf("NULL");
    }
    else {
        printf("%s \n", q);
    }

    return 0;
}//main()

//---- Practice 11-1 (List E11-1) ----
void quizC99YH11(char c, char* p) {
    printf("quiz 1: %c, %c \n", c, *p);
    c = 'C';
    *p = 'P';
    printf("quiz 2: %c, %c \n", c, *p);
}//quiz11()

//---- Practice 11-2 ----
char* scanChar(char* strP, char searchChar) {

}//scanChar()