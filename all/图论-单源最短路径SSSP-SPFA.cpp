#include<iostream>//SPFA(Shortest Path Faster Algorithm):Bellman-Ford的队列优化 
using namespace std;//基本思路：有点像宽搜，层层递进松弛各边，不过一个顶点允许多次入队，因为显然若该顶点最短路径被修改则它的出边顶点及后续各 
#include<cstdio>    //顶点最短路径也会变化(变短)，故需要再次入队修改后续节点。 
                    // 相比Bellman-Ford优点在于每次宽度优先拓展是不再是遍历所有的边而是充分利用邻接表里的拉链来拓展顶点的孩子 
#define inf 999999999 

int dis[101];
int u[101],v[101],w[101];
int first[101],next[101];

int book[101];

int q[101];
int head=1,rear=1;

int main()
{
	freopen("be2.in","r",stdin);
	freopen("be2.out","w",stdout);
	
	int n,m,i;
	cin>>n>>m;
	
	int point=1;
	for(i=1;i<=n;i++)
	{  
		first[i]=-1;
		book[i]=0;
		dis[i]=inf;
    }
    dis[point]=0;

	for(i=1;i<=m;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
		
		next[i]=first[u[i]];
		first[u[i]]=i;
    }
	
	q[rear]=point;
	book[point]=1;
	rear++;
	
	while(head<rear)
	{
		int p=first[q[head]];
		
		while(p!=-1)
		{
			if(dis[v[p]]>dis[u[p]]+w[p])
			{
				dis[v[p]]=dis[u[p]]+w[p];
				if(book[v[p]]==0)
				{
					book[v[p]]=1;
					q[rear]=v[p];
				    rear++;
				}
			}
			p=next[p];
			
		}
		head++;
		book[q[head]]=0;//顺序错了？ 
	}
	
	for(i=1;i<=n;i++)
	  cout<<dis[i]<<" ";
	
	getchar();getchar();
	return 0;
}
