/**
*【Notation】It is changed Character-Code only here. I don't know why.
*            => see the Edited Version〔Reference_CAnsiBasic.txt〕
* 
*@directory ClangC11Console / ClanC11Sample / CAnsiYH / CAnsiYH02_Basic
*@fileName  MainAsciiCharacterViewer.c
*@reference C99YH    結城 浩 『C言語プログラミングレッスン [入門編] 第３版』SB Creative, 2019
*@reference CAnsiYH  結城 浩 『C言語プログラミングレッスン [文法編] 新版』  SB Creative, 2006
*@reference C11DS    arton  『独習 C 新版』翔泳社, 2018
*@reference ■ 電脳産物 (= Electlic Brain Product) by dennou-san
*           ◆C言語：ASCIIコード表（C language: ASCII Code Chart）
*           https://dianxnao.com/c%e8%a8%80%e8%aa%9e%ef%bc%9aascii%e3%82%b3%e3%83%bc%e3%83%89%e8%a1%a8/
*           => 〔ReferenceDocument\Article_AsciiCode_Clanguage.txt〕
* 
*@content CAnsiYH Chapter 2  Basic | ASCII Character / List 2-0 / p13
*@summary MainAsciiCharacterViewer.c
*@English
*@subject ◆ASCII Code Chart〔C99YH 0A | p435〕〔MainAsciiCharacterViewer.c〕
*         I drew it as similar, below.
*         It is opposite Horizontal and Vertical Axis to Chart of〔C99YH 0A〕
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
*@subject ◆Character Code 〔C99YH p266〕
*         It is defined corresponding Binary which is recognizable for Machine, to Character which is recognizable for Human.
*         There are some kinds of Character Code as below.
* 
*         ASCII: Character code default-defined by the specification of C language,
*                depending on Compiler.
* 
*         UTF-8: (Unicode):
*                Character code of most popular in the world,
*                which almost supports main languages;
*                including ASCII, 2 Bytes character (= wide character), Japanese, Arabic, Hebrew, Greek, or Kiril etc...
* 
*         ECU:   (Latin1): 
*                Character code for UNIX: alphabet, numeric, symbol charater only, 
*                but including pronounce-characters and accent-characters of European languages, Euro currency mark too.
*                Probably, Git-Hub automatically may judge Character-Code as ECU. 
*                It might change Non-Characters and Japanese to [?].
*                Visual Studio (UTF-8) shows correctly.
* 
*         Shift-JIS: (windows-31J, CP932):
*                Character code for Japanese, as Windows default in Japan.
*
*@Note   【Consideration】
*         I expected output of alphabet, numeric, symbol character only, as ASCII Code Chart〔C99YH 0A〕.
*         But VS C11 Compiler might probably define them, 
*         there are some gridlines, picture character (as like emoji), 2 Bytes character (= wide character), Control, Japanese Kana character as addition to above.
*         
*         In Chart case, Non-Characters don't show as well, so I replaced them to white-space.
*
*@copyTo  Reference_CAnsiBasic.txt
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

        //Replace Non-Characters to white-space
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
〔C99YH 0A | p435〕〔ReferenceDocument\Article_AsciiCode_Clanguage.txt〕
[00] (  0)     // NUL: NULL Character '\0'
[01] (  1)    // SOH: Start of Header
[02] (  2)    // STX: Start of Text
[03] (  3)    // ETX: End of Text
[04] (  4)    // EOT: End of Transfer
[05] (  5)    // ENQ: End of Quote (= Reference from others)
[06] (  6)    // ACK: Accept OK
[07] (  7)     // BEL: Bell (= Beep)  '\a'
[08] (  8)     // BS:  Back Space     '\b'
[09] (  9)     // HT:  Horizontal Tab '\t'
[0A] ( 10)     // LF:  Line Feed      '\n' (new line)
[0B] ( 11)    // VT:  Vertical Tab   '\v'
[0C] ( 12)    // FF:  Form Feed      '\f' (new page)
[0D] ( 13)     // CR:  Carrige Return '\r' (return left)
[0E] ( 14)    // SO:  Shift out
[0F] ( 15)    // SI:  Shift in
[10] ( 16)    // DLE: Data Link Escape
[11] ( 17)    // DC1: Device Control 1
[12] ( 18)    // DC2: Device Control 2
[13] ( 19)    // DC3: Device Control 3
[14] ( 20)    // DC4: Device Control 4
[15] ( 21)    // NAK: NG Accept (= Failure of Accept)
[16] ( 22)    // SYN: Synchronize
[17] ( 23)    // ETB: End of Transfer Block
[18] ( 24)    // CAN: Cancel
[19] ( 25)    // EM:  End of Media
[1A] ( 26)     // SUB: Substitute
                  somewhy, the one charater as like '->' (actually not two) maybe behave as 'EOF' ?
                  If it is existed, VS throw Compile Error, because "Not closed comment-out yet". 
                  So I deleted it, in temporary for another Compile.
[1B] ( 27)     // ESC: Escape Character  '\' (UNIX) or '¥' (Windows)
 ] ( 28)      // FS:  Form Separetor (= Delimiter)
                  somewhy, broken value, expected [1C] of printf("%02x", c).
[1D] ( 29)    // GS:  Group Separetor (= Delimiter)
[1E] ( 30)    // RS:  Record Separetor (= Delimiter)
[1F] ( 31)    // US:  Unit Separetor (= Delimiter)
[20] ( 32)     // SP:  white-space
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

[80] (128) 
[81] (129) ・
[82] (130) ・
[83] (131) ・
[84] (132) ・
[85] (133) ・
[86] (134) ・
[87] (135) ・
[88] (136) ・
[89] (137) ・
[8A] (138) ・
[8B] (139) ・
[8C] (140) ・
[8D] (141) ・
[8E] (142) ・
[8F] (143) ・
[90] (144) ・
[91] (145) ・
[92] (146) ・
[93] (147) ・
[94] (148) ・
[95] (149) ・
[96] (150) ・
[97] (151) ・
[98] (152) ・
[99] (153) ・
[9A] (154) ・
[9B] (155) ・
[9C] (156) ・
[9D] (157) ・
[9E] (158) ・
[9F] (159) ・
[A0] (160) 
[A1] (161) ｡
[A2] (162) ｢
[A3] (163) ｣
[A4] (164) ､
[A5] (165) ･
[A6] (166) ｦ
[A7] (167) ｧ
[A8] (168) ｨ
[A9] (169) ｩ
[AA] (170) ｪ
[AB] (171) ｫ
[AC] (172) ｬ
[AD] (173) ｭ
[AE] (174) ｮ
[AF] (175) ｯ
[B0] (176) ｰ
[B1] (177) ｱ
[B2] (178) ｲ
[B3] (179) ｳ
[B4] (180) ｴ
[B5] (181) ｵ
[B6] (182) ｶ
[B7] (183) ｷ
[B8] (184) ｸ
[B9] (185) ｹ
[BA] (186) ｺ
[BB] (187) ｻ
[BC] (188) ｼ
[BD] (189) ｽ
[BE] (190) ｾ
[BF] (191) ｿ
[C0] (192) ﾀ
[C1] (193) ﾁ
[C2] (194) ﾂ
[C3] (195) ﾃ
[C4] (196) ﾄ
[C5] (197) ﾅ
[C6] (198) ﾆ
[C7] (199) ﾇ
[C8] (200) ﾈ
[C9] (201) ﾉ
[CA] (202) ﾊ
[CB] (203) ﾋ
[CC] (204) ﾌ
[CD] (205) ﾍ
[CE] (206) ﾎ
[CF] (207) ﾏ
[D0] (208) ﾐ
[D1] (209) ﾑ
[D2] (210) ﾒ
[D3] (211) ﾓ
[D4] (212) ﾔ
[D5] (213) ﾕ
[D6] (214) ﾖ
[D7] (215) ﾗ
[D8] (216) ﾘ
[D9] (217) ﾙ
[DA] (218) ﾚ
[DB] (219) ﾛ
[DC] (220) ﾜ
[DD] (221) ﾝ
[DE] (222) ﾞ
[DF] (223) ﾟ
[E0] (224) ・
[E1] (225) ・
[E2] (226) ・
[E3] (227) ・
[E4] (228) ・
[E5] (229) ・
[E6] (230) ・
[E7] (231) ・
[E8] (232) ・
[E9] (233) ・
[EA] (234) ・
[EB] (235) ・
[EC] (236) ・
[ED] (237) ・
[EE] (238) ・
[EF] (239) ・
[F0] (240) ・
[F1] (241) ・
[F2] (242) ・
[F3] (243) ・
[F4] (244) ・
[F5] (245) ・
[F6] (246) ・
[F7] (247) ・
[F8] (248) ・
[F9] (249) ・
[FA] (250) ・
[FB] (251) ・
[FC] (252) ・
[FD] (253) 
[FE] (254) 
[FF] (255) 

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
| 80 |   |  ・|  ・|  ・|  ・|  ・|  ・|  ・|  ・|  ・|  ・|  ・|  ・|  ・|  ・|  ・|
| 90 |  ・|  ・|  ・|  ・|  ・|  ・|  ・|  ・|  ・|  ・|  ・|  ・|  ・|  ・|  ・|  ・|
| A0 |   |  ｡ |  ｢ |  ｣ |  ､ |  ･ |  ｦ |  ｧ |  ｨ |  ｩ |  ｪ |  ｫ |  ｬ |  ｭ |  ｮ |  ｯ |
| B0 |  ｰ |  ｱ |  ｲ |  ｳ |  ｴ |  ｵ |  ｶ |  ｷ |  ｸ |  ｹ |  ｺ |  ｻ |  ｼ |  ｽ |  ｾ |  ｿ |
| C0 |  ﾀ |  ﾁ |  ﾂ |  ﾃ |  ﾄ |  ﾅ |  ﾆ |  ﾇ |  ﾈ |  ﾉ |  ﾊ |  ﾋ |  ﾌ |  ﾍ |  ﾎ |  ﾏ |
| D0 |  ﾐ |  ﾑ |  ﾒ |  ﾓ |  ﾔ |  ﾕ |  ﾖ |  ﾗ |  ﾘ |  ﾙ |  ﾚ |  ﾛ |  ﾜ |  ﾝ |  ﾞ |  ﾟ |
| E0 |  ・|  ・|  ・|  ・|  ・|  ・|  ・|  ・|  ・|  ・|  ・|  ・|  ・|  ・|  ・|  ・|
| F0 |  ・|  ・|  ・|  ・|  ・|  ・|  ・|  ・|  ・|  ・|  ・|  ・|  ・|   |   |   |
--------------------------------------------------------------------------------------
(EXIT_SUCCESS)
*/