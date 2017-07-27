#include<bits/stdc++.h>
using namespace std;

const int maxn=110;
const int maxm=10010;
int du[maxn];
set<pair<int,int> > S;
set<pair<int,int> >::iterator it;
struct Edge
{
	int v,next;
}	e[maxm<<1];
int g[maxn],tot;
int xz[maxn][4];
int col[maxn];
int ans[maxn];
int sx[maxn];
bool vis[maxn];
int b[maxn][maxn];
int n;
bool bo;

void getsx()
{
	for (int i=1;i<=n;i++)
		S.insert(make_pair(du[i],i));
	for (int i=1;i<=n;i++)
	{
		it=S.end();
		it--;
		sx[i]=it->second;
		vis[sx[i]]=true;
		S.erase(make_pair(du[sx[i]],sx[i]));
		for (int j=g[sx[i]];j;j=e[j].next)
		if (!vis[e[j].v])
		{
			S.erase(make_pair(du[e[j].v],e[j].v));
			du[e[j].v]--;
			S.insert(make_pair(du[e[j].v],e[j].v));
		}
	}
}
void clear()
{
	S.clear();
	for (int i=1;i<=n;i++)
	{
		g[i]=0,du[i]=0;
		vis[i]=0;
		col[i]=4;
		for (int j=0;j<4;j++)	xz[i][j]=0;
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			b[i][j]=false;
	tot=0;
	bo=false;
}
void addedge(int x,int y)
{
	tot++;
	e[tot].v=y;
	e[tot].next=g[x];
	g[x]=tot;
	du[x]++;
}
int que[110][110];
int cnt[110];
void dfs(int t)
{
	if (t>n)
	{
		bo=true;
		return;
	}
	int u=sx[t];
	vis[u]=true;
	int lim=4;
	if (t==1)	lim=1;
	for (int i=0;i<lim;i++)
	if (!xz[u][i])
	{
		ans[u]=i;
		bool flag=true;
		cnt[t]=0;
		for (int j=g[u];j;j=e[j].next)
		if (!vis[e[j].v])
		{
			if (!xz[e[j].v][i])
			{
				xz[e[j].v][i]=true;
				col[e[j].v]--;
				if (col[e[j].v]==0)	flag=false;
				que[++cnt[t]][t]=e[j].v;
			}
		}
		if (flag)
		{
			dfs(t+1);
			if (bo)	return;
		}
		for (int j=1;j<=cnt[t];j++)
		{
			xz[que[j][t]][i]=false;
			col[que[j][t]]++;
		}
	}
	vis[u]=false;
}
int nn;
char s[110];
bool gete()
{
	if (scanf("%s",s)<=0)
	{
		nn=-1;
		return false;
	}
	int le=strlen(s);
	int pos=-1;
	for (int i=0;i<le;i++)
	if (s[i]=='-')
	{
		pos=i;
		break;
	}
	if (pos==-1)
	{
		nn=0;
		for (int i=0;i<le;i++)
			nn=nn*10+s[i]-'0';
		return false;
	}	else
	{
		int x=0,y=0;
		for (int i=0;i<pos;i++)
			x=x*10+s[i]-'0';
		for (int i=pos+1;i<le;i++)
			y=y*10+s[i]-'0';
		b[x][y]=b[y][x]=true;
		return true;
	}
	return true;
}
int main()
{
	//freopen("g.in","r",stdin);
	int ca=0;
	scanf("%d",&nn);
	while (true)
	{
		n=nn;
		if (n==-1)	break;
		ca++;
		if (ca!=1)	printf("\n");
		clear();
		while (gete());
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
			if (b[i][j])	addedge(i,j);
		getsx();
		for (int i=1;i<=n;i++)	vis[i]=0;
		//for (int i=1;i<=n;i++)	printf("%d ",sx[i]);
		//printf("\n");
		dfs(1);
		//if (bo)	cerr<<"OK"<<endl;
		for (int i=1;i<=n;i++)	printf("%d %d\n",i,ans[i]+1);
	}
	return 0;
}
