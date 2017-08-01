#include<bits/stdc++.h>
using namespace std;

const int maxn=1010;
int v[maxn],c[maxn];
int n;
int b[11][11];
int num[11];
//bool vis[11][11];
int que[11];
bool over;
void clear()
{
	memset(b,0,sizeof(b));
	memset(num,0,sizeof(num));
	over=false;
}

void xiao()
{
	bool bo=false;
	for (int i=1;i<=7;i++)
		for (int j=1;j<=num[i];j++)
		if (b[i][j]==num[i])
		{
			b[i][j]=-b[i][j];
			bo=true;
		}
	for (int j=1;j<=7;j++)
	{
		int pre=0;
		num[8]=0;
		for (int i=1;i<=8;i++)
		{
			if (j>num[i])
			{
				for (int ii=pre+1;ii<i;ii++)
				if (b[ii][j]==i-pre-1)
				{
					b[ii][j]=-b[ii][j];
					bo=true;
				}
				pre=i;
			}
		}
	}
	for (int i=1;i<=7;i++)
	{
		int cnt=0;
		for (int j=1;j<=num[i];j++)
			if (b[i][j]>0)	que[++cnt]=b[i][j];
		for (int j=1;j<=num[i];j++)
			b[i][j]=0;
		for (int j=1;j<=cnt;j++)
			b[i][j]=que[j];
		num[i]=cnt;
	}
	if (bo)	xiao();
}
void outit()
{
	for (int j=7;j>=1;j--)
	{
		for (int i=1;i<=7;i++)
		{
			if (j>num[i])	printf("#");
			else printf("%d",b[i][j]);
		}
		printf("\n");
	}
}
int main()
{
	int ca=0;
	while(true)
	{
		clear();
		scanf("%d",&n);
		if (n==0)	break;
		ca++;
		for (int i=1;i<=n;i++)
			scanf("%d%d",&v[i],&c[i]);
		over=false;
		for (int i=1;i<=n;i++)
		{
			if (num[c[i]]>=7)
			{
				over=true;
				break;
			}
			b[c[i]][++num[c[i]]]=v[i];
			xiao();
			//outit();
			//printf("\n");
		}
		if (over)
		{
			printf("Game Over!\n");
			printf("\n");
			continue;
		}
		outit();
		printf("\n");
	}
	return 0;
}
