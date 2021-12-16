//#include<stdio.h>
//#include<string.h>
//int main()
//{
//   int n,i,j;
//   scanf("%d",&n);
//   char a[n][20],q[n][20],u;
//   getchar();
//   //scanf("%c",&u);
//   for(i=0;i<n;i++)
//   {
//         gets(a[i]);
//       //scanf("%s",&a[i]);
//   }
//   int b[n],c;
//   scanf("%d",&c);
//   for(i=0;i<n;i++)
//   {
//       scanf("%d",&b[i]);
//   }
//   for(i=1;i<=c;i++)
//   {
//       for(j=0;j<n;j++)
//       {
//           strcpy(q[b[j]-1],a[j]);
//       }
//   }
//   for(i=0;i<n;i++)
//   {
//   	puts(q[i]);
//   }
//   
//}
////#include<stdio.h>
////int main()
////{
////	char a[4][20];
////	int i;
////	for(i=0;i<4;i++)
////	{
////		gets(a[i]);
////	}
////	for(i=3;i>=0;i--)
////	{
////		puts(a[i]);
////	}
////}
#include<stdio.h>
#include<stdlib.h> 
#include<conio.h>
#include<windows.h>
//定义
int position_x,position_y;//飞机坐标
int high,width;//框架
int bullet_x,bullet_y;//子弹位置
int enemy_x,enemy_y;//敌机
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
 } 
void show()       // 显示
{
	int i,j;
	system("cls");//清屏
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
}
void updatewithoutinput()//更新无关输出的内容 
{
	if(bullet_x>-1)
		bullet_x--;
	static int speed=0;
	if(speed<50)
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
			if(speed==50)
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
	if(_kbhit())//当按键时执行
	{
		input=getch();
		if(input=='a')
			position_y--;
		if(input=='d')
			position_y++;
		if(input=='w')
			position_x++;
		if(input=='s')
			position_x--;
		if(input==' ')
		{
			bullet_x=position_x-1;
			bullet_y=position_y;
		}
	}
}
int main()
{
	startup();
	while(1)
	{
		show();
		updatewithoutinput();
		updatewithinput();
		return 0;
	}
 } 

