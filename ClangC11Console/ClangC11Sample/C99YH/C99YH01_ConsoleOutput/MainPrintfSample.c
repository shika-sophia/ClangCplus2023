/**
*@title ClangC11Console / ClanC11Sample / C99YH / C99TH01_ConsoleOutput
*@class MainPrintfSample.c
*@reference C99YH  結城 浩 『C言語プログラミングレッスン [入門編] 第３版』SB Creative, 2019
*@reference CAnsi  結城 浩 『C言語プログラミングレッスン [文法編] 新版』  SB Creative, 2006
*@reference C11DS  arton  『独習 C 新版』翔泳社, 2018
*
*@content C99YH 第１章 表示 p13- / main(), printf()
*@summary #include 
*         <stdio.h>
*         int   main(void)
*         void  printf(string)
*
*@subject #include <stdio.h>
*         #xxxx         //ディレクティブ: プリプロセッサ(=コンパイル前の処理)への命令
*         #include xxxx //xxxxを import し、実行メモリ上に参照する命令
* 
*@subject <stdio.h> ヘッダーファイル。 
*         ・Standard IOの略
*         ・Consoleでの 基本的な入力・出力を扱う ヘッダーファイル
* 
*@subject int   main()
*         ・プログラムのエントリーポイント。
*         ・「.exe」は main()を探し、ここから実行する。
*         ・main()が存在しないとコンパイルエラー。main()が複数ある場合も同様。
*         ・引数 void 他もある
*         ・戻値 int。return 0; で　0 が返ると プログラムが終了する。
* 
*@subject void  printf(string)
*         ・print format の略
*         ・文字コード UNIX系(Mac, Linux): UTF-8
*                     Windows default:    Shift_JIS
* 
*
*@NOTE 【註】「.h」ヘッダーファイル
*       #incude "MainPrintfSample"
*       ・「"」で括った includeが可能。自己定義のヘッダーファイルへの参照だと思われる。
*       ・C++ でクラス生成時、「.c」「.h」が生成され、
*         class は 「.h」に記述される。
*         名前の変更、ディレクトリ階層の変更で識別されなくなるので注意
*         「.c」内に class を記述しても 「class は識別子として定義されていません」となる
*       
*        ・「.h」を削除しても、実行に影響はない。
*        
*       ・class とは、オブジェクト指向で、各プログラムを部品化して再利用するための概念。
*         C には class という概念がない。C++ で初めて オブジェクト指向を導入された。
* 
*@see
*@author shika
*@date 2022-12-08
*/

#include <stdio.h>

//class MainPrintfSample { };
//int main(void);
//
//int main(void) {
//	printf("Hello World.\n");
//	printf("Hello Japan.\n");
//	printf("はじめまして、Ｃ言語さん。\n");
//
//	return 0;
//}//main()

/*
//====== Result ======
Hello World.
Hello Japan.
はじめまして、Ｃ言語さん。

*/