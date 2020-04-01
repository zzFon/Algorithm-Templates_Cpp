#include<iostream>
using namespace std;
#include<cstdio>

int q[101],head=1,rear=1;
int a[11]={0,1,2,3,4,5};

int main()
{
	for(int i=1;i<=5;i++)
	{
		q[rear]=a[i];
		rear++;
	}
	
	for(int i=head;i<rear;i++)
	  cout<<q[i]<<" ";
	cout<<endl;
	
	q[rear]=6;
	rear++;
	
	for(int i=head;i<rear;i++)
	  cout<<q[i]<<" ";
	cout<<endl;
	
	if(head<rear-1)
	  head++;
	
	for(int i=head;i<rear;i++)
	  cout<<q[i]<<" ";
	cout<<endl;
	
	cout<<q[head]<<endl;
	
	getchar();getchar();
	return 0;
}
