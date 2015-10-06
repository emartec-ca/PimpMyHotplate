// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int HOT_TOP = 7;
int PIN_TEMP = A5;
int KNOB_STIR = A4;
int KNOB_HEAT = A3;
int PIN_HEAT_EN = 2;
int PIN_STIR_EN = 12;
int STIR_REF = 5;
int HEAT_REF = 6;
int plateTemp = 0;
int knobStirPos = 0;
int knobHeatPos = 0;
int heatPWM = 0;
int stirPWM = 0;
boolean isHeatEn = false;
boolean isStirEn = false;
// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
    Serial.begin(9600);
    Serial.println("VERSION 2015-10-04");
  pinMode(HOT_TOP, OUTPUT);  
  pinMode(PIN_HEAT_EN, OUTPUT); 
    pinMode(PIN_STIR_EN, OUTPUT); 
   pinMode(HEAT_REF, OUTPUT); 
  digitalWrite(PIN_HEAT_EN,0);

}

// the loop routine runs over and over again forever:
void loop() {
  
  plateTemp = analogRead(PIN_TEMP);
  knobHeatPos = analogRead(KNOB_HEAT);
  knobStirPos = analogRead(KNOB_STIR);
 isHeatEn =   (knobHeatPos>100)?HIGH:LOW;
 isStirEn =   (knobStirPos>100)?HIGH:LOW;
digitalWrite(PIN_HEAT_EN,isHeatEn);
//digitalWrite(PIN_STIR_EN,isStirEn);
 //analogWrite(HEAT_REF,knobHeatPos);
 heatPWM= map(knobHeatPos,0,1023,255,0);
 stirPWM= map(knobStirPos,0,1023,255,0); 
  analogWrite(HEAT_REF,heatPWM);
  analogWrite(STIR_REF,stirPWM);
  
  Serial.print("HEN:");
  Serial.print(isHeatEn);
    Serial.print("\tSEN:");
  Serial.print(isStirEn);

  Serial.print("\tHEAT: ");
  Serial.print(heatPWM);
  Serial.print("\tStir: ");
  Serial.print(stirPWM);
  Serial.print("\tCURRENT TEMP:");
  //BETA TEMPERATURE EQN: y = 0.1621x + 74.245
  Serial.println(plateTemp);
  
  delay(200);
  /*
  digitalWrite(HOT_TOP, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);               // wait for a second
  digitalWrite(HOT_TOP, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);               // wait for a second
*/

}


