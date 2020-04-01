#include<iostream>//快速排序 O(NlogN)
using namespace std;//基本思想：不断以左界的数（其实以任意一个数也可）作为参考数，j先走i后奏，利用j从右界向左推找到比参考数
#include<cstdio>    //小，i从左界向右推找到比参考数大的，交换i、j所处元素，依次循环直至ij相遇，此时相遇处左皆<=参考数，右处皆>=参考数 
                    //显然此处即是参考数在排序后所在位置，将其归位。然后分治参考数以左、参考数以右，同理处理之 

int a[11]={0,10,8,3,9,2,5,6,4,7,1};

void quicksort(int left,int right)
{
  if(left>right)//没数了，不用排 
    return;
	
  int i,j,tmp;
  i=left;//哨兵i从左界开始 
  j=right;//哨兵j从右界开始 
  tmp=a[left];//参考数 
  while(i!=j)
  {
		while(i<j&&a[j]>=tmp)//哨兵j要先走（只有j先走，才能保证i、j相遇的地方总是<参考数：若i遇上j，则相遇地方是j停下的地方，必<参考数；若 
		  j--;               //j遇上i，则此时i是上次交换后的i，即上次交换前的j，必<参考数）
		while(i<j&&a[i]<=tmp)
		  i++;
		
		swap(a[i],a[j]);
  }
  swap(a[left],a[i]);//将参考数归位 
  quicksort(left,i-1);//分治 
  quicksort(i+1,right);	
}

int main()
{
	int i;
	for(i=1;i<=10;i++)
	  cout<<a[i]<<" ";
	cout<<endl;
	
	quicksort(1,10);//快排参数：左界和右界 
	
	for(i=1;i<=10;i++)
	  cout<<a[i]<<" ";
	  
	getchar();getchar();
	return 0;
}
