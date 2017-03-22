#include <Wire.h>
#include <OCROBOT_I2C_GPS.h>                                                                                                                                                                                    
GPS GPS(0x02);

byte hh,mm,ss,ms;
byte y,m,d;
uint16_t delayTime = 1000;
void setup() {
  Wire.begin();
  Serial.begin(9600);
}
void loop() {
  /*显示时间*/
  GPS.UtcDate(y,m,d);
  GPS.UtcTime(hh,mm,ss,ms);

  Serial.print("DATE:");
  Serial.print("20");
  Serial.print(y);
  Serial.print("/");
  Serial.print(m);
  Serial.print("/");
  Serial.println(d);

  Serial.print("Time:");
  Serial.print(hh);
  Serial.print(":");
  Serial.print(mm);
  Serial.print(":");
  Serial.print(ss);
  Serial.print(":");
  Serial.println(ms);

  /*显示纬度经度*/  
  Serial.print(GPS.LatitudeDirection());  //纬度 WGS84坐标系
  Serial.print(":");
  Serial.println(GPS.Latitude(),4);

  Serial.print(GPS.LongitudeDirection()); //经度 WGS84坐标系
  Serial.print(":");
  Serial.println(GPS.Longitude(),4);

  /*定位状态与有效卫星*/
  Serial.print("Pos:");
  Serial.println(GPS.Positioning()); //定位状态 0:无定位  1:SPS 模式定位  2:差分、SPS模式定位 3 :PPS 模式定位
  
  Serial.print("Sat:");
  Serial.println(GPS.Satellite()); //有效卫星数量

  /*水平定位精度与椭球高度*/

  Serial.print("HDOP:");
  Serial.println(GPS.HDOP()); //水平精度 单位米

  Serial.print("MSL:");
  Serial.println(GPS.MSL()); //椭球高，单位米

  /*航向与速度*/
  Serial.print("Course:");
  Serial.println(GPS.Course()); // 航向 单位度

  Serial.print("Speed:");
  Serial.print(GPS.Speed()); //速度，单位千米/小时
  Serial.println("km/h");

  /*海平面高*/
  Serial.print("SeaLevel:");
  Serial.println(GPS.SeaLevel()); // 海平面高，单位米

}