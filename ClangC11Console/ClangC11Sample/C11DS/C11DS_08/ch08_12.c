/*
・ソート関数 qsort()を利用したプログラム。
qsort(void* base, size_t nmemb, size_t size,
      int(*compare)(const void*, const void*));
*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int compare(const void* p0, const void* p1)
{
    return *(int32_t*)p0 - *(int32_t*)p1;
}//compare

int main(void) 
{
    int32_t array[] = { 32, 18, 97, 5, -4, 32, 10, -99 };

    qsort(array, sizeof(array) / sizeof array[0], sizeof(int32_t), compare);

    for (size_t i = 0; i < sizeof(array) / sizeof array[0]; i++) {
        printf("%i\n", array[i]);
    }
}//main

/*
>ch08_12
-99
-4
5
10
18
32
32
97

*/