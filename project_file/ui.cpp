#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include "ui.h"


// system("cls"); // ���� ���ֱ�
//wherex(); ���� x��ġ

//�簢�� �ڽ��� ���� ����ϰ� ���ð� �޴� ui�Լ� ����
int ui(int x, int y, int height, int width, char* title, char* message, int type, int menu_num, char* menu_1, char* menu_2, char* menu_3) // �˸�â�� ���� �ҽ��Դϴ�.  //menu_num = �޴����� //type�� 2�̸� �ʱ�޴� type�� 3�̸� �޴���ȣ 8��¥��
{	
	y = wherey() + y ; //���� Ŀ����ġ���� �� ��������

	//���������̻� ��µǸ� ȭ�� Ŭ�����ϰ� ó������ ����
	if(y>8000)
	{
		system("cls"); // ���� ���ֱ�
		y=5;
	}
	char Color = 15;  //����
	char BackColor = 0; //����
	int len=strlen(title);
	int m_x = x+2; // �޼��� ��½� xĿ�� ��ġ
	int m_y = y+1; // �޼��� ��½� yĿ�� ��ġ
	int m_c = 0; // �޼��� ��½� ����ϴ� ����
	int m_line = 0; // �޼����� ���� Ŀ�� ��ġ�� ��Ÿ���� ����
	int key = 0 ; // ��/�ƴϿ� �޴��� ���� ���� Ű�� ���� ����
	int menu = 1 ; //��/�ƴϿ� �޴��� ���� ���� �޴� ���� ����

	if(height <= 1 || height <= 1) // ���̳� �ʺ� 0�̸� ����
		return -1;
	if(width-(len/2) < 3) // Ÿ��Ʋ�� �簢�� �� ���� ũ�⸦ �Ѿ�� ����
		return -2;
	if(width < 8) // ũ�Ⱑ �޴� ��ư���� ������ ����
		return -3;
	if(type == 1 && width < 14) // ��/�ƴϿ� �޴� ���ý� ��/�ƴϿ� ��ư���� ������ ����
		return -3;

	
	//�簢�� ��� ����
	SetColor(Color,BackColor);
	gotoxy(x,y);
	printf("��");
	gotoxy(x+width*2-2,y);
	printf("��");
	gotoxy(x,y+height-1);
	printf("��");
	gotoxy(x+width*2-2,y+height-1);
	printf("��");

	gotoxy(x+2,y);
	for(int i = 0 ; i < width-2 ; i ++) // ���� �簢�� ����
		printf("��");

	gotoxy(x+2,y+height-1);
	for(int i = 0 ; i < width-2 ; i ++) // �Ʒ��� �簢�� ����
		printf("��");

	for(int i = 1 ; i < height-1 ; i ++) // ����, ������ �簢�� ����
	{
		gotoxy(x,y+i);
		printf("��");
		for(int i = 0 ; i < width-2 ; i ++)
		{
			printf("��");
		}
		printf("��");
	}
	//�簢�� �׸��� �Ϸ�

	//Ÿ��Ʋ ���
	gotoxy(x+(width-len/2),y);
	printf("%s",title);
	//Ÿ��Ʋ ��� �Ϸ�
	len = strlen(message);

	//�簢�� �ȿ� �޼��� ��� ����

	gotoxy(m_x,m_y);
	for(m_c = 0; m_c < len ; m_c ++ )
	{
		if(m_line > width*2-5) // ù�� ������
		{
			m_line = 0; // Ŀ���� ó������ �ǵ�����
			m_y++; // ���� �޼��� ��ǥ�� y�� +1
			gotoxy(m_x,m_y); // �ι�°�ٷ� �̵�
			if(m_y == y+height-1) // ���� ������
				break; // ������ ����(�޼��� ��� ����)
		}
		while(message[m_c] == '\n') // ���๮���� ���
		{
			m_c++; // �ǳʶٰ�.
			m_line = 0; // Ŀ���� ó������ �ǵ�����
			m_y++; // ���� �޼��� ��ǥ�� y�� +1
			gotoxy(m_x,m_y); // �ι�°�ٷ� �̵�
			if(m_y == y+height-1) // ���� ������
				break; // ������ ����(�޼��� ��� ����)
		}
		printf("%c",message[m_c]);
		m_line ++;
	}

	switch(type)
	{
		case 0: // ����
		/*
		gotoxy(x+width-8/2,y+height-1);
		printf("a"); // �����ִ� ������ ���۴ϴ�.
		*/
		/*
		gotoxy(x+width-22/2,y+height-1);
		printf("����������������������");
		*/
		gotoxy(x+2,y+height);
		//gotoxy((x+width-22/2)+2,y+height-1);
		SetColor(BackColor,Color);
		printf("%s",menu_1);

		if(menu_num>=2)
		{
		gotoxy(x+2,y+height+1);
		//gotoxy((x+width-22/2)+14,y+height-1);
		SetColor(Color,BackColor);
		printf("%s",menu_2);
		}

		if(menu_num>=3)
		{
		gotoxy(x+2,y+height+2);
		//gotoxy((x+width-22/2)+14,y+height-1);
		SetColor(Color,BackColor);
		printf("%s",menu_3);
		}
		while(1)
		{
			if(_kbhit())
			{
				key=getkey();
				switch(key)
				{
					//case 77: // ������ ����Ű
				case 80: // �Ʒ� ����Ű
					if(menu < menu_num)
					{
						SetColor(Color,BackColor);
						switch(menu)
						{
						case 1:
							//gotoxy((x+width-22/2)+2,y+height-1);
							gotoxy(x+2,y+height);
							printf("%s", menu_1);
							break;
						case 2:
							//	gotoxy((x+width-22/2)+14,y+height-1);
							gotoxy(x+2,y+height+1);
							printf("%s", menu_2);
							break;
						case 3:
							//	gotoxy((x+width-22/2)+14,y+height-1);
							gotoxy(x+2,y+height+2);
							printf("%s", menu_3);
							break;
						}
						menu ++;

						SetColor(BackColor,Color);
						switch(menu)
						{
						case 1:
							gotoxy(x+2,y+height);
							printf("%s", menu_1);
							break;
						case 2:
							gotoxy(x+2,y+height+1);
							printf("%s", menu_2);
							break;
						case 3:
							//	gotoxy((x+width-22/2)+14,y+height-1);
							gotoxy(x+2,y+height+2);
							printf("%s", menu_3);
							break;
						}
					}
					break;

					//	case 75: // ���� ����Ű
				case 72: // ���� ����Ű
					if(menu > 1)
					{
						SetColor(Color,BackColor);
						switch(menu)
						{
						case 1:
							gotoxy(x+2,y+height);
							printf("%s", menu_1);
							break;
						case 2:
							gotoxy(x+2,y+height+1);
							printf("%s", menu_2);
							break;
						case 3:
							//	gotoxy((x+width-22/2)+14,y+height-1);
							gotoxy(x+2,y+height+2);
							printf("%s", menu_3);
							break;
						}
						menu --;

						SetColor(BackColor,Color);
						switch(menu)
						{
						case 1:
							gotoxy(x+2,y+height);
							printf("%s", menu_1);
							break;
						case 2:
							gotoxy(x+2,y+height+1);
							printf("%s", menu_2);
							break;
						case 3:
							//	gotoxy((x+width-22/2)+14,y+height-1);
							gotoxy(x+2,y+height+2);
							printf("%s", menu_3);
							break;
						}
					}
					break;
					
					//�齺���̽� �ڷΰ���
					case VK_BACK:
					gotoxy(x+2,y+height+3);
					SetColor(Color,BackColor);
					return -10;
						break;
				//case 32: // �����̽���
				//	return menu;
				//	break;
				case 13: // ����
					gotoxy(x+2,y+height+3);
					SetColor(Color,BackColor);
					return menu;
					break;
				}
			}
		}
		_getch();
		break;
		
	case 1: // �Է�
		/*
		gotoxy(x+width-8/2,y+height-1);
		printf("a"); // �����ִ� ������ ���۴ϴ�.
		*/
		/*
		gotoxy(x+width-22/2,y+height-1);
		printf("����������������������");
		*/
		gotoxy(x+2,y+height);
		//gotoxy((x+width-22/2)+2,y+height-1);
		SetColor(BackColor,Color);
		printf("1. ��  ");

		gotoxy(x+2,y+height+1);
		//gotoxy((x+width-22/2)+14,y+height-1);
		SetColor(Color,BackColor);
		printf("2.�ƴϿ�.");



		while(1)
		{
			if(_kbhit())
			{
				key=getkey();
				switch(key)
				{
				case 77: // ������ ����Ű
					if(menu < 1)
					{
						SetColor(Color,BackColor);
						switch(menu)
						{
						case 0:
							//gotoxy((x+width-22/2)+2,y+height-1);
							gotoxy(x+2,y+height);
							printf("�ƴϿ�");
							break;
						case 1:

							//	gotoxy((x+width-22/2)+14,y+height-1);
							gotoxy(x+2,y+height+1);
							printf("������");
							break;
						}
						menu ++;

						SetColor(BackColor,Color);
						switch(menu)
						{
						case 0:
							gotoxy(x+2,y+height);
							printf("�ƴϿ�");
							break;
						case 1:

							gotoxy(x+2,y+height+1);
							printf("������");
							break;
						}
					}
					break;

				case 75: // ���� ����Ű
					if(menu > 0)
					{
						SetColor(Color,BackColor);
						switch(menu)
						{
						case 0:
							gotoxy((x+width-22/2)+2,y+height-1);
							printf("�ƴϿ�");
							break;
						case 1:

							gotoxy((x+width-22/2)+14,y+height-1);
							printf("������");
							break;
						}
						menu --;

						SetColor(BackColor,Color);
						switch(menu)
						{
						case 0:
							gotoxy((x+width-22/2)+2,y+height-1);
							printf("�ƴϿ�");
							break;
						case 1:
							gotoxy((x+width-22/2)+14,y+height-1);
							printf("������");
							break;
						}
					}
					break;

				case 32: // �����̽���
					return menu;
					break;
				case 13: // ����

					return menu;
					break;
				}
			}
		}
		_getch();
		break;
		

	case 2: //�ʱ�޴� 

		/******Ű�̺�Ʈ ������ �� ó�� ������ ȭ�� ����******/

		gotoxy(x+2,y+height);
		SetColor(BackColor,Color);
		printf("�� Registration ");

		gotoxy(x+2,y+height+1);
		SetColor(Color,BackColor);
		printf("�� ShowAll ");

		gotoxy(x+2,y+height+2);
		SetColor(Color,BackColor);
		printf("�� Search_File ");

		gotoxy(x+2,y+height+3);
		SetColor(Color,BackColor);
		printf("�� Deletion ");

		gotoxy(x+2,y+height+4);
		SetColor(Color,BackColor);
		printf("�� Modification ");

		gotoxy(x+2,y+height+5);
		SetColor(Color,BackColor);
		printf("�� Search_Word ");


		gotoxy(x+2,y+height+6);
		SetColor(Color,BackColor);
		printf("�� Graph ");

		gotoxy(x+2,y+height+7);
		SetColor(Color,BackColor);
		printf("�� Exit  ");

		/******Ű�̺�Ʈ ������ �� ó�� ������ ȭ�� ��******/
		while(1)
		{
			if(_kbhit())
			{
				key=getkey();
				switch(key)
				{
					//case 77: // ������ ����Ű
				case 80: // �Ʒ� ����Ű
				if(menu < menu_num)
					{
						SetColor(Color,BackColor);
						switch(menu)
						{
						case 1:
							gotoxy(x+2,y+height);
							printf("�� Registration ");
							break;
						case 2:
							gotoxy(x+2,y+height+1);
							printf("�� ShowAll ");
							break;
						case 3:
							gotoxy(x+2,y+height+2);
							printf("�� Search_File ");
							break;
						case 4:
							gotoxy(x+2,y+height+3);
							printf("�� Deletion ");
							break;
						case 5:
							gotoxy(x+2,y+height+4);
							printf("�� Modification ");
							break;
						case 6:
							gotoxy(x+2,y+height+5);
							printf("�� Search_Word ");
							break;
						case 7:

							gotoxy(x+2,y+height+6);
							printf("�� Graph ");
							break;

						case 8:

							gotoxy(x+2,y+height+7);
							printf("�� Exit ");
							break;
						}
						menu ++;

						SetColor(BackColor,Color);
						switch(menu)
						{
								case 1:
							gotoxy(x+2,y+height);
							printf("�� Registration ");
							break;
						case 2:
							gotoxy(x+2,y+height+1);
							printf("�� ShowAll ");
							break;
						case 3:
							gotoxy(x+2,y+height+2);
							printf("�� Search_File ");
							break;
						case 4:
							gotoxy(x+2,y+height+3);
							printf("�� Deletion ");
							break;
						case 5:
							gotoxy(x+2,y+height+4);
							printf("�� Modification ");
							break;
						case 6:
							gotoxy(x+2,y+height+5);
							printf("�� Search_Word ");
							break;
						case 7:

							gotoxy(x+2,y+height+6);
							printf("�� Graph ");
							break;

						case 8:

							gotoxy(x+2,y+height+7);
							printf("�� Exit ");
							break;
						}
					}
					break;

					//	case 75: // ���� ����Ű
				case 72: // ���� ����Ű
					if(menu > 1)
					{
						SetColor(Color,BackColor);
						switch(menu)
						{
								case 1:
							gotoxy(x+2,y+height);
							printf("�� Registration ");
							break;
						case 2:
							gotoxy(x+2,y+height+1);
							printf("�� ShowAll ");
							break;
						case 3:
							gotoxy(x+2,y+height+2);
							printf("�� Search_File ");
							break;
						case 4:
							gotoxy(x+2,y+height+3);
							printf("�� Deletion ");
							break;
						case 5:
							gotoxy(x+2,y+height+4);
							printf("�� Modification ");
							break;
						case 6:
							gotoxy(x+2,y+height+5);
							printf("�� Search_Word ");
							break;
						case 7:

							gotoxy(x+2,y+height+6);
							printf("�� Graph ");
							break;

						case 8:

							gotoxy(x+2,y+height+7);
							printf("�� Exit ");
							break;
						}
						menu --;

						SetColor(BackColor,Color);
						switch(menu)
						{
						case 1:
							gotoxy(x+2,y+height);
							printf("�� Registration ");
							break;
						case 2:
							gotoxy(x+2,y+height+1);
							printf("�� ShowAll ");
							break;
						case 3:
							gotoxy(x+2,y+height+2);
							printf("�� Search_File ");
							break;
						case 4:
							gotoxy(x+2,y+height+3);
							printf("�� Deletion ");
							break;
						case 5:
							gotoxy(x+2,y+height+4);
							printf("�� Modification ");
							break;
						case 6:
							gotoxy(x+2,y+height+5);
							printf("�� Search_Word ");
							break;
						case 7:

							gotoxy(x+2,y+height+6);
							printf("�� Graph ");
							break;

						case 8:

							gotoxy(x+2,y+height+7);
							printf("�� Exit ");
							break;
						}
					}
					break;

					//�齺���̽� �ڷΰ���
					case VK_BACK:
						gotoxy(x+2,y+height+7);
					SetColor(Color,BackColor);
					return -10;
						break;
				///case 32: // �����̽���
			//		return menu;
			//		break;
				case 13: // ����
					gotoxy(x+2,y+height+7);
					//getc(stdin);
					SetColor(Color,BackColor);
					return menu;
					break;
				}
			}
		}
		_getch();
		break;
	
		case 3: //Show_all �޴�  

		/******Ű�̺�Ʈ ������ �� ó�� ������ ȭ�� ����******/

		gotoxy(x+2,y+height);
		SetColor(BackColor,Color);
		printf("�� ������Ϲ�ȣ ���� ");


		gotoxy(x+2,y+height+1);
		SetColor(Color,BackColor);
		printf("�� �������� ���� ");

		gotoxy(x+2,y+height+2);
		SetColor(Color,BackColor);
		printf("�� �������� ���� ");

		gotoxy(x+2,y+height+3);
		SetColor(Color,BackColor);
		printf("�� �ۼ��� ���� ");

		gotoxy(x+2,y+height+4);
		SetColor(Color,BackColor);
		printf("�� �����ۼ���¥ ���� ");

		gotoxy(x+2,y+height+5);
		SetColor(Color,BackColor);
		printf("�� ����������¥ ���� ");


		gotoxy(x+2,y+height+6);
		SetColor(Color,BackColor);
		printf("�� ����ũ�� ���� ");

		/******Ű�̺�Ʈ ������ �� ó�� ������ ȭ�� ��******/
		while(1)
		{
			if(_kbhit())
			{
				key=getkey();
				switch(key)
				{
					//case 77: // ������ ����Ű
				case 80: // �Ʒ� ����Ű
					if(menu < menu_num)
					{
						SetColor(Color,BackColor);
						switch(menu)
						{
						case 1:
							gotoxy(x+2,y+height);
							printf("�� ������Ϲ�ȣ ���� ");
							break;
						case 2:
							gotoxy(x+2,y+height+1);
							printf("�� �������� ���� ");
							break;
						case 3:
							gotoxy(x+2,y+height+2);
							printf("�� �������� ���� ");
							break;
						case 4:
							gotoxy(x+2,y+height+3);
							printf("�� �ۼ��� ���� ");
							break;
						case 5:
							gotoxy(x+2,y+height+4);
							printf("�� �����ۼ���¥ ���� ");
							break;
						case 6:
							gotoxy(x+2,y+height+5);
							printf("�� ����������¥ ���� ");
							break;
						case 7:
							gotoxy(x+2,y+height+6);
							printf("�� ����ũ�� ���� ");
							break;
						}
						menu ++;

						SetColor(BackColor,Color);
						switch(menu)
						{
							case 1:
							gotoxy(x+2,y+height);
							printf("�� ������Ϲ�ȣ ���� ");
							break;
						case 2:
							gotoxy(x+2,y+height+1);
							printf("�� �������� ���� ");
							break;
						case 3:
							gotoxy(x+2,y+height+2);
							printf("�� �������� ���� ");
							break;
						case 4:
							gotoxy(x+2,y+height+3);
							printf("�� �ۼ��� ���� ");
							break;
						case 5:
							gotoxy(x+2,y+height+4);
							printf("�� �����ۼ���¥ ���� ");
							break;
						case 6:
							gotoxy(x+2,y+height+5);
							printf("�� ����������¥ ���� ");
							break;
						case 7:
							gotoxy(x+2,y+height+6);
							printf("�� ����ũ�� ���� ");
							break;
						}
					}
					break;

					//	case 75: // ���� ����Ű
				case 72: // ���� ����Ű
					if(menu > 1)
					{
						SetColor(Color,BackColor);
						switch(menu)
						{
							case 1:
							gotoxy(x+2,y+height);
							printf("�� ������Ϲ�ȣ ���� ");
							break;
						case 2:
							gotoxy(x+2,y+height+1);
							printf("�� �������� ���� ");
							break;
						case 3:
							gotoxy(x+2,y+height+2);
							printf("�� �������� ���� ");
							break;
						case 4:
							gotoxy(x+2,y+height+3);
							printf("�� �ۼ��� ���� ");
							break;
						case 5:
							gotoxy(x+2,y+height+4);
							printf("�� �����ۼ���¥ ���� ");
							break;
						case 6:
							gotoxy(x+2,y+height+5);
							printf("�� ����������¥ ���� ");
							break;
						case 7:
							gotoxy(x+2,y+height+6);
							printf("�� ����ũ�� ���� ");
							break;
						}
						menu --;

						SetColor(BackColor,Color);
						switch(menu)
						{
							case 1:
							gotoxy(x+2,y+height);
							printf("�� ������Ϲ�ȣ ���� ");
							break;
						case 2:
							gotoxy(x+2,y+height+1);
							printf("�� �������� ���� ");
							break;
						case 3:
							gotoxy(x+2,y+height+2);
							printf("�� �������� ���� ");
							break;
						case 4:
							gotoxy(x+2,y+height+3);
							printf("�� �ۼ��� ���� ");
							break;
						case 5:
							gotoxy(x+2,y+height+4);
							printf("�� �����ۼ���¥ ���� ");
							break;
						case 6:
							gotoxy(x+2,y+height+5);
							printf("�� ����������¥ ���� ");
							break;
						case 7:
							gotoxy(x+2,y+height+6);
							printf("�� ����ũ�� ���� ");
							break;
						}
					}
					break;

					//�齺���̽� �ڷΰ���
					case VK_BACK:
					gotoxy(x+2,y+height+8);
					SetColor(Color,BackColor);
					return -10;
						break;
				///case 32: // �����̽���
			//		return menu;
			//		break;
				case 13: // ����
					gotoxy(x+2,y+height+8);
					SetColor(Color,BackColor);
					return menu;
					break;
				}
			}
		}
		_getch();
		break;

	

	default :
		return -4;
		break;
	}
	return -5;
} 

int getkey(){
	int ch = _getch();
	if(ch==0xE0 || ch ==0) {
		ch = _getch();
	}
	return ch;
}

void SetColor(color colFront, color colBack)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),((colBack << 4) | colFront));
}

void gotoxy(int x, int y)
{
	COORD Pos = { x-1, y-1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

//���� x Ŀ����ġ
int wherex(void)
 {
     CONSOLE_SCREEN_BUFFER_INFO csb;
 
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csb);
     return (csb.dwCursorPosition.X);
 }


//���� y Ŀ����ġ
 int wherey(void)
 {
     CONSOLE_SCREEN_BUFFER_INFO csb;
 
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csb);
     return (csb.dwCursorPosition.Y);
 }



 void print_graph(int x, int y, int height, int width, char* x_data_1,char* x_data_2,char* x_data_3,char* x_data_4,char* x_data_5,int rate1,int rate2,int rate3,int rate4,int rate5,int div_num) 
 {
	 y = wherey() + y ; //���� Ŀ����ġ���� �� ��������


	char Color = 15;  //����
	char BackColor = 0; //����
	int len=0;
	int x_line = 0; // x��ǥ�� ���� Ŀ�� ��ġ�� ��Ÿ���� ����

	int x1_x = x+2; // x1��ǥ ��½� xĿ�� ��ġ
	int x1_y = y+20; // x1��ǥ ��½� yĿ�� ��ġ
	int x1_c = 0; // x1��ǥ ��½� ����ϴ� ����
	
	int x2_x = x+14; // x2��ǥ ��½� xĿ�� ��ġ
	int x2_y = y+20; // x2��ǥ ��½� yĿ�� ��ġ
	int x2_c = 0; // x2��ǥ ��½� ����ϴ� ����

	int x3_x = x+26; // x3��ǥ ��½� xĿ�� ��ġ
	int x3_y = y+20; // x3��ǥ ��½� yĿ�� ��ġ
	int x3_c = 0; // x3��ǥ ��½� ����ϴ� ����

	int x4_x = x+38; // x4��ǥ ��½� xĿ�� ��ġ
	int x4_y = y+20; // x4��ǥ ��½� yĿ�� ��ġ
	int x4_c = 0; // x4��ǥ ��½� ����ϴ� ����

	int x5_x = x+50; // x5��ǥ ��½� xĿ�� ��ġ
	int x5_y = y+20; // x5��ǥ ��½� yĿ�� ��ġ
	int x5_c = 0; // x5��ǥ ��½� ����ϴ� ����

	int ps_x = 40; // ������ ��½� xĿ�� ��ġ 
	int ps_y = y+21; // ������ ��½� yĿ�� ��ġ
	int div=div_num;//������ �� 
	char ps_c[] = "* ��ĭ�� ���� ����:"; // ������ ��½� ����ϴ� ����
	
	//���񾲱�
	SetColor(14,0);
	gotoxy(ps_x-15,ps_y-22);
	printf("<���� ������ Top 5>");
	SetColor(15,0);

	//�׷��� �� �׸���
	SetColor(Color,BackColor);
	
	gotoxy(x,y+height-1);
	printf("��");
	
	gotoxy(x+2,y+height-1);
	for(int i = 0 ; i < width-2 ; i ++) // x��
		printf("��");

	for(int i = 1 ; i < height-1 ; i ++) //y��
	{
		gotoxy(x,y+i);
		printf("��");
		
	}


	//����׷��� �׸���
	
	for(int i = 1 ; i <= rate1 ; i ++) 
	{
		gotoxy(x+6,y+height-i-1);
		printf("��");
				
	}

	for(int i = 1 ; i <= rate2 ; i ++) 
	{
		gotoxy(x+16,y+height-i-1);
		printf("��");
					
	}
	for(int i = 1 ; i <= rate3 ; i ++) 
	{
		gotoxy(x+28,y+height-i-1);
		printf("��");
				
	}
	for(int i = 1 ; i <= rate4 ; i ++) 
	{
		gotoxy(x+40,y+height-i-1);
		printf("��");
					
	}
	for(int i = 1 ; i <= rate5 ; i ++) 
	{
		gotoxy(x+52,y+height-i-1);
		printf("��");
		
	}


	
	//x�� �� ��� ����

	len = strlen(x_data_1);

	gotoxy(x1_x,x1_y);
	for(x1_c = 0; x1_c < len ; x1_c ++ )
	{
		
		printf("%c",x_data_1[x1_c]);
		
	}


	len = strlen(x_data_2);

	gotoxy(x2_x,x2_y);
	for(x2_c = 0; x2_c < len ; x2_c ++ )
	{
		
		printf("%c",x_data_2[x2_c]);
		
	}
 
	len = strlen(x_data_3);

	gotoxy(x3_x,x3_y);
	for(x3_c = 0; x3_c < len ; x3_c ++ )
	{
		
		printf("%c",x_data_3[x3_c]);
		
	}

	len = strlen(x_data_4);

	gotoxy(x4_x,x4_y);
	for(x4_c = 0; x4_c < len ; x4_c ++ )
	{
		
		printf("%c",x_data_4[x4_c]);
		
	}

	len = strlen(x_data_5);

	gotoxy(x5_x,x5_y);
	for(x5_c = 0; x5_c < len ; x5_c ++ )
	{
		
		printf("%c",x_data_5[x5_c]);
		
	}

	len = strlen(ps_c);

	gotoxy(ps_x,ps_y+1);
	SetColor(14,0);
	
	for(int i = 0; i < len ; i ++ )
	{
		
		printf("%c",ps_c[i]);
		
	}
	printf("%d",div);
		SetColor(15,0);




 }