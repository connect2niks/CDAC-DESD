const int buzzer =21;

void setup() {
  // put your setup code here, to run once:
 pinMode(buzzer,OUTPUT);
 Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(buzzer,HIGH);
Serial.print("buzzer IS ON\n");
delay(5000);
digitalWrite(buzzer,LOW);
Serial.print("buzzer IS OFF\n");
delay(5000);
}
