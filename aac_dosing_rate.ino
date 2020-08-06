
//simple A4988 connection
//jumper reset and sleep together
//connect  VDD to Arduino 3.3v or 5v
//connect  GND to Arduino GND (GND near VDD)
//connect  1A and 1B to stepper coil 1
//connect 2A and 2B to stepper coil 2
//connect VMOT to power source (9v battery + term)
//connect GRD to power source (9v battery - term)

int stp = 5;  //connect pin 13 to step
int dir = 6;  // connect pin 12 to dir
int a = 0;     //  change direction a=1351 to pull back the pusher car 
int i=0;
void setup() 
{                
  pinMode(stp, OUTPUT);
  pinMode(dir, OUTPUT);
  digitalWrite(dir, HIGH); 
        
}


void loop() 
{


  if (a <  1350)  //sweep 200 step in dir 1
   {
    a++;
    digitalWrite(stp, HIGH);   
    delay(20);               
    digitalWrite(stp, LOW);  
    delay(20);              
   }
  else 
   {
    digitalWrite(dir, LOW);
    a++;
    digitalWrite(stp, HIGH);  
    delay(10);               
    digitalWrite(stp, LOW);  
    delay(10);
    
    if (a>2700)    //sweep 200 in dir 2
     {
      a = 0;
      digitalWrite(dir, HIGH);
     }
    }     

}
