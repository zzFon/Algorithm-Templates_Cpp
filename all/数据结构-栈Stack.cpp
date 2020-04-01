#include<iostream>
using namespace std;
#include<cstdio>

int s[101];
int top=1;
int a[11]={0,1,2,3,4,5};

int main()
{
	for(int i=1;i<=5;i++)
    {
		s[top]=a[i];
		top++;
	}
	
	for(int i=1;i<top;i++)
	  cout<<s[i]<<" ";
	cout<<endl;
	
	if(top>1)
	  top--;
	  
	for(int i=1;i<top;i++)
	  cout<<s[i]<<" ";
	cout<<endl; 
	
	s[top]=6;
	top++;
	
	for(int i=1;i<top;i++)
	  cout<<s[i]<<" ";
	cout<<endl; 
	
	cout<<s[top-1]<<endl;
	
	getchar();getchar();
	return 0;
}
