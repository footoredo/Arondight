#include<bits/stdc++.h>
using namespace std;

const int maxn=1010;
int a[maxn];
int tm1[maxn],tm2[maxn];
int n;
char s[110];

void gb(int l,int r)
{
	if (l==r)	return;
	int mid=(l+r)>>1;
	gb(l,mid);
	gb(mid+1,r);
	for (int i=l;i<=mid;i++)	tm1[i]=a[i];
	for (int i=mid+1;i<=r;i++)	tm2[i]=a[i];
	int nowl=l,nowr=mid+1;
	for (int i=l;i<=r;i++)
	{
		if (nowl>mid)
		{
			a[i]=tm2[nowr++];
			continue;
		}
		if (nowr>r)
		{
			a[i]=tm1[nowl++];
			continue;
		}
		printf("1 %d %d\n",tm1[nowl],tm2[nowr]);
		fflush(stdout);
		scanf("%s",s);
		if (s[0]=='Y')	a[i]=tm1[nowl++];else a[i]=tm2[nowr++];
	}
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)	a[i]=i;
	gb(1,n);
	printf("0");
	for (int i=1;i<=n;i++)	printf(" %d",a[i]);
	printf("\n");
	fflush(stdout);
	return 0;
}
