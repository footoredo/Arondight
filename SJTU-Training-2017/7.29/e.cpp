#include<bits/stdc++.h>
using namespace std;

const int maxn=110;
int a[maxn],b[maxn];
bitset<110> num[24*60+10];
int q,n,m;

void check(int x,int y,int z,int q)
{
	int ql=z-x,qr=z-y;
	if (ql<0 || qr<0)	ql+=24*60,qr+=24*60;
	//if (ql==0 || qr==0)	return;
	if (ql+qr<0 || ql+qr>=24*60)	return;
	num[ql+qr][q-1]=1;
}
int main()
{
	while (true)
	{
		scanf("%d%d",&n,&m);
		for (int i=1;i<24*60;i++)	num[i]=0;
		if (n==0 && m==0)	break;
		for (int i=1;i<=n;i++)
		{
			int x,y;
			scanf("%d:%d",&x,&y);
			a[i]=x*60+y;
		}
		for (int i=1;i<=m;i++)
		{
			int x,y;
			scanf("%d:%d",&x,&y);
			b[i]=x*60+y;
		}
		scanf("%d",&q);
		for (int i=1;i<=q;i++)
		{
			int x,y,z;
			scanf("%d:%d",&x,&y);
			z=x*60+y;
			for (int l=1;l<=n;l++)
				for (int r=1;r<=m;r++)
					check(a[l],b[r],z,i);
		}
		int ans=0,pos=0;
		for (int i=1;i<24*60;i++)
		if ((int)num[i].count()==q)	ans++,pos=i;
		if (ans==0)
		{
			printf("il bugiardo passeggeri!\n");
			continue;
		}
		if (ans==1)
		{
			printf("%02d:%02d\n",pos/60,pos%60);
			continue;
		}
		printf("%d scelte\n",ans);
	}
	return 0;
}
