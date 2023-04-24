#include  <LiquidCrystal.h>
LiquidCrystal LCD(12,11,5,4,3,2);

float centigrado(){
int dato;
float c;
dato=analogRead(A4);
c = ((5.0* dato /1023)*100.0)-49.78;
return (c);}

int PinRed = 8;
int PinYe = 7;
int PinGre = 6;
int Pieze = 1;
int PinFoto = A5;

float humiditysensorOutput = 0;


const int PinTMP = A4;
int RawValue= 0;
double Voltage = 0;
double tempC = 0;

int sensorValue = 0;
int i = 0;
int SensorUmidPino = 13;

void setup(){
  
  pinMode(PinRed , OUTPUT);
  pinMode(PinYe ,OUTPUT);
  pinMode(PinGre ,OUTPUT);
  pinMode(Pieze ,OUTPUT);
  pinMode(PinFoto ,INPUT);
  pinMode(PinTMP ,INPUT);
  pinMode(A3 ,INPUT);
}

void loop() {
  
    temperatura();
}

void temperatura() { 
  

 while (i < 9){
   	
    float centigrados = centigrado();
   	int sensorValue = analogRead(PinFoto); 
    float humiditysensorOutput = analogRead(A3);
    float humidity = map(humiditysensorOutput, 0, 1023, 0, 100);
   
   
   
    if (centigrados > 15 || centigrados < 10 ||
        sensorValue > 600||
        humiditysensorOutput <= 613.8 || 
        humiditysensorOutput >= 818.4){
      
    	digitalWrite(Pieze, HIGH);
        digitalWrite(PinGre, LOW);
      
    }else if (centigrados < 15 && centigrados > 10 ||
        sensorValue < 200 ||    
        humiditysensorOutput >= 613.8 || 
        humiditysensorOutput <= 818.4){
    
      	digitalWrite(PinGre, HIGH);  
        digitalWrite(Pieze, LOW);
      	
    }else{
      digitalWrite(Pieze, LOW);
    }
   
   
   
   if (centigrados > 15 && centigrados < 130 || 
       centigrados > -31 && centigrados < 10 ||
     sensorValue > 600 && sensorValue < 1023 || 
       sensorValue > 200){
     
    	digitalWrite(PinYe, HIGH);
        digitalWrite(PinGre, LOW);
    }else{
        digitalWrite(PinYe, LOW);
    }
   
   
   
      if (sensorValue > 600 && sensorValue < 1023 ||
        humiditysensorOutput < 613.8 || 
        humiditysensorOutput > 818.4 ){
    	
        digitalWrite(PinRed, HIGH);
        digitalWrite(PinGre, LOW);
        
    }else{
        digitalWrite(PinRed, LOW);
    }
      
   
   
   
    if (centigrados < 10){
      
      LCD.begin(16,2);
      LCD.print("Tempe BAIXA");
      LCD.setCursor(0,1);
      LCD.print("Tem. = ");
      LCD.setCursor(7,1);
      LCD.print(centigrados);
      LCD.print("C");
      delay(5000);
       }else if (centigrados > 15){
      LCD.begin(16,2);
      LCD.print("Temp ALTA");
      LCD.setCursor(0,1);
      LCD.print("Tem. = ");
      LCD.setCursor(7,1);
      LCD.print(centigrados);
      LCD.print("C");
      delay(5000);
      
      }else{
      LCD.begin(16,2);
      LCD.print("Temperatura OK");
      LCD.setCursor(0,1);
      LCD.print("Tem. = ");
      LCD.setCursor(7,1);
      LCD.print(centigrados);
      LCD.print("C");
      delay(5000);
        }
   
   
   
   
   
       if (sensorValue < 200){
         
      LCD.begin(16,2);
      LCD.print("Ambiente OK ");
      delay(5000);
       }else if (sensorValue > 600){
      LCD.begin(16,2);
      LCD.print("Ambiente muito");
      LCD.setCursor(0,1);
      LCD.print("CLARO");
      delay(5000);
      
      }else{
      LCD.begin(16,2);
      LCD.print("Ambiente a meia");
      LCD.setCursor(0,1);
      LCD.print("luz");
      delay(5000);
      }
   
   
   
  	  if (humiditysensorOutput <= 613.8){
      LCD.begin(16,2);
      LCD.print("Umidade BAIXA");
      LCD.setCursor(0,1);
      LCD.print("Umidade = ");
      LCD.setCursor(10,1);
      LCD.print(humidity);
      LCD.print("%");
      delay(5000);
        
       }else if (humiditysensorOutput >= 818.4 ){
      LCD.begin(16,2);
      LCD.print("Umidade ALTA");
      LCD.setCursor(0,1);
      LCD.print("Umidade = ");
      LCD.setCursor(10,1);
      LCD.print(humidity);
      LCD.print("%");
      delay(5000);
      }else{
        
      LCD.begin(16,2);
      LCD.print("Umidade OK");
      LCD.setCursor(0,1);
      LCD.print("Umidade = ");
      LCD.setCursor(10,1);
      LCD.print(humidity);
      LCD.print("%");
      delay(5000);
        }
    }
}