/**
*@directory ClangC11Console / ClanC11Sample / C99YH / C99YH10_Struct
*@fileName  MainGraphicsStructSample.c
*@reference C99YH  結城 浩 『C言語プログラミングレッスン [入門編] 第３版』SB Creative, 2019
*@reference CAnsi  結城 浩 『C言語プログラミングレッスン [文法編] 新版』  SB Creative, 2006
*@reference C11DS  arton  『独習 C 新版』翔泳社, 2018
*
*@content C99YH 第10章 構造体 | Chapter 10  Struct / List 10-6 / p314
*@summary MainGraphicsStructSample
*         ・'struct' can nest other 'struct'
* 
*@English [幾] coordinate: 座標
*         [幾] rectangle:  四角形
*         [英] nest:       入れ子
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
*         => Another Project  [C++, WindowsAPI] ->〔CppWinApiGUI〕
*         => Another Solution [C#, WindowsForm] ->〔WinFormGUI/WinFormSample/ReverseReference/RR13_Graphics〕
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