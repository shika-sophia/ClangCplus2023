/*
(3) xp�𗘗p���Ă��̒l 1238 ���o�͂���v���O(3) xp�𗘗p���Ă��̒l 1238 ���o�͂���v���O�����B
*/

#include <stdio.h>
#include <stdint.h>

int main(void)
{
    int32_t x = 1234;
    int32_t* xp = &x;
    *xp += 4;
    printf("x = %i, xp = %p\n", *xp, xp);
}//main

/*
>ch08_01q_01
x = 1238, xp = 004FFA74
*/