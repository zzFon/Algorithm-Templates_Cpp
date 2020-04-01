#include<iostream>   //Tarjan割边算法  O(N+M)
using namespace std;//基本思想：如果一个顶点返祖后找到的顶点最小也比父节点要大，显然该顶点无法在不经过父节点的条件下回到祖先节点，故该路径为割边 
#include<cstdio>    //注意：割点中是：low[i]>=num[cur] ，只要能仔细分析“点”和“边”就能明白为什么 
#include<algorithm>//min()
#define N 51
#define M 101

int u[M],v[M];
int first[N];
int next[M];

int n,m;
int index;
int num[N];
int low[N];

void dfs(int cur,int father)
{
	index++;
	num[cur]=index;
	low[cur]=index;
	
	int k=first[cur];
	while(k!=-1)
	{
		if(num[v[k]]==0)
		{
			dfs(v[k],cur);
			low[cur]=min(low[cur],low[v[k]]);
			
			if(low[v[k]]>num[cur])//与割点算法只有此处不同，其他处均相同 
			  cout<<cur<<"-"<<v[k]<<endl;
		}
		else if(v[k]!=father)
		{
			low[cur]=min(low[cur],num[v[k]]);
		}
		
		k=next[k];
	}
}
	
int main()
{
	freopen("Tarjan2.in","r",stdin);
	freopen("Tarjan2-2.out","w",stdout);
	
	int i,j,k;
	cin>>n>>m;
	
	for(i=1;i<=n;i++)
	{
	  first[i]=-1;
	  num[i]=0;
	}
	
	for(i=1;i<=m;i++)
	{
		cin>>u[i]>>v[i];
		
		next[i]=first[u[i]];
		first[u[i]]=i;
    }
    for(i=m+1;i<=2*m;i++)
    {
		u[i]=v[i-m];
		v[i]=u[i-m];
		
		next[i]=first[u[i]];
		first[u[i]]=i;
	}
    
    int root=1;
    index=0;
    dfs(1,root);
	
	getchar();getchar();
	return 0;
}
