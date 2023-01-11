/**
*@directory ClangC11Console / ClanC11Sample / C99YH / C99YH03_Variable
*@fileName  MainConsoleInputSample.c
*@reference C99YH  Œ‹é _ wCŒ¾ŒêƒvƒƒOƒ‰ƒ~ƒ“ƒOƒŒƒbƒXƒ“ [“ü–å•Ò] ‘æ‚R”ÅxSB Creative, 2019
*@reference CAnsi  Œ‹é _ wCŒ¾ŒêƒvƒƒOƒ‰ƒ~ƒ“ƒOƒŒƒbƒXƒ“ [•¶–@•Ò] V”Åx  SB Creative, 2006
*@reference C11DS  arton  w“ÆK C V”ÅxãÄ‰jĞ, 2018
*
*@content C99YH ‘æ‚RÍ •Ï” | Chapter 3 Variable / List 3-5 / p71
*@summary Console Input
*         E#define Directive
*         E<stdio.h> => INDEXkC99YH12_FileOperation/MainFileOpenInputSample.cl
*             „¤ #define stdin
*             „¤ #define stdout
*             „¤ char*  fgets(char *_Buffer, int _MaxCount, FILE _Stream)
* 
*         E<stdlib.h>
*             „¤ int    atoi(const char *_String)
*             „¤ double atof(const char *_String)
* 
*         EArray
*
*@subject #define 
*           Directive: order to Preprocessor, which operate before Compile.
*                      it is described with prefix "#".
*           #define:   definition of constant value, 
*                      it is described as whole Upper case and under bar "_".
*          yNOTEz    [~] don't describe: Type, "=", ";" (if existed, be thrown compile error)
* 
*           [Example]  #define BUFFER_SIZE 256
* 
*@subject <stdio.h> => INDEXkC99YH12_FileOperation/MainFileOpenInputSample.cl
*            „¤ #define stdin  (= Standard Input)   //It usually means "input by key board", can be changed by 'fgets()' Redirect Operation.
*            „¤ #define stdout (= Standard Output)  //It usually means "output to Console", can be changed by 'fgets()' Redirect Operation.
*            „¤ char*  fgets(char *_Buffer, int _MaxCount, FILE _Stream)
*
*@subject <stdlib.h>
*            L int    atoi(const char *_String)    //It convert type 'char[]' as numeric string text to 'int'.
*            „¤ float  atof(const char *_String)    //It convert type 'char[]' as numeric string text to 'float'
*
*@subject Function fgets()  File Get String kC99YH p73, p401l
*           EStandard Input (= Console Input as default)
*           EIf 'Redirect', the Standard Input can be changed to File Input. 
*                =>kC99YH12_FileOperation/MainFileCopyStringViewer.cl
*           E'\0': NULL Character  // It express the termination of String text. 
*           ENULL:                 // It express no reference or NULL Pointer, defined in <stdio.h>.
* 
*         char*  fgets(const char *_Buffer, int _MaxCount, FILE _Stream)
*         
*         [Argument]
*         char* _Buffer:  Pointer of 'char' Array which storage one line of file contents,
*         (as contatnt)   The Array size is required over the value of second argument 'int _MaxCount'.
* 
*         int _MaxCount:  maximum Bytes + 1 of buffer size to read line. +1 is for '\0' NULL character.
* 
*         FILE* _Stream:  EPointer of file to read, which need be open by 'fopen()' with Mode "r" as to read, before this operation.
*                         E[Redirect] Instead of Pointer of file, you can set 'stdin' defined in <stdio.h> as standard input (= usually Console input from Key Board).
* 
*         [Return]
*         char*: Pointer of buffer array which was given by argument, and storaged file contents.
*                or NULL Pointer when it reached 'EOF'.
* 
*         [Behavior] in case of File Pointer:
*         When execute 'fgets(), it reads charaters from File Pointer, and storages them to buffer array.
*         If it reads '\n' Line Feed Character, it adds '\0' NULL Character as end of string text, to buffer array.
*         If it reads (maximum Bytes - 1) before '\n', it stop to read file and add \0'.
*         Then it returns Pointer of the buffer array.
*         If it has already finish to read, it returns 'NULL' Pointer.
* 
*         [Example]
*         char* inputP = fgets(buffer, bufferSize, stdin);
*         while (inputP != NULL) { ... }
*
*         while (fgets(buffer, bufferSize, stdin) != NULL) { ... }
*
*         => copy tokC99YH12_FileOperation\MainFileOpenInputSample.cl
* 
*@subject Function atoi()  ASCII to Integer 
*           EIt change Strings to Integer
* 
*         int    atoi(const char *_String)
* 
*@subject Array kChapter 9l
* 
*@see
*@author shika
*@date 2022-12-12
*/

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 256

void consoleInput(char* buffer, int bufferSize); //self defined

int mainConsoleInputSample(void) {
    char buffer[BUFFER_SIZE];
    int age;

    printf("Please input your name. > ");
    consoleInput(buffer, BUFFER_SIZE);
    printf("Hello, %s.\n", buffer);
    printf("\n");
    
    printf("Please input your age. > ");
    consoleInput(buffer, BUFFER_SIZE);
    age = atoi(buffer);
    printf("Now, you are %d years old, \nafter decade year, you will be %d.\n", age, age + 10);

    return 0;
}//main()

//====== already defined in C99YH08_Function\DividedCompile_consoleInputBody.c ======
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
Please input your name. > sophia
Hello, sophia.

Please input your age. > 24
Now, you are 24 years old,
after decade year, you will be 34.

//---- Trial of Invalid Input ----
Please input your name. >
Hello, .

Please input your age. > age
Now, you are 0 years old,
after decade year, you will be 10.

yAnalysisz
 Eif name were empty input, it show user name as "" empty .
 Eif age were not numeric input, Function 'int  atoi(char*)' return 0.

 */