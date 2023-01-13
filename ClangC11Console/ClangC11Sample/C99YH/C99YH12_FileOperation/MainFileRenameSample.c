/**
*@directory ClangC11Console / ClanC11Sample / C99YH / C99YH12_FileOperation
*@fileName  MainFileRenameSample.c
*@reference C99YH    結城 浩 『C言語プログラミングレッスン [入門編] 第３版』SB Creative, 2019
*@reference CAnsiYH  結城 浩 『C言語プログラミングレッスン [文法編] 新版』  SB Creative, 2006
*@reference C11DS    arton  『独習 C 新版』翔泳社, 2018
*
*@content C99YH 第12章 FileOpreration | Chapter 12  rename() / List 12-7 / p407
*@summary MainFileRenameSample.c
*         This program can change the already existed file name to new name.
*         It is given old file name and new file name by Command Line Argument.
*         It renames old to new.
*         It does not use File Pointer 'FILE*', but use char Pointer 'char* argv[]'.
* 
*@English
*@subject ◆Execute Procedure
*         ・Change comment-out of 'main()' to active.
*         ・Open [Windows Command Prompt for VS2019].
*         ・Change current directory to here.
*           >cd (current directory)
*
*         ・Create temporary file to rename
*           >echo Hello, from Old to New. > oldC99YH12.txt
*
*         ・Compile this
*           >cl MainFileRenameSample.c
*
*         ・Execute with Command Line Argument (= the file name created to rename above)
*           >MainFileRenameSample oldC99YH12.txt newC99YH12.txt
* 
*@subject <stdio.h> => INDEX〔MainFileOpenInputSample.c〕
*            └ int  rename(const char* _OldFileName, const char* _NewFileName)
* 
*@subject ◆Function rename()  〔C99YH p406〕
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
*        【Notation】
*         To success returns false value '0'.
*         To fail    returns true value  'not 0'.
*
*         [Example]
*         if (rename(argv[1], argv[2]) != 0) {
*             printf("<！> Old File [ %s ] cannot rename or is not existed.\n", argv[1]);
*             return -1;
*         }
*
*         printf("<〇> Old File Name [%s] renamed to New File Name [ %s ].\n",
*             argv[1], argv[2]);
*
*         => copy to〔MainFileOpenInputSample.c〕
* 
*@see
*@author shika
*@date 2023-01-13
*/

#include <stdio.h>

//int main(int argc, char* argv[]) {
int mainFileRenameSample(int argc, char* argv[]) {
    if (argc != 3) {
        printf("<！> Invalid Execute Format! \n");
        printf("[Format] when Execute \n");
        printf(">%s OLDFILE NEWFILE [Enter] \n", argv[0]);
    }

    if (rename(argv[1], argv[2]) != 0) {
        printf("<！> Old File [ %s ] cannot rename or is not existed.\n", argv[1]);
        return -1;
    }

    printf("<〇> Old File Name [%s] renamed to New File Name [ %s ].\n",
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
<！> Invalid Execute Format!
[Format] when Execute
>MainFileRenameSample OLDFILE NEWFILE [Enter]

//---- Correctly Execute at First Times ----
>MainFileRenameSample oldC99YH12.txt newC99YH12.txt
<〇> Old File Name [oldC99YH12.txt] renamed to New File Name [ newC99YH12.txt ].

//---- (confirm newC99YH12.txt is existed) ----
//==== newC99YH12.txt ====
Hello, from Old to New.

//---- Correctly Execute at Second Times ----
>MainFileRenameSample oldC99YH12.txt newC99YH12.txt
<！> Old File [ oldC99YH12.txt ] cannot rename or is not existed.

*/
