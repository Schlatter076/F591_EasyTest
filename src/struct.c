/******************************************/
/*           ����������������޹�˾     */
/*Project:     �����Զ����FCT����        */
/*Guest:                                  */
/*Name:             struct.c              */
/*Mcu chip:         Atmega64              */
/*Main clock:       �ⲿ����11.0592MHz    */
/*Rtc clock:                              */
/*Author:                                 */
/*Create date:      2018.05.24            */
/*Design date:                            */
/*Complete date:                          */
/******************************************/

#include <stdio.h>
#include <string.h>

struct motorPozition
{
    unsigned int M_X;
	unsigned int M_Y;
	unsigned int M_Z;
	unsigned char buf[20];
};

struct motorPozition getPozition(char *datas) 
{
    struct motorPozition tem;
	memcpy(tem.buf, datas, 20);  //�������ַ�������
	//strcpy(tem.buf, datas);  //�����ַ���
	return tem;
}