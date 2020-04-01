#include<iostream>//（不出堆最大堆）堆排序  O(NlogN) 
using namespace std;//基本思想：利用最大堆性质，以此对调堆顶（最大数）和堆尾，对调后堆顶向下调整并减少堆元素数， 
#include<cstdio>//”认为“最大的堆顶已出堆，实际上存在堆尾，由此而来，堆尾向堆顶序号依次递减而元素大小也依次递减，
///因为每次放在(当时) 堆尾的都是（当时）堆中最大的元素
 
int h[101];
int n=0;
int a[11]={0,7,6,9,1,4,3,2,8,5,10};

void swap(int x,int y)
{
	int z=h[x];
	h[x]=h[y];
	h[y]=z;
}

void siftdown(int i)
{
	int t,flag=0;
	
	t=i;
	while(i*2<=n&&flag==0)
	{
		if(h[i*2]>h[i])
		  t=i*2;
		if(i*2+1<=n)
		  if(h[i*2+1]>h[t])
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

void heapsort()
{
	while(n>1)
	{
		swap(1,n);
		n--;
		siftdown(1);
	}
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
	
	create();
	
	for(i=1;i<=n;i++)//遍历堆数组(不是遍历堆输出，堆有序不代表堆数组有序) 
	  cout<<h[i]<<" ";
	cout<<endl; 
	
	int num=n;
	heapsort();//（不出堆最大堆）堆排序可以使得堆数组有序而无需出堆排序 
	
	for(i=1;i<=num;i++)//遍历堆数组(经过不出堆最大堆堆排序后堆数组有序)
	  cout<<h[i]<<" ";
	  
	getchar();getchar();
	return 0;
}
