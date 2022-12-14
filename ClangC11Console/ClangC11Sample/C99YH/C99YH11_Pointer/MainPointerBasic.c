/**
*@directory ClangC11Console / ClanC11Sample / C99YH / C99YH11_Pointer
*@fileName  MainPointerBasic.c
*@reference C99YH  結城 浩 『C言語プログラミングレッスン [入門編] 第３版』SB Creative, 2019
*@reference CAnsi  結城 浩 『C言語プログラミングレッスン [文法編] 新版』  SB Creative, 2006
*@reference C11DS  arton  『独習 C 新版』翔泳社, 2018
*
*@content C99YH 第11章 Pointer | Chapter 11 / List - / p343
*@summary MainPointerBasic.c
*@English [英] assign:     割り当てる、代入する
*         [英] substitute: 代入する、入れ替える
* 
*@subject ■ Pointer
*         pointer: The variable which has address of the other variable.
*                  Therefore, it called "pointer" which indicates something.
*
*         ＊Define
*         ・'*': Pointer is defined by adding '*' to the variable name.
* 
*         [Example]
*         int  x;      // definition of int type 
*         int  *p;     // definition of pointer to int type
*         int  *p, *q; // multiple definitions
* 
*         [×] int  *p, q  // Unexpected Result: this expression means "Define Pointer '*p' and int 'q'."
*         
*         ＊Substitute
*         ・'&': <Address operator>: Get the address (not the value) of following variable.
*                Pointer is expressed to substitute address by adding '&' to the value.
*         ・'*': <Redirect operator>: Set the value to the variable which Pointer is having its address.
*                Pointer is expressed to substitute the value to the variable of the having its address by adding '*' to the variable name.
* 
*         [Example]
*         x = 123;  // substitute value '123' to variable 'x'.
*         p = &x;   // substitute address of 'x' to variable 'p'.
*         *p = 123; // <=>  [ p = &x  ->  x = 123 ]
*                   //substitute value '123' to the variable which Pointer is having its address. 
*                      
*         [×] p = x;    //Compile Error: this espression means "Substitute the value of int variable 'x' to Pointer variable 'x' ".
*         [×] p = 123;  //Compile Error: this espression means "Substitute int value '123' to Pointer variable 'x' ".
* 
*         ＊Refer
*         [Example] 
*         printf("%d \n", x);   // show the value of int 'x'
*         printf("%p \n", p);   // show the address value which Pointer is having. 
*         printf("%d \n", *p);  // show the value of the variable which Pointer is having its address.
*                               // 【Notation】the format use '%d' because the variable 'x' ,indicated by Pointer, is int type.
* 
*@subject ◆NULL Pointer 〔C99YH p364〕
*         <stdio.h> => INDEX〔C99YH12_FileOperation/MainFileOpenInputSample.c〕
*            └ #define NULL 0
*
*         ・'NULL': A symbol meaning "nothing of reference".
*         ・NULL Pointer: Pointer can be assigned '0'.  0 means NULL.
*         ・NULL Pointer is used to express end of link, when Liner List or Tree Data Structure.
*         ・You can assign NULL to any Pointer.
*         ・You cannot assign any value to NULL Pointer
*         ・You cannot refer to value of NULL Pointer.
*         ・NULL Check: Before operate 'p', it is necessary to check if p is NULL or not.
* 
*         [Example]
*         int *p;
*         p = NULL;
* 
*         [×] *p = 123;  -> Compile Error: NULL pointer assignment,
*                          -> or output unexpected value, or do unexpeted behavior,
*                          -> or enforcely exited by OS.
* 
*         [×] printf("%p \n", p);  // when 'p = NULL'
* 
*         [Example] NULL Check
*         if (p != NULL) {
*             // write operation: assginment or reference, about 'p' here.
*         }
* 
*         => copy to〔C99YH12_FileOperation/MainFileOpenInputSample.c〕
* 
*@subject <string.h>
*            └ int  strlen(char*)
* 
*         [Contents]
*         int strlen(char *str) {
*             int len = 0;           // Define length valiable 'len' and Initialize as 0.
*             char *s = str;         // Define 's' as char type Pointer 
*                                    // and Substitute the function-argument 'str' value to 's' indicated by Pointer.
*  
*             while (*s != '\0') {   // continue to read each characters until the value of '*s' is '\0'. ('*s' is not address, but value had substituted 'str')
*                 len++;             // increment counting length
*                 s++;               // increment address of 's'
*             }//while
*         
*             return len;            // return length value which have counted.
*          }
* 
*@subject Quiz 10-1  
*         Defining 'score' as double type,
*         Define 'ptr' as Pointer which indicate the 'score'.
*
*         [My Answer]
*         double socre;
*         double ptr = &score;
*         ([or] double *ptr = score; )
* 
*         => Wrong
* 
*         [Book Answer]
*         double *ptr = &score;  // Define Pointer 'ptr' and Inialized by '&score' address.
*           or
*         double *ptr;
*         *ptr = &score;
* 
*@subject Quiz 10-2
*         Pointer 'p' and 'q' are defined as indicating same variable.
*         When Pointer 'p' indicate one variable, What do you describe meaning "Pointer 'q' is too" ?
* 
*         [My Answer] assuming one variable as int x.
*         int x;
*         int *p, *q;
*         p = q = &x;
* 
*         => Correct
* 
*         [Book Answer]
*         q = p;
* 
*@subject Quiz 10-3
*         Defining 'p' , 'q' as int type Pointer, which indicate each variables,
*         What do you describe meaning "show the value indicated by 'p','q' -- by using 'printf()' " ?
* 
*         [My Answer]
*         int *p, *q;
*         printf("p: %d | q: %d | p + q = %d \n", *p, *q, *p + *q);
* 
*         => Correct
*     
*@see
*@author shika
*@date 2022-12-31
*/

#include <stdio.h>

//int main(void) {
int mainPointerBasic(void) {
    //---- Quiz 10-1 ----
    int score = 100;
    int *p = &score;

    //----Quiz 10-2 ----
    int *q;
    q = p;
    printf("Pointer Address:  p = %p | q = %p \n", p, q);

    //----Quiz 10-3 ----
    int scoreQ = 24;
    q = &scoreQ;

    printf("p: %d | q: %d | p + q = %d \n", *p, *q, *p + *q);

    return 0;
}//main()

/*
//====== Result ======
printf("Pointer Address:  p = %p | q = %p \n", p, q);
 -> Pointer Address:  p = 00D7FBF4 | q = 00D7FBF4

printf("p: %d | q: %d | p + q = %d \n", *p, *q, *p + *q);
 -> p: 9436040 | q: 9436040 | p + q = 18872080

【Analysis】
It showed the address value of p, q. (unexpected result)
These addresses are different values each times.

=> I modified '*q = &scoreQ;' -> 'q = &scoreQ;' and then it solved 〔below〕
   Probably, 'q = p;' at previous rows seems to effect the result changing.

Pointer Address:  p = 006FFB9C | q = 006FFB9C
p: 100 | q: 24 | p + q = 124         (expected result)

*/