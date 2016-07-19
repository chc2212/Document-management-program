#ifndef __FUNCTION_H__
#define __FUNCTION_H__

#include"data.h"
#include"file.h"
#include"menu.h"
#include"dirent.h"

extern int Document_count;
extern int new_Document_count;

struct InforWord
{
	int find_num;													//�˻��� ���� ã�� �ܾ��� ����
	int catch_word[2000][3];										//ã�� �ܾ ������ �ִ� ������ ��ġ, �ܾ��� ������ġ, �ܾ��� �� ��ġ
};

void Registration(); 
void Registration_All();
void Registration_One();
void Show_All() ;
void Sort_original();//�����Ŀ� ������ ��Ϲ�ȣ��� �ٽ� �����Ҷ� ���


int compare_num (const void *a, const void *b);
void Sort_num() ;
int compare_type (const void *a, const void *b);
void Sort_type(int g) ;
int compare_title (const void *a, const void *b);
void Sort_title() ;
int compare_writer (const void *a, const void *b);
void Sort_writer() ;
int compare_new_date (const void *a, const void *b);
void Sort_new_date() ;
int compare_update_date (const void *a, const void *b);
void Sort_update_date() ;
int compare_file_size (const void *a, const void *b);
void Sort_file_size() ;

void Show_File(int choice_show, struct Document data,int choice_add);
void Search_File() ;
int Search_Title();
void Delete_File() ;
void Modification_File();
void Word();
void AllSearchWord(char searchword[]);
void OneSearchWord(char searchword[], char title_text[]);		//�˻��� �ܾ�, ���� ���� �̸�
void changeWord(char file_text_data[], int num_word, InforWord infor1, char title_text[], char change_word[]);

void Graph();

#endif