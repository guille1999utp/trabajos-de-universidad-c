#INCLUDE <16F887.H>
#FUSES NOWDT, NOPUT, INTRC_IO, NOMCLR, NOPROTECT, NOBROWNOUT,NOWRT,XT,NOMCLR
#USE DELAY(internal = 8MHZ)
#USE fast_io(b)
#INCLUDE<lcd.C>
#INCLUDE<KBD4X4.C>

INT16  clave = 4050,pos = 0,tecla,num, tiempo,activar = 0,alerta;


#INT_TIMER0
void  temp()
{
if(activar == 1 ){
tiempo=tiempo+1;
if (tiempo%23684 == 0)
      {
        pos = 0;
        activar = 0;
      tiempo = 0;
      alerta = 1;
      }
}
}
VOID  MAIN()
{
kbd_init();
lcd_init();
port_b_pullups(255);
lcd_gotoxy(1,1);
lcd_cursor_on(false);

setup_timer_0(RTCC_INTERNAL|RTCC_DIV_8);
SET_TIMER0(231);
enable_interrupts(int_timer0);
 enable_interrupts(global);
lcd_gotoxy(1,1);
   printf(lcd_putc,"ingrese clave: ");
    lcd_gotoxy(1,2);
   printf(lcd_putc,"                  ");
   while (TRUE)
   {
    tecla = kbd_getc();
    if(alerta ==1 ){
  lcd_gotoxy(1,1);
   printf(lcd_putc,"ingrese clave:       ");
     lcd_gotoxy(1,2);
   printf(lcd_putc,"                 ");
   alerta = 0;
}
   
   if(tecla != 0){
   switch(tecla){
   case '#':
   if(pos == 0){
   if(num == clave ){
 Output_bit(pin_c1,0);
   lcd_gotoxy(1,1);
   printf(lcd_putc,"ok                ");
   lcd_gotoxy(1,2);
   printf(lcd_putc,"                 ");
   delay_ms(3000);
   Output_bit(pin_c1,1);
        num = 0;
        
   lcd_gotoxy(1,1);
   printf(lcd_putc,"ingrese clave: ");
     }else{
   
   lcd_gotoxy(1,1);
   printf(lcd_putc,"INCORRECTO             ");
   
   lcd_gotoxy(1,2);
   printf(lcd_putc,"                  ");
   delay_ms(2000);
   num = 0;
   lcd_gotoxy(1,1);
   printf(lcd_putc,"ingrese clave: ");
      }
   }
   
   
   
   
    if(pos == 1){
   if(num == clave ){
  lcd_gotoxy(1,1);
   printf(lcd_putc,"NUEVA CLAVE:4DGT");
   
   lcd_gotoxy(1,2);
   printf(lcd_putc,"                  ");
   num = 0;
   pos = 2;
    break;
     }else{
   
   lcd_gotoxy(1,1);
   printf(lcd_putc,"INCORRECTO             ");
   
   lcd_gotoxy(1,2);
   printf(lcd_putc,"                  ");
   delay_ms(2000);
    lcd_gotoxy(1,1);
   printf(lcd_putc,"CAMBIO DE CLAVE: ");
   num = 0;
      }
   }
   
      if(pos == 2){
  if(num > 999){
if( num < 10000){
 pos = 0;
 clave = num;
  lcd_gotoxy(1,1);
   printf(lcd_putc,"ingrese clave:   ");
   lcd_gotoxy(1,2);
   printf(lcd_putc,"                 ");
   activar = 0;
   tiempo = 0;
   break;
}
else{
   
   lcd_gotoxy(1,1);
   printf(lcd_putc,"INCORRECTO             ");
   
   lcd_gotoxy(1,2);
   printf(lcd_putc,"                  ");
   delay_ms(2000);
   num = 0;
   lcd_gotoxy(1,1);
   printf(lcd_putc,"NUEVA CLAVE:4DGT");
      }
 }else{
   
   lcd_gotoxy(1,1);
   printf(lcd_putc,"INCORRECTO             ");
   
   lcd_gotoxy(1,2);
   printf(lcd_putc,"                  ");
   delay_ms(2000);
   num = 0;
   lcd_gotoxy(1,1);
   printf(lcd_putc,"NUEVA CLAVE:4DGT ");
      }
  
   }
   
   
   
   
   
    break;
    case '*':
  num = 0;
   lcd_gotoxy(1,2);
   printf(lcd_putc,"                    ");
    break;
        case 'A':
        activar = 0;
        tiempo = 0;
        pos = 0;
        num = 0;
  lcd_gotoxy(1,1);
   printf(lcd_putc,"ingrese clave:   ");
    lcd_gotoxy(1,2);
   printf(lcd_putc,"               ");
    break;
        case 'B':
   activar = 1;
   lcd_gotoxy(1,1);
   printf(lcd_putc,"CAMBIO DE CLAVE: ");
   lcd_gotoxy(1,2);
   printf(lcd_putc,"                    ");
   pos = 1;
   num = 0;
   
    break;
    default:
    if(pos == 0){
   num = num * 10 + (tecla - 0x30);
   lcd_gotoxy(1,1);
   printf(lcd_putc,"ingrese clave: ");

if(num > 0){
if( num < 10){
 lcd_gotoxy(1,2);
   printf(lcd_putc,"*               ");
}}

 if(num > 9){
if( num < 100){
 lcd_gotoxy(1,2);
   printf(lcd_putc,"**               ");
}
}
 if(num > 99){
if( num < 1000){
 lcd_gotoxy(1,2);
   printf(lcd_putc,"***               ");
}
}
 if(num > 999){
if( num < 10000){
 lcd_gotoxy(1,2);
   printf(lcd_putc,"****               ");
}
 }
 
 if(num>9999){ 
 
num = 0;
       lcd_gotoxy(1,2);
   printf(lcd_putc,"               ");
 }
 }
 
 
 
    if(pos == 1){
   num = num * 10 + (tecla - 0x30);
   lcd_gotoxy(1,1);
   printf(lcd_putc,"CAMBIO DE CLAVE: ");
   
   if(num > 0){
if( num < 10){
 lcd_gotoxy(1,2);
   printf(lcd_putc,"*               ");
}}

 if(num > 9){
if( num < 100){
 lcd_gotoxy(1,2);
   printf(lcd_putc,"**               ");
}
}
 if(num > 99){
if( num < 1000){
 lcd_gotoxy(1,2);
   printf(lcd_putc,"***               ");
}
}
 if(num > 999){
if( num < 10000){
 lcd_gotoxy(1,2);
   printf(lcd_putc,"****               ");
}

 }
 if(num>9999){ 
 
num = 0;
       lcd_gotoxy(1,2);
   printf(lcd_putc,"               ");
 }
 }
 
  if(pos == 2){
   num = num * 10 + (tecla - 0x30);
   lcd_gotoxy(1,1);
   printf(lcd_putc,"NUEVA CLAVE 4DGT");
   lcd_gotoxy(1,2);
   printf(lcd_putc,"%lu", num);
 }
   break;
     } 
  }
   }
}
