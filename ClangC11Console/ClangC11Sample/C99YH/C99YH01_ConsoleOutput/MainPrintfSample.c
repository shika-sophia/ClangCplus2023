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
*         int   printf()
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
*@subject <stdio.h> => �kC99YH12_FileOperation\MainFileOpenInputSample.c�l
*           �� int  printf(char format [, T value1] [, T value2] ...)
*                   �� T: int�Ȃǐ��l�^, char, string
* 
*         �Eprint format �̗�
*         �E�����R�[�h UNIX�n(Mac, Linux): UTF-8
*                     Windows default:    Shift_JIS
*         �E���s  "\n"
* 
*         ��printf() �̏��������� �kC99YH �t�^ p446�l
*         ������������ format
*         % [�t���O] [�ŏ��t�B�[���h��] [. ���x] [�����w��q]
*
*         ���t���O: �o�͂̈ʒu�A�o�͌`��
*           -:   ���l��  (�ȗ�����ƉE�l��)
*           +:   �����t��(�ȗ�����ƕ����̂݁u-�v�����t��)
*          �u �v(�X�y�[�X): �ŏ��̕����������łȂ���΁A�X�y�[�X��}��
*           0:   �t�B�[���h���܂� 0 ��}��
*           #:   �ϊ��w��q �kbelow�l
*               o:  �ŏ��̌��� 0 ��t�L�B (octa-decimal: 8�i��)
*               x:  �ŏ��̌��� 0x ��t�L�B(hexa-decimal: 16�i��)
*               X:  �ŏ��̌��� 0X ��t�L�B(hexa-decimal: 16�i��)
*               a, A, e, E, f, F:  �����_��t�L
*               g, G:              �����_��t�L���A�㑱�� 0 ��}��
* 
*         ���ŏ��t�B�[���h��: �o�͂̍ŏ���
*           �E0 �ȏ��10�i�������l�Ŏw��
*           �E�w�蕝��茅�������ꍇ�A�����ŕ����g�����ĕ\��
*           �E�w�蕝��茅�����Ȃ��ꍇ�A�f�t�H���g�Łu �v�X�y�[�X��}���B�u�t���O�v�Ŏw�肵���ꍇ�͂���ɏ]���B
*           �E�u*�v���w�肷��� printf(string, int) �� ���� int ���t�B�[���h���Ƃ���B
*         
*         �����x  �o�͂��鐔���̌� (�ϊ��w��q�ɂ���ĈقȂ�)
*           �E0 �ȏ��10�i�������l�Ŏw��
*           �E�u*�v���w�肷��� printf(string, int) �� ���� int �𐸓x�Ƃ���B
*           �E�ϊ��w��q �kbelow�l
*               d, i, o, u, x, X:  �o�͂��鐔���̍ŏ���
*               a, A, e, E, f, F:  �����_�ȉ��̐����̌�
*               g, G:              ���l�^�̍ő�L������
*               s:                 string �ő�o�C�g��
* 
*         �������w��q  �Ή���������̌^�̒����A�o�͂���^
*            hh:  signed char�^, unsigned char�^ �Ƃ��ďo��
*            h:   short int�^, unsigned short�^ �Ƃ��ďo��
*            l:   long int�^, unsigned long int�^ �Ƃ��ďo��
*            ll:  long long int�^, unsigned long long int�^ �Ƃ��ďo�� 
*            j:   intmax_t�^, unitmax_t�^ �Ƃ��ĕ\��
*            z:   size_t�^ (= ���Z�q sizeof �̌^) �Ƃ��ĕ\��
*            t:   printdiff_t�^ (= �|�C���^�̍���\���^) �Ƃ��ĕ\��
*            L:   long double�^�Ƃ��ĕ\��
* 
*          ���ϊ��w��q  �o�͌`��
*            d, i:   int    10�i�� �����t��  //decimal, integer �̗�
*            u:      int    10�i�� �����Ȃ�  //unsigned
*            o:      int    8�i�� �����Ȃ�   //octa-decimal
*            x:      int    16�i�� �����Ȃ� (abcdef ���������\�L)  //hexa-decimal
*            X:      int    16�i�� �����Ȃ� (ABCDEF ��啶���\�L)
*            c:      int    ���� unsigned char�^�ɕϊ�            //character
*            s:      char   ������ ('\0'�����邩�A�w�肵�����x�܂ŏo��) �����L
*            f, F:   double ������ 10�i���\�L (�����_�ȉ��̌����͐��x�Ŏw��B�l�̊ۂ߂���) //float
*            e, E:   double ������ ���K���\�L [-] 1.234567e+01 �ȂǁA E�Ȃ� E (����)
*            g, G:   double ���x�ɂ���� e, f / E, F�@�̂����ꂩ���g�p
*            a, A:   double 16�i���̐��K���\�L [-] 1.234567p+01 �ȂǁA A�Ȃ� P
*            p:      void   �|�C���^�Ƃ��ďo�� (�����n�ˑ�) �����L
*            n:      int    ����܂ŏo�͂����������������ɕԂ� (�Z�L�����e�B��̗��R���� C11 �Ŕp�~) �����L
*            %:             �u%�v�𕶎��Ƃ��ďo��
*            
*            ���y���z�Z�L�����e�B��A��肪����̂ŁA
*               [C11]�ł� �Z�L�����e�B��z������ printf_s() �֐��𗘗p����B
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

//int main(void){
int mainPrintfSample(void) {
	printf("Hello World.\n");
	printf("Hello Japan.\n");
	printf("�͂��߂܂��āA�b���ꂳ��B\n");

	return 0;
}//main()

/*
//====== Result ======
Hello World.
Hello Japan.
�͂��߂܂��āA�b���ꂳ��B

*/