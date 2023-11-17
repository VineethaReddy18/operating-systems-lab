#include<stdio.h>

int front=-1,rear=-1,pf=0,h=0;

int isFull(int n)
{
	if(rear==n-1)
	{
		return 1;
	}
	return 0;
}
void enq(int q[],int val,int n)
{
	if(front==-1 && rear==-1)
	{
		front++;
		rear++;
		q[rear]=val;
	}
	else
	{
		if(!isFull(n))
		{
			rear++;
			q[rear]=val;
		}
		else
		{
			rear=0;
			q[rear]=val;
		}
	}
}
int dq(int q[])
{
	if(front!=-1)
	{
		if(front==rear)
		{
			
			int t=q[front];
			front=-1;rear=-1;
			return t;
		}
		else
		{
			return q[front++];
		}
	}
}

int Contains(int q[],int val,int n)
{
	for(int i=0;i<n;i++)
	{
		if(q[i]==val)
			return 1;
	}
	return 0;
}

void main()
{
	int n;
	printf("Enter no.of frames:");
	scanf("%d",&n);
	int q[n];
	for(int i=0;i<n;i++)
	{
		q[i]=-1;
	}
	int s;
	printf("Enter size of string:");
	scanf("%d",&s);
	int rs[s];
	printf("Enter reference string:");
	for(int i=0;i<s;i++)
	{
		scanf("%d",&rs[i]);
	}
	int i=0;
	while(i<s)
	{
		if(Contains(q,rs[i],n)==0)
		{
			pf++;
			//printf("%d res:%d ",rs[i],Contains(q,rs[i],n));
			if(isFull(n)==0)
			{
				enq(q,rs[i],n);
			}
			else
			{
				dq(q);
				enq(q,rs[i],n);
			}
		}
		else
			h++;
		for(int j=0;j<n;j++)
		{
			printf("%d ",q[j]);
		}
		printf("\n");
		i++;
	}
	printf("Page faults:%d\n",pf);
	printf("Page hits:%d\n",h);
}
