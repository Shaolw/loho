#ifndef __FUN_LOG_TYPEDEF_H__
#define __FUN_LOG_TYPEDEF_H__




typedef enum _FunLogLevel_{
	LOG_ERROR,
	LOG_DEBUG,
	LOG_INVALID,
}FunLogLevel_t;


typedef enum _FunLogWriteMode_{
	LOG_PRINTF_MODE,			/*��ӡ��Ļ���*/
	LOG_FILE_MODE,			/*�����ļ����*/
	LOG_SOCKET_MODE,			/*�������*/
	LOG_INVALID_MODE,		
}FunLogWriteMode_t;

#endif
