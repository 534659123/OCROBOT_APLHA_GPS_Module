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

/****************************/
 typedef union
  {
	  uint8_t  Hex[4];
	  float   Val;
  }Hex2float;
/****************************/
/****************************/
 typedef union
  {
	  uint8_t  Hex[4];
	  int   Val;
  }Hex2int;
/****************************/
/****************************/
 typedef union
  {
	  uint8_t  Hex[4];
	  uint16_t   Val;
  }Hex2Uint16;
/****************************/
/****************************/
 typedef union
  {
	  uint8_t  Hex[4];
	  long   Val;
  }Hex2long;
/****************************/
/****************************/
 typedef union
  {
	  uint8_t  Hex[4];
	  uint32_t   Val;
  }Hex2Uint32;
/****************************/



/*float*/
void ByteToFloat(float &Num,uint8_t *Byte);
void FloatToByte(float Num,uint8_t *Byte);

/*int*/
void ByteToInt(int &Num,uint8_t *Byte);
void IntToByte(int Num,uint8_t *Byte);
/*Uint*/
void ByteToUint(uint16_t &Num,uint8_t *Byte);
void UintToByte(uint16_t Num,uint8_t *Byte);
/*long*/
void ByteToLong(long &Num,uint8_t *Byte);
void LongToByte(long Num,uint8_t *Byte);
/*ULong*/
void ByteToUlong(uint32_t &Num,uint8_t *Byte);
void UlongToByte(uint32_t Num,uint8_t *Byte);





/***************************************************/
/*合并FLOAT*/
void ByteToFloat(float &Num,uint8_t *Byte)
{
	Hex2float Conversion;
	for(byte a =0;a<4;a++)
	{
		Conversion.Hex[a] = *(Byte + a);
	}
	Num = Conversion.Val;
	

}
/*拆解float*/
void FloatToByte(float Num,uint8_t *Byte)
{
	Hex2float Conversion;
	Conversion.Val = Num; 
	for(byte a =0;a<4;a++)
	{
		*(Byte + a) = Conversion.Hex[a];
	}
	
}
/***************************************************/
/*合并int*/
void ByteToInt(int &Num,uint8_t *Byte)
{
	Hex2int Conversion;
	for(byte a =0;a<2;a++)
	{
		Conversion.Hex[a] = *(Byte + a);
	}
	Num = Conversion.Val;
}

/*拆解int*/

void IntToByte(int Num,uint8_t *Byte)
{
	Hex2int Conversion;
	Conversion.Val = Num; 
	for(byte a =0;a<2;a++)
	{
		*(Byte + a) = Conversion.Hex[a];
	}
	
}
/***************************************************/
/*合并Uint*/
void ByteToUint(uint16_t &Num,uint8_t *Byte)
{
	Hex2Uint16 Conversion;
	for(byte a =0;a<2;a++)
	{
		Conversion.Hex[a] = *(Byte + a);
	}
	Num = Conversion.Val;
}

/*拆解Uint*/

void UintToByte(uint16_t Num,uint8_t *Byte)
{
	Hex2Uint16 Conversion;
	Conversion.Val = Num; 
	for(byte a =0;a<2;a++)
	{
		*(Byte + a) = Conversion.Hex[a];
	}
	
}
/***************************************************/

/*合并long*/
void ByteToLong(long &Num,uint8_t *Byte)
{
	Hex2long Conversion;
	for(byte a =0;a<4;a++)
	{
		Conversion.Hex[a] = *(Byte + a);
	}
	Num = Conversion.Val;
}

/*拆解long*/

void LongToByte(long Num,uint8_t *Byte)
{
	Hex2long Conversion;
	Conversion.Val = Num; 
	for(byte a =0;a<4;a++)
	{
		*(Byte + a) = Conversion.Hex[a];
	}
	
}

/***************************************************/
/*合并Ulong*/
void ByteToUlong(uint32_t &Num,uint8_t *Byte)
{
	Hex2Uint32 Conversion;
	for(byte a =0;a<4;a++)
	{
		Conversion.Hex[a] = *(Byte + a);
	}
	Num = Conversion.Val;
}

/*拆解Ulong*/

void UlongToByte(uint32_t Num,uint8_t *Byte)
{
	Hex2Uint32 Conversion;
	Conversion.Val = Num; 
	for(byte a =0;a<4;a++)
	{
		*(Byte + a) = Conversion.Hex[a];
	}
	
}
