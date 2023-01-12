/**
*@directory ClangC11Console / ClanC11Sample / C99YH / C99YH12_FileOperation
*@fileName  MainFileRemoveSample.c
*@reference C99YH    åãèÈ ç_ ÅwCåæåÍÉvÉçÉOÉâÉ~ÉìÉOÉåÉbÉXÉì [ì¸ñÂï“] ëÊÇRî≈ÅxSB Creative, 2019
*@reference CAnsiYH  åãèÈ ç_ ÅwCåæåÍÉvÉçÉOÉâÉ~ÉìÉOÉåÉbÉXÉì [ï∂ñ@ï“] êVî≈Åx  SB Creative, 2006
*@reference C11DS    arton  Åwì∆èK C êVî≈Åx„ƒâjé–, 2018
*
*@content C99YH ëÊ12èÕ FileOperation | Chapter 12  remove() / List 12-6 / p405
*@summary MainFileRemoveSample.c
*         This program, by Function 'remove()', delete the file which user set in Command Line Argument.
*         It does not use File Pointer 'FILE*', Function 'fopen()' ,and 'fclose()' either.
*         It use only char Pointer for String text of file name.
* 
*@English
*@subject ÅüExecute Procedure
*         ÅEChange comment-out of 'main() to active.
*         ÅEOpen [Windows Command Prompt for VS2019].
*         ÅEChange current directory to here.
*           >cd (current directory)
* 
*         ÅECreate temporary file to delete 
*           >echo Hello. > temp.txt
* 
*         ÅECompile this
*           >cl MainFileRemoveSample.c
* 
*         ÅEExecute with Command Line Argument (= the file name created to delete above)
*           > MainFileRemoveSample temp.txt
*
*@subject <stdio.h> => INDEX ÅkMainFileOpenInputSample.cÅl
             Ñ§ int  remove(const char* _FileName)
            
*@subject Function remove()  ÅkC99YH p405Ål
*         int  remove(const char* _FileName)
*         [Argument] const char* _FileName
*         [Return]   0:     correctly delete the file
*                    not 0: cannot delete because of not exist or else error.
*           ÅyNotationÅz To success returns false value '0'.
*                        To fail    retruns true value 'not 0'
* 
*         [Example]
*         *fileName = argv[1];
* 
*         if (remove(*fileName) != 0) {
*             printf("<ÅI> The file [ %s ] cannot be deleted or is not existed.", *fileName);
*             return -1;
*         }
*               
*         printf("<ÅZ> The file [ %s ] has deleted.", *fileName);
*         
*         => copy toÅkMainFileOpenInputSample.cÅl
* 
*@see
*@author shika
*@date 2023-01-12
*/

#include <stdio.h>

//int main(int argc, char* argv[]) {
int mainFileRemoveSample(int argc, char* argv[]) {
    char* fileName[FILENAME_MAX];

    printf("Å° This program will delete the file which you set the file name in Command Line Argument.\n");

    if (argc != 2){
        printf("<ÅI> Invalid Execute Format. \n");
        printf("[Format] \n");
        printf(">MainFileRemoveSample temp.txt \n");
        return -1;
    }

    *fileName = argv[1];

    if (remove(*fileName) != 0) {
        printf("<ÅI> The file [ %s ] cannot be deleted or is not existed.", *fileName);
        return -1;
    }
    
    printf("<ÅZ> The file [ %s ] has deleted.", *fileName);
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

Å° This program will delete the file which you set the file name in Command Line Argument.
<ÅI> Invalid Execute Format.
[Format]
>MainFileRemoveSample temp.txt

//---- Execute Correctly at First times ----
>MainFileRemoveSample temp.txt
Å° This program will delete the file which you set the file name in Command Line Argument.
<ÅZ> The file [ temp.txt ] has deleted.

(confirm not to exist )

//---- Execute Correctly at Second times ----
>MainFileRemoveSample temp.txt
Å° This program will delete the file which you set the file name in Command Line Argument.
<ÅI> The file [ temp.txt ] cannot be deleted or is not existed.

*/
