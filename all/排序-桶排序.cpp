#include<iostream>//桶排序 O(N) 
using namespace std;//基本思想：用数组b对a中每一个元素进行标记，最有检查b看哪些数被标记了 
#include<cstdio>
                
short a[11]={0,1,2,4,3,5,6,9,7,10,8};
short b[10001]={0};//桶要开的足够大！！ 

void bucket(int n)
{
	int i,j;
	for(i=1;i<=n;i++)//入桶 
	  b[a[i]]++;
	  
	for(i=1;i<=10000;i++)//输出（实际上并没有给a数组排序，只是对a中的数在b中标记了） 
	  if(b[i])
	    for(j=1;j<=b[i];j++)
	      cout<<i<<" ";
}

int main()
{
  int i;
  
  for(i=1;i<=10;i++)
    cout<<a[i]<<" ";
  cout<<endl;
  
  bucket(10); 
  
  getchar();getchar();
  return 0;
}
