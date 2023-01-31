/**
*@directory ClangC11Console / ClanC11Sample / C99YH / C99YH12_FileOperation
*@fileName  PracticeC99YH12.c
*@reference C99YH    結城 浩 『C言語プログラミングレッスン [入門編] 第３版』SB Creative, 2019
*@reference CAnsiYH  結城 浩 『C言語プログラミングレッスン [文法編] 新版』  SB Creative, 2006
*@reference C11DS    arton  『独習 C 新版』翔泳社, 2018
*
*@content C99YH Chapter 12 FileOperation | Practice / List E12-1, E12-2 / p422
*@summary PracticeC99YH12.c
*@English [英] appropriate: 適切に、的確に
* 
*@subject Practice 12-1: 
*         Complete the program List E12-1 which shows the first 5 lines of multi-files,
*         given by Command Line Argument.
* 
*         [Assist to Solve]
*         The '#define' Directive should be appropriately defined some constant values.
* 
*         [My Anawer] in Appendix below
*         -> Wrong, see Appwndix【Consideration】
* 
*         ＊Execute Prcedure 
*         ・Change comment-out of 'main()' to be active.
*         ・Exchange comment-out of 'fopen()' to be active and 'fopen_s() to be negative.
*         ・Open [Windows Commnad Prompt for VS2019]
*          
*          >cd (current directory)
*          >cl PracticeC99YH12.c
*          >PracticeC99YH12 loremCopy.txt 12stats-output.txt
*          
*          (Return back the whole changing above for another code Compile, when you finished to execute here.)  
* 
*         => [Book Anawer] in code
* 
*@subject Practice 12-2:
*         Complete the program List E12-2 which shows 16-decimal value of the files,
*         given by Commnad Line Argument.
*         It is called "Hexa-decimal Dump Prgram".
* 
*         [Annotation]
*         ・At left side, it shows the number of lines as 16-decimal.
*         ・It usually insert white-space ' ' between values, 
*           at center only, insert '-'.
* 
*         [Assist to Solve]
*         Variable 'offset' has the value how Bytes from file-top, now.
*         
*         [My Answer] in code
*         -> Correct
*@see
*@author shika
*@date 2023-01-14
*/

#include <stdio.h>

#define SHOWLINE_MAX 5
#define BUFFER_SIZE 1024

void show5LinesInFile(char*);
void showDump(char*);

//int main(int argc, char* argv[]) {
int mainPracticeC99YH12(int argc, char* argv[]) {
    
    //---- Validate Execute Format ----
    if(argc < 2) {
        printf("<！> Invalid Execute Format!\n");
        printf("Should do with some files name.\n");
        return -1;
    }

    //====== Practice 12-1 [Book Answer] ======
    for (int i = 1; i < argc; i++) {
        show5LinesInFile(argv[i]);
        printf("\n");
    }//for
    
    //====== Practice 12-2 ======    
    showDump(argv[1]);
    printf("\n");
    
    printf("(EXIT_SUCCESS)\n");
    return 0;
}//main()

//====== Practice 12-1 ======
void show5LinesInFile(char* fileName) {
    char buffer[BUFFER_SIZE];

    //FILE* fileP = fopen(fileName, "r");            //When execute, be active
    FILE* fileP = fopen_s(stdin, fileName, "r"); //In temporary for another Compile.
    
    if (fileP == NULL) {
        printf("<！> Not Found the file [ %s ].\n", fileName);
        return;
    }

    printf("+++++ %s +++++\n", fileName);

    for (int j = 0; j < SHOWLINE_MAX; j++) {
        if (fgets(buffer, BUFFER_SIZE, fileP) == NULL) {
            fprintf(stderr, "<！> Error when it read File.\n");
            return;
        }

        printf("%s", buffer);
    }//for j

    if (fclose(fileP)) {
        fprintf(stderr, "<！> Error when close file [%s].\n", fileName);
        return;
    }
}//show5LinesInFile()

//====== Practice 12-2 ======
void showDump(char* fileName) {
    //FILE* fileP = fopen(fileName, "rb");            //When execute, be active
    FILE* fileP = fopen_s(stdin, fileName, "rb"); //In temporary for another Compile.
    
    if (fileP == NULL) {
        printf("<！> Not Found the file [ %s ].\n", fileName);
        return;
    }

    printf("+++++ %s +++++\n", fileName);

    int c;
    long offset = 0L;
    printf("%08lX:", offset);

    while((c = fgetc(fileP)) != EOF){
        if (offset != 0 
            && offset % 8 == 0 
            && offset % 16 != 0) {
            printf("-");
        }
        else {
            printf(" ");
        }

        printf("%02X", (unsigned char)c);
        offset++;

        if (offset != 0 && offset % 16 == 0) {
            printf("\n");
            printf("%08lX:", offset);
        }
    }//while

    if (fclose(fileP)) {
        fprintf(stderr, "<！> Error when close file [%s].\n", fileName);
        return;
    }
}//showDump()

/*
//###### Appendix ######
//====== Practice 12-1 [Windows Command Prompt for VS2019] Execution ======
>cd C:\...\C99YH\C99YH12_FileOperation
>cl PracticeC99YH12.c
PracticeC99YH12.c
/out:PracticeC99YH12.exe
PracticeC99YH12.obj

>PracticeC99YH12 loremCopy.txt 12stats-output.txt

+++++ loremCopy.txt +++++
Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed
do eiusmod tempor incididunt ut labore et dolore magna aliqua.
Ut enim ad minim veniam, quis nostrud exercitation ullamco
laboris nisi ut aliquip ex ea commodo consequat.  Duis aute
irure dolor in reprehenderit in voluptate velit esse cillum

+++++ 12stats-output.txt +++++
== Schoolmate Count ==
6 persons

== Schoolmates in order of ID ==
(  1) ID: 101 Name: 佐藤花子       |  65  90 100  80  73  | Total: 408.00 Average: 81.60

(EXIT_SUCCESS)

//====== Practice 12-2 Result ======
>PracticeC99YH12 loremCopy.txt
+++++ loremCopy.txt +++++
00000000: 4C 6F 72 65 6D 20 69 70-73 75 6D 20 64 6F 6C 6F
00000010: 72 20 73 69 74 20 61 6D-65 74 2C 20 63 6F 6E 73
00000020: 65 63 74 65 74 75 72 20-61 64 69 70 69 73 63 69
00000030: 6E 67 20 65 6C 69 74 2C-20 73 65 64 0D 0A 64 6F
00000040: 20 65 69 75 73 6D 6F 64-20 74 65 6D 70 6F 72 20
00000050: 69 6E 63 69 64 69 64 75-6E 74 20 75 74 20 6C 61
00000060: 62 6F 72 65 20 65 74 20-64 6F 6C 6F 72 65 20 6D
00000070: 61 67 6E 61 20 61 6C 69-71 75 61 2E 0D 0A 55 74
00000080: 20 65 6E 69 6D 20 61 64-20 6D 69 6E 69 6D 20 76
00000090: 65 6E 69 61 6D 2C 20 71-75 69 73 20 6E 6F 73 74
000000A0: 72 75 64 20 65 78 65 72-63 69 74 61 74 69 6F 6E
000000B0: 20 75 6C 6C 61 6D 63 6F-0D 0A 6C 61 62 6F 72 69
000000C0: 73 20 6E 69 73 69 20 75-74 20 61 6C 69 71 75 69
000000D0: 70 20 65 78 20 65 61 20-63 6F 6D 6D 6F 64 6F 20
000000E0: 63 6F 6E 73 65 71 75 61-74 2E 20 20 44 75 69 73
000000F0: 20 61 75 74 65 0D 0A 69-72 75 72 65 20 64 6F 6C
00000100: 6F 72 20 69 6E 20 72 65-70 72 65 68 65 6E 64 65
00000110: 72 69 74 20 69 6E 20 76-6F 6C 75 70 74 61 74 65
00000120: 20 76 65 6C 69 74 20 65-73 73 65 20 63 69 6C 6C
00000130: 75 6D 0D 0A 64 6F 6C 6F-72 65 20 65 75 20 66 75
00000140: 67 69 61 74 20 6E 75 6C-6C 61 20 70 61 72 69 61
00000150: 74 75 72 2E 20 20 45 78-63 65 70 74 65 75 72 20
00000160: 73 69 6E 74 20 6F 63 63-61 65 63 61 74 0D 0A 63
00000170: 75 70 69 64 61 74 61 74-20 6E 6F 6E 20 70 72 6F
00000180: 69 64 65 6E 74 2C 20 73-75 6E 74 20 69 6E 20 63
00000190: 75 6C 70 61 20 71 75 69-20 6F 66 66 69 63 69 61
000001A0: 20 64 65 73 65 72 75 6E-74 20 6D 6F 6C 6C 69 74
000001B0: 0D 0A 61 6E 69 6D 20 69-64 20 65 73 74 20 6C 61
000001C0: 62 6F 72 75 6D 2E 0D 0A
(EXIT_SUCCESS)

//====== Practice 12-1 [My Answer] ======
=> Compile Warning in PracticeC99YH12.c
PracticeC99YH12.c
(65): warning C4047: '関数': 間接参照のレベルが 'const char *' と 'char' で異なっています。
(65): warning C4024: 'fopen': の 型が 1 の仮引数および実引数と異なります。
(69): warning C4047: '初期化中': 間接参照のレベルが 'char' と 'char *' で異なっています。

【Consideration】
=> I modified to delete 'fileNamePAry', to substitute it 'argv[i]'.
   The '#define FILE_MAX' is not necessary, should be 'argc'.
   -> Compile OK.
   -> It shows nothing.

=> Give up 
-> to [Book Answer] in code

#define FILE_MAX 3
#define SHOWLINE_MAX 5
#define BUFFER_SIZE 1024

int main(int argc, char* argv[]) {
//int mainPracticeC99YH12(int argc, char* argv[]) {
    char* fileNamePAry[FILE_MAX];
    char buffer[BUFFER_SIZE];

    //---- Validate Execute Format ----
    if(argc == 1) {
        printf("<！> Invalid Execute Format!\n");
        printf("Should do with some files name.\n");
        return -1;
    }

    //---- Get file name from Command Line Argument ----
    for (int i = 0; i < FILE_MAX; i++) {
        fileNamePAry[i] = argv[i + 1];
    }//for

    for (int i = 0; i < FILE_MAX; i++) {
        if (fileNamePAry[i] == NULL) {
            break;
        }

        FILE* fileP = fopen(*fileNamePAry[i], "r");            //When execute, be active
        //(65): warning C4047: '関数': 間接参照のレベルが 'const char *' と 'char' で異なっています。
        //(65): warning C4024: 'fopen': の 型が 1 の仮引数および実引数と異なります。
        //FILE* fileP = fopen_s(stdin, *fileNamePAry[i], "r"); //In temporary for another Compile.

        for (int j = 0; j < SHOWLINE_MAX; j++) {
            char line = fgets(buffer, BUFFER_SIZE, fileP);
            //(69): warning C4047: '初期化中': 間接参照のレベルが 'char' と 'char *' で異なっています。

            fprintf(stdout, "%s\n", buffer);
        }//for j

        if (fclose(fileP)) {
            fprintf(stderr, "<！> Error when close file [%s].\n", fileNamePAry[i]);
            return -1;
        }
    }//for i

    printf("(EXIT_SUCCESS)\n");
    return 0;
}//main()

*/