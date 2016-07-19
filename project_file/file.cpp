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
	
	//char all_file_name[100][100];//폴더내의 모든 txt파일의 이름을 저장할 배열
	//data.h파일에 넣어놨음
	
	char folder_name[200] = {0, };
	char ran_folder_name[200];
	char *folder=NULL;
	int count_file=0;
	int i=0;
	extern int new_Document_count;
	extern int Document_count;
	char all_file_name[100][100];//폴더내의 모든 txt파일의 이름을 저장할 배열
	
	extern Document data[1000]; //문서 정보의 구조체를 가리키는 포인터 배열
	
	_finddata_t fd;
	long handle;
	int result=1;
	int new_count = 0;
	
		
	//폴더경로를 입력받음
	
	
		printf("\n\n  일괄등록할 폴더이름:");
		fflush(stdin);
		gets(folder_name); //   -->  c:/"폴더이름"

		if(folder_name[0] != NULL)
		{
			strcat(folder_name, "/");
			strcpy(ran_folder_name, folder_name);
			strcat(folder_name,".");
		}
		if ((dirp = opendir(folder_name)) == NULL) 
		{
			printf("\n폴더 이름을 잘못 입력하셨습니다.\n\n");
			return -1;
		}
	

	//폴더 내에 위치한 텍스트 파일들을 확인
	printf("<파일목록>\n");
	while((direntp=readdir(dirp))!=NULL)
	{
		
		if(direntp->d_name[0]=='.')//하위로 갈때..
		{
			continue;
		}

		else
		{
		//**파일이름 뒤쪽을 검사하여 txt파일인지 찾아내고, 저장, 출력 - 시작 -
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
			//**파일이름 뒤쪽을 검사하여 txt파일인지 찾아내고, 저장, 출력 - 끝
		}

		
    }

	count_file=i;
	//printf("-->파일개수:%d\n",count_file + 1);


	for(i=0;i<count_file;i++)//all_file_name에 파일이름을 제대로 입력받았나 test
	{
		printf("%s\n",all_file_name[i]);
	}


	for(i=0;i<count_file;i++)//파일정보를 구조체에 저장 
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

	printf("\n문서 개수 : %d\n", count_file);
	_findclose(handle);
	closedir(dirp);

	return 0;
 }