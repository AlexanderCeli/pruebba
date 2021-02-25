#include "DHT.h" //cargamos la librería DHT
#define DHTPIN 9 //Seleccionamos el pin en el que se //conectará el sensor
#define DHTTYPE DHT11 //Se selecciona el DHT11 que se va usar
DHT dht(DHTPIN, DHTTYPE); //Se inicia una variable que será usada por Arduino para comunicarse con el sensor

#include <SoftwareSerial.h>  // libreria que permite establecer pines digitales
// para comunicacion serie

SoftwareSerial miBT(10, 11);  // pin 10 como RX, pin 11 como TX
int RELE = 8; //pin del relee 1
int RELE2 = 7;
int p;
int tempn1 = 23;
int tempn = 22;
int temp2 = 21;
int tempnn;

int temp3 = 20;
void setup() {
  Serial.begin(9600);   // comunicacion de monitor serial a 9600 bps
  Serial.println("Listo");  // escribe Listo en el monitor
  miBT.begin(38400);    // comunicacion serie entre Arduino y el modulo a 38400 bps
  dht.begin(); //Inicio del sensor
  pinMode (RELE, OUTPUT);
  pinMode (RELE2, OUTPUT);
}

void loop() {
  int h = dht.readHumidity(); //Se lee la humedad
  double t = dht.readTemperature(); //Se lee la temperatura
  Serial.println("Humedad: ");
  Serial.println(h);
  Serial.println("Temperatura: ");
  Serial.println(t);
  delay(2000); //Se espera 2 segundos para seguir leyendo //datos

  if (miBT.available())       // si hay informacion disponible desde modulo
    Serial.write(miBT.read());   // lee Bluetooth y envia a monitor serial de Arduino
  p = miBT.read();
  Serial.write(p);



  
  if (p == 'a') {
    

  if (t <= temp3) {
    Serial.println("teclado salio");
    tempnn = 0;
    Serial.println(tempn);
    if (tempnn == 0) {
      digitalWrite(RELE, !LOW);

    }

  }
   digitalWrite(RELE, HIGH);
  }




  
  if (p == 'b') {
    
  if (t == tempn1) {
    Serial.println("teclado salio");
    tempnn = 1;
    Serial.println(tempn);
    if (tempnn == 1) {
      digitalWrite  (RELE, !HIGH);

    }

  }
 
  digitalWrite(RELE, LOW);
  }









  if (t == tempn) {
    Serial.println("teclado salio");
    tempnn = 1;
    Serial.println(tempn);
    if (tempnn == 1) {
      digitalWrite  (RELE, !HIGH);

    }

  }
  if (t == temp2) {
    Serial.println("teclado salio");
    tempnn = 0;
    Serial.println(tempn);
    if (tempnn == 0) {
      digitalWrite(RELE, !LOW);

    }

  }

}
