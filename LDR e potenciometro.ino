
#define ldr1 A8
#define ldr2 A7
#define led 3
#define pont A15
#define bot 7

int liga, lldr, lp;


void setup()
{

pinMode(led, OUTPUT);
pinMode(ldr1, INPUT);
pinMode(bot,INPUT);
pinMode(pont,INPUT);

Serial.begin(9600);
}
void loop(){  

      digitalWrite(led,LOW);
      
      while ( digitalRead(bot) == 1){
          
          liga= 1;
          Serial.println("botão");
          
      }
      while ( liga == 1){ 
      
        lldr = analogRead(ldr1);
        lp =   analogRead(pont);

        while ( lp > lldr ){
          
                digitalWrite(led,HIGH);
                Serial.println("1");
      
                lldr = analogRead(ldr1);
                lp = analogRead(pont);
                
                
          } 
         while ( lldr > lp ){

                digitalWrite(led,LOW);
                lldr = analogRead(ldr1); 
                lp = analogRead(pont);
                Serial.println("0");
                
         }
        
        
          
        

      }

  
  
}
