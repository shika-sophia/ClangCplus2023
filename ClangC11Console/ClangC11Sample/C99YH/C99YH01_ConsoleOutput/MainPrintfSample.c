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
*         int   printf()
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
*@subject <stdio.h> => 〔C99YH12_FileOperation\MainFileOpenInputSample.c〕
*           └ int  printf(char format [, T value1] [, T value2] ...)
*                   └ T: intなど数値型, char, string
* 
*         ・print format の略
*         ・文字コード UNIX系(Mac, Linux): UTF-8
*                     Windows default:    Shift_JIS
*         ・改行  "\n"
* 
*         ◆printf() の書式文字列 〔C99YH 付録 p446〕
*         ＊書式文字列 format
*         % [フラグ] [最小フィールド幅] [. 精度] [長さ指定子]
*
*         ＊フラグ: 出力の位置、出力形式
*           -:   左詰め  (省略すると右詰め)
*           +:   符号付き(省略すると負数のみ「-」符号付き)
*          「 」(スペース): 最初の文字が符号でなければ、スペースを挿入
*           0:   フィールド幅まで 0 を挿入
*           #:   変換指定子 〔below〕
*               o:  最初の桁に 0 を付記。 (octa-decimal: 8進数)
*               x:  最初の桁に 0x を付記。(hexa-decimal: 16進数)
*               X:  最初の桁に 0X を付記。(hexa-decimal: 16進数)
*               a, A, e, E, f, F:  小数点を付記
*               g, G:              小数点を付記し、後続に 0 を挿入
* 
*         ＊最小フィールド幅: 出力の最小幅
*           ・0 以上の10進数整数値で指定
*           ・指定幅より桁が多い場合、自動で幅を拡張して表示
*           ・指定幅より桁が少ない場合、デフォルトで「 」スペースを挿入。「フラグ」で指定した場合はそれに従う。
*           ・「*」を指定すると printf(string, int) の 引数 int をフィールド幅とする。
*         
*         ＊精度  出力する数字の個数 (変換指定子によって異なる)
*           ・0 以上の10進数整数値で指定
*           ・「*」を指定すると printf(string, int) の 引数 int を精度とする。
*           ・変換指定子 〔below〕
*               d, i, o, u, x, X:  出力する数字の最小個数
*               a, A, e, E, f, F:  小数点以下の数字の個数
*               g, G:              数値型の最大有効桁数
*               s:                 string 最大バイト数
* 
*         ＊長さ指定子  対応する引数の型の長さ、出力する型
*            hh:  signed char型, unsigned char型 として出力
*            h:   short int型, unsigned short型 として出力
*            l:   long int型, unsigned long int型 として出力
*            ll:  long long int型, unsigned long long int型 として出力 
*            j:   intmax_t型, unitmax_t型 として表示
*            z:   size_t型 (= 演算子 sizeof の型) として表示
*            t:   printdiff_t型 (= ポインタの差を表す型) として表示
*            L:   long double型として表示
* 
*          ＊変換指定子  出力形式
*            d, i:   int    10進数 符号付き  //decimal, integer の略
*            u:      int    10進数 符号なし  //unsigned
*            o:      int    8進数 符号なし   //octa-decimal
*            x:      int    16進数 符号なし (abcdef を小文字表記)  //hexa-decimal
*            X:      int    16進数 符号なし (ABCDEF を大文字表記)
*            c:      int    文字 unsigned char型に変換            //character
*            s:      char   文字列 ('\0'が来るか、指定した精度まで出力) ※下記
*            f, F:   double 小数の 10進数表記 (小数点以下の桁数は精度で指定。値の丸めあり) //float
*            e, E:   double 小数の 正規化表記 [-] 1.234567e+01 など、 Eなら E (同上)
*            g, G:   double 精度によって e, f / E, F　のいずれかを使用
*            a, A:   double 16進数の正規化表記 [-] 1.234567p+01 など、 Aなら P
*            p:      void   ポインタとして出力 (処理系依存) ※下記
*            n:      int    これまで出力した文字数を引数に返す (セキュリティ上の理由から C11 で廃止) ※下記
*            %:             「%」を文字として出力
*            
*            ※【註】セキュリティ上、問題があるので、
*               [C11]では セキュリティを配慮した printf_s() 関数を利用する。
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

//int main(void){
int mainPrintfSample(void) {
	printf("Hello World.\n");
	printf("Hello Japan.\n");
	printf("はじめまして、Ｃ言語さん。\n");

	return 0;
}//main()

/*
//====== Result ======
Hello World.
Hello Japan.
はじめまして、Ｃ言語さん。

*/