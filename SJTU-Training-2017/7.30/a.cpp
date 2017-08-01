#include<bits/stdc++.h>
using namespace std;

int n,A,B;
int a,b;
char s[80010],s2[80010];

int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d%d",&n,&A,&B);
		int a=0,b=0;
		for (int i=1;i<=n;i++)
		{
			s[i]=getchar();
			while (s[i]!='A' && s[i]!='B' && s[i]!='C')	s[i]=getchar();
		}
		for (int i=1;i<=n;i++)
		{
			char ch=getchar();
			while (ch!='A' && ch!='B' && ch!='C')	ch=getchar();
			if (ch==s[i])	a++;else b++;
		}
		bool ans=false;
		//printf("%d %d %d %d",a,b,A,B);
		for (int x=0;x<=a;x++)
		{
			if (A-x>=0 && b-(A-x)>=0)
			{
				if (B>=x && B<=x+b-(A-x))	ans=true;
			}
		}
		if (ans)	printf("Not lying\n");else printf("Lying\n");
	}
	return 0;
}
