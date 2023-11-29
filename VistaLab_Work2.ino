//要求使用温湿度传感器，oled屏幕，蜂鸣器，按钮制作温度计，可设置报警阈值，超过报警阈值报警
#include "DHT.h"   //温度传感器模块
#include <Wire.h>  //以下屏幕+I2C通讯
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
//#include <IRremote.h>  //红外遥控
//电源0xFFA25D 菜单0xFFE21D 测试0xFF22DD 上0xFF02FD 左0xFFE01F 右0xFF906F 下0xFF9867
//确认0xFFA857 一0xFF30CF 二0xFF18E7 三0xFF7A85 四0xFF10EF 五0xFF38C7 六0xFF5AA5

#define DHTPIN 2
#define DHTTYPE DHT11
#define OLED_RESET 4  //不用改
#define screen_x 128
#define screen_y 64

float t = 0.00;
float threshold = 28.00;
int screen = 0;
int IRPin = 7;
int set = 0;
int change = 0;
int pinBuzzer = 3; //管脚3连接到蜂鸣器元件的基极

Adafruit_SSD1306 display(screen_x, screen_y, &Wire, OLED_RESET);
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  pinMode(6, INPUT);
  pinMode(5, INPUT);
  Serial.println("DHTtest");
  dht.begin();
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  //与屏幕通讯
  pinMode(pinBuzzer, OUTPUT); //设置pinBuzzer脚为输出状态
}

void loop() {
  digitalWrite(pinBuzzer, HIGH);
  Serial.println(screen);
  display.display();  // 开显示
  t = dht.readTemperature();
  //Serial.print("%  Temperature: ");
  //Serial.print(t);
  set = digitalRead(5);  //blue
  change = digitalRead(6); //green
  if (set == 1) {
    if (screen == 0) {
      screen = 1;
      delay(100);
    } else if (screen == 1) {
      screen = 0;
      delay(100);
    }
  }
  if (screen == 0) {
    ScreenMain();
    if(t > threshold){
      digitalWrite(pinBuzzer, LOW);//输出LOW电平,发声
      delay(100);
    }
  } else if (screen == 1) {
    Setting();
    if (change == 1){
      threshold += 0.1;
      if(threshold > 30.00){
       threshold = 20.00;
      }
      Setting();
    }
  }
}

void ScreenMain() {
  display.setTextColor(WHITE);  //开像素点发光
  display.clearDisplay();       //清屏

  display.setTextSize(2);   //设置字体大小
  display.setCursor(0, 0);  //设置显示位置
  display.println("Tem:");
  display.println(t);
}

void Setting() {
  display.setTextColor(WHITE);  //开像素点发光
  display.clearDisplay();       //清屏

  display.setTextSize(2);   //设置字体大小
  display.setCursor(0, 0);  //设置显示位置
  display.println("Set_Tem:");
  display.println(threshold);
}