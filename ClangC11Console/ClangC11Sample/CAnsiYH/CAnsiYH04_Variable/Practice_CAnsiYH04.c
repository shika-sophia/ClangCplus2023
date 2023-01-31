/**
*@directory ClangC11Console / ClanC11Sample / CAnsiYH / CAnsiYH04_Variable
*@fileName  Practice_CAnsiYH04.c
*@reference C99YH    Œ‹é _ wCŒ¾ŒêƒvƒƒOƒ‰ƒ~ƒ“ƒOƒŒƒbƒXƒ“ [“ü–å•Ò] ‘æ‚R”ÅxSB Creative, 2019
*@reference CAnsiYH  Œ‹é _ wCŒ¾ŒêƒvƒƒOƒ‰ƒ~ƒ“ƒOƒŒƒbƒXƒ“ [•¶–@•Ò] V”Åx  SB Creative, 2006
*@reference C11DS    arton  w“ÆK C V”ÅxãÄ‰jŽÐ, 2018
*
*@content CAnsiYH Chapter 4  Variable | Practice / List - / p85
*@summary Practice_CAnsiYH04.c
*@English
*@subject Practice 1:
*         Tell each Scope, Storage Class, Linkage of these Variable as following:
* 
*         [Example]
*         int a;
*         static int b;
*         extern int c;
* 
*         void func(void) {
*             int d;
*             static int e;
*             extern int f
*         }
* 
*         [My Answer]                    -> [Book Answer]
*         a) Scope:          File Scope
*            Storage Class:  static
*            Linkage:        [~]Internal -> External
* 
*         b) Scope:          File Scope
*            Storage Class:  static
*            Linkage:        Internal
* 
*         c) Scope:          File Scope
*            Storage Class:  [~] extern  -> static
*            Linkage:        External
* 
*         d) Scope:          Block Scope
*            Storage Class:  auto
*            Linkage:        Internal
* 
*         e) Scope:          Block Scope
*            Storage Class:  static
*            Linkage:        Internal
* 
*         f) Scope:          Block Scope
*            Storage Class:  [~] extern    -> static   
*            Linkage:        External
* 
*@subject Practice 2:
*         Explain how the Function 'foo()' will behave, as below.
* 
*         [Example]
*         int foo(void) {
*              static int n = 0;
*              return n++;
*         }
* 
*         [My Answer]
*         Variable 'static int n;' cannot be seen from out of the Block,
*         so that it return 0 at the time of 'return' statement,
*         so that it refer nothing at origin of calling the foo().
* 
*         If the Return Value will be assigned or referred, 
*         the code will be thrown Compile Error, because of NULL Pointer.
*
*         => Wrong
* 
*         [Book Answer]
*         The Function 'foo()' returns the number which is increased at each times of calling itself, such as 0, 1, 2,... .
*         At first time, it returns 0, because Variable with 'static' is impilictly initalitzed as 0 then.
*         The 'foo()' continue to storage the number, even if Control is out of the Block, because of 'static'.
* 
*        yConsiderationz
*         My Answer confused 'static' and 'auto'. I am required to learn carefully again.
* 
*@subject Practice 3:
*         Explain what role of Variable 'lastColor' is taking, as below.
* 
*         [Example]
*         void changeColor (COLOR color) {
*             static COLOR lastColor = INVALID_COLOR;
* 
*             if (color != lastColor) {
*                 setColor(color);
*                 lastColor = color;
*             }
*         }
* 
*         [My Answer]
*         The 'struct lastColor' storage 'stuct color' of last set here.
*         If next argument color is equal to last one, the Function do noting.
*         If it is not equal only, the Function call 'setColor()' with argument 'color'.
*         Therefore, 'lastColor' take a role as condition of calling setColor().
* 
*         It is concealed by 'static', 
*         so that it cannot be seen and changed from out of the Block.
* 
*         => Correct
*   
*         [Book Answer]
*         If the Function 'setColor()' would take time to operate, 
*         the code can abbreviate the time with the condition (= by using 'lastColor').
* 
*@subject Practice 4:
*         Tell which the Expression of Left Side Values are in (a)-(m).
*         Assuming that:
* 
*         [Example]
*         char c;
*         char *p;
*         
*         typedef struct SchoolMate {
*             int id;
*             char name[20];
*             int japanese;
*             int mathematics;
*             int english;
*         } MATE;
* 
*         MATE *mateP;
*         char aAry[2][4] = {"abc", "def" };
*         char *pAry[2] = { "abc", "def" };
*
*         (a) c / (b) &c / (c) &p / (d) p / (e) *p / 
*         (f) mateP->id / (g) mateP->name /
*         (h) aAry[0][0] / (i) aAry[0] / (j) aAry
*         (k) pAry[0][0] / (L) pAry[0] / (m) pAry
* 
*         [My Anaswer]
*         Nothing, because there is not any assignment.
*         => I don't understand this question meaning.
*         => see Book Answer.
* 
*         [Book Answer]
*         Correct Solution: (a), (d), (e), (f), (h), (k), (L)
*
          They are Expressions of Left Side Value.
*         The question seems to mean "can be assigned".
*     
*         (Reasons)
*         Z(a) c can be assigned
*         ~(b) &c is address Literal of 'c', so that it cannot be assigned.
*         ~(c) &p is as same as above.
*         Z(d) p can be assigned.
*         Z(e) *p is the value which 'p' indicate, and '*p' can be assigned. 
*         Z(f) (mateP->id) can be referred and assigned. 
*      -> ~(g) (mateP->name) cannot be assigned directly.
*              If (mateP->name[0]), it can be done.
*         Z(h) aAry[0][0] can be assigned.
*      -> ~(i) aAry[0] cannot be assigned, because aAry[0] is regarded as Identifier of Array.
*         ~(j) aAry cannot be assigned, because it is a Identifier.
*         Z(k) pAry[0][0] can be assigned.
*      -> Z(L) pAry[0] can be assigned, because pAry[0] is regarded as Pointer.
*         ~(m) pAry cannot be assigned, because it is a Identifier.
* 
*       ¦ They should be especially required Annotations at '->' mark above.
* 
*@see
*@author  shika
*@date    2023-01-31
*/

#include <stdio.h>

//int main(void) {
int mainPractice_CAnsiYH04(void) {

    return 0;
}//main()