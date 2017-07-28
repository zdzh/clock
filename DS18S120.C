/***************************************************************************************
 *	FileName					:	
 *	CopyRight					:
 *	ModuleName					:	
 *
 *	CPU							:
 *	RTOS						:
 *
 *	Create Data					:	
 *	Author/Corportation			:	
 *
 *	Abstract Description		:	
 *
 *--------------------------------Revision History--------------------------------------
 *	No	version		Data			Revised By			Item			Description
 *	
 *
 ***************************************************************************************/


/**************************************************************
*	Debug switch Section
**************************************************************/


/**************************************************************
*	Include File Section
**************************************************************/
#include"AD.H"

/**************************************************************
*	Macro Define Section
**************************************************************/

/**************************************************************
*	Struct Define Section
**************************************************************/


/**************************************************************
*	Prototype Declare Section
**************************************************************/


/**************************************************************
*	Global Variable Declare Section
**************************************************************/


/**************************************************************
*	File Static Variable Define Section
**************************************************************/
sbit ds = P3^7;

/**************************************************************
*	Function Define Section
**************************************************************/

/**
*  @name: void delayMs(uint i)
*	@description: ��ʱ����
 *	@param�� i ��ʱʱ��	
 *	@return		��none
 *  @notice ��none
 */
 void delayMs(uint i)
 {
	 uchar j;
	 while( i > 0 )
	 {
		 for( j = 0; j < 110; j++ )
		 {
			 ;
		 }
		 i--;
	 }
 }

/**
	*  @name: void dsreset()
	*	@description: DS180B20��λ����ʼ������
	*	@param:	none
	*	@return:		none
	*  @notice: none
 */
void dsreset()
{
	uint i;
	ds = 0;
	i = 103;
	while ( i > 0 )
	{
		i--;             //��ʱ
	}
	ds = 1;
	i = 4;
	while( i > 0) 
	{
		i--;
	}
}
 
/**
*  @name: bit tempReadBit()
*	@description: ��һλ����
 *	@param			
 *	@return		����ȡ������
 *  @notice
 */
bit tempReadBit()
{
	uint i;
	bit dat;
	ds = 0;
	i++;
	ds = 1;
	i++; i++;
	dat = ds;
	i = 8;
	while( i > 0 )
	{
		i--;
	}
	return dat;
}


	
	/**
*  @name: uchar tempRead()
 *	@description����һ���ֽ�����
 *	@param			
 *	@return		����ȡ������
 *  @notice
 */
 uchar tempRead()
{
	uchar i, j, dat;
	dat = 0;
	for( i = 0; i < 8; i++ )
	{
		j = tempReadBit();
		dat = (dat >> 1) | (j << 7);               //����ȡ�����ݴ���һ���ֽ�
	} 
	return dat;
}
	
 
 /**
 *  @name��void tempWrite(uchar dat)
 *	@description�� ��ds18b20дһ���ֽ�����
 *	@param			����Ҫд�������
 *	@return		
 *  @notice
 */
void tempWrite(uchar dat)
{
	uint i;
	uchar j;
	bit test;
	for( j = 0; j < 8; j++ )
	{
		test = dat & 0x01;
		dat >>= 1;
		if( test == 1 )           //д1
		{
			ds = 0;
			i++; i++;
			ds = 1;
			i = 8;
			while( i > 0 )
			{
				i--;
			}
		}
		else             //д0
		{
			ds = 0;
			i = 8;
			while( i > 0 )
			{
				i--;
			}
			ds = 1;
			i++; i++;
		}
	}
}

 
 /**
*  @name:float getTemp()
*	@description: ��ȡ�¶�
 *	@param	�� none 		
*	@return		: ��ȡ�����¶� * 10
*  @notice   :none
 */
uint getTemp()
{
	uchar a, b;
	float ftemp;
  uint	temp;
	dsreset();
	delayMs(1);
  tempWrite(0xcc);
	tempWrite(0xbe);
	a = tempRead();          //����8λ
	b = tempRead();          //����8λ 
	temp = b;
	temp <<= 8;
	temp = temp | a;         //�ϲ�Ϊһ����
	ftemp = temp * 0.0625;          //�¶��ڼĴ�����Ϊ12λ���ֱ���Ϊ0.0625
  temp = ftemp * 10 + 0.5;           //�+0.05Ϊ��������,*10 ��ʾ֧ȡһλС��
	return temp;
}

 /**
*  @name:void tempchang()
*	@description: ��ʼ��ȡ�¶Ȳ�ת��
*	@param			:none
*	@return		:none
*  @notice : none
 */
void tempchange()
{
	dsreset();
	delayMs(1);
	tempWrite(0xcc);    //д������romָ��
	tempWrite(0x44);     //д�¶�ת��ָ��
}