/*
3. 2行3列の行列を表す変数 m を初期化子なしで宣言し、最初の行が 1, 2, 3、
次の行が 4, 5, 6となるよう代入する。
外側のループを do 文で、内側のループを while 文で 1 から 6 までを出力するプログラム。
*/

#include <stdio.h>

int main(void)
{
    int m[2][3];
    m[0][0] = 1;
    m[0][1] = 2;
    m[0][2] = 3;
    m[1][0] = 4;
    m[1][1] = 5;
    m[1][2] = 6;

    int i = 0;
    int j = 0;
    do {
        while (j < 3) {
            printf("m[%i][%i] = %i\n", i, j, m[i][j]);
            j++;
        }//while
        j = 0;
        i++;
    } while (i < 2);

    return 0;
}//main

/*
>ch06_04q_05
m[0][0] = 1
m[0][1] = 2
m[0][2] = 3
m[1][0] = 4
m[1][1] = 5
m[1][2] = 6
*/