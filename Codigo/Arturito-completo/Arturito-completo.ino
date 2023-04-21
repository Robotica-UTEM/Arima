#include <SoftwareSerial.h>

SoftwareSerial BT1(13,12); // Habilita mediante la libreria SoftwareSerial dos pines cualquieras a RX, TX, para de este modo no ocupar la comunicacion
                         // serial que existe en los pines 1 y 2 con el computador
char lectura;
int IN1 = 0;             //Nombre control Puente H L298N
int IN2 = 1;
int IN3 = 2;            
int IN4 = 3;
int IN5 = 4;
int IN6 = 5;
int IN7 = 6;             
int IN8 = 7;
int LED_blue = 9;
int LED_green = 10;
int LED_red = 11;

void setup()
   {
       BT1.begin(9600);                                 //Inicia serial Android-Arduino
       pinMode(IN1,OUTPUT);                             //Declara pines de salida de motores
       pinMode(IN2,OUTPUT);
       pinMode(IN3,OUTPUT);                             //Declara pines de salida de motores
       pinMode(IN4,OUTPUT);
       pinMode(IN5,OUTPUT);                             //Levanta Brazos
       pinMode(IN6,OUTPUT);                             //Baja Brazos
       pinMode(IN7,OUTPUT);                             //Abre Brazo
       pinMode(IN8,OUTPUT);                             //Cierra Brazo
       pinMode(LED_blue,OUTPUT);
       pinMode(LED_red,OUTPUT);
       pinMode(LED_green,OUTPUT);
   }

void loop()
   {
       if (BT1.available()>0){                      // Si existen datos desde el Android los lee
           lectura=(BT1.read());                   // Guarda en la variable "lectura1" lo que manda el android

if(lectura=='1'){                                   // En caso de que llege el comando 1 retroceder:
               digitalWrite(IN1,1);                
               digitalWrite(IN2,0);                
               digitalWrite(IN3,1);                  
               digitalWrite(IN4,0);
               delay(50);               
             }
             
         if(lectura=='2'){                         // En caso de que llege el comando 2 va hacia la derecha:
               digitalWrite(IN1,0);                
               digitalWrite(IN2,1);                
               digitalWrite(IN3,1);                  
               digitalWrite(IN4,0);
               delay(50);
             }
             
         if(lectura=='3'){                         // En caso de que llege el comando 3 avanzar:
               digitalWrite(IN1,0);                
               digitalWrite(IN2,1);                
               digitalWrite(IN3,0);                  
               digitalWrite(IN4,1);
               delay(50);
             }   
             
         if(lectura=='4'){                         // En caso de que llege el comando 4 va a la izquierda:
               digitalWrite(IN1,1);                
               digitalWrite(IN2,0);                
               digitalWrite(IN3,0);                  
               digitalWrite(IN4,1);
               delay(50);
             }
        
         if(lectura=='5'){                         // En caso de que llege el comando 5 baja brazos:
               digitalWrite(IN5,1);                
               digitalWrite(IN6,0);
               delay(50);               
             }
             
         if(lectura=='6'){                         // En caso de que llege el comando 6 brazos abiertos:
               digitalWrite(IN7,1);                
               digitalWrite(IN8,0);
               delay(50);
             }
             
         if(lectura=='7'){                         // En caso de que llege el comando 7 sube brazos:
               digitalWrite(IN5,0);                
               digitalWrite(IN6,1);
               delay(50);
             }   
             
         if(lectura=='8'){                         // En caso de que llege el comando 8 se cierran los brazos
               digitalWrite(IN7,0);                
               digitalWrite(IN8,1);
               delay(50);
             }
             
         if(lectura=='x'){             // En caso de que llege el comando 4 va a la derecha:
            digitalWrite(IN1,0);                
               digitalWrite(IN2,0);                
               digitalWrite(IN3,0);                  
               digitalWrite(IN4,0);  
               digitalWrite(IN5,0);                
               digitalWrite(IN6,0);                
               digitalWrite(IN7,0);                  
               digitalWrite(IN8,0);  
               delay(50);
             }
             
            if(lectura=='0'){                             //stop
               digitalWrite(IN1,0);                
               digitalWrite(IN2,0);                
               digitalWrite(IN3,0);                  
               digitalWrite(IN4,0);           
               digitalWrite(IN5,0);                
               digitalWrite(IN6,0);                
               digitalWrite(IN7,0);                  
               digitalWrite(IN8,0);
               digitalWrite(LED_red,0);
               digitalWrite(LED_green,0);
               digitalWrite(LED_blue,0);
               delay(50);
               
            }
              if(lectura=='a'){                          //aplausos
               digitalWrite(IN7,1);                
               digitalWrite(IN8,0); 
               delay(2000);               
               digitalWrite(IN7,0);                  
               digitalWrite(IN8,0);           
               delay(150);
               digitalWrite(IN7,0);                
               digitalWrite(IN8,1);                
               delay(2000);
               digitalWrite(IN7,0);                  
               digitalWrite(IN8,0);  
               delay(150);
               digitalWrite(IN7,1);                
               digitalWrite(IN8,0); 
               delay(2000);               
               digitalWrite(IN7,0);                  
               digitalWrite(IN8,0);           
               delay(150);
               digitalWrite(IN7,0);                
               digitalWrite(IN8,1);                
               delay(2000);
               digitalWrite(IN7,0);                  
               digitalWrite(IN8,0);  
               delay(150);
               digitalWrite(IN7,1);                
               digitalWrite(IN8,0); 
               delay(2000);               
               digitalWrite(IN7,0);                  
               digitalWrite(IN8,0);           
               delay(150);
            
            }
            
         if(lectura=='z'){                         // En caso de que llege el comando z girando
               digitalWrite(IN1,1);                
               digitalWrite(IN2,0);                
               digitalWrite(IN3,0);                  
               digitalWrite(IN4,1);  
               delay(1000);
               digitalWrite(IN1,0);                
               digitalWrite(IN2,1);                
               digitalWrite(IN3,1);                  
               digitalWrite(IN4,0);  
               delay(1000);
       }
       if(lectura=='r'){                         // enciende led rojo 
              int estadored = digitalRead(LED_red);
              digitalWrite(LED_red,!estadored);
              delay(50);
       }
       if(lectura=='g'){                        // enciende led verde
              int estadogreen = digitalRead(LED_green);
              digitalWrite(LED_green,!estadogreen);
              delay(50);
       }
       if(lectura=='b'){                       // enciende led blue
              int estadoblue = digitalRead(LED_blue);
              digitalWrite(LED_blue,!estadoblue);
              delay(50);
       }
            
       }
   }
