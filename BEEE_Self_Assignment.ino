//*** Design a system for a game that displays and increment score by 1 whenever a football hits a desired target  *************  

// I have used Utrasonic Sensor . But We can also use PIR Sensor for this purpose as well. Both sensor will work fine.

// Constant Variables
const int LEDPin=13;   // Green Led 
const int Trigger=10;
const int Echo=3;

// Changable variables
int score=0;     //To count the score & to make increment by 1 if target is hit.
int distance;
long duration;

void setup() {
 Serial.begin(9600);                 // Serial Port Declaration where 9600 is the band speed or data transfer speed.
 pinMode(LEDPin,OUTPUT);             // Declaring pin-type of Led pin as OUTPUT 
 pinMode(Trigger,OUTPUT);            // Declaring pin-type of Trigger pin as OUTPUT
 pinMode(Echo,INPUT);                // Declaring pin-type of Echo pin as INPUT.
}

void loop() {
  digitalWrite(Trigger,LOW);
  delayMicroseconds(2);
  digitalWrite(Trigger,HIGH);       // Sending the Utrasonic Waves for 10 microseconds.
  delayMicroseconds(10);
  digitalWrite(Trigger,LOW);
  
  // ********************  CALCULATION Part ***************
  
  duration=pulseIn(Echo,HIGH);   // Calculate the time taken by the ECHO pin to receive the incoming reflected signal.
  distance=duration*0.017;       // Calculate the distance of the object.  
  
  // **************** CALCULATION Part ends *************** 
  
  if(distance<=25)              // When distance is less than 25 cm
  {
   score=score+1;                   // Increment the score by 1 points.
   digitalWrite(LEDPin,HIGH);  // Just to give the sign that the football has hit the target.
   delay(100);
   digitalWrite(LEDPin,LOW);                // OFF the led after showing the score.
   delay(100); 
   if(score>4)
   {
    Serial.println("You are the Winnner");
    delay(1000);
    exit(0);                                     // Terminates the program when score reaches 4 points
   }
  }  
  Serial.print("Your Current Score is: ");        
  Serial.println(score);                       // Showing the Score in Serial Monitor.
  
 }
