/*
3. ���j�R�[�h�u�ȁv�� 0x306A�A�u�Ɂv�� 0x306B�A�u�́v�� 0x306E
�u�ȁv����u�́v�� 1 ��������Bfor �����g���āu�ȁv����u�́v���e�s�ɕ\������v���O�����B
(�𓚂����ċL�q p426)
*/
#include <stdio.h>
#include <wchar.h>
#include <locale.h>

int main(void)
{
    setlocale(LC_CTYPE, "ja");
    for (wchar_t c = L'��'; c <= L'��'; c++) {
        printf("%lc\n", c);
    }//for
}//main

/*
>ch07_01q_02
��
��
��
��
��
*/