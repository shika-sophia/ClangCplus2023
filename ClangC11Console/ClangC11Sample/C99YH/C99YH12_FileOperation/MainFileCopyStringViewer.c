/**
*@directory ClangC11Console / ClanC11Sample / C99YH / C99YH12_FileOperation
*@fileName  MainFileCopyStringViewer.c
*@based     MainFileCopyCommandLineArgumentViewer.c
*@based     MainFileCopyConsoleInputViewer.c
*@based     MainFileOpenInputSample.c
*@reference C99YH    ���� �_ �wC����v���O���~���O���b�X�� [�����] ��R�ŁxSB Creative, 2019
*@reference CAnsiYH  ���� �_ �wC����v���O���~���O���b�X�� [���@��] �V�Łx  SB Creative, 2006
*@reference C11DS    arton  �w�ƏK C �V�Łx�ĉj��, 2018
*
*@content C99YH ��12�� FileOperation | Chapter 12 / List 12-4 / p400
*@summary File Copy -- fgets() File Get String Version --
*         �ECopy String text one by one Line, not one Byte.
*         �EIn this way, NULL Character '\0' cannot read,
            therefore this program can read Text File only, cannot Binary File,
            File Open Mode is "r" or "w" only.

*@English
*@subject ��Execute Procedure
*         �ECopy the execution format [ MainFileCopyStringViewer ..\\C99YH07_WhileIteration\\lorem.txt loremCopy.txt ].
*         �EChange comment-out of 'main()' to active.
*         �EChange comment-out of 'fopen()' to active and 'fopen_s()' to negative in From-File and To-File.
*         �EExecute by [Windows Command Prompt for VS2019]
*           (because, C11-compiled by Visual Studio, it throws Compile Error by cause of 'fopen() unsafe'.)
*
*           >cd (current directory)
*           >cl MainFileCopyStringViewer.c
*           >MainFileCopyStringViewer ..\\C99YH07_WhileIteration\\lorem.txt loremCopy.txt
*           >fc ..\\C99YH07_WhileIteration\\lorem.txt loremCopy.txt
*               => Command 'fc'�kC99YH12_FileOperation\MainFileCopyConsoleInputViewer.c�l
* 
*         �E(Return back whole of changes for another Compile, after execution here.)
*
*@subject <stdio.h> => INDEX�kMainFileOpenInputSample.c�l
*            �� char*  fgets(const char* _Buffer, int _MaxCount, FILE* _Stream)
*            �� int    fputs(const char* _Buffer, FILE* _Stream)
*
*@subject ��Different Arguments of 'fgets() and 'fputs()' �kC99YH p402�l
*         The reason why fgets() has 'int _MaxCount':
*         Because Byte size of one line is unknown, to prevent OverFlow which it read beyond array size,
*         It need notify the Maximum Byte Size of buffer array.
*         By this, fgets() can stop reading before OverFlow.
* 
*         Other side, fputs() has alrady had the elements of buffer array to write, 
*         it knows the Byte size within buffer array size,
*         it only continue to write the elements until '\0'.
* 
*         => copy to�kC99YH12_FileOperation\MainFileOpenInputSample.c�l
* 
*@subject ��Different Terminal Conditions of While-Iteration with 'fgetc() fputc()' and 'fgets() fputs()':
*         [Example] List 12-3 �kMainFileCopyCommandLineArgumenViewer.c�l
*         while ((c = fgetc(fromFileP)) != EOF) {
*             fputc(c, toFileP);
*         }//while
* 
*         [Example] List 12-4 �kthis�l
*         while (fgets(buffer, BUFFER_SIZE, fromFileP) != NULL) {
*            fputs(buffer, toFileP);
*         }//while
* 
*         => copy to�kC99YH12_FileOperation\MainFileOpenInputSample.c�l
* 
*@see MainFileOpenInputSample.c
*@author shika
*@date 2023-01-09
*/

#include <stdio.h>

#define BUFFER_SIZE 256

//int main(int argc, char* argv[]) {
int mainFileCopyStringViewer(int argc, char* argv[]) {
    printf("�� This program is to copy file to file.\n");

    if (argc != 3) {
        printf("<�I> Invalid Execution Format.\n");
        printf("Execute in this format:\n[> %s ..\\C99YH07_WhileIteration\\lorem.txt loremCopy.txt].\n", argv[0]);
        return -1;
    }

    char* fromFileName = argv[1];
    char* toFileName = argv[2];

    //---- From-File to copy ----
    //FILE* fromFileP = fopen(fromFileName, "r");
    FILE* fromFileP = fopen_s(stdin, fromFileName, "r");

    if (fromFileP == NULL) {
        printf("<�I> Not Found the file [ %s ].", fromFileName);
        return -1;
    }

    //---- To-File to save ----   
    //FILE* toFileP = fopen(toFileName, "w");
    FILE* toFileP = fopen_s(stdout, toFileName, "w");

    if (toFileP == NULL) {
        printf("<�I> Cannot create the file [ %s ].", toFileName);
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

/*
//====== Execute by [Windows Command Prompt for VS2019] ======
>cd C:\...\C99YH\C99YH12_FileOperation

>cl MainFileCopyStringViewer.c
MainFileCopyStringViewer.c
/out:MainFileCopyStringViewer.exe
MainFileCopyStringViewer.obj

>MainFileCopyStringViewer ..\\C99YH07_WhileIteration\\lorem.txt loremCopy.txt
�� This program is to copy file to file.
(The copy has done.)

*/
