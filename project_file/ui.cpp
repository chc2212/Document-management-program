#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include "ui.h"


// system("cls"); // 흔적 없애기
//wherex(); 현재 x위치

//사각형 박스와 질문 출력하고 선택값 받는 ui함수 시작
int ui(int x, int y, int height, int width, char* title, char* message, int type, int menu_num, char* menu_1, char* menu_2, char* menu_3) // 알림창을 띄우는 소스입니다.  //menu_num = 메뉴개수 //type가 2이면 초기메뉴 type가 3이면 메뉴번호 8개짜리
{	
	y = wherey() + y ; //현재 커서위치에서 더 내려간다

	//일정영역이상 출력되면 화면 클리어하고 처음부터 시작
	if(y>8000)
	{
		system("cls"); // 흔적 없애기
		y=5;
	}
	char Color = 15;  //색깔
	char BackColor = 0; //색깔
	int len=strlen(title);
	int m_x = x+2; // 메세지 출력시 x커서 위치
	int m_y = y+1; // 메세지 출력시 y커서 위치
	int m_c = 0; // 메세지 출력시 출력하는 글자
	int m_line = 0; // 메세지의 현재 커서 위치를 나타내는 변수
	int key = 0 ; // 예/아니요 메뉴일 시의 누른 키값 저장 변수
	int menu = 1 ; //예/아니오 메뉴일 시의 선택 메뉴 저장 변수

	if(height <= 1 || height <= 1) // 높이나 너비가 0이면 종료
		return -1;
	if(width-(len/2) < 3) // 타이틀이 사각형 윗 변의 크기를 넘어서면 종료
		return -2;
	if(width < 8) // 크기가 메뉴 버튼보다 작으면 종료
		return -3;
	if(type == 1 && width < 14) // 예/아니오 메뉴 선택시 예/아니오 버튼보다 작으면 종료
		return -3;

	
	//사각형 출력 시작
	SetColor(Color,BackColor);
	gotoxy(x,y);
	printf("┌");
	gotoxy(x+width*2-2,y);
	printf("┐");
	gotoxy(x,y+height-1);
	printf("└");
	gotoxy(x+width*2-2,y+height-1);
	printf("┘");

	gotoxy(x+2,y);
	for(int i = 0 ; i < width-2 ; i ++) // 위쪽 사각형 라인
		printf("─");

	gotoxy(x+2,y+height-1);
	for(int i = 0 ; i < width-2 ; i ++) // 아래쪽 사각형 라인
		printf("─");

	for(int i = 1 ; i < height-1 ; i ++) // 왼쪽, 오른쪽 사각형 라인
	{
		gotoxy(x,y+i);
		printf("│");
		for(int i = 0 ; i < width-2 ; i ++)
		{
			printf("　");
		}
		printf("│");
	}
	//사각형 그리기 완료

	//타이틀 출력
	gotoxy(x+(width-len/2),y);
	printf("%s",title);
	//타이틀 출력 완료
	len = strlen(message);

	//사각형 안에 메세지 출력 시작

	gotoxy(m_x,m_y);
	for(m_c = 0; m_c < len ; m_c ++ )
	{
		if(m_line > width*2-5) // 첫줄 꽉차면
		{
			m_line = 0; // 커서를 처음으로 되돌리고
			m_y++; // 실제 메세지 좌표의 y에 +1
			gotoxy(m_x,m_y); // 두번째줄로 이동
			if(m_y == y+height-1) // 전부 꽉차면
				break; // 루프문 중지(메세지 출력 중지)
		}
		while(message[m_c] == '\n') // 개행문자일 경우
		{
			m_c++; // 건너뛰고.
			m_line = 0; // 커서를 처음으로 되돌리고
			m_y++; // 실제 메세지 좌표의 y에 +1
			gotoxy(m_x,m_y); // 두번째줄로 이동
			if(m_y == y+height-1) // 전부 꽉차면
				break; // 루프문 중지(메세지 출력 중지)
		}
		printf("%c",message[m_c]);
		m_line ++;
	}

	switch(type)
	{
		case 0: // 선택
		/*
		gotoxy(x+width-8/2,y+height-1);
		printf("a"); // 남아있는 쓰래기 없앱니다.
		*/
		/*
		gotoxy(x+width-22/2,y+height-1);
		printf("【　　　】─【　　　】");
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
					//case 77: // 오른쪽 방향키
				case 80: // 아래 방향키
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

					//	case 75: // 왼쪽 방향키
				case 72: // 위쪽 방향키
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
					
					//백스페이스 뒤로가기
					case VK_BACK:
					gotoxy(x+2,y+height+3);
					SetColor(Color,BackColor);
					return -10;
						break;
				//case 32: // 스페이스바
				//	return menu;
				//	break;
				case 13: // 엔터
					gotoxy(x+2,y+height+3);
					SetColor(Color,BackColor);
					return menu;
					break;
				}
			}
		}
		_getch();
		break;
		
	case 1: // 입력
		/*
		gotoxy(x+width-8/2,y+height-1);
		printf("a"); // 남아있는 쓰래기 없앱니다.
		*/
		/*
		gotoxy(x+width-22/2,y+height-1);
		printf("【　　　】─【　　　】");
		*/
		gotoxy(x+2,y+height);
		//gotoxy((x+width-22/2)+2,y+height-1);
		SetColor(BackColor,Color);
		printf("1. 예  ");

		gotoxy(x+2,y+height+1);
		//gotoxy((x+width-22/2)+14,y+height-1);
		SetColor(Color,BackColor);
		printf("2.아니오.");



		while(1)
		{
			if(_kbhit())
			{
				key=getkey();
				switch(key)
				{
				case 77: // 오른쪽 방향키
					if(menu < 1)
					{
						SetColor(Color,BackColor);
						switch(menu)
						{
						case 0:
							//gotoxy((x+width-22/2)+2,y+height-1);
							gotoxy(x+2,y+height);
							printf("아니오");
							break;
						case 1:

							//	gotoxy((x+width-22/2)+14,y+height-1);
							gotoxy(x+2,y+height+1);
							printf("　예　");
							break;
						}
						menu ++;

						SetColor(BackColor,Color);
						switch(menu)
						{
						case 0:
							gotoxy(x+2,y+height);
							printf("아니오");
							break;
						case 1:

							gotoxy(x+2,y+height+1);
							printf("　예　");
							break;
						}
					}
					break;

				case 75: // 왼쪽 방향키
					if(menu > 0)
					{
						SetColor(Color,BackColor);
						switch(menu)
						{
						case 0:
							gotoxy((x+width-22/2)+2,y+height-1);
							printf("아니오");
							break;
						case 1:

							gotoxy((x+width-22/2)+14,y+height-1);
							printf("　예　");
							break;
						}
						menu --;

						SetColor(BackColor,Color);
						switch(menu)
						{
						case 0:
							gotoxy((x+width-22/2)+2,y+height-1);
							printf("아니오");
							break;
						case 1:
							gotoxy((x+width-22/2)+14,y+height-1);
							printf("　예　");
							break;
						}
					}
					break;

				case 32: // 스페이스바
					return menu;
					break;
				case 13: // 엔터

					return menu;
					break;
				}
			}
		}
		_getch();
		break;
		

	case 2: //초기메뉴 

		/******키이벤트 없을시 맨 처음 나오는 화면 시작******/

		gotoxy(x+2,y+height);
		SetColor(BackColor,Color);
		printf("① Registration ");

		gotoxy(x+2,y+height+1);
		SetColor(Color,BackColor);
		printf("② ShowAll ");

		gotoxy(x+2,y+height+2);
		SetColor(Color,BackColor);
		printf("③ Search_File ");

		gotoxy(x+2,y+height+3);
		SetColor(Color,BackColor);
		printf("④ Deletion ");

		gotoxy(x+2,y+height+4);
		SetColor(Color,BackColor);
		printf("⑤ Modification ");

		gotoxy(x+2,y+height+5);
		SetColor(Color,BackColor);
		printf("⑥ Search_Word ");


		gotoxy(x+2,y+height+6);
		SetColor(Color,BackColor);
		printf("⑦ Graph ");

		gotoxy(x+2,y+height+7);
		SetColor(Color,BackColor);
		printf("⑧ Exit  ");

		/******키이벤트 없을시 맨 처음 나오는 화면 끝******/
		while(1)
		{
			if(_kbhit())
			{
				key=getkey();
				switch(key)
				{
					//case 77: // 오른쪽 방향키
				case 80: // 아래 방향키
				if(menu < menu_num)
					{
						SetColor(Color,BackColor);
						switch(menu)
						{
						case 1:
							gotoxy(x+2,y+height);
							printf("① Registration ");
							break;
						case 2:
							gotoxy(x+2,y+height+1);
							printf("② ShowAll ");
							break;
						case 3:
							gotoxy(x+2,y+height+2);
							printf("③ Search_File ");
							break;
						case 4:
							gotoxy(x+2,y+height+3);
							printf("④ Deletion ");
							break;
						case 5:
							gotoxy(x+2,y+height+4);
							printf("⑤ Modification ");
							break;
						case 6:
							gotoxy(x+2,y+height+5);
							printf("⑥ Search_Word ");
							break;
						case 7:

							gotoxy(x+2,y+height+6);
							printf("⑦ Graph ");
							break;

						case 8:

							gotoxy(x+2,y+height+7);
							printf("⑧ Exit ");
							break;
						}
						menu ++;

						SetColor(BackColor,Color);
						switch(menu)
						{
								case 1:
							gotoxy(x+2,y+height);
							printf("① Registration ");
							break;
						case 2:
							gotoxy(x+2,y+height+1);
							printf("② ShowAll ");
							break;
						case 3:
							gotoxy(x+2,y+height+2);
							printf("③ Search_File ");
							break;
						case 4:
							gotoxy(x+2,y+height+3);
							printf("④ Deletion ");
							break;
						case 5:
							gotoxy(x+2,y+height+4);
							printf("⑤ Modification ");
							break;
						case 6:
							gotoxy(x+2,y+height+5);
							printf("⑥ Search_Word ");
							break;
						case 7:

							gotoxy(x+2,y+height+6);
							printf("⑦ Graph ");
							break;

						case 8:

							gotoxy(x+2,y+height+7);
							printf("⑧ Exit ");
							break;
						}
					}
					break;

					//	case 75: // 왼쪽 방향키
				case 72: // 위쪽 방향키
					if(menu > 1)
					{
						SetColor(Color,BackColor);
						switch(menu)
						{
								case 1:
							gotoxy(x+2,y+height);
							printf("① Registration ");
							break;
						case 2:
							gotoxy(x+2,y+height+1);
							printf("② ShowAll ");
							break;
						case 3:
							gotoxy(x+2,y+height+2);
							printf("③ Search_File ");
							break;
						case 4:
							gotoxy(x+2,y+height+3);
							printf("④ Deletion ");
							break;
						case 5:
							gotoxy(x+2,y+height+4);
							printf("⑤ Modification ");
							break;
						case 6:
							gotoxy(x+2,y+height+5);
							printf("⑥ Search_Word ");
							break;
						case 7:

							gotoxy(x+2,y+height+6);
							printf("⑦ Graph ");
							break;

						case 8:

							gotoxy(x+2,y+height+7);
							printf("⑧ Exit ");
							break;
						}
						menu --;

						SetColor(BackColor,Color);
						switch(menu)
						{
						case 1:
							gotoxy(x+2,y+height);
							printf("① Registration ");
							break;
						case 2:
							gotoxy(x+2,y+height+1);
							printf("② ShowAll ");
							break;
						case 3:
							gotoxy(x+2,y+height+2);
							printf("③ Search_File ");
							break;
						case 4:
							gotoxy(x+2,y+height+3);
							printf("④ Deletion ");
							break;
						case 5:
							gotoxy(x+2,y+height+4);
							printf("⑤ Modification ");
							break;
						case 6:
							gotoxy(x+2,y+height+5);
							printf("⑥ Search_Word ");
							break;
						case 7:

							gotoxy(x+2,y+height+6);
							printf("⑦ Graph ");
							break;

						case 8:

							gotoxy(x+2,y+height+7);
							printf("⑧ Exit ");
							break;
						}
					}
					break;

					//백스페이스 뒤로가기
					case VK_BACK:
						gotoxy(x+2,y+height+7);
					SetColor(Color,BackColor);
					return -10;
						break;
				///case 32: // 스페이스바
			//		return menu;
			//		break;
				case 13: // 엔터
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
	
		case 3: //Show_all 메뉴  

		/******키이벤트 없을시 맨 처음 나오는 화면 시작******/

		gotoxy(x+2,y+height);
		SetColor(BackColor,Color);
		printf("① 문서등록번호 정렬 ");


		gotoxy(x+2,y+height+1);
		SetColor(Color,BackColor);
		printf("② 문서종류 정렬 ");

		gotoxy(x+2,y+height+2);
		SetColor(Color,BackColor);
		printf("③ 문서제목 정렬 ");

		gotoxy(x+2,y+height+3);
		SetColor(Color,BackColor);
		printf("④ 작성자 정렬 ");

		gotoxy(x+2,y+height+4);
		SetColor(Color,BackColor);
		printf("⑤ 문서작성날짜 정렬 ");

		gotoxy(x+2,y+height+5);
		SetColor(Color,BackColor);
		printf("⑥ 문서수정날짜 정렬 ");


		gotoxy(x+2,y+height+6);
		SetColor(Color,BackColor);
		printf("⑦ 문서크기 정렬 ");

		/******키이벤트 없을시 맨 처음 나오는 화면 끝******/
		while(1)
		{
			if(_kbhit())
			{
				key=getkey();
				switch(key)
				{
					//case 77: // 오른쪽 방향키
				case 80: // 아래 방향키
					if(menu < menu_num)
					{
						SetColor(Color,BackColor);
						switch(menu)
						{
						case 1:
							gotoxy(x+2,y+height);
							printf("① 문서등록번호 정렬 ");
							break;
						case 2:
							gotoxy(x+2,y+height+1);
							printf("② 문서종류 정렬 ");
							break;
						case 3:
							gotoxy(x+2,y+height+2);
							printf("③ 문서제목 정렬 ");
							break;
						case 4:
							gotoxy(x+2,y+height+3);
							printf("④ 작성자 정렬 ");
							break;
						case 5:
							gotoxy(x+2,y+height+4);
							printf("⑤ 문서작성날짜 정렬 ");
							break;
						case 6:
							gotoxy(x+2,y+height+5);
							printf("⑥ 문서수정날짜 정렬 ");
							break;
						case 7:
							gotoxy(x+2,y+height+6);
							printf("⑦ 문서크기 정렬 ");
							break;
						}
						menu ++;

						SetColor(BackColor,Color);
						switch(menu)
						{
							case 1:
							gotoxy(x+2,y+height);
							printf("① 문서등록번호 정렬 ");
							break;
						case 2:
							gotoxy(x+2,y+height+1);
							printf("② 문서종류 정렬 ");
							break;
						case 3:
							gotoxy(x+2,y+height+2);
							printf("③ 문서제목 정렬 ");
							break;
						case 4:
							gotoxy(x+2,y+height+3);
							printf("④ 작성자 정렬 ");
							break;
						case 5:
							gotoxy(x+2,y+height+4);
							printf("⑤ 문서작성날짜 정렬 ");
							break;
						case 6:
							gotoxy(x+2,y+height+5);
							printf("⑥ 문서수정날짜 정렬 ");
							break;
						case 7:
							gotoxy(x+2,y+height+6);
							printf("⑦ 문서크기 정렬 ");
							break;
						}
					}
					break;

					//	case 75: // 왼쪽 방향키
				case 72: // 위쪽 방향키
					if(menu > 1)
					{
						SetColor(Color,BackColor);
						switch(menu)
						{
							case 1:
							gotoxy(x+2,y+height);
							printf("① 문서등록번호 정렬 ");
							break;
						case 2:
							gotoxy(x+2,y+height+1);
							printf("② 문서종류 정렬 ");
							break;
						case 3:
							gotoxy(x+2,y+height+2);
							printf("③ 문서제목 정렬 ");
							break;
						case 4:
							gotoxy(x+2,y+height+3);
							printf("④ 작성자 정렬 ");
							break;
						case 5:
							gotoxy(x+2,y+height+4);
							printf("⑤ 문서작성날짜 정렬 ");
							break;
						case 6:
							gotoxy(x+2,y+height+5);
							printf("⑥ 문서수정날짜 정렬 ");
							break;
						case 7:
							gotoxy(x+2,y+height+6);
							printf("⑦ 문서크기 정렬 ");
							break;
						}
						menu --;

						SetColor(BackColor,Color);
						switch(menu)
						{
							case 1:
							gotoxy(x+2,y+height);
							printf("① 문서등록번호 정렬 ");
							break;
						case 2:
							gotoxy(x+2,y+height+1);
							printf("② 문서종류 정렬 ");
							break;
						case 3:
							gotoxy(x+2,y+height+2);
							printf("③ 문서제목 정렬 ");
							break;
						case 4:
							gotoxy(x+2,y+height+3);
							printf("④ 작성자 정렬 ");
							break;
						case 5:
							gotoxy(x+2,y+height+4);
							printf("⑤ 문서작성날짜 정렬 ");
							break;
						case 6:
							gotoxy(x+2,y+height+5);
							printf("⑥ 문서수정날짜 정렬 ");
							break;
						case 7:
							gotoxy(x+2,y+height+6);
							printf("⑦ 문서크기 정렬 ");
							break;
						}
					}
					break;

					//백스페이스 뒤로가기
					case VK_BACK:
					gotoxy(x+2,y+height+8);
					SetColor(Color,BackColor);
					return -10;
						break;
				///case 32: // 스페이스바
			//		return menu;
			//		break;
				case 13: // 엔터
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

//현재 x 커서위치
int wherex(void)
 {
     CONSOLE_SCREEN_BUFFER_INFO csb;
 
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csb);
     return (csb.dwCursorPosition.X);
 }


//현재 y 커서위치
 int wherey(void)
 {
     CONSOLE_SCREEN_BUFFER_INFO csb;
 
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csb);
     return (csb.dwCursorPosition.Y);
 }



 void print_graph(int x, int y, int height, int width, char* x_data_1,char* x_data_2,char* x_data_3,char* x_data_4,char* x_data_5,int rate1,int rate2,int rate3,int rate4,int rate5,int div_num) 
 {
	 y = wherey() + y ; //현재 커서위치에서 더 내려간다


	char Color = 15;  //색깔
	char BackColor = 0; //색깔
	int len=0;
	int x_line = 0; // x좌표의 현재 커서 위치를 나타내는 변수

	int x1_x = x+2; // x1좌표 출력시 x커서 위치
	int x1_y = y+20; // x1좌표 출력시 y커서 위치
	int x1_c = 0; // x1좌표 출력시 출력하는 글자
	
	int x2_x = x+14; // x2좌표 출력시 x커서 위치
	int x2_y = y+20; // x2좌표 출력시 y커서 위치
	int x2_c = 0; // x2좌표 출력시 출력하는 글자

	int x3_x = x+26; // x3좌표 출력시 x커서 위치
	int x3_y = y+20; // x3좌표 출력시 y커서 위치
	int x3_c = 0; // x3좌표 출력시 출력하는 글자

	int x4_x = x+38; // x4좌표 출력시 x커서 위치
	int x4_y = y+20; // x4좌표 출력시 y커서 위치
	int x4_c = 0; // x4좌표 출력시 출력하는 글자

	int x5_x = x+50; // x5좌표 출력시 x커서 위치
	int x5_y = y+20; // x5좌표 출력시 y커서 위치
	int x5_c = 0; // x5좌표 출력시 출력하는 글자

	int ps_x = 40; // 참고내용 출력시 x커서 위치 
	int ps_y = y+21; // 참고내용 출력시 y커서 위치
	int div=div_num;//나누는 수 
	char ps_c[] = "* 한칸당 문서 개수:"; // 참고내용 출력시 출력하는 글자
	
	//제목쓰기
	SetColor(14,0);
	gotoxy(ps_x-15,ps_y-22);
	printf("<문서 종류별 Top 5>");
	SetColor(15,0);

	//그래프 축 그리기
	SetColor(Color,BackColor);
	
	gotoxy(x,y+height-1);
	printf("└");
	
	gotoxy(x+2,y+height-1);
	for(int i = 0 ; i < width-2 ; i ++) // x축
		printf("─");

	for(int i = 1 ; i < height-1 ; i ++) //y축
	{
		gotoxy(x,y+i);
		printf("│");
		
	}


	//막대그래프 그리기
	
	for(int i = 1 ; i <= rate1 ; i ++) 
	{
		gotoxy(x+6,y+height-i-1);
		printf("■");
				
	}

	for(int i = 1 ; i <= rate2 ; i ++) 
	{
		gotoxy(x+16,y+height-i-1);
		printf("■");
					
	}
	for(int i = 1 ; i <= rate3 ; i ++) 
	{
		gotoxy(x+28,y+height-i-1);
		printf("■");
				
	}
	for(int i = 1 ; i <= rate4 ; i ++) 
	{
		gotoxy(x+40,y+height-i-1);
		printf("■");
					
	}
	for(int i = 1 ; i <= rate5 ; i ++) 
	{
		gotoxy(x+52,y+height-i-1);
		printf("■");
		
	}


	
	//x축 값 출력 시작

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