/*******************************************************************************
* File Name: BTN_4.h  
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

#if !defined(CY_PINS_BTN_4_H) /* Pins BTN_4_H */
#define CY_PINS_BTN_4_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "BTN_4_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 BTN_4__PORT == 15 && ((BTN_4__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    BTN_4_Write(uint8 value);
void    BTN_4_SetDriveMode(uint8 mode);
uint8   BTN_4_ReadDataReg(void);
uint8   BTN_4_Read(void);
void    BTN_4_SetInterruptMode(uint16 position, uint16 mode);
uint8   BTN_4_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the BTN_4_SetDriveMode() function.
     *  @{
     */
        #define BTN_4_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define BTN_4_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define BTN_4_DM_RES_UP          PIN_DM_RES_UP
        #define BTN_4_DM_RES_DWN         PIN_DM_RES_DWN
        #define BTN_4_DM_OD_LO           PIN_DM_OD_LO
        #define BTN_4_DM_OD_HI           PIN_DM_OD_HI
        #define BTN_4_DM_STRONG          PIN_DM_STRONG
        #define BTN_4_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define BTN_4_MASK               BTN_4__MASK
#define BTN_4_SHIFT              BTN_4__SHIFT
#define BTN_4_WIDTH              1u

/* Interrupt constants */
#if defined(BTN_4__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in BTN_4_SetInterruptMode() function.
     *  @{
     */
        #define BTN_4_INTR_NONE      (uint16)(0x0000u)
        #define BTN_4_INTR_RISING    (uint16)(0x0001u)
        #define BTN_4_INTR_FALLING   (uint16)(0x0002u)
        #define BTN_4_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define BTN_4_INTR_MASK      (0x01u) 
#endif /* (BTN_4__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define BTN_4_PS                     (* (reg8 *) BTN_4__PS)
/* Data Register */
#define BTN_4_DR                     (* (reg8 *) BTN_4__DR)
/* Port Number */
#define BTN_4_PRT_NUM                (* (reg8 *) BTN_4__PRT) 
/* Connect to Analog Globals */                                                  
#define BTN_4_AG                     (* (reg8 *) BTN_4__AG)                       
/* Analog MUX bux enable */
#define BTN_4_AMUX                   (* (reg8 *) BTN_4__AMUX) 
/* Bidirectional Enable */                                                        
#define BTN_4_BIE                    (* (reg8 *) BTN_4__BIE)
/* Bit-mask for Aliased Register Access */
#define BTN_4_BIT_MASK               (* (reg8 *) BTN_4__BIT_MASK)
/* Bypass Enable */
#define BTN_4_BYP                    (* (reg8 *) BTN_4__BYP)
/* Port wide control signals */                                                   
#define BTN_4_CTL                    (* (reg8 *) BTN_4__CTL)
/* Drive Modes */
#define BTN_4_DM0                    (* (reg8 *) BTN_4__DM0) 
#define BTN_4_DM1                    (* (reg8 *) BTN_4__DM1)
#define BTN_4_DM2                    (* (reg8 *) BTN_4__DM2) 
/* Input Buffer Disable Override */
#define BTN_4_INP_DIS                (* (reg8 *) BTN_4__INP_DIS)
/* LCD Common or Segment Drive */
#define BTN_4_LCD_COM_SEG            (* (reg8 *) BTN_4__LCD_COM_SEG)
/* Enable Segment LCD */
#define BTN_4_LCD_EN                 (* (reg8 *) BTN_4__LCD_EN)
/* Slew Rate Control */
#define BTN_4_SLW                    (* (reg8 *) BTN_4__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define BTN_4_PRTDSI__CAPS_SEL       (* (reg8 *) BTN_4__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define BTN_4_PRTDSI__DBL_SYNC_IN    (* (reg8 *) BTN_4__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define BTN_4_PRTDSI__OE_SEL0        (* (reg8 *) BTN_4__PRTDSI__OE_SEL0) 
#define BTN_4_PRTDSI__OE_SEL1        (* (reg8 *) BTN_4__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define BTN_4_PRTDSI__OUT_SEL0       (* (reg8 *) BTN_4__PRTDSI__OUT_SEL0) 
#define BTN_4_PRTDSI__OUT_SEL1       (* (reg8 *) BTN_4__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define BTN_4_PRTDSI__SYNC_OUT       (* (reg8 *) BTN_4__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(BTN_4__SIO_CFG)
    #define BTN_4_SIO_HYST_EN        (* (reg8 *) BTN_4__SIO_HYST_EN)
    #define BTN_4_SIO_REG_HIFREQ     (* (reg8 *) BTN_4__SIO_REG_HIFREQ)
    #define BTN_4_SIO_CFG            (* (reg8 *) BTN_4__SIO_CFG)
    #define BTN_4_SIO_DIFF           (* (reg8 *) BTN_4__SIO_DIFF)
#endif /* (BTN_4__SIO_CFG) */

/* Interrupt Registers */
#if defined(BTN_4__INTSTAT)
    #define BTN_4_INTSTAT            (* (reg8 *) BTN_4__INTSTAT)
    #define BTN_4_SNAP               (* (reg8 *) BTN_4__SNAP)
    
	#define BTN_4_0_INTTYPE_REG 		(* (reg8 *) BTN_4__0__INTTYPE)
#endif /* (BTN_4__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_BTN_4_H */


/* [] END OF FILE */
