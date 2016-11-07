/*
 * Copyright (c) 2015, ARM Limited and Contributors. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * Redistributions of source code must retain the above copyright notice, this
 * list of conditions and the following disclaimer.
 *
 * Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * Neither the name of ARM nor the names of its contributors may be used
 * to endorse or promote products derived from this software without specific
 * prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include <arm_gic.h>
#include <bl_common.h>
#include <stratix10_soc_def.h>

#define ARM_IRQ_SEC_PHY_TIMER		29

#define ARM_IRQ_SEC_SGI_0		8
#define ARM_IRQ_SEC_SGI_1		9
#define ARM_IRQ_SEC_SGI_2		10
#define ARM_IRQ_SEC_SGI_3		11
#define ARM_IRQ_SEC_SGI_4		12
#define ARM_IRQ_SEC_SGI_5		13
#define ARM_IRQ_SEC_SGI_6		14
#define ARM_IRQ_SEC_SGI_7		15

#define PLAT_GROUP0_IRQS		ARM_IRQ_SEC_SGI_0,		\
					ARM_IRQ_SEC_SGI_6

#define PLAT_GROUP1_IRQS		ARM_IRQ_SEC_PHY_TIMER,		\
					ARM_IRQ_SEC_SGI_1,		\
					ARM_IRQ_SEC_SGI_2,		\
					ARM_IRQ_SEC_SGI_3,		\
					ARM_IRQ_SEC_SGI_4,		\
					ARM_IRQ_SEC_SGI_5,		\
					ARM_IRQ_SEC_SGI_7



const unsigned int irq_sec_array[] = {
	PLAT_GROUP0_IRQS,
	PLAT_GROUP1_IRQS
};


void plat_gic_driver_init(void)
{
	arm_gic_init(PLAT_GICC_BASE,
		     PLAT_GICD_BASE,
		     PLAT_GICR_BASE,
		     irq_sec_array,
		     ARRAY_SIZE(irq_sec_array));
}

/******************************************************************************
 * ARM common helper to initialize the GIC.
 *****************************************************************************/
void plat_arm_gic_init(void)
{
	arm_gic_setup();
}

