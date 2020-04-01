#include<iostream>
using namespace std;
#include<cstdio>

int a[11]={0,2,5,1,4,3,7,6,8,9,10};
int t[11];//用于临时存储，大小必须和a等大 

void mergesort(int left,int right)
{
	if(left<right)//若该条件不成立说明只分解剩下1个元素了，不用再分了，返回 
	{
		int i,j,mid,tp;
		mid=left+(right-left)/2;
		i=left;//左区间指针i 
		j=mid+1;//右区间指针j 
        tp=left;//暂存数组t的指针 
				
		mergesort(left,mid);//归:利用递归将数列分解 
		mergesort(mid+1,right);
		
	    while(i<=mid||j<=right)//并：将当前区间分解为左区间和右区间，分别用i j指向左右区间头元素，i j向后推（区间内）依次比较去较小的放入t中暂时存储 
	    {                      //注意：左区间弹出元素到t的条件：i指向元素比j的小 或 j已经爆了区间。右区间同理 
			if(j>right||i<=mid&&a[i]<=a[j])
			  t[tp++]=a[i++];
			else
			  t[tp++]=a[j++];
		}
		int k;
		for(k=left;k<=right;k++)
		  a[k]=t[k]; 
	}
}	  

int main()
{
	int n=10;
	
	mergesort(1,n);
	
	int i;
	for(i=1;i<=n;i++)
	  cout<<a[i]<<" "; 
	
	getchar();getchar();
	return 0;
}
