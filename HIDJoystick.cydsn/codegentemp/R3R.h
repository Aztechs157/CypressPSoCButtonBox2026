/*******************************************************************************
* File Name: R3R.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_R3R_H) /* Pins R3R_H */
#define CY_PINS_R3R_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "R3R_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 R3R__PORT == 15 && ((R3R__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    R3R_Write(uint8 value);
void    R3R_SetDriveMode(uint8 mode);
uint8   R3R_ReadDataReg(void);
uint8   R3R_Read(void);
void    R3R_SetInterruptMode(uint16 position, uint16 mode);
uint8   R3R_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the R3R_SetDriveMode() function.
     *  @{
     */
        #define R3R_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define R3R_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define R3R_DM_RES_UP          PIN_DM_RES_UP
        #define R3R_DM_RES_DWN         PIN_DM_RES_DWN
        #define R3R_DM_OD_LO           PIN_DM_OD_LO
        #define R3R_DM_OD_HI           PIN_DM_OD_HI
        #define R3R_DM_STRONG          PIN_DM_STRONG
        #define R3R_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define R3R_MASK               R3R__MASK
#define R3R_SHIFT              R3R__SHIFT
#define R3R_WIDTH              1u

/* Interrupt constants */
#if defined(R3R__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in R3R_SetInterruptMode() function.
     *  @{
     */
        #define R3R_INTR_NONE      (uint16)(0x0000u)
        #define R3R_INTR_RISING    (uint16)(0x0001u)
        #define R3R_INTR_FALLING   (uint16)(0x0002u)
        #define R3R_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define R3R_INTR_MASK      (0x01u) 
#endif /* (R3R__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define R3R_PS                     (* (reg8 *) R3R__PS)
/* Data Register */
#define R3R_DR                     (* (reg8 *) R3R__DR)
/* Port Number */
#define R3R_PRT_NUM                (* (reg8 *) R3R__PRT) 
/* Connect to Analog Globals */                                                  
#define R3R_AG                     (* (reg8 *) R3R__AG)                       
/* Analog MUX bux enable */
#define R3R_AMUX                   (* (reg8 *) R3R__AMUX) 
/* Bidirectional Enable */                                                        
#define R3R_BIE                    (* (reg8 *) R3R__BIE)
/* Bit-mask for Aliased Register Access */
#define R3R_BIT_MASK               (* (reg8 *) R3R__BIT_MASK)
/* Bypass Enable */
#define R3R_BYP                    (* (reg8 *) R3R__BYP)
/* Port wide control signals */                                                   
#define R3R_CTL                    (* (reg8 *) R3R__CTL)
/* Drive Modes */
#define R3R_DM0                    (* (reg8 *) R3R__DM0) 
#define R3R_DM1                    (* (reg8 *) R3R__DM1)
#define R3R_DM2                    (* (reg8 *) R3R__DM2) 
/* Input Buffer Disable Override */
#define R3R_INP_DIS                (* (reg8 *) R3R__INP_DIS)
/* LCD Common or Segment Drive */
#define R3R_LCD_COM_SEG            (* (reg8 *) R3R__LCD_COM_SEG)
/* Enable Segment LCD */
#define R3R_LCD_EN                 (* (reg8 *) R3R__LCD_EN)
/* Slew Rate Control */
#define R3R_SLW                    (* (reg8 *) R3R__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define R3R_PRTDSI__CAPS_SEL       (* (reg8 *) R3R__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define R3R_PRTDSI__DBL_SYNC_IN    (* (reg8 *) R3R__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define R3R_PRTDSI__OE_SEL0        (* (reg8 *) R3R__PRTDSI__OE_SEL0) 
#define R3R_PRTDSI__OE_SEL1        (* (reg8 *) R3R__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define R3R_PRTDSI__OUT_SEL0       (* (reg8 *) R3R__PRTDSI__OUT_SEL0) 
#define R3R_PRTDSI__OUT_SEL1       (* (reg8 *) R3R__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define R3R_PRTDSI__SYNC_OUT       (* (reg8 *) R3R__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(R3R__SIO_CFG)
    #define R3R_SIO_HYST_EN        (* (reg8 *) R3R__SIO_HYST_EN)
    #define R3R_SIO_REG_HIFREQ     (* (reg8 *) R3R__SIO_REG_HIFREQ)
    #define R3R_SIO_CFG            (* (reg8 *) R3R__SIO_CFG)
    #define R3R_SIO_DIFF           (* (reg8 *) R3R__SIO_DIFF)
#endif /* (R3R__SIO_CFG) */

/* Interrupt Registers */
#if defined(R3R__INTSTAT)
    #define R3R_INTSTAT            (* (reg8 *) R3R__INTSTAT)
    #define R3R_SNAP               (* (reg8 *) R3R__SNAP)
    
	#define R3R_0_INTTYPE_REG 		(* (reg8 *) R3R__0__INTTYPE)
#endif /* (R3R__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_R3R_H */


/* [] END OF FILE */
