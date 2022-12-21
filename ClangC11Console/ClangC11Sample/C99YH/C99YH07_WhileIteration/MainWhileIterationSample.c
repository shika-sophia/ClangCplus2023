/**
*@directory ClangC11Console / ClanC11Sample / C99YH / C99YH07_WhileIteration
*@fileName  MainWhileIterationSample.c
*@reference C99YH  åãèÈ ç_ ÅwCåæåÍÉvÉçÉOÉâÉ~ÉìÉOÉåÉbÉXÉì [ì¸ñÂï“] ëÊÇRî≈ÅxSB Creative, 2019
*@reference CAnsi  åãèÈ ç_ ÅwCåæåÍÉvÉçÉOÉâÉ~ÉìÉOÉåÉbÉXÉì [ï∂ñ@ï“] êVî≈Åx  SB Creative, 2006
*@reference C11DS  arton  Åwì∆èK C êVî≈Åx„ƒâjé–, 2018
*
*@content C99YH ëÊÇVèÕ While Iteration | Chapter 7 / List 7-1, 7-2, 7-3 / p186
* 
*@subject List 7-1 while
*         [Format]
*         while( conditional expression ) {
*            //operation
*         }//while
*
*@subject List 7-2  It is continuous loop until user inputs '.'. ÅkbelowÅl 
*@subject List 7-3  while((c = getchar()) != '.')
*         ÅEThe conditional expression in 'while()' include function 'c = getchar()'.
*         ÅEsubstitute operator '=':  It substitute the following value to variable at left side
          ÅEcompare operator '!=':    'A != B' means to judge if A is not equal B
*         ÅEThese operators priority is defferant: '!=' is higher than substitute 'c = getchar()', 
*           so it need be with '()' to notify changing priority to compiler: 'c = getchar()' is higer than "!='.
* 
*@subject List 7-4  
*         => see <stdio.h> [Example] ÅkbelowÅl
*         => seeÅkMainWhileEOF_withFileLoad.cÅl
* 
*@subject <stdio.h>
*            Ñ§ int  getchar(void)  
*                If user input multi number of characters, 'while { }' turn continuously as same as the number.
*                Inputing return-key when user has done the inputs, is recognized one character, white-space too.
*                The 'return character' is added 'char* inputAry[]' as one char and output as line feed when 'printf()'.
* 
*            Ñ§ int  putchar(int character) // output character
*            Ñ§ #define EOF -1              // = End of File
* 
*              [Example] List 7-4
*                while((c = getchar()) != EOF) { 
*                    putchar(c);
*                }
* 
*         => seeÅkMainWhileEOF_withFileLoad.cÅl
*         => seeÅkC99YH05_SwitchMultiBranch\MainSwitchGetcharSample.cÅl
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

    printf("ÅüHit any key [END: . ] > ");
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
ÅüHit any key [END: . ] > any
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