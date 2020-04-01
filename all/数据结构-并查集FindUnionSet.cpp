#include<iostream>//并查集  O(logN) 
using namespace std;//作为一种数据结构，并查集有且只有两种操作：合并集合和检索元素所属集合 
#include<cstdio> 

int f[101];

int getf(int v)//查 
{
	if(f[v]==v)//若自己的根节点就是自己则显然该节点是该树的根 
	  return v;
	else
	{
		f[v]=getf(f[v]);//顺藤摸瓜找下去，这里还有路径压缩可以加速后面的查找
		return f[v];
	}
} 

void merge(int u,int v)
{
	int t1=getf(u);//查 
	int t2=getf(v);//查 
	if(t1!=t2)//若两个节点根相同则不用再合并
	{
		f[t2]=t1;//靠左法则 
	} 
} 

int main()
{
	
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	
	int n,m,i,j,k;
	cin>>n>>m;
	
	for(i=1;i<=n;i++)//初始化 
	  f[i]=i;
	  
	int x,y;
	for(i=1;i<=m;i++)//并 
	{
		cin>>x>>y;
		merge(x,y);
	} 
	
	int sum=0;
	for(i=1;i<=n;i++) 
	  if(f[i]==i)
	    sum++;
    cout<<sum<<endl;
	
	getchar();getchar();
	return 0;
}
