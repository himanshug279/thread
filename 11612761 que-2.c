#include<stdio.h>
#include<pthread.h>
int size;
float minimum,maximum,average;
void *avg(void *ar)
{
	int *b=(int *)ar;
	int sum=0;
	for(int i=0;i<size;i++)
	{
		sum+=b[i];	
	}
	average=sum/size;
	printf("The average value is :- %f\n",average);
}
void *min(void *ar)
{
	int *b=(int *)ar;
	minimum=b[0];
	for(int i=0;i<size;i++)
	{
		if(minimum>b[i])
		minimum=b[i];	
	}
	printf("The minimum value is :- %f\n",minimum);
}
void *max(void *ar)
{
	int *b=(int *)ar;
	maximum=b[0];
	for(int i=0;i<size;i++)
	{
		if(maximum<b[i])
		maximum=b[i];	
	}
	printf("The maximum value is:- %f\n",maximum);
}
int main(int argc, char *argv[])
{
	pthread_t p1,p2,p3;
	size=argc-1;
	int a[size];
	for(int i=1;i<size+1;i++)
	{
		a[i-1]=atoi(argv[i]);
	}
	pthread_create(&p1,NULL,avg,(void *)a);
	pthread_create(&p2,NULL,min,(void *)a);
	pthread_create(&p3,NULL,max,(void *)a);
	pthread_join(p1,NULL);
	pthread_join(p2,NULL);
	pthread_join(p3,NULL);
        
}
