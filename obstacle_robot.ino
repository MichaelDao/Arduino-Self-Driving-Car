// sensor code
// http://www.mediafire.com/file/dql27gnuljjpurr/Obstacle_Avoiding_Robot_Code.ino
// Motor code
// http://www.instructables.com/id/Arduino-Motor-Shield-Tutorial/

// Define the sensor pins
#define trigSensor 13
#define echoSensor 12 

void setup() {
  // begin serial communication
  Serial.begin(9600); 

  // trigPin set to output
  pinMode(trigSensor, OUTPUT); // Send sound waves
  // echoPin set to input 
  pinMode(echoSensor, INPUT); //receive sound waves
  
  //set the speed of the motors, between 0-255
  analogWrite(3, 130); //Spins the motor on Channel A at half speed
  analogWrite(11, 130); //Spins the motor on Channel B at half speed
}
 
void loop() {
  // Create local variables
  long echoPulse, distInCm; 
  
  // Start scan by sending low output
  digitalWrite(trigSensor, LOW);  
  delayMicroseconds(2); // delay the sensor for operation to work
  
  // Continue scan by sending high output
  digitalWrite(trigSensor, HIGH); 
  delayMicroseconds(10); // delay the sensor a bit longer
  
  // Continue scan by sending low output
  digitalWrite(trigSensor, LOW);
  
  // Assign the input value to variable
  echoPulse = pulseIn(echoSensor, HIGH);
  
  // Convert the distance to centimeters.
  distInCm = (echoPulse/2)/29.1;
  
  //If obstacle is less than 40 centimers, turn right
  if (distInCm < 40){   
    analogWrite(3, 255); //Spins the motor on Channel A at full speed
    analogWrite(11, 0); //Spins the motor on Channel B at no speed
  
  } else {
    // No obstacle detected, keep going forward
    delay(15);
    analogWrite(3, 130); //Spins the motor on Channel A at half speed
    analogWrite(11, 130); //Spins the motor on Channel B at half speed
  }
}