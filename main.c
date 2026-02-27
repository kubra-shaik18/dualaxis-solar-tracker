#include<Wire.h>
#include<Adafruit_SSD1306.h>
#include<ESP32Servo.h> 

#define SCREEN_WIDTH 125
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

Adafruit_SSD1306 display(SCREEN_WIDTH,SCREEN_HEIGHT,&Wire,OLED_RESET);
int nldr = 15;
int sldr = 2;
int eldr = 13;
int wldr = 4;
Servo myServo1;
Servo myServo2;
const int servoPin1 = 18;
const int servoPin2 = 19;


void setup() {
  myServo1.attach(servoPin1);
  myServo2.attach(servoPin2);
  display.begin(9600);
  if(!display.begin(SSD1306_SWITCHCAPVCC,0x3C))
  {
    for(;;);
  }
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  pinMode(nldr,INPUT_PULLDOWN);
  pinMode(sldr,INPUT_PULLDOWN);
  pinMode(eldr,INPUT_PULLDOWN);
  pinMode(wldr,INPUT_PULLDOWN);
  myServo1.write(90);
  delay(3000);
  }

void loop() {
  display.clearDisplay();
  display.setCursor(0,0);
  int nt = analogRead(nldr); 
  int st = analogRead(sldr);
  int et = analogRead(eldr);
  int wt = analogRead(wldr);
  display.println(nt);
  display.println(st);
  display.println(et);
  display.println(wt);
  display.display();
  delay(300);
  if(nt>2000 && nt>st && nt>et && nt>wt)
  {
  myServo1.write(120);
  myServo2.write(45);
  delay(1000);
  }
  else if (st>2000 && st>nt && st>et && st>wt){
  myServo1.write(120);
  myServo2.write(0);
  delay(1000);
  }
  else if(et>2000 && et>st && et>nt && et>wt){
  myServo1.write(60);
  myServo2.write(90);
  delay(1000);
  }
  else if(wt>2000 && wt>st && wt>nt && wt>et){
  myServo1.write(120);
  myServo2.write(170);
  delay(1000);
  }


}
