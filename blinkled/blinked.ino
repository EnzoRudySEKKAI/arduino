int switchPin = 12;
int redPin = 11;
int greenPin = 8;
int bluePin = 3;
int val = 0;
int state = -1;
int lastVal = 0; 
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(switchPin, INPUTA);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  val = digitalRead(switchPin);
  if(lastVal!=val && val ==1){
    Serial.print(" Etat du bouton\n");
    Serial.print(val);
    Serial.print("\n");
    if(state == 2 || state == -1){
      Serial.print("Rouge\n");
      state = 0;
    }else if(state == 1){
      Serial.print("Bleu\n");
      state+=1;
    } else{
      Serial.print("Vert\n");
      state+=1;
    }
  }
  if (val == HIGH)
  { 
    if(state==0){
      digitalWrite(redPin, HIGH);
      delay(500);
    } else if (state ==1){
      digitalWrite(greenPin, HIGH); 
      delay(500);
    } else {
      digitalWrite(bluePin, HIGH); 
      delay(500);
    }
    
  } else {
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, LOW);
  }
  lastVal = val;
  
}
