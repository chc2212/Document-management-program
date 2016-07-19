#ifndef __UI_H__
#define __UI_H__

//#include"function.h"
//#include"data.h"
//#include"file.h"


typedef unsigned char color;
const color BLACK = 0;
const color BLUE = 1;
const color GREEN = 2;
const color CYAN = 3;
const color RED = 4;
const color MAGENTA = 5;
const color PURPLE = MAGENTA;
const color BROWN = 6;
const color LIGHTGRAY = 7;
const color GRAY =  8;
const color LIGHTBLUE =9;
const color LIGHTGREEN = 10;
const color LIGHTCYAN = 11;
const color LIGHTRED = 12;
const color LIGHTMAGENTA = 13;
const color LIGHTPURPLE = LIGHTMAGENTA;
const color YELLOW = 14;
const color WHITE = 15;


//Ʈ���� ���� ������ ���� ū ���� �ڷ� ���Ҷ��� ����
//Ʈ�� - ����ü ����
struct tnode
{ 
 struct tnode *child1;
 struct tnode *child2;
 struct tnode *child3;
 struct tnode *child4;
 struct tnode *child5;
 struct tnode *child6;
 struct tnode *child7;
 struct tnode *child8;
 struct tnode *parent;
 
 int element; //�����ʹ� �Լ������ͷ� ���� x(�̸� �Լ��� �ڷ���, �Լ������� �ڷ����� �˰� �־����) ��������� ���������ؼ� �ϴ°��� ������
};
//�θ�� �ڽĸ� �˸� �ǹǷ� Ʈ������ ������ʿ� ������.



int ui(int x, int y, int height, int width, char* title, char* message, int type, int menu_num, char* menu_1, char* menu_2, char* menu_3); //ui����Լ�
int getkey(); //Ű�Է� �޴� �Լ�
void SetColor(color colFront, color colBack); //�� ����
void gotoxy(int x, int y);//Ű�� x,y�� ������.
int wherex(void); //���� x Ŀ����ġ
int wherey(void); //���� y Ŀ����ġ
void print_graph(int x, int y, int height, int width, char* x_data_1,char* x_data_2,char* x_data_3,char* x_data_4,char* x_data_5,int rate1,int rate2,int rate3,int rate4,int rate5,int div);
#endif