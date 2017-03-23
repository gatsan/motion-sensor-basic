 //GATSAN Technologies
 //PIR Motion Sensor
 //www.gatsan.com
 
int inputPin = 2;               // choose the input pin (for PIR sensor), This will be the PIR "out" pin
int pirState = LOW;             // we start, assuming no motion detected
int val = 0;                    // variable for reading the pin status
 
void setup() {
  pinMode(inputPin, INPUT);     // declare the PIR Motion sensor as input
 
  Serial.begin(9600);           // Serial coomunication started at 9600 baud rate (bps)
}
 
void loop(){
  val = digitalRead(inputPin);  // read input value
  if (val == HIGH) {            // check if the input is HIGH i.e. If the sensor detected motion
    if (pirState == LOW) {      // If there was no movement before
      Serial.println("Motion detected!"); // Feedback on Serial Console is printed here
      pirState = HIGH;          // Sensing movement
    }
  } else {                      // If there is no movement
    if (pirState == HIGH){      // If there was movement before
      Serial.println("Motion ended!");      // movement stoped here
      
      pirState = LOW;           // Sensor is not sensing any movement
    }
  }
}
