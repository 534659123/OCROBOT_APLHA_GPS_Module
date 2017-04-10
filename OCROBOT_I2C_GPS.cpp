#include "OCROBOT_I2C_GPS.h"


GPS::GPS(byte Addr)
{
	_addr = Addr;
}


void GPS::UtcTime(byte &UTC_HH, byte &UTC_MM, byte &UTC_SS, byte &UTC_MS)
{
	Wire.beginTransmission(_addr); //像指定地址设备发送请求
	Wire.write(1);              // 请求指令码
	Wire.endTransmission();    // 停止指令
	
	/*接收返回数据*/
	Wire.requestFrom((int)_addr, (int)4);    // 从指定的地址读取4个字节
	byte UTCdata[4];
	byte s=0;
	while(Wire.available())    // 判断是否有数据
	{ 
		UTCdata[s]= Wire.read(); // 读取数据
		s++;
	}
	UTC_HH = UTCdata[0];
	UTC_MM = UTCdata[1];
	UTC_SS = UTCdata[2];
	UTC_MS = UTCdata[3];
}

float GPS::Latitude(void)  //返回纬度
{
	Wire.beginTransmission(_addr); //像指定地址设备发送请求
	Wire.write(2);              // 请求指令码(纬度数据)
	Wire.endTransmission();    // 停止指令
	
	/*接收返回数据*/
	Wire.requestFrom((int)_addr, (int)4);    // 从指定的地址读取4个字节
	byte LatitudeData[4];
	byte s=0;
	while(Wire.available())    // 判断是否有数据
	{ 
		LatitudeData[s]= Wire.read(); // 读取数据
		s++;
	}
	float latitude;
	ByteToFloat(latitude,LatitudeData);
	return latitude;
	
}

char GPS::LatitudeDirection(void) //纬度方向
{
	Wire.beginTransmission(_addr); //像指定地址设备发送请求
	Wire.write(3);              // 请求指令码(纬度方向)
	Wire.endTransmission();    // 停止指令
	
	/*接收返回数据*/
	Wire.requestFrom((int)_addr, (int)1);    // 从指定的地址读取4个字节
	char direction = Wire.read(); // 读取数据
	return direction;
}

/*----------------*/

float GPS::Longitude(void)  //返回经度
{
	Wire.beginTransmission(_addr); //像指定地址设备发送请求
	Wire.write(4);              // 请求指令码(经度数据)
	Wire.endTransmission();    // 停止指令
	
	/*接收返回数据*/
	Wire.requestFrom((int)_addr, (int)4);    // 从指定的地址读取4个字节
	byte longitudeData[4];
	byte s=0;
	while(Wire.available())    // 判断是否有数据
	{ 
		longitudeData[s]= Wire.read(); // 读取数据
		s++;
	}
	float longitude;
	ByteToFloat(longitude,longitudeData);
	return longitude;
	
}

char GPS::LongitudeDirection(void) //纬度方向
{
	Wire.beginTransmission(_addr); //像指定地址设备发送请求
	Wire.write(5);              // 请求指令码(纬度方向)
	Wire.endTransmission();    // 停止指令
	
	/*接收返回数据*/
	Wire.requestFrom((int)_addr, (int)1);    // 从指定的地址读取4个字节
	char direction = Wire.read(); // 读取数据
	return direction;
}


byte GPS::Positioning(void)   // 定位情况
{
	Wire.beginTransmission(_addr); //像指定地址设备发送请求
	Wire.write(6);              // 请求指令码(定位状态)
	Wire.endTransmission();    // 停止指令
	
		/*接收返回数据*/
	Wire.requestFrom((int)_addr, (int)1);    // 从指定的地址读取4个字节
	byte positioning = Wire.read(); // 读取数据
	return positioning;
}

byte GPS::Satellite()  //有效卫星数量
{
	Wire.beginTransmission(_addr); //像指定地址设备发送请求
	Wire.write(7);              // 请求指令码(有效卫星数量)
	Wire.endTransmission();    // 停止指令
	
			/*接收返回数据*/
	Wire.requestFrom((int)_addr, (int)1);    // 从指定的地址读取4个字节
	byte satellite = Wire.read(); // 读取数据
	return satellite;
}

float GPS::HDOP(void)
{
	Wire.beginTransmission(_addr); //像指定地址设备发送请求
	Wire.write(8);              // 请求指令码(水平定位精度) 单位米
	Wire.endTransmission();    // 停止指令
	
		/*接收返回数据*/
	Wire.requestFrom((int)_addr, (int)4);    // 从指定的地址读取4个字节
	byte HDOPData[4];
	byte s=0;
	while(Wire.available())    // 判断是否有数据
	{ 
		HDOPData[s]= Wire.read(); // 读取数据
		s++;
	}
	float Hdop;
	ByteToFloat(Hdop,HDOPData);
	return Hdop;
}

float GPS::MSL(void)
{
	Wire.beginTransmission(_addr); //像指定地址设备发送请求
	Wire.write(9);              // 请求指令码(椭球高) 单位米
	Wire.endTransmission();    // 停止指令
	
	/*接收返回数据*/
	Wire.requestFrom((int)_addr, (int)4);    // 从指定的地址读取4个字节
	byte MSLData[4];
	byte s=0;
	while(Wire.available())    // 判断是否有数据
	{ 
		MSLData[s]= Wire.read(); // 读取数据
		s++;
	}
	float Msl;
	ByteToFloat(Msl,MSLData);
	return Msl;
}


float GPS::SeaLevel(void)
{
	Wire.beginTransmission(_addr); //像指定地址设备发送请求
	Wire.write(10);              // 请求指令码(海平高) 单位米
	Wire.endTransmission();    // 停止指令
	
	/*接收返回数据*/
	Wire.requestFrom((int)_addr, (int)4);    // 从指定的地址读取4个字节
	byte SeaLevelData[4];
	byte s=0;
	while(Wire.available())    // 判断是否有数据
	{ 
		SeaLevelData[s]= Wire.read(); // 读取数据
		s++;
	}
	float seaLevel;
	ByteToFloat(seaLevel,SeaLevelData);
	return seaLevel;
}

void GPS::UtcDate(byte &UTC_YY, byte &UTC_mm, byte &UTC_DD)
{
	Wire.beginTransmission(_addr); //像指定地址设备发送请求
	Wire.write(11);              // 请求指令码（年月日）
	Wire.endTransmission();    // 停止指令
	
	/*接收返回数据*/
	Wire.requestFrom((int)_addr, (int)3);    // 从指定的地址读取4个字节
	byte UTCdata[3];
	byte s=0;
	while(Wire.available())    // 判断是否有数据
	{ 
		UTCdata[s]= Wire.read(); // 读取数据
		s++;
	}
	UTC_DD = UTCdata[0];
	UTC_mm = UTCdata[1];
	UTC_YY = UTCdata[2];
}


float GPS::Course(void)
{
	Wire.beginTransmission(_addr); //像指定地址设备发送请求
	Wire.write(12);              // 请求指令码(海平高) 单位米
	Wire.endTransmission();    // 停止指令
	
	/*接收返回数据*/
	Wire.requestFrom((int)_addr, (int)4);    // 从指定的地址读取4个字节
	byte CourseData[4];
	byte s=0;
	while(Wire.available())    // 判断是否有数据
	{ 
		CourseData[s]= Wire.read(); // 读取数据
		s++;
	}
	float ourse;
	ByteToFloat(ourse,CourseData);
	return ourse;
}


float GPS::Speed(void)
{
	Wire.beginTransmission(_addr); //像指定地址设备发送请求
	Wire.write(13);              // 请求指令码(速度) 单位 千米每小时
	Wire.endTransmission();    // 停止指令
	
	/*接收返回数据*/
	Wire.requestFrom((int)_addr, (int)4);    // 从指定的地址读取4个字节
	byte SpeedData[4];
	byte s=0;
	while(Wire.available())    // 判断是否有数据
	{ 
		SpeedData[s]= Wire.read(); // 读取数据
		s++;
	}
	float speed;
	ByteToFloat(speed,SpeedData);
	return speed;
}

void GPS::SetReplace(byte Replace)
{
	Wire.beginTransmission(_addr); //像指定地址设备发送请求
	Wire.write(Replace);              // 请求指令 配置刷新率
	Wire.endTransmission();    // 停止指令
}


