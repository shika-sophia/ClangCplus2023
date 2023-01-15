/**
*@directory ClangC11Console / ClanC11Sample / C99YH / C99YH08_Function
*@fileName  MainDividedCompileSample.c
*@reference C99YH  åãèÈ ç_ ÅwCåæåÍÉvÉçÉOÉâÉ~ÉìÉOÉåÉbÉXÉì [ì¸ñÂï“] ëÊÇRî≈ÅxSB Creative, 2019
*@reference CAnsi  åãèÈ ç_ ÅwCåæåÍÉvÉçÉOÉâÉ~ÉìÉOÉåÉbÉXÉì [ï∂ñ@ï“] êVî≈Åx  SB Creative, 2006
*@reference C11DS  arton  Åwì∆èK C êVî≈Åx„ƒâjé–, 2018
*
*@content C99YH ëÊÇWèÕ ä÷êî | Chapter 8  Function / List 8-5a, 8-5b, 8-5c / p237
*
*@summary ÅüDevidied Compile   / ï™äÑÉRÉìÉpÉCÉã
*           Declaration Prototype: =>ÅkconsoleInput.hÅl
*              Å™  Å™  (Reference)
*           Definition  Function:  =>ÅkDividedCompile_consoleInputBody.cÅl
*           main() as Entry Point  => (this file)
*              Å´  Å´ (Compile)
*           each [.obj] Object Files
*              Å´  Å´
*         ÅüIntegrated Compile / ìùçáÉRÉìÉpÉCÉã
*              Å´    (Compile)
*           [.exe] Execute File
* 
*@subject Visual Studio Execution
*         VS always do 'Divided Compile' and 'Integrated Compile'.
* 
*         When user save files, VS compile these files with option of yielding Object Files only,
*         each [.c] C Files save as the same name of Object Files in '/Debug' directory.
*         
*         When user order to execute, VS do 'Integrated Compile' with whole of Object Files,
*         and yield [(project name).exe] Execute File, execute this [.exe].
* 
*@subject Procedure
          ÅüDivided Compile with option to yield [.obj] Object File only.
*         ÅüIntegrated Compile each [.obj] Object Files,
*           which yields [.exe] Execute File.
* 
*         [Examples]
*         ÅñWindows
*         >cd (current directory)                   //Change Directory
*         >cl /c DividedCompile_consoleInputBody.c  //Divided Compile with option '/c', which yields [.obj] only.
*         >cl /c MainDividedCompileSample.c         //Divided Compile with option '/c', which yields [.obj] only.
*         >cl MainDividedCompileSample.obj DividedCompile_consoleInputBody.obj 
*                                                   //Integrated Compile each [.obj] files, which yields to [.exe] Execute File.
*                                                   //ÅyNotationÅzput 'Main.obj' before, which you want to be [.exe] name.
* 
*         >MainDividedCompileSample                 //Execute above [.exe].
* 
*         ÅñUNIX (Mac OS, Linux)
*         $cd (current directory)
*         $gcc -c -o DividedCompile_consoleInputBody.o DividedCompile_consoleInputBody.c
*         $ls 
*         DividedCompile_consoleInputBody.o
* 
*         $gcc -c -o MainDividedCompileSample.o MainDividedCompileSample.c
*         $ls 
*         MainDividedCompileSample.o
* 
*         $gcc -o MainDividedCompileSampleExe DividedCompile_consoleInputBody.o MainDividedCompileSample.o
*         $ls
*         MainDividedCompileSampleExe
* 
*         $./MainDividedCompileSampleExe
* 
*@see    consoleInput.h
*@see    DividedCompile_consoleInputBody.c
*@see    CAnsiYH01_Introduction\Reference_CAnsiYH01.txt
*@author shika
*@date 2022-12-24
*/

#include <stdio.h>         //default-defined standard Header file
#include "consoleInput.h"  //self-defined Header file

#define BUFFER_SIZE 256

//int main(void) {
int mainDividedCompileSample(void) {
    char buffer[BUFFER_SIZE];

    printf("ÅüPlease input your name > ");
    consoleInput(buffer, BUFFER_SIZE);

    printf("Hello, %s.\n", buffer);

    return 0;
}//main()

/*
//====== "consoleInput.h" ======
//---- Declaration Prototype ----
void consoleInput(char*, int);

//====== DividedCompile_consoleInputBody.c ======
//---- Definition Function ----

#include <stdio.h>
#include "consoleInput.h"

void consoleInput(char* buffer, int bufferSize) {
    char* inputAry = fgets(buffer, bufferSize, stdin);

    if (inputAry == NULL) {
        buffer[0] = '\0';
        return;
    }

    for (int i = 0; i < bufferSize; i++) {
        if (buffer[i] == '\n') {
            buffer[i] = '\0';
            return;
        }
    }//for
}//consoleInput()


//====== Command Prompt Execution ======
>cd C:\ ... \ClangCplus2023\ClangC11Console\ClangC11Sample\C99YH\C99YH08_Function

>cl /c DividedCompile_consoleInputBody.c
>cl /c MainDividedCompileSample.c
[Å~] >cl DividedCompile_consoleInputBody.obj MainDividedCompileSample.obj
    /out:DividedCompile_consoleInputBody.exe -> (Deleted)
    DividedCompile_consoleInputBody.obj
    MainDividedCompileSample.obj

    (Retry)
[ÅZ] >cl MainDividedCompileSample.obj DividedCompile_consoleInputBody.obj
     /out:MainDividedCompileSample.exe
     MainDividedCompileSample.obj
     DividedCompile_consoleInputBody.obj

>MainDividedCompileSample

//====== Result ======
ÅüPlease input your name > Alice
Hello, Alice.

*/