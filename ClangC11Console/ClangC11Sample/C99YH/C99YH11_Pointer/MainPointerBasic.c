/**
*@directory ClangC11Console / ClanC11Sample / C99YH / C99YH11_Pointer
*@fileName  MainPointerBasic.c
*@reference C99YH  Œ‹é _ wCŒ¾ŒêƒvƒƒOƒ‰ƒ~ƒ“ƒOƒŒƒbƒXƒ“ [“ü–å•Ò] ‘æ‚R”ÅxSB Creative, 2019
*@reference CAnsi  Œ‹é _ wCŒ¾ŒêƒvƒƒOƒ‰ƒ~ƒ“ƒOƒŒƒbƒXƒ“ [•¶–@•Ò] V”Åx  SB Creative, 2006
*@reference C11DS  arton  w“ÆK C V”ÅxãÄ‰jĞ, 2018
*
*@content C99YH ‘æ11Í Pointer | Chapter 11 / List - / p343
*@summary MainPointerBasic.c
*@English [E] assign:     Š„‚è“–‚Ä‚éA‘ã“ü‚·‚é
*         [E] substitute: ‘ã“ü‚·‚éA“ü‚ê‘Ö‚¦‚é
*         [E] indicate:   w‚µ¦‚·
* 
*@subject ¡ Pointer
*         Pointer: The variable which indicate address of the other variable.
*                  Therefore, it called "pointer" which indicates something.
*
*         –Define
*         E'*': Pointer is defined by adding '*' before the Variable name.
* 
*         [Example]
*         int  x;      // definition of int type 
*         int  *p;     // definition of pointer to int type
*         int  *p, *q; // multiple definitions
* 
*         [~] int  *p, q  // Unexpected Result: this expression means "Define Pointer '*p' and int 'q'."
*         
*         –Assignment
*         E'&': <Address operator>: Get the address (not the value) of following variable.
*                Pointer is expressed to assign address by adding '&' to the value.
*         E'*': <Redirect operator>: Set the value to the variable which Pointer is having its address.
*                Pointer is expressed to assgn the value to the variable of the having its address by adding '*' to the variable name.
* 
*         [Example]
*         x = 123;  // substitute value '123' to variable 'x'.
*         p = &x;   // substitute address of 'x' to variable 'p'.
*         *p = 123; // <=>  [ p = &x  ->  x = 123 ]
*                   //substitute value '123' to the variable which Pointer is having its address. 
*                      
*         [~] p = x;    //Compile Error: this expression means "Assign the value of int variable 'x' to Pointer variable 'x' ".
*         [~] p = 123;  //Compile Error: this expression means "Assgin int value '123' to Pointer variable 'x' ".
* 
*         –Refer
*         [Example] 
*         printf("%d \n", x);   // show the value of int 'x'
*         printf("%p \n", p);   // show the address value which Pointer is having. 
*         printf("%d \n", *p);  // show the value of the variable which Pointer is having its address.
*                               // yAnnotationzthe format use '%d' because the variable 'x' ,indicated by Pointer, is int type.
* 
*@subject ŸNULL Pointer kC99YH p364lkCAnsi p110lkCAnsiYH06_Pointer\Reference_CAnsiPointer.txtl
          <stdio.h> => INDEXkC99YH12_FileOperation/MainFileOpenInputSample.cl
             „¤ #define NULL 0

          NULL Pointer:
           EThe constant value which indicate nowhere. It means no reference.
           EThe constant value is often defined as '0', depending on Compiler,
             so that Conditional Expression 'if(NULL)' is false.

             [Example]
             FILE *fp = fopen(...);
             if(!fp) { ... }         // as same as 'if(fp == NULL)'
             if(fp)  { ... }         // as same as 'if(fp != NULL)'

           EWe cannot refer and assign to address of NULL Pointer.
             If we would do, we will be thrown Runtime Error,
             because Compiler cannot find address which NULL Pointer indicate,
             as like NullPointerException in [Java][C#].

           EWe can assign NULL to any Pointer, that means no reference or to delete the already reference.
           EWe can assign 0    to any Pointer, that means to assgin NULL.
           ENULL Check: Before we operate 'p', it is necessary to check if p is NULL or not.

            [Example]
            int *p;
            p = NULL;

            [~] *p = 123;  -> Runtime Error: NULL pointer assignment,
                           -> or output unexpected value, or do unexpeted behavior,
                           -> or enforcely exited by OS.

            [~] printf("%p \n", p);  // when 'p = NULL'

            [Example] NULL Check
            if (p != NULL) {
                // write operation: assginment or reference, about 'p' here.
            }

         EThe reason why NULL Pointer is necessary:
             Because Compiler can tell Error of Function to Programmer, as NULL Pointer,
             when we use Function whose Return-Type is Pointer Type, such as that:
               Function 'FILE* fopen( ... )' which open a file of argument, whose Return-Type is FILE Pointer 'FILE*',
               if 'fopen()' cannot open the file, it return NULL Pointer.
               Function 'void* malloc()' which take a space in Memory, whose Return-Value is General Pointer 'void*',
               if 'malloc()' cannot take a space in Memory, it return NULL Pointer.
            Because NULL Pointer is used to express end of link,
            when we use Liner List or Tree Data Structure.

           EDon't confuse and identify NULL Pointer, Empty-String "" and NULL Character '\0',
             these are different things.

          => copy to/from kCAnsiYH06_Pointer\Reference_CAnsiPointer.txtl

*@subject <string.h>
*            „¤ int  strlen(char*)
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

yAnalysisz
It showed the address value of p, q. (unexpected result)
These addresses are different values each times.

=> I modified '*q = &scoreQ;' -> 'q = &scoreQ;' and then it solved kbelowl
   Probably, 'q = p;' at previous rows seems to effect the result changing.

Pointer Address:  p = 006FFB9C | q = 006FFB9C
p: 100 | q: 24 | p + q = 124         (expected result)

*/