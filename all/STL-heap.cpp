#include<iostream>
using namespace std;
#include<cstdio>
#include<algorithm>//堆算法的头文件

int h[11]={0,10,5,7,2,4,3,9,8,1,6};

int cmp(int a,int b)
{
	return a>b;
} 

int cmp2(int a,int b)
{
	return a<b;
} 

int main()
{
	make_heap(&h[1],&h[10+1]);//建立堆make_heap(头指针,尾指针,比较参数)，默认最大堆 
	
	for(int i=1;i<=10;i++)//最大堆遍历（不是排序） 
	  cout<<h[i]<<" ";
	cout<<endl;
	
	make_heap(&h[1],&h[10+1],cmp);//建立最小堆，注意cmp函数！！！！ 
	
	for(int i=1;i<=10;i++)//最小堆遍历（不是排序） 
	  cout<<h[i]<<" ";
	cout<<endl; 
	
	h[11]=11;
	push_heap(&h[1],&h[10+1+1],cmp);//按照cmp的比较法则插入新元素 
	  
	for(int i=1;i<=11;i++)//最小堆遍历（不是排序） 
	  cout<<h[i]<<" ";
	cout<<endl; 
	
	pop_heap(&h[1],&h[10+1+1],cmp);//堆顶出堆(实际上是将其置于堆尾并使得堆元素-1) 
    
    for(int i=1;i<=10;i++)//最小堆遍历（不是排序） 
	  cout<<h[i]<<" ";
	cout<<endl; 
	
	cout<<h[11]<<endl;
	
    int k[11]={0,10,5,7,2,4,3,9,8,1,6};
    
    sort_heap(&k[1],&k[10+1],cmp2);//堆排序 
    
    for(int i=1;i<=10;i++)//最小堆遍历（不是排序） 
	  cout<<h[i]<<" ";
	cout<<endl; 
	
	getchar();getchar();
	return 0;
} 
