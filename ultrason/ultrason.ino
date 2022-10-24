int TRIGGER_PIN = 3;
int ECHO_PIN = 4;

const float SOUND_SPEED = 340.0 / 1000;

void setup() {

  Serial.begin(9600);

  pinMode(TRIGGER_PIN, OUTPUT);
  digitalWrite(TRIGGER_PIN, LOW);
  pinMode(ECHO_PIN, INPUT);
}
 
void loop() {
  
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);
  
  long measure = pulseIn(ECHO_PIN, HIGH);

  int distance = measure / 2 * SOUND_SPEED;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print("mm\n");
  

  delay(500);
}
