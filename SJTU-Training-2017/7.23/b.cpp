#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn=110;
const int maxm=1400;
struct Edge
{
	int v,next;
}	edge[maxm<<1];
int g[maxn],tot;
int n,mm;
int match[maxn];
int st[maxn],cnt;
int ans;
int type[maxn];
int fa[maxn];
int que[maxn],l,r;
int to[maxn];
int meng[maxn],mmd;

void clear()
{
	for (int i=0;i<=n+5;i++)	g[i]=0;
	//memset(g,0,sizeof(g));
	tot=0;
	for (int i=0;i<=n+5;i++)	match[i]=0;
	//memset(match,0,sizeof(match));
	ans=0;
	for (int i=0;i<=n+5;i++)	to[i]=0;
	//memset(to,0,sizeof(to));
	for (int i=0;i<=n+5;i++)	meng[i]=0;
	//memset(meng,0,sizeof(meng));
}
void addedge(int x,int y)
{
	tot++;
	edge[tot].v=y;
	edge[tot].next=g[x];
	g[x]=tot;
}
int find(int t)
{
	if (fa[t]==t)	return t;
	return fa[t]=find(fa[t]);
}
int lca(int x,int y)
{
	mmd++;
	for (;;swap(x,y))
	if (x)
	{
		x=find(x);
		if (meng[x]==mmd)	return x;
		meng[x]=mmd;
		if (match[x])	x=to[match[x]];else x=0;
	}
}
void shrink(int x,int y,int z)
{
	while (find(x)!=z)
	{
		to[x]=y;
		if (type[match[x]]==1)	type[match[x]]=0,que[++r]=match[x];
		if (find(x)==x)	fa[x]=z;
		if (find(match[x])==match[x])	fa[match[x]]=z;
		y=match[x];
		x=to[y];
	}
}
bool ok(int p0)
{
	for (int i=1;i<=cnt;i++)	fa[i]=i,type[i]=-1;
	l=r=0;
	que[++r]=p0;
	type[p0]=0;
	while (l<r)
	{
		int u=que[++l];
		for (int j=g[u];j;j=edge[j].next)
		{
			int v=edge[j].v;
			if (type[v]==-1)
			{
				to[v]=u;type[v]=1;
				if (!match[v])
				{
					int pre,now;
					now=v;
					while (now)
					{
						pre=match[to[now]];
						match[now]=to[now];
						match[to[now]]=now;
						now=pre;
					}
					return true;
				}
				type[match[v]]=0;
				que[++r]=match[v];
			}	else
			if (type[v]==0 && find(u)!=find(v))
			{
				int lc;
				lc=lca(u,v);
				shrink(u,v,lc);
				shrink(v,u,lc);
			}
		}
	}
	return false;
}
void add(int x,int y)
{
	addedge(x,y);
	addedge(y,x);
}
struct Store
{
	int x,y;
	bool bo;
}	ques[maxm];

int main()
{
	while (scanf("%d%d",&n,&mm)!=EOF)
	{
		for (int i=1;i<=mm;i++)
		{
			scanf("%d%d",&ques[i].x,&ques[i].y);
			ques[i].bo=false;
		}
		clear();
		for (int i=1;i<=mm;i++)
			add(ques[i].x,ques[i].y);
		for (int i=1;i<=n;i++)	st[i]=i;
		cnt=n;
		ans=0;
		for (int i=1;i<=cnt;i++)
		if (!match[st[i]] && ok(st[i]))	ans++;
		//printf("? %d\n",ans);
		int __ans=ans;
		int sum=0;
		for (int i=1;i<=mm;i++)
		{
			//cerr<<i<<endl;
			clear();
			int u=ques[i].x,v=ques[i].y;
			for (int j=1;j<=mm;j++)
			if (ques[j].x!=u && ques[j].x!=v && ques[j].y!=u && ques[j].y!=v)
				add(ques[j].x,ques[j].y);
			for (int j=1;j<=n;j++)	st[j]=j;
			cnt=n;
			ans=0;
			for (int j=1;j<=cnt;j++)
			if (!match[st[j]] && ok(st[j]))	ans++;
			//printf("? %d %d\n",i,ans);
			if (ans+1<__ans)
			{
				ques[i].bo=true;
				sum++;
			}
		}
		printf("%d\n",sum);
		for (int i=1;i<=mm;i++)
		{
			if (ques[i].bo)
			{
				printf("%d",i);
				sum--;
				if (sum>0)	printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}
/*
? 2
? 1 1
? 2 0
? 3 1
? 4 1
*/
