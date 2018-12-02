
/*Reloj 12 hrs mediante el protocolo i2c*/

#include <LiquidCrystal_I2C.h>
#include<Wire.h>

LiquidCrystal_I2C lcd(0x3f,16,2);

unsigned int minutos=32;
unsigned int segundos=0;
unsigned int horas=11;
unsigned int dia=05;
unsigned int mes=03;
unsigned int anio=2018;

unsigned int cont=2;

void setup() {
  lcd.backlight();
  lcd.init();

}

void loop() {
   lcd.clear();
   lcd.print("Hora:");
   segundos++;
  if(segundos>59){
    minutos++;
    segundos=0;
  }
  if(minutos>59){
    horas++;
    minutos=0;
    segundos=0;
  }
  if(horas>=12)
  {
    cont++;
    horas=0;
    minutos=0;
    segundos=0;
    if (cont==3)
    {
      cont=1;
      dia++;
      
      if (((mes==1) || (mes==3)||(mes==5) ||(mes==7) || (mes==8) || (mes==10) ||(mes==12))&&(dia>31))
    {
        mes++;
        dia=1;
    
    }
      if (mes==13)
            {
              mes=1;
              anio++;
              dia=1; 
            } 
    
  
     if (((mes==4)||(mes==6) ||(mes==9) || (mes==11)&& (dia>30)))
         {
           mes++;
           dia=1; 
         }
  
    if (((mes==2) && (dia>28)))
        {
         mes++;
         dia=1; 
        }
      }
    }  
   
 if (horas==0)
 {
  lcd.print("12");
  lcd.print(":");
  if(minutos<10)lcd.print("0");
  lcd.print(minutos);
  lcd.print(":");
  if(segundos<10)lcd.print("0");
  lcd.print(segundos);
  lcd.print(" ");
  if(cont==1)lcd.print("AM");
  if(cont==2)lcd.print("PM");
  lcd.setCursor(0,1);
  lcd.print("Fecha:");
  if(dia<10)lcd.print("0");
  lcd.print(dia);
  lcd.print("/");
  if(mes<10)lcd.print("0");
  lcd.print(mes);
  lcd.print("/");
  lcd.print(anio); 
  delay(950);
 }
 
 if (horas!=0)
 {
  if(horas<10)lcd.print("0");
  lcd.print(horas);
  lcd.print(":");
  if(minutos<10)lcd.print("0");
  lcd.print(minutos);
  lcd.print(":");
  if(segundos<10)lcd.print("0");
  lcd.print(segundos);
  lcd.print(" ");
  if(cont==1)lcd.print("AM");
  if(cont==2)lcd.print("PM");
  lcd.setCursor(0,1);
  lcd.print("Fecha:");
  if(dia<10)lcd.print("0");
  lcd.print(dia);
  lcd.print("/");
  if(mes<10)lcd.print("0");
  lcd.print(mes);
  lcd.print("/");
  lcd.print(anio); 
  delay(950);
 }
}
