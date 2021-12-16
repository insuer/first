#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int main()
{
	int i,j;
	int x=10,y=5;
	char input;
	int ny=5,location;
	int iffired=0,point=0;
	int ifkilled=0;
	while(1)
	{
		//ny=(rand()%15+2;
		system("cls");
		/*if(ifkilled==1)
		{
			location=ny;
			ny=(rand()%15+2);
		}*/
		//else
		if(ifkilled==0)
		{
		
			for(i=0;i<ny;i++)
				printf(" ");
			printf("+\n");
			
		} 
		if(iffired==0)
		{
			for(i=0;i<x;i++)
			{
				printf("\n");
	 		}
	    }
	    else
	    {
	 		for(i=0;i<x;i++)
			{
				for(j=0;j<y;j++)
				printf(" ");
				printf("|\n");
	 		}
	 		if(y==ny /*location*/)
	 		{
				ny=(rand()%15+2);
	 			ifkilled=1;
	 			point++;
	 		}
	 		else
	 			ifkilled=0;
	 		iffired=0;
		}
	 	for(j=0;j<y;j++)
		{
			printf(" ");
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
	 	printf("* *\npoint=%d",point);
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
