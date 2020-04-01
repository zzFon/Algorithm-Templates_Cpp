#include<iostream>
using namespace std;
#include<cstdio>

struct BiTree//自创三叉链表 
{
	char data;
	int left,right;
	int parent;
}t[101];
int n=0;

char q[101];
int head=1,rear=1;

void CreateTree()
{
	int i,j,k;
	int num;
	cin>>num;
	
	char father,node;
	int Type;
	n=0;
	for(i=1;i<=num;i++)
	{
		cin>>father>>node>>Type;
		if(father=='#')
		{
			n++;
			t[n].data=node;
			t[n].left=-1;
			t[n].right=-1;
			t[n].parent=-1;
        }
        else
        {
			n++;
			t[n].data=node;
			t[n].left=-1;
			t[n].right=-1;
			t[n].parent=-1;
			for(j=1;j<n;j++)
			  if(t[j].data==father)
			    break;
			t[n].parent=j;
			if(Type==1)
			  t[j].left=n;
			else
			  t[j].right=n;
		}/**/
	}
}

void PreOrder(int root)
{
	if(root>n||root==-1)
	  return;
	else
	{
		cout<<t[root].data;
		PreOrder(t[root].left);
		PreOrder(t[root].right);
	}
} 

void InOrder(int root)
{
	if(root>n||root==-1)
	  return;
	else
	{
		InOrder(t[root].left);
		cout<<t[root].data;
		InOrder(t[root].right);
	}
}		

void PostOrder(int root)
{
	if(root>n||root==-1)
	  return;
	else
	{
		PostOrder(t[root].left);
		PostOrder(t[root].right);
		cout<<t[root].data;
	}
} 

void LevelOrder(int root)
{
	q[rear]=t[root].data;
	head=root;
	rear++;
	while(head<rear)
	{
		if(t[head].left!=-1)
		{
		  q[rear]=t[t[head].left].data;
		  rear++;
		}
		if(t[head].right!=-1)
		{
		  q[rear]=t[t[head].right].data;
		  rear++;
		}
		cout<<q[head];
		head++;
	}
}

int main()
{
	freopen("Bitree.in","r",stdin);
	freopen("Bitree.out","w",stdout);
	
	CreateTree();//利用三叉链表建立二叉树 
	
	PreOrder(1);//先序遍历 
	cout<<endl;
	
	InOrder(1);//中序遍历
	cout<<endl;
	
	PostOrder(1);//后序遍历 
	cout<<endl;
	
	LevelOrder(1);//层次遍历 
	cout<<endl;
	
	getchar();getchar();
	return 0;
}
