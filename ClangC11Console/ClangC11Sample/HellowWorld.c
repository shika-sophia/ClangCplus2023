//==== Template ====

/**
*@directory ClangC11Console / ClanC11Sample / C99YH / C99YH00_
*@fileName  Main.c
*@reference C99YH  ���� �_ �wC����v���O���~���O���b�X�� [�����] ��R�ŁxSB Creative, 2019
*@reference CAnsi  ���� �_ �wC����v���O���~���O���b�X�� [���@��] �V�Łx  SB Creative, 2006
*@reference C11DS  arton  �w�ƏK C �V�Łx�ĉj��, 2018
*
*@content C99YH ���  | Chapter  / List - / p
*@summary
*
*@subject
*
*@see 
*@author shika
*@date 2023-
*/ 
/*
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 256

void consoleInput(char*, int);

int main(void) {
//int mainXxxx(void) {
    char buffer[BUFFER_SIZE];
    int canInput = 0; // as boolean (default false)

    //---- Loop Question ----
    while (!canInput) {
        printf("");
        consoleInput(buffer, BUFFER_SIZE);
        
        //---- Validate Input ----
        if () {
            canInput = 1;  // to break while()
        }
        else {
            printf("<�I> should be input in range [ - ].\n");
            continue;
        }
    }//while

    return 0;
}//main()

//====== already defined in C99YH03_Variable/MainConsoleInputSample.c ======
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

*/

//==== HelloWorld.c ====
/*
*@directory ClangCplus2023 / ClangC11Console / ClanC11Sample / 
*@fileName  HelloWorld.c
*@reference C99YH  ���� �_ �wC����v���O���~���O���b�X�� [�����] ��R�ŁxSB Creative, 2019
*@reference CAnsi  ���� �_ �wC����v���O���~���O���b�X�� [���@��] �V�Łx  SB Creative, 2006
*@reference C11DS  arton  �w�ƏK C �V�Łx�ĉj��, 2018
*
*@content C����t�@�C���̍쐬/�ۑ�/���s
*         �E�g���q �u.c�v
*
*@subject Directory Tree
*         (when Solution-> [Mouse RightClick] -> Icon[whole view])
*
*         solution ClangCplus2023
*            �� project ClangC11Console
*                �� ClanC11Sample
*                    �� HelloWorld.c
* 
*           (�� Debug  -- whole view mode ONLY )
*                �� ClangC11Console.tlog
*                    �� �ulinkcommand.1.tlog�v�ulink.read.1.tlog�v�ulink.write.1.tlog�v�Ȃ�
*                �� ClangC11Console.exe.recipe
*                �� ClangC11Console.ilk
*                �� ClangC11Console.log
*                �� ClangC11Console.obj
*                �� HelloWorld.obj 
*                    :
* 
*@subject Windows Command Prompt for developer 
*         (this appeared after installing C++ liblaray into Visual Studio 2019) 
* 
*         Procedure:  Windows -> [Start] ->
*           [x86_x64 Cross Tools Command Prompt for VS 2019]
*           C:\Program Files (x86)\Microsoft Visual Studio\2019\Community>
* 
*         > clang --version
*         clang version 12.0.0
*         Target: i686-pc-windows-msvc
*         Thread model: posix
*         InstalledDir: C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\Llvm\bin
*
*@see
*@author shika
*@date 2022-12-06
*/

#include <stdio.h>

//int main(void) {
int mainHelloWorld(void) {
	printf("Hello World, Clang.");

	return 0;
}//main()

/*
//==== Result ====
Hello World, Clang.

../../ClangCplus2023\Debug\ClangC11Console.exe (�v���Z�X 14948) �́A
�R�[�h 0 �ŏI�����܂����B
���̃E�B���h�E�����ɂ́A�C�ӂ̃L�[�������Ă�������...
*/