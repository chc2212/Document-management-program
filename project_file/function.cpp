#include<stdio.h>
#include <sys/types.h>
#include <io.h>
#include <time.h>
#include<string.h>
#include<stdlib.h>


#include"function.h"
#include "ui.h"
#define charNum 450000

void Registration() //문서 등록하는 함수 
{
	int choice_num = 0; //문서 등록 방법 선택 시, 선택 번호 저장 
	char empty;
	

	//printf("\n①Registration\n");
	//printf("<등록방법 선택>\n");
	while(choice_num != 1 && choice_num != 2)
	{
		//printf("1.일괄등록  2.하나등록\n");
		//printf("Enter_the_choice_number:");
		choice_num = ui(2,5,5,30,"① Registration ","Q) 등록방법을 선택해주세요. \n\n",0,2,"① 일괄등록 ","② 하나등록 ","");
		//scanf("%d",&choice_num);
		//empty = getc(stdin);

		//백스페이스 입력
		if(choice_num==-10)
		{
			return ;
		}

		if(choice_num==1)
		{
			Registration_All(); // 일괄 등록하는 함수
		}

 		else if(choice_num==2)
 		{
 			Registration_One();// 하나 등록하는 함수 
 		}
		/*
		else
		{	
			printf("번호를 잘못 입력하셨습니다.다시 입력해 주십시오.\n\n");
		}
		*/
	}

}//Registration


void Registration_All()//문서 일괄 등록하는 함수 
{
	int re_value=0;//FIle함수에서 받아올 리턴 값
	re_value=File();//File함수에서 폴더 내의 모든 문서에 대한 정보를 읽어옴 
	 
	if(re_value==0)
	{
	extern Document data[1000];
	
	for(int i = Document_count; i < Document_count + new_Document_count; i++)
	{
		//ui(15,5,5,30,"① Registration ","\n\n",0,2,"① 일괄등록 ","② 하나등록 ","");
		printf("\n%d번째 문서의 정보 입력을 시작하겠습니다.\n", i + 1);
		data[i].num = i+1;
		printf("문서 종류:");
		fflush(stdin);
		gets(data[i].type);
	//	getc(stdin);
		printf("문서 제목:");
		fflush(stdin);
		gets(data[i].title);
	//	getc(stdin);
		printf("작성자:");
		fflush(stdin);
		gets(data[i].writer);
	//	getc(stdin);
	}

	Document_count += new_Document_count;
	if(new_Document_count != 0)
	{
		printf("\n총 %d개의 문서 등록을 완료하였습니다.\n", new_Document_count);
	}
	else
	{
		printf("폴더 안에 문서가 없습니다.\n");
	}
	printf("\n현재 %d개의 문서가 등록되어 있습니다.\n", Document_count);


	}
	

}//Registration_All

void Registration_One()//문서 하나 등록하는 함수
{
	
	char filename[100];
	char all_file_name[100][100];//폴더내의 모든 txt파일의 이름을 저장할 배열
	
	extern Document data[1000]; //문서 정보의 구조체를 가리키는 포인터 배열

	_finddata_t fd;
	long handle;
	int result=1;
	char empty;

	//printf("\n\n  일괄등록할 폴더이름:");
	printf("\n\n등록하고자 하는 파일이름(파일경로포함)을 입력해주세요.\n");
	scanf("%s",filename);
	 
	if((handle=_findfirst(filename,&fd)) == -1L)
		printf("문서가 없습니다.상위 메뉴로 돌아갑니다.\n\n");
	else
	{
		Document_count++;//파일 개수 추가 
		data[Document_count - 1].num=Document_count;//파일 번호
		strcpy(data[Document_count - 1].filename,filename);//파일이름 
		data[Document_count - 1].new_date=fd.time_create;//파일 작성날짜
		strcpy(data[Document_count - 1].new_date_string,ctime(&fd.time_create));
		data[Document_count - 1].update_date=fd.time_write;//파일 수정날짜
		strcpy(data[Document_count - 1].update_date_string,ctime(&fd.time_write));
		data[Document_count - 1].file_size=fd.size;//파일크기

		//나머지정보 사용자가 입력 
		empty = getc(stdin);	
		printf("문서 종류:");
		fflush(stdin);
		gets(data[Document_count - 1].type);//파일 종류
	//	getc(stdin);
		printf("문서 제목:");
		fflush(stdin);
		gets(data[Document_count - 1].title);//파일제목
	//	  getc(stdin);
		printf("문서 작성자:");
		fflush(stdin);
		gets(data[Document_count - 1].writer);//파일 작성자
	//	getc(stdin);

		//printf("%d\n", Document_count); 파일갯수 출력 왜 해주는지?
	}
	_findclose(handle);

}//Registration_One

void Show_All() //전체 문서에 관한 정보 보기 함수  
{	
	extern Document data[1000]; //문서 정보의 구조체를 가리키는 포인터 배열
	int choice_num; //정렬방법 선택 시, 선택 번호 저장

	
	/*
	printf("<정렬방법 선택>\n");
	printf("1.문서등록번호	2.문서종류	3. 문서제목  4. 작성자 \n");
	printf("5.문서작성날짜   6.문서수정날짜  7. 문서크기\n");
	printf("Enter_the_choice_number:");
	scanf("%d",&choice_num);	
	*/

	choice_num = ui(2,5,5,30,"② Show_All ","Q) 등록방법을 선택해주세요. \n\n",3,7,"","","");
	
	//백스페이스 입력 뒤로가기
		if(choice_num==-10)
		{
			return ;
		}
	
	switch(choice_num)
	{
		case 1:
			Sort_num() ;
			break;
		case 2:
			Sort_type(0) ;
			Sort_original();
			
			break;
		case 3:
			Sort_title() ;
			Sort_original();
			break;
		case 4:
			Sort_writer() ;
			Sort_original();
			break;
		case 5:
			Sort_new_date() ;
			Sort_original();
			break;
		case 6:
			Sort_update_date() ;
			Sort_original();
			break;
		case 7:
			Sort_file_size() ;
			Sort_original();
			break;
	
		default:
			break;
	}



}

void Sort_original()
{
	extern Document data[1000]; //문서 정보의 구조체를 가리키는 포인터 배열
	
	qsort((void*)&data,Document_count,sizeof(Document), compare_num );
	
	
		
}

int compare_num (const void *a, const void *b)
{
	Document *a1=(Document *)a;
	Document *b1=(Document *)b;
	
	return (a1->num - b1->num);
}

int compare_type (const void *a, const void *b)
{
	Document *a1=(Document *)a;
	Document *b1=(Document *)b;
	
	
	return strcmp( a1->type ,b1->type);
}

int compare_title (const void *a, const void *b)
{
	Document *a1=(Document *)a;
	Document *b1=(Document *)b;
	
	
	return strcmp( a1->title ,b1->title);
}


int compare_writer (const void *a, const void *b)
{
	Document *a1=(Document *)a;
	Document *b1=(Document *)b;
	
	
	return strcmp( a1->writer ,b1->writer);
}




int compare_new_date (const void *a, const void *b)
{
	Document *a1=(Document *)a;
	Document *b1=(Document *)b;
	
	
	return ( a1->new_date - b1->new_date);
}



int compare_update_date (const void *a, const void *b)
{
	Document *a1=(Document *)a;
	Document *b1=(Document *)b;
	
	
	return ( a1->update_date - b1->update_date);
}



int compare_file_size (const void *a, const void *b)
{
	Document *a1=(Document *)a;
	Document *b1=(Document *)b;
	
	
	return ( a1->file_size - b1->file_size);
}


void Sort_num()
{
	extern Document data[1000]; //문서 정보의 구조체를 가리키는 포인터 배열
	
	qsort((void*)&data,Document_count,sizeof(Document), compare_num );
	
	printf("등록번호 |          문서종류          |          문서제목          |          작성자          \n");
	for(int i = 0 ; i < Document_count ; i++)
	{
		Show_File(1, data[i],0);
	}
		
}


void Sort_type(int g) 
{
	int i, j;
	int start_num;
	int end_num;
	int count;
	extern Document data[1000]; //문서 정보의 구조체를 가리키는 포인터 배열

	qsort((void*)&data,Document_count,sizeof(Document), compare_type );

	for(i=0;i<Document_count - 1;i++)
	{ 
		if(strcmp(data[i].type,data[i + 1].type)==0)//검색할 문서제목를 찾을때
		{
			start_num = i;
			j = i + 1;
			while(j < Document_count)
			{
				if(strcmp(data[j].type, data[j + 1].type) == 0)
				{
					j++;
				}
				else
					break;
			}
			end_num = j;
			count = end_num - start_num + 1;
			qsort((void*)&data[start_num],count,sizeof(Document), compare_num);
			i = end_num;
		}
	}
	if(g==0)
	{
		printf("등록번호 |          문서종류          |          문서제목          |          작성자          \n");
	for(i = 0; i < Document_count ; i++)
	{
		Show_File(1, data[i],0);
	}

	}
}
	
void Sort_title() 
{
	int i, j;
	int start_num;
	int end_num;
	int count;
	extern Document data[1000]; //문서 정보의 구조체를 가리키는 포인터 배열

	qsort((void*)&data,Document_count,sizeof(Document), compare_title );

	for(i=0;i<Document_count - 1;i++)
	{ 
		if(strcmp(data[i].title,data[i + 1].title)==0)//검색할 문서제목를 찾을때
		{
			start_num = i;
			j = i + 1;
			while(j < Document_count)
			{
				if(strcmp(data[j].title, data[j + 1].title) == 0)
				{
					j++;
				}
				else
					break;
			}
			end_num = j;
			count = end_num - start_num + 1;
			qsort((void*)&data[start_num],count,sizeof(Document), compare_num);
			i = end_num;
		}
	}
	printf("등록번호 |          문서종류          |          문서제목          |          작성자          \n");
	for(i = 0 ; i < Document_count ; i++)
	{
		Show_File(1, data[i],0);
	}
}
void Sort_writer()
{
	int i, j;
	int start_num;
	int end_num;
	int count;
	extern Document data[1000]; //문서 정보의 구조체를 가리키는 포인터 배열

	qsort((void*)&data,Document_count,sizeof(Document), compare_writer );

	for(i=0;i<Document_count - 1;i++)
	{ 
		if(strcmp(data[i].writer,data[i + 1].writer)==0)//검색할 문서제목를 찾을때
		{
			start_num = i;
			j = i + 1;
			while(j < Document_count)
			{
				if(strcmp(data[j].writer, data[j + 1].writer) == 0)
				{
					j++;
				}
				else
					break;
			}
			end_num = j;
			count = end_num - start_num + 1;
			qsort((void*)&data[start_num],count,sizeof(Document), compare_num);
			i = end_num;
		}
	}
	printf("등록번호 |          문서종류          |          문서제목          |          작성자          \n");
	for(i = 0 ; i < Document_count ; i++)
	{
		Show_File(1, data[i],0);
	}
}


void Sort_new_date()
{
	int i, j;
	int start_num;
	int end_num;
	int count;
	extern Document data[1000]; //문서 정보의 구조체를 가리키는 포인터 배열

	//qsort((void*)&data,Document_count,sizeof(data[0].new_date), compare_new_date );
	qsort((void*)&data,Document_count,sizeof(Document), compare_new_date );
	
	for(i=0;i<Document_count - 1;i++)
	{ 
		if(data[i].new_date == data[i + 1].new_date)//검색할 문서제목를 찾을때
		{
			start_num = i;
			j = i + 1;
			while(j < Document_count)
			{
				if(data[j].new_date == data[j + 1].new_date)
				{
					j++;
				}
				else
					break;
			}
			end_num = j;
			count = end_num - start_num + 1;

			qsort((void*)&data[start_num],count,sizeof(Document), compare_num);
			i = end_num;
		}
	}

	printf("등록번호 |          문서종류          |          문서제목          |          작성자          |          작성날짜          \n");
	for(int i = 0 ; i < Document_count ; i++)
	{
		Show_File(2, data[i],5);
	}
}
void Sort_update_date()
{
	int i, j;
	int start_num;
	int end_num;
	int count;
	extern Document data[1000]; //문서 정보의 구조체를 가리키는 포인터 배열

	//qsort((void*)&data,Document_count,sizeof(data[0].update_date), compare_update_date );
	qsort((void*)&data,Document_count,sizeof(Document), compare_update_date );

	for(i=0;i<Document_count - 1;i++)
	{ 
		if(data[i].update_date == data[i + 1].update_date)//검색할 문서제목를 찾을때
		{
			start_num = i;
			j = i + 1;
			while(j < Document_count)
			{
				if(data[j].update_date == data[j + 1].update_date)
				{
					j++;
				}
				else
					break;
			}
			end_num = j;
			count = end_num - start_num + 1;

			qsort((void*)&data[start_num],count,sizeof(Document), compare_num);
			i = end_num;
		}
	}

	printf("등록번호 |          문서종류          |          문서제목          |          작성자          |          수정날짜          \n");
	for(int i = 0 ; i < Document_count ; i++)
	{
		Show_File(2, data[i],6);
	}
}
void Sort_file_size()
{
	int i, j;
	int start_num;
	int end_num;
	int count;
	extern Document data[1000]; //문서 정보의 구조체를 가리키는 포인터 배열

	//qsort((void*)&data,Document_count,sizeof(data[0].file_size), compare_file_size );
	qsort((void*)&data,Document_count,sizeof(Document), compare_file_size );
	
	for(i=0;i<Document_count - 1;i++)
	{ 
		if(data[i].file_size == data[i + 1].file_size)//검색할 문서제목를 찾을때
		{
			start_num = i;
			j = i + 1;
			while(j < Document_count)
			{
				if(data[j].file_size == data[j + 1].file_size)
				{
					j++;
				}
				else
					break;
			}
			end_num = j;
			count = end_num - start_num + 1;

			qsort((void*)&data[start_num],count,sizeof(Document), compare_num);
			i = end_num;
		}
	}
	printf("등록번호 |          문서종류          |          문서제목          |          작성자          |          파일크기          \n");
	for(int i = 0 ; i < Document_count ; i++)
	{
		Show_File(2, data[i],7);
	}
}




void Show_File(int choice_show, struct Document data,int choice_add)
{
	extern int Document_count;
	//extern Document data[1000];
	

	if(choice_show==1)//해당 문서의 문서 등록 번호, 종류, 제목, 작성자만 출력
	{
	
		printf("    %d     ",data.num); //등록번호

		printf("   %s",data.type); //문서종류
		//*칸맞춰주기 위한 작업 -시작-
		int j=0;
		while(data.type[j]!=NULL)
			j++;
		while(j!=30)
		{
			printf(" ");
			j++;
		}	
		//*칸맞춰주기 위한 작업 -끝-

		printf("%s",data.title); //문서제목
		//*칸맞춰주기 위한 작업 -시작-
		j=0;
		while(data.title[j]!=NULL)
			j++;
		while(j!=30)
		{
			printf(" ");
			j++;
		}	
		//*칸맞춰주기 위한 작업 -끝-

		printf("%s\n",data.writer); //작성자
		//*칸맞춰주기 위한 작업 -시작-
		j=0;
		
	}
	else if(choice_show==2)
	{
		
		//해당 문서의 문서 등록 번호, 종류, 제목, 작성자 +a출력
		//*a는 문서 작성 날짜, 문서 수정 날짜, 문서 크기 중 하나 
		//	printf("작성날짜 : %s수정날짜 : %s크기 : %d\n", data.new_date, data.update_date, data.file_size);

		if(choice_add == 5) //작성날짜를 원하면
		{
			//	printf("등록번호 |          문서종류          |          문서제목          |          작성자          |          작성날짜          \n");
				printf("    %d     ",data.num); //등록번호

		printf("   %s",data.type); //문서종류
		//*칸맞춰주기 위한 작업 -시작-
		int j=0;
		while(data.type[j]!=NULL)
			j++;
		while(j!=30)
		{
			printf(" ");
			j++;
		}	
		//*칸맞춰주기 위한 작업 -끝-

		printf("%s",data.title); //문서제목
		//*칸맞춰주기 위한 작업 -시작-
		j=0;
		while(data.title[j]!=NULL)
			j++;
		while(j!=30)
		{
			printf(" ");
			j++;
		}	
		//*칸맞춰주기 위한 작업 -끝-

		printf("%s",data.writer); //작성자
		//*칸맞춰주기 위한 작업 -시작-
		j=0;
		while(data.writer[j]!=NULL)
			j++;
		while(j!=30)
		{
			printf(" ");
			j++;
		}	
		//*칸맞춰주기 위한 작업 -끝-

		printf("%s",data.new_date_string); //작성날짜
		//*칸맞춰주기 위한 작업 -시작-
		
		//*칸맞춰주기 위한 작업 -끝-
		}

	//******************************************
			if(choice_add == 6) //수정날짜를 원하면
		{
				//printf("등록번호 |          문서종류          |          문서제목          |          작성자          |          수정날짜          \n");
				printf("    %d     ",data.num); //등록번호

		printf("   %s",data.type); //문서종류
		//*칸맞춰주기 위한 작업 -시작-
		int j=0;
		while(data.type[j]!=NULL)
			j++;
		while(j!=30)
		{
			printf(" ");
			j++;
		}	
		//*칸맞춰주기 위한 작업 -끝-

		printf("%s",data.title); //문서제목
		//*칸맞춰주기 위한 작업 -시작-
		j=0;
		while(data.title[j]!=NULL)
			j++;
		while(j!=30)
		{
			printf(" ");
			j++;
		}	
		//*칸맞춰주기 위한 작업 -끝-

		printf("%s",data.writer); //작성자
		//*칸맞춰주기 위한 작업 -시작-
		j=0;
		while(data.writer[j]!=NULL)
			j++;
		while(j!=30)
		{
			printf(" ");
			j++;
		}	
		//*칸맞춰주기 위한 작업 -끝-

		printf("%s",data.update_date_string); //수정날짜
		//*칸맞춰주기 위한 작업 -시작-
		/*
		j=0;
		while(data.type[j]!=NULL)
			j++;
		while(j!=30)
		{
			printf(" ");
			j++;
		}	
		*/
		//*칸맞춰주기 위한 작업 -끝-
		}

		//****************************
				if(choice_add == 7) //파일크기를 원하면
		{
				//printf("등록번호 |          문서종류          |          문서제목          |          작성자          |          파일크기          \n");
				printf("    %d     ",data.num); //등록번호

		printf("   %s",data.type); //문서종류
		//*칸맞춰주기 위한 작업 -시작-
		int j=0;
		while(data.type[j]!=NULL)
			j++;
		while(j!=30)
		{
			printf(" ");
			j++;
		}	
		//*칸맞춰주기 위한 작업 -끝-

		printf("%s",data.title); //문서제목
		//*칸맞춰주기 위한 작업 -시작-
		j=0;
		while(data.title[j]!=NULL)
			j++;
		while(j!=30)
		{
			printf(" ");
			j++;
		}	
		//*칸맞춰주기 위한 작업 -끝-

		printf("%s",data.writer); //작성자
		//*칸맞춰주기 위한 작업 -시작-
		j=0;
		while(data.writer[j]!=NULL)
			j++;
		while(j!=30)
		{
			printf(" ");
			j++;
		}	
		//*칸맞춰주기 위한 작업 -끝-

		printf("%d\n",data.file_size); //파일크기
		//*칸맞춰주기 위한 작업 -시작-
		/*
		j=0;
		while(data.type[j]!=NULL)
			j++;
		while(j!=30)
		{
			printf(" ");
			j++;
		}	
		*/
		//*칸맞춰주기 위한 작업 -끝-
		}


	}

}



void Search_File() //문서 찾기 함수
{
	int choice_num; 
	char temp_arr[30]={0};
	extern Document data[1000]; //문서 정보의 구조체를 가리키는 포인터 배열
	 
	//printf("<찾기방법 선택>\n");
	//printf("1.문서종류 2. 문서제목  3. 작성자 \n");
	//printf("Enter_the_choice_number:");
	//scanf("%d",&choice_num); 

	choice_num = ui(2,5,5,30,"③ Search File","Q) 어떤 방법으로 찾을지 선택해주세요. \n\n",0,3,"① 문서 종류로 찾기","② 문서 제목으로 찾기","③ 작성자로 찾기");

	
	//백스페이스 입력 뒤로가기
		if(choice_num==-10)
		{
			return ;
		}
 
	if(choice_num==1)
	{
		printf("문서 종류:");
		scanf("%s",temp_arr); 


		for(int i=0;i<Document_count;i++)
		{
  
			if(strcmp(data[i].type,temp_arr)==0)//검색할 문서종류를 찾을때
			{
   
				Show_File(1,data[i],0);
			}
 
		}
	}
	else if(choice_num==2)
	{
		printf("문서 제목:");
		scanf("%s",temp_arr);

		for(int i=0;i<Document_count;i++)
		{
  
			if(strcmp(data[i].title,temp_arr)==0)//검색할 작성자를 찾을때
			{
   
				Show_File(1,data[i],0);
			}
		}

	}
	else if(choice_num==3)
	{
		printf("작성자:");
		scanf("%s",temp_arr);

		for(int i=0;i<Document_count;i++)
		{
  
			if(strcmp(data[i].writer,temp_arr)==0)//검색할 작성자를 찾을때
			{
   
				Show_File(1,data[i],0);
			}
		}
	}
}

int Search_Title()
{
	int cnt=0;
	char temp_arr[30]={0};
	int temp_num=0;
	int current_num = 0;
	extern Document data[1000]; //문서 정보의 구조체를 가리키는 포인터 배열
	//getc(stdin);
	printf("제목 입력\n:");
	fflush(stdin);
	gets(temp_arr); 
	//getc(stdin);
	 
	for(int i=0;i<Document_count;i++)
	{ 
		if(strcmp(data[i].title,temp_arr)==0)//검색할 문서제목를 찾을때
		{
			Show_File(1,data[i], 0);
			cnt++;
			current_num = i;
		}
	}
	if(cnt >= 2)//같은 제목이 여러개일 경우 
	{
		printf("제목이 같은 파일이 있습니다.\n");
	
		while(1)
		{
			printf("등록 번호 선택\n:");
			scanf("%d", &temp_num); 
			printf("문서 제목 : %s\n", data[temp_num - 1].title);
			if(strcmp(data[temp_num - 1].title,temp_arr) == 0)//선택한 번호의 제목과 일치할때
			{
				Show_File(1,data[temp_num - 1], 0);
				return temp_num - 1;		    
			}
			else
				printf("등록번호를 잘못 입력하셨습니다\n");
		}
	}
	else if(cnt == 0)
	{
		printf("등록된 문서가 없습니다.\n");
		return -1;
	}
	return current_num;

}

void Delete_File()//문서 정보 삭제하는 함수 
{
	extern Document data[1000]; //문서 정보의 구조체를 가리키는 포인터 배열

	int choice_num=0;
	struct Document doc;
	int ran;
	ran=Search_Title();

	if(ran != -1)
	{
		doc = data[ran];
		int i=0;


		for(i=doc.num-1;i<Document_count;i++)//i=doc.num-1  삭제하려는 문서의 등록번호부터
		{
			data[i].num=data[i+1].num;
			data[i].num--;
			strcpy(data[i].type,data[i+1].type);  
			strcpy(data[i].title,data[i+1].title);
			strcpy(data[i].writer,data[i+1].writer);
			strcpy(data[i].filename,data[i+1].filename);
			data[i].new_date=data[i+1].new_date;
		 data[i].update_date=data[i+1].update_date;
		 data[i].file_size=data[i+1].file_size;
		}

		
		Document_count--;
		printf("문서제목이 %s인 문서의 정보는 삭제되었습니다.\n\n",doc.title);
	 
		
		
		choice_num = ui(2,5,5,30,"④ Deletion","Q) 전체 문서의 정보를 확인하시겠습니까? \n\n",0,2,"① 예","② 아니요","");
		
	//백스페이스 입력 초기메뉴로
		if(choice_num==-10)
		{
			return ;
		}
		/*
		printf("전체 문서의 정보를 확인하시겠습니까?\n");
		printf("1.예 2.아니요\n");
		printf("Enter_the_choice_number:");
		scanf("%d",&choice_num);
		*/
		if(choice_num==1)
		{
	 
			for(i=0;i<Document_count;i++)
			{
				Show_File(1,  data[i], 0);
			}
		}
	}
}

void Modification_File()
{
	extern Document data[1000]; //문서 정보의 구조체를 가리키는 포인터 배열
	int choice_num=0;
 
	struct Document doc;
	int ran;
	ran=Search_Title();

	if(ran != -1)
	{
		doc = data[ran];

		choice_num = ui(2,5,5,30,"⑤ Modification","Q) 수정할 항목을 선택해주세요. \n\n",0,3,"① 문서종류","② 문서제목","③ 작성자");
	
	//백스페이스 입력 초기메뉴로
		if(choice_num==-10)
		{
			return ;
		}
		/*
		printf("<수정할 항목 선택>\n");
		printf("1.문서종류 2. 문서제목  3. 작성자 \n");
		printf("Enter_the_choice_number:");
		scanf("%d",&choice_num); 
	*/ 
		if(choice_num==1)
		{
			printf("문서 종류:");
			scanf("%s",data[doc.num-1].type); 
	  
		}


		else if(choice_num==2)
		{
			printf("문서 제목:");
			scanf("%s",data[doc.num-1].title);
	  
		}

		else if(choice_num==3)
		{
			printf("작성자:");
			scanf("%s",data[doc.num-1].writer);

		}
	}
}


void Word()
{
	int select_num = 0;
	char empty;
	char searchword[10] = {0, };
	char title_text[10] = {0, };
	extern Document data[1000];
	struct Document doc;
	int ran;

//	printf("\n⑥Search_Word \n");
	while(select_num != 1 && select_num !=2)
	{  

		//printf("전체 문서 단어 검색을 원할 시 1번, 특정 문서 단어 검색을 원할 시 2번을 누르세요\n");
			select_num = ui(2,5,5,30,"⑥ Search_Word ","Q) 단어 검색영역을 선택해주세요. \n\n",0,2,"① 전체문서 단어 검색 ","② 특정문서 단어 검색 ","");
				
	//백스페이스 입력 초기메뉴로
		if(select_num==-10)
		{
			return ;
		}
		//scanf("%d", &select_num);
		//empty = getc(stdin);
		if(select_num != 1 && select_num != 2)
			printf("번호를 잘못 입력하셨습니다. 다시 입력해 주십시오.\n");
	}

	if(select_num == 1)
	{
		printf("\n찾고자 하는 단어를 입력하세요.\n한글은 지원하지 않으며 대문자, 소문자는 상관없습니다.\n");
		scanf("%s", searchword);
		printf("\n");
		AllSearchWord(searchword);
	}
	else if(select_num == 2)
	{
		ran=Search_Title();

		if(ran != -1)
		{
			doc = data[ran];
			OneSearchWord(searchword, doc.filename);
		}
	}
}

void AllSearchWord(char searchword[])
{
	extern Document data[1000];
	FILE *pf;
	InforWord *Infors;
	int i = 0, j = 0, k = 0;									//for문 돌리기 위한 변수
	int paragraph = 0;											//문단의 갯수를 나타내는 변수
	int length = 0;												//총 단어의 길이를 나타내는 변수
	int para_length = 0;										//문단 내의 최대 단어수를 나타내는 변수
	int find_length = 0;										//문단 내의 최대 단어수를 찾기 위한 변수
	int x = 0, y = 0;											//word_data배열 내에서 이동하기 위한 변수
	int count = 0;												//입력한 단어의 총 아스키코드 합
	int word_count;												//검색할 단어의 총 아스키코드 합
	int num_word = 0;											//입력한 단어의 길이
	int change_numWord = 0;										//바꿀 단어의 길이
	int ran_num;												//임의로 쓰일 숫자들
	int st_word, ed_word;										//원래 단어의 시작 위치, 끝위치
	char compare_char1, compare_char2;							//단어들의 대문자, 소문자를 통일시키기 위해 사용하는 변수
	bool check;													//단어 비교 시, 일치하는지 안하는지를 비교하기 위한 변수
	bool word_check = 0;										//단어가 전체문서내에 있는지 없는지를 체크하기 위한 변수
	char empty;
	int select_num = 0;											//선택을 위해 사용하는 변수
	int doc_check;
	char change_word[10] = {0, };
	char title_text[200];
	char file_text_data[charNum];
	int end_num;

	Infors = (InforWord*)malloc(sizeof(InforWord) * Document_count);

	for(i = 0 ; i < 10 ; i++)									
	{
		if(searchword[i] != 0)
		{
			ran_num = searchword[i];
			if(ran_num >= 65 && ran_num <= 90)
				ran_num += 32;
			count += ran_num;
		}
	}
	num_word = strlen(searchword);
	
	for(doc_check = 0 ; doc_check < Document_count ; doc_check++)
	{
		for(i = 0 ; i < charNum ; i++)
			file_text_data[i] = 0;
		x = 0;
		for(j = 0 ; j < 100 ; j++)
		{
			for(k = 0 ; k < 3 ; k++)
			{
				Infors[doc_check].catch_word[j][k] = 0;
			}
		}

		strcpy(title_text, data[doc_check].filename);

		if((pf=fopen(title_text, "rb")) == NULL)
		{
			printf("Can't open ");
		}
		else	
		{
			fread(file_text_data, sizeof file_text_data, 1, pf);
			end_num = charNum;
			//입력한 단어의 아스키코드값, 길이를 계산
			
			for(i = 0 ; i < charNum ; i++)
			{
				if(file_text_data[i] == 0)
				{
					end_num = i;
					break;
				}
				if(file_text_data[i] == 13)	//문단 구분하기 위한 첫번째 방법
				{
					if(file_text_data[i + 2] != 13 && file_text_data[i - 1] != 32)	//엔터 받은 뒤 그 위치가 문단의 중간 부분인지, 시작 부분인지를 구별하기 위한 방법
					{
						paragraph += 1;									//몇번째 문단인지를 파악
					}
				}
				word_count = 0;											//각각의 아스키코드를 구해야되기 때문에 항상 초기화
				for(j = i ; j < i + num_word ; j++)						//각 배열의 위치에서부터 아스키코드값을 계산
				{
					ran_num = file_text_data[j];
					if(ran_num >= 65 && ran_num <= 90)
						ran_num += 32;
					word_count += ran_num;
				}

				if(count == word_count)									//아스키 코드값이 일치하는 경우
				{
					check = 0;											//단어 비교를 위한 변수 초기화
					for(j = 0 ; j < num_word ; j++)						//현재 배열의 위치에서부터 입력받은 단어의 길이만큼
					{
						compare_char1 = file_text_data[i + j];			//대문자 소문자 비교를 위해 값을 따로 저장
						compare_char2 = searchword[j];
						if(compare_char1 >= 65 && compare_char1 <= 97)	//대문자인 경우 소문자로 변환
							compare_char1 += 32;
						if(compare_char2 >= 65 && compare_char2 <= 97)
							compare_char2 += 32;
						if(compare_char1 != compare_char2)				//소문자로 변환한 단어를 비교
							check = 1;
					}
					if(check == 0)										//입력 단어를 찾은 경우
					{
						Infors[doc_check].catch_word[x][0] = paragraph;			//현재 단어가 있는 문단의 위치를 저장
						Infors[doc_check].catch_word[x][1] = i;					//단어가 일치하는 배열의 위치를 저장
						x++;											//다음 단어를 저장할 위치로 변경
					}
				}

			}
			Infors[doc_check].find_num = x;										//찾은 단어들의 갯수
			if(x != 0)	word_check = 1;

			for(i = 0 ; i < x ; i++)									//찾은 문서내 단어의 원래 원형을 파악
			{
				st_word = Infors[doc_check].catch_word[i][1];						//찾은 원형 단어의 시작 위치를 파악
				while(file_text_data[st_word - 1] >= 65 && file_text_data[st_word - 1] <= 122)
				{
					st_word -= 1;
				}
				Infors[doc_check].catch_word[i][1] = st_word;

				ed_word = Infors[doc_check].catch_word[i][1];						//찾은 원형 단어의 끝 위치를 파악
				while(file_text_data[ed_word + 1] >= 65 && file_text_data[ed_word + 1] <= 122)
				{
					ed_word += 1;
				}
				Infors[doc_check].catch_word[i][2] = ed_word;
			}
			printf("%d번 문서에서 %d개의 단어를 검색하였습니다.\n", data[doc_check].num, Infors[doc_check].find_num);
		}
	}

	printf("\n단어 검색이 완료되었습니다.\n");

	if(word_check)
	{
		select_num = ui(2,5,5,30,"⑥ Search_Word ","Q) 문서의 내용을 통해 단어 위치를 확인하시겠습니까? \n\n",0,2,"① 한다 ","② 안한다 ","");
	
		//printf("문서의 내용을 통해 단어 위치를 확인하시겠습니까??\n");
	//	printf("\n1. 한다.\t2. 안한다.\n");

	//	scanf("%d", &select_num);

		if(select_num == 1)
		{

			printf("\n  단어 위치를 확인할 문서의 번호를 입력하세요.\n");
			scanf("%d", &select_num);
			x = 0;

			strcpy(title_text, data[select_num - 1].filename);
			if((pf=fopen(title_text, "rb")) == NULL)
			{
				printf("Can't open ");
			}
			else
			{
				fread(file_text_data, sizeof file_text_data, 1, pf);

				for(i = 0 ; i < end_num ; i++)
				{
					if(i == Infors[select_num - 1].catch_word[x][1])
						printf("★");
					printf("%c", file_text_data[i]);
					if(i == Infors[select_num - 1].catch_word[x][2])
					{
						printf("★");
						x++;
					}
				}
				printf("\n출력을 완료하였습니다.\n\n");
			}
		}

		//단어 수정

		select_num = ui(2,5,5,30,"⑥ Search_Word ","Q) 찾은 단어들을 전부 수정하시겠습니까?? \n\n",0,2,"① 수정한다 ","② 안한다 ","");
	
					
	//백스페이스 입력 초기메뉴로
		if(select_num==-10)
		{
			return ;
		}
	//	printf("찾은 단어들을 전부 수정하시겠습니까??\n1. 수정한다. 2. 안한다.\n");
	//	scanf("%d", &select_num);
		//empty = getc(stdin);
		
		if(select_num == 1)
		{
			printf("\n  바꿀 단어를 입력하십시오.\n");
			fflush(stdin);
			gets(change_word);
		//	getc(stdin);
			for(i = 0 ; i < Document_count ; i++)
			{
				if(Infors[i].find_num != 0)
				{
					for(j = 0 ; j < charNum ; j++)
						file_text_data[j] = 0;
					strcpy(title_text, data[i].filename);
					if((pf=fopen(title_text, "rb")) == NULL)
					{
						printf("Can't open ");
					}
					else
					{
						fread(file_text_data, sizeof file_text_data, 1, pf);
						changeWord(file_text_data, num_word, Infors[i], title_text, change_word);	//단어 수정 함수 호출	
					}
				}
			}
		}
		
	}
	else
		printf("문서 전체에서 찾은 단어가 0이기 때문에 단어위치확인 및 단어수정 작업은 하지 않습니다.\n");
	fclose(pf);
	free(Infors);
}

void OneSearchWord(char searchword[], char title_text[])		//검색할 단어, 파일 문서 이름
{
	FILE *pf;
	int i = 0, j = 0, k = 0;									//for문 돌리기 위한 변수
	int paragraph = 0;											//문단의 갯수를 나타내는 변수
	int length = 0;												//총 단어의 길이를 나타내는 변수
	int para_length = 0;										//문단 내의 최대 단어수를 나타내는 변수
	int find_length = 0;										//문단 내의 최대 단어수를 찾기 위한 변수
	int x = 0, y = 0;											//word_data배열 내에서 이동하기 위한 변수
	InforWord infor1;											//검색단어 정보 구조체/
	int count = 0;												//입력한 단어의 총 아스키코드 합
	int word_count;												//검색할 단어의 총 아스키코드 합
	int num_word = 0;											//입력한 단어의 길이
	int change_numWord = 0;										//바꿀 단어의 길이
	int ran_num;												//임의로 쓰일 숫자들
	int st_word, ed_word;										//원래 단어의 시작 위치, 끝위치
	char compare_char1, compare_char2;							//단어들의 대문자, 소문자를 통일시키기 위해 사용하는 변수
	bool check;													//단어 비교 시, 일치하는지 안하는지를 비교하기 위한 변수
	char empty;
	int select_num = 0;											//선택을 위해 사용하는 변수
	char change_word[10] = {0, };
	int end_num;

	for(i = 0 ; i < 100 ; i++)
	{
		for(j = 0 ; j < 3 ; j++)
		{
			infor1.catch_word[i][j] = 0;
		}
	}
	if((pf=fopen(title_text, "rb")) == NULL)
	{
		printf("Can't open \n");
	}

	printf("\n찾고자 하는 단어를 입력하세요.\n한글은 지원하지 않으며 대문자, 소문자는 상관없습니다.\n");
	scanf("%s", searchword);
	printf("\n");

	char file_text_data[charNum] = {0, };

	fread(file_text_data, sizeof file_text_data, 1, pf);
	
	//입력한 단어의 아스키코드값, 길이를 계산
	for(i = 0 ; i < 10 ; i++)									
	{
		if(searchword[i] != 0)
		{
			ran_num = searchword[i];
			if(ran_num >= 65 && ran_num <= 90)
				ran_num += 32;
			count += ran_num;
		}
	}
	num_word = strlen(searchword);

	end_num = charNum;
	for(i = 0 ; i < charNum ; i++)
	{
		if(file_text_data[i] == 0)
		{
			end_num = i;
			break;
		}
		if(file_text_data[i] == 13)	//문단 구분하기 위한 첫번째 방법
		{
			if(file_text_data[i + 2] != 13 && file_text_data[i - 1] != 32)	//엔터 받은 뒤 그 위치가 문단의 중간 부분인지, 시작 부분인지를 구별하기 위한 방법
			{
				paragraph += 1;									//몇번째 문단인지를 파악
			}
		}
		word_count = 0;											//각각의 아스키코드를 구해야되기 때문에 항상 초기화
		for(j = i ; j < i + num_word ; j++)						//각 배열의 위치에서부터 아스키코드값을 계산
		{
			ran_num = file_text_data[j];
			if(ran_num >= 65 && ran_num <= 90)
				ran_num += 32;
			word_count += ran_num;
		}

		if(count == word_count)									//아스키 코드값이 일치하는 경우
		{
			check = 0;											//단어 비교를 위한 변수 초기화
			for(j = 0 ; j < num_word ; j++)						//현재 배열의 위치에서부터 입력받은 단어의 길이만큼
			{
				compare_char1 = file_text_data[i + j];			//대문자 소문자 비교를 위해 값을 따로 저장
				compare_char2 = searchword[j];
				if(compare_char1 >= 65 && compare_char1 <= 97)	//대문자인 경우 소문자로 변환
					compare_char1 += 32;
				if(compare_char2 >= 65 && compare_char2 <= 97)
					compare_char2 += 32;
				if(compare_char1 != compare_char2)				//소문자로 변환한 단어를 비교
					check = 1;
			}
			if(check == 0)										//입력 단어를 찾은 경우
			{
				infor1.catch_word[x][0] = paragraph;			//현재 단어가 있는 문단의 위치를 저장
				infor1.catch_word[x][1] = i;					//단어가 일치하는 배열의 위치를 저장
				x++;											//다음 단어를 저장할 위치로 변경
			}
		}

	}
	infor1.find_num = x;										//찾은 단어들의 갯수

	for(i = 0 ; i < x ; i++)									//찾은 문서내 단어의 원래 원형을 파악
	{
		st_word = infor1.catch_word[i][1];						//찾은 원형 단어의 시작 위치를 파악
		while(file_text_data[st_word - 1] >= 65 && file_text_data[st_word - 1] <= 122)
		{
			st_word -= 1;
		}
		infor1.catch_word[i][1] = st_word;

		ed_word = infor1.catch_word[i][1];						//찾은 원형 단어의 끝 위치를 파악
		while(file_text_data[ed_word + 1] >= 65 && file_text_data[ed_word + 1] <= 122)
		{
			ed_word += 1;
		}
		infor1.catch_word[i][2] = ed_word;
	}
	printf("현재 문서에서 %d개의 단어를 검색하였습니다.", infor1.find_num);

	if(infor1.find_num != 0)
	{
		select_num = ui(2,5,5,30,"⑥ Search_Word ","Q) 해당 문서를 통해 찾은 단어를 직접 확인하시겠습니까??\n해당 단어는 앞뒤로 별표가 붙은 상태로 출력됩니다. ",0,2,"① 본다 ","② 안본다 ","");
				
	//백스페이스 입력 초기메뉴로
		if(select_num==-10)
		{
			return ;
		}

	//printf("\n해당 문서를 통해 찾은 단어를 직접 확인하시겠습니까??\n해당 단어는 앞뒤로 별표가 붙은 상태로 출력됩니다.\n1. 본다\t\t2. 안본다.\n");
	//	scanf("%d", &select_num);
		//empty = getc(stdin);

		//찾은 단어 앞뒤로 별표를 붙여서 출력
		x = 0;
		if(select_num == 1)
		{
			for(i = 0 ; i < end_num ; i++)
			{
				if(i == infor1.catch_word[x][1])
					printf("★");
				printf("%c", file_text_data[i]);
				if(i == infor1.catch_word[x][2])
				{
					printf("★");
					x++;
				}
			}
			printf("\n출력을 완료하였습니다.\n\n");
		}

		//단어 수정
		select_num = ui(2,5,5,30,"⑥ Search_Word ","Q) 찾은 단어들을 전부 수정하시겠습니까??\n\n",0,2,"① 수정한다 ","② 안한다 ","");
		//printf("찾은 단어들을 전부 수정하시겠습니까??\n1. 수정한다. 2. 안한다.\n");
	//	scanf("%d", &select_num);
		//empty = getc(stdin);

					
	//백스페이스 입력 초기메뉴로
		if(select_num==-10)
		{
			return ;
		}
		
		if(select_num == 1)
		{
			printf("바꿀 단어를 입력하십시오.\n");
			fflush(stdin);
			gets(change_word);
			//getc(stdin);
			changeWord(file_text_data, num_word, infor1, title_text, change_word);	//단어 수정 함수 호출	
		}
	}
	
	printf("단어 검색이 완료되었습니다.\n");
	fclose(pf);
}



//단어 수정 함수
void changeWord(char file_text_data[], int num_word, InforWord infor1, char title_text[], char change_word[])
{
	int i = 0, j = 0, k = 0;									//for문 돌리기 위한 변수
	int change_numWord = 0;										//바꿀 단어의 길이
	int compare_num;											//기존 단어와 바꿀 단어의 길이의 차
	int st_word = 0, ed_word = 0;										//원래 단어의 시작 위치, 끝위치
	int total_textNum;
	int x = 0;
	int start_num, end_num = 0;
	
	FILE *pf;
	
	char ch_textData[charNum] = {0, };
	//입력한 단어의 아스키코드값, 길이를 계산
	

	change_numWord = strlen(change_word);						//바꿀 단어의 길이를 파악

	compare_num = change_numWord - num_word;					//바꿀 단어와 기존 단어 길이의 차를 구함
	total_textNum = charNum;

	if(compare_num < 0)
	{
		total_textNum = total_textNum + (compare_num * infor1.find_num);
	}
	start_num = 0;
	
	for(i = 0 ; i < infor1.find_num ; i++)						//찾았던 단어 수만큼 반복
	{
		infor1.catch_word[i][1] += (compare_num * i);
		infor1.catch_word[i][2] += (compare_num * (i + 1));
		if(infor1.catch_word[i][1] < charNum)
		{
			st_word = infor1.catch_word[i][1];				//기존 단어의 첫 시작 위치를 기억
			ed_word = infor1.catch_word[i][2];		//기존 단어의 끝 위치를 기억

			for(j = start_num ; j < st_word ; j++)								//char형 배열의 마지막 값은 항상 NULL값이어야 함
				ch_textData[j] = file_text_data[j - (compare_num * i)];	//바뀌게 되는 단어의 다음 위치까지는 새로 저장
			
			for(j = 0 ; j < change_numWord ; j++)
				ch_textData[j + st_word] = change_word[j];
			
			start_num = ed_word + 1;
		}
	}
	end_num = total_textNum;
	
	for(j = start_num ; j < total_textNum ; j++)
	{
		if(file_text_data[j] == 0)
		{
			end_num = j;
			break;
		}	
		ch_textData[j] = file_text_data[j - (compare_num * i)];
	}
	
	if((pf=fopen(title_text, "w+")) == NULL)
	{
		printf("Can't open \n");
	}
	else
	{
		for(i = 0 ; i < end_num ; i++)
			if(ch_textData[i] != 13)
				fprintf(pf, "%c", ch_textData[i]);
	}
	printf("\n수정이 완료되었습니다.\n");
	fclose(pf);
}



void Graph()
{	
	extern Document data[1000]; //문서 정보의 구조체를 가리키는 포인터 배열

	// type_name, type_num 두개의 동일한 인덱스는 동일한 타입에 따른 정보
	char type_name[1000][200];//타입종류
	int type_num[1000]={0};//타입에 맞는 개수 

	char sort_type_name[1000][200];//정렬한 타입종류
	int sort_type_num[1000]={0};//정렬한 타입에 맞는 개수 

	int type_count=0;// 타입종류 개수 
	int max1=-1,max2=-1,max3=-1,max4=-1,max5=-1; //최대값구할때 사용
	int max[5] = {-1,-1,-1,-1,-1};//최대값의 인덱스 저장
	int avg_max=0;//최대값들 평균
	int i,a;//배열 인덱스

	

	if(Document_count != 0)
	{
	Sort_type(1) ;//문서 종류로 정렬

	//첫 문서 종류는 저장하고 루프 들어감 
	type_num[0]=1;
	strcpy(type_name[0],data[0].type);
	//printf("type_name[%d]:%s, type_num[%d]:%d\n",type_count,type_name[type_count],type_count,type_num[type_count]);
				


	for(i=0; i<Document_count-1; i++)//문서 개수 만큼 루프
	{
		//printf("%s\n",data[i].type);

			if(strcmp(data[i].type, data[i+1].type)==0)
			{

				
				type_num[type_count]++;
				//printf("if문\n");
				//printf("type_name[%d]:%s, type_num[%d]:%d\n",type_count,type_name[type_count],type_count,type_num[type_count]);
								
			}//if
			else
			{
				type_count++;//타입개수 증가
				type_num[type_count]++;
				strcpy(type_name[type_count],data[i+1].type );
				//printf("else 문\n");
				//printf("type_name[%d]:%s, type_num[%d]:%d\n",type_count,type_name[type_count],type_count,type_num[type_count]);
				
			
			}//else
		
	
	}//for


	

	Sort_original();// 구조체 순서 원상복귀


	//많은순서대로 5개 찾기
	for( int i=0 ; i<type_count+1 ; i++ ) 
	{
	
		if(type_num[i] >= max1 && i!=max[0]&& i!=max[1] && i!=max[2]&& i!=max[3]  && i!=max[4]   )  
		{	
			max1 = type_num[i];  // max에 저장
			max[0]=i;
			
		}
	}
	for( int i=0 ; i<type_count+1 ; i++ ) 
	{
		if(type_num[i] >= max2  && i!=max[0]&& i!=max[1] && i!=max[2]&& i!=max[3]  && i!=max[4]   )  
		{	
			max2 = type_num[i];  // max에 저장
			max[1]=i;
		}
	}
	for( int i=0 ; i<type_count+1 ; i++ ) 
	{
		if(type_num[i] >= max3   && i!=max[0]&& i!=max[1] && i!=max[2]&& i!=max[3]  && i!=max[4]    )  
		{	
			max3 = type_num[i];  // max에 저장
			max[2]=i;
		}
	}
	for( int i=0 ; i<type_count+1 ; i++ ) 
	{
		if(type_num[i] >= max4 && i!=max[0]&& i!=max[1] && i!=max[2]&& i!=max[3]  && i!=max[4] )
		{	
			max4 = type_num[i];  // max에 저장
			max[3]=i;
		}
	}
	for( int i=0 ; i<type_count+1 ; i++ ) 
	{
		if(type_num[i] >= max5  && i!=max[0]&& i!=max[1] && i!=max[2]&& i!=max[3]  && i!=max[4] )  
		{	
			max5 = type_num[i];  // max에 저장
			max[4]=i;
		}
	}



//최대크기에 따라서 범위 나누기
	if(max1>=0 && max1<=20)//네모 한칸당 문서 개수 1개 의미
	{
		print_graph(2,5,20,30, type_name[max[0]], type_name[max[1]], type_name[max[2]], type_name[max[3]],type_name[max[4]],max1,max2,max3,max4,max5,1);
	}
	
	if(max1>20 && max1<=100)//네모 한칸당 문서 개수 5개 의미
	{
		print_graph(2,5,20,30, type_name[max[0]], type_name[max[1]], type_name[max[2]], type_name[max[3]],type_name[max[4]],max1/5,max2/5,max3/5,max4/5,max5/5,5);
	}

	if(max1>100 && max1<=200)//네모 한칸당 문서 개수 10개 의미
	{
		print_graph(2,5,20,30, type_name[max[0]], type_name[max[1]], type_name[max[2]], type_name[max[3]],type_name[max[4]],max1/10,max2/10,max3/10,max4/10,max5/10,10);
	}

	if(max1>200 && max1<=1000)//네모 한칸당 문서 개수 50개 의미
	{
		print_graph(2,5,20,30, type_name[max[0]], type_name[max[1]], type_name[max[2]], type_name[max[3]],type_name[max[4]],max1/50,max2/50,max3/50,max4/50,max5/50,50);
	}
	

	}//if

	

	else 
		printf("\n\n\n등록된 문서가 없습니다.");
}