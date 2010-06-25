#ifndef _RMCOMMONDATATYPE_H_
#define _RMCOMMONDATATYPE_H_

#include <stdlib.h>
#include <stdio.h>
#include "rmcommondefine.h"


#define MAX_VIDEO_NUM 16


#define channelid_t int/*ͨ��ID*/

typedef enum outputmode{/*Ԥ��ģʽ*/
    OM_ONE,
    OM_FOUR,
    OM_NINE,
    OM_SIXTEEN,
	OM_PIP,
	OM_ZOOMIN,
	OM_INVALID
}outputmode_t;


typedef enum _tvsystem_{/*��ʽ*/
    TS_PAL,/*PAL*/
    TS_NTSC,/*NTSC*/
    TS_INVALID 
}tvsystem_t;

typedef enum _resolution_{/*�ֱ���*/
    RES_D1,
    RES_HD1,
    RES_CIF,
    RES_QCIF,
    RES_MOBILE,
    RES_BUTT
}resolution_t;


typedef enum hiVO_DEV_E
{
    VO_DEV_HD  = 0,                 /* high definition device */
    VO_DEV_AD  = 1,                 /* assistant device */
    VO_DEV_SD  = 2,                 /* spot device */
    VO_DEV_BUTT
} VO_DEV_E;

#endif /*_RMCOMMONDATATYPE_H_*/

