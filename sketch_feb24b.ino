#define trigPin 6 
#define echoPin 5 
#define buzzer 2 
#define led 4 
float new_delay; 
void setup()
{

Serial.begin (9600);
pinMode(trigPin, OUTPUT); 
pinMode(echoPin, INPUT); 
pinMode(buzzer,OUTPUT); 
pinMode(led,OUTPUT); 
}
void loop() 
{
long duration, distance;
digitalWrite(trigPin, LOW); 
delayMicroseconds(2); 
digitalWrite(trigPin, HIGH); 
delayMicroseconds(10);

digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH); 
distance = (duration/2) / 29.1; 
new_delay= (distance *3) +30; 
Serial.print(distance);
Serial.println("  cm"); 
if (distance < 10) 
{
digitalWrite(buzzer,HIGH); 
digitalWrite(led,HIGH); 
}
else if (distance < 50) 
{
digitalWrite(buzzer,HIGH); digitalWrite(led,HIGH); delay(new_delay);
digitalWrite(buzzer,LOW); 
digitalWrite(led,LOW); 
}
else 
{
digitalWrite(buzzer,LOW); 
digitalWrite(led,LOW); 
}
delay(20); 
}

