/*
5. 8ビットの符号なし整数で定義し、-1 で初期化。次に 16 ビットの変数、
   32ビットの変数、64ビットの変数に次々に代入。それぞれを表示するプログラム

*/

#include <stdio.h>
#include <stdint.h>

int main(void)
{
    uint8_t uint8 = -1;
    int16_t int16 = uint8;
    int32_t int32 = int16;
    int64_t int64 = int32;

    printf("uint8: %d\n", uint8);
    printf("int16: %d\n", int16);
    printf("int32: %d\n", int32);
    printf("int64: %lli\n", int64);

    return 0;
}//main
/*
uint8: 255
int16: 255
int32: 255
int64: 255
*/
