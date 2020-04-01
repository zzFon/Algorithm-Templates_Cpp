#include<iostream>//匈牙利算法  O（NM） 
using namespace std;//基本思想:枚举其中一边的顶点，对每一个进行测试看该顶点是否可以成功匹配若成功总匹配+1。测试顶点是否可以成功匹配：DFS(注意判重)
#include<cstdio>    //搜索与顶点相连的边，查看本次DFS中未访问过的顶点是否允许匹配，允许匹配条件：1.该顶点未匹配 或 2.该点可以连锁反应（也是DFS判断） 
#include<cstring>//memset()

int book[101];//用于DFS是判重
int match[101];//用于记录匹配关系
int sum=0;//最大匹配（数）的累加器
int e[101][101];

int n,m;

int dfs(int u)
{
	int i;
	for(i=1;i<=n;i++)//枚举顶点进行遍历 
	{
		if(e[u][i]==1&&book[i]==0)//若该点与当前点连通且未被遍历
		{
			book[i]=1;
			if(match[i]==0||dfs(match[i])==1)//若该点还没有匹配或者可以产生连锁反应则当前点可以与之匹配
			{
				match[i]=u;
				match[u]=i;
				return 1;//返回匹配成功 
			}
			
		}
	}
	return 0;//返回匹配失败
} 

int main()
{
    int i,j,k;
	cin>>n>>m;
	
	for(i=1;i<=m;i++)	
	{
		int x,y;
		cin>>x>>y;
		e[x][y]=1;
		e[y][x]=1;
	}
	
	memset(match,0,sizeof(match));//初始化匹配数组 
	sum=0;
	for(i=1;i<=n;i++)//枚举其中一边的顶点进行匹配(根据二分图的性质可知只需枚举匹配其中一边的顶点)
	{
		memset(book,0,sizeof(book));//在下一个顶点匹配前，要将用于DFS判重的book清0
		if(dfs(i)==1)//如果该点匹配成功，最大匹配+1 
		  sum++;
	} 
	
	cout<<sum<<endl;
	
	getchar();getchar();
	return 0;
}
