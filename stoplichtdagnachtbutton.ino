int rood = 8;
int geel = 9;
int groen = 10;
int roodvoetganger = 6;                                                                                                                       
int groenvoetganger = 7;
const int buttonPin = 2;
int buttonPushCounter = 0;   // counter for the number of button presses
int buttonState = 0;         // current state of the button
int lastButtonState = 0;     // previous state of the button
const int LDRPin = A0;
int LDRValue = 0;

void setup(){
pinMode(buttonPin, INPUT);
pinMode(rood,OUTPUT);
pinMode(geel,OUTPUT);
pinMode(groen,OUTPUT);
pinMode(roodvoetganger,OUTPUT);
pinMode(groenvoetganger,OUTPUT);
Serial.begin(9600);
digitalWrite(groen, HIGH);
digitalWrite(roodvoetganger, HIGH);
LDRValue = analogRead(LDRPin);
Serial.print(LDRValue);
}

void loop(){
// read the pushbutton input pin:
  buttonState = digitalRead(buttonPin);
  LDRValue = analogRead(LDRPin);

  if(LDRValue < 800){
    digitalWrite(groen, LOW);
    digitalWrite(roodvoetganger, LOW);
    digitalWrite(groenvoetganger,HIGH);
    digitalWrite(geel, LOW);
    delay(300);
    digitalWrite(groenvoetganger,LOW);
    digitalWrite(geel, HIGH);
    delay(500);
    digitalWrite(geel, LOW);
    delay(200);
    LDRValue= analogRead(LDRPin);
  }else{
    digitalWrite(geel, LOW);
    digitalWrite(groen, HIGH);
    digitalWrite(roodvoetganger, HIGH);
  }

  // compare the buttonState to its previous state
  if (buttonState != lastButtonState) {
       
    // if the state has changed, increment the counter
    if (buttonState == HIGH) {
      // if the current state is HIGH then the button went from off to on:
      buttonPushCounter++;
      changeLights();
      Serial.println("on");
      Serial.print("number of button pushes: ");
      Serial.println(buttonPushCounter);
      } else {
      // if the current state is LOW then the button went from on to off:
      Serial.println("off");
    }
   
    // Delay a little bit to avoid bouncing
    delay(50);
  }
  // save the current state as the last state, for next time through the loop
  lastButtonState = buttonState;
  


}


void changeLights(){

/* *** auto geel *** */
digitalWrite(geel,HIGH);
digitalWrite(groen,LOW);
delay(2000);

/* *** auto rood *** */
digitalWrite(rood,HIGH);
digitalWrite(geel,LOW);
digitalWrite(roodvoetganger,HIGH);
digitalWrite(groenvoetganger,LOW);
delay(800);

/* *** voetganger groen  *** */
digitalWrite(roodvoetganger,LOW);
digitalWrite(groenvoetganger,HIGH);
delay(3700);                                   // 3700 + 300 = 4000
/* *** voetganger knippert *** */
for (int teller=1;teller<=4;teller=teller+1){
  digitalWrite(groenvoetganger,HIGH);
  delay(200);
  digitalWrite(groenvoetganger,LOW);
  delay(200);
}
/* *** voetganger rood *** */
digitalWrite(roodvoetganger,HIGH);
delay(1000);
/* *** auto groen *** */
digitalWrite(rood,LOW);
digitalWrite(groen,HIGH);
delay(2000);        // edit: deze delay mag weg maar kan ook blijven staan om er voor te zorgen dat auto minstens 4 seconde groen blijft als voetganger te snel op knop drukt nadat voetganger rood wordt.
}
