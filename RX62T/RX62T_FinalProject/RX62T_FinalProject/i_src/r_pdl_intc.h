/*""FILE COMMENT""*******************************************************
* System Name	: External interrupt API for RX62T
* File Name		: r_pdl_intc.h
* Version		: 1.01
* Contents		: External interrupt API header
* Customer		:
* Model			:
* Order			:
* CPU			: RX
* Compiler		: RXC
* OS			:
* Programmer	:
* Note			:
************************************************************************
* Copyright, 2011. Renesas Electronics Corporation
* and Renesas Solutions Corporation
************************************************************************
* History		: 2011.05.04
*				: Ver 1.01
*				: Release CS3.
*""FILE COMMENT END""**************************************************/

#ifndef R_PDL_INTC_H
#define R_PDL_INTC_H

#include "r_pdl_common_defs_RX62Txx.h"

/* Function prototypes */
bool R_INTC_CreateExtInterrupt(
	uint8_t,
	uint16_t,
	void *,
	uint8_t
);
bool R_INTC_CreateSoftwareInterrupt(
	uint8_t,
	void *,
	uint8_t
);
bool R_INTC_CreateFastInterrupt(
	uint8_t
);
bool R_INTC_CreateExceptionHandlers(
	void *,
	void *,
	void *
);
bool R_INTC_ControlExtInterrupt(
	uint8_t,
	uint16_t
);
bool R_INTC_GetExtInterruptStatus(
	uint8_t,
	uint8_t *
);
bool R_INTC_Read(
	uint16_t,
	uint8_t *
);
bool R_INTC_Write(
	uint16_t,
	uint8_t
);
bool R_INTC_Modify(
	uint16_t,
	uint8_t,
	uint8_t
);

/* Interrupt pins */
#define PDL_INTC_IRQ0			0
#define PDL_INTC_IRQ1			1
#define PDL_INTC_IRQ2			2
#define PDL_INTC_IRQ3			3
#define PDL_INTC_IRQ4			4
#define PDL_INTC_IRQ5			5
#define PDL_INTC_IRQ6			6
#define PDL_INTC_IRQ7			7
#define PDL_INTC_PRIVILEGED		8
#define PDL_INTC_UNDEFINED		9
#define PDL_INTC_FLOATING_POINT 10
#define PDL_INTC_NMI			11
#define PDL_INTC_SWINT			12

/* Detection sense selection */
#define PDL_INTC_LOW					0x0001u
#define PDL_INTC_FALLING				0x0002u
#define PDL_INTC_RISING					0x0004u
#define PDL_INTC_BOTH					0x0008u

/* IRQ alternate pin selection */
#define PDL_INTC_A						0x0010u
#define PDL_INTC_B						0x0020u
#define PDL_INTC_C						0x0040u

/* DTC trigger control */
#define PDL_INTC_DTC_TRIGGER_DISABLE	0x0080u
#define PDL_INTC_DTC_TRIGGER_ENABLE		0x0100u

/* LVD detection control */
#define PDL_INTC_LVD_DISABLE			0x0200u
#define PDL_INTC_LVD_ENABLE				0x0400u

/* Oscillation stop detection control */
#define PDL_INTC_OSD_DISABLE			0x0800u
#define PDL_INTC_OSD_ENABLE				0x1000u

/* Interrupt control */
#define PDL_INTC_ENABLE					0x0200u
#define PDL_INTC_DISABLE				0x0400u

/* Flag control */
#define PDL_INTC_CLEAR_IR_FLAG			0x0800u
#define PDL_INTC_CLEAR_OSD_FLAG			0x1000u

/* DTC software trigger control */
#define PDL_INTC_DTC_SW_TRIGGER_DISABLE	0x01u
#define PDL_INTC_DTC_SW_TRIGGER_ENABLE	0x02u

/* Interrupt registers */
#define PDL_INTC_REG_IPL	0x0100u
#define PDL_INTC_REG_IR		0x0200u
#define PDL_INTC_REG_IER	0x0400u
#define PDL_INTC_REG_IPR	0x0800u
#define PDL_INTC_REG_DTCER	0x1000u
#define PDL_INTC_REG_SWINTR	0x2000u

/* Logical operations */
#define PDL_INTC_AND	0x01u
#define PDL_INTC_OR		0x02u
#define PDL_INTC_XOR	0x04u

/* IR registers */
#define PDL_INTC_REG_IR_BSC_BUSERR		(PDL_INTC_REG_IR | IR_BSC_BUSERR)
#define PDL_INTC_REG_IR_FCUIF_FIFERR	(PDL_INTC_REG_IR | IR_FCUIF_FIFERR)
#define PDL_INTC_REG_IR_FCUIF_FRDYI		(PDL_INTC_REG_IR | IR_FCUIF_FRDYI)
#define PDL_INTC_REG_IR_ICU_SWINT		(PDL_INTC_REG_IR | IR_ICU_SWINT)
#define PDL_INTC_REG_IR_CMT0_CMI		(PDL_INTC_REG_IR | IR_CMT0_CMI0)
#define PDL_INTC_REG_IR_CMT1_CMI		(PDL_INTC_REG_IR | IR_CMT1_CMI1)
#define PDL_INTC_REG_IR_CMT2_CMI		(PDL_INTC_REG_IR | IR_CMT2_CMI2)
#define PDL_INTC_REG_IR_CMT3_CMI		(PDL_INTC_REG_IR | IR_CMT3_CMI3)
#define PDL_INTC_REG_IR_SPI0_SPEI		(PDL_INTC_REG_IR | IR_RSPI0_SPEI0)
#define PDL_INTC_REG_IR_SPI0_SPRI		(PDL_INTC_REG_IR | IR_RSPI0_SPRI0)
#define PDL_INTC_REG_IR_SPI0_SPTI		(PDL_INTC_REG_IR | IR_RSPI0_SPTI0)
#define PDL_INTC_REG_IR_SPI0_SPII		(PDL_INTC_REG_IR | IR_RSPI0_SPII0)
#define PDL_INTC_REG_IR_CAN0_ERS		(PDL_INTC_REG_IR | IR_CAN0_ERS0)
#define PDL_INTC_REG_IR_CAN0_RXF		(PDL_INTC_REG_IR | IR_CAN0_RXF0)
#define PDL_INTC_REG_IR_CAN0_TXF		(PDL_INTC_REG_IR | IR_CAN0_TXF0)
#define PDL_INTC_REG_IR_CAN0_RXM		(PDL_INTC_REG_IR | IR_CAN0_RXM0)
#define PDL_INTC_REG_IR_CAN0_TXM		(PDL_INTC_REG_IR | IR_CAN0_TXM0)
#define PDL_INTC_REG_IR_ICU_IRQ0		(PDL_INTC_REG_IR | IR_ICU_IRQ0)
#define PDL_INTC_REG_IR_ICU_IRQ1		(PDL_INTC_REG_IR | IR_ICU_IRQ1)
#define PDL_INTC_REG_IR_ICU_IRQ2		(PDL_INTC_REG_IR | IR_ICU_IRQ2)
#define PDL_INTC_REG_IR_ICU_IRQ3		(PDL_INTC_REG_IR | IR_ICU_IRQ3)
#define PDL_INTC_REG_IR_ICU_IRQ4		(PDL_INTC_REG_IR | IR_ICU_IRQ4)
#define PDL_INTC_REG_IR_ICU_IRQ5		(PDL_INTC_REG_IR | IR_ICU_IRQ5)
#define PDL_INTC_REG_IR_ICU_IRQ6		(PDL_INTC_REG_IR | IR_ICU_IRQ6)
#define PDL_INTC_REG_IR_ICU_IRQ7		(PDL_INTC_REG_IR | IR_ICU_IRQ7)
#define PDL_INTC_REG_IR_WDT_WOVI		(PDL_INTC_REG_IR | IR_WDT_WOVI)
#define PDL_INTC_REG_IR_AD0_ADI			(PDL_INTC_REG_IR | IR_AD0_ADI0)
#define PDL_INTC_REG_IR_S12ADA0_ADI		(PDL_INTC_REG_IR | IR_S12AD0_S12ADI0)
#define PDL_INTC_REG_IR_S12ADA1_ADI		(PDL_INTC_REG_IR | IR_S12AD1_S12ADI1)
#define PDL_INTC_REG_IR_CMPI			(PDL_INTC_REG_IR | IR_S12AD_CMPI)
#define PDL_INTC_REG_IR_MTU0_TGIA		(PDL_INTC_REG_IR | IR_MTU0_TGIA0)
#define PDL_INTC_REG_IR_MTU0_TGIB		(PDL_INTC_REG_IR | IR_MTU0_TGIB0)
#define PDL_INTC_REG_IR_MTU0_TGIC		(PDL_INTC_REG_IR | IR_MTU0_TGIC0)
#define PDL_INTC_REG_IR_MTU0_TGID		(PDL_INTC_REG_IR | IR_MTU0_TGID0)
#define PDL_INTC_REG_IR_MTU0_TCIV		(PDL_INTC_REG_IR | IR_MTU0_TCIV0)
#define PDL_INTC_REG_IR_MTU0_TGIE		(PDL_INTC_REG_IR | IR_MTU0_TGIE0)
#define PDL_INTC_REG_IR_MTU0_TGIF		(PDL_INTC_REG_IR | IR_MTU0_TGIF0)
#define PDL_INTC_REG_IR_MTU1_TGIA		(PDL_INTC_REG_IR | IR_MTU1_TGIA1)
#define PDL_INTC_REG_IR_MTU1_TGIB		(PDL_INTC_REG_IR | IR_MTU1_TGIB1)
#define PDL_INTC_REG_IR_MTU1_TCIV		(PDL_INTC_REG_IR | IR_MTU1_TCIV1)
#define PDL_INTC_REG_IR_MTU1_TCIU		(PDL_INTC_REG_IR | IR_MTU1_TCIU1)
#define PDL_INTC_REG_IR_MTU2_TGIA		(PDL_INTC_REG_IR | IR_MTU2_TGIA2)
#define PDL_INTC_REG_IR_MTU2_TGIB		(PDL_INTC_REG_IR | IR_MTU2_TGIB2)
#define PDL_INTC_REG_IR_MTU2_TCIV		(PDL_INTC_REG_IR | IR_MTU2_TCIV2)
#define PDL_INTC_REG_IR_MTU2_TCIU		(PDL_INTC_REG_IR | IR_MTU2_TCIU2)
#define PDL_INTC_REG_IR_MTU3_TGIA		(PDL_INTC_REG_IR | IR_MTU3_TGIA3)
#define PDL_INTC_REG_IR_MTU3_TGIB		(PDL_INTC_REG_IR | IR_MTU3_TGIB3)
#define PDL_INTC_REG_IR_MTU3_TGIC		(PDL_INTC_REG_IR | IR_MTU3_TGIC3)
#define PDL_INTC_REG_IR_MTU3_TGID		(PDL_INTC_REG_IR | IR_MTU3_TGID3)
#define PDL_INTC_REG_IR_MTU3_TCIV		(PDL_INTC_REG_IR | IR_MTU3_TCIV3)
#define PDL_INTC_REG_IR_MTU4_TGIA		(PDL_INTC_REG_IR | IR_MTU4_TGIA4)
#define PDL_INTC_REG_IR_MTU4_TGIB		(PDL_INTC_REG_IR | IR_MTU4_TGIB4)
#define PDL_INTC_REG_IR_MTU4_TGIC		(PDL_INTC_REG_IR | IR_MTU4_TGIC4)
#define PDL_INTC_REG_IR_MTU4_TGID		(PDL_INTC_REG_IR | IR_MTU4_TGID4)
#define PDL_INTC_REG_IR_MTU4_TCIV		(PDL_INTC_REG_IR | IR_MTU4_TCIV4)
#define PDL_INTC_REG_IR_MTU5_TGIU		(PDL_INTC_REG_IR | IR_MTU5_TGIU5)
#define PDL_INTC_REG_IR_MTU5_TGIV		(PDL_INTC_REG_IR | IR_MTU5_TGIV5)
#define PDL_INTC_REG_IR_MTU5_TGIW		(PDL_INTC_REG_IR | IR_MTU5_TGIW5)
#define PDL_INTC_REG_IR_MTU6_TGIA		(PDL_INTC_REG_IR | IR_MTU6_TGIA6)
#define PDL_INTC_REG_IR_MTU6_TGIB		(PDL_INTC_REG_IR | IR_MTU6_TGIB6)
#define PDL_INTC_REG_IR_MTU6_TGIC		(PDL_INTC_REG_IR | IR_MTU6_TGIC6)
#define PDL_INTC_REG_IR_MTU6_TGID		(PDL_INTC_REG_IR | IR_MTU6_TGID6)
#define PDL_INTC_REG_IR_MTU6_TCIV		(PDL_INTC_REG_IR | IR_MTU6_TCIV6)
#define PDL_INTC_REG_IR_MTU7_TGIA		(PDL_INTC_REG_IR | IR_MTU7_TGIA7)
#define PDL_INTC_REG_IR_MTU7_TGIB		(PDL_INTC_REG_IR | IR_MTU7_TGIB7)
#define PDL_INTC_REG_IR_MTU7_TGIC		(PDL_INTC_REG_IR | IR_MTU7_TGIC7)
#define PDL_INTC_REG_IR_MTU7_TGID		(PDL_INTC_REG_IR | IR_MTU7_TGID7)
#define PDL_INTC_REG_IR_MTU7_TCIV		(PDL_INTC_REG_IR | IR_MTU7_TCIV7)
#define PDL_INTC_REG_IR_POE_OEI1		(PDL_INTC_REG_IR | IR_POE_OEI1)
#define PDL_INTC_REG_IR_POE_OEI2		(PDL_INTC_REG_IR | IR_POE_OEI2)
#define PDL_INTC_REG_IR_POE_OEI3		(PDL_INTC_REG_IR | IR_POE_OEI3)
#define PDL_INTC_REG_IR_POE_OEI4		(PDL_INTC_REG_IR | IR_POE_OEI4)
#define PDL_INTC_REG_IR_GPT0_GTCIA		(PDL_INTC_REG_IR | IR_GPT0_GTCIA0)
#define PDL_INTC_REG_IR_GPT0_GTCIB		(PDL_INTC_REG_IR | IR_GPT0_GTCIB0)
#define PDL_INTC_REG_IR_GPT0_GTCIC		(PDL_INTC_REG_IR | IR_GPT0_GTCIC0)
#define PDL_INTC_REG_IR_GPT0_GTCIE		(PDL_INTC_REG_IR | IR_GPT0_GTCIE0)
#define PDL_INTC_REG_IR_GPT0_GTCIV		(PDL_INTC_REG_IR | IR_GPT0_GTCIV0)
#define PDL_INTC_REG_IR_GPT0_LOCO1		(PDL_INTC_REG_IR | IR_GPT0_LOCO1)
#define PDL_INTC_REG_IR_GPT1_GTCIA		(PDL_INTC_REG_IR | IR_GPT1_GTCIA1)
#define PDL_INTC_REG_IR_GPT1_GTCIB		(PDL_INTC_REG_IR | IR_GPT1_GTCIB1)
#define PDL_INTC_REG_IR_GPT1_GTCIC		(PDL_INTC_REG_IR | IR_GPT1_GTCIC1)
#define PDL_INTC_REG_IR_GPT1_GTCIE		(PDL_INTC_REG_IR | IR_GPT1_GTCIE1)
#define PDL_INTC_REG_IR_GPT1_GTCIV		(PDL_INTC_REG_IR | IR_GPT1_GTCIV1)
#define PDL_INTC_REG_IR_GPT2_GTCIA		(PDL_INTC_REG_IR | IR_GPT2_GTCIA2)
#define PDL_INTC_REG_IR_GPT2_GTCIB		(PDL_INTC_REG_IR | IR_GPT2_GTCIB2)
#define PDL_INTC_REG_IR_GPT2_GTCIC		(PDL_INTC_REG_IR | IR_GPT2_GTCIC2)
#define PDL_INTC_REG_IR_GPT2_GTCIE		(PDL_INTC_REG_IR | IR_GPT2_GTCIE2)
#define PDL_INTC_REG_IR_GPT2_GTCIV		(PDL_INTC_REG_IR | IR_GPT2_GTCIV2)
#define PDL_INTC_REG_IR_GPT3_GTCIA		(PDL_INTC_REG_IR | IR_GPT3_GTCIA3)
#define PDL_INTC_REG_IR_GPT3_GTCIB		(PDL_INTC_REG_IR | IR_GPT3_GTCIB3)
#define PDL_INTC_REG_IR_GPT3_GTCIC		(PDL_INTC_REG_IR | IR_GPT3_GTCIC3)
#define PDL_INTC_REG_IR_GPT3_GTCIE		(PDL_INTC_REG_IR | IR_GPT3_GTCIE3)
#define PDL_INTC_REG_IR_GPT3_GTCIV		(PDL_INTC_REG_IR | IR_GPT3_GTCIV3)
#define PDL_INTC_REG_IR_SCI0_ERI		(PDL_INTC_REG_IR | IR_SCI0_ERI0)
#define PDL_INTC_REG_IR_SCI0_RXI		(PDL_INTC_REG_IR | IR_SCI0_RXI0)
#define PDL_INTC_REG_IR_SCI0_TXI		(PDL_INTC_REG_IR | IR_SCI0_TXI0)
#define PDL_INTC_REG_IR_SCI0_TEI		(PDL_INTC_REG_IR | IR_SCI0_TEI0)
#define PDL_INTC_REG_IR_SCI1_ERI		(PDL_INTC_REG_IR | IR_SCI1_ERI1)
#define PDL_INTC_REG_IR_SCI1_RXI		(PDL_INTC_REG_IR | IR_SCI1_RXI1)
#define PDL_INTC_REG_IR_SCI1_TXI		(PDL_INTC_REG_IR | IR_SCI1_TXI1)
#define PDL_INTC_REG_IR_SCI1_TEI		(PDL_INTC_REG_IR | IR_SCI1_TEI1)
#define PDL_INTC_REG_IR_SCI2_ERI		(PDL_INTC_REG_IR | IR_SCI2_ERI2)
#define PDL_INTC_REG_IR_SCI2_RXI		(PDL_INTC_REG_IR | IR_SCI2_RXI2)
#define PDL_INTC_REG_IR_SCI2_TXI		(PDL_INTC_REG_IR | IR_SCI2_TXI2)
#define PDL_INTC_REG_IR_SCI2_TEI		(PDL_INTC_REG_IR | IR_SCI2_TEI2)
#define PDL_INTC_REG_IR_IIC0_EEI		(PDL_INTC_REG_IR | IR_RIIC0_ICEEI0)
#define PDL_INTC_REG_IR_IIC0_RXI		(PDL_INTC_REG_IR | IR_RIIC0_ICRXI0)
#define PDL_INTC_REG_IR_IIC0_TXI		(PDL_INTC_REG_IR | IR_RIIC0_ICTXI0)
#define PDL_INTC_REG_IR_IIC0_TEI		(PDL_INTC_REG_IR | IR_RIIC0_ICTEI0)
#define PDL_INTC_REG_IR_LIN0_LIN		(PDL_INTC_REG_IR | IR_LIN0_LIN0)

/* IER registers */
#define PDL_INTC_REG_IER02	(PDL_INTC_REG_IER | 0x02)
#define PDL_INTC_REG_IER03	(PDL_INTC_REG_IER | 0x03)
#define PDL_INTC_REG_IER05	(PDL_INTC_REG_IER | 0x05)
#define PDL_INTC_REG_IER07	(PDL_INTC_REG_IER | 0x07)
#define PDL_INTC_REG_IER08	(PDL_INTC_REG_IER | 0x08)
#define PDL_INTC_REG_IER0C	(PDL_INTC_REG_IER | 0x0C)
#define PDL_INTC_REG_IER0D	(PDL_INTC_REG_IER | 0x0D)
#define PDL_INTC_REG_IER0E	(PDL_INTC_REG_IER | 0x0E)
#define PDL_INTC_REG_IER0F	(PDL_INTC_REG_IER | 0x0F)
#define PDL_INTC_REG_IER10	(PDL_INTC_REG_IER | 0x10)
#define PDL_INTC_REG_IER11	(PDL_INTC_REG_IER | 0x11)
#define PDL_INTC_REG_IER12	(PDL_INTC_REG_IER | 0x12)
#define PDL_INTC_REG_IER13	(PDL_INTC_REG_IER | 0x13)
#define PDL_INTC_REG_IER14	(PDL_INTC_REG_IER | 0x14)
#define PDL_INTC_REG_IER15	(PDL_INTC_REG_IER | 0x15)
#define PDL_INTC_REG_IER16	(PDL_INTC_REG_IER | 0x16)
#define PDL_INTC_REG_IER17	(PDL_INTC_REG_IER | 0x17)
#define PDL_INTC_REG_IER18	(PDL_INTC_REG_IER | 0x18)
#define PDL_INTC_REG_IER1A	(PDL_INTC_REG_IER | 0x1A)
#define PDL_INTC_REG_IER1B	(PDL_INTC_REG_IER | 0x1B)
#define PDL_INTC_REG_IER1C	(PDL_INTC_REG_IER | 0x1C)
#define PDL_INTC_REG_IER1D	(PDL_INTC_REG_IER | 0x1D)
#define PDL_INTC_REG_IER1E	(PDL_INTC_REG_IER | 0x1E)
#define PDL_INTC_REG_IER1F	(PDL_INTC_REG_IER | 0x1F)

/* IPR registers */
#define PDL_INTC_REG_IPR_BSC_BUSERR			(PDL_INTC_REG_IPR | IPR_BSC_BUSERR)
#define PDL_INTC_REG_IPR_FCUIF_FIFERR		(PDL_INTC_REG_IPR | IPR_FCUIF_FIFERR)
#define PDL_INTC_REG_IPR_FCUIF_FRDYI		(PDL_INTC_REG_IPR | IPR_FCUIF_FRDYI)
#define PDL_INTC_REG_IPR_ICU_SWINT			(PDL_INTC_REG_IPR | IPR_ICU_SWINT)
#define PDL_INTC_REG_IPR_CMT0_CMI			(PDL_INTC_REG_IPR | IPR_CMT0_CMI0)
#define PDL_INTC_REG_IPR_CMT1_CMI			(PDL_INTC_REG_IPR | IPR_CMT1_CMI1)
#define PDL_INTC_REG_IPR_CMT2_CMI			(PDL_INTC_REG_IPR | IPR_CMT2_CMI2)
#define PDL_INTC_REG_IPR_CMT3_CMI			(PDL_INTC_REG_IPR | IPR_CMT3_CMI3)
#define PDL_INTC_REG_IPR_SPI0_SPEI			(PDL_INTC_REG_IPR | IPR_RSPI0_SPEI0)
#define PDL_INTC_REG_IPR_SPI0_SPRI			(PDL_INTC_REG_IPR | IPR_RSPI0_SPRI0)
#define PDL_INTC_REG_IPR_SPI0_SPTI			(PDL_INTC_REG_IPR | IPR_RSPI0_SPTI0)
#define PDL_INTC_REG_IPR_SPI0_SPII			(PDL_INTC_REG_IPR | IPR_RSPI0_SPII0)
#define PDL_INTC_REG_IPR_CAN0_ERS			(PDL_INTC_REG_IPR | IPR_CAN0_ERS0)
#define PDL_INTC_REG_IPR_CAN0_RXF			(PDL_INTC_REG_IPR | IPR_CAN0_RXF0)
#define PDL_INTC_REG_IPR_CAN0_TXF			(PDL_INTC_REG_IPR | IPR_CAN0_TXF0)
#define PDL_INTC_REG_IPR_CAN0_RXM			(PDL_INTC_REG_IPR | IPR_CAN0_RXM0)
#define PDL_INTC_REG_IPR_CAN0_TXM			(PDL_INTC_REG_IPR | IPR_CAN0_TXM0)
#define PDL_INTC_REG_IPR_ICU_IRQ0			(PDL_INTC_REG_IPR | IPR_ICU_IRQ0)
#define PDL_INTC_REG_IPR_ICU_IRQ1			(PDL_INTC_REG_IPR | IPR_ICU_IRQ1)
#define PDL_INTC_REG_IPR_ICU_IRQ2			(PDL_INTC_REG_IPR | IPR_ICU_IRQ2)
#define PDL_INTC_REG_IPR_ICU_IRQ3			(PDL_INTC_REG_IPR | IPR_ICU_IRQ3)
#define PDL_INTC_REG_IPR_ICU_IRQ4			(PDL_INTC_REG_IPR | IPR_ICU_IRQ4)
#define PDL_INTC_REG_IPR_ICU_IRQ5			(PDL_INTC_REG_IPR | IPR_ICU_IRQ5)
#define PDL_INTC_REG_IPR_ICU_IRQ6			(PDL_INTC_REG_IPR | IPR_ICU_IRQ6)
#define PDL_INTC_REG_IPR_ICU_IRQ7			(PDL_INTC_REG_IPR | IPR_ICU_IRQ7)
#define PDL_INTC_REG_IPR_WDT_WOVI			(PDL_INTC_REG_IPR | IPR_WDT_WOVI)
#define PDL_INTC_REG_IPR_AD0_ADI			(PDL_INTC_REG_IPR | IPR_AD0_ADI0)
#define PDL_INTC_REG_IPR_S12ADA0_ADI		(PDL_INTC_REG_IPR | IPR_S12AD0_S12ADI0)
#define PDL_INTC_REG_IPR_S12ADA1_ADI		(PDL_INTC_REG_IPR | IPR_S12AD1_S12ADI1)
#define PDL_INTC_REG_IPR_CMPI				(PDL_INTC_REG_IPR | IPR_S12AD_CMPI)
#define PDL_INTC_REG_IPR_MTU0_TGIA			(PDL_INTC_REG_IPR | IPR_MTU0_TGIA0)
#define PDL_INTC_REG_IPR_MTU0_TGIB			(PDL_INTC_REG_IPR | IPR_MTU0_TGIB0)
#define PDL_INTC_REG_IPR_MTU0_TGIC			(PDL_INTC_REG_IPR | IPR_MTU0_TGIC0)
#define PDL_INTC_REG_IPR_MTU0_TGID			(PDL_INTC_REG_IPR | IPR_MTU0_TGID0)
#define PDL_INTC_REG_IPR_MTU0_TCIV			(PDL_INTC_REG_IPR | IPR_MTU0_TCIV0)
#define PDL_INTC_REG_IPR_MTU0_TGIE			(PDL_INTC_REG_IPR | IPR_MTU0_TGIE0)
#define PDL_INTC_REG_IPR_MTU0_TGIF			(PDL_INTC_REG_IPR | IPR_MTU0_TGIF0)
#define PDL_INTC_REG_IPR_MTU1_TGIA			(PDL_INTC_REG_IPR | IPR_MTU1_TGIA1)
#define PDL_INTC_REG_IPR_MTU1_TGIB			(PDL_INTC_REG_IPR | IPR_MTU1_TGIB1)
#define PDL_INTC_REG_IPR_MTU1_TCIV			(PDL_INTC_REG_IPR | IPR_MTU1_TCIV1)
#define PDL_INTC_REG_IPR_MTU1_TCIU			(PDL_INTC_REG_IPR | IPR_MTU1_TCIU1)
#define PDL_INTC_REG_IPR_MTU2_TGIA			(PDL_INTC_REG_IPR | IPR_MTU2_TGIA2)
#define PDL_INTC_REG_IPR_MTU2_TGIB			(PDL_INTC_REG_IPR | IPR_MTU2_TGIB2)
#define PDL_INTC_REG_IPR_MTU2_TCIV			(PDL_INTC_REG_IPR | IPR_MTU2_TCIV2)
#define PDL_INTC_REG_IPR_MTU2_TCIU			(PDL_INTC_REG_IPR | IPR_MTU2_TCIU2)
#define PDL_INTC_REG_IPR_MTU3_TGIA			(PDL_INTC_REG_IPR | IPR_MTU3_TGIA3)
#define PDL_INTC_REG_IPR_MTU3_TGIB			(PDL_INTC_REG_IPR | IPR_MTU3_TGIB3)
#define PDL_INTC_REG_IPR_MTU3_TGIC			(PDL_INTC_REG_IPR | IPR_MTU3_TGIC3)
#define PDL_INTC_REG_IPR_MTU3_TGID			(PDL_INTC_REG_IPR | IPR_MTU3_TGID3)
#define PDL_INTC_REG_IPR_MTU3_TCIV			(PDL_INTC_REG_IPR | IPR_MTU3_TCIV3)
#define PDL_INTC_REG_IPR_MTU4_TGIA			(PDL_INTC_REG_IPR | IPR_MTU4_TGIA4)
#define PDL_INTC_REG_IPR_MTU4_TGIB			(PDL_INTC_REG_IPR | IPR_MTU4_TGIB4)
#define PDL_INTC_REG_IPR_MTU4_TGIC			(PDL_INTC_REG_IPR | IPR_MTU4_TGIC4)
#define PDL_INTC_REG_IPR_MTU4_TGID			(PDL_INTC_REG_IPR | IPR_MTU4_TGID4)
#define PDL_INTC_REG_IPR_MTU4_TCIV			(PDL_INTC_REG_IPR | IPR_MTU4_TCIV4)
#define PDL_INTC_REG_IPR_MTU5_TGIU			(PDL_INTC_REG_IPR | IPR_MTU5_TGIU5)
#define PDL_INTC_REG_IPR_MTU5_TGIV			(PDL_INTC_REG_IPR | IPR_MTU5_TGIV5)
#define PDL_INTC_REG_IPR_MTU5_TGIW			(PDL_INTC_REG_IPR | IPR_MTU5_TGIW5)
#define PDL_INTC_REG_IPR_MTU6_TGIA			(PDL_INTC_REG_IPR | IPR_MTU6_TGIA6)
#define PDL_INTC_REG_IPR_MTU6_TGIB			(PDL_INTC_REG_IPR | IPR_MTU6_TGIB6)
#define PDL_INTC_REG_IPR_MTU6_TGIC			(PDL_INTC_REG_IPR | IPR_MTU6_TGIC6)
#define PDL_INTC_REG_IPR_MTU6_TGID			(PDL_INTC_REG_IPR | IPR_MTU6_TGID6)
#define PDL_INTC_REG_IPR_MTU6_TCIV			(PDL_INTC_REG_IPR | IPR_MTU6_TCIV6)
#define PDL_INTC_REG_IPR_MTU7_TGIA			(PDL_INTC_REG_IPR | IPR_MTU7_TGIA7)
#define PDL_INTC_REG_IPR_MTU7_TGIB			(PDL_INTC_REG_IPR | IPR_MTU7_TGIB7)
#define PDL_INTC_REG_IPR_MTU7_TGIC			(PDL_INTC_REG_IPR | IPR_MTU7_TGIC7)
#define PDL_INTC_REG_IPR_MTU7_TGID			(PDL_INTC_REG_IPR | IPR_MTU7_TGID7)
#define PDL_INTC_REG_IPR_MTU7_TCIV			(PDL_INTC_REG_IPR | IPR_MTU7_TCIV7)
#define PDL_INTC_REG_IPR_POE_OEI1			(PDL_INTC_REG_IPR | IPR_POE_OEI1)
#define PDL_INTC_REG_IPR_POE_OEI2			(PDL_INTC_REG_IPR | IPR_POE_OEI2)
#define PDL_INTC_REG_IPR_POE_OEI3			(PDL_INTC_REG_IPR | IPR_POE_OEI3)
#define PDL_INTC_REG_IPR_POE_OEI4			(PDL_INTC_REG_IPR | IPR_POE_OEI4)
#define PDL_INTC_REG_IPR_GPT0_GTCIA			(PDL_INTC_REG_IPR | IPR_GPT0_GTCIA0)
#define PDL_INTC_REG_IPR_GPT0_GTCIB			(PDL_INTC_REG_IPR | IPR_GPT0_GTCIB0)
#define PDL_INTC_REG_IPR_GPT0_GTCIC			(PDL_INTC_REG_IPR | IPR_GPT0_GTCIC0)
#define PDL_INTC_REG_IPR_GPT0_GTCIE			(PDL_INTC_REG_IPR | IPR_GPT0_GTCIE0)
#define PDL_INTC_REG_IPR_GPT0_GTCIV			(PDL_INTC_REG_IPR | IPR_GPT0_GTCIV0)
#define PDL_INTC_REG_IPR_GPT0_LOCO1			(PDL_INTC_REG_IPR | IPR_GPT0_LOCO1)
#define PDL_INTC_REG_IPR_GPT1_GTCIA			(PDL_INTC_REG_IPR | IPR_GPT1_GTCIA1)
#define PDL_INTC_REG_IPR_GPT1_GTCIB			(PDL_INTC_REG_IPR | IPR_GPT1_GTCIB1)
#define PDL_INTC_REG_IPR_GPT1_GTCIC			(PDL_INTC_REG_IPR | IPR_GPT1_GTCIC1)
#define PDL_INTC_REG_IPR_GPT1_GTCIE			(PDL_INTC_REG_IPR | IPR_GPT1_GTCIE1)
#define PDL_INTC_REG_IPR_GPT1_GTCIV			(PDL_INTC_REG_IPR | IPR_GPT1_GTCIV1)
#define PDL_INTC_REG_IPR_GPT2_GTCIA			(PDL_INTC_REG_IPR | IPR_GPT2_GTCIA2)
#define PDL_INTC_REG_IPR_GPT2_GTCIB			(PDL_INTC_REG_IPR | IPR_GPT2_GTCIB2)
#define PDL_INTC_REG_IPR_GPT2_GTCIC			(PDL_INTC_REG_IPR | IPR_GPT2_GTCIC2)
#define PDL_INTC_REG_IPR_GPT2_GTCIE			(PDL_INTC_REG_IPR | IPR_GPT2_GTCIE2)
#define PDL_INTC_REG_IPR_GPT2_GTCIV			(PDL_INTC_REG_IPR | IPR_GPT2_GTCIV2)
#define PDL_INTC_REG_IPR_GPT3_GTCIA			(PDL_INTC_REG_IPR | IPR_GPT3_GTCIA3)
#define PDL_INTC_REG_IPR_GPT3_GTCIB			(PDL_INTC_REG_IPR | IPR_GPT3_GTCIB3)
#define PDL_INTC_REG_IPR_GPT3_GTCIC			(PDL_INTC_REG_IPR | IPR_GPT3_GTCIC3)
#define PDL_INTC_REG_IPR_GPT3_GTCIE			(PDL_INTC_REG_IPR | IPR_GPT3_GTCIE3)
#define PDL_INTC_REG_IPR_GPT3_GTCIV			(PDL_INTC_REG_IPR | IPR_GPT3_GTCIV3)
#define PDL_INTC_REG_IPR_SCI0_ERI			(PDL_INTC_REG_IPR | IPR_SCI0_ERI0)
#define PDL_INTC_REG_IPR_SCI0_RXI			(PDL_INTC_REG_IPR | IPR_SCI0_RXI0)
#define PDL_INTC_REG_IPR_SCI0_TXI			(PDL_INTC_REG_IPR | IPR_SCI0_TXI0)
#define PDL_INTC_REG_IPR_SCI0_TEI			(PDL_INTC_REG_IPR | IPR_SCI0_TEI0)
#define PDL_INTC_REG_IPR_SCI1_ERI			(PDL_INTC_REG_IPR | IPR_SCI1_ERI1)
#define PDL_INTC_REG_IPR_SCI1_RXI			(PDL_INTC_REG_IPR | IPR_SCI1_RXI1)
#define PDL_INTC_REG_IPR_SCI1_TXI			(PDL_INTC_REG_IPR | IPR_SCI1_TXI1)
#define PDL_INTC_REG_IPR_SCI1_TEI			(PDL_INTC_REG_IPR | IPR_SCI1_TEI1)
#define PDL_INTC_REG_IPR_SCI2_ERI			(PDL_INTC_REG_IPR | IPR_SCI2_ERI2)
#define PDL_INTC_REG_IPR_SCI2_RXI			(PDL_INTC_REG_IPR | IPR_SCI2_RXI2)
#define PDL_INTC_REG_IPR_SCI2_TXI			(PDL_INTC_REG_IPR | IPR_SCI2_TXI2)
#define PDL_INTC_REG_IPR_SCI2_TEI			(PDL_INTC_REG_IPR | IPR_SCI2_TEI2)
#define PDL_INTC_REG_IPR_IIC0_ICEEI			(PDL_INTC_REG_IPR | IPR_RIIC0_ICEEI0)
#define PDL_INTC_REG_IPR_IIC0_ICRXI			(PDL_INTC_REG_IPR | IPR_RIIC0_ICRXI0)
#define PDL_INTC_REG_IPR_IIC0_ICTXI			(PDL_INTC_REG_IPR | IPR_RIIC0_ICTXI0)
#define PDL_INTC_REG_IPR_IIC0_ICTEI			(PDL_INTC_REG_IPR | IPR_RIIC0_ICTEI0)
#define PDL_INTC_REG_IPR_LIN0_LIN			(PDL_INTC_REG_IPR | IPR_LIN0_LIN0)

/* DTCER registers */
#define PDL_INTC_REG_DTCER_ICU_SWINT		(PDL_INTC_REG_DTCER | DTCE_ICU_SWINT)
#define PDL_INTC_REG_DTCER_CMT0_CMI			(PDL_INTC_REG_DTCER | DTCE_CMT0_CMI0)
#define PDL_INTC_REG_DTCER_CMT1_CMI			(PDL_INTC_REG_DTCER | DTCE_CMT1_CMI1)
#define PDL_INTC_REG_DTCER_CMT2_CMI			(PDL_INTC_REG_DTCER | DTCE_CMT2_CMI2)
#define PDL_INTC_REG_DTCER_CMT3_CMI			(PDL_INTC_REG_DTCER | DTCE_CMT3_CMI3)
#define PDL_INTC_REG_DTCER_USB0_D0FIFO		(PDL_INTC_REG_DTCER | DTCE_USB0_D0FIFO0)
#define PDL_INTC_REG_DTCER_USB0_D1FIFO		(PDL_INTC_REG_DTCER | DTCE_USB0_D1FIFO0)
#define PDL_INTC_REG_DTCER_USB1_D0FIFO		(PDL_INTC_REG_DTCER | DTCE_USB1_D0FIFO1)
#define PDL_INTC_REG_DTCER_USB1_D1FIFO		(PDL_INTC_REG_DTCER | DTCE_USB1_D1FIFO1)
#define PDL_INTC_REG_DTCER_SPI0_SPRI		(PDL_INTC_REG_DTCER | DTCE_RSPI0_SPRI0)
#define PDL_INTC_REG_DTCER_SPI0_SPTI		(PDL_INTC_REG_DTCER | DTCE_RSPI0_SPTI0)
#define PDL_INTC_REG_DTCER_SPI1_SPRI		(PDL_INTC_REG_DTCER | DTCE_RSPI1_SPRI1)
#define PDL_INTC_REG_DTCER_SPI1_SPTI		(PDL_INTC_REG_DTCER | DTCE_RSPI1_SPTI1)
#define PDL_INTC_REG_DTCER_ICU_IRQ0			(PDL_INTC_REG_DTCER | DTCE_ICU_IRQ0)
#define PDL_INTC_REG_DTCER_ICU_IRQ1			(PDL_INTC_REG_DTCER | DTCE_ICU_IRQ1)
#define PDL_INTC_REG_DTCER_ICU_IRQ2			(PDL_INTC_REG_DTCER | DTCE_ICU_IRQ2)
#define PDL_INTC_REG_DTCER_ICU_IRQ3			(PDL_INTC_REG_DTCER | DTCE_ICU_IRQ3)
#define PDL_INTC_REG_DTCER_ICU_IRQ4			(PDL_INTC_REG_DTCER | DTCE_ICU_IRQ4)
#define PDL_INTC_REG_DTCER_ICU_IRQ5			(PDL_INTC_REG_DTCER | DTCE_ICU_IRQ5)
#define PDL_INTC_REG_DTCER_ICU_IRQ6			(PDL_INTC_REG_DTCER | DTCE_ICU_IRQ6)
#define PDL_INTC_REG_DTCER_ICU_IRQ7			(PDL_INTC_REG_DTCER | DTCE_ICU_IRQ7)
#define PDL_INTC_REG_DTCER_ICU_IRQ8			(PDL_INTC_REG_DTCER | DTCE_ICU_IRQ8)
#define PDL_INTC_REG_DTCER_ICU_IRQ9			(PDL_INTC_REG_DTCER | DTCE_ICU_IRQ9)
#define PDL_INTC_REG_DTCER_ICU_IRQ10		(PDL_INTC_REG_DTCER | DTCE_ICU_IRQ10)
#define PDL_INTC_REG_DTCER_ICU_IRQ11		(PDL_INTC_REG_DTCER | DTCE_ICU_IRQ11)
#define PDL_INTC_REG_DTCER_ICU_IRQ12		(PDL_INTC_REG_DTCER | DTCE_ICU_IRQ12)
#define PDL_INTC_REG_DTCER_ICU_IRQ13		(PDL_INTC_REG_DTCER | DTCE_ICU_IRQ13)
#define PDL_INTC_REG_DTCER_ICU_IRQ14		(PDL_INTC_REG_DTCER | DTCE_ICU_IRQ14)
#define PDL_INTC_REG_DTCER_ICU_IRQ15		(PDL_INTC_REG_DTCER | DTCE_ICU_IRQ15)
#define PDL_INTC_REG_DTCER_AD0_ADI			(PDL_INTC_REG_DTCER | DTCE_AD0_ADI0)
#define PDL_INTC_REG_DTCER_AD1_ADI			(PDL_INTC_REG_DTCER | DTCE_AD1_ADI1)
#define PDL_INTC_REG_DTCER_S12AD_ADI		(PDL_INTC_REG_DTCER | DTCE_S12AD_ADI)
#define PDL_INTC_REG_DTCER_MTU0_TGIA		(PDL_INTC_REG_DTCER | DTCE_MTU0_TGIA0)
#define PDL_INTC_REG_DTCER_MTU0_TGIB		(PDL_INTC_REG_DTCER | DTCE_MTU0_TGIB0)
#define PDL_INTC_REG_DTCER_MTU0_TGIC		(PDL_INTC_REG_DTCER | DTCE_MTU0_TGIC0)
#define PDL_INTC_REG_DTCER_MTU0_TGID		(PDL_INTC_REG_DTCER | DTCE_MTU0_TGID0)
#define PDL_INTC_REG_DTCER_MTU1_TGIA		(PDL_INTC_REG_DTCER | DTCE_MTU1_TGIA1)
#define PDL_INTC_REG_DTCER_MTU1_TGIB		(PDL_INTC_REG_DTCER | DTCE_MTU1_TGIB1)
#define PDL_INTC_REG_DTCER_MTU2_TGIA		(PDL_INTC_REG_DTCER | DTCE_MTU2_TGIA2)
#define PDL_INTC_REG_DTCER_MTU2_TGIB		(PDL_INTC_REG_DTCER | DTCE_MTU2_TGIB2)
#define PDL_INTC_REG_DTCER_MTU3_TGIA		(PDL_INTC_REG_DTCER | DTCE_MTU3_TGIA3)
#define PDL_INTC_REG_DTCER_MTU3_TGIB		(PDL_INTC_REG_DTCER | DTCE_MTU3_TGIB3)
#define PDL_INTC_REG_DTCER_MTU3_TGIC		(PDL_INTC_REG_DTCER | DTCE_MTU3_TGIC3)
#define PDL_INTC_REG_DTCER_MTU3_TGID		(PDL_INTC_REG_DTCER | DTCE_MTU3_TGID3)
#define PDL_INTC_REG_DTCER_MTU4_TGIA		(PDL_INTC_REG_DTCER | DTCE_MTU4_TGIA4)
#define PDL_INTC_REG_DTCER_MTU4_TGIB		(PDL_INTC_REG_DTCER | DTCE_MTU4_TGIB4)
#define PDL_INTC_REG_DTCER_MTU4_TGIC		(PDL_INTC_REG_DTCER | DTCE_MTU4_TGIC4)
#define PDL_INTC_REG_DTCER_MTU4_TGID		(PDL_INTC_REG_DTCER | DTCE_MTU4_TGID4)
#define PDL_INTC_REG_DTCER_MTU4_TCIV		(PDL_INTC_REG_DTCER | DTCE_MTU4_TCIV4)
#define PDL_INTC_REG_DTCER_MTU5_TGIU		(PDL_INTC_REG_DTCER | DTCE_MTU5_TGIU5)
#define PDL_INTC_REG_DTCER_MTU5_TGIV		(PDL_INTC_REG_DTCER | DTCE_MTU5_TGIV5)
#define PDL_INTC_REG_DTCER_MTU5_TGIW		(PDL_INTC_REG_DTCER | DTCE_MTU5_TGIW5)
#define PDL_INTC_REG_DTCER_MTU6_TGIA		(PDL_INTC_REG_DTCER | DTCE_MTU6_TGIA6)
#define PDL_INTC_REG_DTCER_MTU6_TGIB		(PDL_INTC_REG_DTCER | DTCE_MTU6_TGIB6)
#define PDL_INTC_REG_DTCER_MTU6_TGIC		(PDL_INTC_REG_DTCER | DTCE_MTU6_TGIC6)
#define PDL_INTC_REG_DTCER_MTU6_TGID		(PDL_INTC_REG_DTCER | DTCE_MTU6_TGID6)
#define PDL_INTC_REG_DTCER_MTU7_TGIA		(PDL_INTC_REG_DTCER | DTCE_MTU7_TGIA7)
#define PDL_INTC_REG_DTCER_MTU7_TGIB		(PDL_INTC_REG_DTCER | DTCE_MTU7_TGIB7)
#define PDL_INTC_REG_DTCER_MTU8_TGIA		(PDL_INTC_REG_DTCER | DTCE_MTU8_TGIA8)
#define PDL_INTC_REG_DTCER_MTU8_TGIB		(PDL_INTC_REG_DTCER | DTCE_MTU8_TGIB8)
#define PDL_INTC_REG_DTCER_MTU9_TGIA		(PDL_INTC_REG_DTCER | DTCE_MTU9_TGIA9)
#define PDL_INTC_REG_DTCER_MTU9_TGIB		(PDL_INTC_REG_DTCER | DTCE_MTU9_TGIB9)
#define PDL_INTC_REG_DTCER_MTU9_TGIC		(PDL_INTC_REG_DTCER | DTCE_MTU9_TGIC9)
#define PDL_INTC_REG_DTCER_MTU9_TGID		(PDL_INTC_REG_DTCER | DTCE_MTU9_TGID9)
#define PDL_INTC_REG_DTCER_MTU10_TGIA		(PDL_INTC_REG_DTCER | DTCE_MTU10_TGIA10)
#define PDL_INTC_REG_DTCER_MTU10_TGIB		(PDL_INTC_REG_DTCER | DTCE_MTU10_TGIB10)
#define PDL_INTC_REG_DTCER_MTU10_TGIC		(PDL_INTC_REG_DTCER | DTCE_MTU10_TGIC10)
#define PDL_INTC_REG_DTCER_MTU10_TGID		(PDL_INTC_REG_DTCER | DTCE_MTU10_TGID10)
#define PDL_INTC_REG_DTCER_MTU10_TCIV		(PDL_INTC_REG_DTCER | DTCE_MTU10_TCIV10)
#define PDL_INTC_REG_DTCER_MTU11_TGIU		(PDL_INTC_REG_DTCER | DTCE_MTU11_TGIU11)
#define PDL_INTC_REG_DTCER_MTU11_TGIV		(PDL_INTC_REG_DTCER | DTCE_MTU11_TGIV11)
#define PDL_INTC_REG_DTCER_MTU11_TGIW		(PDL_INTC_REG_DTCER | DTCE_MTU11_TGIW11)
#define PDL_INTC_REG_DTCER_TMR0_CMIA0		(PDL_INTC_REG_DTCER | DTCE_TMR0_CMIA0)
#define PDL_INTC_REG_DTCER_TMR0_CMIB0		(PDL_INTC_REG_DTCER | DTCE_TMR0_CMIB0)
#define PDL_INTC_REG_DTCER_TMR1_CMIA		(PDL_INTC_REG_DTCER | DTCE_TMR1_CMIA1)
#define PDL_INTC_REG_DTCER_TMR1_CMIB		(PDL_INTC_REG_DTCER | DTCE_TMR1_CMIB1)
#define PDL_INTC_REG_DTCER_TMR2_CMIA		(PDL_INTC_REG_DTCER | DTCE_TMR2_CMIA2)
#define PDL_INTC_REG_DTCER_TMR2_CMIB		(PDL_INTC_REG_DTCER | DTCE_TMR2_CMIB2)
#define PDL_INTC_REG_DTCER_TMR3_CMIA		(PDL_INTC_REG_DTCER | DTCE_TMR3_CMIA3)
#define PDL_INTC_REG_DTCER_TMR3_CMIB		(PDL_INTC_REG_DTCER | DTCE_TMR3_CMIB3)
#define PDL_INTC_REG_DTCER_DMAC_DMAC0I		(PDL_INTC_REG_DTCER | DTCE_DMAC_DMAC0I)
#define PDL_INTC_REG_DTCER_DMAC_DMAC1I		(PDL_INTC_REG_DTCER | DTCE_DMAC_DMAC1I)
#define PDL_INTC_REG_DTCER_DMAC_DMAC2I		(PDL_INTC_REG_DTCER | DTCE_DMAC_DMAC2I)
#define PDL_INTC_REG_DTCER_DMAC_DMAC3I		(PDL_INTC_REG_DTCER | DTCE_DMAC_DMAC3I)
#define PDL_INTC_REG_DTCER_EXDMAC_EXDMAC0I	(PDL_INTC_REG_DTCER | DTCE_EXDMAC_EXDMAC0I)
#define PDL_INTC_REG_DTCER_EXDMAC_EXDMAC1I	(PDL_INTC_REG_DTCER | DTCE_EXDMAC_EXDMAC1I)
#define PDL_INTC_REG_DTCER_SCI0_RXI			(PDL_INTC_REG_DTCER | DTCE_SCI0_RXI0)
#define PDL_INTC_REG_DTCER_SCI0_TXI			(PDL_INTC_REG_DTCER | DTCE_SCI0_TXI0)
#define PDL_INTC_REG_DTCER_SCI1_RXI			(PDL_INTC_REG_DTCER | DTCE_SCI1_RXI1)
#define PDL_INTC_REG_DTCER_SCI1_TXI			(PDL_INTC_REG_DTCER | DTCE_SCI1_TXI1)
#define PDL_INTC_REG_DTCER_SCI2_RXI			(PDL_INTC_REG_DTCER | DTCE_SCI2_RXI2)
#define PDL_INTC_REG_DTCER_SCI2_TXI			(PDL_INTC_REG_DTCER | DTCE_SCI2_TXI2)
#define PDL_INTC_REG_DTCER_SCI3_RXI			(PDL_INTC_REG_DTCER | DTCE_SCI3_RXI3)
#define PDL_INTC_REG_DTCER_SCI3_TXI			(PDL_INTC_REG_DTCER | DTCE_SCI3_TXI3)
#define PDL_INTC_REG_DTCER_SCI5_RXI			(PDL_INTC_REG_DTCER | DTCE_SCI5_RXI5)
#define PDL_INTC_REG_DTCER_SCI5_TXI			(PDL_INTC_REG_DTCER | DTCE_SCI5_TXI5)
#define PDL_INTC_REG_DTCER_SCI6_RXI			(PDL_INTC_REG_DTCER | DTCE_SCI6_RXI6)
#define PDL_INTC_REG_DTCER_SCI6_TXI			(PDL_INTC_REG_DTCER | DTCE_SCI6_TXI6)
#define PDL_INTC_REG_DTCER_IIC0_RXI			(PDL_INTC_REG_DTCER | DTCE_RIIC0_ICRXI0)
#define PDL_INTC_REG_DTCER_IIC0_TXI			(PDL_INTC_REG_DTCER | DTCE_RIIC0_ICTXI0)
#define PDL_INTC_REG_DTCER_IIC1_RXI			(PDL_INTC_REG_DTCER | DTCE_RIIC1_ICRXI1)
#define PDL_INTC_REG_DTCER_IIC1_TXI			(PDL_INTC_REG_DTCER | DTCE_RIIC1_ICTXI1)

#endif
/* End of file */
