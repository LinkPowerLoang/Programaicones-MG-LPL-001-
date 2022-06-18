char texto[500];
int cont = 0;
int nElemenst = 0;

void setup() {
Serial.begin(9600);
}

void loop() {
  do{
    if(Serial.available()!=0){
      texto[cont] = Serial.read();
      cont +=1;
      }
    }
    while(cont < 500 && texto [cont-1] != ' - ');
    cont =0; 

    nElemenst = sizeof(texto) / sizeof(char);
    for(int i = 0; i < nElemenst; i++){
      Serial.print(texto[i]);
      texto[i]= '  ';
      }
     Serial.println(" ");
     delay(100);

}
