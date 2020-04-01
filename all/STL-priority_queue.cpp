#include<iostream>
using namespace std;
#include<cstdio>
#include<queue>//优先队列的头文件 
#include<functional>//该头文件中包含了比较方式，可以利用 

int a[11]={0,9,6,8,4,5,7,1,3,2,10};

struct cmp1//采用结构体自定义优先级方式 
{
	bool operator()(int &a,int &b)
	{
	  return a>b;
	}
};

struct cmp2//采用结构体自定义优先级方式 
{
	bool operator()(int &a,int &b)
	{
	  return a<b;
	}
};

struct number1
{
	int x;
	int y;
	bool operator < (const number1 &a) const
	{
		return x<a.x;
	}
}; 

struct number2
{
	int x;
	int y;
	bool operator < (const number2 &a) const
	{
		return y<a.y;
	}
}; 

priority_queue<int>q0;//定义默认优先队列q0 
priority_queue<int,vector<int>,cmp1>q1;//根据cmp1规则的优先队列q1 
priority_queue<int,vector<int>,cmp2>q2;//根据cmp2规则的优先队列q2
priority_queue<int,vector<int>,greater<int> >q3;//利用functional 
priority_queue<int,vector<int>,less<int> >q4;//利用functional

priority_queue<number1>q5;
priority_queue<number2>q6;

int main()
{
	int i;
	
	cout<<"默认： "<<endl; 
	for(i=1;i<=10;i++)
	  q0.push(a[i]);
	for(i=1;i<=10;i++)//按默认优先级输出(默认为最大优先队列) 
	{
		cout<<q0.top()<<" ";
		q0.pop();
	}
	cout<<endl<<endl;
	
	cout<<"利用自定义结构体cmp1重载运算符return a>b: "<<endl;
	for(i=1;i<=10;i++)
	  q1.push(a[i]);
	for(i=1;i<=10;i++)//最小队列（注意：cmp结构体中为>） 
	{
		cout<<q1.top()<<" ";
		q1.pop();
	}
	cout<<endl<<endl;
	
	cout<<"利用自定义结构体cmp2重载运算符return a<b: "<<endl;
	for(i=1;i<=10;i++)
	  q2.push(a[i]);
	for(i=1;i<=10;i++)//最大队列（注意：cmp结构体中为<） 
	{
		cout<<q2.top()<<" ";
		q2.pop();
	}
	cout<<endl<<endl;
	
	cout<<"利用functional已有准则greater: "<<endl;
	for(i=1;i<=10;i++)
	  q3.push(a[i]);
	for(i=1;i<=10;i++)//最小队列（注意：利用了functional的greater） 
	{
		cout<<q3.top()<<" ";
		q3.pop();
	}
	cout<<endl<<endl;
	
	cout<<"利用functional已有准则less: "<<endl;
	for(i=1;i<=10;i++)
	  q4.push(a[i]);
	for(i=1;i<=10;i++)//最大队列（注意：利用了functional的greater） 
	{
		cout<<q4.top()<<" ";
		q4.pop();
	}
	cout<<endl<<endl;
	
	struct number1 b[6];
	b[1].x=1;b[1].y=9;
	b[2].x=2;b[2].y=8;
	b[3].x=3;b[3].y=7;
	
	cout<<"以结构体作为元素："<<endl;
	for(i=1;i<=3;i++)
	  q5.push(b[i]); 
	for(i=1;i<=3;i++)
	{
		struct number1 t;
		t=q5.top();
		cout<<t.x<<" "<<t.y<<endl;
		q5.pop();
	}
	cout<<endl<<endl;
	
	struct number2 c[6];
	c[1].x=1;c[1].y=9;
	c[2].x=2;c[2].y=8;
	c[3].x=3;c[3].y=7;
	
	cout<<"以结构体作为元素："<<endl;
	for(i=1;i<=3;i++)
	  q6.push(c[i]); 
	for(i=1;i<=3;i++)
	{
		struct number2 t;
		t=q6.top();
		cout<<t.x<<" "<<t.y<<endl;
		q6.pop();
	}
	cout<<endl<<endl;
	
	
	
	getchar();getchar();
	return 0;
}
