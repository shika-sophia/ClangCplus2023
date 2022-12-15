/**
*@directory ClangC11Console / ClanC11Sample / C99YH / C99YH03_Variable
*@fileName  PracticeC99YH03.c
*@reference C99YH  ���� �_ �wC����v���O���~���O���b�X�� [�����] ��R�ŁxSB Creative, 2019
*@reference CAnsi  ���� �_ �wC����v���O���~���O���b�X�� [���@��] �V�Łx  SB Creative, 2006
*@reference C11DS  arton  �w�ƏK C �V�Łx�ĉj��, 2018
*
*@content C99YH ��R�� ���K��� / List 3-8 / p91
*@subject Practice 3-1  True or False
*         �Z (1) A variable name 'i' is usually int type. 
*                  -> false: 'i' should be defined as int or else.
*                  variable name is not concerned with the variable type.
*         �Z (2) When int x = 3, x value after executing 'x = x + 1;' is 4. 
*                 -> true: calculator '=' means 'substitute. 
*                    It is no problem that variable 'x' exist both side of '='.
*         �Z (3) I wanted that value of int n would be 0, I described 'n = "0"; '.  
*                  -> wrong: compile error.
*                     The double quatation["] express string value.
*                     So "0" cannot substitute into int n. you should describe 'int n = 0'.
*         �Z (4) I tried to verify that m value equals n value, I described 'm = n'.
*                  -> wrong: calculator '=' means 'substitute', calculator '==' means 'equal'.
*                     So you should describe 'm == n'.
*            
*@subject Practice 3-2  Make Program as below
*         It ask two persons name and age.
*         It output the average of two person's ages.
*
*NOTE�yProblem�z�G���[ LNK2019
*     �������̊O���V���{�� _main ���֐� "int __cdecl invoke_main(void)" (?invoke_main@@YAHXZ) �ŎQ�Ƃ���܂���
*     ClangCplus2023\ClangC11Console\MSVCRTD.lib(exe_main.obj)	1	
*
*     �� Prototype 'int main(void);'�@�� �O�R�[�h 'MainMultipleQuestViewer.c'�ŕt�L�����Ƃ���A
*     �Ȍ�̃r���h�ŁA���̃G���[���o�āA�V�K�R���p�C������t�Ȃ��Ȃ����B
*     �R���p�C���͒ʂ邪�u.obj�v�u.exe�v�𐶐������B
*     �V�K�t�@�C���� int main(void)�������Ă��A�����F�������A��L�̃G���[�ƂȂ�B
*     ����ȑO�Ƀr���h�����t�@�C������ ��� int main(void) { } ��p�ӂ���ƁA
*     ��L�G���[��}���ł��邪�A�V�K�t�@�C���̃r���h�͂ł��Ȃ��B
*     �d���Ȃ��A[Windows Command Prompt for VS2019]�ŃR���p�C�����A���s�k���L�l
* 
*     => VS����A���̃t�@�C���̃r���h�����O����Ă���̂ŁA
*        [���̃t�@�C���̃v���p�e�B] 
*        [�S��] �r���h���珜�O:  �͂�     -> ������
*               ���:           �e�L�X�g -> C/C++�R���p�C��
*        �ɕύX����ƁA�r���h���ɁA���̃t�@�C�����܂܂�AVS�Ŏ��s�\�B
*        �u.obj�v�� /Debug���ɐ��������B
*        (������ [.c]�t�@�C���ł͂Ȃ��A[C++]�t�@�C���Ƃ��ĔF������Ă���)
* 
*     => �t�@�C���쐬�� [�e�L�X�g.txt]�ł͂Ȃ��A
*        [C++�t�@�C��.cpp] -> [.c]�ɕύX���č쐬����΁A�f�t�H���g�� '���: C/C++�R���p�C��' �ɂȂ��Ă���B
* 
*@see
*@author shika
*@date 2022-12-14
*/

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 256

//int main(void);
void consoleInput(char*, int);  //already definied in MainConsoleInputSample.c

//int main(void) {
int mainPracticeC99YH03(void) {
    char buffer[BUFFER_SIZE];
    char name1[BUFFER_SIZE];
    char name2[BUFFER_SIZE];
    int age1;
    int age2;
    double average;
    
    printf("��Please tell me two person's name and age\n");
    printf("��First person's name > ");
    consoleInput(name1, BUFFER_SIZE);

    printf("��%s's age > ", name1);
    consoleInput(buffer, BUFFER_SIZE);
    age1 = atoi(buffer);

    printf("��Second person's name > ");
    consoleInput(name2, BUFFER_SIZE);

    printf("��%s's age > ", name2);
    consoleInput(buffer, BUFFER_SIZE);
    age2 = atoi(buffer);

    average = (age1 + age2) / 2.0;

    printf("---- Result ----\n");
    printf("We preciate your corporation.\n");
    printf("The average of %s and %s ages is %.2f \n", name1, name2, average);

    return 0;
}//main()

//====== already definied in MainConsoleInputSample.c ======
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
//====== Command Prompt ======
>cd c:\ ... \C99YH\C99YH03_Variable
>cl PracticeC99YH03.c
Microsoft(R) C/C++ Optimizing Compiler Version 19.29.30147 for x86
Copyright (C) Microsoft Corporation.  All rights reserved.

PracticeC99YH03.c
/out:PracticeC99YH03.exe
PracticeC99YH03.obj

>PracticeC99YH03
��Please tell me two person's name and age
��First person's name > shika
��shika's age > 50
��Second person's name > sophia
��sophia's age > 24
---- Result ----
We preciate your corporation.
The average of shika and sophia ages is 37.00

//====== VS Execution ======
��Please tell me two person's name and age
��First person's name > Mitoma
��Mitoma's age > 25
��Second person's name > Yuri
��Yuri's age > 24
---- Result ----
We preciate your corporation.
The average of Mitoma and Yuri ages is 24.50
*/