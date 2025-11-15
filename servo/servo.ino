#include <Servo.h> 
Servo myservo;    
int pos = 00;   
         
void setup(){ 
 myservo.attach(3); 
} 

void loop(){ 
 for(pos = 00; pos < 180; pos += 1)  
 {
  myservo.write(pos); 
  delay(15);              
 } 
 for(pos = 180; pos>=1; pos-=1)  
 {                              
  myservo.write(pos);                 
  delay(15);                        
 }
}
