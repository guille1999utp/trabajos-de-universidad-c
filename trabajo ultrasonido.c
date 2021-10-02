#INCLUDE<16F887.H>
#device adc = 10
#FUSES NOWDT, NOPUT, INTRC_IO, NOMCLR, NOPROTECT, NOBROWNOUT, NOWRT
#USE DELAY(internal = 8MHZ)
#use standard_io(C)
int32 fosc = 80000000;
#define P_ECHO PIN_C0
#define P_TRIG PIN_C1



#define LCD_DATA4  PIN_D4
#define LCD_DATA5  PIN_D5
#define LCD_DATA6  PIN_D6
#define LCD_DATA7  PIN_D7
#define LCD_RS_PIN   PIN_D0
#define LCD_ENABLE_PIN    PIN_D2
#define LCD_RW_PIN   PIN_D1

#INCLUDE<lcd.C>

#include <HCSR04.c>
#USE fast_io(a)
#USE fast_io(c)
#USE fast_io(d)
#INCLUDE<lcd.C>

int16 t,adc;

float distancia = 0;                                     // Variable para almacenar la distancia
float por;


void main()
{      
HCSR04_init();// Inicializa el sensor ultrasonico
lcd_init();
lcd_gotoxy(1,1);
lcd_cursor_on(false);
set_tris_c(0);

while(true)
   {

     delay_us(20);
     adc = por/0.0977517107;

   if(adc != 0){ 
   t = adc+985;
Output_bit(pin_c4,1);
delay_us(t);
Output_bit(pin_c4,0);
   t= 2000-adc;
   delay_us(t);
   }
  while(true){
       distancia = HCSR04_get_distance(); 
      if(distancia>20){
      if(distancia<50){
      
      por= ((distancia-20)*100)/30;
      
      lcd_gotoxy(1,1);
      printf(lcd_putc,"porc: %0.0f                          ",por);
      lcd_gotoxy(1,2);
      printf(lcd_putc,"Dist: %0.1f cm                    ", distancia);      // Imprime la distancia
   
     
        
      }else{
      por = 0;
       lcd_gotoxy(1,1);
      lcd_putc("error distancia                       ");
         lcd_gotoxy(1,2);
      printf(lcd_putc,"                         "); 
      t = 511.5 + 985;
Output_bit(pin_c4,1);
delay_us(t);
Output_bit(pin_c4,0);
   t= 2000 - 511.5;
   delay_us(t);
      }
     }else{
     por = 0;
     lcd_gotoxy(1,1);
     lcd_putc("error distancia                         ");
        lcd_gotoxy(1,2);
        printf(lcd_putc,"                           "); 
        t = 511.5 + 985;
Output_bit(pin_c4,1);
delay_us(t);
Output_bit(pin_c4,0);
   t= 2000 - 511.5;
   delay_us(t);
     }


break;


  }
  
   }
   }

   
