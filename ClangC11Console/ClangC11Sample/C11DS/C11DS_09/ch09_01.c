/*
・externの用法
*/

#include <stdio.h>

extern int ex2(int x, int y);

extern int ex1(int x, int y)
{
    printf("ex1: %i\n", x + y);
    return x + y;
}//ex1

int main()
{
    ex1(2, 3);
    ex2(5, 6);
}

/*
【コンパイル・エラー】
未解決の外部シンボル _ex2 が関数 _main で参照されました
ch09_01.exe : fatal error LNK1120: 1 件の未解決の 外部参照

>ch09_01
ex2: 30
*/