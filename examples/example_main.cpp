#include <Arduino.h>
#include <CAN.h>
#include "vesc_can_bus_arduino.h"

CANV can;             // get torque sensor data, throttle for now

bool print_realtime_data=1;
long last_print_data;


void setup()
{

    //Serial.begin(9600); // Wired comms from USB port

    can.initialize();

}

void loop()
{
    can.spin();

    can.vesc_set_duty(0.1); //2 amps of current

 
        if (millis() - last_print_data > 1000)
        {
            Serial.print("erpm ");
            Serial.println(can.erpm); 
            Serial.print("voltage ");
            Serial.println(can.inpVoltage);
            Serial.print("dutyCycleNow ");
            Serial.println(can.dutyCycleNow);
            Serial.print("avgInputCurrent ");
            Serial.println(can.avgInputCurrent);
            Serial.print("avgMotorCurrent ");
            Serial.println(can.avgMotorCurrent);
            Serial.print("tempFET ");
            Serial.println(can.tempFET);
            Serial.print("tempMotor ");
            Serial.println(can.tempMotor);
            last_print_data = millis();
            Serial.println("..............................");
            Serial.println();
        }
    delay(5);
}
