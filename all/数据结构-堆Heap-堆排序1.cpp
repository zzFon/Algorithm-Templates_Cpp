#include<iostream>//(出堆最小堆)堆排序  O(NlogN) 
using namespace std;//基本思想：利用最小堆堆的基本性质，不断将堆顶出堆并让堆尾补位，再向下调整实现排序 
#include<cstdio>

int h[101];
int n=0;
int a[11]={0,7,6,9,1,4,3,2,8,5,10};

void swap(int x,int y)
{
	int a=h[x];
	h[x]=h[y];
	h[y]=a;
}

void siftdown(int i)
{
	int t,flag=0;
	
	t=i;
	while(i*2<=n&&flag==0)
	{
		if(h[i*2]<h[i])
		  t=i*2;
		if(i*2+1<=n)
		  if(h[i*2+1]<h[t])
		    t=i*2+1;
		
		if(t!=i)
		{
			swap(i,t);
			i=t;
		}
		else
		  flag=1;
	}
}

void create()
{
	int i;
	for(i=n/2;i>=1;i--)
	  siftdown(i);
}

int heapsort()
{
	int t;
	t=h[1];
	h[1]=h[n];
	n--;
	siftdown(1);
	return t;
}

int main()
{
	int i;
	
	n=0;
	for(i=1;i<=10;i++)
	{
		n++;
		h[n]=a[i];
	}
	
	create();//建立最小堆
	
	int num=n;
	for(i=1;i<=num;i++)
	  cout<<heapsort()<<" "; 
	
	getchar();getchar();
	return 0;
}
