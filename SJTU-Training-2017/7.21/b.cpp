#include<bits/stdc++.h>
using namespace std;

const int maxn=110;
struct Point
{
	int x,y;
	int op;
}	a[maxn];
int b[310][310],c[310][310];
int n,m,shan,bu;
int ans;
int minx,miny,maxx,maxy;
int numx[310],cntx,numy[310],cnty;
bool bo;
int cnt;
int nr,nc;
void check(int minx,int maxx,int miny,int maxy)
{
	if (minx>maxx || miny>maxy)	return;
	bo=true;
	int hei=b[maxx][maxy]-b[minx-1][maxy]-b[maxx][miny-1]+b[minx-1][miny-1];
	int bai=c[maxx][maxy]-c[minx-1][maxy]-c[maxx][miny-1]+c[minx-1][miny-1];
	ans=min(ans,shan-hei+bai);
}
int main()
{

	scanf("%d%d%d%d",&nr,&nc,&n,&m);
	shan=n;bu=m;
	for (int i=1;i<=n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		x+=7;y+=4;
		cnt++;
		a[cnt].x=x;a[cnt].y=y;a[cnt].op=1;
	}
	for (int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		x+=7;y+=4;
		cnt++;
		a[cnt].x=x;a[cnt].y=y;a[cnt].op=0;
	}
	n+=m;
	for (int i=1;i<=n;i++)
	{
		numx[++cntx]=a[i].x;
		numx[++cntx]=a[i].x-1;
		numx[++cntx]=a[i].x+1;
		numy[++cnty]=a[i].y;
		numy[++cnty]=a[i].y-1;
		numy[++cnty]=a[i].y+1;
	}
	numx[++cntx]=0;
	numx[++cntx]=nr-1;
	numy[++cnty]=0;
	numy[++cnty]=nc-1;
	sort(numx+1,numx+cntx+1);
	sort(numy+1,numy+cnty+1);
	cntx=unique(numx+1,numx+cntx+1)-(numx+1);
	cnty=unique(numy+1,numy+cnty+1)-(numy+1);
	int lx=lower_bound(numx+1,numx+cntx+1,0)-numx;
	int rx=lower_bound(numx+1,numx+cntx+1,nr-1)-numx;
	int ly=lower_bound(numy+1,numy+cnty+1,0)-numy;
	int ry=lower_bound(numy+1,numy+cnty+1,nc-1)-numy;
	for (int i=1;i<=n;i++)
	{
		int tx=lower_bound(numx+1,numx+cntx+1,a[i].x)-numx;
		int ty=lower_bound(numy+1,numy+cnty+1,a[i].y)-numy;
		a[i].x=tx;
		a[i].y=ty;
		if (a[i].op==0)	c[tx][ty]++;else b[tx][ty]++;
	}
	for (int i=1;i<=cntx;i++)
		for (int j=1;j<=cnty;j++)
		{
			b[i][j]=b[i-1][j]+b[i][j-1]-b[i-1][j-1]+b[i][j];
			c[i][j]=c[i-1][j]+c[i][j-1]-c[i-1][j-1]+c[i][j];
		}
	ans=1<<30;
	for (int i=1;i<=n;i++)
	{
		maxx=0;
		minx=cntx+1;
		maxy=0;
		miny=cnty+1;
		if (a[i].op==0)
		{
			maxx=max(maxx,a[i].x-1);
			minx=min(minx,a[i].x+1);
			maxy=max(maxy,a[i].y-1);
			miny=min(miny,a[i].y+1);
		}	else
		{
			maxx=max(maxx,a[i].x);
			minx=min(minx,a[i].x);
			maxy=max(maxy,a[i].y);
			miny=min(miny,a[i].y);
		}
		minx=max(minx,lx);
		maxx=min(maxx,rx);
		miny=max(miny,ly);
		maxy=min(maxy,ry);
		check(minx,maxx,miny,maxy);
	}
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++)
		{
			maxx=0;
			minx=cntx+1;
			maxy=0;
			miny=cnty+1;
			if (a[i].op==0)
			{
				maxx=max(maxx,a[i].x-1);
				minx=min(minx,a[i].x+1);
				maxy=max(maxy,a[i].y-1);
				miny=min(miny,a[i].y+1);
			}	else
			{
				maxx=max(maxx,a[i].x);
				minx=min(minx,a[i].x);
				maxy=max(maxy,a[i].y);
				miny=min(miny,a[i].y);
			}
			if (a[j].op==0)
			{
				maxx=max(maxx,a[j].x-1);
				minx=min(minx,a[j].x+1);
				maxy=max(maxy,a[j].y-1);
				miny=min(miny,a[j].y+1);
			}	else
			{
				maxx=max(maxx,a[j].x);
				minx=min(minx,a[j].x);
				maxy=max(maxy,a[j].y);
				miny=min(miny,a[j].y);
			}
			minx=max(minx,lx);
			maxx=min(maxx,rx);
			miny=max(miny,ly);
			maxy=min(maxy,ry);
			check(minx,maxx,miny,maxy);
		}
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++)
			for (int k=j+1;k<=n;k++)
			{
				maxx=0;
				minx=cntx+1;
				maxy=0;
				miny=cnty+1;
				if (a[i].op==0)
				{
					maxx=max(maxx,a[i].x-1);
					minx=min(minx,a[i].x+1);
					maxy=max(maxy,a[i].y-1);
					miny=min(miny,a[i].y+1);
				}	else
				{
					maxx=max(maxx,a[i].x);
					minx=min(minx,a[i].x);
					maxy=max(maxy,a[i].y);
					miny=min(miny,a[i].y);
				}
				if (a[j].op==0)
				{
					maxx=max(maxx,a[j].x-1);
					minx=min(minx,a[j].x+1);
					maxy=max(maxy,a[j].y-1);
					miny=min(miny,a[j].y+1);
				}	else
				{
					maxx=max(maxx,a[j].x);
					minx=min(minx,a[j].x);
					maxy=max(maxy,a[j].y);
					miny=min(miny,a[j].y);
				}
				if (a[k].op==0)
				{
					maxx=max(maxx,a[k].x-1);
					minx=min(minx,a[k].x+1);
					maxy=max(maxy,a[k].y-1);
					miny=min(miny,a[k].y+1);
				}	else
				{
					maxx=max(maxx,a[k].x);
					minx=min(minx,a[k].x);
					maxy=max(maxy,a[k].y);
					miny=min(miny,a[k].y);
				}
				minx=max(minx,lx);
				maxx=min(maxx,rx);
				miny=max(miny,ly);
				maxy=min(maxy,ry);
				check(minx,maxx,miny,maxy);
			}
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++)
			for (int k=j+1;k<=n;k++)
				for (int l=k+1;l<=n;l++)
				{
					maxx=0;
					minx=cntx+1;
					maxy=0;
					miny=cnty+1;
					if (a[i].op==0)
					{
						maxx=max(maxx,a[i].x-1);
						minx=min(minx,a[i].x+1);
						maxy=max(maxy,a[i].y-1);
						miny=min(miny,a[i].y+1);
					}	else
					{
						maxx=max(maxx,a[i].x);
						minx=min(minx,a[i].x);
						maxy=max(maxy,a[i].y);
						miny=min(miny,a[i].y);
					}
					if (a[j].op==0)
					{
						maxx=max(maxx,a[j].x-1);
						minx=min(minx,a[j].x+1);
						maxy=max(maxy,a[j].y-1);
						miny=min(miny,a[j].y+1);
					}	else
					{
						maxx=max(maxx,a[j].x);
						minx=min(minx,a[j].x);
						maxy=max(maxy,a[j].y);
						miny=min(miny,a[j].y);
					}
					if (a[k].op==0)
					{
						maxx=max(maxx,a[k].x-1);
						minx=min(minx,a[k].x+1);
						maxy=max(maxy,a[k].y-1);
						miny=min(miny,a[k].y+1);
					}	else
					{
						maxx=max(maxx,a[k].x);
						minx=min(minx,a[k].x);
						maxy=max(maxy,a[k].y);
						miny=min(miny,a[k].y);
					}
					if (a[l].op==0)
					{
						maxx=max(maxx,a[l].x-1);
						minx=min(minx,a[l].x+1);
						maxy=max(maxy,a[l].y-1);
						miny=min(miny,a[l].y+1);
					}	else
					{
						maxx=max(maxx,a[l].x);
						minx=min(minx,a[l].x);
						maxy=max(maxy,a[l].y);
						miny=min(miny,a[l].y);
					}
					minx=max(minx,lx);
					maxx=min(maxx,rx);
					miny=max(miny,ly);
					maxy=min(maxy,ry);
					check(minx,maxx,miny,maxy);
				}
	if (!bo)	ans=0;
	printf("%d\n",ans);
	return 0;
}
