/**
*@directory ClangC11Console / ClanC11Sample / C99YH / C99YH12_FileOperation
*@fileName  MainFilePrintFormatViewer.c
*@based     MainFileCopyStringViewer.c
*@based     MainFileCopyCommandLineArgumentViewer.c
*@based     MainFileCopyConsoleInputViewer.c
*@based     MainFileOpenInputSample.c
*@reference C99YH    ���� �_ �wC����v���O���~���O���b�X�� [�����] ��R�ŁxSB Creative, 2019
*@reference CAnsiYH  ���� �_ �wC����v���O���~���O���b�X�� [���@��] �V�Łx  SB Creative, 2006
*@reference C11DS    arton  �w�ƏK C �V�Łx�ĉj��, 2018
*
*@content C99YH ��12�� FileOperation | Chapter 12  fprintf() / List 12-5 / p402
*@summary MainFilePrintFormatViewer.c
*         This Program gets file name to read and write from Command Line Argument.
*         It read the contents from the File.
*         It write to another File with self-defined Format.
*         
*@English
*@subject ��Execute Procedure
*         �ECopy the execution format [ MainFilePrintFormatViewer ..\\C99YH07_WhileIteration\\lorem.txt loremCopy.txt ].
*         �EChange comment-out of 'main()' to active.
*         �EChange comment-out of 'fopen()' to active and 'fopen_s()' to negative in From-File and To-File.
*         �EExecute by [Windows Command Prompt for VS2019]
*           (because, C11-compiled by Visual Studio, it throws Compile Error by cause of 'fopen() unsafe'.)
*
*           >cd (current directory)
*           >cl MainFileCopyStringViewer.c
*           >MainFileCopyStringViewer ..\\C99YH07_WhileIteration\\lorem.txt loremCopyWithLineNumber.txt
*           >fc ..\\C99YH07_WhileIteration\\lorem.txt loremCopy.txt
*               => Command 'fc'�kC99YH12_FileOperation\MainFileCopyConsoleInputViewer.c�l
*
*         �E(Return back whole of changes for another Compile, after execution here.)
*
*@subject <stdio.h> => INDEX �kMainFileOpenInputSample.c�l
*            �� FILE*  fopen(const char* _FileName, const char* _Mode)
*            �� int    fclose(FILE* _Stream) 
*            �� char*  fgets(const char* _Buffer, int _MaxCount, FILE* _Stream)
*            �� int    fprintf(FILE* , const char _Format, [T value ...])
* 
*@subject ��Function fprintf()  = abbreviation of File Print Format �kC99YH p402�l
*         �EIt is used, instead of 'fputs(buffer, toFileP);'
*         �EFunction 'printf()' write to Console with Format as Standard Output,
            Function 'fprintf()' write to File with Format.
*         �EArgument Format and Value as same printf(). 
*           =>�kC99YH01_ConsoleOutput\MainPrintfSample.c�l
* 
*         int  fprintf(FILE* _Stream, const char _Format, [T value ...])
*         [Argument]
*         FILE* _Stream:      Pointer of file which is opened by 'fopen()' with Mode 'w' to write, before this operation.
*                             or 'stdout' defined in <stdio.h> as Standard Output (= Console output), which behave as same 'printf()'.
*                             or 'stderr' definrd in <stdio.h> as Standard Error  (= Console Output), for example =>�kC99YH11_Pointer\MainSearchDictionaryFromFileViewer.c�l
*         const char _Format: as same printf().
*         [T value ...]:      as same printf().
* 
*         => copy to�kC99YH12_FileOperation\MainFileOpenInputSample.c�l
* 
*@see
*@author shika
*@date 2023-01-12
*/

#include <stdio.h>

#define BUFFER_SIZE 1024

//int main(int argc, char* argv[]) {
int mainFileCopyStringViewer(int argc, char* argv[]) {
    printf("�� This program is to read file and to write file with line number.\n");

    if (argc != 3) {
        printf("<�I> Invalid Execution Format.\n");
        printf("Execute in this format:\n[> %s ..\\C99YH07_WhileIteration\\lorem.txt loremCopyWithLineNumber.txt].\n", argv[0]);
        return -1;
    }

    char* fromFileName = argv[1];
    char* toFileName = argv[2];

    //---- From-File to copy ----
    //FILE* fromFileP = fopen(fromFileName, "r");
    FILE* fromFileP = fopen_s(stdin, fromFileName, "r");  //In Temporary active -> When execute, switch Comment-out above.

    if (fromFileP == NULL) {
        printf("<�I> Not Found the file [ %s ].", fromFileName);
        return -1;
    }

    //---- To-File to save ----   
    //FILE* toFileP = fopen(toFileName, "w");
    FILE* toFileP = fopen_s(stdout, toFileName, "w"); //In Temporary active -> When execute, switch Comment-out above.

    if (toFileP == NULL) {
        printf("<�I> Cannot create the file [ %s ].", toFileName);
        fclose(fromFileP);
        return -1;
    }

    //---- Read & Write File contents with Line Number ----
    int lineNum = 1L;
    char buffer[BUFFER_SIZE];
    while (fgets(buffer, BUFFER_SIZE, fromFileP) != NULL) {
        //fputs(buffer, toFileP);
        fprintf(toFileP, "%08ld: %s", lineNum, buffer);
        lineNum++;
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

/*
//====== Execute by [Windows Commnand Prompt for VS2019] ======
>cd C:\...\C99YH\C99YH12_FileOperation

>cl MainFilePrintFormatViewer.c
MainFilePrintFormatViewer.c
/out:MainFilePrintFormatViewer.exe
MainFilePrintFormatViewer.obj

>MainFilePrintFormatViewer ..\\C99YH07_WhileIteration\\lorem.txt loremCopyWithLineNumber.txt

�� This program is to read file and to write file with line number.
(The copy has done.)


//====== loremCopyWithLineNumber.txt ======
00000001: Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed
00000002: do eiusmod tempor incididunt ut labore et dolore magna aliqua.
00000003: Ut enim ad minim veniam, quis nostrud exercitation ullamco
00000004: laboris nisi ut aliquip ex ea commodo consequat.  Duis aute
00000005: irure dolor in reprehenderit in voluptate velit esse cillum
00000006: dolore eu fugiat nulla pariatur.  Excepteur sint occaecat
00000007: cupidatat non proident, sunt in culpa qui officia deserunt mollit
00000008: anim id est laborum.
*/