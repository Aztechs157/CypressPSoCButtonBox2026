/*******************************************************************************
* File Name: R2L.h  
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

#if !defined(CY_PINS_R2L_H) /* Pins R2L_H */
#define CY_PINS_R2L_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "R2L_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 R2L__PORT == 15 && ((R2L__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    R2L_Write(uint8 value);
void    R2L_SetDriveMode(uint8 mode);
uint8   R2L_ReadDataReg(void);
uint8   R2L_Read(void);
void    R2L_SetInterruptMode(uint16 position, uint16 mode);
uint8   R2L_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the R2L_SetDriveMode() function.
     *  @{
     */
        #define R2L_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define R2L_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define R2L_DM_RES_UP          PIN_DM_RES_UP
        #define R2L_DM_RES_DWN         PIN_DM_RES_DWN
        #define R2L_DM_OD_LO           PIN_DM_OD_LO
        #define R2L_DM_OD_HI           PIN_DM_OD_HI
        #define R2L_DM_STRONG          PIN_DM_STRONG
        #define R2L_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define R2L_MASK               R2L__MASK
#define R2L_SHIFT              R2L__SHIFT
#define R2L_WIDTH              1u

/* Interrupt constants */
#if defined(R2L__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in R2L_SetInterruptMode() function.
     *  @{
     */
        #define R2L_INTR_NONE      (uint16)(0x0000u)
        #define R2L_INTR_RISING    (uint16)(0x0001u)
        #define R2L_INTR_FALLING   (uint16)(0x0002u)
        #define R2L_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define R2L_INTR_MASK      (0x01u) 
#endif /* (R2L__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define R2L_PS                     (* (reg8 *) R2L__PS)
/* Data Register */
#define R2L_DR                     (* (reg8 *) R2L__DR)
/* Port Number */
#define R2L_PRT_NUM                (* (reg8 *) R2L__PRT) 
/* Connect to Analog Globals */                                                  
#define R2L_AG                     (* (reg8 *) R2L__AG)                       
/* Analog MUX bux enable */
#define R2L_AMUX                   (* (reg8 *) R2L__AMUX) 
/* Bidirectional Enable */                                                        
#define R2L_BIE                    (* (reg8 *) R2L__BIE)
/* Bit-mask for Aliased Register Access */
#define R2L_BIT_MASK               (* (reg8 *) R2L__BIT_MASK)
/* Bypass Enable */
#define R2L_BYP                    (* (reg8 *) R2L__BYP)
/* Port wide control signals */                                                   
#define R2L_CTL                    (* (reg8 *) R2L__CTL)
/* Drive Modes */
#define R2L_DM0                    (* (reg8 *) R2L__DM0) 
#define R2L_DM1                    (* (reg8 *) R2L__DM1)
#define R2L_DM2                    (* (reg8 *) R2L__DM2) 
/* Input Buffer Disable Override */
#define R2L_INP_DIS                (* (reg8 *) R2L__INP_DIS)
/* LCD Common or Segment Drive */
#define R2L_LCD_COM_SEG            (* (reg8 *) R2L__LCD_COM_SEG)
/* Enable Segment LCD */
#define R2L_LCD_EN                 (* (reg8 *) R2L__LCD_EN)
/* Slew Rate Control */
#define R2L_SLW                    (* (reg8 *) R2L__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define R2L_PRTDSI__CAPS_SEL       (* (reg8 *) R2L__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define R2L_PRTDSI__DBL_SYNC_IN    (* (reg8 *) R2L__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define R2L_PRTDSI__OE_SEL0        (* (reg8 *) R2L__PRTDSI__OE_SEL0) 
#define R2L_PRTDSI__OE_SEL1        (* (reg8 *) R2L__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define R2L_PRTDSI__OUT_SEL0       (* (reg8 *) R2L__PRTDSI__OUT_SEL0) 
#define R2L_PRTDSI__OUT_SEL1       (* (reg8 *) R2L__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define R2L_PRTDSI__SYNC_OUT       (* (reg8 *) R2L__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(R2L__SIO_CFG)
    #define R2L_SIO_HYST_EN        (* (reg8 *) R2L__SIO_HYST_EN)
    #define R2L_SIO_REG_HIFREQ     (* (reg8 *) R2L__SIO_REG_HIFREQ)
    #define R2L_SIO_CFG            (* (reg8 *) R2L__SIO_CFG)
    #define R2L_SIO_DIFF           (* (reg8 *) R2L__SIO_DIFF)
#endif /* (R2L__SIO_CFG) */

/* Interrupt Registers */
#if defined(R2L__INTSTAT)
    #define R2L_INTSTAT            (* (reg8 *) R2L__INTSTAT)
    #define R2L_SNAP               (* (reg8 *) R2L__SNAP)
    
	#define R2L_0_INTTYPE_REG 		(* (reg8 *) R2L__0__INTTYPE)
#endif /* (R2L__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_R2L_H */


/* [] END OF FILE */
