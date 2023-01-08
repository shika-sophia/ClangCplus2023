/**
*@directory ClangC11Console / ClanC11Sample / C99YH / C99YH12_FileOperation
*@fileName  MainFileCopyCommandLineArgumentViewer.c
*@based     MainFileCopyConsoleInputViewer.c
*@based     MainFileOpenInputViewer.c
*@reference C99YH    ���� �_ �wC����v���O���~���O���b�X�� [�����] ��R�ŁxSB Creative, 2019
*@reference CAnsiYH  ���� �_ �wC����v���O���~���O���b�X�� [���@��] �V�Łx  SB Creative, 2006
*@reference C11DS    arton  �w�ƏK C �V�Łx�ĉj��, 2018
*
*@content C99YH ��12�� FileOperation | Chapter 12 / List 12-3 / p
*@summary File Copy -- Command Line Argument Version --
*@English
*@subject ��Execute Procedure
*         �ECopy the execution format [ MainFileCopyCommandLineArgumentViewer ..\\C99YH07_WhileIteration\\lorem.txt loremCopy.txt ].
*         �EChange comment-out of 'main()' to active.
*         �EChange comment-out of 'fopen()' to active and 'fopen_s()' to negative in From-File and To-File.
*         �EExecute by [Windows Command Prompt for VS2019]
*           (because, executed by Visual Studio, it throws Compile Error by cause of 'fopen() unsafe'.)
*          
*           >cd (current directory)
*           >cl MainFileCopyCommandLineArgumentViewer.c
*           >MainFileCopyCommandLineArgumentViewer ..\\C99YH07_WhileIteration\\lorem.txt loremCopy.txt
* 
*         �E(Return back whole of changes for another Compile, after execution here.)
*
*@subject int main(int argc, char* argv[]) 
*         => �kC99YH06_ForIteratation\MainCommandLineArgumentSample.c�l
* 
*@see     MainFileCopyConsoleInputViewer.c
*@see     MainFileOpenInputViewer.c
*@author shika
*@date 2023-01-08
*/

#include <stdio.h>

//int main(int argc, char* argv[]) {
int mainFileCopyCommandLineArgumentViewer(int argc, char* argv[]) {
    printf("�� This program is to copy file to file.\n");
    
    if (argc != 3) {
        printf("<�I> Invalid Execution Format.\n");
        printf("Execute in this format:\n[> % s ..\\C99YH07_WhileIteration\\lorem.txt loremCopy.txt].\n", argv[0]);
        return -1;
    }

    char* fromFileName = argv[1];
    char* toFileName = argv[2];
    
    //---- From-File to copy ----
    //FILE* fromFileP = fopen(fromFileName, "rb");
    FILE* fromFileP = fopen_s(stdin, fromFileName, "rb");

    if (fromFileP == NULL) {
        printf("<�I> Not Found the file [ %s ].", fromFileName);
        return -1;
    }

    //---- To-File to save ----   
    //FILE* toFileP = fopen(toFileName, "wb");
    FILE* toFileP = fopen_s(stdout, toFileName, "wb");

    if (toFileP == NULL) {
        printf("<�I> Cannot create the file [ %s ].", toFileName);
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

/*
//====== Execute by [Windows Command Prompt for VS2019] ======
>cd C:\ ... \C99YH\C99YH12_FileOperation
>cl MainFileCopyCommandLineArgumentViewer.c
MainFileCopyCommandLineArgumentViewer.c
/out:MainFileCopyCommandLineArgumentViewer.exe
MainFileCopyCommandLineArgumentViewer.obj

>MainFileCopyCommandLineArgumentViewer ..\\C99YH07_WhileIteration\\lorem.txt loremCopy.txt
�� This program is to copy file to file.
(The copy has done.)

>fc ..\\C99YH07_WhileIteration\\lorem.txt loremCopy.txt
�t�@�C�� ..\\C99YH07_WHILEITERATION\\lorem.txt �� LOREMCOPY.TXT ���r���Ă��܂�
FC: ����_�͌��o����܂���ł���

//---- Test of Invalid Execution Format ----
>MainFileCopyCommandLineArgumentViewer
�� This program is to copy file to file.
<�I> Invalid Execution Format.
Execute in this format:
[>MainFileCopyCommandLineArgumentViewer ..\C99YH07_WhileIteration\lorem.txt loremCopy.txt ].

*/