/*******************************************************************************
* File Name: R4R.h  
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

#if !defined(CY_PINS_R4R_H) /* Pins R4R_H */
#define CY_PINS_R4R_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "R4R_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 R4R__PORT == 15 && ((R4R__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    R4R_Write(uint8 value);
void    R4R_SetDriveMode(uint8 mode);
uint8   R4R_ReadDataReg(void);
uint8   R4R_Read(void);
void    R4R_SetInterruptMode(uint16 position, uint16 mode);
uint8   R4R_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the R4R_SetDriveMode() function.
     *  @{
     */
        #define R4R_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define R4R_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define R4R_DM_RES_UP          PIN_DM_RES_UP
        #define R4R_DM_RES_DWN         PIN_DM_RES_DWN
        #define R4R_DM_OD_LO           PIN_DM_OD_LO
        #define R4R_DM_OD_HI           PIN_DM_OD_HI
        #define R4R_DM_STRONG          PIN_DM_STRONG
        #define R4R_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define R4R_MASK               R4R__MASK
#define R4R_SHIFT              R4R__SHIFT
#define R4R_WIDTH              1u

/* Interrupt constants */
#if defined(R4R__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in R4R_SetInterruptMode() function.
     *  @{
     */
        #define R4R_INTR_NONE      (uint16)(0x0000u)
        #define R4R_INTR_RISING    (uint16)(0x0001u)
        #define R4R_INTR_FALLING   (uint16)(0x0002u)
        #define R4R_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define R4R_INTR_MASK      (0x01u) 
#endif /* (R4R__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define R4R_PS                     (* (reg8 *) R4R__PS)
/* Data Register */
#define R4R_DR                     (* (reg8 *) R4R__DR)
/* Port Number */
#define R4R_PRT_NUM                (* (reg8 *) R4R__PRT) 
/* Connect to Analog Globals */                                                  
#define R4R_AG                     (* (reg8 *) R4R__AG)                       
/* Analog MUX bux enable */
#define R4R_AMUX                   (* (reg8 *) R4R__AMUX) 
/* Bidirectional Enable */                                                        
#define R4R_BIE                    (* (reg8 *) R4R__BIE)
/* Bit-mask for Aliased Register Access */
#define R4R_BIT_MASK               (* (reg8 *) R4R__BIT_MASK)
/* Bypass Enable */
#define R4R_BYP                    (* (reg8 *) R4R__BYP)
/* Port wide control signals */                                                   
#define R4R_CTL                    (* (reg8 *) R4R__CTL)
/* Drive Modes */
#define R4R_DM0                    (* (reg8 *) R4R__DM0) 
#define R4R_DM1                    (* (reg8 *) R4R__DM1)
#define R4R_DM2                    (* (reg8 *) R4R__DM2) 
/* Input Buffer Disable Override */
#define R4R_INP_DIS                (* (reg8 *) R4R__INP_DIS)
/* LCD Common or Segment Drive */
#define R4R_LCD_COM_SEG            (* (reg8 *) R4R__LCD_COM_SEG)
/* Enable Segment LCD */
#define R4R_LCD_EN                 (* (reg8 *) R4R__LCD_EN)
/* Slew Rate Control */
#define R4R_SLW                    (* (reg8 *) R4R__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define R4R_PRTDSI__CAPS_SEL       (* (reg8 *) R4R__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define R4R_PRTDSI__DBL_SYNC_IN    (* (reg8 *) R4R__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define R4R_PRTDSI__OE_SEL0        (* (reg8 *) R4R__PRTDSI__OE_SEL0) 
#define R4R_PRTDSI__OE_SEL1        (* (reg8 *) R4R__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define R4R_PRTDSI__OUT_SEL0       (* (reg8 *) R4R__PRTDSI__OUT_SEL0) 
#define R4R_PRTDSI__OUT_SEL1       (* (reg8 *) R4R__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define R4R_PRTDSI__SYNC_OUT       (* (reg8 *) R4R__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(R4R__SIO_CFG)
    #define R4R_SIO_HYST_EN        (* (reg8 *) R4R__SIO_HYST_EN)
    #define R4R_SIO_REG_HIFREQ     (* (reg8 *) R4R__SIO_REG_HIFREQ)
    #define R4R_SIO_CFG            (* (reg8 *) R4R__SIO_CFG)
    #define R4R_SIO_DIFF           (* (reg8 *) R4R__SIO_DIFF)
#endif /* (R4R__SIO_CFG) */

/* Interrupt Registers */
#if defined(R4R__INTSTAT)
    #define R4R_INTSTAT            (* (reg8 *) R4R__INTSTAT)
    #define R4R_SNAP               (* (reg8 *) R4R__SNAP)
    
	#define R4R_0_INTTYPE_REG 		(* (reg8 *) R4R__0__INTTYPE)
#endif /* (R4R__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_R4R_H */


/* [] END OF FILE */
