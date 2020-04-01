#include<iostream>//二分答案  O(logN) 
using namespace std;//基本思想：根据所给条件确定所求答案所在区间范围，即求出左界和右界，然后不断二分该区间直直区间完全被二分（当区间完全被二分   
#include<cstdio>    //，易证实际上整个区间的所有可能答案都已经被遍历或淘汰，且二分过程中总是朝着最优解前进的，所以区间二分完毕后保留下来的ans
                    //即为所求）。所以说，其实二分答案是一种分厂非常非常非常非常非常非常非常非常非常高效的枚举 
//例子：给定一个元素个数为n的数列进行分组，最大分组数为m，求分组使得最大元素和最小 

int n,m;
int a[100001];
int ans;

int check(int ans)//检查当前的答案是否满足条件 
{
  int tot=0,i,k=0;
  for(i=1;i<=n;i++)
  {
    if(tot+a[i]<=ans)
    {
		tot+=a[i];
    }
    else
    {
		tot=a[i];
		k++;
	}
  }
  if(tot>0)
    k++;
  
  if(k<=m)
    return 1;
  else 
    return 0;
}

int main()
{
	freopen("salary.in","r",stdin);
	freopen("salary.out","w",stdout);
	
	int i,j,k;
	cin>>n>>m;
	
	int sum=0;
	int max=0;
	for(i=1;i<=n;i++)//读入元素，同时记录元素最大值（左界）和元素和（右界） 
	{
	  cin>>a[i];
	  
	  sum+=a[i];
	  if(a[i]>max)
	    max=a[i];
    }
	
    int left,right;//由于所求为：最大元素和的最小值 ，所以易得答案所在区间： 
    left=max; //左界为元素最大值 
    right=sum;//右界为元素和 
    while(left<=right)//当区间还可以二分 
    {
		int mid=left+(right-left)/2;//记录中点mid 
		if(check(mid)==1)//若mid作为一个答案可以通过，则先记录下mid作为目前最优ans 
		{
		  ans=mid;
		  right=mid-1;//继续二分：因为mid可以作为答案，即mid这个答案符合所有条件，则已知mid为答案时，组数<=m，由此可得若要使得ans得到最小值 
		}	          //则需要在组数更多、mid更小的左区间查找，所以区间右边可以去掉（因为mid已经计算过了，也可以释放出区间） 
	    else//当mid不通过时，说明组数>m,要使得组数符合要求，则要增大mid，才能较小分组数,所以查找右区间，左区间去掉(mid已计算过无法通过， 
	    {   //再算也是浪费表情，去掉） 
			left=mid+1;
		}
	}
	
	cout<<ans<<endl;
	
	getchar();getchar();
	return 0;
}
