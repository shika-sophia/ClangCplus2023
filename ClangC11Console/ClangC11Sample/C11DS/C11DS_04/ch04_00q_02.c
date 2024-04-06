/*
3. Cで扱える最大の整数と最小の整数を表示するプログラム
*/

#include <stdio.h>
#include <limits.h>

int main(void)
{
    printf("最大の整数： %lli\n", LLONG_MAX);
    printf("最小の整数： %lli\n", LLONG_MIN);

    return 0;
}//main

/*
最大の整数： 9223372036854775807
最小の整数： -9223372036854775808
*/