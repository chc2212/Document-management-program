#include<stdio.h>
#include <sys/types.h>
#include <io.h>
#include <time.h>
#include<string.h>

#include"file.h"
#include"data.h"
#include "ui.h"


 int File()
 {
	DIR *dirp;
	struct dirent *direntp;
	
	//char all_file_name[100][100];//�������� ��� txt������ �̸��� ������ �迭
	//data.h���Ͽ� �־����
	
	char folder_name[200] = {0, };
	char ran_folder_name[200];
	char *folder=NULL;
	int count_file=0;
	int i=0;
	extern int new_Document_count;
	extern int Document_count;
	char all_file_name[100][100];//�������� ��� txt������ �̸��� ������ �迭
	
	extern Document data[1000]; //���� ������ ����ü�� ����Ű�� ������ �迭
	
	_finddata_t fd;
	long handle;
	int result=1;
	int new_count = 0;
	
		
	//������θ� �Է¹���
	
	
		printf("\n\n  �ϰ������ �����̸�:");
		fflush(stdin);
		gets(folder_name); //   -->  c:/"�����̸�"

		if(folder_name[0] != NULL)
		{
			strcat(folder_name, "/");
			strcpy(ran_folder_name, folder_name);
			strcat(folder_name,".");
		}
		if ((dirp = opendir(folder_name)) == NULL) 
		{
			printf("\n���� �̸��� �߸� �Է��ϼ̽��ϴ�.\n\n");
			return -1;
		}
	

	//���� ���� ��ġ�� �ؽ�Ʈ ���ϵ��� Ȯ��
	printf("<���ϸ��>\n");
	while((direntp=readdir(dirp))!=NULL)
	{
		
		if(direntp->d_name[0]=='.')//������ ����..
		{
			continue;
		}

		else
		{
		//**�����̸� ������ �˻��Ͽ� txt�������� ã�Ƴ���, ����, ��� - ���� -
			int j=0;
			while(direntp->d_name[j]!=NULL)
			{
				j++;
			}
			if(direntp->d_name[j-1] == 't' && direntp->d_name[j-2] == 'x' && direntp->d_name[j-3] == 't' && direntp->d_name[j-4] == '.')
			{

				strcpy(all_file_name[i], ran_folder_name);
				strcat(all_file_name[i],direntp->d_name);
				//printf("%s\n",direntp->d_name);
				i++;
			}
			//**�����̸� ������ �˻��Ͽ� txt�������� ã�Ƴ���, ����, ��� - ��
		}

		
    }

	count_file=i;
	//printf("-->���ϰ���:%d\n",count_file + 1);


	for(i=0;i<count_file;i++)//all_file_name�� �����̸��� ����� �Է¹޾ҳ� test
	{
		printf("%s\n",all_file_name[i]);
	}


	for(i=0;i<count_file;i++)//���������� ����ü�� ���� 
	{
		new_count = i + Document_count;
		handle=_findfirst(all_file_name[i],&fd);

		data[new_count].num=i+1;
		strcpy(data[new_count].filename,all_file_name[i]);
		data[new_count].new_date=fd.time_create;
		strcpy(data[new_count].new_date_string,ctime(&fd.time_create));
		data[new_count].update_date=fd.time_write;
		strcpy(data[new_count].update_date_string,ctime(&fd.time_write));
		data[new_count].file_size=fd.size;

		result=_findnext(handle,&fd);

	}
	new_Document_count = count_file;

	printf("\n���� ���� : %d\n", count_file);
	_findclose(handle);
	closedir(dirp);

	return 0;
 }