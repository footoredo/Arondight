#include<bits/stdc++.h>
using namespace std;

struct Cube
{
	int x1,y1,x2,y2;
}	c[60];
int a[10][10],b[10][10];
int cnt,ans;
int vis[10][10];
int que[10],num[10];
bool wudeng;

void clear()
{
	memset(vis,0,sizeof(vis));
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	cnt=ans=0;
	memset(c,0,sizeof(c));
}
int get()
{
	bool bo=true;
	for (int i=1;i<=5;i++)
	if (que[i]!=que[1])	bo=false;
	if (bo)
	{
		if (wudeng==false)
		{
			wudeng=true;
			return 50;
		}	else
			return 100;
	}
	sort(que+1,que+6);
		
	memset(num,0,sizeof(num));
	for (int i=1;i<=5;i++)	num[que[i]]++;
	
	for (int i=1;i+5-1<=6;i++)
	{
		bo=true;
		for (int j=1;j<=5;j++)
			if (num[i+j-1]==0)	bo=false;
		if (bo)	return 40;
	}
	
	for (int i=1;i+4-1<=6;i++)
	{
		bo=true;
		for (int j=1;j<=4;j++)
			if (num[i+j-1]==0)	bo=false;
		if (bo)	return 30;
	}
	
	int bo2=false,bo3=false,bo4=false;
	for (int i=1;i<=6;i++)
	{
		if (num[i]==2)	bo2=true;
		if (num[i]==3)	bo3=true;
		if (num[i]==4)	bo4=true;
	}
	if (bo3 && bo2)	return 25;
	if (bo4)
	{
		for (int i=1;i<=6;i++)
		if (num[i]==4)	return 4*i;
	}
	if (bo3)
	{
		for (int i=1;i<=6;i++)
		if (num[i]==3)	return 3*i;
	}
	return 0;
}
void check()
{
	wudeng=false;
	int sum=0;
	for (int i=1;i<=5;i++)
	{
		for (int j=1;j<=5;j++)
			que[j]=b[i][j];
		sum+=get();
	}
	for (int j=1;j<=5;j++)
	{
		for (int i=1;i<=5;i++)
			que[i]=b[i][j];
		sum+=get();
	}
	for (int i=1;i<=5;i++)
		que[i]=b[i][i];
	sum+=get();
	for (int i=1;i<=5;i++)
		que[i]=b[i][5-i+1];
	sum+=get();
	if (sum>ans)	ans=sum;
	/*
	for (int i=1;i<=5;i++)
	{
		for (int j=1;j<=5;j++)
			printf("%d ",b[i][j]);
		printf("\n");
	}
	printf("sum: %d\n",sum);
	*/
}

int main()
{
	int te;
	scanf("%d",&te);
	for (int ca=1;ca<=te;ca++)
	{
		clear();
		cnt=0;
		for (int i=1;i<=5;i++)
			for (int j=1;j<=5;j++)
			if (a[i][j]==0)
			{
				char ch=getchar();
				while (ch!='V' && ch!='H' && ch!='S')	ch=getchar();
				if (ch=='V')
				{
					int x,y;
					scanf("%d%d",&x,&y);
					cnt++;
					c[cnt].x1=i;
					c[cnt].y1=j;
					c[cnt].x2=i+1;
					c[cnt].y2=j;
					a[i][j]=x;
					a[i+1][j]=y;
					if (x>y)	swap(x,y);
					vis[x][y]=true;
				}
				if (ch=='H')
				{
					int x,y;
					scanf("%d%d",&x,&y);
					cnt++;
					c[cnt].x1=i;
					c[cnt].y1=j;
					c[cnt].x2=i;
					c[cnt].y2=j+1;
					a[i][j]=x;
					a[i][j+1]=y;
					if (x>y)	swap(x,y);
					vis[x][y]=true;
				}
				if (ch=='S')
				{
					int x;
					scanf("%d",&x);
					a[i][j]=x;
				}
			}
		for (int i=1;i<=5;i++)
			for (int j=1;j<=5;j++)
				b[i][j]=a[i][j];
		/*
		for (int i=1;i<=5;i++)
		{
			for (int j=1;j<=5;j++)
				printf("%d ",a[i][j]);
			printf("\n");
		}
		*/
		ans=0;
		check();
		for (int i=1;i<=cnt;i++)
		{
			for (int x=1;x<=6;x++)
				for (int y=x;y<=6;y++)
				if (!vis[x][y])
				{
					b[c[i].x1][c[i].y1]=x;
					b[c[i].x2][c[i].y2]=y;
					check();
					b[c[i].x1][c[i].y1]=y;
					b[c[i].x2][c[i].y2]=x;
					check();
					b[c[i].x1][c[i].y1]=a[c[i].x1][c[i].y1];
					b[c[i].x2][c[i].y2]=a[c[i].x2][c[i].y2];
				}
		}
		printf("Case %d: %d\n",ca,ans);
	}
	return 0;
}
