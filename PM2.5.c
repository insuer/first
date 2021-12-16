#include<stdio.h>
int main()
{
	int n,a[n],b1=0,b2=0,b3=0,b4=0,b5=0,b6=0,i,j,k;
	float av,sum=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	for(j=0;j<n;j++)
	{
		if(a[j]<=50)
		b1++;
		else if((a[j]>50)&&(a[j]<=100))
		b2++;
		else if((a[j]>100)&&(a[j]<=150))
		b3++;
		else if((a[j]>=151)&&(a[j]<=200))
		b4++;
		else if((a[j]>=201)&&a[j]<=300)
		b5++;
		else if((a[j])>300)
		b6++;
		sum=sum+a[j];	 
	}
	av=sum/n;
	printf("%.2f\n",av);
	printf("%d %d %d %d %d %d",b1,b2,b3,b4,b5,b6);
	return 0;
}
