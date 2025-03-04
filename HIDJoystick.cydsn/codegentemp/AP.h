/*******************************************************************************
* File Name: AP.h  
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

#if !defined(CY_PINS_AP_H) /* Pins AP_H */
#define CY_PINS_AP_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "AP_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 AP__PORT == 15 && ((AP__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    AP_Write(uint8 value);
void    AP_SetDriveMode(uint8 mode);
uint8   AP_ReadDataReg(void);
uint8   AP_Read(void);
void    AP_SetInterruptMode(uint16 position, uint16 mode);
uint8   AP_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the AP_SetDriveMode() function.
     *  @{
     */
        #define AP_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define AP_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define AP_DM_RES_UP          PIN_DM_RES_UP
        #define AP_DM_RES_DWN         PIN_DM_RES_DWN
        #define AP_DM_OD_LO           PIN_DM_OD_LO
        #define AP_DM_OD_HI           PIN_DM_OD_HI
        #define AP_DM_STRONG          PIN_DM_STRONG
        #define AP_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define AP_MASK               AP__MASK
#define AP_SHIFT              AP__SHIFT
#define AP_WIDTH              1u

/* Interrupt constants */
#if defined(AP__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in AP_SetInterruptMode() function.
     *  @{
     */
        #define AP_INTR_NONE      (uint16)(0x0000u)
        #define AP_INTR_RISING    (uint16)(0x0001u)
        #define AP_INTR_FALLING   (uint16)(0x0002u)
        #define AP_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define AP_INTR_MASK      (0x01u) 
#endif /* (AP__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define AP_PS                     (* (reg8 *) AP__PS)
/* Data Register */
#define AP_DR                     (* (reg8 *) AP__DR)
/* Port Number */
#define AP_PRT_NUM                (* (reg8 *) AP__PRT) 
/* Connect to Analog Globals */                                                  
#define AP_AG                     (* (reg8 *) AP__AG)                       
/* Analog MUX bux enable */
#define AP_AMUX                   (* (reg8 *) AP__AMUX) 
/* Bidirectional Enable */                                                        
#define AP_BIE                    (* (reg8 *) AP__BIE)
/* Bit-mask for Aliased Register Access */
#define AP_BIT_MASK               (* (reg8 *) AP__BIT_MASK)
/* Bypass Enable */
#define AP_BYP                    (* (reg8 *) AP__BYP)
/* Port wide control signals */                                                   
#define AP_CTL                    (* (reg8 *) AP__CTL)
/* Drive Modes */
#define AP_DM0                    (* (reg8 *) AP__DM0) 
#define AP_DM1                    (* (reg8 *) AP__DM1)
#define AP_DM2                    (* (reg8 *) AP__DM2) 
/* Input Buffer Disable Override */
#define AP_INP_DIS                (* (reg8 *) AP__INP_DIS)
/* LCD Common or Segment Drive */
#define AP_LCD_COM_SEG            (* (reg8 *) AP__LCD_COM_SEG)
/* Enable Segment LCD */
#define AP_LCD_EN                 (* (reg8 *) AP__LCD_EN)
/* Slew Rate Control */
#define AP_SLW                    (* (reg8 *) AP__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define AP_PRTDSI__CAPS_SEL       (* (reg8 *) AP__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define AP_PRTDSI__DBL_SYNC_IN    (* (reg8 *) AP__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define AP_PRTDSI__OE_SEL0        (* (reg8 *) AP__PRTDSI__OE_SEL0) 
#define AP_PRTDSI__OE_SEL1        (* (reg8 *) AP__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define AP_PRTDSI__OUT_SEL0       (* (reg8 *) AP__PRTDSI__OUT_SEL0) 
#define AP_PRTDSI__OUT_SEL1       (* (reg8 *) AP__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define AP_PRTDSI__SYNC_OUT       (* (reg8 *) AP__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(AP__SIO_CFG)
    #define AP_SIO_HYST_EN        (* (reg8 *) AP__SIO_HYST_EN)
    #define AP_SIO_REG_HIFREQ     (* (reg8 *) AP__SIO_REG_HIFREQ)
    #define AP_SIO_CFG            (* (reg8 *) AP__SIO_CFG)
    #define AP_SIO_DIFF           (* (reg8 *) AP__SIO_DIFF)
#endif /* (AP__SIO_CFG) */

/* Interrupt Registers */
#if defined(AP__INTSTAT)
    #define AP_INTSTAT            (* (reg8 *) AP__INTSTAT)
    #define AP_SNAP               (* (reg8 *) AP__SNAP)
    
	#define AP_0_INTTYPE_REG 		(* (reg8 *) AP__0__INTTYPE)
#endif /* (AP__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_AP_H */


/* [] END OF FILE */
