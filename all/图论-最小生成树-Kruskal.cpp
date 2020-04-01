#include<iostream>//Kruskal的按秩压缩优化 O（MlogM） 
using namespace std;//优化：实际上是优化并查集，利用按秩压缩提高合并效率，所谓按秩压缩是指给每个并查集的头头记录该集合元素数， 
#include<cstdio>    //合并时把元素少的合并到多的出，提高效率 
#include<algorithm>

struct edge
{
	int u;
	int v;
	int w;
}e[101];

struct f
{
  int father;
  int rank;//添加优化元素：秩 
}f[51];

bool cmp(struct edge a,struct edge b)
{
	return a.w<b.w;
}

int getf(int v)
{
	if(f[v].father==v)//
	  return f[v].father;//
	else
	{
		f[v].father=getf(f[v].father);//
		return f[v].father;//
	}
}

int merge(int u,int v)
{
	int t1=getf(u);
	int t2=getf(v);
	if(t1==t2)
	  return 0;
	else
	{
		if(f[t1].rank>=f[t2].rank)//按秩压缩，提高合并效率 
		{
			f[t2].father=t1;//
			f[t2].rank+=f[t1].rank;//
		}//
		else//
		{
			f[t1].father=t2;//
			f[t1].rank+=f[t2].rank;//
		}//
		return 1;
	}
}

int main()
{
	freopen("Kruskal.in","r",stdin);
	freopen("Kruskal2.out","w",stdout);
	
	int i,j,k,n,m;
	cin>>n>>m;
	
	for(i=1;i<=n;i++)
	{
	   f[i].father=i;// 
	   f[i].rank=1;//初始化秩 
    }  
	  
	for(i=1;i<=m;i++)
	  cin>>e[i].u>>e[i].v>>e[i].w;
	
	sort(e+1,e+1+m,cmp); 
	
	int sum=0;
	int cnt=0;
	for(i=1;i<=m;i++)
	{
		if(merge(e[i].u,e[i].v))
		{
		  sum+=e[i].w;
		  cnt++;
		}
		if(cnt==n-1)
		  break;
	}
	
	cout<<sum<<endl;		
	
	getchar();getchar();
	return 0;
}
