/**
*@directory ClangC11Console / ClanC11Sample / C99YH / C99YH10_Struct
*@fileName  MainStructSchoolmateSample.c
*@reference C99YH  ���� �_ �wC����v���O���~���O���b�X�� [�����] ��R�ŁxSB Creative, 2019
*@reference CAnsi  ���� �_ �wC����v���O���~���O���b�X�� [���@��] �V�Łx  SB Creative, 2006
*@reference C11DS  arton  �w�ƏK C �V�Łx�ĉj��, 2018
*
*@content C99YH ��10�� �\���� | Chapter 10  Struct / List 10-1 �` 10-5, 10-8 / p293-
*@English [�p] quailifier:   �C���q
*         [�p] abbreviation: �ȗ�
*         [�p] alias:        �ʖ�
* 
*@summary MainStructSchoolmateSample.c
*        �ystruct�z�\����
*         �EDeclaration of 'struct'
*         �EDefinition of 'struct'
*         �ESubstitute into 'struct'
*         �ESubstitute one 'struct' to the other 'struct'
*         �EGet value (= Reference) from 'struct'
*         �EArray as 'struct' member
*         �EInitialize 'struct'
*         �E'struct' Array
*         �E'struct' Array with Intialization
*         �E'typedef'
*         �E<string.h> -- strcpy()
*         �ENOTE�yCompile Error�z'strcpy' in VS
*         �EString Array
*
*@subject �ystruct�z �\����
*         �E'struct' is a kind of 'type' which can have the 'member' as local variables of different types.
* 
*@subject Declaration of 'struct' at file top under Prototype.
*         [Format]
*         struct structName {
*             type memberName;
*             type memberName;
*                :
*         }
* 
*@subject Definition of 'struct' in local
*         [Format]
*         struct structName variableName;
*
*@subject Substitute into 'struct'
*         [Format]
*         variableName.memberName = (value of its type);
*
*@subject Substitute one 'struct' to the other 'struct'
*         These 'struct' need be defined as same 'struct'.
*         This operation copy whole values of one (= later of substitute experession) to the other (= former of substitute experession).
* 
*         [Format] former <- later
*            variableName1 = variableName2;
* 
*@subject Get value (= Reference) from 'struct'
*         [Format]
*         variableName.memberName
* 
*         [Example]
*         printf("ID: %d \n", mate.id);
* 
*         [�~] printf(mate);
*         [�~] printf("ID: %d \n", mate);
*         [�~] printf("ID: %d \n", id);
*
*@subject Array as 'struct' member
*         => struct SchoolmateWithArray
* 
*         [�~] chris.pointAry = pointAry;
*         [�Z] chris.pointAry[0] = value0;
*         [�Z] chris.pointAry[1] = value1;
*                :
* 
*@subject Initialize 'struct' when defininiton
*         �EThe initial values need be put as same order of 'struct' declaration member.
* 
*         [Format]
*         struct structName variableName = {
*             value1, value2, ...
*         };
*
*@subject 'struct' Array
*         �EThe elements of 'struct' array are required to be initialized.
* 
*         [Format]
*         struct structName arrayName[int];
*         struct structName arrayName[] = { variableName1, variableName2, ... };
* 
*@subject 'struct' Array with Intialization
*         �ECombination of 'Initialze�@struct' and 'struct Array' above two.
*         �EIn this case, 'variableName' of 'struct' is not necessary, it is instead to 'mateAry[i]'.
* 
*         [Example] List 10-5
*         struct Schoolmate mateAry[] = {
*             { 10, "Alice", 100, 85, 60, 95, 73 },
*             { 12, "Bobby", 99, 85, 60, 95, 73 },
*             { 17, "David", 45, 32, 67, 92, 12 },
*         };
*
*@subject qualifier? 'typedef' = abbreviation of type defininition
*         �EIt can rename any type to self-defined alias,
*           for not only 'struct' but also any other type.
* 
*         [Format]
*         typedef (type) (aliasName)
* 
*         [Example] List 10-8
*         ��Declaration
*         typedef struct SchoolmateWithArray {
*             int id;
*             char name[NAME_MAX];
*             int pointAry[SUBJECT_MAX];
*         } STUDENT;
* 
*         ��Definition
*         STUDENT chris;  <=>  struct SchoolmateWithArray chris;
* 
*         ��Argument Type
*         void showSchoolmateWithArray(STUDENT);  <=>  void showSchoolmateWithArray(struct SchoolmateWithArray);
* 
*@subject <string.h>
*            �� char*    strcpy(char* _Destinations, const char* _Source)    [��] Compile Error�kbelow�l
*      [C11] �� errno_t  strcpy_s(char* _Destinations, rsize_t _SizeInBytes, const char* _Source)
* 
*         [Example]
*         strcpy(alice.name, "Alice");
*         strcpy(&alice.name[0], "Alice);
* 
*         [�~] alice.name = "Alice";
* 
*         (meaning as same behavior)
*         alice.name[0] = 'A';
*         alice.name[1] = 'l';
*         alice.name[2] = 'i';
*         alice.name[3] = 'c';
*         alice.name[4] = 'e';
*         alice.name[5] = '\0';  NUL Character
* 
*@NOTE �yCompile Error�zthrown ONLY by Visual Studio Execution.
*       Error 'strcpy':
*       This function or variable may be unsafe. 
*       Consider using strcpy_s instead. 
*       To disable deprecation, use _CRT_SECURE_NO_WARNINGS. 
*       See online help for details.
*       ClangC11Console	C:\...\C99YH10_Struct\MainStructSchoolmateSample.c	38	
*
*       => [Windows Command Prompt for VS2019] Execution of using still 'strcpy()' is OK.�kbelow�l
*
*@subject String Array
*         �EIn C language, one string text is defined as 'char[]',
*           therefore, string array is done as 'char[][]', as below.
* 
*         [Example]
*         char subjectNameAry[SUBJECT_MAX][NAME_MAX] = {
*             "Japanese","English", "Mathematics", "Science", "Society"
*         };
* 
*         for (int i = 0; i < SUBJECT_MAX; i++) {
*             printf("%s\n", subjectNameAry[i]);
*         }//for
* 
*@see
*@author shika
*@date 2022-12-28
*/

#include <stdio.h>
#include <string.h>

#define NAME_MAX 50
#define SUBJECT_MAX 5
#define MATE_MAX 3

void showSchoolmate(struct Schoolmate);
void showSchoolmateWithArray(STUDENT);

struct Schoolmate {
    int id;
    char name[NAME_MAX];
    int japanese;
    int english;
    int mathematics;
    int science;
    int society;
};

typedef struct SchoolmateWithArray {
    int id;
    char name[NAME_MAX];
    int pointAry[SUBJECT_MAX];
} STUDENT;

//int main(void) {
int mainStructSchoolmateSample(void) {
    struct Schoolmate alice;
    struct Schoolmate bobby;
    //struct SchoolmateWithArray chris;
    STUDENT chris;
    struct Schoolmate david = {
        17, "David", 45, 32, 67, 92, 12
    };

    //---- Alice ----
    alice.id = 10;
    //strcpy(&alice.name[0], "Alice");
    strcpy_s(&alice.name[0], NAME_MAX, "Alice");
    alice.japanese = 100;
    alice.english = 85;
    alice.mathematics = 60;
    alice.science = 95;
    alice.society = 73;

    //---- Bobby ----
    bobby = alice;   //Substitute alice to bobby

    bobby.id = 12;
    //strcpy(&bobby.name[0], "Bobby");
    strcpy_s(&bobby.name[0], NAME_MAX, "Bobby");
    bobby.japanese = 99;   //lack of english, mathematics as same as alice

    //---- Chris ----
    chris.id = 15;
    //strcpy(&chris.name[0], "Chris");
    strcpy_s(&chris.name[0], NAME_MAX, "Chris");

    int pointAry[] = { 70, 97, 77, 65, 88, };
    for (int i = 0; i < SUBJECT_MAX; i++) {
        chris.pointAry[i] = pointAry[i];
    }//for

    //---- struct Array ----
    struct Schoolmate mateAry[] = { alice, bobby, david, };

    //---- print ----
    showSchoolmate(alice);
    showSchoolmate(bobby);
    showSchoolmateWithArray(chris);
    showSchoolmate(david);

    for (int i = 0; i < MATE_MAX; i++) {
        showSchoolmate(mateAry[i]);
    }//for
    return 0;
}//main()

void showSchoolmate(struct Schoolmate mate) {
    printf("ID:   %d \n", mate.id);
    printf("Name: %s \n", mate.name);
    printf("Japanese:    %3d \n", mate.japanese);
    printf("English:     %3d \n", mate.english);
    printf("Mathematics: %3d \n", mate.mathematics);
    printf("Science:     %3d \n", mate.science);
    printf("Society:     %3d \n", mate.society);
    int sum = mate.japanese + mate.english + mate.mathematics + mate.science + mate.society;
    printf("Summary:     %3d \n", sum);
    printf("\n");
}//showSchoolmate()

void showSchoolmateWithArray(STUDENT mateWithArray) {
    char subjectNameAry[SUBJECT_MAX][NAME_MAX] = {
        "Japanese","English", "Mathematics", "Science", "Society"
    };

    printf("ID:   %d \n", mateWithArray.id);
    printf("Name: %s \n", mateWithArray.name);

    int sum = 0;
    for (int i = 0; i < SUBJECT_MAX; i++) {
        printf("%s: %d\n", subjectNameAry[i], mateWithArray.pointAry[i]);
        sum += mateWithArray.pointAry[i];
    }//for
    printf("Summary: %d\n", sum);
    printf("\n");
}//showSchoolmateWithArray()

/*
//====== Result ======
//====== Visual Studio Execution of using 'strcpy_s()' instead ======
ID:   10
Name: Alice
Japanese:    100
English:      85
Mathematics:  60
Science:      95
Society:      73
Summary:     413

ID:   12
Name: Bobby
Japanese:     99
English:      85
Mathematics:  60
Science:      95
Society:      73
Summary:     412

//---- struct SchoolmateWithArray ----
ID:   15
Name: Chris
Japanese: 70
English: 97
Mathematics: 77
Science: 65
Society: 88
Summary: 397

//---- Initialize struct ----
ID:   17
Name: David
Japanese:     45
English:      32
Mathematics:  67
Science:      92
Society:      12
Summary:     248

//---- struct array ----
ID:   10
Name: Alice
Japanese:    100
English:      85
Mathematics:  60
Science:      95
Society:      73
Summary:     413

ID:   12
Name: Bobby
Japanese:     99
English:      85
Mathematics:  60
Science:      95
Society:      73
Summary:     412

ID:   17
Name: David
Japanese:     45
English:      32
Mathematics:  67
Science:      92
Society:      12
Summary:     248

//====== [Windows Command Prompt for VS2019] Execution of using still 'strcpy()' ======
>cd C:\...\C99YH\C99YH10_Struct

>cl MainStructSchoolmateSample.c
/out:MainStructSchoolmateSample.exe
MainStructSchoolmateSample.obj

>MainStructSchoolmateSample
ID:   10
Name: Alice
Japanese:    100
English:      85
Mathematics:  60
Summary:     245

ID:   12
Name: Bobby
Japanese:     99
English:      85
Mathematics:  60
Summary:     244

*/