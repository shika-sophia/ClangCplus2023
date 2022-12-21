/**
*@directory ClangC11Console / ClanC11Sample / C99YH / C99YH07_WhileIteration
*@fileName  MainWhileIterationSample.c
*@reference C99YH  ���� �_ �wC����v���O���~���O���b�X�� [�����] ��R�ŁxSB Creative, 2019
*@reference CAnsi  ���� �_ �wC����v���O���~���O���b�X�� [���@��] �V�Łx  SB Creative, 2006
*@reference C11DS  arton  �w�ƏK C �V�Łx�ĉj��, 2018
*
*@content C99YH ��V�� While Iteration | Chapter 7 / List 7-1, 7-2, 7-3 / p186
* 
*@subject List 7-1 while
*         [Format]
*         while( conditional expression ) {
*            //operation
*         }//while
*
*@subject List 7-2  It is continuous loop until user inputs '.'. �kbelow�l 
*@subject List 7-3  while((c = getchar()) != '.')
*         �EThe conditional expression in 'while()' include function 'c = getchar()'.
*         �Esubstitute operator '=':  It substitute the following value to variable at left side
          �Ecompare operator '!=':    'A != B' means to judge if A is not equal B
*         �EThese operators priority is defferant: '!=' is higher than substitute 'c = getchar()', 
*           so it need be with '()' to notify changing priority to compiler: 'c = getchar()' is higer than "!='.
* 
*@subject List 7-4  
*         => see <stdio.h> [Example] �kbelow�l
*         => see�kMainWhileEOF_withFileLoad.c�l
* 
*@subject <stdio.h>
*            �� int  getchar(void)  
*                If user input multi number of characters, 'while { }' turn continuously as same as the number.
*                Inputing return-key when user has done the inputs, is recognized one character, white-space too.
*                The 'return character' is added 'char* inputAry[]' as one char and output as line feed when 'printf()'.
* 
*            �� int  putchar(int character) // output character
*            �� #define EOF -1              // = End of File
* 
*              [Example] List 7-4
*                while((c = getchar()) != EOF) { 
*                    putchar(c);
*                }
* 
*         => see�kMainWhileEOF_withFileLoad.c�l
*         => see�kC99YH05_SwitchMultiBranch\MainSwitchGetcharSample.c�l
*@author shika
*@date 2022-12-21
*/

#include <stdio.h>

#define BUFFER_SIZE 256

//int main(void) {
int mainWhileIterationSample(void) {
    //---- List 7-1 ----
    int i = 0;
    while (i < 3) {
        printf("%d\n", i);
        i++;
    }//while
    printf("end\n");
    printf("\n");

    //---- List 7-2 ----
    char c = 0;
    int index = 0;
    char inputAry[BUFFER_SIZE];

    printf("��Hit any key [END: . ] > ");
    while(c != '.') {
        c = getchar();

        printf("input: %c\n", c);
        inputAry[index] = c;
        index++;

        if (index >= BUFFER_SIZE) {
            break;  // to break out while { }
        }
    }//while
    printf("\n(end)\n");

    for (int j = 0; j < index; j++) {
        printf("%c", (char)inputAry[j]);
    }//for

    return 0;
}//main()

/*
//====== Result ======
//---- List 7-1 ----
0
1
2
end

//---- List 7-2 ----
��Hit any key [END: . ] > any
input: a
input: n
input: y
input:

> key
input: k
input: e
input: y
input:

> inputs.
input: i
input: n
input: p
input: u
input: t
input: s
input: .

(end)
any
key
inputs.
*/