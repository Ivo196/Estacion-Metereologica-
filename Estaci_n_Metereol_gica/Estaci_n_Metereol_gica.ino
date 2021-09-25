#include <Wire.h>    // incluye libreria de bus I2C
#include <Adafruit_Sensor.h>  // incluye librerias para sensor BMP280
#include <Adafruit_BMP280.h>

Adafruit_BMP280 bmp;    // crea objeto con nombre bmp

float TEMPERATURA;    // variable para almacenar valor de temperatura
float PRESION;      // variable para almacenar valor de presion atmosferica


void setup() {
  Serial.begin(9600);       // inicializa comunicacion serie a 9600 bps
  Serial.println("Iniciando:");     // texto de inicio
  if ( !bmp.begin() ) {       // si falla la comunicacion con el sensor mostrar
    Serial.println("BMP280 no encontrado !"); // texto y detener flujo del programa
    while (1);          // mediante bucle infinito
  }
  
}

void loop() {
  TEMPERATURA = bmp.readTemperature();    // almacena en variable el valor de temperatura
  PRESION = bmp.readPressure()/100;   // almacena en variable el valor de presion divido (Valor en hectopascal) 
            // por 100 para covertirlo a hectopascales
  Serial.print("Temperatura: ");    // muestra texto
  Serial.print(TEMPERATURA);      // muestra valor de la variable
  Serial.print(" C ");        // muestra letra C indicando grados centigrados
    
  Serial.print("Presión: ");      // muestra texto
  Serial.print(PRESION);      // muestra valor de la variable
  Serial.println(" hPa");     // muestra texto hPa indicando hectopascales

   Serial.print("Altitud aprox: ");    // muestra texto
  Serial.print(bmp.readAltitude(1032));      // muestra valor de la variable, Aquí colocar la presión en hPa del lugar donde vives.
  Serial.println(" m ");        // muestra letra C indicando grados centigrados

  delay(5000);          // demora de 5 segundos entre lecturas
}
