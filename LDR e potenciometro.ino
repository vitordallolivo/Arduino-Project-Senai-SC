
#define ldr1 A8  // porta de conversor digital analogico para o LDR
#define led 3  // saida para ligar o transistor
#define pont A15 // entrada do potenciômetro
#define bot 7 // botão para iniciar o circuito

int liga, lldr, lp;


void setup()
{

pinMode(led, OUTPUT);  // saida de sinal
pinMode(ldr1, INPUT); // entrada
pinMode(bot,INPUT);  // entrada
pinMode(pont,INPUT); // entrada

Serial.begin(9600);
}
void loop(){  

      digitalWrite(led,LOW);
      
      while ( digitalRead(bot) == 1){  // enquanto o botão for pressionada
          
          liga= 1; // variavel fica igual a um
          Serial.println("botão");
          
      }
      while ( liga == 1){  // enquanto a variavel liga for igual a 1
      
        lldr = analogRead(ldr1); // passando o valor do LDR para uma variavel
        lp =   analogRead(pont); // valor do pontenciômetro para uma variavel

        while ( lp > lldr ){ // valor de potenciômetro maior que LDR
          
                digitalWrite(led,HIGH); // envia o sinal alto ao Led
                Serial.println("1");   // na entrada serial manda 1 ao Led acesso 
      
                lldr = analogRead(ldr1);
                lp = analogRead(pont);
                
                
          } 
         while ( lldr > lp ){ // valor de LDR maior que do potenciometro

                digitalWrite(led,LOW); // envia sinal baixo ao led
                lldr = analogRead(ldr1);  
                lp = analogRead(pont);
                Serial.println("0"); // mostra no serial manda 0 ao led quando desligado
                
         }
        
        
          
        

      }

  
  
}
