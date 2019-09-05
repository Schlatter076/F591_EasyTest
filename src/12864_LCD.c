
/******************************************/
/*           ����������������޹�˾     */
/*Project:      FCT��������               */
/*Guest:                                  */
/*Name:             12864_lcd.c           */
/*Mcu chip:         Atmega64              */
/*Main clock:       �ⲿ����11.0592MHz    */
/*Rtc clock:                              */
/*Author:           Jack.Fu               */
/*Create date:      2008.11.20            */
/*Design date:                            */
/*Complete date:                          */
/******************************************/

/********************************************************************/
/********************************************************************/
#include <iom64v.h>
#include <macros.h>
#include <delay.h>
#include <port.h>
#include <default.h>
#include <12864_LCD.h>

/*---------------------------------------------*/
/***************LCD��ʼ������ start ************/
void init_lcd(void)
{
    clr_bit(PORTE,LCD_EN);
    set_bit(PORTE,LCD_RS);
    delay_nms(2);
    write_command(0x32); //ѡ�����ָ�
    delay_nms(2);
    write_command(0x32);
    delay_nms(2);
    write_command(0x08); //����ʾ������ʾ���
    delay_nms(2);
    write_command(0x01); //�����ʾ
    delay_nms(2);
    write_command(0x0c); //����ʾ
    delay_nms(2);
    write_command(0x02); //AC=0
    delay_nms(200);
    write_command(0x06); //AC�Զ���1����ֹ����
}
/***************LCD��ʼ������ end **************/
/*---------------------------------------------*/

/*---------------------------------------------*/
/***************д�����ֺ��� start**************/
void write_command(unsigned char x)
{
    clr_bit(PORTE,LCD_RS);
    LCD_data=x;
    clr_bit(PORTE,LCD_EN);
    delay_nms(2);
    set_bit(PORTE,LCD_EN);
    delay_nms(2);
}
/***************д�����ֺ��� end ***************/
/*---------------------------------------------*/

/*---------------------------------------------*/
/***************д���ݺ��� start****************/
void write_data(unsigned char x)
{
    set_bit(PORTE,LCD_RS);
    LCD_data=x;
    clr_bit(PORTE,LCD_EN);
    delay_nms(2);
    set_bit(PORTE,LCD_EN);
    delay_nms(2);
}
/***************д���ݺ��� end *****************/
/*---------------------------------------------*/

/*---------------------------------------------*/
/********��ʾһ���ַ������ݺ��� start***********/
//��������DisplayLine
//���룺line��ʾָ�����У�DBpointer��ʾ������ָ��
//�������
//���ܣ���ʾһ���ַ�������
void displayline(uchar line,uchar *DBpointer)
{
    uchar i,Len;
    write_command(line);
	Len = 16;
    //Len =  strlen(DBpointer);
    for (i=0;i<Len;i++)
    {
        write_data(*(DBpointer+i));
    }
}
/********��ʾһ���ַ������ݺ��� end*************/
/*---------------------------------------------*/

/*---------------------------------------------*/
/*************��ʾ��ӭ������ start**************/
//��������DispWelcome
//���룺��
//�������
//���ܣ���ʾ��ӭ��
void DispWelcome(void)
{
    displayline(LINE1,"    ��ӭʹ��    ");
    displayline(LINE2,"KM�Զ���� FCT  ");
    displayline(LINE3,"    Ver:2.0     ");
    displayline(LINE4,"  PKS-������  ");
}
/*************��ʾ��ӭ������ end****************/
/*---------------------------------------------*/

/*---------------------------------------------*/
/*************��ʾ�밴������ start**************/
//��������Disp_Autokey
//���룺��
//�������
//���ܣ���ʾ�밴��
void Disp_Autokey(void)
{
    displayline(LINE1,"KM�Զ���� FCT  ");
    displayline(LINE2,"                ");
    displayline(LINE3,"                ");
    displayline(LINE4,"�밴�Ӽ���ʼ����");
}
/*************��ʾ�밴������ end****************/
/*---------------------------------------------*/
//�����ʾ����
void Disp_dachong(void)
{
    displayline(LINE1,"����Ӧ�Զ�FCT ");
	displayline(LINE2,"                ");
	displayline(LINE3,"                ");
    displayline(LINE4,"�밴�Ӽ���ʼ����");
}
//С����ʾ����
void Disp_xiaochong(void)
{
    displayline(LINE1,"С���Ӧ�Զ�FCT ");
    displayline(LINE2,"                ");
	displayline(LINE3,"                ");
    displayline(LINE4,"�밴�Ӽ���ʼ����");
}
//��ͷ��ʾ����
void Disp_longtou(void)
{
    displayline(LINE1,"��ͷ��Ӧ�Զ�FCT ");
	displayline(LINE2,"                ");
	displayline(LINE3,"                ");
    displayline(LINE4,"�밴�Ӽ���ʼ����");
}
/*---------------------------------------------*/