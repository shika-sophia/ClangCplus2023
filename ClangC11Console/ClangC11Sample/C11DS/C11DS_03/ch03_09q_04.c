/*
4. 修正前
=>別紙 ch03_09q_04.c

4. 修正後
=>別紙 ch03-09q_05.c
*/

#include <stdio.h>

int main(void)
{
    printf("%%lli: %lli,%%llu: %llu\n", 32, 48);
  
    return 0;
}//main

/*
【警告】
 warning C4477: 'printf' : 書式 文字列 '%lli' には、型 '__int64' の引数が必要です が、可変個引数 1 は型 'int' です
ch03_09q_04.c(13): note: 書式文字列に '%i' を使用 することをお勧めします
ch03_09q_04.c(13): note: 書式文字列に '%Ii' を使用することをお勧めします
ch03_09q_04.c(13): note: 書式文字列に '%I32i' を使用することをお勧めします
ch03_09q_04.c(13): warning C4477: 'printf' : 書式 文字列 '%llu' には、型 'unsigned __int64' の引数が必要ですが、可変個引数 2 は型 'int' です
ch03_09q_04.c(13): note: 書式文字列に '%u' を使用 することをお勧めします
ch03_09q_04.c(13): note: 書式文字列に '%Iu' を使用することをお勧めします
ch03_09q_04.c(13): note: 書式文字列に '%I32u' を使用することをお勧めします

>ch03_09q_04
%lli: 206158430240,%llu: 18597521940019152

【考察】
こうなる理由は64ビット整数に変換されるとき符号拡張を起こしている？
警告通り、「%i」「%u」を利用すべき
=>32, 48はint として32ビットで処理されているので、上記のバグが起こる。
32LL, 48LLとしてもOK。
*/