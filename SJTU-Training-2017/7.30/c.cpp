#include<bits/stdc++.h>
using namespace std;

const int maxn=250010;
const int mo=1e9+7;
int n;
int a[maxn<<1],b[maxn];
int num[maxn];
void px()
{
	//for (int i=1;i<=n;i++)	num[i]=0;
	for (int i=1;i<=n;i++)	num[b[i]]++;
	int cnt=0;
	for (int i=1;i<=n;i++)
	{
		while (num[i])
		{
			b[++cnt]=i;
			num[i]--;
		}
	}
}
int main()
{
	while (scanf("%d",&n)==1)
	{
		for (int i=1;i<=n;i++)	scanf("%d",&a[i]);
		for (int i=1;i<=n;i++)	scanf("%d",&b[i]);
		px();
		int maxx=-1<<30;
		for (int i=b[1];i<=n;i++)
			maxx=max(maxx,a[i]-i);
		a[n+1]=maxx;
		maxx=a[n+1]-(n+1);
		int now=n;
		for (int i=n;i>=1;i--)
		{
			maxx=max(maxx,a[i]-i);
			while (now>1 && b[now]==i)
			{
				a[n+now]=maxx;
				now--;
			}
		}
		int ans=0;
		for (int i=n+1;i<=2*n;i++)
		{
			ans=ans+a[i];
			if (ans>=mo)	ans-=mo;
		}
		printf("%d\n",ans);
	}
	return 0;
}
