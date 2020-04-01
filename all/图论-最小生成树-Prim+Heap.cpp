#include<iostream>//Dijkstra算法 队列优化 
using namespace std;//优化：优先队列，大大加快了查找最小估计值的速度，由N变为logN(自己画画函数图像就知道快了多少) 
#include<cstdio>
#define inf 999999999
#include<queue>//优先队列头文件 

int u[101],v[101],w[101];
int first[101],next[101];

int dis[101];
//优先队列优化后是不需要book的，因为book是用于区分P和Q，而优先队列优化后，优先队列q就是Q 
//再说了，优化前book基本作用于查找估计值中的最小值，现在都不用找了，book就更加不需要了 

struct number//优先队列的结构体
{
	int num;//
	int w;//
	bool operator < (const number &a) const//重载运算符 
	{//
		return w>a.w;//使得按权值由小到大排队 
	}//
};//

priority_queue<number>q;//定义优先队列 

int main()
{
	
	freopen("di.in","r",stdin);
	
	int n,m,i,j,k;
	cin>>n>>m;
	
	for(i=1;i<=n;i++)
	  first[i]=-1;
	
	for(i=1;i<=n;i++)
	  dis[i]=inf;
	
	int point=1;//默认源点为顶点1 
	for(i=1;i<=m;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
		next[i]=first[u[i]];
	    first[u[i]]=i;
	    
	    if(u[i]==point)
	    {
	    	dis[v[i]]=w[i];
	    	
	    	struct number x;//该点与源点直接连通，将该连通边加入优先队列 
	    	x.num=v[i];//
	    	x.w=w[i];//
	    	q.push(x);//
	    }
	      
	}
	
	dis[point]=0;
	
    while(!q.empty())//当还有估计值边时(Q集合不空时)执行循环 
    {
	  struct number x=q.top();//弹出估计值离源点最近的顶点 
	  q.pop();//
	  
	  if(x.w!=dis[x.num])//由于每次拓展顶点都会有松弛，而松弛必然导致同一个顶点多次入队。解决这个问题的方法就是利用dis的 
	    continue;        //查新性(即dis中的值必定是最新的) ，以此回避掉多余的元素 
	  
	  int k=first[x.num];
	  while(k!=-1)
	  {
	    if(dis[v[k]]>dis[u[k]]+w[k]) //写错了！！dis[v[k]]>w[k] 
	    {
	      dis[v[k]]=dis[u[k]]+w[k];//写错了！！dis[v[k]]=w[k] 
		  if(dis[v[k]]<inf)//每次松弛后由于一些顶点对源点的估计值更新，要入队(至于重复入队问题上面已解决)	
		  {                //记住别让inf这些没必要入队的入队。至于book就不需要存在了，原因见上 
			struct number y;//
			y.num=v[k];//
			y.w=dis[v[k]];//
			q.push(y);//
		  }//
	    } 
	    k=next[k];
	  }	
	} 
	
	for(i=1;i<=n;i++)
	  cout<<dis[i]<<" ";
	
	getchar();getchar();
	return 0;
}
