#include<stdio.h>

/*
��˸�ʽ�������ָ�ʽ�У������ݵĸ��ֽڴ洢�ڵ͵�ַ�У��������ݵĵ��ֽ������ڸߵ�ַ��
С�˸�ʽ�����˴洢��ʽ�෴����С�˴洢��ʽ�У��͵�ַ�д�ŵ��������ݵĵ��ֽڣ��ߵ�ַ��ŵ��������ݵĸ��ֽ�
����1 ��˸�ʽ
����0 С�˸�ʽ
*/
unsigned char GetSystemEndian()
{
    int a = 0x1;
    
    return ((*(unsigned char *)&a) == 1)?0:1;
}

unsigned char GetSystemEndian1()
{
		union w
		{
    	int a;
    	char b;
		}c;
		c.a = 1;
		return (c.b == 1)?0:1;
	
}

int main()
{
  printf("Get the System endian\n");
  unsigned char a = 0;
  a = GetSystemEndian();
  printf("11111111111a(%d)[0 Small endian 1 : Big endian]\n");
  a = GetSystemEndian1();
  printf("22222222222a(%d)[0 Small endian 1 : Big endian]\n");
  return 0;
}

