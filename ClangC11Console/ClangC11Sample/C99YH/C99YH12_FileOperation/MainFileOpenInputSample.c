/**
*@directory ClangC11Console / ClanC11Sample / C99YH / C99YH12_FileOperation
*@fileName  MainFileOpenInputSample.c
*@reference C99YH    Œ‹é _ wCŒ¾ŒêƒvƒƒOƒ‰ƒ~ƒ“ƒOƒŒƒbƒXƒ“ [“ü–å•Ò] ‘æ‚R”ÅxSB Creative, 2019
*@reference CAnsiYH  Œ‹é _ wCŒ¾ŒêƒvƒƒOƒ‰ƒ~ƒ“ƒOƒŒƒbƒXƒ“ [•¶–@•Ò] V”Åx  SB Creative, 2006
*@reference C11DS    arton  w“ÆK C V”ÅxãÄ‰jĞ, 2018
*
*@content C99YH ‘æ12Í FileOperation | Chapter 12 / List 12-1 / p384
*@summary MainFileOpenInputSample.c
*@English [‰p] procedure:      è‡
*         [P]  relative path:  ‘Š‘ÎƒpƒX
*         [P]  CR: carriage return •œ‹AAs‚Ìæ“ª‚É–ß‚·A‰üs
*         [P]  LF: line feed       ‰üs
*         [‰p] correspond:     ‘Î‰‚·‚éA‘Š“–‚·‚éAˆê’v‚·‚éA’²˜a‚·‚éA’ÊM‚·‚é
*         [‰p] explicit:       –¾¦“I  <-> implicit ˆÃ–Ù“I
* 
*@subject ŸExecute Procedure
*         ECopy the file name as relative path [ ..\\C99YH07_WhileIteration\\lorem.txt ].
*         EChange comment-out of 'main()' to active.
*         EChange comment-out of 'consoleInput()' definition to active.
*         EChange comment-out of 'fopen()' to active and 'fopen_s()' to negative.
*         EExecute by [Windows Command Prompt for VS2019]
*           (because, C11-compiled by Visual Studio, it throws Compile Error by cause of 'fopen() unsafe'.)
*         EIt asks file name ,and then Paste the file name and [Enter] Key.
*         E(Return back whole of changes for another Compile, after execution here.)
* 
*         [Example]
*         Please input File Name > ..\\C99YH07_WhileIteration\\lorem.txt
*
*@subject <stdio.h>  [INDEX]
*            „¤ #define stdin  (= Standard Input)   
*                          //It usually means "input by key board", can be changed by 'fgets()' Redirect Operation.
*                          =>kC99YH03_Variable\MainMultipleQuestViewer.cl
*            „¤ #define stdout (= Standard Output) 
*                          //It usually means "output to Console", can be changed by 'fgets()' Redirect Operation.
*                          =>kC99YH03_Variable\MainMultipleQuestViewer.cl
*            „¤ #define stderr
*            „¤ #define FILENAME_MAX 260 //The maximum number of character as file name including directory path and '\0' NULL Character
*            „¤ #define FOPEN_MAX 20     //The maximum number which OS of user environment can open files at same time
*            „¤ #define NULL 0           //It means no reference or NULL Pointerkbelowl
*            „¤ #define EOF -1           //End of File
*                          =>kC99YH07_WhileIteration\MainWhileIterationSample.cl
*
*            „¤ int     printf(char format [, T value1] [, T value2] ...) 
*                          => kC99YH01_ConsoleOutput\MainPrintfSample.cl
*        [~] „¤ FILE*   fopen(const char* _FileName, const char* _Mode)  kbelowl
*            „¤ errno_t fopen_s(FILE* _Stream, const char _FileName, const char _Mode) //(Editing...)
* 
*            „¤ int     fclose(FILE* _Stream)  kbelowl
*            „¤ int     getchar(void)
*                          If user input multi number of characters, 'while { }' turn continuously as same as the number.
*                          Inputing return-key when user has done the inputs, is recognized one character, white-space too.
*                          The 'return character' is added 'char* inputAry[]' as one char and output as line feed when 'printf()'.
*                          =>kC99YH07_WhileIteration\MainWhileIterationSample.cl
*            „¤ int     putchar(int character) // output character
*                          =>kC99YH07_WhileIteration\MainWhileIterationSample.cl                          
*            „¤ int c   fgetc(FILE*)        // It gets 'char' one by one Byte, from Pointer of the file which has already opend by 'fopen()'. kbelowl
*            „¤ int     fputc(int c, FILE*) // It put 'char' one by one Byte from Pointer given argument, to Console or Save File. kbelowl
*            „¤ char*   fgets(const char* _Buffer, int _MaxCount, FILE* _Stream)
*                          // It gets string text one by one line, not one Byte, from Pointer of copy-file to 'char[] *buffer'.
*                          =>kC99YH03_Variable\MainConsoleInputSample.cl
*            „¤ int     fputs(const char* _Buffer, FILE* _Stream)
*                          // It puts string text one by one line, not one Byte, from argument of 'char[] *buffer' to Pointer of save-file.
* 
*            „¤ int     fprintf(FILE* _Stream, const char* _Format, T ... value);
*                          =>kC99YH11_Pointer\MainSearchDictionaryFromFileViewer.cl
*            „¤ void    fflush(FILE _Stream)  
*                          //It lets OS to output immediately, to prevent late for waiting user input.
*                          =>kC99YH03_Variable\MainMultipleQuestViewer.cl
*            „¤ int?    ferror(FILE*)       // It can verify to be error, or not (= reached EOF).
*
*@subject ŸThe reason why variable 'c' is defined as 'int', not 'char'.
*         EBecause it can recognize 'EOF' exactly, whose value is -1.
*         EIf 'c' is defined as 'char', and if '\xFF' character is in the document,
*           most significant digit of bit does sign-expand, changes to -1,
*           and it is recognized as 'EOF' unexactly, the document is cut off where is not end of file.
*         => see kC99YH p199l
*         => copy from kC99YH07_WhileIteration\MainWhileEOF_withFileLoad.cl
*
*@subject ŸLine Feed Character (Depending on Text Editor Settings)
*         Ewhen read, '\n' -> divide CR [Carriage Return], LF [Line Feed] -> '\x0D', '\x0A'
*         Ewhen write, '\x0D', '\x0A' -> CR, LF -> '\n'
*         E'\x1A' [Ctrl + Z] is recognized as 'EOF' [End of File]
*
*@subject ŸNULL Pointer kC99YH p364l
*         <stdio.h> => INDEXkC99YH12_FileOperation/MainFileOpenInputSample.cl
*            „¤ #define NULL 0
*
*         E'NULL': A symbol meaning "nothing of reference".
*         ENULL Pointer: Pointer can be assigned '0'.  0 means NULL.
*         ENULL Pointer is used to express end of link, when Liner List or Tree Data Structure.
*         EYou can assign NULL to any Pointer.
*         EYou cannot assign any value to NULL Pointer
*         EYou cannot refer to value of NULL Pointer.
*         ENULL Check: Before operate 'p', it is necessary to check if p is NULL or not.
*
*         [Example]
*         int *p;
*         p = NULL;
*
*         [~] *p = 123;  -> Compile Error: NULL pointer assignment,
*                          -> or output unexpected value, or do unexpeted behavior,
*                          -> or enforcely exited by OS.
*
*         [~] printf("%p \n", p);  // when 'p = NULL'
*
*         [Example] NULL Check
*         if (p != NULL) {
*             // write operation: assginment or reference, about 'p' here.
*         }
*
*         => copy fromkC99YH11_Pointer\MainPointerBasic.cl
*
*@subject ŸVoid Cast
*         If program need not check NULL or else Errors, in sense of telling it obviously,
*         you can explicitly add '(void)' before the function calling, as meaning to ignore the return-value.
*
*         [Example]
*         (void)func(x, y);
* 
*@subject ŸFile Open
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
*         ŸFile Open Mode 
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
*         –NOTE
*         Text File:   Human can read and write its contents, can operate with Text-Editor,
*                      and define with extension [.txt].
*         Binary File: Machine Language described only '0' and '1', usally cannot be understand by human.
*                      It cannot read and write usual Text-Editor, but can do by Binary-Editor. 
*                      For example, Execute File of Windows [.exe], Object File yielded by C language Compile [.obj],
*                      Image File [.jpg][.gif][.png], Music File [.mp3][.wav], Movie File [.mp4][.mpeg] etc...
*         Read:  Program <- File
*         Write: Program -> File
*
*@subject ŸFile Close
*         EDon't forget file close, 
*           because FOPEN_MAX the maximum number which OS of user environment can open files at same time, is limited 20 (defined in <stdio.h>). 
*         E(Depending on OS), when you open file, expect to write something there, and remain to open (= do not close),
*           if you reset PC, the file record could be deleted, though you have already written it, but un-saved because of 'not close'.
*           
*         int  fclose(FILE* _Stream)
*         [Argument]  FILE* -Stream:  File Pointer which have already opened.
*         [Return]    int (as bool)
*            0:      correctly
*            EOF -1: uncorrectly
* 
*            [Example] If Conditional Expression were not 0, True. 
*            [~] if (fclose(fileP) != 0) { ... }   //The if-statement means "if fclose() returns true, condition is true".
*                 ||                               //Therefore you can write more simplely: 'if (fclose())'.
*                 ||                               //ŸShould not compare both boolean values
*                 ||                               // => see if-statmentkC99YH04_ConditionalBranch\MainValidateInputSample.cl
*            [Z] if (fclose(fileP)) { ... }
*
*@subject ŸGet char kC99YH p391l
*         Efgetc() get 'char' one by one Byte, from Pointer of the file which has already opend by 'fopen()' with Mode "r" or "rb".
*         EThe operation is continued to read by 'while'-statement, so that whole of file contents can read.
* 
*         <stdio.h>
*         int  fgetc(FILE* fileP)   
*                                  
*         [Argument] FILE* fileP    // Pointer of the file which has already opend by 'fopen()' with Mode "r" or "rb" as mean of readable.
*         [Return]   int c          // defined as 'int', not as 'char', because EOF can be recieved too.
*                      n:      If success to read 'char', it returns the ASCII code (= character code).
*                      EOF -1: End of File, or Error while File Read  -> ferror()
*
*@subject ŸPut char kC99YH p394l
*         Efputc() put 'char' one by one Byte from Pointer given argument, to Console or Save File.
*         
*         <stdio.h>
*         int     fputc(int _Character, FILE* _Stream)  
* 
*         [Argument]
*         int _Character 
*         FILE* fileP:   
*            // Pointer of the file which has already opend by 'fopen()' with Mode "w" or "wb" as mean of writable.
*            //yNotationzfopen() with Mode "w' or "wb"
*            // If the same name file has already existed, the file contents will be deleted, exactly the file size is to be 0.
*            // Be careful confirm if the same name file exist or not.
*         
*@subject ŸVerify to be error or not  kC99YH p392l
*         <stdio.h>
*         int?    ferror(FILE*)    // It can verify to be error, or not (= reached EOF without error).
*
*@see                 
*@author shika
*@date 2023-01-06, 01-07
*/

#include <stdio.h>

void consoleInput(char*, int);

//int main(void) {
int mainFileOpenInputSample(void) {
    char fileName[FILENAME_MAX];
        // = { "..\\C99YH07_WhileIteration\\lorem.txt" };
        // <stdio.h> -- #define FILENAME_MAX 260

    printf("ŸPlease input File Name > ");
    consoleInput(fileName, FILENAME_MAX);

    //FILE* fileP = fopen(fileName, "r");
    FILE* fileP = fopen_s(stdout, fileName, "r"); 
        // In temporary, 'fopen_s()' is active, for another code compile. This shows nothing still now.
        // When execute, Exchange comment-out of 'fopen()' and 'fopen_s()'.
    
    if (fileP == NULL) {
        printf("<I> Not Found this file [%s]. \n", fileName);
        return -1;
    }

    //---- Read File and Show File ----
    int c;
    while ((c = fgetc(fileP)) != EOF) {
        putchar(c);
    }//while

    if (fclose(fileP)) {
        printf("<I> Closing Error: [%s]", fileName);
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
ŸPlease input File Name > ..\\C99YH07_WhileIteration\\lorem.txt

Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed
do eiusmod tempor incididunt ut labore et dolore magna aliqua.
Ut enim ad minim veniam, quis nostrud exercitation ullamco
laboris nisi ut aliquip ex ea commodo consequat.  Duis aute
irure dolor in reprehenderit in voluptate velit esse cillum
dolore eu fugiat nulla pariatur.  Excepteur sint occaecat
cupidatat non proident, sunt in culpa qui officia deserunt mollit
anim id est laborum.

*/