/**
*@directory ClangC11Console / ClanC11Sample / C99YH / C99YH07_WhileIteration
*@fileName  MainPracticeC99YH07.c
*@reference C99YH  åãèÈ ç_ ÅwCåæåÍÉvÉçÉOÉâÉ~ÉìÉOÉåÉbÉXÉì [ì¸ñÂï“] ëÊÇRî≈ÅxSB Creative, 2019
*@reference CAnsi  åãèÈ ç_ ÅwCåæåÍÉvÉçÉOÉâÉ~ÉìÉOÉåÉbÉXÉì [ï∂ñ@ï“] êVî≈Åx  SB Creative, 2006
*@reference C11DS  arton  Åwì∆èK C êVî≈Åx„ƒâjé–, 2018
*
*@content C99YH ëÊÇVèÕ WhileIteration ó˚èKñ‚ëË | Chapter 7 Practice / List - / p
*@subject Practice 7-1  True or False about 'while' sentence [Example] below.
*         
*         [Example]
*         int n = 3;
*         while(n > 0) {
*             printf("%d\n", n);
*             n--;
*         }
* 
*         ÅZ (1) It shows '3 2 1 0' with line feed.
*               -> False: It doesn't show '0', because conditional expression is 'n > 0', when '0' is false, so it is out of while { }.
*         ÅZ (2) The decrement expression 'n--' is operated 3 times.
*               -> True: '3 -> 2 -> 1 -> 0'.
*         ÅZ (3) The function 'printf()' is operated 3 times.
*               -> True: '3 2 1'
* 
*@subject Practice 7-2:
*         Replace 'for' to 'while' of List E7-2.
*         Of course, maintaining the same behavior.
*  
*         -> [My Answer] ÅkbelowÅl
* 
*@subject Practice 7-3:  Make a program that: 
*         When user inputs multi-rows from standard input (= Console), 
*         it counts the number of each kind of characters -- upper case, lower case, alphabet, or white-space,
*         on assuming that user can input ASCII code only.
*         
*         -> [My Answer] ÅkbelowÅl
*            I defined each counter as 'int' type. But [Book Answer] is defferent as below.
* 
*         => [Book Answer] 
*            Each counters are defined as 'long' type.
*            The reason why it need be defined as 'long' type, 
*            is because of considering applicablity to very long document.
*                                       Ñ§ [âp] ìKópâ¬î\ê´
* 
*            (In this CompilerÅ@-- VS clang, the range of 'long' is same as 'int',
*            so I modified my program changing 'int' to 'long long'.)
* 
*@see
*@author shika
*@date 2022-12-23
*/

#include <stdio.h>
#include <ctype.h>

//int main(void) {
int mainPracticeC99YH07(void) {
    //---- Practice 7-2 ----
    int i = 0;
    while (i < 10) {
        printf("%d ", i);

        int j = 0;
        while (j < i) {
            putchar('*');
            j++;
        }//while j
        printf("\n");

        i++;
    }//while i
    printf("\n");

    //---- Practice 7-3 ----
    int c;
    long long upperCount = 0LL;
    long long lowerCount = 0LL;
    long long alphaCount = 0LL;
    long long spaceCount = 0LL;

    printf("ÅüPractice 7-3: Please sevral input [ - : END ] > ");

    while ((c = getchar()) != '-') {
        if (isupper(c)) {
            upperCount++;
        }
        else if (islower(c)) {
            lowerCount++;
        }

        if (isalpha(c)) {
            alphaCount++;
        }

        if (isspace(c)) {
            spaceCount++;
        }
    }//while

    printf("Upper count: %lld\n", upperCount);
    printf("Lower count: %lld\n", lowerCount);
    printf("Alphabet count: %lld\n", alphaCount);
    printf("Space count: %lld\n", spaceCount);

    return 0;
}//main()

/*
//====== Result ======
//---- Practice 7-2 ----
0
1 *
2 **
3 ***
4 ****
5 *****
6 ******
7 *******
8 ********
9 *********

//---- Practice 7-3 ----
ÅüPractice 7-3: Please sevral input  [ - : END ] > 
    This is Japan. That is USA. This is a pen. She is Sophia.-
Upper count: 9
Lower count: 32
Alphabet count: 41
Space count: 12
*/