/**
*@directory ClangC11Console / ClanC11Sample / C99YH / C99YH12_FileOperation
*@fileName  MainSchoolmateGradeViewer2_FromFileToFile.c
*@based on  C99YH10_Struct\MainSchoolmateGradeFromFileViewer.c
*@based on  C99YH11_Pointer\MainExchangeValuesEachOther.c
*@reference C99YH    結城 浩 『C言語プログラミングレッスン [入門編] 第３版』SB Creative, 2019
*@reference CAnsiYH  結城 浩 『C言語プログラミングレッスン [文法編] 新版』  SB Creative, 2006
*@reference C11DS    arton  『独習 C 新版』翔泳社, 2018
*
*@content C99YH 第12章 FileOperation | Chapter 12  SchoolmateGradeViewer2 / List 12-8 / p410
*@summary MainSchoolmateGradeViewer2_FromFileToFile.c
*@English
* 
*@prepare 12stats-input.txt 〔Appendix below〕
*         ・Deploy this file in the current directory here.
*         ・It can be copied from Sample Code in Publisher Web page.
* 
*@execute ◆Execute Procedure
*         ・Change comment-out of 'main()' to active.
*         ・ExChange 2 comment-out of 'fopen() to active, 'fopen_s()' to negative in 'main()'.
*         ・Exchange 1 comment-out of 'sscanf()' to active, 'sscanf_s() to negative
*           in 'inputSchoolmateWithPointer()' of here, not in〔C99YH10_Struct\MainSchoolmateGradeFromFileViewer.c〕.
*  
*         ・Open [Windows Command Prompt for VS2019]
*           (because Functions 'fopen()', 'sscanf()' are thrown Error of 'unsafe' by C11 Compiler of VS Execution.)
*         
*         ・>cd (current directory)
*         ・>cl MainSchoolmateGradeViewer2_FromFileToFile.c
*         ・>MainSchoolmateGradeViewer2_FromFileToFile 12stats-input.txt 12stats-output.txt
* 
*         ・(Return back whole of changes for another Compile, after execution here.)
* 
*@subject ◆Requirements Definition / 要件定義
*         ＊[Input Data] from file '12stats-input.txt' as Redirect file
*         ・ID
*         ・Name
*         ・Score of each subject (max 5 subjects)
*
*         ＊[Output caluclated stats] to '12stats-output' as Redirect file
*         ・Name List in order of ID
*         ・Name List in order of totalIndividual score
*         ・Average, Maximum, Minimum of each subjects
*         ・Average of whole students
*
*         => based on copy from〔C99YH10_Struct\MainSchoolmateGradeFromFileViewer.c〕
*
*@subject <stdio.h> => INDEX〔C99YH12_FileOperation/MainFileOpenInputSample.c〕
*        [×] └ FILE*   fopen(const char* _FileName, const char* _Mode)
*            └ errno_t fopen_s(FILE** _Stream, const char* _FileName, const char* _Mode)
*            └ int     fclose(FILE*)
*            └ char*   fgets(char* _Buffer, int _MaxCount, FILE* _Stream)
*
*        [×]: C11 Compile Error, because of 'unsafe'.
* 
*@subject <string.h>
*        [×] └ int     strcpy(char* _Destination, const char* _Source)
*            └ errno_t strcpy_s(char* _Destination, int _SizeInBytes, const char* _Source)
*        [×] └ int     sscanf(const char* _Buffer, const char* _Format, T value ...)
*            └ int     sscanf_s(const char* _Buffer, const char* _Format, T value ...)
*            └ size_t  strlen(const char* _Str)
*
*        [×]: C11 Compile Error, because of 'unsafe'.
* 
*@see C99YH10_Struct\MainSchoolmateGradeFromFileViewer.c
*@author shika
*@date 2023-01-13
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//====== Define Directive ======
#define BUFFER_SIZE 512  //byte size of one row
#define NAME_MAX 50      //byte size of each name
#define MATE_MAX 100     //max number of Schoolmate struct
#define SUBJECT_MAX 5    //max number of subjects

//====== Struct Declaration ======
typedef struct Schoolmate {
    int id;                      // ID
    char name[NAME_MAX];         // Name
    int scoreAry[SUBJECT_MAX];   // score Array of whole subjects
    double totalIndividual;      // totalIndividual of whole subjects
} MATE;

typedef struct SchoolMateData {
    int mateSize;           // element count of 'mateAry' below
    MATE mateAry[MATE_MAX]; // Array of whole Schoolmate struct
} DATA;

//====== Prototype Declaration ======
//int main(int argc, char* argv[]);
int mainSchoolmateGradeViewer2_FromFileToFile(int argc, char* argv[]);
int inputSchoolmateWithPointer(FILE*, DATA*);
void sortByIdWithPointer(DATA*);
void sortByTotalWithPointer(DATA*);
void exchangeMate(MATE*, MATE*);
void writeSchoolmateGrade(FILE*, DATA*);
void writeCaluclatedStats(FILE*, DATA*);

//====== Function Definition ======
//int main(int argc, char* argv[]) {
int mainSchoolmateGradeViewer2_FromFileToFile(int argc, char* argv[]) {
    DATA data; 

    //---- Validate Command Line Argument ----
    if(!(argc == 2 || argc == 3)) {
        printf("<！> Invalid Execute Format! \n");
        printf("[Format] when execute \n");
        printf(">%s 12stats-input.txt 12stats-output.txt \n", argv[0]);
        return -1;
    }

    char* inputFileName[FILENAME_MAX] = { argv[1] };
    char* outputFileName[FILENAME_MAX] = { argv[2] };

    //---- Open Files ----
    //FILE* inputFileP = fopen(*inputFileName, "r");            //when Command Prompt execute
    FILE* inputFileP = fopen_s(stdin, *inputFileName, "r"); //in temporary for another compile

    if (inputFileP == NULL) {
        fprintf(stderr, "<！> Not Found Input File [ %s ]. \n", *inputFileName);
        return -1;
    }

    FILE* outputFileP = stdout;
    if (argc == 3) {
        //outputFileP = fopen(*outputFileName, "w");             //when Command Prompt execute
        outputFileP = fopen_s(stdout, *outputFileName, "w"); //in temporary for another compile

        if (outputFileP == NULL) {
            fprintf(stderr, "<！> Output File [ %s ] cannot create,\nor has already existed the same name file. \n", *outputFileName);
            return -1;
        }
    }
    
    //---- Load Data ----
    if (inputSchoolmateWithPointer(inputFileP, &data) < 0) {
        printf("<！> Error when Load Data.\n");
        return -1;
    }

    //---- Show Schoolmate Count or Write to File ----
    fprintf(outputFileP, "== Schoolmate Count ==\n");
    fprintf(outputFileP, "%d persons\n", data.mateSize);
    fprintf(outputFileP, "\n");

    //---- Show Name List soted by ID or Write to File ----
    fprintf(outputFileP, "== Schoolmates in order of ID ==\n");
    sortByIdWithPointer(&data);
    writeSchoolmateGrade(outputFileP, &data);
    fprintf(outputFileP, "\n");

    //---- Show Name List sorted by totalIndividual score or Write to File ----
    fprintf(outputFileP, "== Schoolmates in order of individual Total Score ==\n");
    sortByTotalWithPointer(&data);
    writeSchoolmateGrade(outputFileP, &data);
    fprintf(outputFileP, "\n");

    //---- Show Caluculated Stats or Write to File ----
    fprintf(outputFileP, "== Culculated Stats of each subjects and whole subjects ==\n");
    writeCaluclatedStats(outputFileP, &data);
    fprintf(outputFileP, "\n");

    //---- Close Files ----
    if (fclose(outputFileP)) {
        printf("<！> Error when Close Output File [ %s ].\n", *outputFileName);
        fclose(inputFileP);
        return -1;
    }

    if (fclose(inputFileP)) {
        printf("<！> Error when Close Input File [ %s ].\n", *inputFileName);
        return -1;
    }

    printf("(EXIT_SUCCESS) \n");
    return 0;
}//main()

//====== based on C99YH10_Struct\MainSchoolmateGradeFromFileViewer.c ======
int inputSchoolmateWithPointer(FILE* inputFileP, DATA *dataP) {
    char buffer[BUFFER_SIZE];
    char nameBuffer[BUFFER_SIZE];
    int n = 0;  //Schoolmate Count for local

    //---- Load Data ----
    while (fgets(buffer, BUFFER_SIZE, inputFileP) != NULL) {
        if (n >= MATE_MAX) {
            printf("<！> Too many numbers of Schoolmate in Data File. [within %d persons]\n", MATE_MAX);
            return -1;
        }

        //---- Pointer to add load data to 'mateAry' ----
        MATE* mateP = &dataP -> mateAry[n];

        //---- Parse load data by Function 'sscanf()' ----
        //int dataNum = sscanf(buffer, "%d %s %d %d %d %d %d\n",      //when Command Prompt execute
        int dataNum = sscanf_s(buffer, "%d %s %d %d %d %d %d\n",  //in temporary for another compile
            &mateP->id,
            &nameBuffer[0],
            &mateP->scoreAry[0],
            &mateP->scoreAry[1],
            &mateP->scoreAry[2],
            &mateP->scoreAry[3],
            &mateP->scoreAry[4]
        );

        //Check loaded data type
        if (dataNum != 7) {
            fprintf(stderr, "<！> Data is wrong with the type, under Row %d.\n", n + 1);
            fprintf(stderr, "Data: %s\n", buffer);
            return -1;
        }

        //Check name length to prevent OverFlow / ±1 is for '\0'
        if (strlen(nameBuffer) + 1 > NAME_MAX) {
            fprintf(stderr, "<！> Too long character of the Name under Row %d. [within %d Bytes]\n",
                n + 1, NAME_MAX - 1);
            fprintf(stderr, "Name: %s\n", nameBuffer);
            return -1;
        }

        //---- copy Name to struct.name ----
        strcpy_s(mateP->name, NAME_MAX, nameBuffer);

        //---- calculate totalIndividual score and assign to struct.totalIndividual ----
        mateP->totalIndividual = 0;
        for (int i = 0; i < SUBJECT_MAX; i++) {
            mateP->totalIndividual += mateP->scoreAry[i];
        }

        //increment Schoolmate Count for local
        n++;
    }//while

    //whole Schoolmate Count of File Data 
    dataP -> mateSize = n;

    return dataP -> mateSize;
}//inputSchoolmateWithPointer()

void sortByIdWithPointer(DATA *dataP) {
    for (int i = 0; i < (dataP -> mateSize - 1); i++) {
        MATE* matePi = (&dataP -> mateAry[i]);

        for (int j = i + 1; j < (dataP -> mateSize); j++) {
            MATE* matePj = (&dataP -> mateAry[j]);

            if ((matePi->id) > (matePj->id)) {  //ascending of ID
                exchangeMate(matePi, matePj);   //self-defined below
            }
        }//for j
    }//for i
}//sortByIdWithPointer()

void sortByTotalWithPointer(DATA *dataP) {
    for (int i = 0; i < (dataP -> mateSize - 1); i++) {
        MATE* matePi = (&dataP -> mateAry[i]);

        for (int j = i + 1; j < (dataP -> mateSize); j++) {
            MATE* matePj = (&dataP -> mateAry[j]);

            if ((matePi->totalIndividual) < (matePj->totalIndividual)) {  //descending of totalIndiviual
                exchangeMate(matePi, matePj); //self-defined below
            }
        }//for j
    }//for i
}//sortByTotalWithPointer()

void writeSchoolmateGrade(FILE* outputFileP, DATA* dataP) {
    for (int n = 0; n < (dataP -> mateSize); n++) {
        MATE* mateP = (&dataP -> mateAry[n]);

        //auto increment
        fprintf(outputFileP, "(%3d) ", n + 1);

        //ID
        fprintf(outputFileP, "ID: %3d ", mateP->id);

        //Name
        fprintf(outputFileP, "Name: %-14s | ", mateP->name);

        //socre
        for (int i = 0; i < SUBJECT_MAX; i++) {
            fprintf(outputFileP, "%3d ", mateP->scoreAry[i]);
        }//for i

        //totalIndividual
        fprintf(outputFileP, " | Total: %0.2f ", mateP->totalIndividual);

        //average 
        fprintf(outputFileP, "Average: %0.2f ", mateP->totalIndividual / SUBJECT_MAX);
        fprintf(outputFileP, "\n");
    }//for n
}//writeSchoolmateGrade()

void writeCaluclatedStats(FILE* outputFileP, DATA* dataP) {
    int max[SUBJECT_MAX];              //max of each subject
    int min[SUBJECT_MAX];              //min of each subject
    double totalSubject[SUBJECT_MAX];  //total of each subject
    double totalWhole;                 //total of whole subjects

    MATE* mateP;

    //---- initialized by index 0 data ---
    mateP = (&dataP -> mateAry[0]);

    for (int i = 0; i < SUBJECT_MAX; i++) {
        max[i] = mateP->scoreAry[i];
        min[i] = mateP->scoreAry[i];
        totalSubject[i] = (mateP -> scoreAry[i]);
    }//for i

    totalWhole = (mateP -> totalIndividual);

    //---- Caluculate Data ----
    for (int n = 1; n < (dataP -> mateSize); n++) {  // 'n = 0' already has read above.
        mateP = (&dataP -> mateAry[n]);

        for (int i = 0; i < SUBJECT_MAX; i++) {
            if (max[i] < (mateP -> scoreAry[i])) {
                max[i] = (mateP -> scoreAry[i]);
            }

            if (min[i] > (mateP -> scoreAry[i])) {
                min[i] = (mateP -> scoreAry[i]);
            }

            totalSubject[i] += (mateP -> scoreAry[i]);
        }//for i

        totalWhole += (mateP -> totalIndividual);
    }//for n

    //---- Show Caluculated Stats ----
    for (int i = 0; i < SUBJECT_MAX; i++) {
        fprintf(outputFileP, "Subject %d: ", i + 1);
        fprintf(outputFileP, "Maximum: %3d / ", max[i]);
        fprintf(outputFileP, "Minimum: %3d / ", min[i]);
        fprintf(outputFileP, "Average: %0.2f \n", totalSubject[i] / (dataP -> mateSize));
    }//for i

    fprintf(outputFileP, "Average of Total: %0.2f \n", totalWhole / (dataP -> mateSize));
}//writeCaluclatedStats()

//====== based on C99YH11_Pointer\MainExchangeValuesEachOther.c ======
void exchangeMate(MATE* p, MATE* q) {
    MATE temp = *p;
    *p = *q;
    *q = temp;
}//exchangeMate()


/*
//###### Appendix ######
//====== 12stats-input ======
101 佐藤花子 65 90 100 80 73
102 阿部和馬 82 75 63 21 45
103 伊藤光一 74 31 41 59 38
104 佐藤太郎 100 95 98 82 65
105 村松真治 55 48 79 90 88
106 進東三太郎 74 45 59 27 38


//====== Execute [Windows Command Prompt for VS2019] ======
>cd C:\...\C99YH\C99YH12_FileOperation

>cl MainSchoolmateGradeViewer2_FromFileToFile.c
MainSchoolmateGradeViewer2_FromFileToFile.c
/out:MainSchoolmateGradeViewer2_FromFileToFile.exe
MainSchoolmateGradeViewer2_FromFileToFile.obj

>MainSchoolmateGradeViewer2_FromFileToFile 12stats-input.txt 12stats-output.txt
(EXIT_SUCCESS)

//====== 12stats-output.txt ======
>type 12stats-output.txt
== Schoolmate Count ==
6 persons

== Schoolmates in order of ID ==
(  1) ID: 101 Name: 佐藤花子       |  65  90 100  80  73  | Total: 408.00 Average: 81.60
(  2) ID: 102 Name: 阿部和馬       |  82  75  63  21  45  | Total: 286.00 Average: 57.20
(  3) ID: 103 Name: 伊藤光一       |  74  31  41  59  38  | Total: 243.00 Average: 48.60
(  4) ID: 104 Name: 佐藤太郎       | 100  95  98  82  65  | Total: 440.00 Average: 88.00
(  5) ID: 105 Name: 村松真治       |  55  48  79  90  88  | Total: 360.00 Average: 72.00
(  6) ID: 106 Name: 進東三太郎     |  74  45  59  27  38  | Total: 243.00 Average: 48.60

== Schoolmates in order of individual Total Score ==
(  1) ID: 104 Name: 佐藤太郎       | 100  95  98  82  65  | Total: 440.00 Average: 88.00
(  2) ID: 101 Name: 佐藤花子       |  65  90 100  80  73  | Total: 408.00 Average: 81.60
(  3) ID: 105 Name: 村松真治       |  55  48  79  90  88  | Total: 360.00 Average: 72.00
(  4) ID: 102 Name: 阿部和馬       |  82  75  63  21  45  | Total: 286.00 Average: 57.20
(  5) ID: 103 Name: 伊藤光一       |  74  31  41  59  38  | Total: 243.00 Average: 48.60
(  6) ID: 106 Name: 進東三太郎     |  74  45  59  27  38  | Total: 243.00 Average: 48.60

== Culculated Stats of each subjects and whole subjects ==
Subject 1: Maximum: 100 / Minimum:  55 / Average: 75.00
Subject 2: Maximum:  95 / Minimum:  31 / Average: 64.00
Subject 3: Maximum: 100 / Minimum:  41 / Average: 73.33
Subject 4: Maximum:  90 / Minimum:  21 / Average: 59.83
Subject 5: Maximum:  88 / Minimum:  38 / Average: 57.83
Average of Total: 330.00


//---- Test of Invalid Execute ----
<！> Invalid Execute Format!
[Format] when execute
>MainSchoolmateGradeViewer2_FromFileToFile 12stats-input.txt 12stats-output.txt

*/