/*
2. int�^�̕ϐ���INT_MAX�ŏ��������A�R�}���h���C�������ŏ��Z��������B
 ���� �R�}���h���C�������� 0 �Ȃ�G���[���o���B�ŏI�I�Ȍ��ʂ�\������v���O�����B
 if����1�񂾂����p�Bbreak�����g���Ƃ͌���Ȃ��Bfor���̏������� argc �� i ���r����B
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char* argv[])
{
    int x = INT_MAX;

    if (argc == 1) {
        puts("number!");
        return 1;
    }

    for (int i = 1; i < argc; i++) {

        if (atoi(argv[i]) == 0) {
            puts("<!> divisor is 0.");
            return 2;
        }

        x /= atoi(argv[i]);
    }//for

    printf("result = %d\n", x);
   
    return 0;
}//main

/*
>ch05_03q_02
number!

>ch05_03q_02 3 6 9
result = 13256071

>ch05_03q_02 3 5 0 9
<!> divisor is 0.

>ch05_03q_02 300 500 900
result = 15
*/