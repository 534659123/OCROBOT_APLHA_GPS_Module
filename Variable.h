/*
*ocrobot-迷你强
2017年1月6日
数据类型拆分
*/
#if defined(ARDUINO) && ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif
/*float*/
void ByteToFloat(float &Num,uint8_t *Byte);
void FloatToByte(float Num,uint8_t *Byte);

/*int*/
void ByteToInt(int &Num,uint8_t *Byte);
void IntToByte(int Num,uint8_t *Byte);
/*Uint*/
void ByteToUint(unsigned int &Num,uint8_t *Byte);
void UintToByte(unsigned int Num,uint8_t *Byte);
/*long*/
void ByteToLong(long &Num,uint8_t *Byte);
void LongToByte(long Num,uint8_t *Byte);
/*ULong*/
void ByteToUlong(unsigned long &Num,uint8_t *Byte);
void UlongToByte(unsigned long Num,uint8_t *Byte);