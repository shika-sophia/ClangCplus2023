/**
*@directory ClangC11Console / ClanC11Sample / CAnsiYH / CAnsiYH02_Basic
*@fileName  MainAsciiCharacterViewer.c
*@reference C99YH    ���� �_ �wC����v���O���~���O���b�X�� [�����] ��R�ŁxSB Creative, 2019
*@reference CAnsiYH  ���� �_ �wC����v���O���~���O���b�X�� [���@��] �V�Łx  SB Creative, 2006
*@reference C11DS    arton  �w�ƏK C �V�Łx�ĉj��, 2018
*
*@content CAnsiYH Chapter 2  Basic | ASCII Character / List 2-0 / p13
*@summary MainAsciiCharacterViewer.c
*@English
*@subject ASCII Code Chart�kC99YH 0A�l
*         I drew it as similar below.
*         It is opposite Horizontal and Vertical Axis to Chart of�kC99YH 0A�l
* 
*         The usage of Chart that you can know this charater code value (16-decimal), 
*         by adding both value of Horizontal and Vertical.
* 
*         You can output to Console, by using 'printf()'
* 
*         [Example]
*         int c;             It should be defined as 'int', not 'char'.
*         printf("%X", c);   %X or %x show 16-decimal value.
*         printf("%d", c);   %d show 10-decimal value.
*         printf("%c", c);   %c show character.
* 
*@subject ��Character Code
*         It is defined corresponding Binary which is recognaizable for Machine, to Character which is recognizable for Human.
*         There are some kinds of Character Code as below.
* 
*         ASCII: Character code default-defined by the specification of C language,
*                depending on Compiler.
* 
*         UTF-8: (Unicode):
*                Character code of most popular in the world,
*                which almost supports main languages;
*                including ASCII, 2Bytes Character, Japanese, Arabic, Hebrew, Greek, or Kiril etc...
* 
*         ECU:   (Latin1): 
*                Character code for UNIX: alphabet, numeric, symbol charater only.
* 
*         Shift-JIS: (windows-31J, CP932):
*                Character code for Japanese, as Windows default in Japan.
*
*@Note   �yConsideration�z
*         I expected output of alphabet, numeric, symbol character only, as ASCII Code Chart�kC99YH 0A�l.
*         But VS C11 Compiler might probably define them, 
*         there are some gridlines, picture character (as like emoji), 2 Bytes character, Control, Japanese Kana character as addition to above.
*         
*         In Chart case, Non-Characters don't show as well, so I replaced them to white-space.
*
*@see
*@author  shika
*@date    2023-01-16
*/

#include <stdio.h>

//int main(void) {
int mainAsciiCharacterViewer(void) {
    int c;
    int column = 256 / 16;

    //====== Show 16-decimal, 10-decimal, char Value ======
    for (int c = 0; c <= 256; c++) {
        printf("[%02X] (%3d) %c\n", c, c, c);
    }//for 
    printf("\n");

    //====== Make Chart ======
    //Horizontal Grid Line 
    printf("------");
    for (int i = 0; i < column; i++) {
        printf("-----");
    }//for
    printf("\n");

    //Column Header
    printf("| -- |");
    for (int i = 0; i < 256; i += 16) {       
        printf(" %02X |", i / 16);
    }//for
    printf("\n");

    //Horizontal and Vertical Grid Line 
    printf("|----|");
    for (int i = 0; i < column; i++) {
        printf("----|");
    }//for
    printf("\n");

    //Show Character
    printf("| 00 |");
    for (int c = 0; c < 256; c++) {

        //Replace non charcters to white-space
        if (0 <= c && c <= 31) {  
            if (c == 16) {    
                printf("\n");
                printf("| %02X |", c);
            }
            printf("    |");
            continue;
        }

        //Line Feed
        if (c != 0 && c % 16 == 0) {
            printf("\n");
            printf("| %02X |", c);
        }       

        printf(" %2c |", c);
    }//for
    printf("\n");

    //Horizontal Grid Line 
    printf("------");
    for (int i = 0; i < column; i++) {
        printf("-----");
    }//for
    printf("\n");

    printf("(EXIT_SUCCESS)\n");
    return 0;
}//main()

/*
//====== Result ======
for (int c = 0; c < 256; c++) {
    printf("[%02X] (%3d) %c\n", c, c, c);
}//for

//====== Show 16-decimal, 10-decimal, char Value ======
[00] (  0)     // NUL NULL Character '\0'
[01] (  1)    // SOH
[02] (  2)    // STX
[03] (  3)    // ETX
[04] (  4)    // EOT
[05] (  5)    // ENQ
[06] (  6)    // ACK
[07] (  7)     // BEL Beep           '\a'
[08] (  8)     // BS  Back Space     '\b'
[09] (  9)     // HT  Horizontal Tab '\t'
[0A] ( 10)     // LF  Line Feed      '\n' (new line)
[0B] ( 11)    // VT  Vertical Tab   '\v'
[0C] ( 12)    // FF  Form Feed      '\f' (new page)
[0D] ( 13)     // CR  Carrige Return '\r' (return left)
[0E] ( 14)    // SO
[0F] ( 15)    // SI
[10] ( 16)    // DLE
[11] ( 17)    // DC1
[12] ( 18)    // DC2
[13] ( 19)    // DC3
[14] ( 20)    // DC4
[15] ( 21)    // NAK
[16] ( 22)    // SYN
[17] ( 23)    // ETB
[18] ( 24)    // CAN  Cancel
[19] ( 25)    // EM
[1A] ( 26)     // SUB
                  somewhy, the one charater as like '->' (actually not two) maybe behave as 'EOF' ?
                  If it is existed, VS throw Compile Error, because "Not closed comment-out yet". 
                  So I deleted it, in temporary for another Compile.
[1B] ( 27)     // ESC  Escape [ESC]
 ] ( 28)      // FS
                  somewhy, broken value, expected [1C] of printf("%02x", c).
[1D] ( 29)    // GS
[1E] ( 30)    // RS
[1F] ( 31)    // US
[20] ( 32)     // SP  white-space
[21] ( 33) !
[22] ( 34) "
[23] ( 35) #
[24] ( 36) $
[25] ( 37) %
[26] ( 38) &
[27] ( 39) '
[28] ( 40) (
[29] ( 41) )
[2A] ( 42) *
[2B] ( 43) +
[2C] ( 44) ,
[2D] ( 45) -
[2E] ( 46) .
[2F] ( 47) /
[30] ( 48) 0
[31] ( 49) 1
[32] ( 50) 2
[33] ( 51) 3
[34] ( 52) 4
[35] ( 53) 5
[36] ( 54) 6
[37] ( 55) 7
[38] ( 56) 8
[39] ( 57) 9
[3A] ( 58) :
[3B] ( 59) ;
[3C] ( 60) <
[3D] ( 61) =
[3E] ( 62) >
[3F] ( 63) ?
[40] ( 64) @
[41] ( 65) A
[42] ( 66) B
[43] ( 67) C
[44] ( 68) D
[45] ( 69) E
[46] ( 70) F
[47] ( 71) G
[48] ( 72) H
[49] ( 73) I
[4A] ( 74) J
[4B] ( 75) K
[4C] ( 76) L
[4D] ( 77) M
[4E] ( 78) N
[4F] ( 79) O
[50] ( 80) P
[51] ( 81) Q
[52] ( 82) R
[53] ( 83) S
[54] ( 84) T
[55] ( 85) U
[56] ( 86) V
[57] ( 87) W
[58] ( 88) X
[59] ( 89) Y
[5A] ( 90) Z
[5B] ( 91) [
[5C] ( 92) \
[5D] ( 93) ]
[5E] ( 94) ^
[5F] ( 95) _
[60] ( 96) `
[61] ( 97) a
[62] ( 98) b
[63] ( 99) c
[64] (100) d
[65] (101) e
[66] (102) f
[67] (103) g
[68] (104) h
[69] (105) i
[6A] (106) j
[6B] (107) k
[6C] (108) l
[6D] (109) m
[6E] (110) n
[6F] (111) o
[70] (112) p
[71] (113) q
[72] (114) r
[73] (115) s
[74] (116) t
[75] (117) u
[76] (118) v
[77] (119) w
[78] (120) x
[79] (121) y
[7A] (122) z
[7B] (123) {
[7C] (124) |
[7D] (125) }
[7E] (126) ~
[7F] (127)    // DEL  Delete [DEL]

[80] (128) �
[81] (129) �E
[82] (130) �E
[83] (131) �E
[84] (132) �E
[85] (133) �E
[86] (134) �E
[87] (135) �E
[88] (136) �E
[89] (137) �E
[8A] (138) �E
[8B] (139) �E
[8C] (140) �E
[8D] (141) �E
[8E] (142) �E
[8F] (143) �E
[90] (144) �E
[91] (145) �E
[92] (146) �E
[93] (147) �E
[94] (148) �E
[95] (149) �E
[96] (150) �E
[97] (151) �E
[98] (152) �E
[99] (153) �E
[9A] (154) �E
[9B] (155) �E
[9C] (156) �E
[9D] (157) �E
[9E] (158) �E
[9F] (159) �E
[A0] (160) �
[A1] (161) �
[A2] (162) �
[A3] (163) �
[A4] (164) �
[A5] (165) �
[A6] (166) �
[A7] (167) �
[A8] (168) �
[A9] (169) �
[AA] (170) �
[AB] (171) �
[AC] (172) �
[AD] (173) �
[AE] (174) �
[AF] (175) �
[B0] (176) �
[B1] (177) �
[B2] (178) �
[B3] (179) �
[B4] (180) �
[B5] (181) �
[B6] (182) �
[B7] (183) �
[B8] (184) �
[B9] (185) �
[BA] (186) �
[BB] (187) �
[BC] (188) �
[BD] (189) �
[BE] (190) �
[BF] (191) �
[C0] (192) �
[C1] (193) �
[C2] (194) �
[C3] (195) �
[C4] (196) �
[C5] (197) �
[C6] (198) �
[C7] (199) �
[C8] (200) �
[C9] (201) �
[CA] (202) �
[CB] (203) �
[CC] (204) �
[CD] (205) �
[CE] (206) �
[CF] (207) �
[D0] (208) �
[D1] (209) �
[D2] (210) �
[D3] (211) �
[D4] (212) �
[D5] (213) �
[D6] (214) �
[D7] (215) �
[D8] (216) �
[D9] (217) �
[DA] (218) �
[DB] (219) �
[DC] (220) �
[DD] (221) �
[DE] (222) �
[DF] (223) �
[E0] (224) �E
[E1] (225) �E
[E2] (226) �E
[E3] (227) �E
[E4] (228) �E
[E5] (229) �E
[E6] (230) �E
[E7] (231) �E
[E8] (232) �E
[E9] (233) �E
[EA] (234) �E
[EB] (235) �E
[EC] (236) �E
[ED] (237) �E
[EE] (238) �E
[EF] (239) �E
[F0] (240) �E
[F1] (241) �E
[F2] (242) �E
[F3] (243) �E
[F4] (244) �E
[F5] (245) �E
[F6] (246) �E
[F7] (247) �E
[F8] (248) �E
[F9] (249) �E
[FA] (250) �E
[FB] (251) �E
[FC] (252) �E
[FD] (253) �
[FE] (254) �
[FF] (255) �

//---- out of definition ----
[100] (256)

//====== Make Chart ======
--------------------------------------------------------------------------------------
| -- | 00 | 01 | 02 | 03 | 04 | 05 | 06 | 07 | 08 | 09 | 0A | 0B | 0C | 0D | 0E | 0F |
|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|
| 00 |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
| 10 |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
| 20 |    |  ! |  " |  # |  $ |  % |  & |  ' |  ( |  ) |  * |  + |  , |  - |  . |  / |
| 30 |  0 |  1 |  2 |  3 |  4 |  5 |  6 |  7 |  8 |  9 |  : |  ; |  < |  = |  > |  ? |
| 40 |  @ |  A |  B |  C |  D |  E |  F |  G |  H |  I |  J |  K |  L |  M |  N |  O |
| 50 |  P |  Q |  R |  S |  T |  U |  V |  W |  X |  Y |  Z |  [ |  \ |  ] |  ^ |  _ |
| 60 |  ` |  a |  b |  c |  d |  e |  f |  g |  h |  i |  j |  k |  l |  m |  n |  o |
| 70 |  p |  q |  r |  s |  t |  u |  v |  w |  x |  y |  z |  { |  | |  } |  ~ |   |
| 80 |  � |  �E|  �E|  �E|  �E|  �E|  �E|  �E|  �E|  �E|  �E|  �E|  �E|  �E|  �E|  �E|
| 90 |  �E|  �E|  �E|  �E|  �E|  �E|  �E|  �E|  �E|  �E|  �E|  �E|  �E|  �E|  �E|  �E|
| A0 |  � |  � |  � |  � |  � |  � |  � |  � |  � |  � |  � |  � |  � |  � |  � |  � |
| B0 |  � |  � |  � |  � |  � |  � |  � |  � |  � |  � |  � |  � |  � |  � |  � |  � |
| C0 |  � |  � |  � |  � |  � |  � |  � |  � |  � |  � |  � |  � |  � |  � |  � |  � |
| D0 |  � |  � |  � |  � |  � |  � |  � |  � |  � |  � |  � |  � |  � |  � |  � |  � |
| E0 |  �E|  �E|  �E|  �E|  �E|  �E|  �E|  �E|  �E|  �E|  �E|  �E|  �E|  �E|  �E|  �E|
| F0 |  �E|  �E|  �E|  �E|  �E|  �E|  �E|  �E|  �E|  �E|  �E|  �E|  �E|  � |  � |  � |
--------------------------------------------------------------------------------------
(EXIT_SUCCESS)
*/