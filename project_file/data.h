#ifndef __DATA_H__
#define __DATA_H__


#include"function.h"
#include"menu.h"
#include"file.h"
#include"dirent.h"

struct Document
{
	int num; //���� ��� ��ȣ
	char type[50]; //���� ����
	char title[200]; //���� ����
	char writer[200]; //�ۼ���
	char filename[300]; //���� ���� �̸�
	long new_date; //�����ۼ���¥
	char new_date_string[300];
	long update_date; //����������¥  
	char update_date_string[300];    
	int file_size; //���� ũ��
};

void LoadDocument();
void SaveDocument();

#endif