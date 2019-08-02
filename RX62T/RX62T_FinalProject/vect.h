/***********************************************************************/
/*                                                                     */
/*  FILE        :vect.h                                                */
/*  DATE        :Fri, May 31, 2013                                     */
/*  DESCRIPTION :Definition of Vector                                  */
/*  CPU TYPE    :RX62T                                                 */
/*                                                                     */
/*  This file is generated by Renesas Project Generator (Ver.4.51).    */
/*  NOTE:THIS IS A TYPICAL EXAMPLE.                                    */
/*                                                                     */
/***********************************************************************/
/************************************************************************
*
* Device     : RX/RX600/RX62T
*
* File Name  : vect.h
*
* Abstract   : Definition of Vector.
*
* History    : 1.00  (2010-06-08)  [Hardware Manual Revision : 0.20]
*
* NOTE       : THIS IS A TYPICAL EXAMPLE.
*
*  Copyright (C) 2010 Renesas Electronics Corporation and
*  Renesas Solutions Corp. All rights reserved.
*
************************************************************************/

// Exception(Supervisor Instruction)
#pragma interrupt (Excep_SuperVisorInst)
void Excep_SuperVisorInst(void);

// Exception(Undefined Instruction)
#pragma interrupt (Excep_UndefinedInst)
void Excep_UndefinedInst(void);

// Exception(Floating Point)
#pragma interrupt (Excep_FloatingPoint)
void Excep_FloatingPoint(void);

// NMI
#pragma interrupt (NonMaskableInterrupt)
void NonMaskableInterrupt(void);

// Dummy
#pragma interrupt (Dummy)
void Dummy(void);

// BRK
#pragma interrupt (Excep_BRK(vect=0))
void Excep_BRK(void);

// vector  1 reserved
// vector  2 reserved
// vector  3 reserved
// vector  4 reserved
// vector  5 reserved
// vector  6 reserved
// vector  7 reserved
// vector  8 reserved
// vector  9 reserved
// vector 10 reserved
// vector 11 reserved
// vector 12 reserved
// vector 13 reserved
// vector 14 reserved
// vector 15 reserved

// BUSERR
#pragma interrupt (Excep_BUSERR(vect=16))
void Excep_BUSERR(void);

// vector 17 reserved
// vector 18 reserved
// vector 19 reserved
// vector 20 reserved

// FCU_FCUERR
#pragma interrupt (Excep_FCUIF_FIFEERR(vect=21))
void Excep_FCUIF_FIFEERR(void);

// vector 22 reserved

// FCU_FRDYI
#pragma interrupt (Excep_FCUIF_FRDYI(vect=23))
void Excep_FCUIF_FRDYI(void);

// vector 24 reserved
// vector 25 reserved
// vector 26 reserved

// ICU SWINT
#pragma interrupt (Excep_ICU_SWINT(vect=27))
void Excep_ICU_SWINT(void);

// CMTU0_CMT0
#pragma interrupt (Excep_CMT0_CMI0(vect=28))
void Excep_CMT0_CMI0(void);

// CMTU0_CMT1
#pragma interrupt (Excep_CMT0_CMI1(vect=29))
void Excep_CMT0_CMI1(void);

// CMTU1_CMT2
#pragma interrupt (Excep_CMT1_CMI2(vect=30))
void Excep_CMT1_CMI2(void);

// CMTU1_CMT3
#pragma interrupt (Excep_CMT1_CMI3(vect=31))
void Excep_CMT1_CMI3(void);

// vector 32 reserved
// vector 33 reserved
// vector 34 reserved
// vector 35 reserved
// vector 36 reserved
// vector 37 reserved
// vector 38 reserved
// vector 39 reserved
// vector 40 reserved
// vector 41 reserved
// vector 42 reserved
// vector 43 reserved

// RSPI0 SPEI0
#pragma interrupt (Excep_RSPI0_SPEI0(vect=44))
void Excep_RSPI0_SPEI0(void);

// RSPI0 SPRI0
#pragma interrupt (Excep_RSPI0_SPRI0(vect=45))
void Excep_RSPI0_SPRI0(void);

// RSPI0 SPTI0
#pragma interrupt (Excep_RSPI0_SPTI0(vect=46))
void Excep_RSPI0_SPTI0(void);

// RSPI0 SPII0
#pragma interrupt (Excep_RSPI0_SPII0(vect=47))
void Excep_RSPI0_SPII0(void);

// vector 48 reserved
// vector 49 reserved
// vector 50 reserved
// vector 51 reserved
// vector 52 reserved
// vector 53 reserved
// vector 54 reserved
// vector 55 reserved

// CAN0 ERS0
#pragma interrupt (Excep_CAN0_ERS0(vect=56))
void Excep_CAN0_ERS0(void);

// CAN0 RXF0
#pragma interrupt (Excep_CAN0_RXF0(vect=57))
void Excep_CAN0_RXF0(void);

// CAN0 TXF0
#pragma interrupt (Excep_CAN0_TXF0(vect=58))
void Excep_CAN0_TXF0(void);

// CAN0 RXM0
#pragma interrupt (Excep_CAN0_RXM0(vect=59))
void Excep_CAN0_RXM0(void);

// CAN0 TXM0
#pragma interrupt (Excep_CAN0_TXM0(vect=60))
void Excep_CAN0_TXM0(void);

// vector 61 reserved
// vector 62 reserved
// vector 63 reserved

// IRQ0
#pragma interrupt (Excep_IRQ0(vect=64))
void Excep_IRQ0(void);

// IRQ1
#pragma interrupt (Excep_IRQ1(vect=65))
void Excep_IRQ1(void);

// IRQ2
#pragma interrupt (Excep_IRQ2(vect=66))
void Excep_IRQ2(void);

// IRQ3
#pragma interrupt (Excep_IRQ3(vect=67))
void Excep_IRQ3(void);

// IRQ4
#pragma interrupt (Excep_IRQ4(vect=68))
void Excep_IRQ4(void);

// IRQ5
#pragma interrupt (Excep_IRQ5(vect=69))
void Excep_IRQ5(void);

// IRQ6
#pragma interrupt (Excep_IRQ6(vect=70))
void Excep_IRQ6(void);

// IRQ7
#pragma interrupt (Excep_IRQ7(vect=71))
void Excep_IRQ7(void);

// vector 72 reserved
// vector 73 reserved
// vector 74 reserved
// vector 75 reserved
// vector 76 reserved
// vector 77 reserved
// vector 78 reserved
// vector 79 reserved
// vector 80 reserved
// vector 81 reserved
// vector 82 reserved
// vector 83 reserved
// vector 84 reserved
// vector 85 reserved
// vector 86 reserved
// vector 87 reserved
// vector 88 reserved
// vector 89 reserved
// vector 90 reserved
// vector 91 reserved
// vector 92 reserved
// vector 93 reserved
// vector 94 reserved
// vector 95 reserved

// WDT WOVI
#pragma interrupt (Excep_WDT_WOVI(vect=96))
void Excep_WDT_WOVI(void);

// vector 97 reserved

// ADA0 ADI0
#pragma interrupt (Excep_ADA0_ADI0(vect=98))
void Excep_ADA0_ADI0(void);

// vector 99 reserved
// vector 100 reserved
// vector 101 reserved

// S12ADA0 S12ADI0
#pragma interrupt (Excep_S12ADA0_S12ADI0(vect=102))
void Excep_S12ADA0_S12ADI0(void);

// S12ADA1 S12ADI1
#pragma interrupt (Excep_S12ADA1_S12ADI1(vect=103))
void Excep_S12ADA1_S12ADI1(void);

// vector 104 reserved
// vector 105 reserved

// CMP CMPI
#pragma interrupt (Excep_CMP_CMPI(vect=106))
void Excep_CMP_CMPI(void);

// vector 107 reserved
// vector 108 reserved
// vector 109 reserved
// vector 110 reserved
// vector 111 reserved
// vector 112 reserved
// vector 113 reserved

// MTU3_0 TGIA0
#pragma interrupt (Excep_MTU30_TGIA0(vect=114))
void Excep_MTU30_TGIA0(void);

// MTU3_0 TGIB0
#pragma interrupt (Excep_MTU30_TGIB0(vect=115))
void Excep_MTU30_TGIB0(void);

// MTU3_0 TGIC0
#pragma interrupt (Excep_MTU30_TGIC0(vect=116))
void Excep_MTU30_TGIC0(void);

// MTU3_0 TGID0
#pragma interrupt (Excep_MTU30_TGID0(vect=117))
void Excep_MTU30_TGID0(void);

// MTU3_0 TCIV0
#pragma interrupt (Excep_MTU30_TCIV0(vect=118))
void Excep_MTU30_TCIV0(void);

// MTU3_0 TGIE0
#pragma interrupt (Excep_MTU30_TGIE0(vect=119))
void Excep_MTU30_TGIE0(void);

// MTU3_0 TGIF0
#pragma interrupt (Excep_MTU30_TGIF0(vect=120))
void Excep_MTU30_TGIF0(void);

// MTU3_1 TGIA1
#pragma interrupt (Excep_MTU31_TGIA1(vect=121))
void Excep_MTU31_TGIA1(void);

// MTU3_1 TGIB1
#pragma interrupt (Excep_MTU31_TGIB1(vect=122))
void Excep_MTU31_TGIB1(void);

// MTU3_1 TCIV1
#pragma interrupt (Excep_MTU31_TCIV1(vect=123))
void Excep_MTU31_TCIV1(void);

// MTU3_1 TCIU1
#pragma interrupt (Excep_MTU31_TCIU1(vect=124))
void Excep_MTU31_TCIU1(void);

// MTU3_2 TGIA2
#pragma interrupt (Excep_MTU32_TGIA2(vect=125))
void Excep_MTU32_TGIA2(void);

// MTU3_2 TGIB2
#pragma interrupt (Excep_MTU32_TGIB2(vect=126))
void Excep_MTU32_TGIB2(void);

// MTU3_2 TCIV2
#pragma interrupt (Excep_MTU32_TCIV2(vect=127))
void Excep_MTU32_TCIV2(void);

// MTU3_2 TCIU2
#pragma interrupt (Excep_MTU32_TCIU2(vect=128))
void Excep_MTU32_TCIU2(void);

// MTU3_3 TGIA3
#pragma interrupt (Excep_MTU33_TGIA3(vect=129))
void Excep_MTU33_TGIA3(void);

// MTU3_3 TGIB3
#pragma interrupt (Excep_MTU33_TGIB3(vect=130))
void Excep_MTU33_TGIB3(void);

// MTU3_3 TGIC3
#pragma interrupt (Excep_MTU33_TGIC3(vect=131))
void Excep_MTU33_TGIC3(void);

// MTU3_3 TGID3
#pragma interrupt (Excep_MTU33_TGID3(vect=132))
void Excep_MTU33_TGID3(void);

// MTU3_3 TCIV3
#pragma interrupt (Excep_MTU33_TCIV3(vect=133))
void Excep_MTU33_TCIV3(void);

// MTU3_4 TGIA4
#pragma interrupt (Excep_MTU34_TGIA4(vect=134))
void Excep_MTU34_TGIA4(void);

// MTU3_4 TGIB4
#pragma interrupt (Excep_MTU34_TGIB4(vect=135))
void Excep_MTU34_TGIB4(void);

// MTU3_4 TGIC4
#pragma interrupt (Excep_MTU34_TGIC4(vect=136))
void Excep_MTU34_TGIC4(void);

// MTU3_4 TGID4
#pragma interrupt (Excep_MTU34_TGID4(vect=137))
void Excep_MTU34_TGID4(void);

// MTU3_4 TCIV4
#pragma interrupt (Excep_MTU34_TCIV4(vect=138))
void Excep_MTU34_TCIV4(void);

// MTU3_5 TCIU5
#pragma interrupt (Excep_MTU35_TCIU5(vect=139))
void Excep_MTU35_TCIU5(void);

// MTU3_5 TCIV5
#pragma interrupt (Excep_MTU35_TCIV5(vect=140))
void Excep_MTU35_TCIV5(void);

// MTU3_5 TCIW5
#pragma interrupt (Excep_MTU35_TCIW5(vect=141))
void Excep_MTU35_TCIW5(void);

// MTU3_6 TGIA6
#pragma interrupt (Excep_MTU36_TGIA6(vect=142))
void Excep_MTU36_TGIA6(void);

// MTU3_6 TGIB6
#pragma interrupt (Excep_MTU36_TGIB6(vect=143))
void Excep_MTU36_TGIB6(void);

// MTU3_6 TGIC6
#pragma interrupt (Excep_MTU36_TGIC6(vect=144))
void Excep_MTU36_TGIC6(void);

// MTU3_6 TGID6
#pragma interrupt (Excep_MTU36_TGID6(vect=145))
void Excep_MTU36_TGID6(void);

// MTU3_6 TCIV6
#pragma interrupt (Excep_MTU36_TCIV6(vect=146))
void Excep_MTU36_TCIV6(void);

// vector 147 reserved
// vector 148 reserved

// MTU3_7 TGIA7
#pragma interrupt (Excep_MTU37_TGIA7(vect=149))
void Excep_MTU37_TGIA7(void);

// MTU3_7 TGIB7
#pragma interrupt (Excep_MTU37_TGIB7(vect=150))
void Excep_MTU37_TGIB7(void);

// MTU3_7 TGIC7
#pragma interrupt (Excep_MTU37_TGIC7(vect=151))
void Excep_MTU37_TGIC7(void);

// MTU3_7 TGID7
#pragma interrupt (Excep_MTU37_TGID7(vect=152))
void Excep_MTU37_TGID7(void);

// MTU3_7 TCIV7
#pragma interrupt (Excep_MTU37_TCIV7(vect=153))
void Excep_MTU37_TCIV7(void);

// vector 154 reserved
// vector 155 reserved
// vector 156 reserved
// vector 157 reserved
// vector 158 reserved
// vector 159 reserved
// vector 160 reserved
// vector 161 reserved
// vector 162 reserved
// vector 163 reserved
// vector 164 reserved
// vector 165 reserved
// vector 166 reserved
// vector 167 reserved
// vector 168 reserved
// vector 169 reserved

// POE3 OE11
#pragma interrupt (Excep_POE3_OE11(vect=170))
void Excep_POE3_OE11(void);

// POE3 OE12
#pragma interrupt (Excep_POE3_OE12(vect=171))
void Excep_POE3_OE12(void);

// POE3 OE13
#pragma interrupt (Excep_POE3_OE13(vect=172))
void Excep_POE3_OE13(void);

// POE3 OE14
#pragma interrupt (Excep_POE3_OE14(vect=173))
void Excep_POE3_OE14(void);

// GPT0 GTCIA0
#pragma interrupt (Excep_GPT0_GTCIA0(vect=174))
void Excep_GPT0_GTCIA0(void);

// GPT0 GTCIB0
#pragma interrupt (Excep_GPT0_GTCIB0(vect=175))
void Excep_GPT0_GTCIB0(void);

// GPT0 GTCIC0
#pragma interrupt (Excep_GPT0_GTCIC0(vect=176))
void Excep_GPT0_GTCIC0(void);

// GPT0 GTCIE0
#pragma interrupt (Excep_GPT0_GTCIE0(vect=177))
void Excep_GPT0_GTCIE0(void);

// GPT0 GTCIV0
#pragma interrupt (Excep_GPT0_GTCIV0(vect=178))
void Excep_GPT0_GTCIV0(void);

// GPT0 LOCO1
#pragma interrupt (Excep_GPT0_LOCO1(vect=179))
void Excep_GPT0_LOCO1(void);

// GPT1 GTCIA1
#pragma interrupt (Excep_GPT1_GTCIA1(vect=180))
void Excep_GPT1_GTCIA1(void);

// GPT1 GTCIB1
#pragma interrupt (Excep_GPT1_GTCIB1(vect=181))
void Excep_GPT1_GTCIB1(void);

// GPT1 GTCIC1
#pragma interrupt (Excep_GPT1_GTCIC1(vect=182))
void Excep_GPT1_GTCIC1(void);

// GPT1 GTCIE1
#pragma interrupt (Excep_GPT1_GTCIE1(vect=183))
void Excep_GPT1_GTCIE1(void);

// GPT1 GTCIV1
#pragma interrupt (Excep_GPT1_GTCIV1(vect=184))
void Excep_GPT1_GTCIV1(void);

// vector 185 reserved

// GPT2 GTCIA2
#pragma interrupt (Excep_GPT2_GTCIA2(vect=186))
void Excep_GPT2_GTCIA2(void);

// GPT2 GTCIB2
#pragma interrupt (Excep_GPT2_GTCIB2(vect=187))
void Excep_GPT2_GTCIB2(void);

// GPT2 GTCIC2
#pragma interrupt (Excep_GPT2_GTCIC2(vect=188))
void Excep_GPT2_GTCIC2(void);

// GPT2 GTCIE2
#pragma interrupt (Excep_GPT2_GTCIE2(vect=189))
void Excep_GPT2_GTCIE2(void);

// GPT2 GTCIV2
#pragma interrupt (Excep_GPT2_GTCIV2(vect=190))
void Excep_GPT2_GTCIV2(void);

// vector 191 reserved

// GPT3 GTCIA3
#pragma interrupt (Excep_GPT3_GTCIA3(vect=192))
void Excep_GPT3_GTCIA3(void);

// GPT3 GTCIB3
#pragma interrupt (Excep_GPT3_GTCIB3(vect=193))
void Excep_GPT3_GTCIB3(void);

// GPT3 GTCIC3
#pragma interrupt (Excep_GPT3_GTCIC3(vect=194))
void Excep_GPT3_GTCIC3(void);

// GPT3 GTCIE3
#pragma interrupt (Excep_GPT3_GTCIE3(vect=195))
void Excep_GPT3_GTCIE3(void);

// GPT3 GTCIV3
#pragma interrupt (Excep_GPT3_GTCIV3(vect=196))
void Excep_GPT3_GTCIV3(void);

// vector 197 reserved
// vector 198 reserved
// vector 199 reserved
// vector 200 reserved
// vector 201 reserved
// vector 202 reserved
// vector 203 reserved
// vector 204 reserved
// vector 205 reserved
// vector 206 reserved
// vector 207 reserved
// vector 208 reserved
// vector 209 reserved
// vector 210 reserved
// vector 211 reserved
// vector 212 reserved
// vector 213 reserved

// SCI0_ERI0
#pragma interrupt (Excep_SCI0_ERI0(vect=214))
void Excep_SCI0_ERI0(void);

// SCI0_RXI0
#pragma interrupt (Excep_SCI0_RXI0(vect=215))
void Excep_SCI0_RXI0(void);

// SCI0_TXI0
#pragma interrupt (Excep_SCI0_TXI0(vect=216))
void Excep_SCI0_TXI0(void);

// SCI0_TEI0
#pragma interrupt (Excep_SCI0_TEI0(vect=217))
void Excep_SCI0_TEI0(void);

// SCI1_ERI1
#pragma interrupt (Excep_SCI1_ERI1(vect=218))
void Excep_SCI1_ERI1(void);

// SCI1_RXI1
#pragma interrupt (Excep_SCI1_RXI1(vect=219))
void Excep_SCI1_RXI1(void);

// SCI1_TXI1
#pragma interrupt (Excep_SCI1_TXI1(vect=220))
void Excep_SCI1_TXI1(void);

// SCI1_TEI1
#pragma interrupt (Excep_SCI1_TEI1(vect=221))
void Excep_SCI1_TEI1(void);

// SCI2_ERI2
#pragma interrupt (Excep_SCI2_ERI2(vect=222))
void Excep_SCI2_ERI2(void);

// SCI2_RXI2
#pragma interrupt (Excep_SCI2_RXI2(vect=223))
void Excep_SCI2_RXI2(void);

// SCI2_TXI2
#pragma interrupt (Excep_SCI2_TXI2(vect=224))
void Excep_SCI2_TXI2(void);

// SCI2_TEI2
#pragma interrupt (Excep_SCI2_TEI2(vect=225))
void Excep_SCI2_TEI2(void);

// vector 226 reserved
// vector 227 reserved
// vector 228 reserved
// vector 229 reserved
// vector 230 reserved
// vector 231 reserved
// vector 232 reserved
// vector 233 reserved
// vector 234 reserved
// vector 235 reserved
// vector 236 reserved
// vector 237 reserved
// vector 238 reserved
// vector 239 reserved
// vector 240 reserved
// vector 241 reserved
// vector 242 reserved
// vector 243 reserved
// vector 244 reserved
// vector 245 reserved

// RIIC0 ICEEI0
#pragma interrupt (Excep_RIIC0_ICEEI0(vect=246))
void Excep_RIIC0_ICEEI0(void);

// RIIC0 ICRXI0
#pragma interrupt (Excep_RIIC0_ICRXI0(vect=247))
void Excep_RIIC0_ICRXI0(void);

// RIIC0 ICTXI0
#pragma interrupt (Excep_RIIC0_ICTXI0(vect=248))
void Excep_RIIC0_ICTXI0(void);

// RIIC0 ICTEI0
#pragma interrupt (Excep_RIIC0_ICTEI0(vect=249))
void Excep_RIIC0_ICTEI0(void);

// vector 250 reserved
// vector 251 reserved
// vector 252 reserved
// vector 253 reserved

// LIN0 LIN0
#pragma interrupt (Excep_LIN0_LIN0(vect=254))
void Excep_LIN0_LIN0(void);

// vector 255 reserved

//;<<VECTOR DATA START (POWER ON RESET)>>
//;Power On Reset PC
extern void PowerON_Reset_PC(void);                                                                                                                
//;<<VECTOR DATA END (POWER ON RESET)>>

