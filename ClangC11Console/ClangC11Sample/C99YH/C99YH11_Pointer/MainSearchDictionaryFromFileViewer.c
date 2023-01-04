/**
*@directory ClangC11Console / ClanC11Sample / C99YH / C99YH11_Pointer
*@fileName  MainSearchDictionaryFromFileViewer.c
*@reference C99YH    結城 浩 『C言語プログラミングレッスン [入門編] 第３版』SB Creative, 2019
*@reference CAnsiYH  結城 浩 『C言語プログラミングレッスン [文法編] 新版』  SB Creative, 2006
*@reference C11DS    arton  『独習 C 新版』翔泳社, 2018
*
*@content C99YH 第11章 Pointer | Chapter 11 / List 11-2 / p369
*@summary Search Dictionary from [.txt] file
*         This program wait user to input English word ,search it from dictionary [.txt] file,
*         and output the search-word, the Japanese meaning.
* 
*@English [英] verify:       検証する、確かめる
*         [英] equivalence:  等価
*         [英] equality:     平等 
* 
*@subject ◆Requirement Definition / 要件定義
*         ・(above)
* 
*         ＊Prepare: [11dictionary.txt]
*         Deploy '11dictionary.txt' in same directory.
*         The file can be copied from Publisher Web page.
* 
*         ＊Execute: [Windows Command Prompt for VS2019]
*         >cd (current directory)
*         >cl MainSearchDictionaryFromFileViewer.c
*         >MainSearchDictionaryFromFileViewer 11dictionary.txt xxxx
*             [Command Line Argument] 
*             11dictionary.txt:  dictionary file
*             xxxx:              search word
*
*         ＊【Notation】for [Windows Command Prompt for VS2019] Execution
*         ・To execute correctly, this code need be substituted two parts of commnt-out.
*           Row 177: fopen_s() -> fopen()
*           Row 224: sscanf_s() -> sscanf()
* 
*@subject int  main(int argc, char* argv[]) 
*         ◆Entry Point
*         ・Validate Command Line Argument
*         ・Local Variable Definition
*             FILE* fileP       // Pointer of dictionary file
*             char* dicFile     // Parse from Command Line Argument
*             char* searchWord  // Parse from Command Line Argument
*         ・Open dictionary file
*         ・Read dictionary file
*         ・Search & Output
* 
*@subject int  loadDictionary(FILE* fileP) //self-defined
*         ・Load the data from dictionary file given by Command Line Argument.
*         ・[Argument] FILE* fileP: Pointer of dictionary file defined in 'main()'.
*         ・[Return]   int   over 0: return correctly the number of loaded words.
*                           -1:      return uncorrectly to happen load error. 
* 
*@subject <stdlib.h> ?
*            └ #define stdin   // = strndard input
*            └ #define stdout  // = standard output
*            └ #define stderr  // = standard error
*            |
*        [×] └ FILE*  fopen(const char _FileName, const char _Mode)  // = file open
*                [Argument]
*                const char _FileName:  
*                const char _Mode:
* 
*            └ FILE*  fopen_s(FILE* _Stream, const char _FileName, const char _Mode)
* 
*            └ int    fprintf(FILE* _Stream, const char* _Format, T ... value);
*                [Argument]
*                FILE* _Stream:        // in this case: 'stderr'
*                const char* _Format,  // as same as 'printf()'
*                T ... value:          // as same as 'printf()'
* 
*            └ int    fclose(FILE* _Stream)  // = file close
*                [Argument]
*                FILE* _Stream:        // in this case: 'stderr'
* 
*@subject Compare both String texts 〔C99YH p374〕
*         ・[×] To compare String or to verify equivalence, you cannot use operator '==' as like [str == "Hello"].
*         ・so need 'strcmp()' below.
* 
*         <string.h>  
*            └ int  strcmp(const char* _Str1, const char* _Str2)  // = string compare
*                [Argument]
*                const char* _Str1:
*                const char* _Str2:
* 
*                [Return] 0:     equal in dicionary order
*                         plus:  first argument is former of dictionary order than second one.
*                         minus: first argument is latter of dictionary order than second one.
* 
*@NOTE【Compile Error】in clang of VS2019 Execution
*      C4996 'fopen':
*      This function or variable may be unsafe. 
*      Consider using fopen_s instead. 
*      To disable deprecation, use _CRT_SECURE_NO_WARNINGS.
*      See online help for details.
*      ClangC11Console:	C:\...\C99YH11_Pointer\MainSearchDictionaryFromFileViewer.c	138	
*
*      => No problem to execute by [Windows Command Prompt for VS2019]
*      => In Temporary to prevent Compile Error for another Code,
*         I modified 'fileP = fopen(dicFile, "r");'
*         -> 'fileP = fopen_s(stdin, dicFile, "r");'
* 
*@NOTE【Compile Error】in clang of VS2019 Execution
*      C4996 'sscanf':
*      This function or variable may be unsafe.
*      Consider using sscanf_s instead. 
*      To disable deprecation, use _CRT_SECURE_NO_WARNINGS.
*      See online help for details.
*      ClangC11Console:	C:\...\C99YH11_Pointer\MainSearchDictionaryFromFileViewer.c	197	
*
*      => No problem to execute by [Windows Command Prompt for VS2019]
*      => In Temporary to prevent Compile Error for another Code,
*         I modified 'sscanf()' -> 'sscanf_s()'.
*         
*@NOTE【Warning】in clang of VS2019 Execution
*      ・警告C6054 文字列 'englishBuffer' は 0 で終了しない可能性があります。
*      ・警告C6054 文字列 'japaneseBuffer' は 0 で終了しない可能性があります。
*      => I modified adding 'if (englishBuffer != 0 && ...) '
* 
*@see
*@author shika
*@date 2023-01-03, 01-04
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//====== Define constant ======
#define BUFFER_SIZE 256
#define DIC_MAX 100
#define ENGLISH_SIZE 50
#define JAPANESE_SIZE 50

char *usage[] = {
    "Name: ", "-- Search Dictionary Viewer --",
    "Format: ", ">MainSearchDictionaryFromFileViewer (dictionary file) (search word)",
    "Description: ",
    "This program wait to input English word ,",
    "search it from dictionary[.txt] file,",
    "and output the searched word, the Japanese meaning.",
    "[Dictionary Example]",
    "  dictionary 辞書",
    "  English 英語",
    "  foreign 外国の",
    "  home 家",
    "  end 終了",
    "Author: ", "結城浩",
    "Copyright (C) 1994, 2018 by YUUKI Hiroshi", 
    NULL,
};

//====== Struct Declaration ======
typedef struct wordPair {
    char englishWord[ENGLISH_SIZE];
    char japaneseWord[JAPANESE_SIZE];
} PAIR;

//====== Global Variable ======
PAIR dicAry[DIC_MAX];
int dicSize = 0;

//====== Prototype Declaration ======
int loadDictionary(FILE*);

//====== Function Definition ======
//int main(int argc, char* argv[]) {
int mainSearchDictionaryFromFileViewer(int argc, char* argv[]) {

    //---- Validate Command Line Argument ----
    if (argc != 3) {
        printf("<！> Execution Error: Invalid Argument.\n");

        for (int i = 0; usage[i] != NULL; i++) {
            printf("%s \n", usage[i]);
        }//for

        return 0;
    }

    //---- Local Variable Definition -----
    FILE* fileP;  //Pointer of dictionary file
    char* dicFile = argv[1];
    char* searchWord = argv[2];

    //---- Open Dictionary File ----
    //fileP = fopen(dicFile, "r");        //for [Windows Command Prompt for VS2019] Execution
    fileP = fopen_s(stdin, dicFile, "r"); //in temporary for another Compile. This could output unexpectedly.

    if (fileP == NULL) {
        fprintf(stderr, 
            "Not Found Dictionary File [%s]. \n",
            dicFile);
    
        return -1;
    }

    //---- Read Dictionary File ----
    if (loadDictionary(fileP) < 0) {
        fprintf(stderr,
            "Load File Error in Dictionary File [%s]. \n",
            dicFile);
        fclose(fileP);

        return -1;
    }

    //---- Search & Output ----
    for (int i = 0; i < dicSize; i++) {
        if (strcmp(dicAry[i].englishWord, searchWord) == 0) {
            printf("Search Word: %s | Meaning: %s \n", searchWord, dicAry[i].japaneseWord);
        }
    }//for

    return 0;
}//main()

int loadDictionary(FILE* fileP) {
    char buffer[BUFFER_SIZE];
    char englishBuffer[ENGLISH_SIZE];
    char japaneseBuffer[JAPANESE_SIZE];

    //---- Load Dictionary File ----
    dicSize = 0;

    while (fgets(buffer, BUFFER_SIZE, fileP) != NULL) {
        if (dicSize >= DIC_MAX) {
            fprintf(stderr, "<！> Too much to load words. [MAX: %d ] \n", DIC_MAX);
            fclose(fileP);
            return -1;
        }

        //---- Parse Dictinary Data using 'sscanf()' ----
        //int num = sscanf(buffer, "%s %s\n",   
        //    englishBuffer, japaneseBuffer);   //for [Windows Command Prompt for VS2019] Execution
        int num = sscanf_s(buffer, "%s %s\n",   
            englishBuffer, japaneseBuffer);     //in temporary for another Compile.

        if (num != 2) {
            fprintf(stderr, "<！> Invalid Format in row %d.\n", dicSize + 1);  // +1: index -> row number
            fprintf(stderr, "%s\n", buffer);
            return -1;
        }

        //---- Check English word length to prevent Overflow ----
        if (englishBuffer != 0 && strlen(englishBuffer) + 1 > ENGLISH_SIZE) {   // +1: '\0'
            fprintf(stderr, "Too long English word in %d row.\n", dicSize + 1); // +1: array index -> row number
            fprintf(stderr, "[MAX %d Byte] \n", ENGLISH_SIZE - 1);              // -1: '\0'
            return -1;
        }

        //---- Copy English word ----
        strcpy_s(dicAry[dicSize].englishWord, ENGLISH_SIZE, englishBuffer);

        //---- Check Japanese word length to prevent Overflow ----
        if (japaneseBuffer != 0 && strlen(japaneseBuffer) + 1 > ENGLISH_SIZE) {                 // +1: '\0'
            fprintf(stderr, "Too long Japanese word in %d row.\n", dicSize + 1);  // +1: array index -> row number
            fprintf(stderr, "[MAX %d Byte] \n", JAPANESE_SIZE - 1);      // -1: '\0'
            return -1;
        }

        //---- Copy Japanese word ----
        strcpy_s(dicAry[dicSize].japaneseWord, JAPANESE_SIZE, japaneseBuffer);

        //---- increment ----
        dicSize++;
    }//while

    return dicSize;
}//loadDictionary()

/*
//###### Appendix ######
//====== 11dictionary.txt ======
>type 11dictionary.txt

dictionary 辞書
English 英語
foreign 外国の
home 家
end 終了

//====== Execute: [Windows Command Prompt for VS2019] =======
>cd C:\...\C99YH\C99YH11_Pointer
>cl MainSearchDictionaryFromFileViewer.c

MainSearchDictionaryFromFileViewer.c
/out:MainSearchDictionaryFromFileViewer.exe
MainSearchDictionaryFromFileViewer.obj

>MainSearchDictionaryFromFileViewer 11dictionary.txt home

//====== Result ======
Search Word: home | Meaning: 家

//---- Test Invalid Format Execution ----
>MainSearchDictionaryFromFileViewer

<！> Execution Error: Invalid Argument.
Name:
-- Search Dictionary Viewer --
Format:
>MainSearchDictionaryFromFileViewer (dictionary file) (search word)
Description:
This program wait to input English word ,
search it from dictionary[.txt] file,
and output the searched word, the Japanese meaning.
[Dictionary Example]
  dictionary 辞書
  English 英語
  foreign 外国の
  home 家
  end 終了
Author:
結城浩
Copyright (C) 1994, 2018 by YUUKI Hiroshi
*/