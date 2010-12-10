#include <stdio.h>
#include <stdlib.h>
#include "hi_key_gpio_api.h"

int main(void)
{
    unsigned char keyvalue=0xff;
    if(Hi_Gpio_Key_Open()!=0)
    {
	return -1;
    }

	/*������ʹ��*/
    Hi_Gpio_Key_Enable_RepKey(1);
    	/*����������ʱ��*/
    Hi_Gpio_Key_Set_Reptimeout(1000);
    while(1)
    {
	Hi_Gpio_Key_ReadKey(&keyvalue);

	if(0xff!=keyvalue)
	{
	    printf("key value:%x !\n",keyvalue);
	}
    }

    Hi_Gpio_Key_Close();
}

