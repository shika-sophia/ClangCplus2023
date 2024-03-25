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
    printf("%%lli = %lli\n", value);

    return 0;
}//main

/*
>ch03_09q_02
%lli = 9223372036854775807
*/