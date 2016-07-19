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
			printf("\n잘못 입력하셨습니다. 상위 메뉴로 다시 돌아갑니다.\n\n");
		menu_loop(num);
	}

	for(int i = 0 ; i < Document_count ; i++)
	{
		printf("\n%d번째 문서정보\n", i + 1);
		printf("등록번호 : %d\t문서종류 : %s\t문서제목 : %s\n작성자 : %s\t파일이름 : %s\n",
			data[i].num, data[i].type, data[i].title, data[i].writer, data[i].filename);
		printf("작성날짜 : %s크기 : %d\n", 
			data[i].new_date_string, data[i].file_size);
		printf("수정날짜 : ");
		for(int j = 0 ; j < 25 ; j++)
			printf("%c", data[i].update_date_string[j]);
	}


	SaveDocument();


return 0;
}
