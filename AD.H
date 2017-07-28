/***************************************************************************************
 *	File Name				:		
 *	CopyRight				:
 *	ModuleName				:	
 *
 *	CPU						:
 *	RTOS					:
 *
 *	Create Data				:	
 *	Author/Corportation		:	
 *
 *	Abstract Description	:	this will be used for 
 *
 *--------------------------------Revision History--------------------------------------
 *	No	version		Data			Revised By			Item			Description
 *	
 *
 ***************************************************************************************/


/**************************************************************
*	Multi-Include-Prevent Section
**************************************************************/
#ifndef __AD_H
#define __AD_H


/**************************************************************
*	Debug switch Section
**************************************************************/


/**************************************************************
*	Include File Section
**************************************************************/
#include<reg52.h>

/**************************************************************
*	Macro Define Section
**************************************************************/
#define uint unsigned int
#define uchar unsigned char 
/**************************************************************
*	Struct Define Section
**************************************************************/


/**************************************************************
*	Prototype Declare Section
**************************************************************/
/**
*  @name: void delay(uint i)
*	@description: ��ʱ����
 *	@param�� i ��ʱʱ��	
 *	@return		��none
 *  @notice ��none
 */
 void delayMs(uint i);
	 
 /**
*  @name:uint getTemp()
*	@description: ��ȡ�¶�
 *	@param	�� none 		
*	@return		: ��ȡ�����¶�
 *  @notice
 */
uint getTemp();


 /**
*  @name:void tempchang()
*	@description: ��ʼ��ȡ�¶Ȳ�ת��
 *	@param			
 *	@return		
 *  @notice
 */
void tempchange();

/**
 *  @name:void writeData(uchar dat)
 *	@description : д����
 *	@param			��dat����
 *	@return		
 *  @notice
 */
void writeData(uchar dat);

 /**
*  @name: void init()
*	@description: ��ʼ��lcd
 *	@param			��none
 *	@return		��none
 *  @notice��none
 */
void init();

/**
*  @name:void writeCom(uchar com)
*	@description: ��lcdд����
 *	@param		��com ����	
 *	@return		�� none
 *  @notice �� none
 */
void writeCom(uchar com);


 /**
 *  @name�� void displayLcd(uchar x, uint num)
 *	@description��ָ��λ����ʾ����
 *	@param			���¶�
 *	@return		��none
 *  @notice�� none
 */
void displayLcd(uchar x, uint num);
/**************************************************************
*	End-Multi-Include-Prevent Section
**************************************************************/
#endif