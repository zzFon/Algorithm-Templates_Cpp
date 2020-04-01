#include<iostream>//Floyd-Warshall算法 O(N3) 
using namespace std;//基本思想：将每一个节点作为中继点枚举，松弛各点之间的距离 
#include<cstdio>
#define inf 999999999

int tu[101][101];

int main()
{
	
	freopen("Floyd.in","r",stdin);
	freopen("Floyd.out","w",stdout);
	
    int i,j;//初始化邻接矩阵 
	for(i=1;i<=100;i++)
	  for(j=1;j<=100;j++)
	    if(i==j)
	      tu[i][j]=0;
	    else
	      tu[i][j]=inf;	
	
    int n,m,x,y,z;
    cin>>n>>m;//读入顶点数n边数m 
    for(i=1;i<=m;i++)//读入各边 
    {
		cin>>x>>y>>z;
		tu[x][y]=z;
	}
	
	int k;//Floyd-Warshall松弛 
	for(k=1;k<=n;k++)
	  for(i=1;i<=n;i++)
	    for(j=1;j<=n;j++)
	      if(tu[i][j]>tu[i][k]+tu[k][j])//或：tu[i][j]=min(tu[i][j],tu[i][k]+tu[k][j]); 
	        tu[i][j]=tu[i][k]+tu[k][j];
	
	cin>>x>>y;
	cout<<tu[x][y]<<endl;
	
	getchar();getchar();
	return 0;
}
