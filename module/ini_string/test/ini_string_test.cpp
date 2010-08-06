#include<stdio.h>
#include"get_lan_string.h"
#include"get_lan_string_typedef.h"



int main(int argc, char *argv[])
{
	ini_database_t *ini_database = NULL;
	int ret = 0;
	ini_database = GetLanguageStringCreate(CHINESE_SIMPLE_LAN);
	if(!ini_database)
	{
		printf("GetLanguageStringCreate failed!\n");
		ret = -1;
		goto OVER;
	}
	
	PrintIniDataBase(ini_database);

	GetLanguageStringDestory(ini_database);
	if(!ini_database)
	{
		printf("GetLanguageStringDestory succed!\n");
	}
	

	
OVER:
	return ret;
}
