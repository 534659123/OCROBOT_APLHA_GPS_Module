#include <Wire.h>
/***********/
byte I2CAddr = 10;   //需要修改的地址，请自行修改 （取值范围1-127）
/***********/
void setup() {
  Wire.begin();        // 初始化I2C接口
  Serial.begin(9600);

  Wire.beginTransmission(2); //设备默认地址 本设备GPS模块 = 2
  Wire.write(200);              // 修改地址的操作码
  Wire.write(I2CAddr);     //向I2C设备写入新地址
  Wire.endTransmission();    // stop transmitting
  
Serial.println("OK");    //串口显示OK则完成写入，拨动模块开关并重新上电即可
}

void loop() {
  // put your main code here, to run repeatedly:

}