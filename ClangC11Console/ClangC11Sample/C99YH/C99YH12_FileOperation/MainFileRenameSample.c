/**
*@directory ClangC11Console / ClanC11Sample / C99YH / C99YH12_FileOperation
*@fileName  MainFileRenameSample.c
*@reference C99YH    ���� �_ �wC����v���O���~���O���b�X�� [�����] ��R�ŁxSB Creative, 2019
*@reference CAnsiYH  ���� �_ �wC����v���O���~���O���b�X�� [���@��] �V�Łx  SB Creative, 2006
*@reference C11DS    arton  �w�ƏK C �V�Łx�ĉj��, 2018
*
*@content C99YH ��12�� FileOpreration | Chapter 12  rename() / List 12-7 / p407
*@summary MainFileRenameSample.c
*         This program can change the already existed file name to new name.
*         It is given old file name and new file name by Command Line Argument.
*         It renames old to new.
*         It does not use File Pointer 'FILE*', but use char Pointer 'char* argv[]'.
* 
*@English
*@subject ��Execute Procedure
*         �EChange comment-out of 'main()' to active.
*         �EOpen [Windows Command Prompt for VS2019].
*         �EChange current directory to here.
*           >cd (current directory)
*
*         �ECreate temporary file to rename
*           >echo Hello, from Old to New. > oldC99YH12.txt
*
*         �ECompile this
*           >cl MainFileRenameSample.c
*
*         �EExecute with Command Line Argument (= the file name created to rename above)
*           >MainFileRenameSample oldC99YH12.txt newC99YH12.txt
* 
*@subject <stdio.h> => INDEX�kMainFileOpenInputSample.c�l
*            �� int  rename(const char* _OldFileName, const char* _NewFileName)
* 
*@subject ��Function rename()  �kC99YH p406�l
*         int  rename(const char* _OldFileName, const char* _NewFileName)
*         
*         [Argument]
*         const char* _OldFileName
*         const char* _NewFileName
*
*         [Return]
*         int  0:     success
*         not 0: failure
*
*        �yNotation�z
*         To success returns false value '0'.
*         To fail    returns true value  'not 0'.
*
*         [Example]
*         if (rename(argv[1], argv[2]) != 0) {
*             printf("<�I> Old File [ %s ] cannot rename or is not existed.\n", argv[1]);
*             return -1;
*         }
*
*         printf("<�Z> Old File Name [%s] renamed to New File Name [ %s ].\n",
*             argv[1], argv[2]);
*
*         => copy to�kMainFileOpenInputSample.c�l
* 
*@see
*@author shika
*@date 2023-01-13
*/

#include <stdio.h>

//int main(int argc, char* argv[]) {
int mainFileRenameSample(int argc, char* argv[]) {
    if (argc != 3) {
        printf("<�I> Invalid Execute Format! \n");
        printf("[Format] when Execute \n");
        printf(">%s OLDFILE NEWFILE [Enter] \n", argv[0]);
    }

    if (rename(argv[1], argv[2]) != 0) {
        printf("<�I> Old File [ %s ] cannot rename or is not existed.\n", argv[1]);
        return -1;
    }

    printf("<�Z> Old File Name [%s] renamed to New File Name [ %s ].\n",
        argv[1], argv[2]);

    return 0;
}//main()

/*
//====== Execute [Windows Command Prompt for VS2019] ======
>cd C:\...\C99YH\C99YH12_FileOperation

//---- Create temporary file to rename ----
>echo Hello, from Old to New. > oldC99YH12.txt

//---- (confirm oldC99YH12.txt is existed) ----
//==== oldC99YH12.txt ====
Hello, from Old to New.

//---- Compile ----
>cl MainFileRenameSample.c
MainFileRenameSample.c
/out:MainFileRenameSample.exe
MainFileRenameSample.obj

//---- Test of Invalid Execute ----
>MainFileRenameSample
<�I> Invalid Execute Format!
[Format] when Execute
>MainFileRenameSample OLDFILE NEWFILE [Enter]

//---- Correctly Execute at First Times ----
>MainFileRenameSample oldC99YH12.txt newC99YH12.txt
<�Z> Old File Name [oldC99YH12.txt] renamed to New File Name [ newC99YH12.txt ].

//---- (confirm newC99YH12.txt is existed) ----
//==== newC99YH12.txt ====
Hello, from Old to New.

//---- Correctly Execute at Second Times ----
>MainFileRenameSample oldC99YH12.txt newC99YH12.txt
<�I> Old File [ oldC99YH12.txt ] cannot rename or is not existed.

*/
