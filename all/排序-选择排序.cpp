#include<iostream>//选择排序 O(N^2) 
using namespace std;//每一趟从待排序的数据元素中选出最小（或最大）的一个元素，
#include<cstdio>//顺序放在已排好序的数列的最后，直到全部待排序的数据元素排完。 
                
short a[11]={0,1,2,4,3,5,6,9,7,10,8};

void select(int n)
{
  int i,j,min,minpos;
  for(i=1;i<=n-1;i++)
  {
    min=a[i];
    minpos=i;
    for(j=i+1;j<=n;j++)
      if(a[j]<min)
      {
	    min=a[j];
	    minpos=j;
	  }
	a[minpos]=a[i];
	a[i]=min;
  }
}

int main()
{
  int i;
  
  for(i=1;i<=10;i++)
    cout<<a[i]<<" ";
  cout<<endl;
  
  select(10);
  
  for(i=1;i<=10;i++)
    cout<<a[i]<<" ";
  cout<<endl;
  
  getchar();getchar();
  return 0;
}
