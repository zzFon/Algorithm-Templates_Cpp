#include<iostream>//高/高 O(商的各位数之和)<=(LenOf被除数*10) 弹簧除法 
using namespace std;//一开始先把除数b拉伸到最大(*10*10*...*10)，但必须满足a>=b 
#include<cstdio>    //然后就开始循环试除，如果a>=b,则CalceMinus,否则压缩b(/10) 
#include<cstring>   //如果压缩b的结果是lb<初始lb,说明a已经不能再除了(哪怕是原始b) 
#include<cmath>     //此时除法结束 
#define maxl 500+5  //注意：1.由于弹簧是越压越紧的，故c的位数是越来越高的 
                    //        c的存储实际上是1位最高，然后每次都向lc+1拓展作为最低位 
string a1,b1;       //      2.为了方便弹簧拉伸和压缩，b的存储也是1位最高lb最低 
short a[maxl],b[maxl],c[maxl];
int la,lb,originlb,lc;

void reverseb()
{
	for(int i=1;i<=lb/2;i++)
	  swap(b[i],b[lb-i+1]); 
}

void init()
{
	la=a1.length();lb=b1.length();originlb=lb;
	memset(a,0,sizeof(a));memset(b,0,sizeof(b));//必须 
	for(int i=0;i<la;i++)
	  a[i+1]=a1[la-1-i]-'0';
	for(int i=0;i<lb;i++)
	  b[i+1]=b1[lb-1-i]-'0';
	reverseb();
}

void CalcMinus()
{
	reverseb();
	for(int i=1;i<=la;i++)
	{
		if(a[i]<b[i])
		{
			a[i+1]--;
			a[i]+=10; 
		}
		a[i]-=b[i];
	}
	while(a[la]==0)
	  la--;
	reverseb();
}

int cmp()//cmp a b
{
	if(la>lb)
	  return 1;
	else if(la==lb)
	{
		reverseb();
		int l=la;
		for(int i=l;i>=1;i--)
	    {
	    	if(a[i]>b[i])
	    	{
	    		reverseb();
	    		return 1;
			} 
	    	else if(a[i]<b[i])
	    	{
	    		reverseb();
	    		return 0;
			}  
		}
		reverseb();
		return 1;
	}
	else 
	  return 0;
}

void CalcDivision()
{
	while(cmp()==1)//a>=b
	{
		lb++;
		b[lb]=0;
	}
	lb--;
	/*for(int i=la;i>=1;i--)
		cout<<a[i];
	cout<<endl;
	for(int i=1;i<=lb;i++)
		cout<<b[i];
	cout<<endl;*/
	
	memset(c,0,sizeof(c));lc=1;
	while(1)
	{
		while(cmp()==1)//a>=b
		{ 
		  /*for(int i=la;i>=1;i--)
		    cout<<a[i];
		  cout<<"-";
		  for(int i=1;i<=lb;i++)
		    cout<<b[i];
		  cout<<endl;*/
		  
		  CalcMinus();
		  c[lc]++;
		}  
		
		lb--;
		if(lb<originlb)
		  break;
		lc++;
		c[lc]=0;
		
	}
}

int main()
{	
	cin>>a1>>b1;
	
	init();//读入字符串a b并处理成数 
    CalcDivision(); 
	void PrintOut();PrintOut(); 
	
	return 0;
}

void PrintOut()
{
	for(int i=1;i<=lc;i++)
	  cout<<c[i];
	cout<<endl; 
}
