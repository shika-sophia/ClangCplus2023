/*
2. 「go to」文を使わずに例5.5-2と同等のプログラム。
*/

#include <stdio.h>
int main(void)
{
    for (int i = 0; i < 8; i++) {
        switch (i % 3) {
        case 0:
            printf("%i Fizz\n", i);
            break;

        case 1:
            printf("%i Fizz + 1\n", i);
            break;

        case 2:
            break;//switch

        default:
            puts("<!> Bug! never come here");
        }//switch

        if (i % 3 == 2) {
            break;//for
        }
    }//for

    puts("end");
    return 0;
}//main

/*
>ch05_05q_02
0 Fizz
1 Fizz + 1
end
*/