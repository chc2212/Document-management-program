#ifndef __DATA_H__
#define __DATA_H__


#include"function.h"
#include"menu.h"
#include"file.h"
#include"dirent.h"

struct Document
{
	int num; //문서 등록 번호
	char type[50]; //문서 종류
	char title[200]; //문서 제목
	char writer[200]; //작성자
	char filename[300]; //문서 파일 이름
	long new_date; //문서작성날짜
	char new_date_string[300];
	long update_date; //문서수정날짜  
	char update_date_string[300];    
	int file_size; //문서 크기
};

void LoadDocument();
void SaveDocument();

#endif