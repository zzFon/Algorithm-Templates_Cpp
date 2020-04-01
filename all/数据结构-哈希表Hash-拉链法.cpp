#include<iostream>//哈希表-拉链法 
using namespace std;//基本思想：分别建立哈希表、哈希表表头、哈希函数，利用哈希函数在表头中找到对应的域，每个域代表一类相似元素（放入哈希函数后返回值相同） 
#include<cstdio>//这类元素在哈希表中组成线性链，通过扫描该线性链查找所需的元素 
 
#include<cstring>//memset()的头文件 

#define N 100001
#define M 200003//据说表头容量M最好是N的2倍以上 

struct hxb//哈希表 
{
	int data;
	int next;
}hxb[N];

int bt[M]={-1};//哈希表表头（貌似这样子赋值-1有时也不行） 

int hash(int x)//哈希函数 
{
	return x%M;
}

int main()
{
	int n,m,i;
	
	memset(bt,-1,sizeof(bt));//初始化表头 
	
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>hxb[i].data;//读入元素 
		hxb[i].next=-1;//初始化该元素的后继指针 
		if(bt[hash(hxb[i].data)]!=-1)//检查该链是否已有元素（若有则进行头插入） 
		  hxb[i].next=bt[hash(hxb[i].data)];//将新元素的后继指向旧的链头 
   	    bt[hash(hxb[i].data)]=i;//再由表头指向该新元素 
	}
	
	int x;
	int p;
	int flag;
	for(i=1;i<=m;i++)//查找(拉链法比起一般的扫描显然高效很多，而效率的大小又由表头和哈希表各自的容量决定（显然在哈希表容量足够的前提下
	                // 表头容量与哈希表容量的比越大效率越高）) 
	{
		cin>>x;
		flag=0;
	    p=bt[hash(x)];
	    //cout<<p<<endl;
	    while(p!=-1)
	    {
			if(hxb[p].data==x)
			{
				cout<<"YES"<<endl;
				flag=1;
				break;
			}
			p=hxb[p].next;
		}
		if(flag==0)
		  cout<<"NO"<<endl;
	}
	
	getchar();getchar();
	return 0;
}
