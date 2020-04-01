#include<iostream>//STL：sort()排序  O(NlogN)
using namespace std;
#include<cstdio>
#include<algorithm>//这是sort（）的头文件

short a[11]={0,1,2,4,3,5,6,9,7,10,8};

bool cmp(int a,int b)//返回必须是bool型，该函数决定排序方式 
{
	return a<b;//a<b返回true a>b返回false ,升序排序 
}

int main()
{
  int i;
  for(i=1;i<=10;i++)
   cout<<a[i]<<" ";
  cout<<endl;
  
  sort(a+1,a+1+10,cmp);//参数1：待排序的首地址(这里不排a[0]故a+1否则是a) 
                       //参数2：带排序的末地址的下一个地址，说白了就是 首地址+带排序元素长度
					   //参数3：升序or降序 函数 
  for(i=1;i<=10;i++)
   cout<<a[i]<<" ";
  cout<<endl;
  
  getchar();getchar();
  return 0;
} 
