#include<bits/stdc++.h>
using namespace std;

const int maxn=3010;
int maxx[maxn][maxn],minx[maxn][maxn];
int n;
int a[maxn],pos[maxn];
int la[maxn][maxn];
int cut[maxn][maxn];
int ans;

inline bool lx(int l,int r)
{
	if (l>r)	return true;
	return ((maxx[l][r]-minx[l][r]+1)==(r-l+1));
}
void init()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		pos[a[i]]=i;
	}
	for (int i=1;i<=n;i++)
	{
		maxx[i][i]=minx[i][i]=a[i];
		for (int j=i+1;j<=n;j++)
		{
			maxx[i][j]=max(maxx[i][j-1],a[j]);
			minx[i][j]=min(minx[i][j-1],a[j]);
		}
	}
	for (int i=1;i<=n;i++)
		for (int j=i;j<=n;j++)
			if (lx(i,j))	la[i][j]=j;else la[i][j]=la[i][j-1];
	for (int i=1;i<=n;i++)
	{
		cut[i][i]=1;
		int pre=i;
		for (int j=i+1;j<=n;j++)
		{
			if (a[j]<maxx[i][pre])	pre=i-1;
			if (lx(pre+1,j) && (pre==i-1 || minx[pre+1][j]==maxx[i][pre]+1))
			{
				cut[i][j]=cut[i][pre]+1;
				pre=j;
			}	else cut[i][j]=-1;
		}
	}
}
int query(int l,int r,int &sum)
{
	if (l>r)	return true;
	if (cut[l][r]==-1)	return false;
	sum+=cut[l][r];
	return true;
}
void clear()
{
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			cut[i][j]=la[i][j]=maxx[i][j]=minx[i][j]=0;
		}
		a[i]=pos[i]=0;
	}
	ans=0;
}
int main()
{
	int te;
	scanf("%d",&te);
	while (te--)
	{
		clear();
		init();
		for (int i=1;i<=n;i++)
		if (lx(1,i-1) && (i==1 || minx[1][i-1]==1))
		{
			int p=pos[i];
			int l=p,r=p;
			for (int k=i;k<=n;k++)
			{
				l=min(l,pos[k]);
				r=max(r,pos[k]);
				if (lx(r+1,n) && (r==n || maxx[r+1][n]==n))
				if (lx(l,r))
				{
					int q=la[i][l-1];
					if (q==l-1 && i!=l-1)
					{
						q=la[i][l-2];
						if (minx[q+1][l-1]>maxx[i][q])	q=l-1;
					}
					int sum=0;
					if (query(1,i-1,sum) && query(q+1,l-1,sum) && query(r+1,n,sum))
						ans=max(ans,sum+2);
				}
			}
		}
		printf("%d\n",ans);
		clear();
	}
	return 0;
}
