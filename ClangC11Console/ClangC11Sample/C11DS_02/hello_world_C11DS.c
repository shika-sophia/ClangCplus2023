/*
�ŏ��̃v���O����
*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) 
{
    if (argc == 1) {
        puts("hello world!");
    }
    else {
        int sum = 0;
        //�C���f�b�N�X0�͖�������
        for (int i = 1; i < argc; i++) {
            sum += atoi(argv[i]);
        }//for

        printf("sum = %d\n", sum);
    }//if,else
    return 0;
}//main

/*
�y���s���z
�R�}���h�v�����v�gVS2019
���ϐ��Ƀ����J�[��o�^
�J�����g�f�B���N�g���ɓ��������J�[���R�s�[
�f�X�N�g�b�v��VS����\�[�X�t�@�C�����R�s�[

>cd C:\Users\******\Desktop\C11DS\C11DS_02     //�J�����g�f�B���N�g���Ɉړ�

C:\Users\******\Desktop\C11DS\C11DS_02>cl hello_world_C11DS.c  //�R���p�C��
Microsoft(R) C/C++ Optimizing Compiler Version 19.29.30147 for x86
Copyright (C) Microsoft Corporation.  All rights reserved.

hello_world_C11DS.c
Microsoft (R) Incremental Linker Version 14.29.30147.0
Copyright (C) Microsoft Corporation.  All rights reserved.

/out:hello_world_C11DS.exe
hello_world_C11DS.obj

C:\Users\******\Desktop\C11DS\C11DS_02>hello_world_C11DS   //���s
hello world!

C:\Users\******\Desktop\C11DS\C11DS_02>hello_world_C11DS 1 2 3 4 5
sum = 15

C:\Users\******\Desktop\C11DS\C11DS_02>hello_world_C11DS hello 2024
sum = 2024

C:\Users\******\Desktop\C11DS\C11DS_02>exit
*/