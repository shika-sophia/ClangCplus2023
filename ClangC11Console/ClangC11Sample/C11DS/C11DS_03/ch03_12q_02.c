/*
2. キャスト式を用いてINT_MIN を正数として表示するプログラム。
ただし、 printf()の書式指定子には 「%lli」 を使うこと。
結果として「2147483648」を出す。*/
#include <stdio.h>
#include <limits.h>

int main(void)
{
    int int_min = INT_MIN;
    long long int lli = (long long int)int_min;
    printf("%lli\n", -lli);

    return 0;
}//main
/*
>ch03_12q_02
2147483648

【考察】
解答では「unsigned int」にキャストして、それを「long long」にキャストしている。

*/