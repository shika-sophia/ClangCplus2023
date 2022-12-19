/**
*@directory ClangC11Console / ClanC11Sample / C99YH / C99YH06_ForIteration
*@fileName  MainCommandLineArgumentSample.c
*@reference C99YH  ���� �_ �wC����v���O���~���O���b�X�� [�����] ��R�ŁxSB Creative, 2019
*@reference CAnsi  ���� �_ �wC����v���O���~���O���b�X�� [���@��] �V�Łx  SB Creative, 2006
*@reference C11DS  arton  �w�ƏK C �V�Łx�ĉj��, 2018
*
*@content C99YH ��U�� ForIteration | Chapter 6 / List 6-5 / p172
*@subject ��Command Line Argument / �R�}���h���C������
*         int  main(int argc, char* argv[])
*           �� [Argument]
*             int   argc:   argument count
*             char* argv[]: Array of argument values as char*
*               �� argv[0]:  Command Name (=[.exe] file name)
*               �� argv[i]:  argument value 
*                  :
*               �� argv[argc - 1]: last argument value
*               �� argv[argc]:     NULL
* 
*         => '*' detail�kChapter 11 Pointer�l
* 
*@subject Settings of Visual Studio execution
*         [Project] Mouse Right click -> [Property] -> [Debug] Tab ->
*         [Command Line Argument] -> (Edit each argument with white-space delimiter) -> [ OK ]
*                                      �� in this case: "This is command line argument."
*         => [Execute without Debug] (Ctrl + F5)
* 
*        �yNotation�zAfter execution, Remove above setting argument for another executions.
*
*@subject Windows Command Prompt execution
*         >cd (set current directory)                              //Change Directory
*         (current directory) >cl MainCommandLineArgumentSample.c  //Compile and Output this object file
*         (current directory) >MainCommandLineArgumentSample 1 2 3 //Execute [.exe] with each argument delimited by white-space. 
*
*@subject UNIX Terminal execution �kC99YH p5, p7, p172�l
*         $ cd (set current directory)
*         $ gcc -o MainCommandLineArgumentSample ./MainCommandLineArgumentSample.c
*         $ MainCommandLineArgumentSample 1 2 3
* 
*@see
*@author shika
*@date 2022-12-19
*/

#include <stdio.h>

//int main(int argc, char* argv[]) {
int mainCommandLineArgumentSample(int argc, char* argv[]) {

    printf("Argument Num: %d\n", argc);

    for (int i = 0; i < argc; i++) {
        printf("argv[%d] = %s \n", i, argv[i]);
    }//for

    return 0;
}//main()

/*
Argument Num: 6
argv[0] = C:\ ... \ClangCplus2023\Debug\ClangC11Console.exe
argv[1] = This
argv[2] = is
argv[3] = command
argv[4] = line
argv[5] = argument.

//---- Windows Command Prompt for VS2019 execution ----
>cd (Paste full path of this file without file name)

(current directory) >cl MainCommandLineArgumentSample.c

Microsoft(R) C/C++ Optimizing Compiler Version 19.29.30147 for x86
Copyright (C) Microsoft Corporation.  All rights reserved.

MainCommandLineArgumentSample.c
Microsoft (R) Incremental Linker Version 14.29.30147.0
Copyright (C) Microsoft Corporation.  All rights reserved.

/out:MainCommandLineArgumentSample.exe
MainCommandLineArgumentSample.obj

(current directory) >MainCommandLineArgumentSample 1 2 3
Argument Num: 4
argv[0] = MainCommandLineArgumentSample
argv[1] = 1
argv[2] = 2
argv[3] = 3
*/