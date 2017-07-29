#include<bits/stdc++.h>
using namespace std;

char s[10][5][3];
void prepare()
{
	strcpy(s[0][0]," - ");
	strcpy(s[0][1],"| |");
	strcpy(s[0][2]," . ");
	strcpy(s[0][3],"| |");
	strcpy(s[0][4]," - ");
	
	strcpy(s[1][0]," . ");
	strcpy(s[1][1],". |");
	strcpy(s[1][2]," . ");
	strcpy(s[1][3],". |");
	strcpy(s[1][4]," . ");
	
	strcpy(s[2][0]," - ");
	strcpy(s[2][1],". |");
	strcpy(s[2][2]," - ");
	strcpy(s[2][3],"| .");
	strcpy(s[2][4]," - ");
	
	strcpy(s[3][0]," - ");
	strcpy(s[3][1],". |");
	strcpy(s[3][2]," - ");
	strcpy(s[3][3],". |");
	strcpy(s[3][4]," - ");
	
	strcpy(s[4][0]," . ");
	strcpy(s[4][1],"| |");
	strcpy(s[4][2]," - ");
	strcpy(s[4][3],". |");
	strcpy(s[4][4]," . ");
	
	strcpy(s[5][0]," - ");
	strcpy(s[5][1],"| .");
	strcpy(s[5][2]," - ");
	strcpy(s[5][3],". |");
	strcpy(s[5][4]," - ");
	
	strcpy(s[6][0]," - ");
	strcpy(s[6][1],"| .");
	strcpy(s[6][2]," - ");
	strcpy(s[6][3],"| |");
	strcpy(s[6][4]," - ");
	
	strcpy(s[7][0]," - ");
	strcpy(s[7][1],". |");
	strcpy(s[7][2]," . ");
	strcpy(s[7][3],". |");
	strcpy(s[7][4]," . ");
	
	strcpy(s[8][0]," - ");
	strcpy(s[8][1],"| |");
	strcpy(s[8][2]," - ");
	strcpy(s[8][3],"| |");
	strcpy(s[8][4]," - ");
	
	strcpy(s[9][0]," - ");
	strcpy(s[9][1],"| |");
	strcpy(s[9][2]," - ");
	strcpy(s[9][3],". |");
	strcpy(s[9][4]," - ");
}
char ss[100010];
char tt[5][100010];
int ti[21];
char pic[21][5][10];
int len[21];
int n;
void clear()
{
	memset(ti,0,sizeof(ti));
	memset(pic,0,sizeof(pic));
	memset(len,0,sizeof(len));
	n=0;
}
int getnum()
{
	int ha=strlen(ss);
	int x=0;
	for (int i=0;i<ha;i++)
	if (ss[i]<='9' && ss[i]>='0')	x=x*10+ss[i]-'0';
	return x;
}
char zc[5][10],now[5][10];

bool check(int x,int l)
{
	for (int i=0;i<5;i++)
		for (int j=0;j<10;j++)
		{
			zc[i][j]=' ';
			now[i][j]=' ';
		}
	for (int i=0;i<5;i++)
	{
		if (x/100!=0)
		{
			for (int j=0;j<3;j++)
				zc[i][j]=s[x/100][i][j];
		}
		if (x/10!=0)
		{
			for (int j=0;j<3;j++)
				zc[i][j+3]=s[(x%100)/10][i][j];
		}
		for (int j=0;j<3;j++)
			zc[i][j+6]=s[x%10][i][j];
	}
	for (int i=0;i<5;i++)
		for (int j=0;j<9;j++)
			now[i][j]=pic[l][i][9-len[l]+j];
	for (int i=0;i<5;i++)
		for (int j=0;j<9;j++)
		if (now[i][j]!='*' && now[i][j]!=zc[i][j])	return false;
	return true;
}
int main()
{
	prepare();
	while (true)
	{
		clear();
		gets(ss);
		while (ss[0]!='#' && ss[0]!='$')
		{
			n++;
			ti[n]=getnum();
			for (int i=0;i<5;i++)	gets(tt[i]);
			int le=strlen(tt[0]);
			for (int j=0;j<le;j++)
			{
				bool bo=false;
				for (int i=0;i<5;i++)
				if (tt[i][j]!=' ')	bo=true;
				if (bo)
				{
					for (int i=0;i<5;i++)
						pic[n][i][len[n]]=tt[i][j];
					len[n]++;
				}
			}
			gets(ss);
		}
		int pos=0;
		int ans=0;
		for (int x=0;x<=999;x++)
		{
			bool bo=true;
			for (int j=1;j<=n;j++)
				if (!check((x+ti[j])%1000,j))
					bo=false;
			if (bo)	ans++,pos=x;
		}
		if (ans!=1)
		{
			printf("? %d\n",ans);
		}	else
		{
			printf("%d\n",pos);
		}
		if (ss[0]=='$')	break;
	}
	return 0;
}
