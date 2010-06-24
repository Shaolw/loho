/*************************************
author:zhoumin
date:2010-4-14
usage: 
**************************************/ 

#include <stdio.h>
#include<sys/types.h>
#include<dirent.h>
#include<unistd.h>
#include <string.h>
#include<stdlib.h>


#define DIR_PATHNAME "./input"
#define KEY_ASCII    '@'


#define DATE 20100624

static void usage()
{
 printf("Usage: main xml(file name)\n"); 
 return;
}

char *tag_string[] = {
 "_CONTENT_",
 "_HEADER_",
 "_COMMENT_",
 NULL,
};


static void ParserLine(char *line_string, char *left_string, char *right_string )
{
   printf("ParserLineline_string(%s)\n", line_string);
   
   if(line_string){
  char *p= NULL;
  p = line_string;
  int key_position = 0;
  int line_len = 0;
  int left_len = 0;
  int right_len = 0;
  
  
  line_len = strlen(line_string);
 
  printf("line_len(%d)\n", line_len);
  /*ȥ�����з�*/
  do{
   if((*p == '\r') && (*(p + 1) == '\n'))
   {
    *p = '\0';
    break;
   }
  }
  while(*p++ != '\0');

  p = line_string;

  do{
   if(*p != KEY_ASCII){
    printf(" aaaaaaaaaa *p (%c)\n", *p);
    key_position ++;
   }
   else
   {
    printf("find the @,key_position(%d)\n", key_position);
    break; 
   } 

  }while(*p++ != '\0');
  
  if(0 != key_position){
   memcpy(left_string, line_string, key_position);
   *(left_string+key_position)= '\0';
   
   memcpy(right_string, line_string + key_position + 1 , line_len - key_position);
   right_string[line_len - key_position] = '\0';
   
   if((left_string != NULL) && (right_string != NULL)){
     left_len = strlen(left_string);
     right_len = strlen(right_string);
     if(left_len > right_len){
      /*����ߵ��ַ������ȴ����ұߵ��ַ�����ʱ,�Ҷȵ��ַ���������Ҫ���ո�.*/
       for(int i = right_len; i <= left_len - 1; i++){
         right_string[i] = ' ';
        }
        right_string[left_len] = '\0';
      }
     if(left_len < right_len){
      /*�ұߵ��ַ���������ߵ��ַ���*/ 
      right_string[left_len - 1] = '.';
      right_string[left_len] = '\0';
    }

  }
  
  return;
  
 }
 
 }
}


/*

*/
static void Substitute(char *pInput, char *pOutput, char *pSrc, char *pDst)
{
 char  *pi, *po, *p;
 int   nSrcLen, nDstLen, nLen;  // ָ�������ַ������ζ�ָ��.
 pi = pInput;  
 // ָ������ַ������ζ�ָ��.
 po = pOutput;
 // ���㱻�滻�����滻���ĳ���.
 nSrcLen = strlen(pSrc);
 nDstLen = strlen(pDst);  // ����piָ���ַ����е�һ�γ����滻����λ��,������ָ��(�Ҳ����򷵻�null).  
 p = strstr(pi, pSrc);
 if(p)
 {
   // �ҵ�.
   while(p)
   {
     // ���㱻�滻��ǰ���ַ����ĳ���.
     nLen = (int)(p - pi);
     // ���Ƶ�����ַ���.
     memcpy(po, pi, nLen);
     memcpy(po + nLen, pDst, nDstLen);
     // �������滻��.
     pi = p + nSrcLen;
     // ����ָ���������ָ��λ��.
     po = po + nLen + nDstLen;
     // ��������.
     p = strstr(pi, pSrc);
   }
   // ����ʣ���ַ���.
   strcpy(po, pi);
 }
 else
 {
   // û���ҵ���ԭ������.
   strcpy(po, pi);
 }
}
int main(int argc ,char *argv[])
{
 if(argc  < 2){
  usage();  
  return -1;
 }
#if 1
 DIR * dir = NULL;  
 struct dirent * ent;
 int find_file_flag = 0; /*�����ҵ�content�ļ�ʱΪ1,header�ļ���Ϊ2,comment�ļ���Ϊ3*/
 FILE *fl = NULL;
 FILE *fl_xml_filename = NULL;
 char file_name[32] = {0};
 char buf_line[1000];
 char left_string[120] = {0};
 char right_string[120] = {0};
 char left_string_buf[200] = {0};
 char right_string_buf[200] = {0};
 
 
 char *buf_xmlfile = NULL;
 char *buf_output_xmlfile = NULL;
 char *pInput = NULL;
 char *pOutput = NULL;
 
 buf_xmlfile = (char *)malloc(500*1000);
 buf_output_xmlfile = (char *)malloc(500*1000);
 if(!buf_xmlfile){
  printf("buf_xmlfile NULL\n");
  return -1;
 }
 
 
 fl_xml_filename = fopen(argv[1], "r");
 if(fl_xml_filename == NULL){
  printf("open file(%s) failed!\n", argv[1]);  
  return -1; 
 }
 fread(buf_xmlfile, 500*1000, 1, fl_xml_filename);
 fclose(fl_xml_filename);
 
 pInput = buf_xmlfile;
 pOutput = buf_output_xmlfile;
 

 /*���ļ�*/
 dir = opendir(DIR_PATHNAME);  
 if(NULL == dir){
  printf("open the dir(%s)failed!\n", DIR_PATHNAME);
  return -1;
 }

   while ((ent = readdir(dir))) {  
   /*�ҵ���һ���ļ�*/
   
   printf("dir(%s),filename(%s)\n", DIR_PATHNAME, ent->d_name);
   find_file_flag = 0;
   if(strstr(ent->d_name, "content") !=  0)
   {
    printf("find (%s)\n", ent->d_name);
    find_file_flag = 1;
   }
   if(strstr(ent->d_name, "header") !=  0)
   {
    printf("find (%s)\n", ent->d_name);
    find_file_flag = 2;
   }
   if(strstr(ent->d_name, "comment") !=  0)
   {
    printf("find (%s)\n", ent->d_name);
    find_file_flag = 3;
   }
   
   if(find_file_flag != 0){
    
    sprintf(file_name, "%s/%s", DIR_PATHNAME,ent->d_name);
    fl = fopen(file_name, "r");
    if(fl == NULL)
    {
     printf("open file failed(%s)\n", file_name); 
     return -1;
    }
    
    while(!feof(fl)){
     
     /*��ȡһ��*/
     if(fgets(buf_line, 100, fl) != NULL){
      printf("%s", buf_line);
      }
     /*����*/
     ParserLine(buf_line, left_string, right_string); 
     
     printf("left_string(%s), right_string(%s)\n", left_string, right_string);

     /*�滻����*/
     sprintf(left_string_buf, "%s=\"%s\"", tag_string[find_file_flag - 1], left_string);
     sprintf(right_string_buf, "%s=\"%s\"", tag_string[find_file_flag - 1], right_string);
     
     printf("left_string_buf(%s), right_string_buf(%s)\n", left_string_buf, right_string_buf);
//     Substitute(pInput, pOutput, right_string_buf,left_string_buf, right_string_buf);     
     
     fl_xml_filename = fopen(argv[1], "r");
     if(fl_xml_filename == NULL){
      printf("open file(%s) failed!\n", argv[1]);  
      return -1; 
     }     
     
     fread(buf_xmlfile, 500*1000, 1, fl_xml_filename);     
     fclose(fl_xml_filename);
     
     Substitute(buf_xmlfile, buf_output_xmlfile,left_string_buf, right_string_buf); 
     
     /*д��*/
     fl_xml_filename = fopen(argv[1], "w");
     
     fwrite(buf_output_xmlfile, strlen(buf_output_xmlfile)+1, 1, fl_xml_filename);     
     fclose(fl_xml_filename);

    }
    fclose(fl);
   }
        
   }  
   
 /*��ȡ�ļ�*/
 
  
 closedir(dir);

#endif
 return 0;

}
