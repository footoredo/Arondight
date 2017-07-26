#include<bits/stdc++.h>
using namespace std;

const int maxn=100010;
int fa[maxn],q[maxn];//0=up 1=down
struct Edge
{
	int v,op,next; //0=yes 1=f
}	e[maxn<<1];
int g[maxn],tot;
void addedge(int x,int y,int op)
{
	tot++;
	e[tot].v=y;
	e[tot].op=op;
	e[tot].next=g[x];
	g[x]=tot;
}
pair<int,int> lc[maxn][20];//0=up 1=down 2=not
int dep[maxn];
int n,m;
void dfs(int t)
{
	if (t!=1)
	{
		lc[t][0]=make_pair(fa[t],q[t]);
		for (int i=1;i<20;i++)
		{
			int v=lc[t][i-1].first;
			if (lc[v][i-1].first==0)	break;
			int tmp=2;
			if (lc[t][i-1].second==lc[v][i-1].second)	tmp=lc[t][i-1].second;
			lc[t][i]=make_pair(lc[v][i-1].first,tmp);
		}
	}
	dep[t]=dep[fa[t]]+1;
	for (int i=g[t];i;i=e[i].next)
	if (e[i].v!=fa[t])
	{
		fa[e[i].v]=t;
		if (e[i].op==0)	q[e[i].v]=1;else q[e[i].v]=0;
		dfs(e[i].v);
	}
}
int lca(int x,int y)
{
	if (x==y)	return x;
	if (dep[x]<dep[y])	swap(x,y);
	int m=dep[x]-dep[y];
	int k=0;
	while (m)
	{
		if (m&1)	x=lc[x][k].first;
		m>>=1;
		k++;
	}
	if (x==y)	return x;
	k=0;
	while (x!=y)
	{
		if (lc[x][k].first!=lc[y][k].first || lc[x][k].first==lc[y][k].first && k==0)
		{
			x=lc[x][k].first;
			y=lc[y][k].first;
			k++;
		}	else k--;
	}
	return x;
}
bool ok(int x,int y,int o)
{
	if (x==y)	return true;
	int det=dep[x]-dep[y];
	for (int i=0;i<20;i++)
	if (det&(1<<i))
	{
		int tmp=lc[x][i].second;
		if (tmp!=o)	return false;
		x=lc[x][i].first;
	}
	return true;
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		addedge(x,y,0);
		addedge(y,x,1);
	}
	dfs(1);
	scanf("%d",&m);
	for (int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		int z=lca(x,y);
		if (ok(x,z,0) && ok(y,z,1))
		{
			printf("Yes\n");
		}	else
		{
			printf("No\n");
		}
	}
	return 0;
}
