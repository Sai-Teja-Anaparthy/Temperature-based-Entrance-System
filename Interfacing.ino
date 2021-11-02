/*************************                  ---ENGINEERING CAPESTONE PROJECT 2021---         ************************************************
 *                   
 *                
 * Project By:    Robocon's
 * Group:         6
 * Group Members: Mandal, Kirti 
 *                Anaparthy, Sai Teja 
 *                Kurmaighari, Sai Teja
 * Project Name:  Temperature Based Entrance System
 * Submitted To:  Prof. Jarabek, Mike
 * Instructor:    Prof. Jarabek, Mike
   References:    Adafruit, Jul 29, 2012 http://www.adafruit.com/products/684
                  Shedboy71, 6th May 2016 http://www.arduinoprojects.net/lcd-projects/mlx90614-and-oled-display-example.php#codesyntax_1
 *
 *                
 **************************                 ---ENGINEERING CAPESTONE PROJECT 2021---         **************************************************/

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1331.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_MLX90614.h>
Adafruit_MLX90614 mlx = Adafruit_MLX90614();

// You can use any (4 or) 5 pins
#define sclk 13
#define mosi 11
#define cs   10
#define rst  9
#define dc   8
int ledpinred = 5;         //red
int ledpingreen = 6;         //green
int buzzer = 12;//the pin of the active buzzer
// Color definitions
#define BLACK           0x0000
#define BLUE            0x001F
#define RED             0xF800
#define GREEN           0x07E0
#define CYAN            0x07FF
#define MAGENTA         0xF81F
#define YELLOW          0xFFE0
#define WHITE           0xFFFF

Adafruit_SSD1331 display = Adafruit_SSD1331(&SPI, cs, dc, rst);

float p = 3.1415926;

void setup(void) 
{
  pinMode (ledpinred, OUTPUT);
  pinMode (ledpingreen, OUTPUT);
  pinMode(buzzer,OUTPUT);//initialize the buzzer pin as an output
  Serial.begin(9600);
  Serial.println("hello!");
  display.begin();
   Serial.println("MLX_90614 testing");  
  mlx.begin();
}

void loop() 
{
/*MLX90614 LOGIC*/
  Serial.print("Ambient = "); 
  Serial.print(mlx.readAmbientTempC()); 
  Serial.print("*C\tObject = "); 
  Serial.print(mlx.readObjectTempC()); 
  Serial.println(" Celsius");
  Serial.print("Ambient = ");
  Serial.print(mlx.readAmbientTempF()); 
  Serial.print("*F\tObject = "); 
  Serial.print(mlx.readObjectTempF()); 
  Serial.println(" Farenhite");
  Serial.println();
  delay(1000);
  /*MLX90614 ends*/
  
  /*OLED CODE LOGIC STARTS*/
   display.fillScreen(BLACK);
  display.setCursor(0, 5);
  display.setTextColor(RED);
  display.setTextSize(1);
  display.println("TEMPERATURE TEST");
  display.setTextColor(WHITE, CYAN);
  display.setTextSize(2);
  display.print("Amb=");
  display.print(mlx.readAmbientTempF());
  display.print("\n");
  display.setTextColor(WHITE, CYAN);
  display.setTextSize(2);
  display.print("Body=");
  display.println(mlx.readObjectTempF());
  
   display.setTextSize(1);
    display.setTextColor(YELLOW);
  display.print("ALL TEMPERATURES IN FARHENITE");
  delay(5000);
  display.setCursor(0, 5);
  display.fillScreen(BLACK); 
  if(mlx.readObjectTempF()<= 84.0)
  { 
    digitalWrite(ledpingreen, HIGH );    // turn the LED off by making the voltage LOW
    delay(1000);
    display.setTextColor(CYAN);
    display.setTextSize(0);
    display.println("    Action   ");
    display.setTextSize(2);
    display.setTextColor(GREEN);
    display.println(" Entry  Validate  *_* ");
    delay(5000);
    digitalWrite(ledpingreen, LOW);    // turn the LED ON by making the voltage HIGH
    delay(1000); 
  }
  else
   { 
    display.setCursor(0, 5);
    display.fillScreen(BLACK);
    digitalWrite(ledpinred, HIGH);    // turn the LED ON by making the voltage HIGH
   // delay(1000);
    digitalWrite(buzzer,HIGH);  
    delay(1000);//wait for 1ms
    display.setTextSize(0);
    display.setTextColor(CYAN);
    display.println("    Action   ");
    display.setTextSize(2);
   // display.print(millis() / 1000);
    display.setTextColor(RED);
    display.print("COVID-19 Alert     X ");
    delay(5000);
     digitalWrite(buzzer,LOW);
   // delay(1000);//wait for 1ms
    digitalWrite(ledpinred, LOW);    // turn the LED ON by making the voltage HIGH
    delay(1000); 
   }
  /*OLED CODE LOGIC ENDS*/
}
