#define SENSOR1 2// define pin 2 for sensor1
#define SENSOR2 3// define pin 3 for sensor2
char t;
void setup() {
pinMode(SENSOR1, INPUT_PULLUP);// define pin as Input sensor1
pinMode(SENSOR2, INPUT_PULLUP);// define pin as Input sensor2
pinMode(13,OUTPUT);   //left motors forward
pinMode(12,OUTPUT);   //left motors reverse
pinMode(11,OUTPUT);   //right motors forward
pinMode(10,OUTPUT);   //right motors reverse
pinMode(9,OUTPUT);    //Led
Serial.begin(9600);
}

void loop() {
  label:
  
  int L1 =digitalRead(SENSOR1);// read the sensor 1
  int L2 =digitalRead(SENSOR2);// read the sensor 2
  if(Serial.available()){
  t = Serial.read();
  Serial.println(t);
}
if(L1==1 && L2==0)
{
if(t == 'F'){ 
  //move forward(all motors rotate in forward direction)
  digitalWrite(13,HIGH);
  digitalWrite(11,HIGH);
}
 
else if(t == 'B'){      //move reverse (all motors rotate in reverse direction)
  digitalWrite(12,HIGH);
  digitalWrite(10,HIGH);
}
 
else if(t == 'L'){      //turn right (left side motors rotate in forward direction, right side motors doesn't rotate)
  digitalWrite(11,HIGH);
  digitalWrite(12,HIGH);
}
 
else if(t == 'R'){      //turn left (right side motors rotate in forward direction, left side motors doesn't rotate)
  digitalWrite(13,HIGH);
  digitalWrite(10,HIGH);
}

else if(t == 'W'){    //turn led on or off)
  digitalWrite(9,HIGH);
}
else if(t == 'S'){      //STOP (all motors stop)
  digitalWrite(13,LOW);
  digitalWrite(12,LOW);
  digitalWrite(11,LOW);
  digitalWrite(10,LOW);
}
}
else if(L1==0 || L2==1)
{
   Serial.println("Obstacle detected");
    
   if(t == 'B')
   {      //move reverse (all motors rotate in reverse direction)
  digitalWrite(12,HIGH);
  digitalWrite(10,HIGH);
}
  else{
    //STOP (all motors stop)
    digitalWrite(13,LOW);
    digitalWrite(12,LOW);
    digitalWrite(11,LOW);
    digitalWrite(10,LOW);
  }
    goto label;
}

}
