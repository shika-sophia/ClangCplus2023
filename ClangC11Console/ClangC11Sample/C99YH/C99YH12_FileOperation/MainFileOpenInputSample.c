/**
*@directory ClangC11Console / ClanC11Sample / C99YH / C99YH12_FileOperation
*@fileName  MainFileOpenInputSample.c
*@reference C99YH    結城 浩 『C言語プログラミングレッスン [入門編] 第３版』SB Creative, 2019
*@reference CAnsiYH  結城 浩 『C言語プログラミングレッスン [文法編] 新版』  SB Creative, 2006
*@reference C11DS    arton  『独習 C 新版』翔泳社, 2018
*
*@content C99YH 第12章 FileOperation | Chapter 12 / List 12-1 / p384
*@summary MainFileOpenInputSample.c
*@English [英] procedure:      手順
*         [P]  relative path:  相対パス
*         [P]  CR: carriage return 復帰、行の先頭に戻す、改行
*         [P]  LF: line feed       改行
*         [英] correspond:     対応する、相当する、一致する、調和する、通信する
*         [英] explicit:       明示的  <-> implicit 暗黙的
* 
*@subject ◆Execute Procedure
*         ・Copy the file name as relative path [ ..\\C99YH07_WhileIteration\\lorem.txt ].
*         ・Change comment-out of 'consoleInput()' definition to active.
*         ・Change comment-out of 'fopen()' to active and 'fopen_s()' to negative.
*         ・Execute by [Windows Command Prompt for VS2019]
*           (because, executed by Visual Studio, it throws Compile Error by cause of 'fopen() unsafe'.)
*         ・It asks file name ,and then Paste the file name and [Enter] Key.
* 
*         [Example]
*         ◆Please input File Name > ..\\C99YH07_WhileIteration\\lorem.txt
*
*@subject <stdio.h>
*            └ #define FILENAME_MAX 260
*            └ int    fgetc(char)
*        [×] └ FILE*  fopen(const char* _FileName, const char* _Mode)
*            └ int    fclose(FILE* _Stream)
* 
*@subject ◆File Open
*         Open:  The operation that Function 'fopen()' asks OS of user environment, "From now, I will open the file, Can I ?".
*         Close: The operation that Function 'fclose()' tells OS of user environment, "I will not use the file any more."
*
*         FILE* fopen(const char* _FileName, const char* _Mode)
*         [Argument] 
*         const char* _FileName: string text of file name to operate
*         const char* _Mode:     string text of file open purpose
*         [Return]
*         FILE*: File Pointer Type
*           If it success to open the file, value of FILE* is corresponding with address (= location) in the opened file contents, as one by one.
*           If it failure to open the file, value of FILE* is assigned 'NULL' (means no reference), which is called "NULL Pointer",
*           in this case, program need check NULL, nevertheless it behave unexpectedly or exit unusually.
*           
*         ◆File Open Mode 
*         "r":  Text File to read
*         "w":  Text File to write (file length is 0.)
*         "a":  Text File to append writing
*         "rb": Binary File to read
*         "wb": Binary File to write (file length is 0.)
*         "ab": Binary File to append writing
*         "r+": Text File to read and write
*         "w+": Text File to read and write (file length is 0.)
*         "a+": Text File to read and append writing
*         "r+b" or "rb+": Binary File to read and write
*         "w+b" or "wb+": Binary File to read and write (file length is 0.)
*         "a+b" or "ab+": Binary File to read and append writing
* 
*         ＊NOTE
*         Text File:   Human can read and write its contents, can operate with Text-Editor,
*                      and define with extension [.txt].
*         Binary File: Machine Language described only '0' and '1', usally cannot be understand by human.
*                      It cannot read and write usual Text-Editor, but can do by Binary-Editor. 
*                      For example, Execute File of Windows [.exe], Object File yielded by C language Compile [.obj],
*                      Image File [.jpg][.gif][.png], Music File [.mp3][.wav], Movie File [.mp4][.mpeg] etc...
*         Read:  Program <- File
*         Write: Program -> File
* 
*@subject ◆Line Feed Character (Depending on Text Editor Settings)
*         ・when read, '\n' -> divide CR [Carriage Return], LF [Line Feed] -> '\x0D', '\x0A'
*         ・when write, '\x0D', '\x0A' -> CR, LF -> '\n'
*         ・'\x1A' [Ctrl + Z] is recognized as 'EOF' [End of File]
* 
*@subject ◆Void Cast
*         If program need not check NULL or else Errors, in sense of telling it obviously,
*         you can explicitly add '(void)' before the function calling, as meaning to ignore the return-value.
*          
*         [Example]
*         (void)func(x, y);
* 
*@see
*@author shika
*@date 2023-01-06
*/

#include <stdio.h>

void consoleInput(char*, int);

//int main(void) {
int mainFileOpenInputSample(void) {
    char fileName[FILENAME_MAX];
        // = { "..\\C99YH07_WhileIteration\\lorem.txt" };
        // <stdio.h> -- #define FILENAME_MAX 260

    printf("◆Please input File Name > ");
    consoleInput(fileName, FILENAME_MAX);

    //FILE* fileP = fopen(fileName, "r");
    FILE* fileP = fopen_s(stdout, fileName, "r"); 
        // In temporary, 'fopen_s()' is active, for another code compile. This shows nothing still now.
        // When execute, Exchange comment-out of 'fopen()' and 'fopen_s()'.

    if (fileP == NULL) {
        printf("<！> Not Found this file [%s]. \n", fileName);
        return -1;
    }

    //---- Read File and Show File ----
    int c;
    while ((c = fgetc(fileP)) != EOF) {
        putchar(c);
    }//while

    if (fclose(fileP)) {
        printf("<！> Closing Error: [%s]", fileName);
        return -1;
    }

    return 0;
}//main()

//====== already defined in C99YH08_Function\DividedCompile_consoleInputBody.c ======
//void consoleInput(char* buffer, int bufferSize) {
//    char* inputAry = fgets(buffer, bufferSize, stdin);
//
//    if (inputAry == NULL) {
//        buffer[0] = '\0';
//        return;
//    }
//
//    for (int i = 0; i < bufferSize; i++) {
//        if (buffer[i] == '\n') {
//            buffer[i] = '\0';
//            return;
//        }
//    }//for
//}//consoleInput()

/*
//====== [Windows Command Prompt for VS2019] Execution ======
//---- Fixed File Name Version ----
when 'char fileName[FILENAME_MAX] = { "..\\C99YH07_WhileIteration\\lorem.txt" };'

>cd C:\...\C99YH\C99YH12_FileOperation

>cl MainFileOpenInputSample.c
MainFileOpenInputSample.c
/out:MainFileOpenInputSample.exe
MainFileOpenInputSample.obj

>MainFileOpenInputSample
Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed
do eiusmod tempor incididunt ut labore et dolore magna aliqua.
Ut enim ad minim veniam, quis nostrud exercitation ullamco
laboris nisi ut aliquip ex ea commodo consequat.  Duis aute
irure dolor in reprehenderit in voluptate velit esse cillum
dolore eu fugiat nulla pariatur.  Excepteur sint occaecat
cupidatat non proident, sunt in culpa qui officia deserunt mollit
anim id est laborum.

//---- Console Input Version ----
>cd C:\...\C99YH\C99YH12_FileOperation

>cl MainFileOpenInputSample.c
MainFileOpenInputSample.c
/out:MainFileOpenInputSample.exe
MainFileOpenInputSample.obj

>MainFileOpenInputSample
◆Please input File Name > ..\\C99YH07_WhileIteration\\lorem.txt

Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed
do eiusmod tempor incididunt ut labore et dolore magna aliqua.
Ut enim ad minim veniam, quis nostrud exercitation ullamco
laboris nisi ut aliquip ex ea commodo consequat.  Duis aute
irure dolor in reprehenderit in voluptate velit esse cillum
dolore eu fugiat nulla pariatur.  Excepteur sint occaecat
cupidatat non proident, sunt in culpa qui officia deserunt mollit
anim id est laborum.

*/