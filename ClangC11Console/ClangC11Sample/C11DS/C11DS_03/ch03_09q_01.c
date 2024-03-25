/*
◆練習問題3.9 p81
1.コード修正前
=>別紙 ch03_09q_01.c

1.コード修正後
=>別紙 ch03_09q_02.c
*/
#include <stdio.h>
#include <limits.h>

int main(void)
{
    long long value = LLONG_MAX;
    printf("%%i = %i\n", value);

    return 0;
}//main

/*
>ch03_09q_01
%i = -1

【警告】
 warning C4477: 'printf' : 書式 文字列 '%i' には、型 'int' の引数が必要ですが、可 変個引数 1 は型 '__int64' です
ch03_09q_01.c(15): note: 書式文字列に '%lli' を使 用することをお勧めします
ch03_09q_01.c(15): note: 書式文字列に '%I64i' を使用することをお勧めします
*/
