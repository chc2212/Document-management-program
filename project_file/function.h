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
	int find_num;													//검색을 통해 찾은 단어의 갯수
	int catch_word[2000][3];										//찾은 단어를 가지고 있는 문단의 위치, 단어의 시작위치, 단어의 끝 위치
};

void Registration(); 
void Registration_All();
void Registration_One();
void Show_All() ;
void Sort_original();//정렬후에 원래의 등록번호대로 다시 정렬할때 사용


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
void OneSearchWord(char searchword[], char title_text[]);		//검색할 단어, 파일 문서 이름
void changeWord(char file_text_data[], int num_word, InforWord infor1, char title_text[], char change_word[]);

void Graph();

#endif