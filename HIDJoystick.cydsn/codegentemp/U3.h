/*******************************************************************************
* File Name: U3.h  
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

#if !defined(CY_PINS_U3_H) /* Pins U3_H */
#define CY_PINS_U3_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "U3_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 U3__PORT == 15 && ((U3__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    U3_Write(uint8 value);
void    U3_SetDriveMode(uint8 mode);
uint8   U3_ReadDataReg(void);
uint8   U3_Read(void);
void    U3_SetInterruptMode(uint16 position, uint16 mode);
uint8   U3_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the U3_SetDriveMode() function.
     *  @{
     */
        #define U3_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define U3_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define U3_DM_RES_UP          PIN_DM_RES_UP
        #define U3_DM_RES_DWN         PIN_DM_RES_DWN
        #define U3_DM_OD_LO           PIN_DM_OD_LO
        #define U3_DM_OD_HI           PIN_DM_OD_HI
        #define U3_DM_STRONG          PIN_DM_STRONG
        #define U3_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define U3_MASK               U3__MASK
#define U3_SHIFT              U3__SHIFT
#define U3_WIDTH              1u

/* Interrupt constants */
#if defined(U3__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in U3_SetInterruptMode() function.
     *  @{
     */
        #define U3_INTR_NONE      (uint16)(0x0000u)
        #define U3_INTR_RISING    (uint16)(0x0001u)
        #define U3_INTR_FALLING   (uint16)(0x0002u)
        #define U3_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define U3_INTR_MASK      (0x01u) 
#endif /* (U3__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define U3_PS                     (* (reg8 *) U3__PS)
/* Data Register */
#define U3_DR                     (* (reg8 *) U3__DR)
/* Port Number */
#define U3_PRT_NUM                (* (reg8 *) U3__PRT) 
/* Connect to Analog Globals */                                                  
#define U3_AG                     (* (reg8 *) U3__AG)                       
/* Analog MUX bux enable */
#define U3_AMUX                   (* (reg8 *) U3__AMUX) 
/* Bidirectional Enable */                                                        
#define U3_BIE                    (* (reg8 *) U3__BIE)
/* Bit-mask for Aliased Register Access */
#define U3_BIT_MASK               (* (reg8 *) U3__BIT_MASK)
/* Bypass Enable */
#define U3_BYP                    (* (reg8 *) U3__BYP)
/* Port wide control signals */                                                   
#define U3_CTL                    (* (reg8 *) U3__CTL)
/* Drive Modes */
#define U3_DM0                    (* (reg8 *) U3__DM0) 
#define U3_DM1                    (* (reg8 *) U3__DM1)
#define U3_DM2                    (* (reg8 *) U3__DM2) 
/* Input Buffer Disable Override */
#define U3_INP_DIS                (* (reg8 *) U3__INP_DIS)
/* LCD Common or Segment Drive */
#define U3_LCD_COM_SEG            (* (reg8 *) U3__LCD_COM_SEG)
/* Enable Segment LCD */
#define U3_LCD_EN                 (* (reg8 *) U3__LCD_EN)
/* Slew Rate Control */
#define U3_SLW                    (* (reg8 *) U3__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define U3_PRTDSI__CAPS_SEL       (* (reg8 *) U3__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define U3_PRTDSI__DBL_SYNC_IN    (* (reg8 *) U3__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define U3_PRTDSI__OE_SEL0        (* (reg8 *) U3__PRTDSI__OE_SEL0) 
#define U3_PRTDSI__OE_SEL1        (* (reg8 *) U3__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define U3_PRTDSI__OUT_SEL0       (* (reg8 *) U3__PRTDSI__OUT_SEL0) 
#define U3_PRTDSI__OUT_SEL1       (* (reg8 *) U3__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define U3_PRTDSI__SYNC_OUT       (* (reg8 *) U3__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(U3__SIO_CFG)
    #define U3_SIO_HYST_EN        (* (reg8 *) U3__SIO_HYST_EN)
    #define U3_SIO_REG_HIFREQ     (* (reg8 *) U3__SIO_REG_HIFREQ)
    #define U3_SIO_CFG            (* (reg8 *) U3__SIO_CFG)
    #define U3_SIO_DIFF           (* (reg8 *) U3__SIO_DIFF)
#endif /* (U3__SIO_CFG) */

/* Interrupt Registers */
#if defined(U3__INTSTAT)
    #define U3_INTSTAT            (* (reg8 *) U3__INTSTAT)
    #define U3_SNAP               (* (reg8 *) U3__SNAP)
    
	#define U3_0_INTTYPE_REG 		(* (reg8 *) U3__0__INTTYPE)
#endif /* (U3__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_U3_H */


/* [] END OF FILE */
