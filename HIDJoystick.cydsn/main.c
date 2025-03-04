/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include <project.h>
void StartUp (void);
void ReadJoystick (void);
void ReadButtons (void);
void setBit(uint8, uint8);
static int8 Joystick_Data[3] = {0, 0, 0};
static unsigned char Buttons1;
static unsigned char Buttons2;
static unsigned char Buttons3;


int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    StartUp();
 for(;;)
 {
 /* Waits for ACK from the host */
 while(!USBFS_1_bGetEPAckState(1));
 ReadButtons();
 /* Delay added to periodically send data */
 CyDelay(10);
 Joystick_Data[0] = Buttons1;
 Joystick_Data[1] = Buttons2;
 Joystick_Data[2] = Buttons3;

 /* Loads EP1 for a IN transfer to PC */
 USBFS_1_LoadInEP(
 1, (uint8 *)Joystick_Data, 3);
 }
}
void StartUp (void)
{
 CYGlobalIntEnable;
 LCD_Char_1_Start();
 LCD_Char_1_Position(0,0);
 LCD_Char_1_PrintString("PSoC 3 USB HID");
 LCD_Char_1_Position(1,0);
 LCD_Char_1_PrintString("Joystick Demo");
 /* Activates and configs the USB component */
 USBFS_1_Start(0, USBFS_1_5V_OPERATION);
 /* Waits for configuration data from host */
 while(!USBFS_1_bGetConfiguration());
 /* Begins initial communication with PC */
 USBFS_1_LoadInEP(
 1, (uint8 *)Joystick_Data, 3);
}
void ReadButtons (void)
{
    setBit(0, !C1_Read());
    setBit(1, !C2_Read());
    setBit(2, !C3_Read());
    setBit(3, !C4_Read());
    setBit(4, !C5_Read());
    setBit(5, SW1_Read());
    setBit(6, !R4L_Read());
    setBit(7, !R4R_Read());
    setBit(8, !R3L_Read());
    setBit(9, !R3R_Read());
    setBit(10, !R2L_Read());
    setBit(11, !R2R_Read());
    setBit(12, !R1_Read());
    setBit(13, !AH_Read());
    setBit(14, !AL_Read());
    setBit(15, !AP_Read());
    setBit(16, !U1_Read());
    setBit(17, !U2_Read());
    setBit(18, !U3_Read());
}

void setBit(uint8 bitNum, uint8 pinRead) {
    if (bitNum < 8) {
        
        if (pinRead != 0) {
            Buttons1 |= (0x01 << bitNum);
        }
        else {
            Buttons1 &= ~(0x01 << bitNum);
        }
    }
    else if (bitNum < 16) {
        bitNum -= 8;
        if (pinRead != 0) {
            Buttons2 |= (0x01 << bitNum);
        }
        else {
            Buttons2 &= ~(0x01 << bitNum);
        }
    }
    else {
        bitNum -= 16;
        if (pinRead != 0) {
            Buttons3 |= (0x01 << bitNum);
        }
        else {
            Buttons3 &= ~(0x01 << bitNum);
        }
    }
        
}



/* [] END OF FILE */
