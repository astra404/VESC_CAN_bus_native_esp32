#include <Arduino.h> //required for PD# definitions

class CANV
{

public:

#define CAN_RX 21                              // Set RX to pin 21
#define CAN_TX 22                              // Set TX to pin 22

long unsigned int rxId;
unsigned char len = 0;
unsigned char len1 = 0;
unsigned char rxBuf[8];
char msgString[128];// Array to store serial string


float inpVoltage, dutyCycleNow, avgInputCurrent, avgMotorCurrent, tempFET, tempMotor;
long erpm, WattHours;


void initialize();
void spin();
void get_frame(); // populates rxId and rxBuf with latest can frame 
void can_send(byte data[8]); //transmits the send commands to the sensor
void print_raw_can_data(); //output raw can data to terminal (debug)


void vesc_set_duty(float duty);
void vesc_set_current(float current);
void vesc_set_erpm(float erpm);
float process_data_frame_vesc(char datatype, unsigned char byte1, unsigned char byte2);
int hex2int(char buf[]);
bool sendpacket(uint32_t id, uint8_t ext, unsigned int len, uint8_t buf[]);

};
