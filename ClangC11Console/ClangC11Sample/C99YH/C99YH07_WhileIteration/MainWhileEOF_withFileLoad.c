/**
*@directory ClangC11Console / ClanC11Sample / C99YH / C99YH07_WhileIteration
*@fileName  MainWhileEOF_withFileLoad.c
*@reference C99YH  結城 浩 『C言語プログラミングレッスン [入門編] 第３版』SB Creative, 2019
*@reference CAnsi  結城 浩 『C言語プログラミングレッスン [文法編] 新版』  SB Creative, 2006
*@reference C11DS  arton  『独習 C 新版』翔泳社, 2018
*
*@content C99YH 第７章 WhileIteration | Chapter 7 / List 7-4, 7-6 / p198, p204
*@summary MainWhileEOF_withFileLoad.c
*         <stdio.h> => INDEX〔C99YH12_FileOperation/MainFileOpenInputSample.c〕
*            └ int  putchar(int character) 〔MainWhileIterationSample.c〕
*            └ #define EOF -1              〔MainWhileIterationSample.c〕
* 
*@subject ◆Visual Studio Execution 
*        【Notation】It need be finished by [Ctrl] + [C].
* 
*@subject ◆Command Prompt Execution with File Load and Save 〔C99YH p201〕
*         ＊Redirect of Standard IO
*         ・When execute, '<' means to change standard-input to following file. 
*         ・When execute, '>' means to change standard-output to following file. 
*         ・By this execution, we can read only plain text files as like [.txt], [.c],
*           cannot do binary files as like [.exe], [.obj]. 
* 
*         [Example]
*         ＊Windows
*         >cd (current directory)                         //Change directory
*         (current directory) >cl xxxx.c                  //Compile
*         (current directory) >xxxx < yyyy.txt            //Execute with file load
*         (current directory) >xxxx < yyyy.txt > zzzz.txt //Execute with file load and save
* 
*         ＊UNIX (Mac, Linux)
*         $cd (current directory)
*         $gcc -o xxxx xxxx.c
*         $./xxxx < yyyy.txt
*         $./xxxx < yyyy.txt > zzzz.txt
*
*@subject ◆The reason why variable 'c' is defined as 'int', not 'char'.
*         ・Because it can recognize 'EOF' exactly, whose value is -1.
*         ・If 'c' is defined as 'char', and if '\xFF' character is in the document,
*           most significant digit of bit does sign-expand, changes to -1, 
*           and it is recognized as 'EOF' unexactly, the document is cut off where is not end of file.
*         => see 〔C99YH p199〕
*         => copy to 〔C99YH12_FileOperation/MainFileOpenInputSample.c〕
* 
*@subject ◆Lorem ipsum
*         ・It is non-sence document for dammy,
*           described by blending Latina and English.
*         ・It is often used to confirm Web page design.
*         ・There is a web-blog article which forthly translated it to Japanese.〔below Appendix〕
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
◆HIROTA YANO Blog
＊ダミーテキストの Lorem ipsum を日本語にしてみた
2019-02-09
https://yanohirota.com/lolem-ipsum-jp/

ロレム・イプサムの嘆き、トマト大好き学部のエリット、
しかし時と活力、そのような労働と悲しみ、ブラインド行うには いくつかの重要な事柄に座ります。
長年にわたり、私は学区と長寿であれば、
そのような刺激の取り組み、彼女のうち、運動の利点を分注を邪魔されたする人が来ます。
クピダタットのつるの痛みになりたい宿題に、批判されてきたら痛み、
マグナ逃亡しても結果の喜びを生成しません。
先例クピダタットブラックは先例していない、
つまり、彼らは あなたの悩みに責任がある人の、一般的な義務を捨て、魂を癒しています。

※ Blog author's comment:
(いい感じに意味不明な文章である。しかし、トマト大好き学部が気になりすぎる。
 エリット君はそこでいったい何を学んでいるのか。
 トマトに悲しみ、トマトに嘆くエリット。
 卒業論文は「トマトによる魂の癒し」といったところか。
 気になりすぎてデザインどころではない。)
*/