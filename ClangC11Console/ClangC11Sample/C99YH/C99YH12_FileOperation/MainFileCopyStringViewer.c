/**
*@directory ClangC11Console / ClanC11Sample / C99YH / C99YH12_FileOperation
*@fileName  MainFileCopyStringViewer.c
*@based     MainFileCopyCommandLineArgumentViewer.c
*@based     MainFileCopyConsoleInputViewer.c
*@based     MainFileOpenInputSample.c
*@reference C99YH    結城 浩 『C言語プログラミングレッスン [入門編] 第３版』SB Creative, 2019
*@reference CAnsiYH  結城 浩 『C言語プログラミングレッスン [文法編] 新版』  SB Creative, 2006
*@reference C11DS    arton  『独習 C 新版』翔泳社, 2018
*
*@content C99YH 第12章 FileOperation | Chapter 12 / List 12-4 / p400
*@summary File Copy -- fgets() File Get String Version --
*         ・Copy String text one by one Line, not one Byte.
*         ・In this way, NULL Character '\0' cannot read,
            therefore this program can read Text File only, cannot Binary File,
            so that File Open Mode is "r" and "w" only.
*@English
*@subject ◆Execute Procedure
*         ・Copy the execution format [ MainFileCopyStringViewer ..\\C99YH07_WhileIteration\\lorem.txt loremCopy.txt ].
*         ・Change comment-out of 'main()' to active.
*         ・Change comment-out of 'fopen()' to active and 'fopen_s()' to negative in From-File and To-File.
*         ・Execute by [Windows Command Prompt for VS2019]
*           (because, C11-compiled by Visual Studio, it throws Compile Error by cause of 'fopen() unsafe'.)
*
*           >cd (current directory)
*           >cl MainFileCopyStringViewer.c
*           >MainFileCopyStringViewer ..\\C99YH07_WhileIteration\\lorem.txt loremCopy.txt
*           >fc ..\\C99YH07_WhileIteration\\lorem.txt loremCopy.txt
*               => Command 'fc'〔C99YH12_FileOperation\MainFileCopyConsoleInputViewer.c〕
* 
*         ・(Return back whole of changes for another Compile, after execution here.)
*
*@subject <stdio.h> => 〔MainFileOpenInputSample.c〕
*            └ char*  fgets(const char* _Buffer, int _MaxCount, FILE* _Stream)
*            └ int    fputs(const char* _Buffer, FILE* _Stream)
*
*@see
*@author shika
*@date 2023-01-09
*/

#include <stdio.h>

#define BUFFER_SIZE 256

int main(int argc, char* argv[]) {
//int mainFileCopyStringViewer(int argc, char* argv[]) {
    printf("■ This program is to copy file to file.\n");

    if (argc != 3) {
        printf("<！> Invalid Execution Format.\n");
        printf("Execute in this format:\n[> %s ..\\C99YH07_WhileIteration\\lorem.txt loremCopy.txt].\n", argv[0]);
        return -1;
    }

    char* fromFileName = argv[1];
    char* toFileName = argv[2];

    //---- From-File to copy ----
    FILE* fromFileP = fopen(fromFileName, "r");
    //FILE* fromFileP = fopen_s(stdin, fromFileName, "r");

    if (fromFileP == NULL) {
        printf("<！> Not Found the file [ %s ].", fromFileName);
        return -1;
    }

    //---- To-File to save ----   
    FILE* toFileP = fopen(toFileName, "w");
    //FILE* toFileP = fopen_s(stdout, toFileName, "w");

    if (toFileP == NULL) {
        printf("<！> Cannot create the file [ %s ].", toFileName);
        fclose(fromFileP);
        return -1;
    }

    //---- Read & Write File contents ----
    char buffer[BUFFER_SIZE];
    while (fgets(buffer, BUFFER_SIZE, fromFileP) != NULL) {
        fputs(buffer, toFileP);
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
