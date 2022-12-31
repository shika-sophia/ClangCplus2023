/**
*@directory ClangC11Console / ClanC11Sample / C99YH / C99YH10_Struct
*@fileName  MainCalculateRectangleArea.c
*@reference C99YH  ���� �_ �wC����v���O���~���O���b�X�� [�����] ��R�ŁxSB Creative, 2019
*@reference CAnsi  ���� �_ �wC����v���O���~���O���b�X�� [���@��] �V�Łx  SB Creative, 2006
*@reference C11DS  arton  �w�ƏK C �V�Łx�ĉj��, 2018
*
*@content C99YH ��10�� �\���� Practice 10-3 | Chapter 10  Struct / List E10-3 / p334
*@summary MainCalculateRectangleArea.c
*@English [��] rectangle:  �l�p�`
*         [��] area:       �ʐ�   = square
*         [��] line segment: ����
*         [�p] verify:     ���؂���
*         [��] subtract:   ��, ���Z
* 
*@subject Practice 10-3  Complete List E10-3 to show caluculated Rectangle Area value.
*
*@subject <math.h>
*           �� int  abs(int x)  
*               It returns the absolute value.
*               But if x is float or double type, it is not available,
*               because it deletes a part of value under floating point by changing the type [float or double -> int].
* 
*           �� double  fabs(double x) 
*
*subject Algorithm of Distance between line segments
*        �EIt calculate absolute value of subtract by verifing higher or lower of each values.
*        �EIt is available in any case: whichever a, b are plus or minus sign.
* 
*        [Example] self-defined Function
*        double distance(double a, double b) {
*            if (a > b) {
*                return a - b; 
*            } else {
*                return b - a;
*            }
*        }//distance()
* 
*        [Example] Another Solution: default-defined standard Function
*        <math.h>
*          �� double  fabs(a - b)
* 
*@see
*@author shika
*@date 2022-12-30
*/

#include <stdio.h>
#include <math.h>

//====== Struct Declaration ======
typedef struct Rectangle {
    double x1, y1;  //Top Left Point 
    double x2, y2;  //Bottom Right Point
} RECT;

//====== Prototype Declaration ======
double distance(double, double);
double calcArea(RECT);

//====== Fuction Definition ======
//int main(void) {
int mainCalculateRectangleArea(void) {
    RECT rect;
    double area;

    rect.x1 = 3.1;
    rect.y1 = 4.1;
    rect.x2 = 5.9;
    rect.y2 = -2.6;

    area = calcArea(rect);

    printf("Rectangle (%g,%g)-(%g,%g) Area: %g \n",
        rect.x1, rect.y1, rect.x2, rect.y2, area);

    return 0;
}//main()

double distance(double a, double b) {
    if (a > b) {
        return a - b; 
    } else {
        return b - a;
    }
}//distance()

double calcArea(RECT rect) {
    double x, y; // 2 line segment distance of Rectangle
    x = distance(rect.x1, rect.x2);
    y = distance(rect.y1, rect.y2);

    return x * y;
}//calcArea()

/*
//====== Result ======
Rectangle (3.1,4.1)-(5.9,2.6) Area: 4.2
Rectangle (3.1,4.1)-(5.9,-2.6) Area: 18.76

*/