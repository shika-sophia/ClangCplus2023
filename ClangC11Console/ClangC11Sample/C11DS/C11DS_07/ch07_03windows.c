/*
—á7.3 ƒƒCƒh•¶š‚Ìo—Í p163
*/

#include <stdio.h>
#include <locale.h>
#include <uchar.h>

int main(void)
{
    setlocale(LC_CTYPE, "ja");
    wchar_t a = L'‚ ';
    char16_t a0 = u'‚ ';
    char32_t a1 = U'‚ ';
    printf("%lc\n", a);

}//main

/*
>ch07_03windows
‚ 

*/
