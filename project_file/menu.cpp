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
	num = ui(2,5,5,30,"�ʱ�޴�","Q) ���ϴ� �޴��� �������ּ���. \n\n",2,8,"","","");
	//empty = getc(stdin);

	return num;
}


void menu_loop(int menu_num)//count: ����� �����Ͱ��� �̹Ƿ� �� �ε����� �����ϸ� �ȴ�
{
	if(menu_num==1)
	{
		Registration(); 
	}
	if(menu_num==2)//��ϵ� ��ü �ڷ� �����ֱ� 
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