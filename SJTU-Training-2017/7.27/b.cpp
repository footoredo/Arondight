#include<bits/stdc++.h>
using namespace std;

struct Ke
{
	int l,r,s;
}	a[110];
bool b[110][110];
int n,m;
int SS,TT;

const int maxn=250;
const int maxm=20010;
const int INF=1<<30;
int S,T;
struct Edge
{
	int v,flow,next;
}	e[maxm<<1];
int g[maxn],tot;
void addedge(int x,int y,int flow)
{
	//printf(": %d %d %d\n",x,y,flow);
	e[++tot].v=y;e[tot].flow=flow;e[tot].next=g[x];g[x]=tot;
	e[++tot].v=x;e[tot].flow=0;e[tot].next=g[y];g[y]=tot;
}
void clear()
{
	memset(g,0,sizeof(g));
	tot=1;
}
int w[maxn],has[maxn],d[maxn];
int que[maxn],pre1[maxn],pre2[maxn],p[maxn];
bool vis[maxn];
int maxflow()
{
	for (int i=1;i<=n;i++)
	{
		has[i]=0;
		d[i]=0;
		vis[i]=false;
	}
	for (int i=1;i<=n;i++)	p[i]=g[i];
	int l,r;
	l=r=1;
	que[1]=T;
	has[0]=1;
	vis[T]=true;
	while (l<=r)
	{
		int u=que[l++];
		for (int i=g[u];i;i=e[i].next)
		if ((i&1) && !vis[e[i].v])
		{
			que[++r]=e[i].v;
			vis[e[i].v]=true;
			d[e[i].v]=d[u]+1;
			has[d[e[i].v]]++;
		}
	}
	for (int i=1;i<=n;i++)
	if (!vis[i])	d[i]=n,has[n]++;
	int flow=INF;
	int ans=0;
	int u=S;
	while (d[S]<n)
	{
		w[u]=flow;
		bool bo=true;
		for (int i=p[u];i;i=e[i].next)
		if (e[i].flow && d[e[i].v]==d[u]-1)
		{
			flow=min(flow,e[i].flow);
			p[u]=i;
			pre1[e[i].v]=u;
			pre2[e[i].v]=i;
			u=e[i].v;
			bo=false;
			if (u==T)
			{
				ans+=flow;
				while (u!=S)
				{
					e[pre2[u]].flow-=flow;
					e[pre2[u]^1].flow+=flow;
					u=pre1[u];
				}
				flow=INF;
			}
			break;
		}
		if (!bo)	continue;
		int minx=n,pos=0;
		for (int i=g[u];i;i=e[i].next)
		if (e[i].flow && d[e[i].v]<minx)	minx=d[e[i].v],pos=i;
		p[u]=pos;
		has[d[u]]--;
		if (has[d[u]]==0)	break;
		d[u]=minx+1;
		has[d[u]]++;
		if (u!=S)	u=pre1[u],flow=w[u];
	}
	return ans;
}

void build()
{
	SS=n*2+1;
	TT=n*2+2;
	S=n*2+3;
	T=n*2+4;
	for (int i=1;i<=n;i++)
	{
		int x=a[i].s/m;
		if (a[i].s%m!=0)	x++;
		addedge(S,i*2,x);
		addedge(i*2-1,i*2,INF);
		addedge(i*2-1,T,x);
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
		if (i!=j)
		{
			if (b[i][j])	addedge(i*2,j*2-1,INF);
		}
	for (int i=1;i<=n;i++)
	{
		addedge(SS,i*2-1,INF);
		addedge(i*2,TT,INF);
	}
}
int main()
{
	int te;
	scanf("%d",&te);
	for (int ca=1;ca<=te;ca++)
	{
		scanf("%d%d",&n,&m);
		clear();
		memset(b, false, sizeof b);
		for (int i=1;i<=n;i++)
			scanf("%d%d%d",&a[i].l,&a[i].r,&a[i].s);
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
			{
				int x;
				scanf("%d",&x);
				if (i==j)	continue;
				if (a[i].r+x<a[j].l)	b[i][j]=true;
			}
		build();
		n=T;
		//printf("%d %d %d\n",n,S,T);
		maxflow();
		addedge(TT,SS,INF);
		maxflow();
		int ans=0;
		for (int i=g[TT];i;i=e[i].next)
		if (e[i].v==SS)
		{
			ans=INF-e[i].flow;
			break;
		}
		printf("Case %d: %d\n",ca,ans);
	}
	return 0;
}
/*
: 5 1 3
: 1 2 1073741824
: 2 6 3
: 3 1 1073741824
: 2 4 1073741824
: 4 3 1073741824
1073741824
*/
