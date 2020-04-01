#include<iostream>//宽度优先搜索 时间复杂度？？？ 
using namespace std;//基本思想:从起点开始拓展子节点，以宽度优先一层一层拓展，直至到达目标节点成为子节点 
#include<cstdio>
//例子：倒水问题 
#define maxn 5000000+10000

int x,y,z;
struct queue
{
	int x;
	int y;
	int step;
}q[maxn];//宽搜搭配的数据结构-队列 
int head=1,rear=1;
int book[101][101]={0};//宽搜记得要判重(宽搜多数情况都要判重，深搜则有时可不用) 

int movex(int i)
{
	if(i==1)
	  if(q[head].x==x)
	    return -1;
	  else
	    return x;
	if(i==2)
	  return q[head].x;
	if(i==3)
	  if(q[head].x==0)
	    return -1;
	  else
	    return 0;
	if(i==4)
	  return q[head].x;
    if(i==5)
      if(y-q[head].y>=q[head].x)
        return 0;
      else
        return q[head].x-(y-q[head].y);
	if(i==6)
	  if(x-q[head].x>=q[head].y)
	    return q[head].x+q[head].y;
	  else
	    return x;
}	
	
int movey(int i)
{
	if(i==1)
	  return q[head].y;
	if(i==2)
	  if(q[head].y==y)
	    return -1;
	  else
	    return y;
	if(i==3) 
	  return q[head].y;
	if(i==4)
	  if(q[head].y==0)
	    return -1;
      else
        return 0;
	if(i==5)
	  if(y-q[head].y>=q[head].x)
	    return q[head].y+q[head].x;
	  else
	    return y;
	if(i==6)
	  if(x-q[head].x>=q[head].y)
	    return 0;
	  else
	    return q[head].y-(x-q[head].x);
}

int main()
{
	//cin>>x>>y>>z;
	x=3,y=22,z=1;
	
	q[rear].x=0;//设置起点 
	q[rear].y=0;
	q[rear].step=0;
	rear++;
	book[0][0]=1;//记录已访问该节点，用于判重 
	
	while(head<rear)
	{
		
		//cout<<head<<" "<<rear<<endl;
		
		int i;
		int tx,ty;
		for(i=1;i<=6;i++)//拓展子节点 
		{
			tx=movex(i);
			if(tx==-1)
			  continue;
	        ty=movey(i);
	        if(ty==-1)
			  continue;
			  
			if(book[tx][ty]==1)//判重 
			  continue;  
	        
	        q[rear].x=tx;
	        q[rear].y=ty;
	        q[rear].step=q[head].step+1;
	        rear++;
	        
	        book[tx][ty]=1;
	        
	        if(q[rear-1].x==z||q[rear-1].y==z)//检查是否已到达目标节点 
	        {
				cout<<q[rear-1].step<<endl;
				getchar();getchar();
	            return 0;
			}
		}/**/
		head++;//父节点已拓展完毕，出队（才能继续拓展下一个父节点） 
	}
	
	cout<<"impossible"<<endl;
	
	getchar();getchar();
	return 0;
}
