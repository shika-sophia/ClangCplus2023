/*
例7.3 ワイド文字の出力 p163
*/

#include <stdio.h>
#include <locale.h>
#include <uchar.h>

int main(void)
{
    setlocale(LC_CTYPE, "ja");
    wchar_t a = L'あ';
    char16_t a0 = u'あ';
    char32_t a1 = U'あ';
    printf("%lc\n", a);

}//main

/*
>ch07_03windows
あ

*/
