#include<iostream>//深度优先搜索  O(Xn)  
using namespace std;//基本思想：深度优先，不断向下搜索直至边界，然后回溯，再访问回溯后节点层下一节点 
#include<cstdio>
#include<cmath>
//例子：N皇后问题 

int ans=0;
int n;	
int sel[14]={0};
		
int check(int deep)
{
	int i;
	for(i=1;i<=deep-1;i++)//遍历已放置的皇后 
	  if(sel[i]==sel[deep]||abs(i-deep)==abs(sel[i]-sel[deep]))//检查是否同列 是否同斜线（显然不可能同行） 
	    return 0;
	return 1;
}

void dfs(int deep)
{
	if(deep>n)
	  ans++;
	else
	{
		int i;
		for(i=1;i<=n;i++)//为当前deep层放置皇后 
		{
			sel[deep]=i;
			if(check(deep))//检查是否有冲突 
			  dfs(deep+1);
		}
	}
}
			
int main()
{
	cin>>n;
	
	ans=0;
	dfs(1);
	
	cout<<ans<<endl;
	
	getchar();getchar();
	return 0;
}
