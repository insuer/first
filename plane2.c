#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int main()
{
	int i,j;
	int x=10,y=5;
	char input;
	int ny=5,location;
	int iffired=0;
	int ifkilled=0;
	while(1)
	{
		//ny=(rand()%15+2;
		system("cls");           //清屏 
		if(ifkilled==1)
		{
			location=ny;         //如果击中靶，赋给位置，随机生成下一个靶的位置 
			//ny=(rand()%15+2);
		}
		else
		{
		
			for(i=0;i<ny;i++)      //如果没有击中靶，生成上一个靶 
				printf(" ");
			printf("+\n");
			
		} 
		if(iffired==0)
		{
			for(i=0;i<x;i++)
			{
				printf("\n");      //如果没有开火，不输出子弹 
	 		}
	    }
	    else
	    {
	 		for(i=0;i<x;i++)
			{
				for(j=0;j<y;j++)
				printf(" ");        //如果开火，输出子弹 
				printf("|\n");
	 		}
	 		if(y==location)
	 			{
					ny=(rand()%15+2);					
					ifkilled=1;
				}        //如果子弹位置与靶相同，表明击中 
	 		else
	 			ifkilled=0;        //如若不同，表明没有击中 
	 		iffired=0;            //子弹发射一列后，消失。 
		}
	 	for(j=0;j<y;j++)
		{
			printf(" ");				//显示飞机 
	 	} 
	 	printf("*\n");
	 	for(j=0;j<y-2;j++)
		{
			printf(" ");
	 	} 
		  
	 	printf("*****\n");
	 	for(j=0;j<y-1;j++)
		{
			printf(" ");
	 	} 
	 	printf("* *");
	 	input=getch();
	 	if(input=='s')
	 	x++;
	 	else if(input=='w')
	 	x--;
	 	else if(input=='a')
	 	y--;
	 	else if(input=='d')
	 	y++;
	 	if(input==' ')
	 	{
		 	iffired=1;
		}
	 	
	}
 } 
