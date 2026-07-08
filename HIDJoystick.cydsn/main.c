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
void ReadButtons (void);
void setBit(uint8, uint8);
static int8 Joystick_Data[2] = {0, 0};
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
 /* Loads EP1 for a IN transfer to PC */
 USBFS_1_LoadInEP(1, (uint8 *)Joystick_Data, 2);
 }
}
void StartUp (void)
{
 CYGlobalIntEnable;
 /* Activates and configs the USB component */
 USBFS_1_Start(0, USBFS_1_5V_OPERATION);
 /* Waits for configuration data from host */
 while(!USBFS_1_bGetConfiguration());
 /* Begins initial communication with PC */
 USBFS_1_LoadInEP(1, (uint8 *)Joystick_Data, 2);
}
void ReadButtons (void)
{
    /* Active low — switch/button closes pin to GND; pull-up reads 0 when pressed, inverted to 1 */
    setBit(0, !SW_A_Read());
    setBit(1, !SW_B_Read());
    setBit(2, !SW_C_Read());
    setBit(3, !SW_D_Read());
    setBit(4, !BTN_1_Read());
    setBit(5, !BTN_2_Read());
    setBit(6, !BTN_3_Read());
    setBit(7, !BTN_4_Read());
    setBit(8, !BTN_5_Read());
    setBit(9, !BTN_6_Read());
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
