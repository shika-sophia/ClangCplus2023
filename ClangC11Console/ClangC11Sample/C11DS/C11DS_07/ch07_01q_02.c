/*
3. ユニコード「な」は 0x306A、「に」は 0x306B、「の」は 0x306E
「な」から「の」は 1 ずつ増える。for 文を使って「な」から「の」を各行に表示するプログラム。
(解答を見て記述 p426)
*/
#include <stdio.h>
#include <wchar.h>
#include <locale.h>

int main(void)
{
    setlocale(LC_CTYPE, "ja");
    for (wchar_t c = L'な'; c <= L'の'; c++) {
        printf("%lc\n", c);
    }//for
}//main

/*
>ch07_01q_02
な
に
ぬ
ね
の
*/