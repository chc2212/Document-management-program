#include<stdio.h>
#include <sys/types.h>
#include <io.h>
#include <time.h>
#include<string.h>
#include<stdlib.h>

#include"data.h"
#include "ui.h"

Document data[1000]; //���� ������ ����ü�� ����Ű�� ������ �迭

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

	printf("�����ߴ� ���� ������ �ε��ϰڽ��ϱ�??\n1. �ε��Ѵ�\t2. ���� �����Ѵ�.\n");
	scanf("%d", &select_num);
	getc(stdin);
	while(select_num != 1 && select_num != 2)
	{
		printf("��ȣ�� �߸� �Է��ϼ̽��ϴ�. �ٽ� �Է��� �ֽʽÿ�.\n");
		printf("1. �ε��Ѵ�\t2. ���� �����Ѵ�.\n");
		scanf("%d", &select_num);
		getc(stdin);
	}
	
	if(select_num ==1)
	{
		if((pf=fopen("document.txt", "r+")) == NULL)
		{
			printf("���� ����� ���������� �����ϴ�.\n");
		}
		else
		{
			printf("���� ����Ǿ� �ִ� ���������� �ҷ����Դϴ�.\n");
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
					printf("%d���� ���� %s�� �������� �ʴ� ����� ������ �� �����ϴ�.\n", i + 1, data[i].filename);
					i--;
					Document_count--;
				}
				else
				{
					data[i].new_date=fd.time_create;//���� �ۼ���¥
					strcpy(data[i].new_date_string,ctime(&fd.time_create));
					data[i].update_date=fd.time_write;//���� ������¥
					strcpy(data[i].update_date_string,ctime(&fd.time_write));
					data[i].file_size=fd.size;//����ũ��
				}
			}

			printf("%d���� ���������� �����Ͽ����ϴ�.\n", Document_count);
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
		printf("���� ���� ������ �����Ͽ����ϴ�\n");
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