#include<bits/stdc++.h>
using namespace std;

const int maxn=1010;
int a[maxn];
int sum,n;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	int ans=0;
	for (int i=1;i<=n;i++)
		if (a[i]*n>sum)	ans++;
	printf("%d\n",ans);
	return 0;
}
