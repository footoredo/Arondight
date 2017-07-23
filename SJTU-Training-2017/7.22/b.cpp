#include<bits/stdc++.h>
using namespace std;

int le[510];
char s[510];
int n;
int f[510][510];
int fail[510];
void kmp(int l,int r)
{
	int j=l-1;
	fail[l]=j;
	for (int i=l+1;i<=r;i++)
	{
		while (j>=l && s[j+1]!=s[i])	j=fail[j];
		if (s[j+1]==s[i])	j++;
		fail[i]=j;
	}
}
int dp(int l,int r)
{
	if (f[l][r]!=0)	return f[l][r];
	if (l==r)	return f[l][r]=1;
	f[l][r]=r-l+1;
	kmp(l,r);
	int len=r-fail[r];
	if ((r-l+1)%len==0)
	{
		for (int i=len;i<(r-l+1);i+=len)
		{
			if (i==1)	f[l][r]=min(f[l][r],dp(l,l+i-1)+le[(r-l+1)/i]);
			else		f[l][r]=min(f[l][r],dp(l,l+i-1)+le[(r-l+1)/i]+2);
		}
	}
	for (int i=l;i<r;i++)
		f[l][r]=min(f[l][r],dp(l,i)+dp(i+1,r));
	//printf(":%d %d %d\n",l,r,f[l][r]);
	return f[l][r];
}

int main()
{
	int ca=0;
	while (true)
	{
		memset(f,0,sizeof(f));
		memset(le,0,sizeof(le));
		ca++;
		scanf("%s",s+1);
		if (s[1]=='0')	break;
		n=strlen(s+1);
		for (int i=1;i<=n;i++)
		{
			int x=i;
			while (x)
			{
				x/=10;
				le[i]++;
			}
		}
		printf("Case %d: %d\n",ca,dp(1,n));
	}
	return 0;
}
