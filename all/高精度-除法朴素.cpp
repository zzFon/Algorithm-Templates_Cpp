#include<iostream>//高/高 O(商的大小) 
using namespace std;//手算试除法，每次看被除数能不能CalcMinus除数，直到不能(实际上就是除法转化成了减法算，超慢) 
#include<cstdio>    
#include<cstring>   
#define maxl 500+5

string a1,b1;
short a[maxl],b[maxl],c[maxl]; 
int la,lb,l;

void init()
{
	la=a1.length();lb=b1.length();
	memset(a,0,sizeof(a));memset(b,0,sizeof(b));//必须 
	for(int i=0;i<la;i++)
	  a[i+1]=a1[la-1-i]-'0';
	for(int i=0;i<lb;i++)
	  b[i+1]=b1[lb-1-i]-'0';
}

int CalcMinus()
{
	if(la<lb)
	  return 0;
	if(la==lb)
	{
		for(int i=la;i>=1;i--)
		  if(a[i]<b[i])
		    return 0;
	}
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
	return 1;
}

void CalcDivision()
{
	memset(c,0,sizeof(c));
	while(CalcMinus()==1)
	{
	  c[1]++;
	  for(int i=1;i<=l;i++)
	  {
		c[i+1]+=c[i]/10;c[i]%=10;
	  }  
	  if(c[l+1]>0)
	  l++;
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
	for(int i=l;i>=1;i--)
	  cout<<c[i];
	cout<<endl; 
}
