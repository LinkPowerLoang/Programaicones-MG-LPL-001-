int btn_1 = A0;
int btn_2 = A1;
int btn_3 = A2;

int tiempo = 270; 
int pinSound = 6; 

void setup(){
pinMode(btn_1, INPUT); 
pinMode(btn_2, INPUT); 
pinMode(btn_3, INPUT); 
pinMode(pinSound, OUTPUT); 
}

void loop(){
  
   if(digitalRead(btn_1)==HIGH) {
     cancion_Guatemala();
     delay(1000);
     }
     
   if(digitalRead(btn_2)==HIGH) {
     cancion_navida();
     delay(1000);
     }

   if(digitalRead(btn_3)==HIGH) {
     cancion_dball();
     delay(1000);
     }
}

void cancion_Guatemala(){
 tone(pinSound,261,tiempo/2);
 delay(tiempo);
 tone(pinSound,261,tiempo/2);
 delay(tiempo);
 tone(pinSound,392,tiempo/2);
 delay(tiempo);

 tone(pinSound,261,tiempo/2);
 delay(tiempo);
 tone(pinSound,261,tiempo/2);
 delay(tiempo);
 tone(pinSound,440,tiempo/2);
 delay(tiempo);

 tone(pinSound,523,tiempo/2);
 delay(tiempo);
 tone(pinSound,523,tiempo/2);
 delay(tiempo);
 tone(pinSound,523,tiempo/2);
 delay(tiempo);
 tone(pinSound,493,tiempo/2);
 delay(tiempo);
 tone(pinSound,440,tiempo/2);
 delay(tiempo);

 tone(pinSound,440,tiempo/2);
 delay(tiempo);
 tone(pinSound,523,tiempo/2);
 delay(tiempo);
 tone(pinSound,493,tiempo/2);
 delay(tiempo);

 tone(pinSound,440,tiempo/2);
 delay(tiempo);
 tone(pinSound,394,tiempo/2);
 delay(tiempo);
 tone(pinSound,349,tiempo/2);
 delay(tiempo);

 tone(pinSound,294,tiempo/2);
 delay(tiempo);
 tone(pinSound,392,tiempo/2);
 delay(tiempo);
 tone(pinSound,261,tiempo/2);
 delay(tiempo);
 tone(pinSound,261,tiempo/2);
 delay(tiempo);

 tone(pinSound,261,tiempo/2);
 delay(tiempo);
 tone(pinSound,294,tiempo/2);
 delay(tiempo);
 tone(pinSound,329,tiempo/2);
 delay(tiempo);
 tone(pinSound,349,tiempo/2);
 delay(tiempo);

 tone(pinSound,349,tiempo/2);
 delay(tiempo);
 tone(pinSound,349,tiempo/2);
 delay(tiempo);
 tone(pinSound,349,tiempo/2);
 delay(tiempo);
 tone(pinSound,329,tiempo/2);
 delay(tiempo);
 tone(pinSound,349,tiempo/2);
 delay(tiempo);
 tone(pinSound,440,tiempo/2);
 delay(tiempo);
 tone(pinSound,392,tiempo/2);
 delay(tiempo);
 tone(pinSound,349,tiempo/2);
 delay(tiempo);

 tone(pinSound,349,tiempo/2);
 delay(tiempo);
 tone(pinSound,440,tiempo/2);
 delay(tiempo);
 tone(pinSound,523,tiempo/2);
 delay(tiempo);

 tone(pinSound,587,tiempo/2);
 delay(tiempo);
 tone(pinSound,493,tiempo/2);
 delay(tiempo);
 tone(pinSound,440,tiempo/2);
 delay(tiempo);
 tone(pinSound,523,tiempo/2);
 delay(tiempo);
 tone(pinSound,493,tiempo/2);
 delay(tiempo);
 tone(pinSound,392,tiempo/2);
 delay(tiempo);
 tone(pinSound,349,tiempo/2);
 delay(tiempo);

 tone(pinSound,261,tiempo/2);
 delay(tiempo);
 tone(pinSound,261,tiempo/2);
 delay(tiempo);
 tone(pinSound,392,tiempo/2);
 delay(tiempo);

 tone(pinSound,261,tiempo/2);
 delay(tiempo);
 tone(pinSound,261,tiempo/2);
 delay(tiempo);
 tone(pinSound,440,tiempo/2);
 delay(tiempo);

 tone(pinSound,523,tiempo/2);
 delay(tiempo);
 tone(pinSound,523,tiempo/2);
 delay(tiempo);
 tone(pinSound,523,tiempo/2);
 delay(tiempo);
 tone(pinSound,493,tiempo/2);
 delay(tiempo);
 tone(pinSound,440,tiempo/2);
 delay(tiempo);

 tone(pinSound,440,tiempo/2);
 delay(tiempo);
 tone(pinSound,261,tiempo/2);
 delay(tiempo);
 tone(pinSound,493,tiempo/2);
 delay(tiempo);

 tone(pinSound,440,tiempo/2);
 delay(tiempo);
 tone(pinSound,392,tiempo/2);
 delay(tiempo);
 tone(pinSound,349,tiempo/2);
 delay(tiempo);

 tone(pinSound,294,tiempo/2);
 delay(tiempo);
 tone(pinSound,392,tiempo/2);
 delay(tiempo);
 tone(pinSound,261,tiempo/2);
 delay(tiempo);
 tone(pinSound,261,tiempo/2);
 delay(tiempo);

 tone(pinSound,261,tiempo/2);
 delay(tiempo);
 tone(pinSound,294,tiempo/2);
 delay(tiempo);
 tone(pinSound,329,tiempo/2);
 delay(tiempo);
 tone(pinSound,349,tiempo/2);
 delay(tiempo);

 tone(pinSound,349,tiempo/2);
 delay(tiempo);
 tone(pinSound,349,tiempo/2);
 delay(tiempo);
 tone(pinSound,349,tiempo/2);
 delay(tiempo);
 tone(pinSound,329,tiempo/2);
 delay(tiempo);
 tone(pinSound,349,tiempo/2);
 delay(tiempo);
 tone(pinSound,440,tiempo/2);
 delay(tiempo);
 tone(pinSound,392,tiempo/2);
 delay(tiempo);
 tone(pinSound,349,tiempo/2);
 delay(tiempo);

 tone(pinSound,349,tiempo/2);
 delay(tiempo);
 tone(pinSound,440,tiempo/2);
 delay(tiempo);
 tone(pinSound,523,tiempo/2);
 delay(tiempo);

 tone(pinSound,587,tiempo/2);
 delay(tiempo);
 tone(pinSound,493,tiempo/2);
 delay(tiempo);
 tone(pinSound,440,tiempo/2);
 delay(tiempo);
 tone(pinSound,523,tiempo/2);
 delay(tiempo);
 tone(pinSound,493,tiempo/2);
 delay(tiempo);
 tone(pinSound,392,tiempo/2);
 delay(tiempo);
 tone(pinSound,349,tiempo/2);
 delay(tiempo);
  }
  
void cancion_navida(){
  tone(pinSound,523,tiempo/2);
  delay(tiempo);
  tone(pinSound,880,tiempo/2);
  delay(tiempo);
  tone(pinSound,783,tiempo/2);
  delay(tiempo);
  tone(pinSound,698,tiempo/2);
  delay(tiempo);
  tone(pinSound,523,tiempo/2);
  delay(tiempo*2+200);

  tone(pinSound,523,tiempo/2);
  delay(tiempo/2);
  tone(pinSound,523,tiempo/2);
  delay(tiempo/2);

  tone(pinSound,523,tiempo/2);
  delay(tiempo);
  tone(pinSound,880,tiempo/2);
  delay(tiempo);
  tone(pinSound,783,tiempo/2);
  delay(tiempo);
  tone(pinSound,698,tiempo/2);
  delay(tiempo);

  tone(pinSound,587,tiempo/2);
  delay(tiempo*4);
    tone(pinSound,587,tiempo/2);
  delay(tiempo);

  tone(pinSound,933,tiempo/2);
  delay(tiempo);
  tone(pinSound,880,tiempo/2);
  delay(tiempo);
  tone(pinSound,783,tiempo/2);
  delay(tiempo);
  tone(pinSound,659,tiempo/2);
  delay(tiempo*2+200);

  tone(pinSound,1046,tiempo/2);
  delay(tiempo/2);  
  tone(pinSound,1046,tiempo/2);
  delay(tiempo/2); 
  tone(pinSound,1046,tiempo/2);
  delay(tiempo); 
  tone(pinSound,1046,tiempo/2);
  delay(tiempo); 
  tone(pinSound,933,tiempo/2);
  delay(tiempo); 
  tone(pinSound,783,tiempo/2);
  delay(tiempo);
  tone(pinSound,880,tiempo/2);
  delay(tiempo*4);

  tone(pinSound,523,tiempo/2);
  delay(tiempo);
  tone(pinSound,880,tiempo/2);
  delay(tiempo);
  tone(pinSound,783,tiempo/2);
  delay(tiempo);
  tone(pinSound,698,tiempo/2);
  delay(tiempo);
  tone(pinSound,523,tiempo/2);
  delay(tiempo*2+200);

  tone(pinSound,523,tiempo/2);
  delay(tiempo);
  tone(pinSound,880,tiempo/2);
  delay(tiempo);
  tone(pinSound,783,tiempo/2);
  delay(tiempo);
  tone(pinSound,698,tiempo/2);
  delay(tiempo);
  tone(pinSound,587,tiempo/2);
  delay(tiempo*2);

  tone(pinSound,587,tiempo/2);
  delay(tiempo);

  tone(pinSound,587,tiempo/2);
  delay(tiempo);

  tone(pinSound,933,tiempo/2);
  delay(tiempo);
  tone(pinSound,880,tiempo/2);
  delay(tiempo);
  tone(pinSound,783,tiempo/2);
  delay(tiempo);

  tone(pinSound,1046,tiempo/2);
  delay(tiempo);
  tone(pinSound,1046,tiempo/2);
  delay(tiempo);
  tone(pinSound,1046,tiempo/2);
  delay(tiempo);
  tone(pinSound,1046,tiempo/2);
  delay(tiempo);
  tone(pinSound,1174,tiempo/2);
  delay(tiempo);
  tone(pinSound,1046,tiempo/2);
  delay(tiempo);
  tone(pinSound,933,tiempo/2);
  delay(tiempo);
  tone(pinSound,783,tiempo/2);
  delay(tiempo);
  tone(pinSound,698,tiempo/2);
  delay(tiempo*2+100);

  tone(pinSound,880,tiempo/2);
  delay(tiempo);
  tone(pinSound,880,tiempo/2);
  delay(tiempo);
  tone(pinSound,880,tiempo/2);
  delay(tiempo*2);
  tone(pinSound,880,tiempo/2);
  delay(tiempo);
  tone(pinSound,880,tiempo/2);
  delay(tiempo);
  tone(pinSound,880,tiempo/2);
  delay(tiempo*2);
  tone(pinSound,880,tiempo/2);
  delay(tiempo);
  tone(pinSound,1046,tiempo/2);
  delay(tiempo);
  tone(pinSound,698,tiempo/2);
  delay(tiempo+tiempo/2);
   tone(pinSound,783,tiempo/2);
  delay(tiempo/2);
  tone(pinSound,880,tiempo/2);
  delay(tiempo*4);

  tone(pinSound,933,tiempo/2);
  delay(tiempo);
  tone(pinSound,933,tiempo/2);
  delay(tiempo);
  tone(pinSound,933,tiempo/2);
  delay(tiempo+tiempo/2);
  tone(pinSound,933,tiempo/2);
  delay(tiempo/2);
  tone(pinSound,933,tiempo/2);
  delay(tiempo);
  tone(pinSound,880,tiempo/2);
  delay(tiempo);
  tone(pinSound,880,tiempo/2);
  delay(tiempo);
  tone(pinSound,880,tiempo/2);
  delay(tiempo/2);
  tone(pinSound,880,tiempo/2);
  delay(tiempo/2);
  tone(pinSound,783,tiempo/2);
  delay(tiempo);
  tone(pinSound,783,tiempo/2);
  delay(tiempo);
  tone(pinSound,880,tiempo/2);
  delay(tiempo/2);
  tone(pinSound,783,tiempo/2);
  delay(tiempo*2);
  tone(pinSound,1046,tiempo/2);
  delay(tiempo*2);

  tone(pinSound,880,tiempo/2);
  delay(tiempo);
  tone(pinSound,880,tiempo/2);
  delay(tiempo);
  tone(pinSound,880,tiempo/2);
  delay(tiempo/2);
  tone(pinSound,880,tiempo/2);
  delay(tiempo);
  tone(pinSound,880,tiempo/2);
  delay(tiempo);
  tone(pinSound,880,tiempo/2);
  delay(tiempo/2);
  tone(pinSound,880,tiempo/2);
  delay(tiempo);
  tone(pinSound,1046,tiempo/2);
  delay(tiempo);
  tone(pinSound,698,tiempo/2);
  delay(tiempo+tiempo/2);
  tone(pinSound,783,tiempo/2);
  delay(tiempo);
  tone(pinSound,880,tiempo/2);
  delay(tiempo*4);

  tone(pinSound,933,tiempo/2);
  delay(tiempo);
  tone(pinSound,933,tiempo/2);
  delay(tiempo);
  tone(pinSound,933,tiempo/2);
  delay(tiempo+tiempo/2);
  tone(pinSound,933,tiempo/2);
  delay(tiempo/2);
  tone(pinSound,933,tiempo/2);
  delay(tiempo);
  tone(pinSound,880,tiempo/2);
  delay(tiempo);
  tone(pinSound,880,tiempo/2);
  delay(tiempo);

  tone(pinSound,880,tiempo/2);
  delay(tiempo/2);
  tone(pinSound,880,tiempo/2);
  delay(tiempo/2);

  tone(pinSound,1046,tiempo/2);
  delay(tiempo);

  tone(pinSound,1046,tiempo/2);
  delay(tiempo);
  tone(pinSound,933,tiempo/2);
  delay(tiempo);
  tone(pinSound,783,tiempo/2);
  delay(tiempo);
  tone(pinSound,698,tiempo/2);
  delay(tiempo*4);
  }
  
void cancion_dball(){
 tone(pinSound, 698, tiempo/2);
 delay(tiempo);
 tone(pinSound, 698, tiempo/2);
 delay(tiempo);
 tone(pinSound, 622, tiempo/2);
 delay(tiempo);   
 tone(pinSound, 523, tiempo/2);
 delay(tiempo);
 tone(pinSound, 698, tiempo/2);
 delay(tiempo*4);
   
 tone(pinSound, 698, tiempo/2);
 delay(tiempo);
 tone(pinSound, 698, tiempo/2);
 delay(tiempo);
 tone(pinSound, 622, tiempo/2);
 delay(tiempo);  
 tone(pinSound, 523, tiempo/2);
 delay(tiempo);
 tone(pinSound, 698, tiempo/2);
 delay(tiempo*4);
    
 tone(pinSound, 466, tiempo/2);
 delay(tiempo); 
 tone(pinSound, 466, tiempo/2);
 delay(tiempo);     
 tone(pinSound, 466, tiempo/2);
 delay(tiempo);
 tone(pinSound, 415, tiempo/2);
 delay(tiempo);  
 tone(pinSound, 466, tiempo/2);
 delay(tiempo);
 tone(pinSound, 466, tiempo/2);
 delay(tiempo);   
 tone(pinSound, 466, tiempo/2);
 delay(tiempo);
 tone(pinSound, 415, tiempo/2);
 delay(tiempo);
   
 tone(pinSound, 349, tiempo/2);
 delay(tiempo*5);
 tone(pinSound, 698, tiempo/2);
 delay(tiempo);  
 tone(pinSound, 698, tiempo/2);
 delay(tiempo);   
 tone(pinSound, 622, tiempo/2);
 delay(tiempo);
 tone(pinSound, 523, tiempo/2);
 delay(tiempo);
 
 tone(pinSound, 698, tiempo/2);
 delay(tiempo*5);
 tone(pinSound, 698, tiempo/2);
 delay(tiempo);
 tone(pinSound, 698, tiempo/2);
 delay(tiempo);
 tone(pinSound, 622, tiempo/2);
 delay(tiempo);
 tone(pinSound, 523, tiempo/2);
 delay(tiempo);
 
 tone(pinSound, 698, tiempo/2);
 delay(tiempo*5);
 tone(pinSound, 466, tiempo/2);
 delay(tiempo);
 tone(pinSound, 466, tiempo/2);
 delay(tiempo);
 tone(pinSound, 466, tiempo/2);
 delay(tiempo);
 tone(pinSound, 415, tiempo/2);
 delay(tiempo);    
 tone(pinSound, 466, tiempo/2);
 delay(tiempo);
 tone(pinSound, 466, tiempo/2);
 delay(tiempo);
 tone(pinSound, 466, tiempo/2);
 delay(tiempo);    
 tone(pinSound, 415, tiempo/2);
 delay(tiempo);
     
 tone(pinSound, 523, tiempo/2);
 delay(tiempo*5);
 tone(pinSound, 523, tiempo/2);
 delay(tiempo);
 tone(pinSound, 622, tiempo/2);
 delay(tiempo);
    
 tone(pinSound, 698, tiempo/2);
 delay(tiempo+200);
 tone(pinSound, 698, tiempo/2);
 delay(tiempo+200);
 tone(pinSound, 698, tiempo/2);
 delay(tiempo+200);
    
 tone(pinSound, 622, tiempo/2);
 delay(tiempo);
 tone(pinSound, 523, tiempo/2);
 delay(tiempo);
 tone(pinSound, 622, tiempo/2);
 delay(tiempo);
 tone(pinSound, 523, tiempo/2);
 delay(tiempo);
 tone(pinSound, 622, tiempo/2);
 delay(tiempo);
 tone(pinSound, 622, tiempo/2);
 delay(tiempo);
  
 tone(pinSound, 698, tiempo/2);
 delay(tiempo*3);  
 tone(pinSound, 523, tiempo/2);
 delay(tiempo);
 tone(pinSound, 622, tiempo/2);
 delay(tiempo);
    
tone(pinSound, 698, tiempo/2);
delay(tiempo*3); 
tone(pinSound, 830, tiempo/2);
delay(tiempo);
tone(pinSound, 783, tiempo/2);
delay(tiempo);
tone(pinSound, 698, tiempo/2);
delay(tiempo);
    
tone(pinSound, 622, tiempo/2);
delay(tiempo+200);
tone(pinSound, 830, tiempo/2);
delay(tiempo);
tone(pinSound, 783, tiempo/2);
delay(tiempo);

 tone(pinSound, 698, tiempo/2);
 delay(tiempo+200);

  }
 
