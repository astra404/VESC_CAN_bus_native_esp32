**VESC library for CAN bus control using native esp32 CAN bus tranceiver**

![image](https://github.com/craigg96/vesc_can_bus_arduino/blob/main/images/header.png?raw=true "Header")
Tis library is based on craigg96 vesc_can_bus_arduino library (https://github.com/craigg96/vesc_can_bus_arduino). Interpretation of can messages are left the same as it was in craiggs96 library, but instead of MCP2515 driver library it uses native arduino CAN bus library (https://github.com/sandeepmistry/arduino-CAN).
The VESC platform is the gold standard for brushless motor control for skateboards and ebikes. This library allows you to use the can bus instead of UART (see solidgeek vescuart library) to communicate with the VESC which is more reliable and allows the single UART port on most arduinos to be free for debugging.  

## Realtime Data Messages
|     Parameter     |
|:-----------------:|
|        rpm        |
|     inpVoltage    |
|    dutyCycleNow   |
|  avgInputCurrent  |
|  avgMotorCurrent  |
|      tempFET      |
|     tempMotor     |
|     WattHours     |

## Command Messages
|     Parameter     |
|:-----------------:|
|        erpm       |
|      dutycycle    |
|       current     |

To use the library out of the box, the vesc tool must be configured as shown in images/vesc_tool_app_settings.png.
VESC ID = 10
CAN STATUS_MESSAGE_MODE = CAN_STATUS_1_2_3_4_5
CAN Baud Rate = CAN_BAUD_250K

Place the .h and .cpp file in the same folder as the .ino file to use this library with no changes.
# To do
* Add support for multiple VESC esc on the same can bus ( currently only 1 esc is supported). This also includes support for diffrent VESC id's.
* Creagte a method to update the value only whe coresponding can message is recived.
* Add instructions on how to use the library and what are the hardvare options.

LONGSHOT
Add support to all of the vesc can bus features.

# Credits

DEPENDENCIES

* https://github.com/sandeepmistry/arduino-CAN

LICENSE

MIT - https://opensource.org/license/mit/
