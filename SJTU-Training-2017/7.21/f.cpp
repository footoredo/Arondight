#include<bits/stdc++.h>
using namespace std;

const int maxn=2710;
const int maxm=1203010;
const int INF=1<<30;
int n,m;
int S,T;
struct Edge
{
	int v,flow,next;
}	e[maxm<<1];
int g[maxn],tot=1;
void addedge(int x,int y,int flow)
{
	//printf(":%d %d %d\n",x,y,flow);
	//cout<<":"<<x<<" "<<y<<" "<<flow<<endl;
	e[++tot].v=y;e[tot].flow=flow;e[tot].next=g[x];g[x]=tot;
	e[++tot].v=x;e[tot].flow=0;e[tot].next=g[y];g[y]=tot;
}
int w[maxn],has[maxn],d[maxn];
int que[maxn],pre1[maxn],pre2[maxn],p[maxn];
bool vis[maxn];
int maxflow()
{
	for (int i=1;i<=n;i++)	has[i]=0,d[i]=0,vis[i]=false;
	for (int i=1;i<=n;i++)	p[i]=g[i];
	int l,r;
	l=r=1;
	que[1]=T;has[0]=1;vis[T]=true;
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
		int MIN=n,pos=0;
		for (int i=g[u];i;i=e[i].next)
		if (e[i].flow && d[e[i].v]<MIN)	MIN=d[e[i].v],pos=i;
		p[u]=pos;
		has[d[u]]--;
		if (has[d[u]]==0)	break;
		d[u]=MIN+1;
		has[d[u]]++;
		if (u!=S)	u=pre1[u],flow=w[u];
	}
	return ans;
}
map<string,int> M;
void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n1,n2,n3,m;
	cin>>n3>>n1>>n2>>m;
	S=n3+2*m+1;
	T=n3+2*m+2;
	n=T;
	int cnt;
	for (int i=1;i<=n1;i++)
	{
		string s;
		cin>>s;
		M[s]=i;
		addedge(S,i,1);
	}
	for (int i=1;i<=n2;i++)
	{
		string s;
		cin>>s;
		M[s]=i+n1;
		addedge(i+n1,T,1);
	}
	cnt=n1+n2;
	for (int i=1;i<=m;i++)
	{
		int x;
		//scanf("%d",&x);
		cin>>x;
		for (int j=1;j<=x;j++)
		{
			string s;
			cin>>s;
			int pos=M[s];
			if (pos==0)
			{
				M[s]=++cnt;
				pos=cnt;
			}
			addedge(pos,n3+i*2-1,INF);
			addedge(n3+i*2,pos,INF);
		}
		addedge(n3+i*2-1,n3+i*2,1);
	}
}
int main()
{
	init();
	cout<<maxflow()<<endl;
	return 0;
}

/*
:14 1 1
:14 2 1
:14 3 1
:4 15 1
:5 15 1
:6 15 1
0
*/
