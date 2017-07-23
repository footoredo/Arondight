#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
char s[30];
int n,all;
ll f[1<<20];
int que[1<<20][21];

int main()
{
	for (int i=0;i<(1<<20);i++)
	{
		for (int j=1;j<=20;j++)
		if (i&(1<<(j-1)))
		{
			que[i][0]++;
			que[i][que[i][0]]=j;
		}
	}
	while (scanf("%s",s+1)!=EOF)
	{
		n=strlen(s+1);
		all=(1<<n)-1;
		for (int i=0;i<=all;i++)	f[i]=0;
		f[all]=1;
		for (int i=all;i>0;i--)
		{
			int now=n-que[i][0]+1;
			if (s[now]=='+')
			{
				for (int j=que[i][0];j>=1;j--)
				{
					if (que[i][j]>now)	f[i^(1<<(que[i][j]-1))]+=f[i];
					else break;
				}
			}	else
			{
				for (int j=1;j<=que[i][0];j++)
				{
					if (que[i][j]<now)	f[i^(1<<(que[i][j]-1))]+=f[i];
					else break;
				}
			}
		}
		//printf("%lld\n",f[0]);
		cout<<f[0]<<endl;
	}
	return 0;
}
