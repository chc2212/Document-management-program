#include<stdio.h>
#include <sys/types.h>
#include <io.h>
#include <time.h>
#include<string.h>
#include<stdlib.h>

#include"data.h"
#include "ui.h"

Document data[1000]; //문서 정보의 구조체를 가리키는 포인터 배열

int Document_count;
int new_Document_count;

void LoadDocument()
{
	FILE *pf;
	char str[300] = {0, };
	int i;
	_finddata_t fd;
	long handle;
	int select_num = 0;

	printf("저장했던 문서 정보를 로드하겠습니까??\n1. 로드한다\t2. 새로 시작한다.\n");
	scanf("%d", &select_num);
	getc(stdin);
	while(select_num != 1 && select_num != 2)
	{
		printf("번호를 잘못 입력하셨습니다. 다시 입력해 주십시오.\n");
		printf("1. 로드한다\t2. 새로 시작한다.\n");
		scanf("%d", &select_num);
		getc(stdin);
	}
	
	if(select_num ==1)
	{
		if((pf=fopen("document.txt", "r+")) == NULL)
		{
			printf("현재 저장된 문서정보가 없습니다.\n");
		}
		else
		{
			printf("현재 저장되어 있는 문서정보를 불러들입니다.\n");
			fgets(str, 10, pf);
			Document_count = atoi(str);
			for(i = 0 ; i < Document_count ; i++)
			{
				data[i].num = i + 1;
				fgets(str, 50, pf);
				str[strlen(str) - 1] = 0;
				strcpy(data[i].type, str);
				fgets(str, 200, pf);
				str[strlen(str) - 1] = 0;
				strcpy(data[i].title, str);
				fgets(str, 200, pf);
				str[strlen(str) - 1] = 0;
				strcpy(data[i].writer, str);
				fgets(str, 300, pf);
				str[strlen(str) - 1] = 0;
				strcpy(data[i].filename, str);

				if((handle=_findfirst(data[i].filename,&fd)) == -1L)
				{
					printf("%d번의 문서 %s는 존재하지 않는 관계로 저장할 수 없습니다.\n", i + 1, data[i].filename);
					i--;
					Document_count--;
				}
				else
				{
					data[i].new_date=fd.time_create;//파일 작성날짜
					strcpy(data[i].new_date_string,ctime(&fd.time_create));
					data[i].update_date=fd.time_write;//파일 수정날짜
					strcpy(data[i].update_date_string,ctime(&fd.time_write));
					data[i].file_size=fd.size;//파일크기
				}
			}

			printf("%d개의 문서정보를 저장하였습니다.\n", Document_count);
		}

		fclose(pf);
	}
}

void SaveDocument()
{
	FILE *pf;
	int i;

	if((pf=fopen("document.txt", "w+")) == NULL)
	{
		printf("문서 정보 저장을 실패하였습니다\n");
	}
	else
	{
		fprintf(pf, "%d\n", Document_count);
		for(i = 0 ; i < Document_count ; i++)
		{
			fprintf(pf, "%s\n", data[i].type);
			fprintf(pf, "%s\n", data[i].title);
			fprintf(pf, "%s\n", data[i].writer);
			fprintf(pf, "%s\n", data[i].filename);
		}
	}

	fclose(pf);

}