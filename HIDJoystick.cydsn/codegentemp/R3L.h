/*******************************************************************************
* File Name: R3L.h  
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

#if !defined(CY_PINS_R3L_H) /* Pins R3L_H */
#define CY_PINS_R3L_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "R3L_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 R3L__PORT == 15 && ((R3L__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    R3L_Write(uint8 value);
void    R3L_SetDriveMode(uint8 mode);
uint8   R3L_ReadDataReg(void);
uint8   R3L_Read(void);
void    R3L_SetInterruptMode(uint16 position, uint16 mode);
uint8   R3L_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the R3L_SetDriveMode() function.
     *  @{
     */
        #define R3L_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define R3L_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define R3L_DM_RES_UP          PIN_DM_RES_UP
        #define R3L_DM_RES_DWN         PIN_DM_RES_DWN
        #define R3L_DM_OD_LO           PIN_DM_OD_LO
        #define R3L_DM_OD_HI           PIN_DM_OD_HI
        #define R3L_DM_STRONG          PIN_DM_STRONG
        #define R3L_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define R3L_MASK               R3L__MASK
#define R3L_SHIFT              R3L__SHIFT
#define R3L_WIDTH              1u

/* Interrupt constants */
#if defined(R3L__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in R3L_SetInterruptMode() function.
     *  @{
     */
        #define R3L_INTR_NONE      (uint16)(0x0000u)
        #define R3L_INTR_RISING    (uint16)(0x0001u)
        #define R3L_INTR_FALLING   (uint16)(0x0002u)
        #define R3L_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define R3L_INTR_MASK      (0x01u) 
#endif /* (R3L__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define R3L_PS                     (* (reg8 *) R3L__PS)
/* Data Register */
#define R3L_DR                     (* (reg8 *) R3L__DR)
/* Port Number */
#define R3L_PRT_NUM                (* (reg8 *) R3L__PRT) 
/* Connect to Analog Globals */                                                  
#define R3L_AG                     (* (reg8 *) R3L__AG)                       
/* Analog MUX bux enable */
#define R3L_AMUX                   (* (reg8 *) R3L__AMUX) 
/* Bidirectional Enable */                                                        
#define R3L_BIE                    (* (reg8 *) R3L__BIE)
/* Bit-mask for Aliased Register Access */
#define R3L_BIT_MASK               (* (reg8 *) R3L__BIT_MASK)
/* Bypass Enable */
#define R3L_BYP                    (* (reg8 *) R3L__BYP)
/* Port wide control signals */                                                   
#define R3L_CTL                    (* (reg8 *) R3L__CTL)
/* Drive Modes */
#define R3L_DM0                    (* (reg8 *) R3L__DM0) 
#define R3L_DM1                    (* (reg8 *) R3L__DM1)
#define R3L_DM2                    (* (reg8 *) R3L__DM2) 
/* Input Buffer Disable Override */
#define R3L_INP_DIS                (* (reg8 *) R3L__INP_DIS)
/* LCD Common or Segment Drive */
#define R3L_LCD_COM_SEG            (* (reg8 *) R3L__LCD_COM_SEG)
/* Enable Segment LCD */
#define R3L_LCD_EN                 (* (reg8 *) R3L__LCD_EN)
/* Slew Rate Control */
#define R3L_SLW                    (* (reg8 *) R3L__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define R3L_PRTDSI__CAPS_SEL       (* (reg8 *) R3L__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define R3L_PRTDSI__DBL_SYNC_IN    (* (reg8 *) R3L__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define R3L_PRTDSI__OE_SEL0        (* (reg8 *) R3L__PRTDSI__OE_SEL0) 
#define R3L_PRTDSI__OE_SEL1        (* (reg8 *) R3L__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define R3L_PRTDSI__OUT_SEL0       (* (reg8 *) R3L__PRTDSI__OUT_SEL0) 
#define R3L_PRTDSI__OUT_SEL1       (* (reg8 *) R3L__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define R3L_PRTDSI__SYNC_OUT       (* (reg8 *) R3L__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(R3L__SIO_CFG)
    #define R3L_SIO_HYST_EN        (* (reg8 *) R3L__SIO_HYST_EN)
    #define R3L_SIO_REG_HIFREQ     (* (reg8 *) R3L__SIO_REG_HIFREQ)
    #define R3L_SIO_CFG            (* (reg8 *) R3L__SIO_CFG)
    #define R3L_SIO_DIFF           (* (reg8 *) R3L__SIO_DIFF)
#endif /* (R3L__SIO_CFG) */

/* Interrupt Registers */
#if defined(R3L__INTSTAT)
    #define R3L_INTSTAT            (* (reg8 *) R3L__INTSTAT)
    #define R3L_SNAP               (* (reg8 *) R3L__SNAP)
    
	#define R3L_0_INTTYPE_REG 		(* (reg8 *) R3L__0__INTTYPE)
#endif /* (R3L__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_R3L_H */


/* [] END OF FILE */
