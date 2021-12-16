#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i,j;
	int x,y=10;
	for(x=1;x<50;x++)
	{
		for(i=0;i<x;i++)
		{
			printf("\n");
		}
		for(j=0;j<y;j++)
		{
			printf(" ");
		}
		printf("o\n");
		system("cls");
	}
	return 0;
 } 
