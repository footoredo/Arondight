#include<bits/stdc++.h>
using namespace std;

const int maxn=110;
int h[maxn];
int a[maxn][maxn];
int n,m;
long long ans;

int main()
{
	int te;
	scanf("%d",&te);
	while (te--)
	{
		scanf("%d%d",&n,&m);
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++)
				scanf("%d",&a[i][j]);
		ans=0;
		for (register int i=1;i<=n;i++)
			for (register int j=1;j<=m;j++)
			{
				for (register int jj=1;jj<=m;jj++)
				{
					int li=i;
					if (jj>=j)	li--;
					while (li>=1 && a[li][jj]!=a[i][j])	li--;
					h[jj]=li;
				}
				register int maxr=h[j];
				for (register int r=j;r<=m;r++)
				{
					if (h[r]>maxr)	maxr=h[r];
					//maxr=max(maxr,h[r]);
					register int maxl=maxr;
					for (register int l=j;l>=1;l--)
					{
						if (h[l]>maxl)	maxl=h[l];
//						maxl=max(maxl,h[l]);
						//printf(":%d %d %d %d %d\n",i,j,l,r,hl);
						ans+=(i-maxl)*(n-i+1);
					}
				}
			}
		double fans = (double)ans/((n*(n+1)/2)*(m*(m+1)/2));
		printf("%.9f\n",fans);
	}
	return 0;
}
