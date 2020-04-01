using namespace std;//最近公共祖先Tarjan离线算法(邻接表)->O(N*N+M=M+N2) 其实邻接矩阵和邻接表貌似差不了多少。差别只是系数级。。 
#include<iostream>  //要好好体会并查集在这里的强大利用 
#include<cstdio>
#include<cstring>
#define maxn 10+5
#define maxm maxn-1//树：边数=点数-1 

int n,NumOfQuestion,rt;
int /*e[maxn][maxn],*/first[maxn],next[maxm],u[maxm],v[maxm],ans[maxn],SonOrNot[maxn];
int ancestor[maxn],book[maxn]; 

struct question
{
	int num,qt;
}question[maxn][maxn];
struct f
{
	int rank,father;
}f[maxn];

void TarjanLCA(int root)
{
    void merge(int u,int v);int getf(int v);
    
	ancestor[root]=root;
	book[root]=1;
	
	/*for(int i=1;i<=n;i++)
	  if(e[root][i]==1&&book[i]==0)
	  {
	  	TarjanLCA(i);//遍历子树 
	  	merge(root,i);//子树遍历完毕，父子合集 (并查集)<-----------------------两个语句密不可分,否则可能导致回答不正确 
	  	ancestor[getf(i)]=root;//标记该集(并查集)的最近祖先：当前节点<---------
	  }*/
	int k=first[root];//<-不同处 
	while(k!=-1)
	{
		if(book[v[k]]==0)
		{
			TarjanLCA(v[k]);
			merge(root,v[k]);
			ancestor[getf(v[k])]=root;
		}
		k=next[k];
	}//<-不同处 
	
	for(int i=1;i<=n;i++)
	  if(question[root][i].qt==1&&book[i]==1)//回答有关当前节点的询问 
	  	ans[question[root][i].num]=ancestor[getf(i)];//自己意会吧 参考几个博客： http://blog.csdn.net/hnust_xiehonghao/article/details/9109295
	                                                 //                          (->这个给出的code貌似不对)http://www.cnblogs.com/ylfdrib/archive/2010/11/03/1867901.html 
	                                                 //                          http://alanyume.com/130.html
	return;
}

int main()
{
	freopen("TarjanLCA.in","r",stdin);
	void init();init();
	
	cin>>n;
	for(int i=1;i<=n-1;i++)
	{
		int x,y;cin>>x>>y;//输入的边一定是"向量式"（x父->y子），否则无法确定这棵树 
		//e[x][y]=e[y][x]=1;
		u[i]=x,v[i]=y;//<-不同处 
		next[i]=first[u[i]],first[u[i]]=i;//<-不同处（由于边是"向量式",故不用再进行"无向处理"） 
		SonOrNot[y]=1;//寻找根节点 
	}
	cin>>NumOfQuestion;
	for(int i=1;i<=NumOfQuestion;i++)//TarjanLCA是离线算法，先记录下所有询问 
	{
		int x,y;cin>>x>>y;
		question[x][y].qt=question[y][x].qt=1;
		question[x][y].num=question[y][x].num=i;//询问顺序 
	}

	for(int i=1;i<=n;i++)
	{
	  f[i].father=i,f[i].rank=1;
	  if(SonOrNot[i]==0)
	    rt=i;
    }
    	
	TarjanLCA(rt);
	 
	for(int i=1;i<=NumOfQuestion;i++)
	  cout<<ans[i]<<endl;/**/
	
	return 0;
}

void init()
{
	/*memset(e,0,sizeof(e));*/
	memset(question,0,sizeof(question));
	memset(ans,-1,sizeof(ans));
	memset(SonOrNot,0,sizeof(SonOrNot));
	memset(book,0,sizeof(book));
	memset(first,-1,sizeof(first));//<-不同处 
	return;
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
	int t1=getf(u),t2=getf(v);
	if(t1!=t2)
	{
		if(f[t1].rank>=f[t2].rank)
		  f[t2].father=t1,f[t1].rank+=f[t2].rank;
		else
		  f[t1].father=t2,f[t2].rank+=f[t1].rank;
	}
}
