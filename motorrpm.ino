#define SensorSol 10  
#define SensorOrta 11
#define SensorSag 12

#define MotorR1 2
#define MotorR2 8 
#define MotorRE 13

#define MotorL1 5
#define MotorL2 4
#define MotorLE 3
int v=0; //250rpm motorlar 5vites



void setup() {
  pinMode(SensorSol, INPUT);
  pinMode(SensorOrta, INPUT);
  pinMode(SensorSag, INPUT);

  pinMode(MotorR1, OUTPUT); 
  pinMode(MotorR2, OUTPUT);

  pinMode(MotorL1, OUTPUT);
  pinMode(MotorL2, OUTPUT);
  Serial.begin(9600);
}
void ileri(){  
  digitalWrite(MotorR1, HIGH); 
  digitalWrite(MotorR2, LOW); 
  analogWrite(MotorRE, v*50); 

  digitalWrite(MotorL1, HIGH);
  digitalWrite(MotorL2, LOW); 
  analogWrite(MotorLE, v*50);   
}
void sag(){ 
  digitalWrite(MotorR1, LOW); 
  digitalWrite(MotorR2, LOW); 
  analogWrite(MotorRE, 0); 

  digitalWrite(MotorL1, HIGH); 
  digitalWrite(MotorL2, LOW); 
  analogWrite(MotorLE, v*50);   
}
void sol(){
  digitalWrite(MotorR1, HIGH); 
  digitalWrite(MotorR2, LOW);
  analogWrite(MotorRE, v*50);

  digitalWrite(MotorL1, LOW); 
  digitalWrite(MotorL2, LOW); 
  analogWrite(MotorLE, 0); 
}
void dur(){ 
  digitalWrite(MotorR1, LOW);
  digitalWrite(MotorR2, LOW);
  digitalWrite(MotorRE, LOW);

  digitalWrite(MotorL1, LOW);
  digitalWrite(MotorL2, LOW);
  digitalWrite(MotorLE, LOW); 
}

void loop() 
{

  if(Serial.available()>0)
  {
  char  w=Serial.read(); 
    if (w=='1')
    {
    ileri();
    }
    if(w=='3')
    {
    sag();
    }
    if(w=='4')
    {
    sol();  
    }      
    if(w=='x');   
  {
    if(!w=='x'); 
    if(v==0) v=0;
    else v=v+1;
  }
    if(w=='y');   
 {
    if(!w=='y'); 
    if(v==5) v=5;
    else v=v-1;
  }

  
  }


}
