#include<iostream>//高-高 O(max(lenA,lenB)) 
using namespace std;//没什么神奇的，就是模拟手算减法，可以优化为逢10000进 
#include<cstdio>    //注意：1.数组清零 
#include<cstring>   //      2.减法结束后while更新位长 
#define maxl 500+5  //      3.结果是负数、0的处理 
                    //      4.由于要借位，故不能unsigned 
string a1,b1;
short a[maxl],b[maxl];//直接在a/b上减，不能unsigned！！！ 
int la,lb,l,fuhao;

void init()
{
	la=a1.length();lb=b1.length();
	memset(a,0,sizeof(a));memset(b,0,sizeof(b));//必须 
	for(int i=0;i<la;i++)
	  a[i+1]=a1[la-1-i]-'0';
	for(int i=0;i<lb;i++)
	  b[i+1]=b1[lb-1-i]-'0';
}

void CalcMinus1()
{
	l=la;
    for(int i=1;i<=l;i++)
    {
    	if(a[i]<b[i])
		{
			a[i+1]--;
			a[i]+=10; 
		} 
		a[i]-=b[i];
	}
	while(a[l]==0)
	  l--;
}

void CalcMinus2()
{
	l=lb;
    for(int i=1;i<=l;i++)
    {
    	if(b[i]<a[i])
		{
			b[i+1]--;
			b[i]+=10; 
		} 
		b[i]-=a[i];
	}
	while(b[l]==0)//while!!
	  l--;
}

int main()
{
	cin>>a1>>b1;
	
	init();//读入字符串a b并处理成数 
	fuhao=1;//负数处理 
	if(la<lb||(la==lb&&a1<b1))
      fuhao=-1;
	if(fuhao==-1)
	  CalcMinus2();
	else
      CalcMinus1(); 
	void PrintOut();PrintOut(); 
	
	return 0;
}

void PrintOut()
{
	if(l==0)//零处理 
	{
		cout<<"0"<<endl;
		return;
	}
	if(fuhao==-1)//负数处理 
	{
	  cout<<"-";
	  for(int i=l;i>=1;i--)
	    cout<<b[i];
	}
	else
	{
	  for(int i=l;i>=1;i--)
	    cout<<a[i];
	}
	cout<<endl; 
}
