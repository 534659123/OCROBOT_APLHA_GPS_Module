#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <OCROBOT_I2C_GPS.h>                                                                                                                                                                                    
GPS GPS(0x02);
LiquidCrystal_I2C lcd(0x20,16,2);

byte hh,mm,ss,ms;
byte y,m,d;
uint16_t delayTime = 3000;
void setup() {
  Wire.begin();
  lcd.init();  
  lcd.backlight();
}
void loop() {
  /*显示时间*/
  GPS.UtcDate(y,m,d);
  GPS.UtcTime(hh,mm,ss,ms);
  lcd.setCursor(0, 0);
  lcd.print("DATE:");
  lcd.print("20");
  lcd.print(y);
  lcd.print("/");
  lcd.print(m);
  lcd.print("/");
  lcd.print(d);
  lcd.setCursor(0, 1);
  lcd.print("Time:");
  lcd.print(hh);
  lcd.print(":");
  lcd.print(mm);
  lcd.print(":");
  lcd.print(ss);
  lcd.print(":");
  lcd.print(ms);
  delay(delayTime);
  lcd.clear();
  /*显示纬度经度*/  
  lcd.setCursor(0, 0);
  lcd.print(GPS.LatitudeDirection());  //纬度 WGS84坐标系
  lcd.print(":");
  lcd.print(GPS.Latitude(),4);

  lcd.setCursor(0, 1);
  lcd.print(GPS.LongitudeDirection()); //经度 WGS84坐标系
  lcd.print(":");
  lcd.print(GPS.Longitude(),4);
  delay(delayTime);
  lcd.clear();
  /*定位状态与有效卫星*/
  lcd.setCursor(0, 0);
  lcd.print("Pos:");
  lcd.print(GPS.Positioning()); //定位状态 0:无定位  1:SPS 模式定位  2:差分、SPS模式定位 3 :PPS 模式定位
  lcd.setCursor(0, 1);
  lcd.print("Sat:");
  lcd.print(GPS.Satellite()); //有效卫星数量
  delay(delayTime);
  lcd.clear();
  /*水平定位精度与椭球高度*/
  lcd.setCursor(0, 0);
  lcd.print("HDOP:");
  lcd.print(GPS.HDOP()); //水平精度 单位米
  lcd.setCursor(0, 1);
  lcd.print("MSL:");
  lcd.print(GPS.MSL()); //椭球高，单位米
  delay(delayTime);
  lcd.clear();
  /*航向与速度*/
  lcd.setCursor(0, 0);
  lcd.print("Course:");
  lcd.print(GPS.Course()); // 航向 单位度
  lcd.setCursor(0, 1);
  lcd.print("Speed:");
  lcd.print(GPS.Speed()); //速度，单位千米/小时
  lcd.print("km/h");
  delay(delayTime);                    
  lcd.clear();
  /*海平面高*/
  lcd.setCursor(0, 0);
  lcd.print("SeaLevel:");
  lcd.print(GPS.SeaLevel()); // 海平面高，单位米
  delay(delayTime);
  lcd.clear();
}