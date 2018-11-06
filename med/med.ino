#include<Wire.h>
#include<SPI.h>
#include"image.h"
#include"SSD1306Wire.h"
#define fsr_pin 2
SSD1306Wire display(0x3c,21,22);

int freq = 5000;
int ledchannel = 0;
int resolution = 8;


void setup() {
    Serial.begin(115200);
    Serial.println();
    display.init();//初始化(init)
    display.clear();//清除螢幕和緩衝區(clear)
    display.drawXbm(35, 0, Logo_width, Logo_height,LOGO1);//印出想顯示的畫面  display.drawXbm(X座標, Y座標, 圖片寬度, 圖片高度, 圖片名稱);
    display.display();//顯示畫面(display)
    
    Serial.begin(115200);
    ledcSetup(ledchannel,freq,resolution);
    ledcAttachPin(LED_BUILTIN,ledchannel);
    pinMode(32,INPUT);
}

void loop() {
    int fsr_value = analogRead(fsr_pin); // 讀取FSR
//    int led_value = map(fsr_value, 0, 4095, 0, 225); // 從0~1023映射到0~255
//    ledcWrite(led_pin, led_value); // 改變LED亮度
    Serial.println(fsr_value);
//    Serial.println(led_value);
    Serial.println("-------------");
    delay(100);

    int rd;
    rd=analogRead(32);
    Serial.println(rd);
    rd=map(rd,0,1028,0,255);
    ledcWrite(ledchannel,rd);
    delay(7);
    
    if (fsr_value>1000) {
    display.clear();//清除螢幕和緩衝區(clear)
    display.drawXbm(35, 0, Logo_width, Logo_height,LOGO);//印出想顯示的畫面  display.drawXbm(X座標, Y座標, 圖片寬度, 圖片高度, 圖片名稱);
    display.display();//顯示畫面(display)
    Serial.println("show LOGO");
   }
  else if(fsr_value>=200 && fsr_value<=500){ 
    display.clear();//清除螢幕和緩衝區(clear)
    display.drawXbm(35, 0, Logo_width, Logo_height,LOGO2);//印出想顯示的畫面  display.drawXbm(X座標, Y座標, 圖片寬度, 圖片高度, 圖片名稱);
    display.display();//顯示畫面(display)
    Serial.println("show LOGO2");
  }
  else if(fsr_value>=500 && fsr_value<=1000){ 
    display.clear();//清除螢幕和緩衝區(clear)
    display.drawXbm(35, 0, Logo_width, Logo_height,LOGO3);//印出想顯示的畫面  display.drawXbm(X座標, Y座標, 圖片寬度, 圖片高度, 圖片名稱);
    display.display();//顯示畫面(display)
    Serial.println("show LOGO3");  
  }
  else {
    display.clear();//清除螢幕和緩衝區(clear)
    display.drawXbm(35, 0, Logo_width, Logo_height,LOGO1);//印出想顯示的畫面  display.drawXbm(X座標, Y座標, 圖片寬度, 圖片高度, 圖片名稱);
    display.display();//顯示畫面(display)
    Serial.println("show LOGO1");
   }
  }
