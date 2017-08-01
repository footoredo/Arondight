#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[1010];
int pos,dir;

int main()
{
	int T;
	scanf("%d",&T);
	for (int ca=1;ca<=T;ca++)
	{
		scanf("%d%d",&n,&m);
		for (int i=1;i<=n;i++)
		{
			int x;
			scanf("%d",&x);
			if (x==0)	a[i]=1;else a[i]=0;
			if (x==2)
			{
				pos=i;
				dir=1;
			}
			if (x==3)
			{
				pos=i;
				dir=-1;
			}
		}
		int ans=0;
		for (int i=1;i<=m;i++)
		{
			if (pos==1 && dir==-1)	dir=1;
			if (pos==n && dir==1)	dir=-1;
			pos+=dir;
			ans+=a[pos];
		}
		printf("%d\n",ans);
	}
	return 0;
}
