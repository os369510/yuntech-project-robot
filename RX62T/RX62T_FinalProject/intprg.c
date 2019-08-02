/***********************************************************************/
/*                                                                     */
/*  FILE        :intprg.c                                              */
/*  DATE        :Fri, May 31, 2013                                     */
/*  DESCRIPTION :Interrupt Program                                     */
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
* File Name  : intprg.c
*
* Abstract   : Interrupt Program.
*
* History    : 1.00  (2010-06-08)  [Hardware Manual Revision : 0.20]
*
* NOTE       : THIS IS A TYPICAL EXAMPLE.
*
*  Copyright (C) 2010 Renesas Electronics Corporation and
*  Renesas Solutions Corp. All rights reserved.
*
************************************************************************/

#include <machine.h>
#include "vect.h"
#pragma section IntPRG

// Exception(Supervisor Instruction)
void Excep_SuperVisorInst(void){/* brk(); */}

// Exception(Undefined Instruction)
void Excep_UndefinedInst(void){/* brk(); */}

// Exception(Floating Point)
void Excep_FloatingPoint(void){/* brk(); */}

// NMI
void NonMaskableInterrupt(void){/* brk(); */}

// Dummy
void Dummy(void){/* brk(); */}

// BRK
void Excep_BRK(void){ wait(); }

// BUSERR
void Excep_BUSERR(void){ }

// FCU FCUERR
void Excep_FCUIF_FIFEERR(void){ }

// FCU FRDYI
void Excep_FCUIF_FRDYI(void){ }

// ICU SWINT
void Excep_ICU_SWINT(void){ }

// CMT0 CMI0
void Excep_CMT0_CMI0(void){ }

// CMT0 CMI1
void Excep_CMT0_CMI1(void){ }

// CMT1 CMI2
void Excep_CMT1_CMI2(void){ }

// CMT1 CMI3
void Excep_CMT1_CMI3(void){ }

// RSPI0 SPEI0
void Excep_RSPI0_SPEI0(void){ }

// RSPI0 SPRI0
void Excep_RSPI0_SPRI0(void){ }

// RSPI0 SPTI0
void Excep_RSPI0_SPTI0(void){ }

// RSPI0 SPII0
void Excep_RSPI0_SPII0(void){ }

// CAN0 ERS0
void Excep_CAN0_ERS0(void){ }

// CAN0 RXF0
void Excep_CAN0_RXF0(void){ }

// CAN0 TXF0
void Excep_CAN0_TXF0(void){ }

// CAN0 RXM0
void Excep_CAN0_RXM0(void){ }

// CAN0 TXM0
void Excep_CAN0_TXM0(void){ }

// IRQ0
void Excep_IRQ0(void){ }

// IRQ1
void Excep_IRQ1(void){ }

// IRQ2
void Excep_IRQ2(void){ }

// IRQ3
void Excep_IRQ3(void){ }

// IRQ4
void Excep_IRQ4(void){ }

// IRQ5
void Excep_IRQ5(void){ }

// IRQ6
void Excep_IRQ6(void){ }

// IRQ7
void Excep_IRQ7(void){ }

// WDT WOVI
void Excep_WDT_WOVI(void){ }

// ADA0 ADI0
void Excep_ADA0_ADI0(void){ }

// S12ADA0 S12ADI0
void Excep_S12ADA0_S12ADI0(void){ }

// S12ADA1 S12ADI1
void Excep_S12ADA1_S12ADI1(void){ }

// CMP CMPI
void Excep_CMP_CMPI(void){ }

// MTU3_0 TGIA0
void Excep_MTU30_TGIA0(void){ }

// MTU3_0 TGIB0
void Excep_MTU30_TGIB0(void){ }

// MTU3_0 TGIC0
void Excep_MTU30_TGIC0(void){ }

// MTU3_0 TGID0
void Excep_MTU30_TGID0(void){ }

// MTU3_0 TCIV0
void Excep_MTU30_TCIV0(void){ }

// MTU3_0 TGIE0
void Excep_MTU30_TGIE0(void){ }

// MTU3_0 TGIF0
void Excep_MTU30_TGIF0(void){ }

// MTU3_1 TGIA1
void Excep_MTU31_TGIA1(void){ }

// MTU3_1 TGIB1
void Excep_MTU31_TGIB1(void){ }

// MTU3_1 TCIV1
void Excep_MTU31_TCIV1(void){ }

// MTU3_1 TCIU1
void Excep_MTU31_TCIU1(void){ }

// MTU3_2 TGIA2
void Excep_MTU32_TGIA2(void){ }

// MTU3_2 TGIB2
void Excep_MTU32_TGIB2(void){ }

// MTU3_2 TCIV2
void Excep_MTU32_TCIV2(void){ }

// MTU3_2 TCIU2
void Excep_MTU32_TCIU2(void){ }

// MTU3_3 TGIA3
void Excep_MTU33_TGIA3(void){ }

// MTU3_3 TGIB3
void Excep_MTU33_TGIB3(void){ }

// MTU3_3 TGIC3
void Excep_MTU33_TGIC3(void){ }

// MTU3_3 TGID3
void Excep_MTU33_TGID3(void){ }

// MTU3_3 TCIV3
void Excep_MTU33_TCIV3(void){ }

// MTU3_4 TGIA4
void Excep_MTU34_TGIA4(void){ }

// MTU3_4 TGIB4
void Excep_MTU34_TGIB4(void){ }

// MTU3_4 TGIC4
void Excep_MTU34_TGIC4(void){ }

// MTU3_4 TGID4
void Excep_MTU34_TGID4(void){ }

// MTU3_4 TCIV4
void Excep_MTU34_TCIV4(void){ }

// MTU3_5 TCIU5
void Excep_MTU35_TCIU5(void){ }

// MTU3_5 TCIV5
void Excep_MTU35_TCIV5(void){ }

// MTU3_5 TCIW5
void Excep_MTU35_TCIW5(void){ }

// MTU3_6 TGIA6
void Excep_MTU36_TGIA6(void){ }

// MTU3_6 TGIB6
void Excep_MTU36_TGIB6(void){ }

// MTU3_6 TGIC6
void Excep_MTU36_TGIC6(void){ }

// MTU3_6 TGID6
void Excep_MTU36_TGID6(void){ }

// MTU3_6 TCIV6
void Excep_MTU36_TCIV6(void){ }

// MTU3_7 TGIA7
void Excep_MTU37_TGIA7(void){ }

// MTU3_7 TGIB7
void Excep_MTU37_TGIB7(void){ }

// MTU3_7 TGIC7
void Excep_MTU37_TGIC7(void){ }

// MTU3_7 TGID7
void Excep_MTU37_TGID7(void){ }

// MTU3_7 TCIV7
void Excep_MTU37_TCIV7(void){ }

// POE3 OE11
void Excep_POE3_OE11(void){ }

// POE3 OE12
void Excep_POE3_OE12(void){ }

// POE3 OE13
void Excep_POE3_OE13(void){ }

// POE3 OE14
void Excep_POE3_OE14(void){ }

// GPT0 GTCIA0
void Excep_GPT0_GTCIA0(void){ }

// GPT0 GTCIB0
void Excep_GPT0_GTCIB0(void){ }

// GPT0 GTCIC0
void Excep_GPT0_GTCIC0(void){ }

// GPT0 GTCIE0
void Excep_GPT0_GTCIE0(void){ }

// GPT0 GTCIV0
void Excep_GPT0_GTCIV0(void){ }

// GPT0 LOCO1
void Excep_GPT0_LOCO1(void){ }

// GPT1 GTCIA1
void Excep_GPT1_GTCIA1(void){ }

// GPT1 GTCIB1
void Excep_GPT1_GTCIB1(void){ }

// GPT1 GTCIC1
void Excep_GPT1_GTCIC1(void){ }

// GPT1 GTCIE1
void Excep_GPT1_GTCIE1(void){ }

// GPT1 GTCIV1
void Excep_GPT1_GTCIV1(void){ }

// GPT2 GTCIA2
void Excep_GPT2_GTCIA2(void){ }

// GPT2 GTCIB2
void Excep_GPT2_GTCIB2(void){ }

// GPT2 GTCIC2
void Excep_GPT2_GTCIC2(void){ }

// GPT2 GTCIE2
void Excep_GPT2_GTCIE2(void){ }

// GPT2 GTCIV2
void Excep_GPT2_GTCIV2(void){ }

// GPT3 GTCIA3
void Excep_GPT3_GTCIA3(void){ }

// GPT3 GTCIB3
void Excep_GPT3_GTCIB3(void){ }

// GPT3 GTCIC3
void Excep_GPT3_GTCIC3(void){ }

// GPT3 GTCIE3
void Excep_GPT3_GTCIE3(void){ }

// GPT3 GTCIV3
void Excep_GPT3_GTCIV3(void){ }

// SCI0 ERI0
void Excep_SCI0_ERI0(void){ }

// SCI0 RXI0
void Excep_SCI0_RXI0(void){ }

// SCI0 TXI0
void Excep_SCI0_TXI0(void){ }

// SCI0 TEI0
void Excep_SCI0_TEI0(void){ }

// SCI1 ERI1
void Excep_SCI1_ERI1(void){ }

// SCI1 RXI1
void Excep_SCI1_RXI1(void){ }

// SCI1 TXI1
void Excep_SCI1_TXI1(void){ }

// SCI1 TEI1
void Excep_SCI1_TEI1(void){ }

// SCI2 ERI2
void Excep_SCI2_ERI2(void){ }

// SCI2 RXI2
void Excep_SCI2_RXI2(void){ }

// SCI2 TXI2
void Excep_SCI2_TXI2(void){ }

// SCI2 TEI2
void Excep_SCI2_TEI2(void){ }

// RIIC0 ICEEI0
void Excep_RIIC0_ICEEI0(void){ }

// RIIC0 ICRXI0
void Excep_RIIC0_ICRXI0(void){ }

// RIIC0 ICTXI0
void Excep_RIIC0_ICTXI0(void){ }

// RIIC0 ICTEI0
void Excep_RIIC0_ICTEI0(void){ }

// LIN0 LIN0
void Excep_LIN0_LIN0(void){ }

