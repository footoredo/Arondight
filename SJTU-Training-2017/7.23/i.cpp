#include<bits/stdc++.h>
using namespace std;

#define foreach(A,x,it) for (int it=A.h[x];it;it=A.e[it].next)
typedef long long ll;
const int maxn=50010;
const int maxm=100010;
template<class T,int maxn,int maxm>
struct AdjList
{
	struct Edge
	{
		T data;
		int next;
	}	e[maxm];
	int h[maxn],t;
	void add(int x,const T&data)
	{
		t++;
		e[t].data=data;
		e[t].next=h[x];
		h[x]=t;
	}
	void drop(int x)
	{
		h[x]=e[h[x]].next;
	}
	T &operator[](const int &index)
	{
		return e[index].data;
	}
	void clear(int n)
	{
		fill(h+1,h+n+1,t=0);
	}
};
int dfn[maxn],sdom[maxn],idom[maxn],id[maxn],f[maxn],fa[maxn],smin[maxn];
AdjList<int,maxn,maxm> pred,succ;
long long answer[maxn];
int stamp;
void predfs(int x)
{
	id[dfn[x]=++stamp]=x;
	foreach(succ,x,i)
	{
		int y=succ[i];
		if (!dfn[y])
		{
			f[y]=x;
			predfs(y);
		}
	}
}
int getfa(int x)
{
	if (fa[x]==x)	return x;
	int ret=getfa(fa[x]);
	if (dfn[sdom[smin[fa[x]]]]<dfn[sdom[smin[x]]])
	{
		smin[x]=smin[fa[x]];
	}
	return fa[x]=ret;
}
void tarjan(int s)
{
	static AdjList<int,maxn,maxn> tmp;
	stamp=tmp.t=0;
	predfs(s);
	for (int i=1;i<=stamp;i++)
	{
		fa[id[i]]=smin[id[i]]=id[i];
		tmp.h[id[i]]=idom[id[i]]=0;
	}
	for (int o=stamp;o>=1;o--)
	{
		int x=id[o];
		if (o!=1)
		{
			sdom[x]=f[x];
			foreach(pred,x,i)
			{
				int p=pred[i];
				if (!dfn[p])	continue;
				if (dfn[p]>dfn[x])
				{
					getfa(p);
					p=sdom[smin[p]];
				}
				if (dfn[sdom[x]]>dfn[p])
				{
					sdom[x]=p;
				}
			}
			tmp.add(sdom[x],x);
		}
		while (tmp.h[x]!=0)
		{
			int y=tmp[tmp.h[x]];
			tmp.drop(x);
			getfa(y);
			if (x!=sdom[smin[y]])
			{
				idom[y]=smin[y];
			}	else
			{
				idom[y]=x;
			}
		}
		foreach(succ,x,i)
		{
			if (f[succ[i]]==x)
			{
				fa[succ[i]]=x;
			}
		}
	}
	idom[s]=s;
	for (int i=2;i<=stamp;i++)
	{
		int x=id[i];
		if (idom[x]!=sdom[x])
		{
			idom[x]=idom[idom[x]];
		}
	}
}
vector<int> son[maxn];
int n,m;
ll mxh[maxn];
void clear()
{
	stamp=0;
	pred.clear(n);
	succ.clear(n);
	for (int i=1;i<=n;i++)	sdom[i]=idom[i]=dfn[i]=id[i]=f[i]=fa[i]=smin[i]=0;
	for (int i=1;i<=n;i++)	answer[i]=0LL;
	for (int i=1;i<=n;i++)	son[i].clear();
	for (int i=1;i<=n;i++)	mxh[i]=0;
}

void ddfs(int t)
{
	if (t!=n)	mxh[t]=mxh[idom[t]]+t;
	for (int i=0;i<son[t].size();i++)
		ddfs(son[t][i]);
}
int main()
{
	while (scanf("%d%d",&n,&m)!=EOF)
	{
		clear();
		for (int i=1;i<=m;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			pred.add(y,x);
			succ.add(x,y);
		}
		tarjan(n);
		for (int i=1;i<n;i++)	son[idom[i]].push_back(i);
		mxh[n]=n;
		ddfs(n);
		for (int i=1;i<n;i++)
			printf("%lld ",mxh[i]);
		printf("%lld\n",mxh[n]);
	}
	return 0;
}
