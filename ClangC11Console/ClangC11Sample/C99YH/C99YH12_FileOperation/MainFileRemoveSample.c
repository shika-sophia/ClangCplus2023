/**
*@directory ClangC11Console / ClanC11Sample / C99YH / C99YH12_FileOperation
*@fileName  MainFileRemoveSample.c
*@reference C99YH    ���� �_ �wC����v���O���~���O���b�X�� [�����] ��R�ŁxSB Creative, 2019
*@reference CAnsiYH  ���� �_ �wC����v���O���~���O���b�X�� [���@��] �V�Łx  SB Creative, 2006
*@reference C11DS    arton  �w�ƏK C �V�Łx�ĉj��, 2018
*
*@content C99YH ��12�� FileOperation | Chapter 12  remove() / List 12-6 / p405
*@summary MainFileRemoveSample.c
*         This program, by Function 'remove()', delete the file which user set in Command Line Argument.
*         It does not use File Pointer 'FILE*', Function 'fopen()' ,and 'fclose()' either.
*         It use only char Pointer for String text of file name.
* 
*@English
*@subject ��Execute Procedure
*         �EChange comment-out of 'main() to active.
*         �EOpen [Windows Command Prompt for VS2019].
*         �EChange current directory to here.
*           >cd (current directory)
* 
*         �ECreate temporary file to delete 
*           >echo Hello. > temp.txt
* 
*         �ECompile this
*           >cl MainFileRemoveSample.c
* 
*         �EExecute with Command Line Argument (= the file name created to delete above)
*           > MainFileRemoveSample temp.txt
*
*@subject <stdio.h> => INDEX �kMainFileOpenInputSample.c�l
             �� int  remove(const char* _FileName)
            
*@subject Function remove()  �kC99YH p405�l
*         int  remove(const char* _FileName)
*         [Argument] const char* _FileName
*         [Return]   0:     correctly delete the file
*                    not 0: cannot delete because of not exist or else error.
*           �yNotation�z To success returns false value '0'.
*                        To fail    retruns true value 'not 0'
* 
*         [Example]
*         *fileName = argv[1];
* 
*         if (remove(*fileName) != 0) {
*             printf("<�I> The file [ %s ] cannot be deleted or is not existed.", *fileName);
*             return -1;
*         }
*               
*         printf("<�Z> The file [ %s ] has deleted.", *fileName);
*         
*         => copy to�kMainFileOpenInputSample.c�l
* 
*@see
*@author shika
*@date 2023-01-12
*/

#include <stdio.h>

//int main(int argc, char* argv[]) {
int mainFileRemoveSample(int argc, char* argv[]) {
    char* fileName[FILENAME_MAX];

    printf("�� This program will delete the file which you set the file name in Command Line Argument.\n");

    if (argc != 2){
        printf("<�I> Invalid Execute Format. \n");
        printf("[Format] \n");
        printf(">MainFileRemoveSample temp.txt \n");
        return -1;
    }

    *fileName = argv[1];

    if (remove(*fileName) != 0) {
        printf("<�I> The file [ %s ] cannot be deleted or is not existed.", *fileName);
        return -1;
    }
    
    printf("<�Z> The file [ %s ] has deleted.", *fileName);
    return 0;
}//main()

/*
//====== Execute by [Windows Command Prompt for VS2019] ======
>cd C:\...\C99YH\C99YH12_FileOperation

//---- Create temporary file to delete ----
>echo Hello. > temp.txt

//---- (confirm to exist) ----
//====== temp.txt ====
Hello.

//---- Compile ----
>cl MainFileRemoveSample.c
MainFileRemoveSample.c
/out:MainFileRemoveSample.exe
MainFileRemoveSample.obj

//---- Test of Invalid Execute ----
>MainFileRemoveSample

�� This program will delete the file which you set the file name in Command Line Argument.
<�I> Invalid Execute Format.
[Format]
>MainFileRemoveSample temp.txt

//---- Execute Correctly at First times ----
>MainFileRemoveSample temp.txt
�� This program will delete the file which you set the file name in Command Line Argument.
<�Z> The file [ temp.txt ] has deleted.

(confirm not to exist )

//---- Execute Correctly at Second times ----
>MainFileRemoveSample temp.txt
�� This program will delete the file which you set the file name in Command Line Argument.
<�I> The file [ temp.txt ] cannot be deleted or is not existed.

*/
