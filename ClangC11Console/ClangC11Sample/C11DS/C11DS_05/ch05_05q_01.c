/*
�����K���5.5 p137
 1. �ugo to�v�����g�킸�ɗ�5-1�Ɠ����̃v���O�����B
*/
#include <stdio.h>

int main(void)
{
    for(int x = 0; x < 5; x++){ 
        for (int y = 0; y < 5; y++) {
            for (int z = 0; z < 5; z++) {
                printf("x: %i, y: %i, z: %i\n", x, y, z);
                if (x == 1 && y == 2 && z == 3) {
                    break;
                }
            }//z
            if (x == 1 && y == 2) {
                break;
            }
        }//y
        if (x == 1) {
            break;
        }
    }//x
    
    puts("end");
}//main

/*
>ch05_05q_01
x: 0, y: 0, z: 0
x: 0, y: 0, z: 1
x: 0, y: 0, z: 2
x: 0, y: 0, z: 3
x: 0, y: 0, z: 4
x: 0, y: 1, z: 0
x: 0, y: 1, z: 1
x: 0, y: 1, z: 2
x: 0, y: 1, z: 3
x: 0, y: 1, z: 4
x: 0, y: 2, z: 0
x: 0, y: 2, z: 1
x: 0, y: 2, z: 2
x: 0, y: 2, z: 3
x: 0, y: 2, z: 4
x: 0, y: 3, z: 0
x: 0, y: 3, z: 1
x: 0, y: 3, z: 2
x: 0, y: 3, z: 3
x: 0, y: 3, z: 4
x: 0, y: 4, z: 0
x: 0, y: 4, z: 1
x: 0, y: 4, z: 2
x: 0, y: 4, z: 3
x: 0, y: 4, z: 4
x: 1, y: 0, z: 0
x: 1, y: 0, z: 1
x: 1, y: 0, z: 2
x: 1, y: 0, z: 3
x: 1, y: 0, z: 4
x: 1, y: 1, z: 0
x: 1, y: 1, z: 1
x: 1, y: 1, z: 2
x: 1, y: 1, z: 3
x: 1, y: 1, z: 4
x: 1, y: 2, z: 0
x: 1, y: 2, z: 1
x: 1, y: 2, z: 2
x: 1, y: 2, z: 3
end
*/