#include<bits/stdc++.h>
using namespace std;

int f[2][21][21][21][21];
int f1,f2;
int n,A,B;
int cnt[210];

int main()
{
	scanf("%d%d%d",&n,&A,&B);
	memset(f,-1,sizeof(f));
	f[0][0][0][0][0]=0;
	f1=0;
	f2=1;
	for (int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		cnt[i]+=x;
	}
	for (int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		cnt[i]+=x;
	}
	for (int i=1;i<=n;i++)
	{
		for (int a1=0;a1<=A;a1++)
			for (int b1=0;b1<=B;b1++)
				for (int a2=0;a2<=A;a2++)
					for (int b2=0;b2<=B;b2++)
						f[f2][a1][b1][a2][b2]=-1;
		for (int a1=0;a1<A;a1++)
			for (int b1=0;b1<B;b1++)
				for (int a2=0;a2<A;a2++)
					for (int b2=0;b2<B;b2++)
					if (f[f1][a1][b1][a2][b2]!=-1)
					{
						int ta1,tb1,ta2,tb2;
						if (cnt[i]==0)
						{
							ta1=a1;tb1=b1;ta2=a2;tb2=b2;
							tb1--;
							tb2--;
							if (tb1<=0 || ta1<=0)	ta1=0,tb1=0;
							if (tb2<=0 || ta2<=0)	ta2=0,tb2=0;
							if (f[f2][ta1][tb1][ta2][tb2]==-1 || f[f2][ta1][tb1][ta2][tb2]>f[f1][a1][b1][a2][b2])	f[f2][ta1][tb1][ta2][tb2]=f[f1][a1][b1][a2][b2];
						}
						if (cnt[i]==1)
						{
							ta1=a1;tb1=b1;ta2=a2;tb2=b2;
							int sum=f[f1][a1][b1][a2][b2];
							if (ta1==0 || tb1==0)	ta1=A,tb1=B,sum++;
							ta1--,tb1--;
							tb2--;
							if (tb1<=0 || ta1<=0)	ta1=0,tb1=0;
							if (tb2<=0 || ta2<=0)	ta2=0,tb2=0;
							if (f[f2][ta1][tb1][ta2][tb2]==-1 || f[f2][ta1][tb1][ta2][tb2]>sum)	f[f2][ta1][tb1][ta2][tb2]=sum;
							
							ta1=a1;tb1=b1;ta2=a2;tb2=b2;
							sum=f[f1][a1][b1][a2][b2];
							if (ta2==0 || tb2==0)	ta2=A,tb2=B,sum++;
							ta2--,tb2--;
							tb1--;
							if (tb1<=0 || ta1<=0)	ta1=0,tb1=0;
							if (tb2<=0 || ta2<=0)	ta2=0,tb2=0;
							if (f[f2][ta1][tb1][ta2][tb2]==-1 || f[f2][ta1][tb1][ta2][tb2]>sum)	f[f2][ta1][tb1][ta2][tb2]=sum;
						}
						if (cnt[i]==2)
						{
							ta1=a1;tb1=b1;ta2=a2;tb2=b2;
							int sum=f[f1][a1][b1][a2][b2];
							if (ta1==0 || tb1==0)	ta1=A,tb1=B,sum++;
							if (ta2==0 || tb2==0)	ta2=A,tb2=B,sum++;
							ta1--,tb1--;
							ta2--,tb2--;
							if (tb1<=0 || ta1<=0)	ta1=0,tb1=0;
							if (tb2<=0 || ta2<=0)	ta2=0,tb2=0;
							if (f[f2][ta1][tb1][ta2][tb2]==-1 || f[f2][ta1][tb1][ta2][tb2]>sum)	f[f2][ta1][tb1][ta2][tb2]=sum;
						}
					}
		swap(f1,f2);
	}
	int ans=2*n;
	for (int a1=0;a1<A;a1++)
		for (int b1=0;b1<B;b1++)
			for (int a2=0;a2<A;a2++)
				for (int b2=0;b2<B;b2++)
				if (f[f1][a1][b1][a2][b2]!=-1)
				{
					if (ans==-1 || ans>f[f1][a1][b1][a2][b2])	ans=f[f1][a1][b1][a2][b2];
				}
	printf("%d\n",ans);
	return 0;
}
