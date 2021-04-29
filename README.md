#### Bluetooth-Operated-Automated-Mini-Vacuum-Cleaner-Using-Arduino
#### ALGORITHM
1.	Switch on the power supply.

2.	Check whether the Motor driver and Bluetooth module got connected.


3.	Turn on mobile Bluetooth
.
4.	Open the Arduino controller Bluetooth app
.
5.	Check whether the Bluetooth module got connected
.
6.	Send commands from the mobile to which accordingly the device will operate
.
7.	Change the direction and movement of the device according to your wish.



#### code :
int IN1 = 2; 
int IN2 = 3; 
int IN3 = 4;
int IN4= 5;

int state;
int flag=0;        //makes sure that the serial only prints once the state
 
void setup() {
    // sets the pins as outputs:
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4,OUTPUT);
    // sets enablePin high so that motor can turn on:
    //digitalWrite(enablePin, HIGH);
    // initialize serial communication at 9600 bits per second:
    Serial.begin(9600);
}
void loop() {
    //if some date is sent, reads it and saves in state
   if(Serial.available() > 0)
   {     
      state = Serial.read();   
      flag=0;
      }
    if (state == '3')
    {
        digitalWrite(IN1,HIGH); // set pin 2 on L293D low
        digitalWrite(IN2,LOW);
        digitalWrite(IN3,HIGH);
        digitalWrite(IN4,LOW);
        // set pin 7 on L293D low
        if(flag == 0){
//          Serial.println("Motor: on");
          flag=1;
        }
    }
    // if the state is '1' the motor will turn right
    else if (state == '1') {
        digitalWrite(IN1, LOW); // set pin 2 on L293D low
        digitalWrite(IN2, HIGH);
        digitalWrite(IN3, HIGH);
        digitalWrite(IN4, LOW);/// set pin 7 on L293D high
       if(flag == 0){
  //        Serial.println("Motor: right");
          flag=1;
        }
    }
    // if the state is '2' the motor will turn left
    else if (state == '2')
    {
        digitalWrite(IN1, HIGH); // set pin 2 on L293D high
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, HIGH);// set pin 7 on L293D low
        if(flag == 0){
    //      Serial.println("Motor: left");
          flag=1;
        }
    }
    else if(state == '4')
    {   
      digitalWrite(IN1,LOW);
      digitalWrite(IN2,HIGH);
      digitalWrite(IN3,LOW);
      digitalWrite(IN4,HIGH);
      if(flag==0){
      //  Serial.println("BCk");
        flag=1;
      }
      }
    else if (state == '5') {
    
        digitalWrite(IN1,HIGH); 
        digitalWrite(IN2,HIGH);
        digitalWrite(IN3,HIGH);
        digitalWrite(IN4,HIGH);
         if(flag == 0){
        // Serial.println("Motor: OFF");
          flag=1;
        }
    }
} 
