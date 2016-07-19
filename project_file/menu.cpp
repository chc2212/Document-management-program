#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"menu.h"
#include"ui.h"


int enter_menu()
{
	int num;
	char empty;

	//printf("Enter_the_menu_number:");
	//scanf("%d",&num);	
	num = ui(2,5,5,30,"초기메뉴","Q) 원하는 메뉴를 선택해주세요. \n\n",2,8,"","","");
	//empty = getc(stdin);

	return num;
}


void menu_loop(int menu_num)//count: 저장된 데이터개수 이므로 그 인덱스에 저장하면 된다
{
	if(menu_num==1)
	{
		Registration(); 
	}
	if(menu_num==2)//등록된 전체 자료 보여주기 
	{
		Show_All();
	}

	if(menu_num==3)//serch
	{
		Search_File();
	}

	if(menu_num==4)
	{
		Delete_File();
	}

	if(menu_num==5)
	{
		Modification_File();
	}

	if(menu_num==6)
	{
		Word();
	}
	if(menu_num==7)
	{
		Graph();
	}
}