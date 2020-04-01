using namespace std;//TarjanÁÚ½Ó±í O(N+M)
#include<iostream>
#include<cstdio>
#include<cstring>

int n,m;
int first[10+5],next[20+5],u[20+5],v[20+5];
int ix,root,flag[10+5],num[10+5],low[10+5];

void tarjan(int cur,int father)
{
	int child=0;
	
	ix++;	 
	num[cur]=ix,low[cur]=ix;
    
    int k=first[cur];
    while(k!=-1)
    {
    	if(num[v[k]]==0)
    	{
    		child++;
    		tarjan(v[k],cur);
			low[cur]=min(low[cur],low[v[k]]);
			
			if(cur!=root&&low[v[k]]>=num[cur])
			  flag[cur]=1;
			if(cur==root&&child>1)
			  flag[cur]=1;
		}
		else if(v[k]!=father)
		  low[cur]=min(low[cur],num[v[k]]);
    	k=next[k];
	}
	
}

int main()
{
	freopen("Tarjan.in","r",stdin);
    memset(first,-1,sizeof(first));
	memset(flag,0,sizeof(flag));
	
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int x,y;cin>>x>>y;
		u[i]=x,v[i]=y;
		next[i]=first[u[i]],first[u[i]]=i;
	}
	for(int i=m+1;i<=2*m;i++)
	{
		u[i]=v[i-m],v[i]=u[i-m];
		next[i]=first[u[i]],first[u[i]]=i;
	}
	
	ix=0,root=1;
	tarjan(1,root);
	
	for(int i=1;i<=n;i++)
	  if(flag[i]==1)
	    cout<<i<<" ";
	cout<<endl; 
	
	return 0;
}
