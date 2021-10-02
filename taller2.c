//nicolas arrieta

#INCLUDE<16F887.H>
#FUSES NOWDT, NOPUT, INTRC_IO, NOMCLR, NOPROTECT, NOBROWNOUT, NOWRT
#USE DELAY(internal = 8MHZ)
#USE fast_io(b)
#USE fast_io(d)
#INCLUDE<lcd.C>
#INCLUDE<KBD4X4.C>

int16 entrada = 0;int repeticiones = 0;int boton;int tiempo = 10  ;
void main(){lcd_init(); kbd_init(); port_b_pullups(1023); lcd_gotoxy(1,1);lcd_cursor_on(true); while(true)
{ boton = kbd_getc(); if(boton != 0){ switch(boton){
case '*': if(entrada == 47531 ){ while(tiempo >= 1){ lcd_gotoxy(1,1);
   printf(lcd_putc,"bienvenido: %u      ",tiempo);lcd_gotoxy(1,2);printf(lcd_putc,"                 ");tiempo = tiempo - 1;delay_ms(200); 
   if(suma == 0){ break;   }   }entrada = 0;tiempo = 10;lcd_gotoxy(1,1); printf(lcd_putc,"ingrese clave: "); } else{repeticiones = repeticiones+1;num = 0;
   }
   if(repeticiones == 3 ){ lcd_gotoxy(1,1);printf(lcd_putc,"ERROR               "); lcd_gotoxy(1,2);printf(lcd_putc,"               ");} break;default:entrada = entrada * 10 + (boton - 0x30);
   lcd_gotoxy(1,1);printf(lcd_putc,"ingrese clave: "); lcd_gotoxy(1,2);printf(lcd_putc,"%lu", entrada);
   break;
     } }
 if(repeticiones == 3 ){
  break;
      }}}
