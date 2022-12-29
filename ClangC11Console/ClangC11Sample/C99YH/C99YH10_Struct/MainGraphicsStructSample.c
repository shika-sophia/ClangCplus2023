/**
*@directory ClangC11Console / ClanC11Sample / C99YH / C99YH10_Struct
*@fileName  MainGraphicsStructSample.c
*@reference C99YH  ���� �_ �wC����v���O���~���O���b�X�� [�����] ��R�ŁxSB Creative, 2019
*@reference CAnsi  ���� �_ �wC����v���O���~���O���b�X�� [���@��] �V�Łx  SB Creative, 2006
*@reference C11DS  arton  �w�ƏK C �V�Łx�ĉj��, 2018
*
*@content C99YH ��10�� �\���� | Chapter 10  Struct / List 10-6 / p314
*@summary MainGraphicsStructSample
*         �E'struct' can nest other 'struct'
* 
*@English [��] coordinate: ���W
*         [��] rectangle:  �l�p�`
*         [�p] nest:       ����q
* 
*@subject Access to nested struct: 
*         [Example]
*         struct LineByPoint lineP;  //definition of struct
*         lineP.point1.x = 10;       //substitution
*         lineP.point1.y = 12;       //substitution
* 
*@subject (main() code disappear yet.)
*         (Here is to show only Examples of Graphics struct.)
* 
*         => Another Project  [C++, WindowsAPI] ->�kCppWinApiGUI�l
*         => Another Solution [C#, WindowsForm] ->�kWinFormGUI/WinFormSample/ReverseReference/RR13_Graphics�l
* 
*@see
*@author shika
*@date 2022-12-29
*/

#include <stdio.h>

//====== Graphics Struct ======
struct Point {
    double x;
    double y;
};

struct LineByCoordinate {
    double x1;
    double y1;
    double x2;
    double y2;
};

struct LineByPoint {
    struct Point point1;
    struct Point point2;
};

struct RectangleByCoordinate {
    double x1;
    double y1;
    double x2;
    double y2;
};

struct RectangleByPoint {
    struct Point point1;
    struct Point point2;
};

//int main(void) {
int mainGraphicsStructSample(void) {

    return 0;
}//main()