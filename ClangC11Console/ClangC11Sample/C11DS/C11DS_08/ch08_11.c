/*
・関数ポインター culc(int, int)に add(int, int)か mul(int, int)を代入するプログラム。
*/

#include <stdio.h>
#include <stdlib.h>

int add(int x, int y)
{
    return x + y;
}//add

int mul(int x, int y)
{
    return x * y;
}//mul

int main(int argc, char* argv[])
{
    if (argc < 3) {
        return 1;
    }
    int (*culc)(int, int);
    char ch = *argv[1];

    int result;
    if (ch == '+') {
        culc = add;
        result = 0;
    }
    else if (ch == '*') {
        culc = mul;
        result = 1;
    }
    else {
        return 2;
    }

    for (int i = 2; i < argc; i++) {
        result = culc(result, atoi(argv[i]));
    }//for

    printf("%i\n", result);
}//main

/*
>ch08_11 + 1 2 3 4 5
15

>ch08_11 * 1 2 3 4 5
120

*/