#include<iostream>//高+高 O(max(lenA,lenB)) 
using namespace std;//没什么神奇的，就是模拟手算加法，可以优化为逢10000进 
#include<cstdio>    //注意：1.数组清零 
#include<cstring>
#define maxl 500+5

string a1,b1;
unsigned short a[maxl],b[maxl],c[maxl+1];//至少c[maxl+1] 
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

void CalcPlus()
{
	memset(c,0,sizeof(c));//必须 
    l=max(la,lb);
    for(int i=1;i<=l;i++)
    {
    	c[i]+=a[i]+b[i];
    	c[i+1]+=c[i]/10;c[i]%=10;//进位 
	}
	if(c[l+1]>0)
	  l++;
}

int main()
{
	cin>>a1>>b1;
	
	init();//读入字符串a b并处理成数 
    CalcPlus(); 
	void PrintOut();PrintOut(); 
	
	return 0;
}

void PrintOut()
{
	for(int i=l;i>=1;i--)
	  cout<<c[i];
	cout<<endl; 
}
