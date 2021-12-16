#include<stdio.h>
#include<stdlib.h> 
#include<conio.h>
#include<windows.h>
//定义
int position_x,position_y;//飞机坐标
int high,width;//框架
int bullet_x,bullet_y;//子弹位置
int enemy_x,enemy_y;//敌机
int score;//游戏得分
void gotoxy(int x,int y)//类似于清屏函数，光标移动到原点位置进行重画
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(handle,pos);
}
void HideCursor()
{
	CONSOLE_CURSOR_INFO cursor_info = {1, 0};
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
void startup()//数据初始化
{
	high=18;
	width=30;
	position_x=high/2;
	position_y=width/2;
	bullet_y=position_y;
	bullet_x=-1;
	enemy_x=0;
	enemy_y=width/2;
	score=0;
 } 
void show()       // 显示
{
	gotoxy(0,0);
	int i,j;
	//system("cls");//清屏
	for(i=0;i<high;i++)
	{
		for(j=0;j<width;j++)
		{
			if(i==position_x&&j==position_y)
				printf("*");//显示飞机 
			else if(i==bullet_x&&j==bullet_y)
				printf("|");//输出子弹
			else if(i==enemy_x&&j==enemy_y)
				printf("$");//输出敌机
			else 
			printf(" ");//输出空格
			
		}
		printf("\n");//转至下一行
	}
	printf("score=%d",score);
}
void updatewithoutinput()//更新无关输出的内容 
{
	if(bullet_x==enemy_x&&bullet_y==enemy_y)
	{
		score++;
		enemy_x=0;
		bullet_x=-1;
		enemy_y=rand()%width;
	}
	if(bullet_x>-1)
		bullet_x--;
	static int speed=0;//用于控制敌机下落
	if(speed<10)
		speed++;
	if(speed==10)
	{
		if(enemy_x>high)
		{
			enemy_x=0;
			enemy_y=rand()%width;
		}
		else
		{
			if(speed==10)
			{
				enemy_x++;
				speed=0;
			}
		}
			
	}
	
	

}
void updatewithinput()//更新有关输入的内容
{
	char input; 
	if(kbhit())//当按键时执行
	{
		input=getch();
		if(input=='a')
			position_y--;
		if(input=='d')
			position_y++;
		if(input=='w')
			position_x--;
		if(input=='s')
			position_x++;
		if(input==' ')
		{
			bullet_x=position_x-1;
			bullet_y=position_y;
		}
	}
}
int main()
{
	HideCursor();
	startup();//数据的初始化
	while(1)
	{
		show();//显示画面
		updatewithoutinput();//与输入无关的内容
		updatewithinput();//与输入有关的内容
		
	}
	return 0;
 } 
