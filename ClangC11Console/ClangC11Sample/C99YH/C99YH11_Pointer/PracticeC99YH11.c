/**
*@directory ClangC11Console / ClanC11Sample / C99YH / C99YH11_Pointer
*@fileName  PracticeC99YH11.c
*@reference C99YH    結城 浩 『C言語プログラミングレッスン [入門編] 第３版』SB Creative, 2019
*@reference CAnsiTH  結城 浩 『C言語プログラミングレッスン [文法編] 新版』  SB Creative, 2006
*@reference C11DS    arton  『独習 C 新版』翔泳社, 2018
*
*@content C99YH 第11章 Pointer | Chapter 11  Practice / List E11-1 / p376
*@summary PracticeC99YH11.c
*@English [英] crucial: 重要, 重大, 不可欠, 決定的, きわめて 重要, 欠かせない
* 
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
*         -> [My Answer] Appendix below / ERROR 1, WARNIG 9 -> GIVE UP
*         -> [Book Answer] List A11-2 -> main() below
*
*@subject Practice 11-3:  Make Function
*         Make self-deifined Function 'int countUpper(char* stringP, int* lengthP)',
*         which returns the number of upper case character in argument string, and returns length of string.
*         [Argument]
*         char* string: string text 
*         int length:   Pointer of int length variable
* 
*         [The way to use]
*         int length;
*         int upper = countUpper("This is Japan.", &length);
*         
*         printf("Length: %d \n", length);
*         printf("Upper Num: %d \n", upper);
* 
*         [Expected Result]
*         Length: 14
*         Upper Num: 2 
* 
*         -> [My Answer] below
*         => Correct
* 
*         [Correct too]
*         char* s = string;
* 
*         while(*s) { ... }
*         if (isupper(*s)) { ... }
* 
*         => [Book Answer] Another Solution: Array Version 〔List A11-3a | C99YH p381〕
* 
//---- List A11-3a ----
int counter (char* stringP, int* lengthP) 
{
    int upper = 0;
    *lengthP = 0;
    
    for (int i = 0; stringP[i] != '0'; i++) {
        if (isupper(string[i])) {
            upper++;
        }
        (*length)++
     }//for

     return upper;
}

@subject【Notation】'(*length)++' and '*length++'
         They are different meanings, because of the priority.
         '(*length)++': increment int value 'length' which Pointer '*length' indicate.
         '*(length++)': At first, increment Pointer address '&length', and then get the value there.

         The priority of Substitute and Increment operator '++' is superior than Pointer Redirect operator '*'.
         Simple '*length++' means '*(length++)'.
         Therefore when increment value indicated by Pointer, it is required priority-blanket '()'.

*@see
*@author shika
*@date 2023-01-04, 01-05
*/

#include <stdio.h>
#include <string.h>

//====== Prototype Declaration ======
void quizC99YH11(char, char*);
char* scanChar(char*, char);
void validateScan(char*, char);
int countUpper(char*, int*);

//====== Function Definition ======
//int main(void) {
int PracticeC99YH11(void) {

    //====== Practice 11-1 (List E11-1) ======
    char a = 'A';
    char b = 'B';

    printf("main 1: %c, %c \n", a, b);
    quizC99YH11(a, &b);
    printf("main 2: %c, %c \n", a, b);
    printf("\n");

    //====== Practice 11-2 [Book Answer] ======
    validateScan("This is Japan.", 'J');
    printf("\n");
    validateScan("This is Japan.", 'E');
    printf("\n");

    //====== Practice 11-3 ======
    int length = 0;
    int upper = countUpper("This is Japan.", &length);

    printf("Length: %d \n", length);
    printf("Upper Num: %d \n", upper);

    return 0;
}//main()

//====== Practice 11-1 (List E11-1) ======
void quizC99YH11(char c, char* p) {
    printf("quiz 1: %c, %c \n", c, *p);
    c = 'C';
    *p = 'P';
    printf("quiz 2: %c, %c \n", c, *p);
}//quiz11()

//====== Practice 11-2 [Book Answer] ======
char* scanChar(char* p, char c) {
    while (*p != '\0') {
        if (*p == c) {
            return p; // if find it, then return the address
        }

        p++;
    }//while

    return NULL;
}//scanChar()

void validateScan(char* strP, char c) {
    char* scanP = scanChar(strP, c);

    if (scanP == NULL) {
        printf("<！> Not Found '%c' in [%s]. \n", c, strP);
    }
    else {
        printf("Found '%c' in [%s].\n", c, strP);
        printf("The text after the found location, is [%s].\n", scanP);
    }
}//validateScan()

//====== Practice 11-3 ======
int countUpper(char* stringP, int* lengthP) {
    int upper = 0;
    int length = 0;

    while (*stringP != '\0') {
        length++;

        if (isupper(*stringP)) {
            upper++;
        }

        stringP++;
    }//while

    *lengthP = length;
    return upper;
}//countUpper()

/*
//====== Result 11-1 ======
main 1: A, B
quiz 1: A, B
quiz 2: C, P
main 2: A, P

//====== Result 11-2 [Book Answer] ======
Found 'J' in [This is Japan.].
The text after the found location, is [Japan.].

<！> Not Found 'E' in [This is Japan.].

//====== Result 11-3 ======
Length: 14
Upper Num: 2

//###### Appendix ######
//====== Practice 11-2 [My Answer] ======
#define WORD_MAX 50
#define WORD_NUM 3
char str[WORD_NUM][WORD_MAX] = { "This", "is", "Japan" };
    //【Warning】C4047 '初期化中': 間接参照のレベルが 'char *' と 'char (*)[3][50]' で異なっています。	
    // (meaning)'Initialization': It is different types of Pointer Redirect Reference: 'char *' and 'char (*)[3][50]'.

int main(void) {
    char* strP = &str;

    //---- switch comment-out ----
    char searchChar = 'J';
    //char searchChar = 'E';

    //---- call scanChar() ----
    char q = scanChar(strP, searchChar);

    if (q == NULL) {       //【Warning】	C4047 '==': 間接参照のレベルが 'int' と 'void *' で異なっています。	
        printf("NULL");    // (meaning) 'Initialization': It is different types of Pointer Redirect Reference: 'int' and 'void*'.
    }
    else {
        printf("%s \n", q); //【Warning】C4477 'printf' : 書式文字列 '%s' には、型 'char *' の引数が必要ですが、可変個引数 1 は型 'int' です
                            // (meaning) 'printf': format string '%s' is required 'char *' type, but [length-adjustable argument1] is 'int' type.
    }
}//main()

char scanChar(char* strP, char searchChar) {
    char q = NULL;              //【Warning】C4047	'初期化中': 間接参照のレベルが 'char' と 'void *' で異なっています。
                                // (meaning) 'Initialization': It is different types of Pointer Redirect Reference: 'int' and 'void*'.
    for (int i = 0; i < WORD_NUM; i++) {
        char word[] = *strP;
                //【Compile Error】C2075 'word': 初期化には中かっこで囲まれた初期化子リストが必要です
                // (meaning) 'word': To initialize it, the expression need be defined by element list with initializer '{ }'.

        for (int j = 0; j < (sizeof(word) / sizeof(word[0])); j++) {
            if (strcmp(word[j], searchChar) == 0) {
                //【Warning】C4024 'strcmp': の型が 2 の仮引数および実引数と異なります。
                //【Warning】C4047 '関数': 間接参照のレベルが 'const char *' と 'char' で異なっています。
                // (meaning) 'strcmp':   It is different types of second argument: the argument of defined function and the parameter of calling.
                // (meaning) 'Function': It is different types of Pointer Redirect Reference: 'const char*' and 'char'.

                q = strP;   //【Worning】C4047 '=': 間接参照のレベルが 'char' と 'char *' で異なっています。
            }               // (meaning)        '=': It is different types of Pointer Redirect Reference: 'char' and 'char*'.
        }//for j

        strP++;
    }//for i

    return q;
}//scanChar()

【Analysis】[My Answer]
 Mainly, different types, I would solve them.
 'if (q == NULL)' and 'char q = NULL;', it may be cause that 'q' defined as 'char' type,
 Because 'NULL' is 'void*', q need be Pointer.
 Most crucial problem is that Array cannot be defined by value indicated by Pointer '*str'.

 see [Book Answer] above
 Wow, it's very simple.
 'char*  scanChar()' return Pointer. 'q' must be Pointer type.
 main() give directly string text: "This is Japan." to Argument 'char*'.
 By 'while (*p != '\0')', check whole text.
 If find it, return its addrss.
 If not, return NULL.
 
 It shows these code only:
   printf("Found '%c' in [%s].\n", c, strP);
   printf("The text after the found location, is [%s].\n", scanP);

 And 'if (*p == c)':
    operator '==' can compare both 'char' types,
    because 'char' is actually 'int' value.
    But '==' cannot compare both string texts without 'strcmp()',
    because string text is actually array of 'char'.
*/