using namespace std;//Kahn拓扑排序（邻接表） O(N+M)
#include<iostream>  //用线性的数据结构(queue,stack,vector等都可以)记录入度=0的点，然后开始循环： 
#include<cstdio>    //弹出数据结构中的首点，标记已访问，cnt++，查找与之相连的点，若点i未访问, 
#include<cstring>   //令其入度-1；若i入度-1后=0，令其加入数据结构； 
#include<queue>     //循环直至数据结构空，若cnt！=n说明有顶点无法拓扑，即图中存在有向环 
#define maxn 1000+10
#define maxm maxn*maxn

int n,m,cnt;
int /*e[maxn][maxn],*/u[maxm],v[maxm],first[maxn],next[maxm],InDegree[maxn],book[maxn];
queue<int>q; 

int main()
{
	void init();init();
	
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int x,y;cin>>x>>y;
		u[i]=x,v[i]=y;//<-不同处 
		next[i]=first[u[i]],first[u[i]]=i;//<-不同处 
		InDegree[y]++;
	}
	
	for(int i=1;i<=n;i++)
	  if(InDegree[i]==0)
	  	q.push(i);
	
	cnt=0;
	while(!q.empty())
	{
		int t=q.front();q.pop();cout<<t<<" ";
		cnt++;
		book[t]=1;
		
		/*for(int i=1;i<=n;i++)
		  if(e[t][i]==1&&book[i]==0)
		  {
		  	InDegree[i]--;
		  	if(InDegree[i]==0)
		  	  q.push(i);
		  }*/
		int k=first[t];//<-不同处 
		while(k!=-1)
		{
			if(book[v[k]]==0)
			{
				InDegree[v[k]]--;
				if(InDegree[v[k]]==0)
				  q.push(v[k]);
			}
			k=next[k];
		}//<-不同处 
	}
	cout<<endl;
	
	if(cnt==n)
	  cout<<"No Circles"<<endl;
	else
	  cout<<"Has Circle(s)"<<endl;
	
	return 0;
}

void init()
{
	//memset(e,0,sizeof(e));
	memset(InDegree,0,sizeof(InDegree));
	memset(book,0,sizeof(book));
	memset(first,-1,sizeof(first));//<-不同处  
	return;
}
