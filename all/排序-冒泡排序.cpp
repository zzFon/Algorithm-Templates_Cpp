#include<iostream>//冒泡排序 O(N^2) 
using namespace std;//基本思想：两两比较待排序数据元素的大小，发现两个数据元素的次序相反时即进行交换，
#include<cstdio>//直到没有反序的数据元素为止。
                
short a[11]={0,1,2,4,3,5,6,9,7,10,8};

void bubble(int n)
{
	int i,j,flag;
	for(i=1;i<=n-1;i++)//枚举趟数，最后一个数不用归位，故n-1趟即可 
    {
	  flag=1;
	  for(j=1;j<=n-i;j++)//两两比较
	  {
	    if(a[j]>a[j+1])
		{
			a[0]=a[j];
			a[j]=a[j+1];
			a[j+1]=a[0];
			flag=0;
		}	 
	  }
	  if(flag)//优化：已排好可以结束 
	    break;
	}
}

int main()
{
  int i;
  
  for(i=1;i<=10;i++)
    cout<<a[i]<<" ";
  cout<<endl;
  
  bubble(10);
  
  for(i=1;i<=10;i++)
    cout<<a[i]<<" ";
  cout<<endl;
  
  getchar();getchar();
  return 0;
}
