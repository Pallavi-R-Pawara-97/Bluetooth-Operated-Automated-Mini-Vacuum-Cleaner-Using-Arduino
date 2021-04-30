/*
 * Control DC motor with Smartphone via bluetooth
 * created by Rui Santos, https://randomnerdtutorials.com
*/

int IN1 = 2; // pin 2 on L293D IC
int IN2 = 3; // pin 7 on L293D IC
int IN3 = 4;
int IN4= 5;// pin 1 on L293D IC

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
   if(Serial.available() > 0){     
      state = Serial.read();   
      flag=0;
     //digitalWrite(IN1, LOW);
     //digitalWrite(IN2, HIGH);
    } 
      
    // if the state is '0' the DC motor will turn off
    

    
    if (state == '3')
    {
        /*digitalWrite(IN1,HIGH); // set pin 2 on L293D low
        digitalWrite(IN2,LOW);
        digitalWrite(IN3,HIGH);
        digitalWrite(IN4,LOW);
        // set pin 7 on L293D low*/
        if(flag == 0){
          Serial.println("Motor: off");
          flag=1;
        }
    }
    // if the state is '1' the motor will turn right
    else if (state == '1') {
        /*digitalWrite(IN1, LOW); // set pin 2 on L293D low
        digitalWrite(IN2, HIGH);
        digitalWrite(IN3, HIGH);
        digitalWrite(IN4, LOW);/// set pin 7 on L293D high*/
       if(flag == 0){
          Serial.println("Motor: right");
          flag=1;
        }
    }
    // if the state is '2' the motor will turn left
    else if (state == '2')
    {
       /* digitalWrite(IN1, HIGH); // set pin 2 on L293D high
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, HIGH);// set pin 7 on L293D low*/
        if(flag == 0){
          Serial.println("Motor: left");
          flag=1;
        }
    }
    else if (state == '0') {
    
        /*digitalWrite(IN1,LOW); // set pin 2 on L293D low
       digitalWrite(IN2, LOW);
        digitalWrite(IN3,LOW);
        digitalWrite(IN4, LOW);
        // set pin 7 on L293D low*/
        if(flag == 0){
          Serial.println("Motor: OFF");
          flag=1;
        }
    }
}
