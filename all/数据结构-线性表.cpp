#include<iostream>
using namespace std;

struct list
{
	int data;
	int next;
};

int a[11]={0,1,2,3,4,5}; 

int main()
{	
	struct list l[101];
	int head=1;
	
	for(int i=1;i<=5;i++)
	{
	  l[i].data=a[i];
	  l[i].next=i+1;
	}
	l[5].next=-1;
	
	int p=1;
	while(p!=-1)
	{
		cout<<l[p].data<<" ";
		p=l[p].next;
	}
	cout<<endl; 
	
	l[3].next=l[4].next;//É¾³ı4ºÅÔªËØ 
	
	p=head;
	while(p!=-1)
	{
		cout<<l[p].data<<" ";
		p=l[p].next;
	}
	cout<<endl; 
	
	l[6].data=4;//²åÈëÔªËØ4 
	l[3].next=6;
	l[6].next=5;
	
	p=head;
	while(p!=-1)
	{
		cout<<l[p].data<<" ";
		p=l[p].next;
	}
	cout<<endl; 
	
	p=head;//²éÕÒÔªËØ3 
	while(p!=-1)
	{
		if(l[p].data==3)
		{
		  cout<<p<<endl;
		  break;
	    }
	    p=l[p].next;
	}
		
	
	getchar();getchar();
	return 0;
}
