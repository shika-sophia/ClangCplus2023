/**
*@directory ClangC11Console / ClanC11Sample / C99YH / C99YH12_FileOperation
*@fileName  MainFileCopyConsoleInputViewer.c
*@based     MainFileOpenInputSample.c
*@reference C99YH    結城 浩 『C言語プログラミングレッスン [入門編] 第３版』SB Creative, 2019
*@reference CAnsiYH  結城 浩 『C言語プログラミングレッスン [文法編] 新版』  SB Creative, 2006
*@reference C11DS    arton  『独習 C 新版』翔泳社, 2018
*
*@content C99YH 第12章 FileOperation | Chapter 12 / List 12-2 / p395
*@summary File Copy -- Console Input Version --
*@English [英] translation: 翻訳
*         [英] abbreviation: 省略、短縮
* 
*@subject ◆Execute Procedure
*         ・Copy the file name as relative path [ ..\\C99YH07_WhileIteration\\lorem.txt ].
*         ・Copy the file name [ loremCopy.txt ], which will be created to save in this directory.
*         ・Change comment-out of 'main()' to active.
*         ・Change comment-out of 'consoleInput()' definition to active.
*         ・Change comment-out of 'fopen()' to active and 'fopen_s()' to negative in From-File and To-File.
*         ・Execute by [Windows Command Prompt for VS2019]
*           (because, executed by Visual Studio, it throws Compile Error by cause of 'fopen() unsafe'.)
*         ・It asks file names ,and then Paste the file names and [Enter] Key.
*         ・(Return back whole of changes for another Compile, after execution here.)
* 
*@subject <stdio.h>  =>〔MainFileOpenInputSample.c〕
*            └ #define FILENAME_MAX 260  
*            └ int  fgetc(FILE*) 
*            └ int  fputc(int c, FILE*)
*            └ int  fclose(FILE*) 
*
*subject ◆Terminal-Command to Compare differences of two files 〔C99YH p396〕
*        ＊Windows:
*        >fc (fileA) (fileB) [Enter] // = abbreviation　of "File Compare"
* 
*        [Example]
*        >fc ..\\C99YH07_WhileIteration\\lorem.txt loremCopy.txt
*           ファイル ..\\C99YH07_WHILEITERATION\\lorem.txt と LOREMCOPY.TXT を比較しています
*           FC: 相違点は検出されませんでした
*        [Translation]
*           Compararing File A with B now.
*           FC: Not Found the difference of both.
* 
*        ＊UNIX (MacOS, Linux): 
*        $diff -s (fileA) (fileB) [Enter] // = abbreviation　of "different"
* 
*        [Example]
*        $diff -s ..\\C99YH07_WhileIteration\\lorem.txt loremCopy.txt
*          Files ..\\C99YH07_WhileIteration\\lorem.txt and loremCopy.txt are identical.
* 
*@see MainFileOpenInputSample.c
*@author shika
*@date 2023-01-08
*/

#include <stdio.h>

void consoleInput(char*, int);

//int main(void) {
int mainFileCopyConsoleInputViewer(void) {
    char fromFileName[FILENAME_MAX];
    char toFileName[FILENAME_MAX];

    printf("◆This program is to copy file to file.\n");

    //---- From-File to copy ----
    printf("Please input file name to copy > ");
    consoleInput(fromFileName, FILENAME_MAX);
    //FILE* fromFileP = fopen(fromFileName, "rb");
    FILE* fromFileP = fopen_s(stdin, fromFileName, "rb");

    if (fromFileP == NULL) {
        printf("<！> Not Found the file [ %s ].", fromFileName);
        return -1;
    }

    //---- To-File to save ----
    printf("Please input file name to save, [Be careful, the file contents will be deleted] > ");
    consoleInput(toFileName, FILENAME_MAX);
    //FILE* toFileP = fopen(toFileName, "wb");
    FILE* toFileP = fopen_s(stdout, toFileName, "wb");

    if (toFileP == NULL) {
        printf("<！> Cannot create the file [ %s ].", toFileName);
        fclose(fromFileP);
        return -1;
    }

    //---- Read & Write File contents ----
    int c;
    while ((c = fgetc(fromFileP)) != EOF) {
        fputc(c, toFileP);
    }//while

    //---- Close Files ----
    if (fclose(toFileP)) {
        printf("Error in File Closing [ %s ].", toFileName);
        fclose(toFileP);
        return -1;
    }

    if (fclose(fromFileP)) {
        printf("Error in File Closing [ %s ].", fromFileName);
        fclose(fromFileP);
        return -1;
    }

    printf("(The copy has done.)");
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
//====== Execute by [Windows Command Prompt for VS2019] ======
>cd C:\ ... \C99YH\C99YH12_FileOperation

>cl MainFileCopyConsoleInputViewer.c
MainFileCopyConsoleInputViewer.c
/out:MainFileCopyConsoleInputViewer.exe
MainFileCopyConsoleInputViewer.obj

>MainFileCopyConsoleInputViewer
◆This program is to copy file to file.
Please input file name to copy > ..\\C99YH07_WhileIteration\\lorem.txt
Please input file name to save, [Be careful, the file contents will be deleted] > loremCopy.txt
(The copy has done.)

>fc ..\\C99YH07_WhileIteration\\lorem.txt loremCopy.txt
ファイル ..\\C99YH07_WHILEITERATION\\lorem.txt と LOREMCOPY.TXT を比較しています
FC: 相違点は検出されませんでした
[Translation]
Compararing File A with B now.
FC: Not Found the difference of both.

//====== Result ======
◆This program is to copy file to file.
Please input file name to copy > ..\\C99YH07_WhileIteration\\lorem.txt
Please input file name to save, [Be careful, the file contents will be deleted] > loremCopy.txt

(The copy has done.)

//====== loremCopy.txt ======
(This file is created in this directory and copied the contents below.)

Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed
do eiusmod tempor incididunt ut labore et dolore magna aliqua.
Ut enim ad minim veniam, quis nostrud exercitation ullamco
laboris nisi ut aliquip ex ea commodo consequat.  Duis aute
irure dolor in reprehenderit in voluptate velit esse cillum
dolore eu fugiat nulla pariatur.  Excepteur sint occaecat
cupidatat non proident, sunt in culpa qui officia deserunt mollit
anim id est laborum.

*/