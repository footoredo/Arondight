#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn=10010;
const int maxm=100010;
int v[maxn];
int du[maxn];
int que[maxn],cnt;
struct Edge
{
	int v,next;
}	e[maxm<<1];
int g[maxn],tot;
int n,m;
bool vis[maxn];
ll ans;
int f[maxn],size[maxn];
ll sum[maxn];
struct Store
{
	int x,y;
}	st[maxm];
void clear()
{
	for (int i=1;i<=n;i++)
	{
		v[i]=0;
		g[i]=0;
		vis[i]=0;
		du[i]=0;
		que[i]=0;
	}
	ans=0;
	tot=cnt=0;
}
void addedge(int x,int y)
{
	tot++;
	e[tot].v=y;
	e[tot].next=g[x];
	g[x]=tot;
}
int fa(int t)
{
	if (f[t]==t)	return t;
	return f[t]=fa(f[t]);
}
void Union(int x,int y)
{
	x=fa(x),y=fa(y);
	if (x==y)	return;
	f[x]=y;
	size[y]+=size[x];
	sum[y]+=sum[x];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while (T--)
	{
		cin>>n>>m;
		clear();
		for (int i=1;i<=n;i++)
			cin>>v[i];
		for (int i=1;i<=m;i++)
		{
			int x,y;
			cin>>x>>y;
			st[i].x=x;
			st[i].y=y;
			addedge(x,y);
			addedge(y,x);
			du[x]++;
			du[y]++;
		}
		for (int i=1;i<=n;i++)
		if (du[i]<=1)
			que[++cnt]=i,vis[i]=true;
		for (int i=1;i<=cnt;i++)
		{
			int u=que[i];
			for (int j=g[u];j;j=e[j].next)
			if (!vis[e[j].v])
			{
				du[e[j].v]--;
				if (du[e[j].v]<=1)
				{
					vis[e[j].v]=true;
					que[++cnt]=e[j].v;
				}
			}
		}
		for (int i=1;i<=n;i++)	f[i]=i,size[i]=1,sum[i]=v[i];
		for (int i=1;i<=m;i++)
		{
			int x=st[i].x,y=st[i].y;
			if (vis[x] || vis[y])	continue;
			Union(x,y);
		}
		ans=0;
		for (int i=1;i<=n;i++)
		if (f[i]==i && !vis[i])
		{
			if (size[i]&1)	ans+=sum[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}
