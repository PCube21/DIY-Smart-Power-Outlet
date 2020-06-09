//HyperLab Arduino Beginner Class

int Relay=8;
int led1=3;
int led2=4;
int led3=5;
int PBPin=2;
int Time=0;
boolean OldButton=LOW;

void setup()
{
  Serial.begin(9600);
  pinMode(Relay,OUTPUT);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(PBPin,INPUT);
}

void loop()
{
  int currentButton = digitalRead(PBPin);
  if (currentButton == HIGH && OldButton == LOW) 
  {
     Time=Time+1;
     Serial.println(Time);
     if(Time>4)
     Time=0;
     Serial.println(Time);
   if(Time==1)
   {
      Serial.println("Case1");
      digitalWrite(led1,HIGH);
      digitalWrite(Relay,HIGH);
      delay(2000);
      digitalWrite(Relay,LOW);
      digitalWrite(led1,LOW);
   }
   if(Time==2)
   {
      Serial.println("Case2");
      digitalWrite(led2,HIGH);
      digitalWrite(Relay,HIGH);
      delay(4000);
      digitalWrite(Relay,LOW);
      digitalWrite(led2,LOW);
   }
   if(Time==3)
   {
     Serial.println("Case3");
     digitalWrite(led3,HIGH);
     digitalWrite(Relay,HIGH);
   }
   else
   {
     digitalWrite(Relay,LOW);
     digitalWrite(led1,LOW);
     digitalWrite(led2,LOW);
     digitalWrite(led3,LOW);
   }
  }
  OldButton = currentButton;
  
  delay(500);
}
