#include<iostream>//KosarajuÀ„∑®  
using namespace std;
#include<cstdio>
#include<cstring>
#define maxn 51

int n,m;

int g[maxn][maxn];
int gr[maxn][maxn];
int book[maxn];

int time;
int a[maxn];

void dfs1(int cur)
{
	book[cur]=1;
	
	int i;
	for(i=1;i<=n;i++)
	  if(g[cur][i]==1&&book[i]==0)
	  	dfs1(i);

	time++;
	a[cur]=time;
}

void dfs2(int cur)
{
	book[cur]=1;
	
	cout<<cur<<" ";
	
	int i;
	for(i=1;i<=n;i++)
	  if(gr[cur][i]==1&&book[i]==0)
	  {
	  	dfs2(i);
	  }
}

int main()
{
	cin>>n>>m;
	
	memset(g,0,sizeof(g));
	memset(gr,0,sizeof(gr));
	memset(book,0,sizeof(book));
	
	int i;
	for(i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		
		g[x][y]=1;
		gr[y][x]=1;
	}
	
	int point=1;
	time=0;
	dfs1(point);
	  
	memset(book,0,sizeof(book));
	int max,maxpos;
	max=a[point];
	maxpos=point;
	while(maxpos!=-1)
	{
		max=-1;
		maxpos=-1;
		for(i=1;i<=n;i++)
		  if(a[i]>max&&book[i]==0)
		  {
		  	max=a[i];
		  	maxpos=i;
		  }
		if(maxpos!=-1)
		  dfs2(maxpos);	  
		cout<<endl;
	}
	
	getchar();getchar();
	return 0;
}
