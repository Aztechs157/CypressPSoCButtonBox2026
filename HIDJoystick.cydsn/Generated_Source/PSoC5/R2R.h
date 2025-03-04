/*******************************************************************************
* File Name: R2R.h  
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

#if !defined(CY_PINS_R2R_H) /* Pins R2R_H */
#define CY_PINS_R2R_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "R2R_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 R2R__PORT == 15 && ((R2R__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    R2R_Write(uint8 value);
void    R2R_SetDriveMode(uint8 mode);
uint8   R2R_ReadDataReg(void);
uint8   R2R_Read(void);
void    R2R_SetInterruptMode(uint16 position, uint16 mode);
uint8   R2R_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the R2R_SetDriveMode() function.
     *  @{
     */
        #define R2R_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define R2R_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define R2R_DM_RES_UP          PIN_DM_RES_UP
        #define R2R_DM_RES_DWN         PIN_DM_RES_DWN
        #define R2R_DM_OD_LO           PIN_DM_OD_LO
        #define R2R_DM_OD_HI           PIN_DM_OD_HI
        #define R2R_DM_STRONG          PIN_DM_STRONG
        #define R2R_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define R2R_MASK               R2R__MASK
#define R2R_SHIFT              R2R__SHIFT
#define R2R_WIDTH              1u

/* Interrupt constants */
#if defined(R2R__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in R2R_SetInterruptMode() function.
     *  @{
     */
        #define R2R_INTR_NONE      (uint16)(0x0000u)
        #define R2R_INTR_RISING    (uint16)(0x0001u)
        #define R2R_INTR_FALLING   (uint16)(0x0002u)
        #define R2R_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define R2R_INTR_MASK      (0x01u) 
#endif /* (R2R__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define R2R_PS                     (* (reg8 *) R2R__PS)
/* Data Register */
#define R2R_DR                     (* (reg8 *) R2R__DR)
/* Port Number */
#define R2R_PRT_NUM                (* (reg8 *) R2R__PRT) 
/* Connect to Analog Globals */                                                  
#define R2R_AG                     (* (reg8 *) R2R__AG)                       
/* Analog MUX bux enable */
#define R2R_AMUX                   (* (reg8 *) R2R__AMUX) 
/* Bidirectional Enable */                                                        
#define R2R_BIE                    (* (reg8 *) R2R__BIE)
/* Bit-mask for Aliased Register Access */
#define R2R_BIT_MASK               (* (reg8 *) R2R__BIT_MASK)
/* Bypass Enable */
#define R2R_BYP                    (* (reg8 *) R2R__BYP)
/* Port wide control signals */                                                   
#define R2R_CTL                    (* (reg8 *) R2R__CTL)
/* Drive Modes */
#define R2R_DM0                    (* (reg8 *) R2R__DM0) 
#define R2R_DM1                    (* (reg8 *) R2R__DM1)
#define R2R_DM2                    (* (reg8 *) R2R__DM2) 
/* Input Buffer Disable Override */
#define R2R_INP_DIS                (* (reg8 *) R2R__INP_DIS)
/* LCD Common or Segment Drive */
#define R2R_LCD_COM_SEG            (* (reg8 *) R2R__LCD_COM_SEG)
/* Enable Segment LCD */
#define R2R_LCD_EN                 (* (reg8 *) R2R__LCD_EN)
/* Slew Rate Control */
#define R2R_SLW                    (* (reg8 *) R2R__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define R2R_PRTDSI__CAPS_SEL       (* (reg8 *) R2R__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define R2R_PRTDSI__DBL_SYNC_IN    (* (reg8 *) R2R__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define R2R_PRTDSI__OE_SEL0        (* (reg8 *) R2R__PRTDSI__OE_SEL0) 
#define R2R_PRTDSI__OE_SEL1        (* (reg8 *) R2R__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define R2R_PRTDSI__OUT_SEL0       (* (reg8 *) R2R__PRTDSI__OUT_SEL0) 
#define R2R_PRTDSI__OUT_SEL1       (* (reg8 *) R2R__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define R2R_PRTDSI__SYNC_OUT       (* (reg8 *) R2R__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(R2R__SIO_CFG)
    #define R2R_SIO_HYST_EN        (* (reg8 *) R2R__SIO_HYST_EN)
    #define R2R_SIO_REG_HIFREQ     (* (reg8 *) R2R__SIO_REG_HIFREQ)
    #define R2R_SIO_CFG            (* (reg8 *) R2R__SIO_CFG)
    #define R2R_SIO_DIFF           (* (reg8 *) R2R__SIO_DIFF)
#endif /* (R2R__SIO_CFG) */

/* Interrupt Registers */
#if defined(R2R__INTSTAT)
    #define R2R_INTSTAT            (* (reg8 *) R2R__INTSTAT)
    #define R2R_SNAP               (* (reg8 *) R2R__SNAP)
    
	#define R2R_0_INTTYPE_REG 		(* (reg8 *) R2R__0__INTTYPE)
#endif /* (R2R__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_R2R_H */


/* [] END OF FILE */
