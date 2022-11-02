#include <SoftwareSerial.h>


#define LF A0
#define LR A2
#define RF A4
#define RR A5
SoftwareSerial BT(0, 1); //TX, RX respetively
String readvoice;
 
void setup() {
pinMode(A0,OUTPUT);   //left motors forward
pinMode(A2,OUTPUT);   //left motors reverse
pinMode(A4,OUTPUT);   //right motors forward
pinMode(A5,OUTPUT);   //right motors reverse
pinMode(9,OUTPUT);   //Led
BT.begin(9600);
Serial.begin(9600);
 
}
 
void loop() {
while (BT.available()){  //Check if there is an available byte to read
  delay(10); //Delay added to make thing stable
  char c = BT.read(); //Conduct a serial read
  readvoice += c; //build the string- "forward", "reverse", "left" and "right"
  } 
    if (readvoice.length() > 0) {
    Serial.println(readvoice);
    }
if(readvoice == "forward"){            //move forward(all motors rotate in forward direction)
  digitalWrite(LF,HIGH);
  digitalWrite(RF,HIGH);
  digitalWrite(RR,LOW);
  digitalWrite(LR,LOW);

}
else if(readvoice == "back"){      //move reverse (all motors rotate in reverse direction)
  digitalWrite(LR,HIGH);
  digitalWrite(RR,HIGH);
  digitalWrite(RF,LOW);
  digitalWrite(LF,LOW);
 
}
 
else if(readvoice == "left"){      //turn right (left side motors rotate in forward direction, right side motors doesn't rotate)
  digitalWrite(RF,HIGH);
  digitalWrite(LF,LOW);
  digitalWrite(LR,LOW);
  digitalWrite(RR,LOW);
  
}
 
else if(readvoice == "right"){      //turn left (right side motors rotate in forward direction, left side motors doesn't rotate)
  digitalWrite(LF,HIGH);
  digitalWrite(LR,LOW);
  digitalWrite(RF,LOW);
  digitalWrite(RR,LOW);

}

 
else if(readvoice == "stop"){      //STOP (all motors stop)
 
  digitalWrite(LF,LOW);
  digitalWrite(LR,LOW);
  digitalWrite(RF,LOW);
  digitalWrite(RR,LOW);

}
delay(100);
readvoice="";
}
