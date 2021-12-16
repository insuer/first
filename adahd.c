#include<stdio.h>
#define g_max(type)\
type type##_max(type x,type y)\
{\
	return x>y? x:y;\
}

int main()
{
	float x,v,y;
	scanf("%f %f",&x,&y); 
	g_max(float);
	v=float_max(x,y);
	printf("%f",v);
	return 0;
 } 
 
