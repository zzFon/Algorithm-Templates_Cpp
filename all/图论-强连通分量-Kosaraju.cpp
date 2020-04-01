using namespace std;//强连通分量SCC(Strongly Connected Component)-Kosaraju算法 O(2*(N+M)) 
#include<iostream>  //对原图G进行一次DFS遍历，遍历时记录每个节点的"回溯时间截"(也可通过压栈实现) 
#include<cstdio>    //然后依据"回溯时间截"堆反图Gr进行DFS遍历，若u能到达v则说明u v强连通，利用并 
#include<cstring>  //查集进行合并，2次DFS遍历后便可以的到强连通分量组成的并查集组 
#include<stack>    //正确性证明：设p为节点的"回溯时间截"，由Kosaraju算法的操作，若第二次DFS中存在 
#define maxn 100+10 //u->v的一个遍历，那么必定满足以下2个条件: 
#define maxm 1000+10//1.对于原图G,存在u<-v  2.pu>pv 
                    //考察条件2，任意两个节点间存在条件2，当且仅当以下2种类情况：(对于原图G的DFS) 
int n,m,first[5][maxn],next[5][maxm],u[5][maxm],v[5][maxm],vis[maxn];
stack<int>s;       //1.v是以u为根的搜索树的非根节点  2.u与v不连通，且u所在的子图比v所在的子图晚遍历到 
struct node        //又因为反图GrDFS中有u<-v(条件1)，所以情况2不成立，只有情况1成立。 
{ int rank,father; }f[maxn];//综合 条件1、情况1知对于原图G有：u->v u<-v 即u v强连通 
void merge(int u,int v);    //又易证：u v强连通且v t强联通必有u t强连通，即u v t相互强连通(传递性) 
                            //故此Kosaraju算法的正确性得证 
void dfs(int t,int flag)
{
	/*if(flag==2) 
	  cout<<t<<" ";*/
	int k=first[flag][t];
    while(k!=-1)
    {
    	if(vis[v[flag][k]]==0)
    	{
    		if(flag==2)
    	      merge(u[flag][k],v[flag][k]);//cout<<"merge:"<<u[flag][k]<<"&"<<v[flag][k]<<endl;
    		vis[v[flag][k]]=1;
		    dfs(v[flag][k],flag);
		}
		k=next[flag][k];
	}
	if(flag==1)
	  s.push(t);//cout<<t<<" ";
	
	return;
}

int main()
{
	freopen("graph.in","r",stdin);
	
	cin>>n>>m;
	memset(first[1],-1,sizeof(first[1]));
	for(int i=1;i<=m;i++)
	{
		cin>>u[1][i]>>v[1][i];
		next[1][i]=first[1][u[1][i]];first[1][u[1][i]]=i;
	}
	
	//cout<<"backtrce index of dfs1:";
	memset(vis,0,sizeof(vis));//遍历正图G
	while(!s.empty()) s.pop(); 
	for(int i=1;i<=n;i++)
	{
		f[i].rank=1;f[i].father=i;//并查集用于合并强连通的点 
		if(vis[i]==0)
		{
			vis[i]=1;
		    dfs(i,1);
		}
	}//cout<<endl; 
	
	memset(first[2],-1,sizeof(first[2]));
	for(int i=1;i<=m;i++)//倒置正图G得到反图Gr 
	{
		u[2][i]=v[1][i];v[2][i]=u[1][i];
		next[2][i]=first[2][u[2][i]];first[2][u[2][i]]=i;
	}
	
	//cout<<"dfs2:"<<endl;
	memset(vis,0,sizeof(vis));//遍历反图Gr 
	while(!s.empty())
	{
		int i=s.top();
		if(vis[i]==0)
		{
			vis[i]=1;
		    dfs(i,2);
		}
		s.pop();
	}//cout<<endl;
	
	//cout<<"SCCs:"<<endl;
	for(int i=1;i<=n;i++)
		if(f[i].father==i)
		{
			for(int j=1;j<=n;j++)
			  if(f[j].father==i)
			    cout<<j<<" ";
			cout<<endl;
		}
	
	return 0;
}

int getf(int v)
{
	if(f[v].father==v)
	  return v;
	else
	{
		f[v].father=getf(f[v].father);
		return f[v].father;
	}
}

void merge(int u,int v)
{
	int t1=getf(u);
	int t2=getf(v);
	if(u!=v)
	{
		if(f[t1].rank>=f[t2].rank)
		{
			f[t2].father=t1;f[t1].rank+=f[t2].rank;
		}
		else
		{
			f[t1].father=t2;f[t2].rank+=f[t1].rank;
		}
	}
}
