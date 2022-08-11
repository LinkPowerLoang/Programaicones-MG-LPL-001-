// Codigo generado para pruebas del kit gec 2021
// Basado en el ejemplo de adafruit 

//Definision de los pines del Dip Swicht
#define DS1 27 //Dip Swicht #1
#define DS2 14 //Dip Swicht #2

//Variable para leer estado del dip swicht
int estadoDS1 = 0;
int estadoDS2 = 0;

void setup() {
  // Activador del monitor serial
  Serial.begin(115200);

  //Definir configuracion de pines de entrada
  pinMode(DS1, INPUT);
  pinMode(DS2, INPUT);
}

void loop() {
//Loop para leer y desplegar el estado de DS1
  estadoDS1 = digitalRead(DS1);
  Serial.print("Valor en DS1 = ");
  Serial.println(estadoDS1);

//Loop para leer y desplegar el estado de DS2
  estadoDS2 = digitalRead(DS2);
  Serial.print("Valor en DS2 = ");
  Serial.println(estadoDS2);

  delay (2000);
}
