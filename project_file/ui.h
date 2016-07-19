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


//트리를 쓰는 이유중 가장 큰 것은 뒤로 백할때의 편리성
//트리 - 구조체 정의
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
 
 int element; //데이터는 함수포인터로 저장 x(미리 함수의 자료형, 함수인자의 자료형을 알고 있어야함) 결론적으로 변수지정해서 하는것이 나을듯
};
//부모와 자식만 알면 되므로 트리구조 사용할필요 없을듯.



int ui(int x, int y, int height, int width, char* title, char* message, int type, int menu_num, char* menu_1, char* menu_2, char* menu_3); //ui출력함수
int getkey(); //키입력 받는 함수
void SetColor(color colFront, color colBack); //색 지정
void gotoxy(int x, int y);//키를 x,y로 보내줌.
int wherex(void); //현재 x 커서위치
int wherey(void); //현재 y 커서위치
void print_graph(int x, int y, int height, int width, char* x_data_1,char* x_data_2,char* x_data_3,char* x_data_4,char* x_data_5,int rate1,int rate2,int rate3,int rate4,int rate5,int div);
#endif