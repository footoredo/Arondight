#include<bits/stdc++.h>
using namespace std;

int b[1010][1010];
int n,m;
char s[1010];
struct Robot
{
	int x,y;
	bool fast;
	bool die;
}	a[1000010];
int f[2][1000010];
int tot,ans,X,Y,num;
void clear()
{
	n=m=0;
	X=0,Y=0;
	tot=0;
	ans=0;
}
void add(int x,int y,bool is)
{
	tot++;
	a[tot].x=x;
	a[tot].y=y;
	a[tot].fast=is;
	a[tot].die=false;
}
int sign(int x,int y)
{
	if (x<y)	return 1;
	if (x==y)	return 0;
	return -1;
}
void doit()
{
	int *f1=f[0],*f2=f[1];
	for (int i=1;i<=tot;i++)
		f[0][i]=i;
	while (num>0)
	{
		for (int i=1;i<=num;i++)
		{
			int u=f1[i];
			int dx=sign(a[u].x,X),dy=sign(a[u].y,Y);
			if (b[a[u].x][a[u].y]=='#' || b[a[u].x][a[u].y]=='+')
				b[a[u].x][a[u].y]='.';
			a[u].x+=dx;
			a[u].y+=dy;
			if (b[a[u].x][a[u].y]=='@')
			{
				ans++;
				a[u].die=true;
			}	else
			if (b[a[u].x][a[u].y]==(-'#') || b[a[u].x][a[u].y]==(-'+'))
			{
				b[a[u].x][a[u].y]='*';
			}	else
			if (b[a[u].x][a[u].y]=='.'||b[a[u].x][a[u].y]=='#' ||b[a[u].x][a[u].y]=='+')
			{
				b[a[u].x][a[u].y]=(a[u].fast?(-'#'):(-'+'));
			}
		}
		for (int i=1;i<=num;i++)
		if (!a[f1[i]].die)
		{
			int u=f1[i];
			if (b[a[u].x][a[u].y]=='@' || b[a[u].x][a[u].y]=='*')
			{
				a[u].die=true;
			}
		}
		int _num=0;
		for (int i=1;i<=num;i++)
		{
			int u=f1[i];
			if (!a[u].die)
			{
				f2[++_num]=u;
				if (a[u].fast)	b[a[u].x][a[u].y]*=-1;
			}
		}
		swap(f1,f2);
		num=_num;
		
		for (int i=1;i<=num;i++)
		if (a[f1[i]].fast)
		{
			int u=f1[i];
			int dx=sign(a[u].x,X),dy=sign(a[u].y,Y);
			if (b[a[u].x][a[u].y]=='#' || b[a[u].x][a[u].y]=='+')
				b[a[u].x][a[u].y]='.';
			a[u].x+=dx;
			a[u].y+=dy;
			if (b[a[u].x][a[u].y]=='@')
			{
				ans++;
				a[u].die=true;
			}	else
			if (b[a[u].x][a[u].y]==(-'#') || b[a[u].x][a[u].y]==(-'+'))
			{
				b[a[u].x][a[u].y]='*';
			}	else
			if (b[a[u].x][a[u].y]=='.'||b[a[u].x][a[u].y]=='#' ||b[a[u].x][a[u].y]=='+')
			{
				b[a[u].x][a[u].y]=(a[u].fast?(-'#'):(-'+'));
			}
		}
		for (int i=1;i<=num;i++)
		if (!a[f1[i]].die)
		{
			int u=f1[i];
			if (b[a[u].x][a[u].y]=='@' || b[a[u].x][a[u].y]=='*')
			{
				a[u].die=true;
			}
		}
		_num=0;
		for (int i=1;i<=num;i++)
		{
			int u=f1[i];
			if (!a[u].die)
			{
				f2[++_num]=u;
				b[a[u].x][a[u].y]*=-1;
			}
		}
		swap(f1,f2);
		num=_num;
	}
}
int main()
{
	while (true)
	{
		if (scanf("%s",s)<=0)	break;
		clear();
		while (s[0]!='$')
		{
			m=strlen(s);
			n++;
			for (int j=1;j<=m;j++)
			{
				b[n][j]=s[j-1];
				if (b[n][j]=='+')	add(n,j,0);
				if (b[n][j]=='#')	add(n,j,1);
				if (b[n][j]=='@')
				{
					X=n;
					Y=j;
				}
			}
			scanf("%s",s);
		}
		//random_shuffle(a+1,a+tot+1);
		num=tot;
		doit();
		printf("%d\n",ans);
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++)
				b[i][j]=0;
	}
	return 0;
}
