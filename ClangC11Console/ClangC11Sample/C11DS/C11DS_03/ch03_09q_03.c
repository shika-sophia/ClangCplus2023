/*
3. —á3.8-3‚ğ•Ï”‚É‘ã“ü‚µ‚Ä‚©‚ço—Í‚·‚éƒvƒƒOƒ‰ƒ€
*/
#include <stdio.h>
#include <limits.h>

int main(void)
{
    int int_max = INT_MAX;
    unsigned int uint_max = UINT_MAX;
    long int lint_max = LONG_MAX;
    unsigned long int ul_max = ULONG_MAX;
    long long int lli_max = LLONG_MAX;
    unsigned long long llu_max = ULLONG_MAX;

    printf("int_max:int_max %i\n", int_max);
    printf("unsigned int_max: %u\n", uint_max);
    printf("long int_max: %li\n", lint_max);
    printf("unsigned long int_max: %ul\n", ul_max);
    printf("long long int_max: %lli\n", lli_max);
    printf("unsigned long long int_max: %llu\n", llu_max);
   
    return 0;
}//main

/*
int_max:int_max 2147483647
unsigned int_max: 4294967295
long int_max: 2147483647
unsigned long int_max: 4294967295l
long long int_max: 9223372036854775807
unsigned long long int_max: 18446744073709551615

*/