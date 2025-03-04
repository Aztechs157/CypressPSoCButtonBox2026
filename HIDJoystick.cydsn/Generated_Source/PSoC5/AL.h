/*******************************************************************************
* File Name: AL.h  
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

#if !defined(CY_PINS_AL_H) /* Pins AL_H */
#define CY_PINS_AL_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "AL_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 AL__PORT == 15 && ((AL__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    AL_Write(uint8 value);
void    AL_SetDriveMode(uint8 mode);
uint8   AL_ReadDataReg(void);
uint8   AL_Read(void);
void    AL_SetInterruptMode(uint16 position, uint16 mode);
uint8   AL_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the AL_SetDriveMode() function.
     *  @{
     */
        #define AL_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define AL_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define AL_DM_RES_UP          PIN_DM_RES_UP
        #define AL_DM_RES_DWN         PIN_DM_RES_DWN
        #define AL_DM_OD_LO           PIN_DM_OD_LO
        #define AL_DM_OD_HI           PIN_DM_OD_HI
        #define AL_DM_STRONG          PIN_DM_STRONG
        #define AL_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define AL_MASK               AL__MASK
#define AL_SHIFT              AL__SHIFT
#define AL_WIDTH              1u

/* Interrupt constants */
#if defined(AL__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in AL_SetInterruptMode() function.
     *  @{
     */
        #define AL_INTR_NONE      (uint16)(0x0000u)
        #define AL_INTR_RISING    (uint16)(0x0001u)
        #define AL_INTR_FALLING   (uint16)(0x0002u)
        #define AL_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define AL_INTR_MASK      (0x01u) 
#endif /* (AL__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define AL_PS                     (* (reg8 *) AL__PS)
/* Data Register */
#define AL_DR                     (* (reg8 *) AL__DR)
/* Port Number */
#define AL_PRT_NUM                (* (reg8 *) AL__PRT) 
/* Connect to Analog Globals */                                                  
#define AL_AG                     (* (reg8 *) AL__AG)                       
/* Analog MUX bux enable */
#define AL_AMUX                   (* (reg8 *) AL__AMUX) 
/* Bidirectional Enable */                                                        
#define AL_BIE                    (* (reg8 *) AL__BIE)
/* Bit-mask for Aliased Register Access */
#define AL_BIT_MASK               (* (reg8 *) AL__BIT_MASK)
/* Bypass Enable */
#define AL_BYP                    (* (reg8 *) AL__BYP)
/* Port wide control signals */                                                   
#define AL_CTL                    (* (reg8 *) AL__CTL)
/* Drive Modes */
#define AL_DM0                    (* (reg8 *) AL__DM0) 
#define AL_DM1                    (* (reg8 *) AL__DM1)
#define AL_DM2                    (* (reg8 *) AL__DM2) 
/* Input Buffer Disable Override */
#define AL_INP_DIS                (* (reg8 *) AL__INP_DIS)
/* LCD Common or Segment Drive */
#define AL_LCD_COM_SEG            (* (reg8 *) AL__LCD_COM_SEG)
/* Enable Segment LCD */
#define AL_LCD_EN                 (* (reg8 *) AL__LCD_EN)
/* Slew Rate Control */
#define AL_SLW                    (* (reg8 *) AL__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define AL_PRTDSI__CAPS_SEL       (* (reg8 *) AL__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define AL_PRTDSI__DBL_SYNC_IN    (* (reg8 *) AL__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define AL_PRTDSI__OE_SEL0        (* (reg8 *) AL__PRTDSI__OE_SEL0) 
#define AL_PRTDSI__OE_SEL1        (* (reg8 *) AL__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define AL_PRTDSI__OUT_SEL0       (* (reg8 *) AL__PRTDSI__OUT_SEL0) 
#define AL_PRTDSI__OUT_SEL1       (* (reg8 *) AL__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define AL_PRTDSI__SYNC_OUT       (* (reg8 *) AL__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(AL__SIO_CFG)
    #define AL_SIO_HYST_EN        (* (reg8 *) AL__SIO_HYST_EN)
    #define AL_SIO_REG_HIFREQ     (* (reg8 *) AL__SIO_REG_HIFREQ)
    #define AL_SIO_CFG            (* (reg8 *) AL__SIO_CFG)
    #define AL_SIO_DIFF           (* (reg8 *) AL__SIO_DIFF)
#endif /* (AL__SIO_CFG) */

/* Interrupt Registers */
#if defined(AL__INTSTAT)
    #define AL_INTSTAT            (* (reg8 *) AL__INTSTAT)
    #define AL_SNAP               (* (reg8 *) AL__SNAP)
    
	#define AL_0_INTTYPE_REG 		(* (reg8 *) AL__0__INTTYPE)
#endif /* (AL__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_AL_H */


/* [] END OF FILE */
