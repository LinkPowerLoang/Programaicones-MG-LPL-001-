int display7c[10] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x67};

// asigancion de pines por segmento 
byte a = 2;
byte b = 3;
byte c = 4;
byte d = 5;
byte e = 6;
byte f = 7;
byte g = 8;

// asigancion por habilidador
byte t1 = 9;
byte t2 = 10;
byte t3 = 11;
byte t4 = 12;

long tempor = 0, contret = 0;

void puerto (int bits, int ini, int fin)
  {
    for (int i = ini; i<=fin; i++)
      {
        digitalWrite(i, bitRead(bits, i - ini));
      } 
  }

void mostrar ()
  {
    int dig [4];
    //digito millar
    dig [0] = tempor/1000;
    // digito centena
    dig [1] = (tempor - dig [0] * 1000)/100;
     // digito decena
    dig [2] = (tempor - dig [0] * 1000 - dig[1]*100)/10;
        // digito unidad
    dig [3] = (tempor - dig [0] * 1000 - dig[1]*100 - dig[2]*10);

    for (int i = t1; i<=t4; i++)
      {
         puerto (display7c[dig[i-t1]], a, g);
         digitalWrite(i, HIGH);
         delay(1);
         digitalWrite(i, LOW);
      }
  }

// tiempor que le toma temporizar ir cargando
  void temporizacion ()
  {
    contret = 50;
    while (contret>0)
      {
        mostrar ();
        contret --;
      } 
   }

   void setup()
   {
      for (int i = a; i<=t4; i++)
      {
        pinMode (i, OUTPUT);
       } 
   }

void loop ()
 {
    while(tempor<9999) 
      {
        temporizacion();
        tempor++;
      } 
  }
