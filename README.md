# CypressPSoCButtonBox2026
This code allows a **Cypress PSoC 5LP** (model CY8KIT-059) to act as an **HID Joystick** for use with the ***FIRST* Robotics Competition Driver Station**. This particular box was designed to control Team 157 AZTECHS's robot for the REBUILT season, Sunstone. The box contains **4 toggle switches** and **6 momentary pushbuttons**, used for controlling the slapdown intake subsystem, dynamically modifying the shooter flywheel's velocity, and several manual subsystem overrides. This button box exists *in addition to* the operator controller, used for performing manual mechanism control after using the button box's switches to enable overrides.
### Files of Note
- `HIDJoystick.cyprj`
    Project to be opened in **PSoC creator**. GUI for editing `.cy*` files
- `HIDJoystick.cydwr`
    Used for pin assignment in PSoC creator.
- `TopDesign.cysch`
    Used to design layout and define pins/components.
- `main.c`
    Translates button presses to HID packets.
### (Re)Configuration Guide
This button box contains 6 pushbuttons and 4 toggle switches, all treated as digital IO pins. It can be repurposed to support any amount of buttons that the PSoC can physically support by assigning pins/ports in PSoC creator and updating `main.c` to send the appropriate amount of bits in the HID packet.

What you'll need:
- a Windows PC/laptop with at least 1 USB-A port
- [Cypress PSoC Creator](https://softwaretools.infineon.com/tools/com.ifx.tb.tool.psoccreator) (and a myInfineon account) 
- .NET Framework 3.5
- Microsoft VC redist 2013
- Text editor (optional, as PSoC creator has a built-in editor)
---
Guide coming soon!
<!--To reconfigure the box to use a different amount of buttons:
- Increase the size of `Joystick_Data` to fit your button count (1 bit per button, increase by 1 every 8 buttons. Empty bits are ignored.)
- Open `HIDJoystick.cyprj` in PSoC creator, then open `TopDesign.cysch`.-->
