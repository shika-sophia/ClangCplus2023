/*
2. 1, 2, 3, ... と掛け算していって、16bit符号付き整数と 32bit符号付き整数の最大値と
 最後の乗数を表示するプログラム。
 (1) for文2つで作る
*/

#include <stdio.h>
#include <stdint.h>

int main(void)
{
    int16_t result16 = 1;
    int32_t result32 = 1;

    for (int i = 1; i <= INT16_MAX; i++) {
        if (result16 * i < 0 || result16 * i > INT16_MAX) {
            printf("16bit= %i last multiple= %i\n", result16, i - 1);
            break;
        }

        result16 *= i;
    }//for16

    for (int i = 1; i <= INT32_MAX; i++) {
        if (result32 * i < 0 || result32 * i > INT32_MAX) {
            printf("32bit= %i last multiple= %i\n", result32, i - 1);
            break;
        }

        result32 *= i;
    }//for32
}//main

/*
出力が出て来ない・・・
break;の終了条件に「* i」を加えないと永久ループになっていたかも
負値の条件も加えてやっと出力が出た。（永久ループ解消）

>ch05_06q_02
16bit= 5040 last multiple= 7
32bit= 2004189184 last multiple= 16

サンプルより大きな数になっている。


*/
