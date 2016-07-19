#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>

#include"function.h"
#include"menu.h"
#include"data.h"
#include"file.h"
#include "ui.h"

int main()
{
	int num = 0;
	extern Document data[1000];

	LoadDocument();
	while(num != 8)
	{
		
		num = enter_menu();
		if(num < 1 || num > 8)
			printf("\n�߸� �Է��ϼ̽��ϴ�. ���� �޴��� �ٽ� ���ư��ϴ�.\n\n");
		menu_loop(num);
	}

	for(int i = 0 ; i < Document_count ; i++)
	{
		printf("\n%d��° ��������\n", i + 1);
		printf("��Ϲ�ȣ : %d\t�������� : %s\t�������� : %s\n�ۼ��� : %s\t�����̸� : %s\n",
			data[i].num, data[i].type, data[i].title, data[i].writer, data[i].filename);
		printf("�ۼ���¥ : %sũ�� : %d\n", 
			data[i].new_date_string, data[i].file_size);
		printf("������¥ : ");
		for(int j = 0 ; j < 25 ; j++)
			printf("%c", data[i].update_date_string[j]);
	}


	SaveDocument();


return 0;
}
