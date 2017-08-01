#include<bits/stdc++.h>
using namespace std;

int n,m,p;
int main()
{
	int te;
	scanf("%d",&te);
	while (te--)
	{
		scanf("%d%d%d",&n,&m,&p);
		int ans=0;
		int num=n*m-1;
		while (num>1)
		{
			int now=1;
			int pre=0;
			while (now<=num)
			{
				ans=(ans+((now-1-pre)&1))&1;
				pre++;
				now+=p;
			}
			num-=pre;
		}
		if (ans==0)	printf("YES\n");else printf("NO\n");
	}
	return 0;
}
