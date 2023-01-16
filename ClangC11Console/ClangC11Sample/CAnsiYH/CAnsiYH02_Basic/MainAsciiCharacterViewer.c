/**
*@directory ClangC11Console / ClanC11Sample / CAnsiYH / CAnsiYH02_Basic
*@fileName  MainAsciiCharacterViewer.c
*@reference C99YH    åãèÈ ç_ ÅwCåæåÍÉvÉçÉOÉâÉ~ÉìÉOÉåÉbÉXÉì [ì¸ñÂï“] ëÊÇRî≈ÅxSB Creative, 2019
*@reference CAnsiYH  åãèÈ ç_ ÅwCåæåÍÉvÉçÉOÉâÉ~ÉìÉOÉåÉbÉXÉì [ï∂ñ@ï“] êVî≈Åx  SB Creative, 2006
*@reference C11DS    arton  Åwì∆èK C êVî≈Åx„ƒâjé–, 2018
*
*@content CAnsiYH Chapter 2  Basic | ASCII Character / List 2-0 / p13
*@summary MainAsciiCharacterViewer.c
*@English
*@subject ASCII Code ChartÅkC99YH 0AÅl
*         I drew it as similar below.
*         It is opposite Horizontal and Vertical Axis to Chart ofÅkC99YH 0AÅl
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
*@subject ÅüCharacter Code
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
*@Note   ÅyConsiderationÅz
*         I expected output of alphabet, numeric, symbol character only, as ASCII Code ChartÅkC99YH 0AÅl.
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

[80] (128) Ä
[81] (129) ÅE
[82] (130) ÅE
[83] (131) ÅE
[84] (132) ÅE
[85] (133) ÅE
[86] (134) ÅE
[87] (135) ÅE
[88] (136) ÅE
[89] (137) ÅE
[8A] (138) ÅE
[8B] (139) ÅE
[8C] (140) ÅE
[8D] (141) ÅE
[8E] (142) ÅE
[8F] (143) ÅE
[90] (144) ÅE
[91] (145) ÅE
[92] (146) ÅE
[93] (147) ÅE
[94] (148) ÅE
[95] (149) ÅE
[96] (150) ÅE
[97] (151) ÅE
[98] (152) ÅE
[99] (153) ÅE
[9A] (154) ÅE
[9B] (155) ÅE
[9C] (156) ÅE
[9D] (157) ÅE
[9E] (158) ÅE
[9F] (159) ÅE
[A0] (160) †
[A1] (161) °
[A2] (162) ¢
[A3] (163) £
[A4] (164) §
[A5] (165) •
[A6] (166) ¶
[A7] (167) ß
[A8] (168) ®
[A9] (169) ©
[AA] (170) ™
[AB] (171) ´
[AC] (172) ¨
[AD] (173) ≠
[AE] (174) Æ
[AF] (175) Ø
[B0] (176) ∞
[B1] (177) ±
[B2] (178) ≤
[B3] (179) ≥
[B4] (180) ¥
[B5] (181) µ
[B6] (182) ∂
[B7] (183) ∑
[B8] (184) ∏
[B9] (185) π
[BA] (186) ∫
[BB] (187) ª
[BC] (188) º
[BD] (189) Ω
[BE] (190) æ
[BF] (191) ø
[C0] (192) ¿
[C1] (193) ¡
[C2] (194) ¬
[C3] (195) √
[C4] (196) ƒ
[C5] (197) ≈
[C6] (198) ∆
[C7] (199) «
[C8] (200) »
[C9] (201) …
[CA] (202)  
[CB] (203) À
[CC] (204) Ã
[CD] (205) Õ
[CE] (206) Œ
[CF] (207) œ
[D0] (208) –
[D1] (209) —
[D2] (210) “
[D3] (211) ”
[D4] (212) ‘
[D5] (213) ’
[D6] (214) ÷
[D7] (215) ◊
[D8] (216) ÿ
[D9] (217) Ÿ
[DA] (218) ⁄
[DB] (219) €
[DC] (220) ‹
[DD] (221) ›
[DE] (222) ﬁ
[DF] (223) ﬂ
[E0] (224) ÅE
[E1] (225) ÅE
[E2] (226) ÅE
[E3] (227) ÅE
[E4] (228) ÅE
[E5] (229) ÅE
[E6] (230) ÅE
[E7] (231) ÅE
[E8] (232) ÅE
[E9] (233) ÅE
[EA] (234) ÅE
[EB] (235) ÅE
[EC] (236) ÅE
[ED] (237) ÅE
[EE] (238) ÅE
[EF] (239) ÅE
[F0] (240) ÅE
[F1] (241) ÅE
[F2] (242) ÅE
[F3] (243) ÅE
[F4] (244) ÅE
[F5] (245) ÅE
[F6] (246) ÅE
[F7] (247) ÅE
[F8] (248) ÅE
[F9] (249) ÅE
[FA] (250) ÅE
[FB] (251) ÅE
[FC] (252) ÅE
[FD] (253) ˝
[FE] (254) ˛
[FF] (255) ˇ

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
| 80 |  Ä |  ÅE|  ÅE|  ÅE|  ÅE|  ÅE|  ÅE|  ÅE|  ÅE|  ÅE|  ÅE|  ÅE|  ÅE|  ÅE|  ÅE|  ÅE|
| 90 |  ÅE|  ÅE|  ÅE|  ÅE|  ÅE|  ÅE|  ÅE|  ÅE|  ÅE|  ÅE|  ÅE|  ÅE|  ÅE|  ÅE|  ÅE|  ÅE|
| A0 |  † |  ° |  ¢ |  £ |  § |  • |  ¶ |  ß |  ® |  © |  ™ |  ´ |  ¨ |  ≠ |  Æ |  Ø |
| B0 |  ∞ |  ± |  ≤ |  ≥ |  ¥ |  µ |  ∂ |  ∑ |  ∏ |  π |  ∫ |  ª |  º |  Ω |  æ |  ø |
| C0 |  ¿ |  ¡ |  ¬ |  √ |  ƒ |  ≈ |  ∆ |  « |  » |  … |    |  À |  Ã |  Õ |  Œ |  œ |
| D0 |  – |  — |  “ |  ” |  ‘ |  ’ |  ÷ |  ◊ |  ÿ |  Ÿ |  ⁄ |  € |  ‹ |  › |  ﬁ |  ﬂ |
| E0 |  ÅE|  ÅE|  ÅE|  ÅE|  ÅE|  ÅE|  ÅE|  ÅE|  ÅE|  ÅE|  ÅE|  ÅE|  ÅE|  ÅE|  ÅE|  ÅE|
| F0 |  ÅE|  ÅE|  ÅE|  ÅE|  ÅE|  ÅE|  ÅE|  ÅE|  ÅE|  ÅE|  ÅE|  ÅE|  ÅE|  ˝ |  ˛ |  ˇ |
--------------------------------------------------------------------------------------
(EXIT_SUCCESS)
*/