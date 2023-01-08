/**
*@directory ClangC11Console / ClanC11Sample / C99YH / C99YH07_WhileIteration
*@fileName  MainWhileEOF_withFileLoad.c
*@reference C99YH  ���� �_ �wC����v���O���~���O���b�X�� [�����] ��R�ŁxSB Creative, 2019
*@reference CAnsi  ���� �_ �wC����v���O���~���O���b�X�� [���@��] �V�Łx  SB Creative, 2006
*@reference C11DS  arton  �w�ƏK C �V�Łx�ĉj��, 2018
*
*@content C99YH ��V�� WhileIteration | Chapter 7 / List 7-4, 7-6 / p198, p204
*@summary MainWhileEOF_withFileLoad.c
*         <stdio.h> => INDEX�kC99YH12_FileOperation/MainFileOpenInputSample.c�l
*            �� int  putchar(int character) �kMainWhileIterationSample.c�l
*            �� #define EOF -1              �kMainWhileIterationSample.c�l
* 
*@subject ��Visual Studio Execution 
*        �yNotation�zIt need be finished by [Ctrl] + [C].
* 
*@subject ��Command Prompt Execution with File Load and Save �kC99YH p201�l
*         ��Redirect of Standard IO
*         �EWhen execute, '<' means to change standard-input to following file. 
*         �EWhen execute, '>' means to change standard-output to following file. 
*         �EBy this execution, we can read only plain text files as like [.txt], [.c],
*           cannot do binary files as like [.exe], [.obj]. 
* 
*         [Example]
*         ��Windows
*         >cd (current directory)                         //Change directory
*         (current directory) >cl xxxx.c                  //Compile
*         (current directory) >xxxx < yyyy.txt            //Execute with file load
*         (current directory) >xxxx < yyyy.txt > zzzz.txt //Execute with file load and save
* 
*         ��UNIX (Mac, Linux)
*         $cd (current directory)
*         $gcc -o xxxx xxxx.c
*         $./xxxx < yyyy.txt
*         $./xxxx < yyyy.txt > zzzz.txt
*
*@subject ��The reason why variable 'c' is defined as 'int', not 'char'.
*         �EBecause it can recognize 'EOF' exactly, whose value is -1.
*         �EIf 'c' is defined as 'char', and if '\xFF' character is in the document,
*           most significant digit of bit does sign-expand, changes to -1, 
*           and it is recognized as 'EOF' unexactly, the document is cut off where is not end of file.
*         => see �kC99YH p199�l
*         => copy to �kC99YH12_FileOperation/MainFileOpenInputSample.c�l
* 
*@subject ��Lorem ipsum
*         �EIt is non-sence document for dammy,
*           described by blending Latina and English.
*         �EIt is often used to confirm Web page design.
*         �EThere is a web-blog article which forthly translated it to Japanese.�kbelow Appendix�l
* 
*@see
*@author shika
*@date 2022-12-21
*/

#include <stdio.h>

//int main(void) {
int mainWhileEOF_withFileLoad(void) {
    int c;
    long long lineNum = 0LL;

    while ((c = getchar()) != EOF) {
        putchar(c);
        
        if (c == '\n') { lineNum++; }
    }//while
    printf("[EOF]\n\n");

    printf("Number of the Lines: %lli \n", lineNum);

    return 0;
}//main()

/*
//====== Command Prompt Result ======
>cl MainWhileEOF_withFileLoad.c    //Compile

MainWhileEOF_withFileLoad.c
/out:MainWhileEOF_withFileLoad.exe
MainWhileEOF_withFileLoad.obj

>MainWhileEOF_withFileLoad < lorem.txt > copyLorem.txt  //Execute with file load and save

>type copyLorem.txt   //Show file contents
Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed
do eiusmod tempor incididunt ut labore et dolore magna aliqua.
Ut enim ad minim veniam, quis nostrud exercitation ullamco
laboris nisi ut aliquip ex ea commodo consequat.  Duis aute
irure dolor in reprehenderit in voluptate velit esse cillum
dolore eu fugiat nulla pariatur.  Excepteur sint occaecat
cupidatat non proident, sunt in culpa qui officia deserunt mollit
anim id est laborum.
[EOF]

Number of the Lines: 8

//====== Appendix ======
��HIROTA YANO Blog
���_�~�[�e�L�X�g�� Lorem ipsum ����{��ɂ��Ă݂�
2019-02-09
https://yanohirota.com/lolem-ipsum-jp/

�������E�C�v�T���̒Q���A�g�}�g��D���w���̃G���b�g�A
���������Ɗ��́A���̂悤�ȘJ���Ɣ߂��݁A�u���C���h�s���ɂ� �������̏d�v�Ȏ����ɍ���܂��B
���N�ɂ킽��A���͊w��ƒ����ł���΁A
���̂悤�Ȏh���̎��g�݁A�ޏ��̂����A�^���̗��_�𕪒����ז����ꂽ����l�����܂��B
�N�s�_�^�b�g�̂�̒ɂ݂ɂȂ肽���h��ɁA�ᔻ����Ă�����ɂ݁A
�}�O�i���S���Ă����ʂ̊�т𐶐����܂���B
���N�s�_�^�b�g�u���b�N�͐�Ⴕ�Ă��Ȃ��A
�܂�A�ނ�� ���Ȃ��̔Y�݂ɐӔC������l�́A��ʓI�ȋ`�����̂āA��������Ă��܂��B

�� Blog author's comment:
(���������ɈӖ��s���ȕ��͂ł���B�������A�g�}�g��D���w�����C�ɂȂ肷����B
 �G���b�g�N�͂����ł������������w��ł���̂��B
 �g�}�g�ɔ߂��݁A�g�}�g�ɒQ���G���b�g�B
 ���Ƙ_���́u�g�}�g�ɂ�鍰�̖����v�Ƃ������Ƃ��납�B
 �C�ɂȂ肷���ăf�U�C���ǂ���ł͂Ȃ��B)
*/