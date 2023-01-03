/**
*@directory ClangC11Console / ClanC11Sample / C99YH / C99YH11_Pointer
*@fileName  MainSearchDictionaryFromFileViewer.c
*@reference C99YH  結城 浩 『C言語プログラミングレッスン [入門編] 第３版』SB Creative, 2019
*@reference CAnsi  結城 浩 『C言語プログラミングレッスン [文法編] 新版』  SB Creative, 2006
*@reference C11DS  arton  『独習 C 新版』翔泳社, 2018
*
*@content C99YH 第11章 Pointer | Chapter 11 / List 11-2 / p369
*@summary Search Dictionary from [.txt] file
*         This program wait user to input English word ,search it from dictionary [.txt] file,
*         and output the search-word, the Japanese meaning.
* 
*@English
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
*@subject int  main(int argc, char argv[]) 
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
*         (Editing...)
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
*@subject <string.h>
*            └ int  strcmp(const char* _Str1, const char* _Str2)  // = string compare
*                [Argument]
*                const char* _Str1:
*                const char* _Str2:
*
*@NOTE【Compile Error】in clang of VS2019
*      C4996 'fopen':
*      This function or variable may be unsafe. 
*      Consider using fopen_s instead. 
*      To disable deprecation, use _CRT_SECURE_NO_WARNINGS.
*      See online help for details.
*      ClangC11Console:	C:\...\C99YH11_Pointer\MainSearchDictionaryFromFileViewer.c	138	
* 
*@see
*@author shika
*@date 2023-01-03
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//====== Define constant ======
#define BUFFER_SIZE 256
#define DIC_SIZE 100
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
PAIR dicAry[DIC_SIZE];
int dicSize = 0;

//====== Prototype Declaration ======
int loadDictionary(FILE*);

//====== Function Definition ======
int main(int argc, char argv[]) {
//int mainSearchDictionaryFromFileViewer(void) {

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
    fileP = fopen_s(stdin, dicFile, "r");

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

//====== Result ======

*/