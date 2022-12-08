/**
*@title ClangC11Console / ClanC11Sample / C99YH / C99TH01_ConsoleOutput
*@class MainPrintfSample.c
*@reference C99YH  ���� �_ �wC����v���O���~���O���b�X�� [�����] ��R�ŁxSB Creative, 2019
*@reference CAnsi  ���� �_ �wC����v���O���~���O���b�X�� [���@��] �V�Łx  SB Creative, 2006
*@reference C11DS  arton  �w�ƏK C �V�Łx�ĉj��, 2018
*
*@content C99YH ��P�� �\�� p13- / main(), printf()
*@summary #include 
*         <stdio.h>
*         int   main(void)
*         void  printf(string)
*
*@subject #include <stdio.h>
*         #xxxx         //�f�B���N�e�B�u: �v���v���Z�b�T(=�R���p�C���O�̏���)�ւ̖���
*         #include xxxx //xxxx�� import ���A���s��������ɎQ�Ƃ��閽��
* 
*@subject <stdio.h> �w�b�_�[�t�@�C���B 
*         �EStandard IO�̗�
*         �EConsole�ł� ��{�I�ȓ��́E�o�͂����� �w�b�_�[�t�@�C��
* 
*@subject int   main()
*         �E�v���O�����̃G���g���[�|�C���g�B
*         �E�u.exe�v�� main()��T���A����������s����B
*         �Emain()�����݂��Ȃ��ƃR���p�C���G���[�Bmain()����������ꍇ�����l�B
*         �E���� void ��������
*         �E�ߒl int�Breturn 0; �Ł@0 ���Ԃ�� �v���O�������I������B
* 
*@subject void  printf(string)
*         �Eprint format �̗�
*         �E�����R�[�h UNIX�n(Mac, Linux): UTF-8
*                     Windows default:    Shift_JIS
* 
*
*@NOTE �y���z�u.h�v�w�b�_�[�t�@�C��
*       #incude "MainPrintfSample"
*       �E�u"�v�Ŋ����� include���\�B���Ȓ�`�̃w�b�_�[�t�@�C���ւ̎Q�Ƃ��Ǝv����B
*       �EC++ �ŃN���X�������A�u.c�v�u.h�v����������A
*         class �� �u.h�v�ɋL�q�����B
*         ���O�̕ύX�A�f�B���N�g���K�w�̕ύX�Ŏ��ʂ���Ȃ��Ȃ�̂Œ���
*         �u.c�v���� class ���L�q���Ă� �uclass �͎��ʎq�Ƃ��Ē�`����Ă��܂���v�ƂȂ�
*       
*        �E�u.h�v���폜���Ă��A���s�ɉe���͂Ȃ��B
*        
*       �Eclass �Ƃ́A�I�u�W�F�N�g�w���ŁA�e�v���O�����𕔕i�����čė��p���邽�߂̊T�O�B
*         C �ɂ� class �Ƃ����T�O���Ȃ��BC++ �ŏ��߂� �I�u�W�F�N�g�w���𓱓����ꂽ�B
* 
*@see
*@author shika
*@date 2022-12-08
*/

#include <stdio.h>

//class MainPrintfSample { };
//int main(void);
//
//int main(void) {
//	printf("Hello World.\n");
//	printf("Hello Japan.\n");
//	printf("�͂��߂܂��āA�b���ꂳ��B\n");
//
//	return 0;
//}//main()

/*
//====== Result ======
Hello World.
Hello Japan.
�͂��߂܂��āA�b���ꂳ��B

*/