using namespace std;//Astart算法 O(比BFS、DoubleBFS一般都小很多，主要取决于H函数) 
#include<iostream>//Astart算法在BFS的基础上通过评估函数实现优化，评估函数f(i)=g(i)+h(i) 
#include<cstdio>  //其中g(i)描述当前状态距离起点的离散度，h(i)描述当前状态距离终点的离散度，h(i)又称启发函数 
#include<cstring> //类似于Dijkstra(f(i)>=0)，选择open表中f(i)最小的加入closed表，该状态的解从估计变为确定 
#include<cstdlib> //然后再从该状态进行扩展：扩展节点1.如果扩展到的状态在closed中则跳，因为该状态的解已经确定了；
#include<queue>   //2.如果不在closed中&&不在open中则添加进open；3.如果在open中则看能否松弛f(有时会是g/h，未必f) 
#include<set>     //能就松弛否则跳。
#define inf 999999999//解的正确性基于两条：1.定理：如果h*(i)是中间节点i到目标节点的实际费用，h(i)是估计费用，如果
                    //                      对于 任何 节点i都有h(i)<=h*(i)&&g(start)=h(end)=0，则用估价函数f(i)=g(i)+h(i)一定可以得到最优解。 
                    //                     2.f(i)>=0下松弛三角形关系成立 
int n,m,sx,sy,ex,ey,e[10][10];
int num[10][10],f[10*10],pre[10*10];
//num给地图中的点编号(自变量是坐标，因变量是编号)，f是该点对应F函数(自变量是该点编号)，pre记录前驱节点(自变量是当前点编号) 
//由于后面涉及到优先队列中的点的f更新，所以做好映射和反映射(num和fnum不是必需，不做亦可，可以有其他方式实现相同功能) 
int next[5][5]={{0,1},{1,0},{0,-1},{-1,0}};

struct fnum//num的反映射(自变量是编号，因变量是编号) 
{ int x,y; }fnum[10*10];
struct node
{ 
  int x,y;
  int step;
  int g,h;//G函数和H函数。对于迷宫问题，G一般用step来描述(起点到状态的距离)，H则可以用曼哈顿距离（常用）、欧式距离、切尔雪夫距离等 
  bool operator < (const node &a) const
  { return (a.g+a.h)<(g+h); }
};

priority_queue<node>open;//open表 
int closed[10][10];//closed表，视不同情况也可以用set、map等 
int inq[10][10];//标记是否进过/了队 

int mht(int x1,int y1,int x2,int y2)//求曼哈顿路径 
{ return abs(x1-x2)+abs(y1-y2); }

int main()
{
	freopen("Astart.in","r",stdin);
	
	void init();init();
	cin>>n>>m;
    int cnt=0;
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=m;j++)
	  {
	  	char t;cin>>t;
	  	if(t=='1')
	  		e[i][j]=1;
		else
		{
			cnt++;
			num[i][j]=cnt;fnum[cnt].x=i,fnum[cnt].y=j;
			pre[cnt]=-1,f[cnt]=inf;
		    if(t=='c')
	  		  sx=i,sy=j;
	  	    else if(t=='b')
	  		  ex=i,ey=j;
		}  
	  }
	
	struct node t;
	t.x=sx,t.y=sy;
	t.step=0;
	t.g=0,t.h=mht(sx,sy,ex,ey);f[num[sx][sy]]=t.g+t.h;
	open.push(t);
	inq[sx][sy]=1;
	
	while(!open.empty())
	{
		struct node t=open.top();
		
		while(!open.empty()&&f[num[t.x][t.y]]!=t.g+t.h)
		{ open.pop();t=open.top(); }
		open.pop();closed[t.x][t.y]=1;//加入closed表，值已确定 
		//必需先弹掉再扩展节点，因为节点进入优先队列后就会进行排序，pop的对象front就可能不是这个点了，可能pop错点 
		
		for(int i=0;i<=3;i++)
		{
			int dx=t.x+next[i][0];
			int dy=t.y+next[i][1];
			if(e[dx][dy]==1||dx<1||n<dx||dy<1||m<dy)
			  continue;
			if(closed[dx][dy]==1)//已在closed表中，是确定值，不再修改(就算不continue也没办法再松弛。。) 
			  continue;
			
			int dg=t.g+1;
			int dh=mht(dx,dy,ex,ey);
			if(inq[dx][dy]==1)//如果在队中 
			{
				if(dg+dh<f[num[dx][dy]])//可以松弛 
				  ;
				else
				  continue;
			}
			
			f[num[dx][dy]]=dg+dh;
			
			struct node v;
			v.x=dx,v.y=dy;
			v.step=t.step+1;
			v.g=dg,v.h=dh;
			open.push(v);inq[dx][dy]=1;
			//cout<<v.g<<" "<<v.h<<" "<<dx<<","<<dy<<endl;
			pre[num[dx][dy]]=num[t.x][t.y];
			
			if(dx==ex&&dy==ey)//倒序输出路径 
			{
				cout<<v.step<<endl;
				int k=num[dx][dy];
				while(k!=-1)
				{
					cout<<"("<<fnum[k].x<<","<<fnum[k].y<<") <- ";
					k=pre[k];
				}
				cout<<"start"<<endl;
				return 0;
			}/**/
		}
	}
    
	return 0;
}

void init()
{
	memset(e,0,sizeof(e));
	memset(num,0,sizeof(num));
	memset(fnum,-1,sizeof(fnum));
	while(!open.empty())
	  open.pop();
	memset(closed,0,sizeof(closed));
}

