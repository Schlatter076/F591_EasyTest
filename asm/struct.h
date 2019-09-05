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

#ifndef _STRUCT_H
#define _STRUCT_H
#define uchar unsigned char
typedef struct motorPozition Pozition;

struct motorPozition
{
    unsigned int M_X;
	unsigned int M_Y;
	unsigned int M_Z;
	uchar buf[20];
};
struct motorPozition getPozition(char *datas);

#endif
