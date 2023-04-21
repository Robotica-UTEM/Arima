/* Movera los brazos dependiendo del comando que le llegue
*/

#include <SoftwareSerial.h>

SoftwareSerial BT1(3,2); // Habilita mediante la libreria SoftwareSerial dos pines cualquieras a RX, TX, para de este modo no ocupar la comunicacion
                         // serial que existe en los pines 1 y 2 con el computador
char lectura1;
int IN1 = 6;
int IN2 = 7;
int IN3 = 4;             //Nombre control Puente H L298N
int IN4 = 5;
int IN5 = 11;
int IN6 = 10;
int IN7 = 9;             //Nombre control Puente H L298N
int IN8 = 8;
int LED = 13;
int cont = 1;

void setup()
   {
       Serial.begin(9600);                              //Incia el serial PC-Arduino
       BT1.begin(9600);                                 //Inicia serial Android-Arduino
       Serial.println("Comunicado con Arturito:");      //Mensaje de inicio
       pinMode(IN5,OUTPUT);                             //Declara pines de salida de motores
       pinMode(IN6,OUTPUT);
       pinMode(IN7,OUTPUT);                             //Declara pines de salida de motores
       pinMode(IN8,OUTPUT);
       pinMode(LED,OUTPUT);
   }

void loop()
   {
       if (BT1.available()>0){                      // Si existen datos desde el Android los lee
           lectura1=(BT1.read());                   // Guarda en la variable "lectura1" lo que manda el android
        
         if(lectura1=='5'){                         // En caso de que llege el comando 1 avanza:
               digitalWrite(IN5,1);                
               digitalWrite(IN6,0);                
               delay(50);
               Serial.println("lectura:");
             }
             
         if(lectura1=='6'){                         // En caso de que llege el comando 2 va hacia la izquierda:
               digitalWrite(IN7,1);                
               digitalWrite(IN8,0);                
               delay(50);
               Serial.println("lectura1:");
             }
             
         if(lectura1=='7'){                         // En caso de que llege el comando 3 retrocede:
               digitalWrite(IN5,0);                
               digitalWrite(IN6,1);                
               delay(50);
               Serial.println("lectura:");
             }   
             
         if(lectura1=='8'){                         // En caso de que llege el comando 4 va a la derecha:
               digitalWrite(IN7,0);                
               digitalWrite(IN8,1);                
               delay(50);
               Serial.println("lectura1:");
             }
             
         if(lectura1=='x'){                         // En caso de que llege el comando 4 va a la derecha:
               digitalWrite(IN5,0);                
               digitalWrite(IN6,0);                
               digitalWrite(IN7,0);                  
               digitalWrite(IN8,0);  
               delay(50);
             }
             
         if(lectura1=='0'){
               int estado = digitalRead(LED);
               digitalWrite(LED,!estado);
               Serial.println(estado);
         }
       }
}
