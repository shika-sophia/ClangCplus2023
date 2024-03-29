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
*         [英] abbreviation:   省略、短縮
* 
*@subject ◆Execute Procedure
*         ・Copy the file name as relative path [ ..\\C99YH07_WhileIteration\\lorem.txt ].
*         ・Change comment-out of 'main()' to active.
*         ・Change comment-out of 'consoleInput()' definition to active.
*         ・Change comment-out of 'fopen()' to active and 'fopen_s()' to negative.
*         ・Execute by [Windows Command Prompt for VS2019]
*           (because, C11-compiled by Visual Studio, it throws Compile Error by cause of 'fopen() unsafe'.)
*         ・It asks file name ,and then Paste the file name and [Enter] Key.
*         ・(Return back whole of changes for another Compile, after execution here.)
* 
*         [Example]
*         Please input File Name > ..\\C99YH07_WhileIteration\\lorem.txt
*
*@subject <stdio.h>  [INDEX] integrated whole C99YH
*            └ #define stdin  (= Standard Input)   
*                          //It usually means "input by key board", can be changed by 'fgets()' Redirect Operation.
*                          =>〔C99YH03_Variable\MainMultipleQuestViewer.c〕
*            └ #define stdout (= Standard Output) 
*                          //It usually means "output to Console", can be changed by 'fgets()' Redirect Operation.
*                          =>〔C99YH03_Variable\MainMultipleQuestViewer.c〕
*            └ #define stderr
*            └ #define FILENAME_MAX 260 //The maximum number of character as file name including directory path and '\0' NULL Character
*            └ #define FOPEN_MAX 20     //The maximum number which OS of user environment can open files at same time
*            └ #define NULL 0           //It means no reference or NULL Pointer〔below〕
*            └ #define EOF -1           //End of File
*                          =>〔C99YH07_WhileIteration\MainWhileIterationSample.c〕
*
*            └ int     printf(const char format [, T value1] [, T value2] ...) 
*                          => 〔C99YH01_ConsoleOutput\MainPrintfSample.c〕
*        [×] └ FILE*   fopen(const char* _FileName, const char* _Mode)  〔below〕
*            └ errno_t fopen_s(FILE* _Stream, const char _FileName, const char _Mode) //(Editing...)
* 
*            └ int     fclose(FILE* _Stream)  〔below〕
*            └ int     getchar(void)
*                          If user input multi number of characters, 'while { }' turn continuously as same as the number.
*                          Inputing return-key when user has done the inputs, is recognized one character, white-space too.
*                          The 'return character' is added 'char* inputAry[]' as one char and output as line feed when 'printf()'.
*                          =>〔C99YH07_WhileIteration\MainWhileIterationSample.c〕
*            └ int     putchar(int character) // output character
*                          =>〔C99YH07_WhileIteration\MainWhileIterationSample.c〕                          
*            └ int c   fgetc(FILE*)        // It gets 'char' one by one Byte, from Pointer of the file which has already opend by 'fopen()'. 〔below〕
*            └ int     fputc(int c, FILE*) // It put 'char' one by one Byte from Pointer given argument, to Console or Save File. 〔below〕
*            └ char*   fgets(const char* _Buffer, int _MaxCount, FILE* _Stream)
*                          // It gets string text one by one line, not one Byte, from Pointer of copy-file to 'char[] *buffer'.
*                          => 〔below〕,copy from〔C99YH03_Variable\MainConsoleInputSample.c〕
*            └ int     fputs(const char* _Buffer, FILE* _Stream)
*                          // It puts string text one by one line, not one Byte, from argument of 'char[] *buffer' to Pointer of save-file.
*                          => 〔below〕
*            └ int     fprintf(FILE* _Stream, const char* _Format, T ... value) 〔below〕
*            └ int     remove(const char* _FileName) 〔below〕
*            └ int     rename(const char* _OldFileName, const char* _NewFileName) 〔below〕
*            └ int     fflush(FILE _Stream)  
*                          //It lets OS to output immediately, to prevent late for waiting user input.
*                          =>〔C99YH03_Variable\MainMultipleQuestViewer.c〕
*            └ int     ferror(FILE*)       // It can verify to be error, or not (= reached EOF). 〔below〕
*/
//====== Reference of File Functions ======
/*
*@subject ◆The reason why variable 'c' is defined as 'int', not 'char'.
*         ・Because it can recognize 'EOF' exactly, whose value is -1.
*         ・If 'c' is defined as 'char', and if '\xFF' character is in the document,
*           most significant digit of bit does sign-expand, changes to -1,
*           and it is recognized as 'EOF' unexactly, the document is cut off where is not end of file.
*         => see 〔C99YH p199〕
*         => copy from 〔C99YH07_WhileIteration\MainWhileEOF_withFileLoad.c〕
*
*@subject ◆Line Feed Character (Depending on Text Editor Settings)
*         ・when read, '\n' -> divide CR [Carriage Return], LF [Line Feed] -> '\x0D', '\x0A'
*         ・when write, '\x0D', '\x0A' -> CR, LF -> '\n'
*         ・'\x1A' [Ctrl + Z] is recognized as 'EOF' [End of File]
*
*@subject ◆NULL Pointer 〔C99YH p364〕
*         <stdio.h> => INDEX〔C99YH12_FileOperation/MainFileOpenInputSample.c〕
*            └ #define NULL 0
*
*         ・'NULL': A symbol meaning "nothing of reference".
*         ・NULL Pointer: Pointer can be assigned '0'.  0 means NULL.
*         ・NULL Pointer is used to express end of link, when Liner List or Tree Data Structure.
*         ・You can assign NULL to any Pointer.
*         ・You cannot assign any value to NULL Pointer
*         ・You cannot refer to value of NULL Pointer.
*         ・NULL Check: Before operate 'p', it is necessary to check if p is NULL or not.
*
*         [Example]
*         int *p;
*         p = NULL;
*
*         [×] *p = 123;  -> Compile Error: NULL pointer assignment,
*                          -> or output unexpected value, or do unexpeted behavior,
*                          -> or enforcely exited by OS.
*
*         [×] printf("%p \n", p);  // when 'p = NULL'
*
*         [Example] NULL Check
*         if (p != NULL) {
*             // write operation: assginment or reference, about 'p' here.
*         }
*
*         => copy from〔C99YH11_Pointer\MainPointerBasic.c〕
*
*@subject ◆Void Cast
*         If program need not check NULL or else Errors, in sense of telling it obviously,
*         you can explicitly add '(void)' before the function calling, as meaning to ignore the return-value.
*
*         [Example]
*         (void)func(x, y);
* 
*@subject ◆Function fopen()  = abbreviation of File Open 〔C99YH p387〕
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
*@subject ◆Function fclose()  = abbreviation of File Close 〔C99YH p390〕
*         ・Don't forget file close, 
*           because FOPEN_MAX the maximum number which OS of user environment can open files at same time, is limited 20 (defined in <stdio.h>). 
*         ・(Depending on OS), when you open file, expect to write something there, and remain to open (= do not close),
*           if you reset PC, the file record could be deleted, though you have already written it, but un-saved because of 'not close'.           
*         ・It is not necessary to close file, if 'fopen()' returns NULL.
* 
*         int  fclose(FILE* _Stream)
*         [Argument]  FILE* -Stream:  File Pointer which have already opened.
*         [Return]    int (as bool)
*            0:      correctly
*            EOF -1: uncorrectly
* 
*            [Example] If Conditional Expression were not 0, True. 
*            [×] if (fclose(fileP) != 0) { ... }   //The if-statement means "if fclose() returns true, condition is true".
*                 ||                               //Therefore you can write more simplely: 'if (fclose())'.
*                 ||                               //◆Should not compare both boolean values
*                 ||                               // => see if-statment〔C99YH04_ConditionalBranch\MainValidateInputSample.c〕
*            [〇] if (fclose(fileP)) { ... }
*
*@subject ◆Function fgetc()  = abbreviation of File Get char 〔C99YH p391〕
*         ・fgetc() get 'char' one by one Byte, from Pointer of the file which has already opend by 'fopen()' with Mode "r" or "rb".
*         ・The operation is continued to read by 'while'-statement, so that whole of file contents can read.
* 
*         <stdio.h>
*         int  fgetc(FILE* fileP)   
*                                  
*         [Argument] FILE* fileP    // Pointer of the file which has already opend by 'fopen()' with Mode "r" or "rb" as mean of readable.
*         [Return]   int c          // defined as 'int', not as 'char', because EOF can be recieved too.
*                      n:      If success to read 'char', it returns the ASCII code (= character code).
*                      EOF -1: End of File, or Error while File Read  -> ferror()
*
*@subject ◆Function fputc()  = abbreviation of File Put char 〔C99YH p394〕
*         ・fputc() put 'char' one by one Byte from Pointer given argument, to Console or Save File.
*         
*         <stdio.h>
*         int     fputc(int _Character, FILE* _Stream)  
* 
*         [Argument]
*         int _Character 
*         FILE* fileP:   
*            // Pointer of the file which has already opend by 'fopen()' with Mode "w" or "wb" as mean of writable.
*            //【Annotation】fopen() with Mode "w' or "wb"
*            // If the same name file has already existed, the file contents will be deleted, exactly the file size is to be 0.
*            // Be careful confirm if the same name file exist or not.
*
*@subject ◆Function fgets()  = abbreviation of File Get String 〔C99YH p73, p401〕
*         ・Standard Input (= Console Input as default)
*         ・If 'Redirect', the Standard Input can be changed to File Input.
*              =>〔C99YH12_FileOperation/MainFileCopyStringViewer.c〕
*         ・'\0': NULL Character  // It express the termination of String text.
*         ・NULL:                 // It express no reference or NULL Pointer, defined in <stdio.h>.
*         
*         [Function]
*         char*  fgets(const char *_Buffer, int _MaxCount, FILE _Stream)
*
*         [Argument]
*         char* _Buffer:  Pointer of 'char' Array which storage one line of file contents,
*         (as contatnt)   The Array size is required over the value of second argument 'int _MaxCount'.
* 
*         int _MaxCount:  maximum Bytes + 1 of buffer size to read line. +1 is for '\0' NULL character.
*
*         FILE* _Stream:  ・Pointer of file to read, which need be open by 'fopen()' with Mode "r" as to read, before this operation.
*                         ・[Redirect] Instead of Pointer of file, you can set 'stdin' defined in <stdio.h> as standard input (= usually Console input from Key Board).
*
*         [Return]
*         char*: Pointer of buffer array which was given by argument, and storaged file contents.
*                or NULL Pointer when it reached 'EOF'.
*
*         [Behavior] in case of File Pointer:
*         When execute 'fgets(), it reads charaters from File Pointer, and storages them to buffer array.
*         If it reads '\n' Line Feed Character, it adds '\0' NULL Character as end of string text, to buffer array.
*         If it reads (maximum Bytes - 1) before '\n', it stop to read file and add \0'.
*         Then it returns Pointer of the buffer array.
*         If it has already finish to read, it returns 'NULL' Pointer.
*
*         [Example]
*         char* inputP = fgets(buffer, bufferSize, stdin);
*         while (inputP != NULL) { ... }
*
*         while (fgets(buffer, bufferSize, stdin) != NULL) { ... }
*
*         => copy from〔C99YH03_Variable\MainConsoleInputSample.c〕
*
*@subject ◆Function fputs()  = abbreviation of File Put String〔C99YH p401〕
*         ・It continues to write elements of buffer array to the output file,
*           until element of this is '\0' NULL Character.
*         ・Therefore, if buffer array includes '\0' at middle of the documents,
*           it cannot write whole of document.
* 
*         int  fputs(const char* _Buffer, FILE* _Stream)
* 
*         [Argument]
*         const char* _Buffer: Pointer of 'char' Array
*         FILE* _Stream:       ・Pointer of file to write, which need be open by 'fopen()' with Mode "w" as to write, before this operation.
*                              ・[Redirect] 'stdout' as standard output (= Console output).
*         
*         [Return]
*         plus value: correctly behave
*         EOF -1:     uncorrectly behave (= happen error) or correctly finished to write because of EOF 'End of File'.
*                     If you want to know which above, need check by 'ferror()'.
*
*@subject ◆Different Arguments of 'fgets() and 'fputs()' 〔C99YH p402〕
*         The reason why fgets() has 'int _MaxCount':
*         Because Byte size of one line is unknown, to prevent OverFlow which it read beyond array size,
*         It need notify the Maximum Byte Size of buffer array.
*         By this, fgets() can stop reading before OverFlow.
*
*         Other side, fputs() has alrady had the elements of buffer array to write,
*         it knows the Byte size within buffer array size,
*         it only continue to write the elements until '\0'.
*
*         => copy from〔MainFileCopyStringViewer.c〕
*
*@subject ◆Different Terminal Conditions of While-Iteration with 'fgetc() fputc()' and 'fgets() fputs()':
* 
*         [Example] List 12-3 〔MainFileCopyCommandLineArgumenViewer.c〕
*         while ((c = fgetc(fromFileP)) != EOF) {
*             fputc(c, toFileP);
*         }//while
*
*         [Example] List 12-4 〔MainFileCopyStringViewer.c〕
*         while (fgets(buffer, BUFFER_SIZE, fromFileP) != NULL) {
*            fputs(buffer, toFileP);
*         }//while
*
*         => copy from〔MainFileCopyStringViewer.c〕
*
*@subject ◆Function fprintf()  =abbreviation of File Print Format 〔C99YH p402〕
*         ・It is used, instead of 'fputs(buffer, toFileP);'
*         ・Function 'printf()' write to Console with Format as Standard Output,
            Function 'fprintf()' write to File with Format.
*         ・Argument Format and Value as same printf().
*           =>〔C99YH01_ConsoleOutput\MainPrintfSample.c〕
*
*         int  fprintf(FILE* _Stream, const char _Format, [T value ...])
*         [Argument]
*         FILE* _Stream:      Pointer of file which is opened by 'fopen()' with Mode 'w' to write, before this operation.
*                             or 'stdout' defined in <stdio.h> as Standard Output (= Console output), which behave as same 'printf()'.
*                             or 'stderr' definrd in <stdio.h> as Standard Error  (= Console Output), for example =>〔C99YH11_Pointer\MainSearchDictionaryFromFileViewer.c〕
*         const char _Format: as same printf().
*         [T value ...]:      as same printf().
*
*         => copy from〔C99YH12_FileOperation\MainFilePrintFormatViewer.c〕
*
*@subject Function remove()  〔C99YH p405〕
*         int  remove(const char* _FileName)
*         [Argument] const char* _FileName
*         [Return]   int 0:     correctly delete the file
*                        not 0: cannot delete because of not exist or else error.
*        【Annotation】To success returns false value '0'.
*                    To fail    retruns true value 'not 0'
*
*         [Example]
*         *fileName = argv[1];
*
*         if (remove(*fileName) != 0) {
*             printf("<！> The file [ %s ] cannot be deleted or is not existed.", *fileName);
*             return -1;
*         }
*
*         printf("<〇> The file [ %s ] has deleted.", *fileName);
*
*         => copy from〔MainFileRemoveSample.c〕
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
*        【Annotation】
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
*         => copy from〔MainFileRenameSample.c〕
*
*@subject ◆Function ferror()  = abbreviation of File Error   〔C99YH p392〕
*         ・It verify to be error or not
* 
*         <stdio.h>
*         int    ferror(FILE*)    // It can verify the code to be error, or not (= reached EOF without error).
*/
/*
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