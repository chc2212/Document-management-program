#include<stdio.h>
#include <sys/types.h>
#include <io.h>
#include <time.h>
#include<string.h>
#include<stdlib.h>


#include"function.h"
#include "ui.h"
#define charNum 450000

void Registration() //���� ����ϴ� �Լ� 
{
	int choice_num = 0; //���� ��� ��� ���� ��, ���� ��ȣ ���� 
	char empty;
	

	//printf("\n��Registration\n");
	//printf("<��Ϲ�� ����>\n");
	while(choice_num != 1 && choice_num != 2)
	{
		//printf("1.�ϰ����  2.�ϳ����\n");
		//printf("Enter_the_choice_number:");
		choice_num = ui(2,5,5,30,"�� Registration ","Q) ��Ϲ���� �������ּ���. \n\n",0,2,"�� �ϰ���� ","�� �ϳ���� ","");
		//scanf("%d",&choice_num);
		//empty = getc(stdin);

		//�齺���̽� �Է�
		if(choice_num==-10)
		{
			return ;
		}

		if(choice_num==1)
		{
			Registration_All(); // �ϰ� ����ϴ� �Լ�
		}

 		else if(choice_num==2)
 		{
 			Registration_One();// �ϳ� ����ϴ� �Լ� 
 		}
		/*
		else
		{	
			printf("��ȣ�� �߸� �Է��ϼ̽��ϴ�.�ٽ� �Է��� �ֽʽÿ�.\n\n");
		}
		*/
	}

}//Registration


void Registration_All()//���� �ϰ� ����ϴ� �Լ� 
{
	int re_value=0;//FIle�Լ����� �޾ƿ� ���� ��
	re_value=File();//File�Լ����� ���� ���� ��� ������ ���� ������ �о�� 
	 
	if(re_value==0)
	{
	extern Document data[1000];
	
	for(int i = Document_count; i < Document_count + new_Document_count; i++)
	{
		//ui(15,5,5,30,"�� Registration ","\n\n",0,2,"�� �ϰ���� ","�� �ϳ���� ","");
		printf("\n%d��° ������ ���� �Է��� �����ϰڽ��ϴ�.\n", i + 1);
		data[i].num = i+1;
		printf("���� ����:");
		fflush(stdin);
		gets(data[i].type);
	//	getc(stdin);
		printf("���� ����:");
		fflush(stdin);
		gets(data[i].title);
	//	getc(stdin);
		printf("�ۼ���:");
		fflush(stdin);
		gets(data[i].writer);
	//	getc(stdin);
	}

	Document_count += new_Document_count;
	if(new_Document_count != 0)
	{
		printf("\n�� %d���� ���� ����� �Ϸ��Ͽ����ϴ�.\n", new_Document_count);
	}
	else
	{
		printf("���� �ȿ� ������ �����ϴ�.\n");
	}
	printf("\n���� %d���� ������ ��ϵǾ� �ֽ��ϴ�.\n", Document_count);


	}
	

}//Registration_All

void Registration_One()//���� �ϳ� ����ϴ� �Լ�
{
	
	char filename[100];
	char all_file_name[100][100];//�������� ��� txt������ �̸��� ������ �迭
	
	extern Document data[1000]; //���� ������ ����ü�� ����Ű�� ������ �迭

	_finddata_t fd;
	long handle;
	int result=1;
	char empty;

	//printf("\n\n  �ϰ������ �����̸�:");
	printf("\n\n����ϰ��� �ϴ� �����̸�(���ϰ������)�� �Է����ּ���.\n");
	scanf("%s",filename);
	 
	if((handle=_findfirst(filename,&fd)) == -1L)
		printf("������ �����ϴ�.���� �޴��� ���ư��ϴ�.\n\n");
	else
	{
		Document_count++;//���� ���� �߰� 
		data[Document_count - 1].num=Document_count;//���� ��ȣ
		strcpy(data[Document_count - 1].filename,filename);//�����̸� 
		data[Document_count - 1].new_date=fd.time_create;//���� �ۼ���¥
		strcpy(data[Document_count - 1].new_date_string,ctime(&fd.time_create));
		data[Document_count - 1].update_date=fd.time_write;//���� ������¥
		strcpy(data[Document_count - 1].update_date_string,ctime(&fd.time_write));
		data[Document_count - 1].file_size=fd.size;//����ũ��

		//���������� ����ڰ� �Է� 
		empty = getc(stdin);	
		printf("���� ����:");
		fflush(stdin);
		gets(data[Document_count - 1].type);//���� ����
	//	getc(stdin);
		printf("���� ����:");
		fflush(stdin);
		gets(data[Document_count - 1].title);//��������
	//	  getc(stdin);
		printf("���� �ۼ���:");
		fflush(stdin);
		gets(data[Document_count - 1].writer);//���� �ۼ���
	//	getc(stdin);

		//printf("%d\n", Document_count); ���ϰ��� ��� �� ���ִ���?
	}
	_findclose(handle);

}//Registration_One

void Show_All() //��ü ������ ���� ���� ���� �Լ�  
{	
	extern Document data[1000]; //���� ������ ����ü�� ����Ű�� ������ �迭
	int choice_num; //���Ĺ�� ���� ��, ���� ��ȣ ����

	
	/*
	printf("<���Ĺ�� ����>\n");
	printf("1.������Ϲ�ȣ	2.��������	3. ��������  4. �ۼ��� \n");
	printf("5.�����ۼ���¥   6.����������¥  7. ����ũ��\n");
	printf("Enter_the_choice_number:");
	scanf("%d",&choice_num);	
	*/

	choice_num = ui(2,5,5,30,"�� Show_All ","Q) ��Ϲ���� �������ּ���. \n\n",3,7,"","","");
	
	//�齺���̽� �Է� �ڷΰ���
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
	extern Document data[1000]; //���� ������ ����ü�� ����Ű�� ������ �迭
	
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
	extern Document data[1000]; //���� ������ ����ü�� ����Ű�� ������ �迭
	
	qsort((void*)&data,Document_count,sizeof(Document), compare_num );
	
	printf("��Ϲ�ȣ |          ��������          |          ��������          |          �ۼ���          \n");
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
	extern Document data[1000]; //���� ������ ����ü�� ����Ű�� ������ �迭

	qsort((void*)&data,Document_count,sizeof(Document), compare_type );

	for(i=0;i<Document_count - 1;i++)
	{ 
		if(strcmp(data[i].type,data[i + 1].type)==0)//�˻��� �������� ã����
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
		printf("��Ϲ�ȣ |          ��������          |          ��������          |          �ۼ���          \n");
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
	extern Document data[1000]; //���� ������ ����ü�� ����Ű�� ������ �迭

	qsort((void*)&data,Document_count,sizeof(Document), compare_title );

	for(i=0;i<Document_count - 1;i++)
	{ 
		if(strcmp(data[i].title,data[i + 1].title)==0)//�˻��� �������� ã����
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
	printf("��Ϲ�ȣ |          ��������          |          ��������          |          �ۼ���          \n");
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
	extern Document data[1000]; //���� ������ ����ü�� ����Ű�� ������ �迭

	qsort((void*)&data,Document_count,sizeof(Document), compare_writer );

	for(i=0;i<Document_count - 1;i++)
	{ 
		if(strcmp(data[i].writer,data[i + 1].writer)==0)//�˻��� �������� ã����
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
	printf("��Ϲ�ȣ |          ��������          |          ��������          |          �ۼ���          \n");
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
	extern Document data[1000]; //���� ������ ����ü�� ����Ű�� ������ �迭

	//qsort((void*)&data,Document_count,sizeof(data[0].new_date), compare_new_date );
	qsort((void*)&data,Document_count,sizeof(Document), compare_new_date );
	
	for(i=0;i<Document_count - 1;i++)
	{ 
		if(data[i].new_date == data[i + 1].new_date)//�˻��� �������� ã����
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

	printf("��Ϲ�ȣ |          ��������          |          ��������          |          �ۼ���          |          �ۼ���¥          \n");
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
	extern Document data[1000]; //���� ������ ����ü�� ����Ű�� ������ �迭

	//qsort((void*)&data,Document_count,sizeof(data[0].update_date), compare_update_date );
	qsort((void*)&data,Document_count,sizeof(Document), compare_update_date );

	for(i=0;i<Document_count - 1;i++)
	{ 
		if(data[i].update_date == data[i + 1].update_date)//�˻��� �������� ã����
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

	printf("��Ϲ�ȣ |          ��������          |          ��������          |          �ۼ���          |          ������¥          \n");
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
	extern Document data[1000]; //���� ������ ����ü�� ����Ű�� ������ �迭

	//qsort((void*)&data,Document_count,sizeof(data[0].file_size), compare_file_size );
	qsort((void*)&data,Document_count,sizeof(Document), compare_file_size );
	
	for(i=0;i<Document_count - 1;i++)
	{ 
		if(data[i].file_size == data[i + 1].file_size)//�˻��� �������� ã����
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
	printf("��Ϲ�ȣ |          ��������          |          ��������          |          �ۼ���          |          ����ũ��          \n");
	for(int i = 0 ; i < Document_count ; i++)
	{
		Show_File(2, data[i],7);
	}
}




void Show_File(int choice_show, struct Document data,int choice_add)
{
	extern int Document_count;
	//extern Document data[1000];
	

	if(choice_show==1)//�ش� ������ ���� ��� ��ȣ, ����, ����, �ۼ��ڸ� ���
	{
	
		printf("    %d     ",data.num); //��Ϲ�ȣ

		printf("   %s",data.type); //��������
		//*ĭ�����ֱ� ���� �۾� -����-
		int j=0;
		while(data.type[j]!=NULL)
			j++;
		while(j!=30)
		{
			printf(" ");
			j++;
		}	
		//*ĭ�����ֱ� ���� �۾� -��-

		printf("%s",data.title); //��������
		//*ĭ�����ֱ� ���� �۾� -����-
		j=0;
		while(data.title[j]!=NULL)
			j++;
		while(j!=30)
		{
			printf(" ");
			j++;
		}	
		//*ĭ�����ֱ� ���� �۾� -��-

		printf("%s\n",data.writer); //�ۼ���
		//*ĭ�����ֱ� ���� �۾� -����-
		j=0;
		
	}
	else if(choice_show==2)
	{
		
		//�ش� ������ ���� ��� ��ȣ, ����, ����, �ۼ��� +a���
		//*a�� ���� �ۼ� ��¥, ���� ���� ��¥, ���� ũ�� �� �ϳ� 
		//	printf("�ۼ���¥ : %s������¥ : %sũ�� : %d\n", data.new_date, data.update_date, data.file_size);

		if(choice_add == 5) //�ۼ���¥�� ���ϸ�
		{
			//	printf("��Ϲ�ȣ |          ��������          |          ��������          |          �ۼ���          |          �ۼ���¥          \n");
				printf("    %d     ",data.num); //��Ϲ�ȣ

		printf("   %s",data.type); //��������
		//*ĭ�����ֱ� ���� �۾� -����-
		int j=0;
		while(data.type[j]!=NULL)
			j++;
		while(j!=30)
		{
			printf(" ");
			j++;
		}	
		//*ĭ�����ֱ� ���� �۾� -��-

		printf("%s",data.title); //��������
		//*ĭ�����ֱ� ���� �۾� -����-
		j=0;
		while(data.title[j]!=NULL)
			j++;
		while(j!=30)
		{
			printf(" ");
			j++;
		}	
		//*ĭ�����ֱ� ���� �۾� -��-

		printf("%s",data.writer); //�ۼ���
		//*ĭ�����ֱ� ���� �۾� -����-
		j=0;
		while(data.writer[j]!=NULL)
			j++;
		while(j!=30)
		{
			printf(" ");
			j++;
		}	
		//*ĭ�����ֱ� ���� �۾� -��-

		printf("%s",data.new_date_string); //�ۼ���¥
		//*ĭ�����ֱ� ���� �۾� -����-
		
		//*ĭ�����ֱ� ���� �۾� -��-
		}

	//******************************************
			if(choice_add == 6) //������¥�� ���ϸ�
		{
				//printf("��Ϲ�ȣ |          ��������          |          ��������          |          �ۼ���          |          ������¥          \n");
				printf("    %d     ",data.num); //��Ϲ�ȣ

		printf("   %s",data.type); //��������
		//*ĭ�����ֱ� ���� �۾� -����-
		int j=0;
		while(data.type[j]!=NULL)
			j++;
		while(j!=30)
		{
			printf(" ");
			j++;
		}	
		//*ĭ�����ֱ� ���� �۾� -��-

		printf("%s",data.title); //��������
		//*ĭ�����ֱ� ���� �۾� -����-
		j=0;
		while(data.title[j]!=NULL)
			j++;
		while(j!=30)
		{
			printf(" ");
			j++;
		}	
		//*ĭ�����ֱ� ���� �۾� -��-

		printf("%s",data.writer); //�ۼ���
		//*ĭ�����ֱ� ���� �۾� -����-
		j=0;
		while(data.writer[j]!=NULL)
			j++;
		while(j!=30)
		{
			printf(" ");
			j++;
		}	
		//*ĭ�����ֱ� ���� �۾� -��-

		printf("%s",data.update_date_string); //������¥
		//*ĭ�����ֱ� ���� �۾� -����-
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
		//*ĭ�����ֱ� ���� �۾� -��-
		}

		//****************************
				if(choice_add == 7) //����ũ�⸦ ���ϸ�
		{
				//printf("��Ϲ�ȣ |          ��������          |          ��������          |          �ۼ���          |          ����ũ��          \n");
				printf("    %d     ",data.num); //��Ϲ�ȣ

		printf("   %s",data.type); //��������
		//*ĭ�����ֱ� ���� �۾� -����-
		int j=0;
		while(data.type[j]!=NULL)
			j++;
		while(j!=30)
		{
			printf(" ");
			j++;
		}	
		//*ĭ�����ֱ� ���� �۾� -��-

		printf("%s",data.title); //��������
		//*ĭ�����ֱ� ���� �۾� -����-
		j=0;
		while(data.title[j]!=NULL)
			j++;
		while(j!=30)
		{
			printf(" ");
			j++;
		}	
		//*ĭ�����ֱ� ���� �۾� -��-

		printf("%s",data.writer); //�ۼ���
		//*ĭ�����ֱ� ���� �۾� -����-
		j=0;
		while(data.writer[j]!=NULL)
			j++;
		while(j!=30)
		{
			printf(" ");
			j++;
		}	
		//*ĭ�����ֱ� ���� �۾� -��-

		printf("%d\n",data.file_size); //����ũ��
		//*ĭ�����ֱ� ���� �۾� -����-
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
		//*ĭ�����ֱ� ���� �۾� -��-
		}


	}

}



void Search_File() //���� ã�� �Լ�
{
	int choice_num; 
	char temp_arr[30]={0};
	extern Document data[1000]; //���� ������ ����ü�� ����Ű�� ������ �迭
	 
	//printf("<ã���� ����>\n");
	//printf("1.�������� 2. ��������  3. �ۼ��� \n");
	//printf("Enter_the_choice_number:");
	//scanf("%d",&choice_num); 

	choice_num = ui(2,5,5,30,"�� Search File","Q) � ������� ã���� �������ּ���. \n\n",0,3,"�� ���� ������ ã��","�� ���� �������� ã��","�� �ۼ��ڷ� ã��");

	
	//�齺���̽� �Է� �ڷΰ���
		if(choice_num==-10)
		{
			return ;
		}
 
	if(choice_num==1)
	{
		printf("���� ����:");
		scanf("%s",temp_arr); 


		for(int i=0;i<Document_count;i++)
		{
  
			if(strcmp(data[i].type,temp_arr)==0)//�˻��� ���������� ã����
			{
   
				Show_File(1,data[i],0);
			}
 
		}
	}
	else if(choice_num==2)
	{
		printf("���� ����:");
		scanf("%s",temp_arr);

		for(int i=0;i<Document_count;i++)
		{
  
			if(strcmp(data[i].title,temp_arr)==0)//�˻��� �ۼ��ڸ� ã����
			{
   
				Show_File(1,data[i],0);
			}
		}

	}
	else if(choice_num==3)
	{
		printf("�ۼ���:");
		scanf("%s",temp_arr);

		for(int i=0;i<Document_count;i++)
		{
  
			if(strcmp(data[i].writer,temp_arr)==0)//�˻��� �ۼ��ڸ� ã����
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
	extern Document data[1000]; //���� ������ ����ü�� ����Ű�� ������ �迭
	//getc(stdin);
	printf("���� �Է�\n:");
	fflush(stdin);
	gets(temp_arr); 
	//getc(stdin);
	 
	for(int i=0;i<Document_count;i++)
	{ 
		if(strcmp(data[i].title,temp_arr)==0)//�˻��� �������� ã����
		{
			Show_File(1,data[i], 0);
			cnt++;
			current_num = i;
		}
	}
	if(cnt >= 2)//���� ������ �������� ��� 
	{
		printf("������ ���� ������ �ֽ��ϴ�.\n");
	
		while(1)
		{
			printf("��� ��ȣ ����\n:");
			scanf("%d", &temp_num); 
			printf("���� ���� : %s\n", data[temp_num - 1].title);
			if(strcmp(data[temp_num - 1].title,temp_arr) == 0)//������ ��ȣ�� ����� ��ġ�Ҷ�
			{
				Show_File(1,data[temp_num - 1], 0);
				return temp_num - 1;		    
			}
			else
				printf("��Ϲ�ȣ�� �߸� �Է��ϼ̽��ϴ�\n");
		}
	}
	else if(cnt == 0)
	{
		printf("��ϵ� ������ �����ϴ�.\n");
		return -1;
	}
	return current_num;

}

void Delete_File()//���� ���� �����ϴ� �Լ� 
{
	extern Document data[1000]; //���� ������ ����ü�� ����Ű�� ������ �迭

	int choice_num=0;
	struct Document doc;
	int ran;
	ran=Search_Title();

	if(ran != -1)
	{
		doc = data[ran];
		int i=0;


		for(i=doc.num-1;i<Document_count;i++)//i=doc.num-1  �����Ϸ��� ������ ��Ϲ�ȣ����
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
		printf("���������� %s�� ������ ������ �����Ǿ����ϴ�.\n\n",doc.title);
	 
		
		
		choice_num = ui(2,5,5,30,"�� Deletion","Q) ��ü ������ ������ Ȯ���Ͻðڽ��ϱ�? \n\n",0,2,"�� ��","�� �ƴϿ�","");
		
	//�齺���̽� �Է� �ʱ�޴���
		if(choice_num==-10)
		{
			return ;
		}
		/*
		printf("��ü ������ ������ Ȯ���Ͻðڽ��ϱ�?\n");
		printf("1.�� 2.�ƴϿ�\n");
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
	extern Document data[1000]; //���� ������ ����ü�� ����Ű�� ������ �迭
	int choice_num=0;
 
	struct Document doc;
	int ran;
	ran=Search_Title();

	if(ran != -1)
	{
		doc = data[ran];

		choice_num = ui(2,5,5,30,"�� Modification","Q) ������ �׸��� �������ּ���. \n\n",0,3,"�� ��������","�� ��������","�� �ۼ���");
	
	//�齺���̽� �Է� �ʱ�޴���
		if(choice_num==-10)
		{
			return ;
		}
		/*
		printf("<������ �׸� ����>\n");
		printf("1.�������� 2. ��������  3. �ۼ��� \n");
		printf("Enter_the_choice_number:");
		scanf("%d",&choice_num); 
	*/ 
		if(choice_num==1)
		{
			printf("���� ����:");
			scanf("%s",data[doc.num-1].type); 
	  
		}


		else if(choice_num==2)
		{
			printf("���� ����:");
			scanf("%s",data[doc.num-1].title);
	  
		}

		else if(choice_num==3)
		{
			printf("�ۼ���:");
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

//	printf("\n��Search_Word \n");
	while(select_num != 1 && select_num !=2)
	{  

		//printf("��ü ���� �ܾ� �˻��� ���� �� 1��, Ư�� ���� �ܾ� �˻��� ���� �� 2���� ��������\n");
			select_num = ui(2,5,5,30,"�� Search_Word ","Q) �ܾ� �˻������� �������ּ���. \n\n",0,2,"�� ��ü���� �ܾ� �˻� ","�� Ư������ �ܾ� �˻� ","");
				
	//�齺���̽� �Է� �ʱ�޴���
		if(select_num==-10)
		{
			return ;
		}
		//scanf("%d", &select_num);
		//empty = getc(stdin);
		if(select_num != 1 && select_num != 2)
			printf("��ȣ�� �߸� �Է��ϼ̽��ϴ�. �ٽ� �Է��� �ֽʽÿ�.\n");
	}

	if(select_num == 1)
	{
		printf("\nã���� �ϴ� �ܾ �Է��ϼ���.\n�ѱ��� �������� ������ �빮��, �ҹ��ڴ� ��������ϴ�.\n");
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
	int i = 0, j = 0, k = 0;									//for�� ������ ���� ����
	int paragraph = 0;											//������ ������ ��Ÿ���� ����
	int length = 0;												//�� �ܾ��� ���̸� ��Ÿ���� ����
	int para_length = 0;										//���� ���� �ִ� �ܾ���� ��Ÿ���� ����
	int find_length = 0;										//���� ���� �ִ� �ܾ���� ã�� ���� ����
	int x = 0, y = 0;											//word_data�迭 ������ �̵��ϱ� ���� ����
	int count = 0;												//�Է��� �ܾ��� �� �ƽ�Ű�ڵ� ��
	int word_count;												//�˻��� �ܾ��� �� �ƽ�Ű�ڵ� ��
	int num_word = 0;											//�Է��� �ܾ��� ����
	int change_numWord = 0;										//�ٲ� �ܾ��� ����
	int ran_num;												//���Ƿ� ���� ���ڵ�
	int st_word, ed_word;										//���� �ܾ��� ���� ��ġ, ����ġ
	char compare_char1, compare_char2;							//�ܾ���� �빮��, �ҹ��ڸ� ���Ͻ�Ű�� ���� ����ϴ� ����
	bool check;													//�ܾ� �� ��, ��ġ�ϴ��� ���ϴ����� ���ϱ� ���� ����
	bool word_check = 0;										//�ܾ ��ü�������� �ִ��� �������� üũ�ϱ� ���� ����
	char empty;
	int select_num = 0;											//������ ���� ����ϴ� ����
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
			//�Է��� �ܾ��� �ƽ�Ű�ڵ尪, ���̸� ���
			
			for(i = 0 ; i < charNum ; i++)
			{
				if(file_text_data[i] == 0)
				{
					end_num = i;
					break;
				}
				if(file_text_data[i] == 13)	//���� �����ϱ� ���� ù��° ���
				{
					if(file_text_data[i + 2] != 13 && file_text_data[i - 1] != 32)	//���� ���� �� �� ��ġ�� ������ �߰� �κ�����, ���� �κ������� �����ϱ� ���� ���
					{
						paragraph += 1;									//���° ���������� �ľ�
					}
				}
				word_count = 0;											//������ �ƽ�Ű�ڵ带 ���ؾߵǱ� ������ �׻� �ʱ�ȭ
				for(j = i ; j < i + num_word ; j++)						//�� �迭�� ��ġ�������� �ƽ�Ű�ڵ尪�� ���
				{
					ran_num = file_text_data[j];
					if(ran_num >= 65 && ran_num <= 90)
						ran_num += 32;
					word_count += ran_num;
				}

				if(count == word_count)									//�ƽ�Ű �ڵ尪�� ��ġ�ϴ� ���
				{
					check = 0;											//�ܾ� �񱳸� ���� ���� �ʱ�ȭ
					for(j = 0 ; j < num_word ; j++)						//���� �迭�� ��ġ�������� �Է¹��� �ܾ��� ���̸�ŭ
					{
						compare_char1 = file_text_data[i + j];			//�빮�� �ҹ��� �񱳸� ���� ���� ���� ����
						compare_char2 = searchword[j];
						if(compare_char1 >= 65 && compare_char1 <= 97)	//�빮���� ��� �ҹ��ڷ� ��ȯ
							compare_char1 += 32;
						if(compare_char2 >= 65 && compare_char2 <= 97)
							compare_char2 += 32;
						if(compare_char1 != compare_char2)				//�ҹ��ڷ� ��ȯ�� �ܾ ��
							check = 1;
					}
					if(check == 0)										//�Է� �ܾ ã�� ���
					{
						Infors[doc_check].catch_word[x][0] = paragraph;			//���� �ܾ �ִ� ������ ��ġ�� ����
						Infors[doc_check].catch_word[x][1] = i;					//�ܾ ��ġ�ϴ� �迭�� ��ġ�� ����
						x++;											//���� �ܾ ������ ��ġ�� ����
					}
				}

			}
			Infors[doc_check].find_num = x;										//ã�� �ܾ���� ����
			if(x != 0)	word_check = 1;

			for(i = 0 ; i < x ; i++)									//ã�� ������ �ܾ��� ���� ������ �ľ�
			{
				st_word = Infors[doc_check].catch_word[i][1];						//ã�� ���� �ܾ��� ���� ��ġ�� �ľ�
				while(file_text_data[st_word - 1] >= 65 && file_text_data[st_word - 1] <= 122)
				{
					st_word -= 1;
				}
				Infors[doc_check].catch_word[i][1] = st_word;

				ed_word = Infors[doc_check].catch_word[i][1];						//ã�� ���� �ܾ��� �� ��ġ�� �ľ�
				while(file_text_data[ed_word + 1] >= 65 && file_text_data[ed_word + 1] <= 122)
				{
					ed_word += 1;
				}
				Infors[doc_check].catch_word[i][2] = ed_word;
			}
			printf("%d�� �������� %d���� �ܾ �˻��Ͽ����ϴ�.\n", data[doc_check].num, Infors[doc_check].find_num);
		}
	}

	printf("\n�ܾ� �˻��� �Ϸ�Ǿ����ϴ�.\n");

	if(word_check)
	{
		select_num = ui(2,5,5,30,"�� Search_Word ","Q) ������ ������ ���� �ܾ� ��ġ�� Ȯ���Ͻðڽ��ϱ�? \n\n",0,2,"�� �Ѵ� ","�� ���Ѵ� ","");
	
		//printf("������ ������ ���� �ܾ� ��ġ�� Ȯ���Ͻðڽ��ϱ�??\n");
	//	printf("\n1. �Ѵ�.\t2. ���Ѵ�.\n");

	//	scanf("%d", &select_num);

		if(select_num == 1)
		{

			printf("\n  �ܾ� ��ġ�� Ȯ���� ������ ��ȣ�� �Է��ϼ���.\n");
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
						printf("��");
					printf("%c", file_text_data[i]);
					if(i == Infors[select_num - 1].catch_word[x][2])
					{
						printf("��");
						x++;
					}
				}
				printf("\n����� �Ϸ��Ͽ����ϴ�.\n\n");
			}
		}

		//�ܾ� ����

		select_num = ui(2,5,5,30,"�� Search_Word ","Q) ã�� �ܾ���� ���� �����Ͻðڽ��ϱ�?? \n\n",0,2,"�� �����Ѵ� ","�� ���Ѵ� ","");
	
					
	//�齺���̽� �Է� �ʱ�޴���
		if(select_num==-10)
		{
			return ;
		}
	//	printf("ã�� �ܾ���� ���� �����Ͻðڽ��ϱ�??\n1. �����Ѵ�. 2. ���Ѵ�.\n");
	//	scanf("%d", &select_num);
		//empty = getc(stdin);
		
		if(select_num == 1)
		{
			printf("\n  �ٲ� �ܾ �Է��Ͻʽÿ�.\n");
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
						changeWord(file_text_data, num_word, Infors[i], title_text, change_word);	//�ܾ� ���� �Լ� ȣ��	
					}
				}
			}
		}
		
	}
	else
		printf("���� ��ü���� ã�� �ܾ 0�̱� ������ �ܾ���ġȮ�� �� �ܾ���� �۾��� ���� �ʽ��ϴ�.\n");
	fclose(pf);
	free(Infors);
}

void OneSearchWord(char searchword[], char title_text[])		//�˻��� �ܾ�, ���� ���� �̸�
{
	FILE *pf;
	int i = 0, j = 0, k = 0;									//for�� ������ ���� ����
	int paragraph = 0;											//������ ������ ��Ÿ���� ����
	int length = 0;												//�� �ܾ��� ���̸� ��Ÿ���� ����
	int para_length = 0;										//���� ���� �ִ� �ܾ���� ��Ÿ���� ����
	int find_length = 0;										//���� ���� �ִ� �ܾ���� ã�� ���� ����
	int x = 0, y = 0;											//word_data�迭 ������ �̵��ϱ� ���� ����
	InforWord infor1;											//�˻��ܾ� ���� ����ü/
	int count = 0;												//�Է��� �ܾ��� �� �ƽ�Ű�ڵ� ��
	int word_count;												//�˻��� �ܾ��� �� �ƽ�Ű�ڵ� ��
	int num_word = 0;											//�Է��� �ܾ��� ����
	int change_numWord = 0;										//�ٲ� �ܾ��� ����
	int ran_num;												//���Ƿ� ���� ���ڵ�
	int st_word, ed_word;										//���� �ܾ��� ���� ��ġ, ����ġ
	char compare_char1, compare_char2;							//�ܾ���� �빮��, �ҹ��ڸ� ���Ͻ�Ű�� ���� ����ϴ� ����
	bool check;													//�ܾ� �� ��, ��ġ�ϴ��� ���ϴ����� ���ϱ� ���� ����
	char empty;
	int select_num = 0;											//������ ���� ����ϴ� ����
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

	printf("\nã���� �ϴ� �ܾ �Է��ϼ���.\n�ѱ��� �������� ������ �빮��, �ҹ��ڴ� ��������ϴ�.\n");
	scanf("%s", searchword);
	printf("\n");

	char file_text_data[charNum] = {0, };

	fread(file_text_data, sizeof file_text_data, 1, pf);
	
	//�Է��� �ܾ��� �ƽ�Ű�ڵ尪, ���̸� ���
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
		if(file_text_data[i] == 13)	//���� �����ϱ� ���� ù��° ���
		{
			if(file_text_data[i + 2] != 13 && file_text_data[i - 1] != 32)	//���� ���� �� �� ��ġ�� ������ �߰� �κ�����, ���� �κ������� �����ϱ� ���� ���
			{
				paragraph += 1;									//���° ���������� �ľ�
			}
		}
		word_count = 0;											//������ �ƽ�Ű�ڵ带 ���ؾߵǱ� ������ �׻� �ʱ�ȭ
		for(j = i ; j < i + num_word ; j++)						//�� �迭�� ��ġ�������� �ƽ�Ű�ڵ尪�� ���
		{
			ran_num = file_text_data[j];
			if(ran_num >= 65 && ran_num <= 90)
				ran_num += 32;
			word_count += ran_num;
		}

		if(count == word_count)									//�ƽ�Ű �ڵ尪�� ��ġ�ϴ� ���
		{
			check = 0;											//�ܾ� �񱳸� ���� ���� �ʱ�ȭ
			for(j = 0 ; j < num_word ; j++)						//���� �迭�� ��ġ�������� �Է¹��� �ܾ��� ���̸�ŭ
			{
				compare_char1 = file_text_data[i + j];			//�빮�� �ҹ��� �񱳸� ���� ���� ���� ����
				compare_char2 = searchword[j];
				if(compare_char1 >= 65 && compare_char1 <= 97)	//�빮���� ��� �ҹ��ڷ� ��ȯ
					compare_char1 += 32;
				if(compare_char2 >= 65 && compare_char2 <= 97)
					compare_char2 += 32;
				if(compare_char1 != compare_char2)				//�ҹ��ڷ� ��ȯ�� �ܾ ��
					check = 1;
			}
			if(check == 0)										//�Է� �ܾ ã�� ���
			{
				infor1.catch_word[x][0] = paragraph;			//���� �ܾ �ִ� ������ ��ġ�� ����
				infor1.catch_word[x][1] = i;					//�ܾ ��ġ�ϴ� �迭�� ��ġ�� ����
				x++;											//���� �ܾ ������ ��ġ�� ����
			}
		}

	}
	infor1.find_num = x;										//ã�� �ܾ���� ����

	for(i = 0 ; i < x ; i++)									//ã�� ������ �ܾ��� ���� ������ �ľ�
	{
		st_word = infor1.catch_word[i][1];						//ã�� ���� �ܾ��� ���� ��ġ�� �ľ�
		while(file_text_data[st_word - 1] >= 65 && file_text_data[st_word - 1] <= 122)
		{
			st_word -= 1;
		}
		infor1.catch_word[i][1] = st_word;

		ed_word = infor1.catch_word[i][1];						//ã�� ���� �ܾ��� �� ��ġ�� �ľ�
		while(file_text_data[ed_word + 1] >= 65 && file_text_data[ed_word + 1] <= 122)
		{
			ed_word += 1;
		}
		infor1.catch_word[i][2] = ed_word;
	}
	printf("���� �������� %d���� �ܾ �˻��Ͽ����ϴ�.", infor1.find_num);

	if(infor1.find_num != 0)
	{
		select_num = ui(2,5,5,30,"�� Search_Word ","Q) �ش� ������ ���� ã�� �ܾ ���� Ȯ���Ͻðڽ��ϱ�??\n�ش� �ܾ�� �յڷ� ��ǥ�� ���� ���·� ��µ˴ϴ�. ",0,2,"�� ���� ","�� �Ⱥ��� ","");
				
	//�齺���̽� �Է� �ʱ�޴���
		if(select_num==-10)
		{
			return ;
		}

	//printf("\n�ش� ������ ���� ã�� �ܾ ���� Ȯ���Ͻðڽ��ϱ�??\n�ش� �ܾ�� �յڷ� ��ǥ�� ���� ���·� ��µ˴ϴ�.\n1. ����\t\t2. �Ⱥ���.\n");
	//	scanf("%d", &select_num);
		//empty = getc(stdin);

		//ã�� �ܾ� �յڷ� ��ǥ�� �ٿ��� ���
		x = 0;
		if(select_num == 1)
		{
			for(i = 0 ; i < end_num ; i++)
			{
				if(i == infor1.catch_word[x][1])
					printf("��");
				printf("%c", file_text_data[i]);
				if(i == infor1.catch_word[x][2])
				{
					printf("��");
					x++;
				}
			}
			printf("\n����� �Ϸ��Ͽ����ϴ�.\n\n");
		}

		//�ܾ� ����
		select_num = ui(2,5,5,30,"�� Search_Word ","Q) ã�� �ܾ���� ���� �����Ͻðڽ��ϱ�??\n\n",0,2,"�� �����Ѵ� ","�� ���Ѵ� ","");
		//printf("ã�� �ܾ���� ���� �����Ͻðڽ��ϱ�??\n1. �����Ѵ�. 2. ���Ѵ�.\n");
	//	scanf("%d", &select_num);
		//empty = getc(stdin);

					
	//�齺���̽� �Է� �ʱ�޴���
		if(select_num==-10)
		{
			return ;
		}
		
		if(select_num == 1)
		{
			printf("�ٲ� �ܾ �Է��Ͻʽÿ�.\n");
			fflush(stdin);
			gets(change_word);
			//getc(stdin);
			changeWord(file_text_data, num_word, infor1, title_text, change_word);	//�ܾ� ���� �Լ� ȣ��	
		}
	}
	
	printf("�ܾ� �˻��� �Ϸ�Ǿ����ϴ�.\n");
	fclose(pf);
}



//�ܾ� ���� �Լ�
void changeWord(char file_text_data[], int num_word, InforWord infor1, char title_text[], char change_word[])
{
	int i = 0, j = 0, k = 0;									//for�� ������ ���� ����
	int change_numWord = 0;										//�ٲ� �ܾ��� ����
	int compare_num;											//���� �ܾ�� �ٲ� �ܾ��� ������ ��
	int st_word = 0, ed_word = 0;										//���� �ܾ��� ���� ��ġ, ����ġ
	int total_textNum;
	int x = 0;
	int start_num, end_num = 0;
	
	FILE *pf;
	
	char ch_textData[charNum] = {0, };
	//�Է��� �ܾ��� �ƽ�Ű�ڵ尪, ���̸� ���
	

	change_numWord = strlen(change_word);						//�ٲ� �ܾ��� ���̸� �ľ�

	compare_num = change_numWord - num_word;					//�ٲ� �ܾ�� ���� �ܾ� ������ ���� ����
	total_textNum = charNum;

	if(compare_num < 0)
	{
		total_textNum = total_textNum + (compare_num * infor1.find_num);
	}
	start_num = 0;
	
	for(i = 0 ; i < infor1.find_num ; i++)						//ã�Ҵ� �ܾ� ����ŭ �ݺ�
	{
		infor1.catch_word[i][1] += (compare_num * i);
		infor1.catch_word[i][2] += (compare_num * (i + 1));
		if(infor1.catch_word[i][1] < charNum)
		{
			st_word = infor1.catch_word[i][1];				//���� �ܾ��� ù ���� ��ġ�� ���
			ed_word = infor1.catch_word[i][2];		//���� �ܾ��� �� ��ġ�� ���

			for(j = start_num ; j < st_word ; j++)								//char�� �迭�� ������ ���� �׻� NULL���̾�� ��
				ch_textData[j] = file_text_data[j - (compare_num * i)];	//�ٲ�� �Ǵ� �ܾ��� ���� ��ġ������ ���� ����
			
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
	printf("\n������ �Ϸ�Ǿ����ϴ�.\n");
	fclose(pf);
}



void Graph()
{	
	extern Document data[1000]; //���� ������ ����ü�� ����Ű�� ������ �迭

	// type_name, type_num �ΰ��� ������ �ε����� ������ Ÿ�Կ� ���� ����
	char type_name[1000][200];//Ÿ������
	int type_num[1000]={0};//Ÿ�Կ� �´� ���� 

	char sort_type_name[1000][200];//������ Ÿ������
	int sort_type_num[1000]={0};//������ Ÿ�Կ� �´� ���� 

	int type_count=0;// Ÿ������ ���� 
	int max1=-1,max2=-1,max3=-1,max4=-1,max5=-1; //�ִ밪���Ҷ� ���
	int max[5] = {-1,-1,-1,-1,-1};//�ִ밪�� �ε��� ����
	int avg_max=0;//�ִ밪�� ���
	int i,a;//�迭 �ε���

	

	if(Document_count != 0)
	{
	Sort_type(1) ;//���� ������ ����

	//ù ���� ������ �����ϰ� ���� �� 
	type_num[0]=1;
	strcpy(type_name[0],data[0].type);
	//printf("type_name[%d]:%s, type_num[%d]:%d\n",type_count,type_name[type_count],type_count,type_num[type_count]);
				


	for(i=0; i<Document_count-1; i++)//���� ���� ��ŭ ����
	{
		//printf("%s\n",data[i].type);

			if(strcmp(data[i].type, data[i+1].type)==0)
			{

				
				type_num[type_count]++;
				//printf("if��\n");
				//printf("type_name[%d]:%s, type_num[%d]:%d\n",type_count,type_name[type_count],type_count,type_num[type_count]);
								
			}//if
			else
			{
				type_count++;//Ÿ�԰��� ����
				type_num[type_count]++;
				strcpy(type_name[type_count],data[i+1].type );
				//printf("else ��\n");
				//printf("type_name[%d]:%s, type_num[%d]:%d\n",type_count,type_name[type_count],type_count,type_num[type_count]);
				
			
			}//else
		
	
	}//for


	

	Sort_original();// ����ü ���� ���󺹱�


	//����������� 5�� ã��
	for( int i=0 ; i<type_count+1 ; i++ ) 
	{
	
		if(type_num[i] >= max1 && i!=max[0]&& i!=max[1] && i!=max[2]&& i!=max[3]  && i!=max[4]   )  
		{	
			max1 = type_num[i];  // max�� ����
			max[0]=i;
			
		}
	}
	for( int i=0 ; i<type_count+1 ; i++ ) 
	{
		if(type_num[i] >= max2  && i!=max[0]&& i!=max[1] && i!=max[2]&& i!=max[3]  && i!=max[4]   )  
		{	
			max2 = type_num[i];  // max�� ����
			max[1]=i;
		}
	}
	for( int i=0 ; i<type_count+1 ; i++ ) 
	{
		if(type_num[i] >= max3   && i!=max[0]&& i!=max[1] && i!=max[2]&& i!=max[3]  && i!=max[4]    )  
		{	
			max3 = type_num[i];  // max�� ����
			max[2]=i;
		}
	}
	for( int i=0 ; i<type_count+1 ; i++ ) 
	{
		if(type_num[i] >= max4 && i!=max[0]&& i!=max[1] && i!=max[2]&& i!=max[3]  && i!=max[4] )
		{	
			max4 = type_num[i];  // max�� ����
			max[3]=i;
		}
	}
	for( int i=0 ; i<type_count+1 ; i++ ) 
	{
		if(type_num[i] >= max5  && i!=max[0]&& i!=max[1] && i!=max[2]&& i!=max[3]  && i!=max[4] )  
		{	
			max5 = type_num[i];  // max�� ����
			max[4]=i;
		}
	}



//�ִ�ũ�⿡ ���� ���� ������
	if(max1>=0 && max1<=20)//�׸� ��ĭ�� ���� ���� 1�� �ǹ�
	{
		print_graph(2,5,20,30, type_name[max[0]], type_name[max[1]], type_name[max[2]], type_name[max[3]],type_name[max[4]],max1,max2,max3,max4,max5,1);
	}
	
	if(max1>20 && max1<=100)//�׸� ��ĭ�� ���� ���� 5�� �ǹ�
	{
		print_graph(2,5,20,30, type_name[max[0]], type_name[max[1]], type_name[max[2]], type_name[max[3]],type_name[max[4]],max1/5,max2/5,max3/5,max4/5,max5/5,5);
	}

	if(max1>100 && max1<=200)//�׸� ��ĭ�� ���� ���� 10�� �ǹ�
	{
		print_graph(2,5,20,30, type_name[max[0]], type_name[max[1]], type_name[max[2]], type_name[max[3]],type_name[max[4]],max1/10,max2/10,max3/10,max4/10,max5/10,10);
	}

	if(max1>200 && max1<=1000)//�׸� ��ĭ�� ���� ���� 50�� �ǹ�
	{
		print_graph(2,5,20,30, type_name[max[0]], type_name[max[1]], type_name[max[2]], type_name[max[3]],type_name[max[4]],max1/50,max2/50,max3/50,max4/50,max5/50,50);
	}
	

	}//if

	

	else 
		printf("\n\n\n��ϵ� ������ �����ϴ�.");
}