/**
*@directory ClangC11Console / ClanC11Sample / C99YH / C99YH11_Pointer
*@fileName  MainSearchDictionaryFromFileViewer.c
*@reference C99YH    åãèÈ ç_ ÅwCåæåÍÉvÉçÉOÉâÉ~ÉìÉOÉåÉbÉXÉì [ì¸ñÂï“] ëÊÇRî≈ÅxSB Creative, 2019
*@reference CAnsiYH  åãèÈ ç_ ÅwCåæåÍÉvÉçÉOÉâÉ~ÉìÉOÉåÉbÉXÉì [ï∂ñ@ï“] êVî≈Åx  SB Creative, 2006
*@reference C11DS    arton  Åwì∆èK C êVî≈Åx„ƒâjé–, 2018
*
*@content C99YH ëÊ11èÕ Pointer | Chapter 11 / List 11-2 / p369
*@summary Search Dictionary from [.txt] file
*         This program wait user to input English word ,search it from dictionary [.txt] file,
*         and output the search-word, the Japanese meaning.
* 
*@English [âp] verify:       åüèÿÇ∑ÇÈÅAämÇ©ÇﬂÇÈ
*         [âp] equivalence:  ìôâø
*         [âp] equality:     ïΩìô 
* 
*@subject ÅüRequirement Definition / óvåèíËã`
*         ÅE(above)
* 
*         ÅñPrepare: [11dictionary.txt]
*         Deploy '11dictionary.txt' in same directory.
*         The file can be copied from Publisher Web page.
* 
*         ÅñExecute: [Windows Command Prompt for VS2019]
*         >cd (current directory)
*         >cl MainSearchDictionaryFromFileViewer.c
*         >MainSearchDictionaryFromFileViewer 11dictionary.txt xxxx
*             [Command Line Argument] 
*             11dictionary.txt:  dictionary file
*             xxxx:              search word
*
*         ÅñÅyNotationÅzfor [Windows Command Prompt for VS2019] Execution
*         ÅETo execute correctly, this code need be substituted two parts of commnt-out.
*           Row 177: fopen_s() -> fopen()
*           Row 224: sscanf_s() -> sscanf()
* 
*@subject int  main(int argc, char* argv[]) 
*         ÅüEntry Point
*         ÅEValidate Command Line Argument
*         ÅELocal Variable Definition
*             FILE* fileP       // Pointer of dictionary file
*             char* dicFile     // Parse from Command Line Argument
*             char* searchWord  // Parse from Command Line Argument
*         ÅEOpen dictionary file
*         ÅERead dictionary file
*         ÅESearch & Output
* 
*@subject int  loadDictionary(FILE* fileP) //self-defined
*         ÅELoad the data from dictionary file given by Command Line Argument.
*         ÅE[Argument] FILE* fileP: Pointer of dictionary file defined in 'main()'.
*         ÅE[Return]   int   over 0: return correctly the number of loaded words.
*                           -1:      return uncorrectly to happen load error. 
* 
*@subject <stdlio.h> => INDEXÅkC99YH12_FileOperation/MainFileOpenInputSample.cÅl
*            Ñ§ #define stdin   // = strndard input
*            Ñ§ #define stdout  // = standard output
*            Ñ§ #define stderr  // = standard error
*            |
*        [Å~] Ñ§ FILE*  fopen(const char _FileName, const char _Mode)  // = file open
*                [Argument]
*                const char _FileName:  
*                const char _Mode:
* 
*            Ñ§ errno_t  fopen_s(FILE* _Stream, const char _FileName, const char _Mode)
* 
*            Ñ§ int    fprintf(FILE* _Stream, const char* _Format, T ... value);
*                [Argument]
*                FILE* _Stream:        // in this case: 'stderr'
*                const char* _Format,  // as same as 'printf()'
*                T ... value:          // as same as 'printf()'
* 
*            Ñ§ int    fclose(FILE* _Stream)  // = file close
*                [Argument]
*                FILE* _Stream:        // in this case: 'stderr'
* 
*@subject Compare both String texts ÅkC99YH p374Ål
*         ÅE[Å~] To compare String or to verify equivalence, you cannot use operator '==' as like [str == "Hello"].
*         ÅEso need 'strcmp()' below.
* 
*         <string.h>  
*            Ñ§ int  strcmp(const char* _Str1, const char* _Str2)  // = string compare
*                [Argument]
*                const char* _Str1:
*                const char* _Str2:
* 
*                [Return] 0:     equal in dicionary order
*                         plus:  first argument is former of dictionary order than second one.
*                         minus: first argument is latter of dictionary order than second one.
* 
*@NOTEÅyCompile ErrorÅzin clang of VS2019 Execution
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
*@NOTEÅyCompile ErrorÅzin clang of VS2019 Execution
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
*@NOTEÅyWarningÅzin clang of VS2019 Execution
*      ÅEåxçêC6054 ï∂éöóÒ 'englishBuffer' ÇÕ 0 Ç≈èIóπÇµÇ»Ç¢â¬î\ê´Ç™Ç†ÇËÇ‹Ç∑ÅB
*      ÅEåxçêC6054 ï∂éöóÒ 'japaneseBuffer' ÇÕ 0 Ç≈èIóπÇµÇ»Ç¢â¬î\ê´Ç™Ç†ÇËÇ‹Ç∑ÅB
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
    "  dictionary é´èë",
    "  English âpåÍ",
    "  foreign äOçëÇÃ",
    "  home â∆",
    "  end èIóπ",
    "Author: ", "åãèÈç_",
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
        printf("<ÅI> Execution Error: Invalid Argument.\n");

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
            fprintf(stderr, "<ÅI> Too much to load words. [MAX: %d ] \n", DIC_MAX);
            fclose(fileP);
            return -1;
        }

        //---- Parse Dictinary Data using 'sscanf()' ----
        //int num = sscanf(buffer, "%s %s\n",   
        //    englishBuffer, japaneseBuffer);   //for [Windows Command Prompt for VS2019] Execution
        int num = sscanf_s(buffer, "%s %s\n",   
            englishBuffer, japaneseBuffer);     //in temporary for another Compile.

        if (num != 2) {
            fprintf(stderr, "<ÅI> Invalid Format in row %d.\n", dicSize + 1);  // +1: index -> row number
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

dictionary é´èë
English âpåÍ
foreign äOçëÇÃ
home â∆
end èIóπ

//====== Execute: [Windows Command Prompt for VS2019] =======
>cd C:\...\C99YH\C99YH11_Pointer
>cl MainSearchDictionaryFromFileViewer.c

MainSearchDictionaryFromFileViewer.c
/out:MainSearchDictionaryFromFileViewer.exe
MainSearchDictionaryFromFileViewer.obj

>MainSearchDictionaryFromFileViewer 11dictionary.txt home

//====== Result ======
Search Word: home | Meaning: â∆

//---- Test Invalid Format Execution ----
>MainSearchDictionaryFromFileViewer

<ÅI> Execution Error: Invalid Argument.
Name:
-- Search Dictionary Viewer --
Format:
>MainSearchDictionaryFromFileViewer (dictionary file) (search word)
Description:
This program wait to input English word ,
search it from dictionary[.txt] file,
and output the searched word, the Japanese meaning.
[Dictionary Example]
  dictionary é´èë
  English âpåÍ
  foreign äOçëÇÃ
  home â∆
  end èIóπ
Author:
åãèÈç_
Copyright (C) 1994, 2018 by YUUKI Hiroshi
*/