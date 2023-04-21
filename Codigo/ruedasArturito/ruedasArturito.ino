/* Movera un motor hacia adelante al recibir el comando (char) '1' y hacia atrsd al recibir el comando '0'
*/

#include <SoftwareSerial.h>

SoftwareSerial BT1(3,2); // Habilita mediante la libreria SoftwareSerial dos pines cualquieras a RX, TX, para de este modo no ocupar la comunicacion
                         // serial que existe en los pines 1 y 2 con el computador
char lectura1;
int IN1 = 6;
int IN2 = 7;
int IN3 = 4;             //Nombre control Puente H L298N
int IN4 = 5;
int LED = 13;
int cont = 1;

void setup()
   {
       Serial.begin(9600);                              //Incia el serial PC-Arduino
       BT1.begin(9600);                                 //Inicia serial Android-Arduino
       Serial.println("Comunicado con Arturito:");      //Mensaje de inicio
       pinMode(IN1,OUTPUT);                             //Declara pines de salida de motores
       pinMode(IN2,OUTPUT);
       pinMode(IN3,OUTPUT);                             //Declara pines de salida de motores
       pinMode(IN4,OUTPUT);
       pinMode(LED,OUTPUT);
   }

void loop()
   {
       if (BT1.available()>0){                      // Si existen datos desde el Android los lee
           lectura1=(BT1.read());                   // Guarda en la variable "lectura1" lo que manda el android
        
         if(lectura1=='1'){                         // En caso de que llege el comando 1 avanza:
               digitalWrite(IN1,1);                
               digitalWrite(IN2,0);                
               digitalWrite(IN3,1);                  
               digitalWrite(IN4,0);  
               delay(50);
             }
             
         if(lectura1=='2'){                         // En caso de que llege el comando 2 va hacia la izquierda:
               digitalWrite(IN1,0);                
               digitalWrite(IN2,1);                
               digitalWrite(IN3,1);                  
               digitalWrite(IN4,0);  
               delay(50);
             }
             
         if(lectura1=='3'){                         // En caso de que llege el comando 3 retrocede:
               digitalWrite(IN1,0);                
               digitalWrite(IN2,1);                
               digitalWrite(IN3,0);                  
               digitalWrite(IN4,1);  
               delay(50);
             }   
             
         if(lectura1=='4'){                         // En caso de que llege el comando 4 va a la derecha:
               digitalWrite(IN1,1);                
               digitalWrite(IN2,0);                
               digitalWrite(IN3,0);                  
               digitalWrite(IN4,1);  
               delay(50);
             }
             
         if(lectura1=='x'){                         // En caso de que llege el comando 4 va a la derecha:
               digitalWrite(IN1,0);                
               digitalWrite(IN2,0);                
               digitalWrite(IN3,0);                  
               digitalWrite(IN4,0);  
               delay(50);
             }
             
         if(lectura1=='0'){
               int estado = digitalRead(LED);
               digitalWrite(LED,!estado);
               Serial.println(estado);
         }
       }
}

