 #include "U8glib.h"            // U8glib library for the OLED
           
int vibrationMotor=7;
int analogInput = 1;
int value = 0;

U8GLIB_SH1106_128X64 u8g(U8G_I2C_OPT_NO_ACK);  // Display which does not send ACK


void setup()
{
   pinMode(analogInput, INPUT);
   pinMode(vibrationMotor, OUTPUT);
}
void loop(){
   digitalWrite(vibrationMotor, LOW);
   // read the value at analog input
   // read the value at analog input
  int heartValue = analogRead(analogInput);
  value = map(heartValue, 0, 1023, 40, 130);
  if (value<45) {
    digitalWrite(vibrationMotor, HIGH);
    value=0;
  }
  delay(20);
  u8g.firstPage();  
  do 
    {
     draw();      
    }
  while( u8g.nextPage() );
delay(500);
}

void draw(void) 
{
  u8g.setFont(u8g_font_profont17r);        // select font
  u8g.drawStr(22, 12, "PULSE"); 
  u8g.setPrintPos(30,40);
  u8g.drawRFrame(15, 20, 100, 30, 10);     // draws frame with rounded edges
  u8g.println(value);                        //Prints the voltage
  u8g.println(" BPM");
}
