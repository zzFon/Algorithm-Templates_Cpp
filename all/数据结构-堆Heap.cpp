#include<iostream>//最小堆  平均时间复杂度O(NlogN) 
using namespace std;//基本思想： 2种建堆方式：1.边建堆便(向上)维护  O(NlogN)  2.先建立无序堆再（逐一向下）维护  
#include<cstdio>//据说是  O(N) ；删除元素时堆顶元素出堆，堆尾元素补位并向下调整（由此实现排序） 
//向上调整：比较父节点是否比自己大，若是则交换，否则结束
//向下调整：比较子节点是否比自己小，若是则去子节点中最小的交换，否则结束
//逐一向下调整：从最后一个内部节点开始（由于堆是完全二叉树，故该节点是n/2），枚举遍历至堆顶，逐一实行向下调整 

int h[101];
int n;
int in[11]={0,5,2,3,4,1};

void swap(int x,int y)
{
	int a;
	a=h[x];
	h[x]=h[y];
	h[y]=a;
}

void siftup(int i)
{
	int t,flag=0;
	while(i!=1&&flag==0)
	{
		if(h[i]<h[i/2])
		{
			swap(i,i/2);
			
			i=i/2;
		}
		else
		  flag=1;
	}
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

int main()
{
	int i;
	
	n=0;
	for(i=1;i<=5;i++)//边插入边维护建立最小堆：向上调整   O(NlogN)
	{
		n++;
		h[n]=in[i];
		siftup(n);
	}
	
	/*for(i=1;i<=n;i++)
	  cout<<h[i];*/
	
	int num=n;
	for(i=1;i<=num;i++)//输出堆：向下调整 
	{
		cout<<h[1]<<" ";
		h[1]=h[n];
		n--;
		siftdown(1);
	}
	cout<<endl;
	
	for(i=1;i<=5;i++)//先建立无序堆再维护：逐个向下调整  O(N) 
	{
		n++;
		h[n]=in[i];
	}
	for(i=n/2;i>=1;i--)
	  siftdown(i);
	
	num=n;
	for(i=1;i<=num;i++)//输出堆：向下调整 
	{
		cout<<h[1]<<" ";
		h[1]=h[n];
		n--;
		siftdown(1);
	}
	
	getchar();getchar();
	return 0;
}
