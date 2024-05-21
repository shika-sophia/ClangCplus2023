/*
？3. コマンドライン引数で与えられた単語をソートして表示するプログラム。
(解答を見て記述)
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(const void* p0, const void* p1)
{
    return strcmp(*(char**)p0, * (char**)p1);
}//compare

int main(int argc, char* argv[])
{
    if (argc < 2) {
        puts("<!> arguments!");
        return 1;
    }

    char array[argc - 1];
    for (int i = 1; i < argc; i++) {
        array[i - 1] = array[i];
    }//for

    qsort(array, argc - 1, sizeof(char*), compare);
    for (int i = 0; i < argc - 1; i++) {
        puts(array[i]);
    }
}//main

/*
【コンパイル・エラー】
定数式が必要です。
error C2466: サイズが 0 の配列 を割り当てまたは宣言しようとしました。
*/