#include "Arduino.h"
/* Pin Configuration Class */
class Configure{
    public: 
        Configure(int pin, int pin_mode);
        void Set_Pin(int pin);
        void Set_Mode(int pin_mode);
        int Get_Pin(void);
        int Get_Mode(void);
        void Init_Pin(void);
    private:
        int pin;
        int pin_mode;
};

Configure::Configure(int pin, int pin_mode){
     this->pin = pin;
     this->pin_mode = pin_mode;
     this->Init_Pin();
     
  }
void Configure::Set_Pin(int pin){
    this->pin = pin;  
}
void Configure::Set_Mode(int pin_mode){
    this->pin_mode = pin_mode;  
}
int Configure::Get_Pin(void){
    return this->pin;  
}
int Configure::Get_Mode(void){
    return this->pin_mode;  
}
void Configure::Init_Pin(void){
    pinMode(Get_Pin(), Get_Mode());
}

/* LED Class */
class LED: public Configure{
    public:
        LED(int pin, int pin_mode, int voltage);
        void Set_Voltage(int voltage);
        int Get_Voltage(void);
        void Turn_On(void);
        void Turn_Off(void);
        int Status();
        void Blink(int duration); 
        void Init_LED(void);
    private:
        int voltage;
};

LED::LED(int pin, int pin_mode, int voltage): Configure(pin, pin_mode){
    this->voltage = voltage;
    this-> Init_LED();
}

void LED::Set_Voltage(int voltage){
  this->voltage = voltage;
  }
int LED::Get_Voltage(void){
  return this->voltage;
  }
void LED::Turn_On(void){
    this->voltage = HIGH;
    digitalWrite(Get_Pin(), Get_Voltage());
    
}
void LED::Turn_Off(void){
    this->voltage = LOW;
    digitalWrite(Get_Pin(), Get_Voltage());
}
int LED:Status(){
    return this->voltage;  
}
void LED::Blink(int duration){
    this->voltage = HIGH;
    digitalWrite(Get_Pin(), Get_Voltage());
    delay(duration);
    this->voltage = LOW;
    digitalWrite(Get_Pin(), Get_Voltage());
    delay(duration);
}
void LED::Init_LED(void){
    digitalWrite(Get_Pin(), Get_Voltage());  
}

LED* led;
Configure* pin;


void setup() {
 Serial.begin(115200);
 while(!Serial);
 led = new LED(13, OUTPUT, LOW);
}

void loop() {
    led->Blink(1000);
    
}
