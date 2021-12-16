#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
int main()
{
	int i,j;
	int vx=1,vy=1;
	int top=0,bottom=20,left=0,right=20;
	int x=0,y=0;
	while(1)
	{
		for(j=0;j<=y;j++)
		{
			//y+=vy;
			printf("\n");
		}
		y+=vy;
		for(i=0;i<=x;i++)
		{
			//x+=vx;
			printf(" ");	
		}
		x+=vx;
		if(x==right||x==left)
		{
			putchar('\a');
			vx=-vx;
		}
		if(y==bottom||y==top) 
		{
			putchar('\a');
			vy=-vy;
		}
		printf("O");
		//sleep(1000);
		system("cls");
	 } 
 } 
