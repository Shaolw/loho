#ifndef __I2CINTERFACE_H__
#define __I2CINTERFACE_H__

struct i2cinterface
{
	/*���ͣ������е�I2C�豸��дĳ���Ĵ���ֱ�ӷ��͵�ַ
	���ɣ��е�����Ҫ����������Ϣ������TW2834����Ҫ��
	��ҳ�Ų��ܶ�ȡ���Ĵ�����ֵ*/	
	unsigned char type;
	unsigned char i2caddr;/*i2c device address*/
	unsigned char regaddr;/*register address*/
	unsigned char operation;/*read(0) or write(1)*/
	unsigned char value;/*read value or write value*/
	unsigned char reserver[11];
};

#define I2CINTERFACE_CMD_TEMPLATE		0x0a

#endif

