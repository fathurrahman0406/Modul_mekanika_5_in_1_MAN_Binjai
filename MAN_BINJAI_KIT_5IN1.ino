#define magnet 12
#define sensor 11
#define UP A1
#define OK A0
#define DOWN A2
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 20, 4);
byte stt_sensor;
char data;
float tinggi;
void(* Reset)(void) = 0;
float waktu;
byte timer_start;
float massa;
float gravitasi;
int stt_percobaan = 0;
int counter;
int counter1;
float a;
float jarak;
float m1;
float m2;
float T;
float v;
float uk;
byte up;
byte ok;
byte down;
int setting;
int pilih;
int pilih_mode=1;
byte magneet=0;
int coba_gravitasi=0;
int GJB=0;
int BIDANG_MIRING=0;
int koefisien_gesek=0;
int Mesin_Atwood=0;


void setup()
{
  pinMode(magnet,OUTPUT);
  pinMode(sensor,INPUT);
  pinMode(OK,INPUT);
  pinMode(UP,INPUT);
  pinMode(DOWN,INPUT);
  digitalWrite(OK,HIGH);
  digitalWrite(UP,HIGH);
  digitalWrite(DOWN,HIGH);
  digitalWrite(9,HIGH);
  digitalWrite(10,HIGH);
	lcd.begin();
	lcd.backlight();
  Serial.begin(9600);
  lcd.setCursor(0,0);
  lcd.print(" Assalamu'alaikum  ");
  for (int x = 0;x<20;x++){
    lcd.setCursor(x,3);
    lcd.write(0xff);
    lcd.setCursor(0,1);
    lcd.print("Kit Mekanika 5 in 1 ");
    lcd.setCursor(0,2);
    lcd.print("     MAN Binjai     ");
    delay(70);
  }
  delay(1000);
  lcd.clear();
  Serial.println("A : gravitasi");
  Serial.println("B : GJB");
  Serial.println("C : B.Miring");
  Serial.println("D : Gesekan");
  Serial.println("E : Mesin Atwood");
  Serial.println();

}

void tombol_mode(){
  up    = digitalRead(UP);
  down  = digitalRead(DOWN);
  ok    = digitalRead(OK);
  if (up==0){delay(200);pilih_mode++;}
  else if (down==0){delay(200);pilih_mode--;}
  if (pilih_mode>5){pilih_mode=1;}
  else if (pilih_mode<1){pilih_mode=5;}
  if (ok == 0){
    lcd.clear();     
    lcd.setCursor(0,0);
    lcd.print("   Tunggu Sebentar   "); 
    for (int x = 0;x<20;x++){
      lcd.setCursor(x,3);
      lcd.write(0xff);
      delay(100);
    }
    stt_percobaan=pilih_mode;  

    pilih_mode=0; 
    lcd.clear();
    }
  
}



void loop()
{
  while (pilih_mode==1)   //memilih percobaan
  { 
    lcd.setCursor(0,0);
    lcd.print("A:Gravitasi<");
    lcd.setCursor(0,1);
    lcd.print("B:GJB ");
    lcd.setCursor(7,1);
    lcd.print("  C:B.Miring ");
    lcd.setCursor(0,2);
    lcd.print("D:Gesekan ");
    lcd.setCursor(0,3);
    lcd.print("E:Mesin Atwood ");
    tombol_mode();
    
  
  }

 while (pilih_mode==2)   //memilih percobaan
  { 
    
    lcd.setCursor(0,0);
    lcd.print("A:Gravitasi ");
    lcd.setCursor(0,1);
    lcd.print("B:GJB<");
    lcd.setCursor(7,1);
    lcd.print("  C:B.Miring ");
    lcd.setCursor(0,2);
    lcd.print("D:Gesekan ");
    lcd.setCursor(0,3);
    lcd.print("E:Mesin Atwood ");
    tombol_mode();
  }

   while (pilih_mode==3)   //memilih percobaan
  { 
    lcd.setCursor(0,0);
    lcd.print("A:Gravitasi ");
    lcd.setCursor(0,1);
    lcd.print("B:GJB ");
    lcd.setCursor(7,1);
    lcd.print("  C:B.Miring<");
    lcd.setCursor(0,2);
    lcd.print("D:Gesekan ");
    lcd.setCursor(0,3);
    lcd.print("E:Mesin Atwood ");
    tombol_mode();
  }

 while (pilih_mode==4)   //memilih percobaan
  { 
    lcd.setCursor(0,0);
    lcd.print("A:Gravitasi ");
    lcd.setCursor(0,1);
    lcd.print("B:GJB ");
    lcd.setCursor(7,1);
    lcd.print("  C:B.Miring ");
    lcd.setCursor(0,2);
    lcd.print("D:Gesekan<");
    lcd.setCursor(0,3);
    lcd.print("E:Mesin Atwood ");
    tombol_mode();
  }

   while (pilih_mode==5)   //memilih percobaan
  { 
    lcd.setCursor(0,0);
    lcd.print("A:Gravitasi ");
    lcd.setCursor(0,1);
    lcd.print("B:GJB ");
    lcd.setCursor(7,1);
    lcd.print("  C:B.Miring ");
    lcd.setCursor(0,2);
    lcd.print("D:Gesekan ");
    lcd.setCursor(0,3);
    lcd.print("E:Mesin Atwood<");
    tombol_mode();

  }











/******************************************percobaan gravitasi*****************************************/
while (stt_percobaan==1){
  while (coba_gravitasi==0){
    lcd.setCursor(0,  0);
    lcd.print("Masukan Nilai Tinggi");
    lcd.setCursor(7,  1);
    lcd.print(tinggi,0);
    lcd.print(" cm");
    lcd.setCursor(0,  3);
    lcd.print("'ok' Aktifkan magnet");
    up    = digitalRead(UP);
    down  = digitalRead(DOWN);
    ok    = digitalRead(OK);
    if (up==0){delay(100);tinggi++;lcd.clear();}
    else if (down==0){delay(100);tinggi--;lcd.clear();}
    if (tinggi<0){tinggi=0;}      //tinggi min
    if (tinggi>100){tinggi=100;}  //tinggi max. 
    if (ok==0){
       lcd.clear();
       for (int x = 0;x<20;x++){
        lcd.setCursor(x,1);
        lcd.write(0xff);
        delay(10);
       }
       lcd.clear();
       coba_gravitasi=1;} 
  }

  while (coba_gravitasi==1){
    lcd.clear();
    digitalWrite(magnet,HIGH);
    lcd.setCursor(0,  1);
    lcd.print("     'ok' Start     ");
    delay(100);
    digitalWrite(OK,HIGH);
    if (digitalRead(OK) == 0){
       for (int x = 0;x<20;x++){
        lcd.setCursor(x,2);
        lcd.write(0xff);
        delay(100);
       }
        counter1=millis(); 
        lcd.clear();
        coba_gravitasi=2;
    }
  }


 while (coba_gravitasi==2){          //PERCOBAAAN GRAVITASI
  digitalWrite(magnet,LOW);
  counter=millis()-counter1;
  waktu = counter*0.001;
  gravitasi = ((2*tinggi)/pow(waktu,2)); //RUMUS GRAVITASI
  lcd.setCursor(0,0);
  lcd.print("h : ");
  lcd.print(tinggi);
  lcd.print(" m");
  lcd.setCursor(0,1);
  lcd.print("t : ");
  lcd.print(waktu);
  lcd.print(" s");
  lcd.setCursor(0,2);
  lcd.print("g : ");
  lcd.print(gravitasi);
  lcd.print(" m/s^2      ");
  if (digitalRead(sensor) == 0){coba_gravitasi=3;lcd.clear(); }
 }

 while (coba_gravitasi==3){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("h : ");
  lcd.print(tinggi);
  lcd.print(" m");
  lcd.setCursor(0,1);
  lcd.print("t : ");
  lcd.print(waktu);
  lcd.print(" s");
  lcd.setCursor(0,2);
  lcd.print("g : ");
  lcd.print(gravitasi);
  lcd.print(" m/s^2");
  lcd.setCursor(0,3);
  lcd.print("      Selesai      ");
  digitalWrite(OK,HIGH);
  if (digitalRead(OK) == 0){Reset();}
  delay(1000);
 }
}

/******************************************percobaan gravitasi*****************************************/









/******************************************GJB*****************************************/
 while (stt_percobaan==2){//PERCOBAAN GJB
    while (GJB==0){
    lcd.setCursor(0,  0);
    lcd.print("Masukan Nilai Tinggi");
    lcd.setCursor(7,  1);
    lcd.print(tinggi,0);
    lcd.print(" cm");
    lcd.setCursor(0,  3);
    lcd.print("'ok' Aktifkan magnet");
    up    = digitalRead(UP);
    down  = digitalRead(DOWN);
    ok    = digitalRead(OK);
    if (up==0){delay(100);tinggi++;lcd.clear();}
    else if (down==0){delay(100);tinggi--;lcd.clear();}
    if (tinggi<0){tinggi=0;}      //tinggi min
    if (tinggi>100){tinggi=100;}  //tinggi max. 
    if (ok==0){
       lcd.clear();
       for (int x = 0;x<20;x++){
        lcd.setCursor(x,1);
        lcd.write(0xff);
        delay(10);
       }
       lcd.clear();
       GJB=1;
       } 
  }


  while (GJB==1){
    lcd.clear();
    digitalWrite(magnet,HIGH);
    lcd.setCursor(0,  1);
    lcd.print("     'ok' Start     ");
    delay(100);
    digitalWrite(OK,HIGH);
    if (digitalRead(OK) == 0){
       for (int x = 0;x<20;x++){
        lcd.setCursor(x,2);
        lcd.write(0xff);
        delay(100);
       }
        counter1=millis(); 
        lcd.clear();
        GJB=2;
    }
  }

 
 while (GJB == 2){
  digitalWrite(magnet,LOW);
  counter=millis()-counter1;
  waktu = counter*0.001;
  v = 9.8*waktu; //RUMUS 
  Serial.print("t:");
  Serial.println(waktu);
  Serial.print("v:");
  Serial.println(v);
  if (digitalRead(sensor) == 0){GJB=3;}
  lcd.setCursor(0,0);
  lcd.print("h : ");
  lcd.print(tinggi);
  lcd.print(" m");
  lcd.setCursor(0,1);
  lcd.print("t : ");
  lcd.print(waktu);
  lcd.print(" s");
  lcd.setCursor(0,2);
  lcd.print("V : ");
  lcd.print(v);
  lcd.print(" m/s       ");
 }

 while (GJB ==3){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("h : ");
  lcd.print(tinggi);
  lcd.print(" m");
  lcd.setCursor(0,1);
  lcd.print("t : ");
  lcd.print(waktu);
  lcd.print(" s");
  lcd.setCursor(0,2);
  lcd.print("V : ");
  lcd.print(v);
  lcd.print(" m/s");
  lcd.setCursor(0,3);
  lcd.print("      Selesai      ");
  digitalWrite(OK,HIGH);
  if (digitalRead(OK) == 0){Reset();}
  delay(1000);
 }
}

/******************************************GJB*****************************************/






/*****************************************BIDANG MIRING*****************************************/
  while (stt_percobaan==3){//BIDANG MIRING
   while (BIDANG_MIRING==0){
    lcd.setCursor(0,  0);
    lcd.print("Masukan Nilai Jarak  ");
    lcd.setCursor(7,  1);
    lcd.print(tinggi,0);
    lcd.print(" cm");
    lcd.setCursor(0,  3);
    lcd.print("'ok' Aktifkan magnet");
    up    = digitalRead(UP);
    down  = digitalRead(DOWN);
    ok    = digitalRead(OK);
    if (up==0){delay(100);tinggi++;lcd.clear();}
    else if (down==0){delay(100);tinggi--;lcd.clear();}
    if (tinggi<0){tinggi=0;}      //tinggi min
    if (tinggi>100){tinggi=100;}  //tinggi max. 
    if (ok==0){
       lcd.clear();
       for (int x = 0;x<20;x++){
        lcd.setCursor(x,1);
        lcd.write(0xff);
        delay(10);
       }
       lcd.clear();
       BIDANG_MIRING=1;
       } 
  }


  while (BIDANG_MIRING==1){
    lcd.clear();
    digitalWrite(magnet,HIGH);
    lcd.setCursor(0,  1);
    lcd.print("     'ok' Start     ");
    delay(100);
    digitalWrite(OK,HIGH);
    if (digitalRead(OK) == 0){
       for (int x = 0;x<20;x++){
        lcd.setCursor(x,2);
        lcd.write(0xff);
        delay(100);
       }
        counter1=millis(); 
        lcd.clear();
        BIDANG_MIRING=2;
    }
  }


 while (BIDANG_MIRING == 2){
  jarak = tinggi;
  stt_sensor = digitalRead(sensor);
  counter=millis()-counter1;
  waktu = counter*0.001;
  a = (2*jarak)/(waktu*waktu);
  if (stt_sensor == 0){BIDANG_MIRING=3;lcd.clear();}
  lcd.setCursor(0,0);
  lcd.print("s : ");
  jarak = tinggi;
  lcd.print(jarak);
  lcd.print(" m");
  lcd.setCursor(0,1);
  lcd.print("t : ");
  lcd.print(waktu);
  lcd.print(" s");
  lcd.setCursor(0,2);
  lcd.print("a : ");
  lcd.print(a);
  lcd.print(" m/s^2      ");
 }
 
while (BIDANG_MIRING == 3){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("s : ");
  jarak = tinggi;
  lcd.print(jarak);
  lcd.print(" m");
  lcd.setCursor(0,1);
  lcd.print("t : ");
  lcd.print(waktu);
  lcd.print(" s");
  lcd.setCursor(0,2);
  lcd.print("a : ");
  lcd.print(a);
  lcd.print(" m/s^2");
  lcd.setCursor(0,3);
  lcd.print("      Selesai      ");
  digitalWrite(OK,HIGH);
  if (digitalRead(OK) == 0){Reset();}
  delay(1000);
 }
}
/*****************************************BIDANG MIRING*****************************************/







/**************************************koefisien gesek*****************************************/
  while (stt_percobaan==4){//koefisien gesek
   while (koefisien_gesek==0){
    lcd.setCursor(0,  0);
    lcd.print("Masukan Nilai Tinggi ");
    lcd.setCursor(7,  1);
    lcd.print(tinggi,0);
    lcd.print(" cm");
    up    = digitalRead(UP);
    down  = digitalRead(DOWN);
    ok    = digitalRead(OK);
    if (up==0){delay(100);tinggi++;lcd.clear();}
    else if (down==0){delay(100);tinggi--;lcd.clear();}
    if (tinggi<0){tinggi=0;}      //tinggi min
    if (tinggi>100){tinggi=100;}  //tinggi max. 
    if (digitalRead(OK)==0){koefisien_gesek=1;delay(1000);lcd.clear();}
   }

   while (koefisien_gesek==1){
    lcd.setCursor(0,  0);
    lcd.print("Masukan Nilai Massa1");
    lcd.setCursor(7,  1);
    lcd.print(m1,1);
    lcd.print(" Kg");
    up    = digitalRead(UP);
    down  = digitalRead(DOWN);
    ok    = digitalRead(OK);
    if (up==0){delay(100);m1=m1+0.1;lcd.clear();}
    else if (down==0){delay(100);m1=m1-0.1;lcd.clear();}
    if (m1<0){m1=0;}      //tinggi min
    if (m1>10){m1=10;}  //tinggi max. 
    if (ok==0){koefisien_gesek=2;delay(1000);lcd.clear();}
   }


    while (koefisien_gesek==2){
    lcd.setCursor(0,  0);
    lcd.print("Masukan Nilai Massa2");
    lcd.setCursor(7,  1);
    lcd.print(m2,1);
    lcd.print(" Kg");
    lcd.setCursor(0,  3);
    lcd.print("'ok' Aktifkan magnet");
    up    = digitalRead(UP);
    down  = digitalRead(DOWN);
    ok    = digitalRead(OK);
    if (up==0){delay(100);m2=m2+0.1;lcd.clear();}
    else if (down==0){delay(100);m2=m2-0.1;lcd.clear();}
    if (m2<0){m2=0;}      //tinggi min
    if (m2>10){m2=10;}  //tinggi max. 
    if (ok==0){
       for (int x = 0;x<20;x++){
        lcd.setCursor(x,2);
        lcd.write(0xff);
        delay(100);
       } 
        lcd.clear();
        koefisien_gesek=3;
    }
  }

  while (koefisien_gesek==3){
    lcd.clear();
    digitalWrite(magnet,HIGH);
    lcd.setCursor(0,  1);
    lcd.print("     'ok' Start     ");
    delay(100);
    digitalWrite(OK,HIGH);
    if (digitalRead(OK) == 0){
       for (int x = 0;x<20;x++){
        lcd.setCursor(x,2);
        lcd.write(0xff);
        delay(100);
       }
        counter1=millis(); 
        lcd.clear();
        koefisien_gesek=4;
    }
  }
  


 while (koefisien_gesek == 4){
  digitalWrite(magnet,LOW);
  stt_sensor = digitalRead(sensor);
  counter=millis()-counter1;
  waktu = counter*0.001;
  gravitasi = ((2*tinggi)/pow(waktu,2));
  uk = (gravitasi*m1)-(((2*tinggi)/waktu*waktu)*(m1+m2));
  if (stt_sensor == 0){koefisien_gesek=5;}
  lcd.setCursor(0,0);
  lcd.print("H : ");
  lcd.print(tinggi,0);
  lcd.print(" m");
  lcd.setCursor(13,0);
  lcd.print("m1:");
  lcd.print(m1,1);
  lcd.setCursor(13,1);
  lcd.print("m2:");
  lcd.print(m2,1);
  lcd.setCursor(0,3);
  lcd.print("g : ");
  lcd.print(gravitasi,2);
  lcd.print(" m/s^2     ");
  lcd.setCursor(0,1);
  lcd.print("t : ");
  lcd.print(waktu);
  lcd.print(" s");
  lcd.setCursor(0,2);
  lcd.print("uk: ");
  lcd.print(uk);
  lcd.print(" N      ");
 }

 while (koefisien_gesek == 5)
 {
  lcd.setCursor(0,0);
  lcd.print("H : ");
  lcd.print(tinggi,0);
  lcd.print(" m");
  lcd.setCursor(13,0);
  lcd.print("m1:");
  lcd.print(m1,1);
  lcd.setCursor(13,1);
  lcd.print("m2:");
  lcd.print(m2,1);
  lcd.setCursor(0,3);
  lcd.print("g : ");
  lcd.print(gravitasi,2);
  lcd.print(" m/s^2     ");
  lcd.setCursor(0,1);
  lcd.print("t : ");
  lcd.print(waktu);
  lcd.print(" s");
  lcd.setCursor(0,2);
  lcd.print("uk: ");
  lcd.print(uk);
  lcd.print(" N      ");
  digitalWrite(OK,HIGH);
  if (digitalRead(OK) == 0){Reset();}
  delay(1000);
  }
 }
/*****************************************koefisien gesek*****************************************/








/*****************************************Mesin Atwood*****************************************/
  while (stt_percobaan==5){//Mesin Atwood
   while (Mesin_Atwood==0){
    lcd.setCursor(0,  0);
    lcd.print("Masukan Nilai Tinggi ");
    lcd.setCursor(7,  1);
    lcd.print(tinggi,0);
    lcd.print(" cm");
    up    = digitalRead(UP);
    down  = digitalRead(DOWN);
    ok    = digitalRead(OK);
    if (up==0){delay(100);tinggi++;lcd.clear();}
    else if (down==0){delay(100);tinggi--;lcd.clear();}
    if (tinggi<0){tinggi=0;}      //tinggi min
    if (tinggi>100){tinggi=100;}  //tinggi max. 
    if (digitalRead(OK)==0){Mesin_Atwood=1;delay(1000);lcd.clear();}
   }

   while (Mesin_Atwood==1){
    lcd.setCursor(0,  0);
    lcd.print("Masukan Nilai Massa1");
    lcd.setCursor(7,  1);
    lcd.print(m1,1);
    lcd.print(" Kg");
    up    = digitalRead(UP);
    down  = digitalRead(DOWN);
    ok    = digitalRead(OK);
    if (up==0){delay(100);m1=m1+0.1;lcd.clear();}
    else if (down==0){delay(100);m1=m1-0.1;lcd.clear();}
    if (m1<0){m1=0;}      //tinggi min
    if (m1>10){m1=10;}  //tinggi max. 
    if (ok==0){Mesin_Atwood=2;delay(1000);lcd.clear();}
   }


    while (Mesin_Atwood==2){
    lcd.setCursor(0,  0);
    lcd.print("Masukan Nilai Massa2");
    lcd.setCursor(7,  1);
    lcd.print(m2,1);
    lcd.print(" Kg");
    lcd.setCursor(0,  3);
    lcd.print("'ok' Aktifkan magnet");
    up    = digitalRead(UP);
    down  = digitalRead(DOWN);
    ok    = digitalRead(OK);
    if (up==0){delay(100);m2=m2+0.1;lcd.clear();}
    else if (down==0){delay(100);m2=m2-0.1;lcd.clear();}
    if (m2<0){m2=0;}      //tinggi min
    if (m2>10){m2=10;}  //tinggi max. 
    if (ok==0){
       for (int x = 0;x<20;x++){
        lcd.setCursor(x,2);
        lcd.write(0xff);
        delay(100);
       } 
        lcd.clear();
        Mesin_Atwood=3;
    }
  }

  while (Mesin_Atwood==3){
    lcd.clear();
    digitalWrite(magnet,HIGH);
    lcd.setCursor(0,  1);
    lcd.print("     'ok' Start     ");
    delay(100);
    digitalWrite(OK,HIGH);
    if (digitalRead(OK) == 0){
       for (int x = 0;x<20;x++){
        lcd.setCursor(x,2);
        lcd.write(0xff);
        delay(100);
       }
        counter1=millis(); 
        lcd.clear();
        Mesin_Atwood=4;
    }
  }
  

 while (Mesin_Atwood == 4){
  digitalWrite(magnet,LOW);
  jarak = tinggi;
  stt_sensor = digitalRead(sensor);
  counter=millis()-counter1;
  waktu = counter*0.001;
  gravitasi = ((2*tinggi)/pow(waktu,2));
  a = ((m1-m2)/(m1+m2))*gravitasi;
  T = (m1*gravitasi)-(m1*a);
  if (stt_sensor == 0){Mesin_Atwood=5;}
  lcd.setCursor(0,0);
  lcd.print("H : ");
  jarak = tinggi;
  lcd.print(jarak,1);
  lcd.print(" m");
  lcd.setCursor(13,0);
  lcd.print("m1:");
  lcd.print(m1,1);
  lcd.setCursor(13,1);
  lcd.print("m2:");
  lcd.print(m2,1);
  lcd.setCursor(13,3);
  lcd.print("g:");
  lcd.print(gravitasi,1);
  lcd.print(" ");
  lcd.setCursor(0,1);
  lcd.print("t : ");
  lcd.print(waktu,1);
  lcd.print(" s ");
  lcd.setCursor(0,2);
  lcd.print("a : ");
  lcd.print(a,2);
  lcd.print(" m/s^2    ");
  lcd.setCursor(0,3);
  lcd.print("T : ");
  lcd.print(T);
  lcd.print(" N  ");
 }

 while (Mesin_Atwood == 5){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("H : ");
  jarak = tinggi;
  lcd.print(jarak,1);
  lcd.print(" m");
  lcd.setCursor(13,0);
  lcd.print("m1:");
  lcd.print(m1,1);
  lcd.setCursor(13,1);
  lcd.print("m2:");
  lcd.print(m2,1);
  lcd.setCursor(13,3);
  lcd.print("g:");
  lcd.print(gravitasi,1);
  lcd.print(" ");
  lcd.setCursor(0,1);
  lcd.print("t : ");
  lcd.print(waktu,1);
  lcd.print(" s ");
  lcd.setCursor(0,2);
  lcd.print("a : ");
  lcd.print(a,2);
  lcd.print(" m/s^2    ");
  lcd.setCursor(0,3);
  lcd.print("T : ");
  lcd.print(T);
  lcd.print(" N  ");
  delay(1000);
  digitalWrite(OK,HIGH);
  if (digitalRead(OK) == 0){Reset();}
  
  
  }
 }
}

/*****************************************Mesin Atwood*****************************************/











/******************** yang ini program menggunakan serial monitor***************************************/
/*
{
  while (stt_percobaan==0){ //memilih percobaan
  lcd.setCursor(0,0);
  lcd.print("A:Gravitasi");
  lcd.setCursor(0,1);
  lcd.print("B:GJB");
  lcd.setCursor(7,1);
  lcd.print("  C:B.Miring");
  lcd.setCursor(0,2);
  lcd.print("D:Gesekan");
  lcd.setCursor(0,3);
  lcd.print("E:Mesin Atwood");
  if (Serial.available()){
    data = Serial.read();
    if (data == 'A'){
      stt_percobaan=1;
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("      Percepatan     ");
      lcd.setCursor(0,1);
      lcd.print("    Gravitasi Bumi   ");
      delay(2000);
      lcd.clear();
      Serial.println("Masukkan Nilai H 'H+nilai'");
      Serial.println("A : Aktifkan Magnet");
      Serial.println("S : Start Uji");
    }
    if (data == 'B'){
      stt_percobaan=2;
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("  Gerak Jatuh Bebas  ");
      lcd.setCursor(0,1);
      lcd.print("         GJB         ");
      delay(2000);
      lcd.clear();
      Serial.println("Masukkan Nilai H 'H+nilai'");
      Serial.println("A : Aktifkan Magnet");
      Serial.println("S : Start Uji");
    }
    else if (data == 'C'){
      stt_percobaan=3;
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Konsep Bidang Miring ");
      delay(2000);
      lcd.clear();
      Serial.println("Masukkan Nilai Jarak 'J+nilai'");
      Serial.println("A : Aktifkan Magnet");
      Serial.println("S : Start Uji");
    }
    else if (data == 'D'){
      stt_percobaan=4;
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("  Koefisien Gesekan  ");
      lcd.setCursor(0,1);
      lcd.print("      Kinetis       ");
      delay(2000);
      lcd.clear();
      Serial.println("Masukkan Nilai Tinggi 'H+nilai'");
      Serial.println("Masukkan Nilai massa1 'M+nilai'");
      Serial.println("Masukkan Nilai massa2 'm+nilai'");
      Serial.println("A : Aktifkan Magnet");
      Serial.println("S : Start Uji");
    }
    else if (data == 'E'){
      stt_percobaan=5;
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("    Mesin Atwood    ");
      delay(2000);
      lcd.clear();
      Serial.println("Masukkan Nilai Tinggi 'H+nilai'");
      Serial.println("Masukkan Nilai massa1 'M+nilai'");
      Serial.println("Masukkan Nilai massa2 'm+nilai'");
      Serial.println("A : Aktifkan Magnet");
      Serial.println("S : Start Uji");
    }
  }
}




while (stt_percobaan==1){
  if (Serial.available()){
    data = Serial.read();
    if (data == 'H'){
      tinggi = Serial.parseFloat();
    }
    else if (data == 'R'){
      Reset();
    }
    else if (data == 'A'){
      digitalWrite(magnet,HIGH);;
    }
    else if (data == 'S'){
      delay(5000);
      digitalWrite(magnet,LOW);
      timer_start = 1;
    }
  }


 counter1=millis();
 while (timer_start == 1){ //PERCOBAAAN GRAVITASI
  stt_sensor = digitalRead(sensor);
  counter=millis()-counter1;
  waktu = counter*0.001;
  gravitasi = ((2*tinggi)/pow(waktu,2)); //RUMUS GRAVITASI
  if (stt_sensor == 0){timer_start=0;}
  lcd.setCursor(0,1);
  lcd.print("t : ");
  lcd.print(waktu);
  Serial.print("t:");
  Serial.println(waktu);
  Serial.print("g:");
  Serial.println(gravitasi);
 }
 
  stt_sensor = digitalRead(sensor);
  lcd.setCursor(0,0);
  lcd.print("h : ");
  lcd.print(tinggi);
  lcd.print(" m");
  lcd.setCursor(0,1);
  lcd.print("t : ");
  lcd.print(waktu);
  lcd.print(" s");
  lcd.setCursor(0,2);
  lcd.print("g : ");
  lcd.print(gravitasi);
  lcd.print(" m/s^2");
 }



 while (stt_percobaan==2){//PERCOBAAN GJB
  if (Serial.available()){
    data = Serial.read();
    if (data == 'H'){
      tinggi = Serial.parseFloat();
    }
    else if (data == 'R'){
      Reset();
    }
    else if (data == 'A'){
      digitalWrite(magnet,HIGH);;
    }
    else if (data == 'S'){
      delay(5000);
      digitalWrite(magnet,LOW);
      timer_start = 1;
    }
  }


 counter1=millis();
 while (timer_start == 1){
  stt_sensor = digitalRead(sensor);
  counter=millis()-counter1;
  waktu = counter*0.001;
  v = 9.8*waktu; //RUMUS 
  Serial.print("t:");
  Serial.println(waktu);
  Serial.print("v:");
  Serial.println(v);
  if (stt_sensor == 0){timer_start=0;}
  lcd.setCursor(0,1);
  lcd.print("t : ");
  lcd.print(waktu);
 }
 
  stt_sensor = digitalRead(sensor);
  lcd.setCursor(0,0);
  lcd.print("h : ");
  lcd.print(tinggi);
  lcd.print(" m");
  lcd.setCursor(0,1);
  lcd.print("t : ");
  lcd.print(waktu);
  lcd.print(" s");
  lcd.setCursor(0,2);
  lcd.print("V : ");
  lcd.print(v);
  lcd.print(" m/s");
 }




  while (stt_percobaan==3){//BIDANG MIRING
  if (Serial.available()){
    data = Serial.read();
    if (data == 'J'){
      tinggi = Serial.parseFloat();
    }
    else if (data == 'R'){
      Reset();
    }
    else if (data == 'A'){
      digitalWrite(magnet,HIGH);;
    }
    else if (data == 'S'){
      delay(5000);
      digitalWrite(magnet,LOW);
      timer_start = 1;
    }
  }


 counter1=millis();
 while (timer_start == 1){
  jarak = tinggi;
  stt_sensor = digitalRead(sensor);
  counter=millis()-counter1;
  waktu = counter*0.001;
  a = (2*jarak)/(waktu*waktu);
  Serial.print("t:");
  Serial.println(waktu);
  Serial.print("a:");
  Serial.println(a);
  if (stt_sensor == 0){timer_start=0;}
  lcd.setCursor(0,1);
  lcd.print("t : ");
  lcd.print(waktu);
 }
 
  stt_sensor = digitalRead(sensor);
  lcd.setCursor(0,0);
  lcd.print("s : ");
  jarak = tinggi;
  lcd.print(jarak);
  lcd.print(" m");
  lcd.setCursor(0,1);
  lcd.print("t : ");
  lcd.print(waktu);
  lcd.print(" s");
  lcd.setCursor(0,2);
  lcd.print("a : ");
  lcd.print(a);
  lcd.print(" m/s^2");
 }




  while (stt_percobaan==4){//koefisien gesek
  if (Serial.available()){
    data = Serial.read();
    if (data == 'H'){
      tinggi = Serial.parseFloat();
    }
    else if (data == 'M'){
      m1 = Serial.parseFloat();
    }
    else if (data == 'm'){
      m2 = Serial.parseFloat();
    }
    else if (data == 'R'){
      Reset();
    }
    else if (data == 'A'){
      digitalWrite(magnet,HIGH);;
    }
    else if (data == 'S'){
      delay(5000);
      digitalWrite(magnet,LOW);
      timer_start = 1;
    }
  }


 counter1=millis();
 while (timer_start == 1){
  stt_sensor = digitalRead(sensor);
  counter=millis()-counter1;
  waktu = counter*0.001;
  gravitasi = ((2*tinggi)/pow(waktu,2));
  uk = (gravitasi*m1)-(((2*tinggi)/waktu*waktu)*(m1+m2));
  Serial.print("t:");
  Serial.println(waktu);
  Serial.print("g:");
  Serial.println(gravitasi);
  Serial.print("uk:");
  Serial.println(uk);
  if (stt_sensor == 0){timer_start=0;}
  lcd.setCursor(0,1);
  lcd.print("t : ");
  lcd.print(waktu);
 }
 
  stt_sensor = digitalRead(sensor);
  lcd.setCursor(0,0);
  lcd.print("H : ");
  lcd.print(tinggi);
  lcd.print(" m");
  lcd.setCursor(13,0);
  lcd.print("m1:");
  lcd.print(m1);
  lcd.setCursor(13,1);
  lcd.print("m2:");
  lcd.print(m2);
  lcd.setCursor(0,3);
  lcd.print("g : ");
  lcd.print(gravitasi);
  lcd.setCursor(0,1);
  lcd.print("t : ");
  lcd.print(waktu);
  lcd.print(" s");
  lcd.setCursor(0,2);
  lcd.print("uk: ");
  lcd.print(uk);
  lcd.print("  ");
 }



  while (stt_percobaan==5){//Mesin Atwood
  if (Serial.available()){
    data = Serial.read();
    if (data == 'H'){
      tinggi = Serial.parseFloat();
    }
    else if (data == 'M'){
      m1 = Serial.parseFloat();
    }
    else if (data == 'm'){
      m2 = Serial.parseFloat();
    }
    else if (data == 'R'){
      Reset();
    }
    else if (data == 'A'){
      digitalWrite(magnet,HIGH);;
    }
    else if (data == 'S'){
      delay(5000);
      digitalWrite(magnet,LOW);
      timer_start = 1;
    }
  }


 counter1=millis();
 while (timer_start == 1){
  jarak = tinggi;
  stt_sensor = digitalRead(sensor);
  counter=millis()-counter1;
  waktu = counter*0.001;
  gravitasi = ((2*tinggi)/pow(waktu,2));
  a = ((m1-m2)/(m1+m2))*gravitasi;
  T = (m1*gravitasi)-(m1*a);
  Serial.print("t:");
  Serial.println(waktu);
  Serial.print("g:");
  Serial.println(gravitasi);
  Serial.print("a:");
  Serial.println(a);
  Serial.print("T:");
  Serial.println(T);
  if (stt_sensor == 0){timer_start=0;}
  lcd.setCursor(0,1);
  lcd.print("t : ");
  lcd.print(waktu);
 }
 
  stt_sensor = digitalRead(sensor);
  lcd.setCursor(0,0);
  lcd.print("H : ");
  jarak = tinggi;
  lcd.print(jarak);
  lcd.print(" m");
  lcd.setCursor(13,0);
  lcd.print("m1:");
  lcd.print(m1);
  lcd.setCursor(13,1);
  lcd.print("m2:");
  lcd.print(m2);
  lcd.setCursor(13,3);
  lcd.print("g:");
  lcd.print(gravitasi);
  lcd.setCursor(0,1);
  lcd.print("t : ");
  lcd.print(waktu);
  lcd.print(" s");
  lcd.setCursor(0,2);
  lcd.print("a : ");
  lcd.print(a);
  lcd.print(" m/s^2 ");
  lcd.setCursor(0,3);
  lcd.print("T : ");
  lcd.print(T);
  lcd.print(" N ");
 }
}


*/


