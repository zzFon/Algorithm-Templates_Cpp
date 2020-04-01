#include<iostream>//插入排序 O(N^2) 
using namespace std;//基本思想：每次将一个待排序的数据元素，插入到前面已经排好序的
#include<cstdio>//数列中的适当位置，使数列依然有序；直到待排序数据元素全部插入完为止。
                
short a[11]={0,1,2,4,3,5,6,9,7,10,8};

void insert(int n)
{
  int i,j;
  
  for(i=2;i<=n;i++)//枚举插入次数
  {
	a[0]=a[i];
    for(j=i-1;j>=1;j--)//在已排好序的数列中查找适当的位置
   {
	  if(a[j]>a[0])
	    a[j+1]=a[j];//向后挪
	  else
	    break;//到位（由此易证若j以降序序则同一个数较后插入的排在较前插入的后面，若j以升序则反之） 
   } 
   a[j+1]=a[0]; 
  } 
}

int main()
{
  int i;
  
  for(i=1;i<=10;i++)
    cout<<a[i]<<" ";
  cout<<endl;
  
  insert(10);
  
  for(i=1;i<=10;i++)
    cout<<a[i]<<" ";
  cout<<endl;
  
  getchar();getchar();
  return 0;
}
