/*******************************************************************************
* File Name: AH.h  
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

#if !defined(CY_PINS_AH_H) /* Pins AH_H */
#define CY_PINS_AH_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "AH_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 AH__PORT == 15 && ((AH__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    AH_Write(uint8 value);
void    AH_SetDriveMode(uint8 mode);
uint8   AH_ReadDataReg(void);
uint8   AH_Read(void);
void    AH_SetInterruptMode(uint16 position, uint16 mode);
uint8   AH_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the AH_SetDriveMode() function.
     *  @{
     */
        #define AH_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define AH_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define AH_DM_RES_UP          PIN_DM_RES_UP
        #define AH_DM_RES_DWN         PIN_DM_RES_DWN
        #define AH_DM_OD_LO           PIN_DM_OD_LO
        #define AH_DM_OD_HI           PIN_DM_OD_HI
        #define AH_DM_STRONG          PIN_DM_STRONG
        #define AH_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define AH_MASK               AH__MASK
#define AH_SHIFT              AH__SHIFT
#define AH_WIDTH              1u

/* Interrupt constants */
#if defined(AH__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in AH_SetInterruptMode() function.
     *  @{
     */
        #define AH_INTR_NONE      (uint16)(0x0000u)
        #define AH_INTR_RISING    (uint16)(0x0001u)
        #define AH_INTR_FALLING   (uint16)(0x0002u)
        #define AH_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define AH_INTR_MASK      (0x01u) 
#endif /* (AH__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define AH_PS                     (* (reg8 *) AH__PS)
/* Data Register */
#define AH_DR                     (* (reg8 *) AH__DR)
/* Port Number */
#define AH_PRT_NUM                (* (reg8 *) AH__PRT) 
/* Connect to Analog Globals */                                                  
#define AH_AG                     (* (reg8 *) AH__AG)                       
/* Analog MUX bux enable */
#define AH_AMUX                   (* (reg8 *) AH__AMUX) 
/* Bidirectional Enable */                                                        
#define AH_BIE                    (* (reg8 *) AH__BIE)
/* Bit-mask for Aliased Register Access */
#define AH_BIT_MASK               (* (reg8 *) AH__BIT_MASK)
/* Bypass Enable */
#define AH_BYP                    (* (reg8 *) AH__BYP)
/* Port wide control signals */                                                   
#define AH_CTL                    (* (reg8 *) AH__CTL)
/* Drive Modes */
#define AH_DM0                    (* (reg8 *) AH__DM0) 
#define AH_DM1                    (* (reg8 *) AH__DM1)
#define AH_DM2                    (* (reg8 *) AH__DM2) 
/* Input Buffer Disable Override */
#define AH_INP_DIS                (* (reg8 *) AH__INP_DIS)
/* LCD Common or Segment Drive */
#define AH_LCD_COM_SEG            (* (reg8 *) AH__LCD_COM_SEG)
/* Enable Segment LCD */
#define AH_LCD_EN                 (* (reg8 *) AH__LCD_EN)
/* Slew Rate Control */
#define AH_SLW                    (* (reg8 *) AH__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define AH_PRTDSI__CAPS_SEL       (* (reg8 *) AH__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define AH_PRTDSI__DBL_SYNC_IN    (* (reg8 *) AH__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define AH_PRTDSI__OE_SEL0        (* (reg8 *) AH__PRTDSI__OE_SEL0) 
#define AH_PRTDSI__OE_SEL1        (* (reg8 *) AH__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define AH_PRTDSI__OUT_SEL0       (* (reg8 *) AH__PRTDSI__OUT_SEL0) 
#define AH_PRTDSI__OUT_SEL1       (* (reg8 *) AH__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define AH_PRTDSI__SYNC_OUT       (* (reg8 *) AH__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(AH__SIO_CFG)
    #define AH_SIO_HYST_EN        (* (reg8 *) AH__SIO_HYST_EN)
    #define AH_SIO_REG_HIFREQ     (* (reg8 *) AH__SIO_REG_HIFREQ)
    #define AH_SIO_CFG            (* (reg8 *) AH__SIO_CFG)
    #define AH_SIO_DIFF           (* (reg8 *) AH__SIO_DIFF)
#endif /* (AH__SIO_CFG) */

/* Interrupt Registers */
#if defined(AH__INTSTAT)
    #define AH_INTSTAT            (* (reg8 *) AH__INTSTAT)
    #define AH_SNAP               (* (reg8 *) AH__SNAP)
    
	#define AH_0_INTTYPE_REG 		(* (reg8 *) AH__0__INTTYPE)
#endif /* (AH__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_AH_H */


/* [] END OF FILE */
