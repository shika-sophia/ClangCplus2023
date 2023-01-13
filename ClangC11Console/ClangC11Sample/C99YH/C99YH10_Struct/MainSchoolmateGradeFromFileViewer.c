/**
*@directory ClangC11Console / ClanC11Sample / C99YH / C99YH10_Struct
*@fileName  MainSchoolmateGradeFromFileViewer.c
*@reference C99YH  ���� �_ �wC����v���O���~���O���b�X�� [�����] ��R�ŁxSB Creative, 2019
*@reference CAnsi  ���� �_ �wC����v���O���~���O���b�X�� [���@��] �V�Łx  SB Creative, 2006
*@reference C11DS  arton  �w�ƏK C �V�Łx�ĉj��, 2018
*
*@content C99YH ��10�� �\���� | Chapter 10  Struct / List 10-7 / p319
*@summary MainSchoolmateGradeFromFileViewer.c
* 
*@prepare 10stats-input.txt �kAppendix below�l
*         �EDeploy this file in the current directory here.
*         �EThis file can be copied from Sample Code in Publisher Web page.
* 
*@execute ��Execute Procedure
*         �EChange comment-out of 'main()' to active.
*         �EChange comment-out of 'sscanf()' to active, 'sscanf_s() to negative
*           in 'inputSchoolmate(void)' �kbelow�l.
*         �EOpen [Windows Command Prompt for VS2019]
*           (because Funciton 'sscanf()' is thrown Error of 'unsafe' by C11 Compiler of VS Execution.)
* 
*          >cd (current directory)
*          >cl MainSchoolmateGradeFromFileViewer.c
*          >MainSchoolmateGradeFromFileViewer < 10stats-input.txt
* 
*         �E(Return back whole of changes for another Compile, after execution here.)
* 
*@subject ��Requirements Definition / �v����`
*         ��[Input Data] from file '10stats-input.txt' as Redirect file
*         �EID
*         �EName
*         �EScore of each subject (max 5 subjects)
* 
*         ��[Output caluclated stats] to Console as standard output
*         �EName List in order of ID
*         �EName List in order of totalIndividual score
*         �EAverage, Maximum, Minimum of each subjects
*         �EAverage of whole students
*
*         => copy to�kC99YH12_FileOperation\MainSchoolmateGradeViewer2_FromFileToFile.c�l
* 
*@subject int main(void)
*         �Echeck mateAry records is if existed.
*         �ELoad Schoolmate data
*             �� call 'inputSchoolmate()'
*         �EShow Schoolmates Count
*             �� refer to 'int mateSize'
*         �EShow Name List in order of ID
*             �� call 'sortById()'
*             �� call 'showSchoolmateGrade()'
*         �EShow Name List in order of totalIndividual score
*             �� call 'sortByTotal()'
*             �� call 'showSchoolmateGrade()'
*         �EShow Average, Maximum, Minimum of each subjects
*             �� call 'showCalculatedStats()'
*
*@subject int inputSchoolmate(void)
*         �ELoad data of Schoolmate records from file '10stats-input.txt'.
*         �EAdd Schoolmate 'struct' to 'mateAry[]' and increase 'mateSize' to the number of 'struct'
*         �E[Return] over 0: the number of loaded Schoolmate records
*                    -1:     Error of Load Data
*
*@subject <stdio.h> => INDEX�kC99YH12_FileOperation/MainFileOpenInputSample.c�l
*            �� char*   fgets(char* _Buffer, int _MaxCount, FILE* _Stream)
*
*@subject <string.h>
*        [�~] �� int     strcpy(char* _Destination, const char* _Source)
*            �� errno_t strcpy_s(char* _Destination, int _SizeInBytes, const char* _Source)
*        [�~] �� int     sscanf(const char* _Buffer, const char* _Format, T value ...)
*            �� int     sscanf_s(const char* _Buffer, const char* _Format, T value ...)
*            �� size_t  strlen(const char* _Str)
* 
*        [�~]: C11 Compile Error, because of 'unsafe'.
* 
*@subject void sortById(void);
*         �Esort as ascending of ID
*@subject void sortByTotal(void);
*         �Esort as descending of totalIndividual
*@subject void showSchoolmateGrade(void);
*@subject void showCaluclatedStats(void);
* 
*@NOTE �yCompile Error�zin VS Execution ONLY
*       C4996	'sscanf': 
*       This function or variable may be unsafe. 
*       Consider using sscanf_s instead. 
*       To disable deprecation, use _CRT_SECURE_NO_WARNINGS.
*       See online help for details.
*       ClangC11Console  C:\...\C99YH10_Struct\MainSchoolmateGradeFromFileViewer.c	151	
*           ||
*@NOTE �yWarning�z MainSchoolmateGradeFromFileViewer.c(163):
*       warning C4477: 'sscanf_s' : ���������� '%s' �ɂ́A�^ 'unsigned int' �̈������K�v�ł����A�ό��� 3 �͌^ 'int *' �ł�
*       note: ���̈����̓o�b�t�@�[ �T�C�Y�Ƃ��Ďg�p����܂�
*       warning C4473: 'sscanf_s': ����������Ƃ��ēn���ꂽ������ �s�����Ă��܂�
*       note: �v���[�X�z���_�[�Ƃ��̃p�����[�^�[�ɂ� 8 �̉ό������K�v�ł����A7 ���w�肳��Ă��܂��B
*       note: �s�����Ă���ό��� 8 ������������ '%d' �ɕK�v�ł�
* 
*       => (unsolved) 
*          In temporary, 'sscanf_s()' is instead of 'sscanf()', for applicating to VS Compile.
*          When Command Prompt execute this code, change comment-out of 'sscanf()' alive.
*
*@see C99YH12_FileOperation\MainSchoolmateGradeViewer2_FromFileToFile.c
*@CopyRight YUUKI Hiroshi who is author of Book C99YH above.
*@author of the modified code: (for individual learnings) shika
*@date 2022-12-29
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
struct Schoolmate {
    int id;                      // ID
    char name[NAME_MAX];         // Name
    int scoreAry[SUBJECT_MAX];   // score Array of whole subjects
    double totalIndividual;      // totalIndividual of whole subjects
};

//====== Global Variable ======
struct Schoolmate mateAry[MATE_MAX]; // Array of whole Schoolmate struct
int mateSize = 0;                    // element count of 'mateAry' above

//====== Prototype Declaration ======
//int main(void);
int mainSchoolmateGradeFromFileViewer(void);
int inputSchoolmate(void);
void sortById(void);
void sortByTotal(void);
void showSchoolmateGrade(void);
void showCaluclatedStats(void);

//====== Function Definition ======
//int main(void) {
int mainSchoolmateGradeFromFileViewer(void) {
    //---- Load Data ----
    if (inputSchoolmate() < 0) {
        printf("<�I> Error of Load Data.\n");
        return -1;
    }

    //---- Show Schoolmate Count ----
    printf("== Schoolmate Count ==\n");
    printf("%d persons\n", mateSize);
    printf("\n");

    //---- Show Name List soted by ID ----
    printf("== Schoolmates in order of ID ==\n");
    sortById();
    showSchoolmateGrade();
    printf("\n");

    //---- Show Name List sorted by totalIndividual score ----
    printf("== Schoolmates in order of individual Total Score ==\n");
    sortByTotal();
    showSchoolmateGrade();
    printf("\n");

    //---- Show Caluculated Stats ----
    printf("== Culculated Stats of each subjects and whole subjects ==\n");
    showCaluclatedStats();
    printf("\n");

    return 0;
}//main()

int inputSchoolmate(void) {
    char buffer[BUFFER_SIZE];
    char nameBuffer[BUFFER_SIZE];
    int n = 0;  //Schoolmate Count for local

    //---- Load Data ----
    while (fgets(buffer, BUFFER_SIZE, stdin) != NULL) {
        if (n >= MATE_MAX) {
            printf("<�I> Too many numbers of Schoolmate in Data File. [within %d persons]\n", MATE_MAX);
            return -1;
        }

        //Pointer to add load data to 'mateAry'
        struct Schoolmate* mateP = &mateAry[n];  

        //Parse load data by Function 'sscanf()'
        //int dataNum = sscanf(buffer, "%d %s %d %d %d %d %d\n",  //when Command Prompt execute
        int dataNum = sscanf_s(buffer, "%d %s %d %d %d %d %d\n",  //when VS Compile
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
            printf("<�I> Data is wrong with the type, under Row %d.\n", n + 1);
            printf("Data: %s\n", buffer);
            return -1;
        }

        //Check name length to prevent overflow / �}1 is for '\0'
        if (strlen(nameBuffer) + 1 > NAME_MAX) {
            printf("<�I> Too long character of the Name under Row %d. [within %d Bytes]\n",
                n + 1, NAME_MAX - 1);
            printf("Name: %s\n", nameBuffer);
            return -1;
        }

        //copy Name to struct.name
        strcpy_s(mateP->name, NAME_MAX, nameBuffer);

        //calculate totalIndividual score and substitute to struct.totalIndividual
        mateP->totalIndividual = 0;
        for (int i = 0; i < SUBJECT_MAX; i++) {
            mateP->totalIndividual += mateP->scoreAry[i];
        }

        //increment Schoolmate Count for local
        n++;
    }//while

    //whole Schoolmate Count of File Data 
    mateSize = n;

    return mateSize;
}//inputSchoolmate()

void sortById(void) {
    for (int i = 0; i < mateSize - 1; i++) {
        struct Schoolmate* matePi = &mateAry[i];

        for (int j = i + 1; j < mateSize; j++) {
            struct Schoolmate* matePj = &mateAry[j];

            if (matePi->id > matePj->id) {  //ascending of ID
                struct Schoolmate temp = *matePi;
                *matePi = *matePj;
                *matePj = temp;
            }
        }//for j
    }//for i
}//sortById()

void sortByTotal(void) {
    for (int i = 0; i < mateSize - 1; i++) {
        struct Schoolmate* matePi = &mateAry[i];

        for (int j = i + 1; j < mateSize; j++) {
            struct Schoolmate* matePj = &mateAry[j];

            if (matePi->totalIndividual < matePj->totalIndividual) {  //descending of totalIndiviual
                struct Schoolmate temp = *matePi;
                *matePi = *matePj;
                *matePj = temp;
            }
        }//for j
    }//for i
}//sortByTotal()

void showSchoolmateGrade(void) {
    for (int n = 0; n < mateSize; n++) {
        struct Schoolmate* mateP = &mateAry[n];

        //auto increment
        printf("(%3d) ", n + 1);

        //ID
        printf("ID: %3d ", mateP->id);

        //Name
        printf("Name: %-14s | ", mateP->name);

        //socre
        for (int i = 0; i < SUBJECT_MAX; i++) {
            printf("%3d ", mateP->scoreAry[i]);
        }//for i

        //totalIndividual
        printf(" | Total: %0.2f ", mateP->totalIndividual);

        //average 
        printf("Average: %0.2f ", mateP->totalIndividual / SUBJECT_MAX);
        printf("\n");
    }//for n
}//showSchoolmateGrade()

void showCaluclatedStats(void) {
    int max[SUBJECT_MAX];              //max of each subject
    int min[SUBJECT_MAX];              //min of each subject
    double totalSubject[SUBJECT_MAX];  //total of each subject
    double totalWhole;                 //total of whole subjects

    struct Schoolmate* mateP;

    //---- initialized by index 0 data ---
    mateP = &mateAry[0];

    for (int i = 0; i < SUBJECT_MAX; i++) {
        max[i] = mateP->scoreAry[i];
        min[i] = mateP->scoreAry[i];
        totalSubject[i] = mateP->scoreAry[i];
    }//for i

    totalWhole = mateP->totalIndividual;

    //---- Caluculate Data ----
    for (int n = 1; n < mateSize; n++) {  // 'n = 0' already has read above.
        mateP = &mateAry[n];

        for (int i = 0; i < SUBJECT_MAX; i++) {
            if (max[i] < mateP->scoreAry[i]) {
                max[i] = mateP->scoreAry[i];
            }

            if (min[i] > mateP->scoreAry[i]) {
                min[i] = mateP->scoreAry[i];
            }

            totalSubject[i] += mateP->scoreAry[i];
        }//for i

        totalWhole += mateP->totalIndividual;
    }//for n

    //---- Show Caluculated Stats ----
    for (int i = 0; i < SUBJECT_MAX; i++) {
        printf("Subject %d: ", i + 1);
        printf("Maximum: %3d / ", max[i]);
        printf("Minimum: %3d / ", min[i]);
        printf("Average: %0.2f \n", totalSubject[i] / mateSize);
    }//for i

    printf("Average of Total: %0.2f \n", totalWhole / mateSize);
}//showCaluclatedStats()

/*
//###### Appendix ######
//====== 10stats-input.txt ======
101 �����Ԏq 65 90 100 80 73
102 �����a�n 82 75 63 21 45
103 �ɓ����� 74 31 41 59 38
104 �������Y 100 95 98 82 65
105 �����^�� 55 48 79 90 88
106 �i���O���Y 74 45 59 27 38
[EOF]

//====== [Windows Command Prompt for VS2019] Execution ======
>cd C:\...\ClangC11Sample\C99YH\C99YH10_Struct

>cl MainSchoolmateGradeFromFileViewer.c
/out:MainSchoolmateGradeFromFileViewer.exe
MainSchoolmateGradeFromFileViewer.obj

>MainSchoolmateGradeFromFileViewer < 10stats-input.txt

//====== Result ======

== Schoolmate Count ==
6 persons

== Schoolmates in order of ID ==
(  1) ID: 101 Name: �����Ԏq       |  65  90 100  80  73  | Total: 408.00 Average: 81.60
(  2) ID: 102 Name: �����a�n       |  82  75  63  21  45  | Total: 286.00 Average: 57.20
(  3) ID: 103 Name: �ɓ�����       |  74  31  41  59  38  | Total: 243.00 Average: 48.60
(  4) ID: 104 Name: �������Y       | 100  95  98  82  65  | Total: 440.00 Average: 88.00
(  5) ID: 105 Name: �����^��       |  55  48  79  90  88  | Total: 360.00 Average: 72.00
(  6) ID: 106 Name: �i���O���Y     |  74  45  59  27  38  | Total: 243.00 Average: 48.60

== Schoolmates in order of individual Total Score ==
(  1) ID: 104 Name: �������Y       | 100  95  98  82  65  | Total: 440.00 Average: 88.00
(  2) ID: 101 Name: �����Ԏq       |  65  90 100  80  73  | Total: 408.00 Average: 81.60
(  3) ID: 105 Name: �����^��       |  55  48  79  90  88  | Total: 360.00 Average: 72.00
(  4) ID: 102 Name: �����a�n       |  82  75  63  21  45  | Total: 286.00 Average: 57.20
(  5) ID: 103 Name: �ɓ�����       |  74  31  41  59  38  | Total: 243.00 Average: 48.60
(  6) ID: 106 Name: �i���O���Y     |  74  45  59  27  38  | Total: 243.00 Average: 48.60

== Culculated Stats of each subjects and whole subjects ==
Subject 1: Maximum: 100 / Minimum:  55 / Average: 75.00
Subject 2: Maximum:  95 / Minimum:  31 / Average: 64.00
Subject 3: Maximum: 100 / Minimum:  41 / Average: 73.33
Subject 4: Maximum:  90 / Minimum:  21 / Average: 59.83
Subject 5: Maximum:  88 / Minimum:  38 / Average: 57.83
Average of Total: 330.00
*/