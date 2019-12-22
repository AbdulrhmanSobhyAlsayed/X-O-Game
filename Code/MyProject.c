#include "T6963C_MikroC_PRO.h"  // include this if using MikroC PRO

 int j = 0;

 int i =0;
 int cc = 0;
 char txt ;
 int counter=0;
 int key;
 char keystr[2];
 int a0=1,a1=1,a2=1,a3=1,a4=1,a5=1,a6=1,a7=1,a8=1;

  unsigned short kp;

  char  keypadPort at PORTE;

 char* set_value(int counter){
     if (counter %2 == 0){
        return "O";
     }
     else{
        return "X";
     }
 }

 
//=============================================================================
//  MAIN
//=============================================================================
void main()
{
  Keypad_Init();
  
  //-------------------------------------------------------
  // setup PIC 18F8527 for SmartGLCD pins
  CMCON = 0x07;        // turn off comparators (make all pins digital)

  LATC =  0b00000110;   // LEDs off at start
  TRISC = 0b00011000;   // C1, C2 backlight LED
  LATG =  0b00000001;   // LED off at start
  TRISG = 0b00000000;   // G0 backlight LED
  LATJ  = 0b00000000;   // RJ6=FS (1=font6 0=font8), RJ5=MD
  TRISJ = 0b00000000;   // GLCD control port

  BacklightRed    = 0;
  BacklightGreen  = 0;    // green is on
  BacklightBlue   = 1;

  //-------------------------------------------------------
  // startup delay, let the PSU voltage stabilise etc.
  Delay_ms(10);

  // Initialize T6963C GLCD  T6963C_init(240, 128, 8, &PORTH, &PORTJ, 2, 1, 0, 4); // init for MikroC version
  T6963C_init(240, 128, 5);   // init for MikroC PRO version
  T6963C_graphics(0);       // graphics mode = on
  T6963C_text(1);           // text mode = on (now both are on)
  T6963C_cursor(0);         // cursor = off
  
  

  TRISE=0xFF;




  
  for( i =0;i<30;i++){
      T6963C_write_text("-",i,5,T6963C_ROM_MODE_TEXT);
      T6963C_write_text("-",i,10,T6963C_ROM_MODE_TEXT);
  }
  for( j=0; j<20;j++){
      T6963C_write_text("|",10,j,T6963C_ROM_MODE_TEXT);
      T6963C_write_text("|",20,j,T6963C_ROM_MODE_TEXT);
  }
  


 
  T6963C_write_text("_",5,2.5,T6963C_ROM_MODE_TEXT);
    T6963C_write_text("_",15,2.5,T6963C_ROM_MODE_TEXT);
    T6963C_write_text("_",25,2.5,T6963C_ROM_MODE_TEXT);
    T6963C_write_text("_",5,7.5,T6963C_ROM_MODE_TEXT);
    T6963C_write_text("_",15,7.5,T6963C_ROM_MODE_TEXT);
    T6963C_write_text("_",25,7.5,T6963C_ROM_MODE_TEXT);
    T6963C_write_text("_",5,12.5,T6963C_ROM_MODE_TEXT);
    T6963C_write_text("_",15,12.5,T6963C_ROM_MODE_TEXT);
    T6963C_write_text("_",25,12.5,T6963C_ROM_MODE_TEXT);
  while(1){
    Delay_ms(50);
    if (RE0_bit && a0){
    T6963C_write_text(set_value(counter),5,2.5,T6963C_ROM_MODE_TEXT);
    counter++;
    a0 = 0;
    }
    else if (RE1_bit && a1){
    T6963C_write_text(set_value(counter),15,2.5,T6963C_ROM_MODE_TEXT);
    counter++;
    a1 = 0;
    }
    else if (RE2_bit && a2){
    T6963C_write_text(set_value(counter),25,2.5,T6963C_ROM_MODE_TEXT);
    counter++;
    a2 = 0;
    }
    else if (RE3_bit && a3){
    T6963C_write_text(set_value(counter),5,7.5,T6963C_ROM_MODE_TEXT);
    counter++;
    a3 = 0;
    }
    else if (RE4_bit && a4){
    T6963C_write_text(set_value(counter),15,7.5,T6963C_ROM_MODE_TEXT);
    counter++;
    a4 = 0;
    }
    else if (RE5_bit && a5){
    T6963C_write_text(set_value(counter),25,7.5,T6963C_ROM_MODE_TEXT);
    counter++;
    a5 = 0;
    }
    else if (RE6_bit && a6){
    T6963C_write_text(set_value(counter),5,12.5,T6963C_ROM_MODE_TEXT);
    counter++;
    a6 = 0;
    }
    else if (RE7_bit && a7){
    T6963C_write_text(set_value(counter),15,12.5,T6963C_ROM_MODE_TEXT);
    counter++;
    a7 = 0;
    }
    else if (RC3_bit && a8){
    T6963C_write_text(set_value(counter),25,12.5,T6963C_ROM_MODE_TEXT);
    counter++;
    a8 = 0;
    }
    else if(RC4_bit){
        T6963C_write_text("_",5,2.5,T6963C_ROM_MODE_TEXT);
        T6963C_write_text("_",15,2.5,T6963C_ROM_MODE_TEXT);
        T6963C_write_text("_",25,2.5,T6963C_ROM_MODE_TEXT);
        T6963C_write_text("_",5,7.5,T6963C_ROM_MODE_TEXT);
        T6963C_write_text("_",15,7.5,T6963C_ROM_MODE_TEXT);
        T6963C_write_text("_",25,7.5,T6963C_ROM_MODE_TEXT);
        T6963C_write_text("_",5,12.5,T6963C_ROM_MODE_TEXT);
        T6963C_write_text("_",15,12.5,T6963C_ROM_MODE_TEXT);
        T6963C_write_text("_",25,12.5,T6963C_ROM_MODE_TEXT);
        counter = 0;
        a0 = 1;
        a1 = 1;
        a2 = 1;
        a3 = 1;
        a4 = 1;
        a5 = 1;
        a6 = 1;
        a7 = 1;
        a8 = 1;
        }
}
}