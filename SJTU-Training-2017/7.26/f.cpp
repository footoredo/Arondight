#include<bits/stdc++.h>
using namespace std;

#define maxn 20010
char s[maxn],ss[maxn<<1];
char s1[maxn],s2[maxn];
int fail1[maxn],fail2[maxn];
int n;
void clear()
{
	memset(s,0,sizeof(s));
	memset(ss,0,sizeof(ss));
	memset(s1,0,sizeof(s1));
	memset(s2,0,sizeof(s2));
	memset(fail1,0,sizeof(fail1));
	memset(fail2,0,sizeof(fail2));
}

int minrep(const char *s)
{
	int length=n;
	int i=0,j=1,k=0;
	while (i<length && j<length && k<length)
	{
		if (s[(i+k)%length]==s[(j+k)%length])
		{
			k++;
		}	else
		{
			if (s[(i+k)%length]>s[(j+k)%length])
			{
				i+=k+1;
			}	else
			{
				j+=k+1;
			}
			if (i==j)	j++;
			k=0;
		}
	}
	return min(i,j);
}
void kmp(const char *s,int *fail)
{
	fail[0]=-1;
	int j=-1;
	for (int i=1;i<n;i++)
	{
		while (j!=-1 && s[j+1]!=s[i])	j=fail[j];
		if (s[j+1]==s[i])	j++;
		fail[i]=j;
	}
}
int getkmp(const char *a,const char *s,const int *fail)
{
	int j=-1;
	for (int i=0;i<2*n;i++)
	{
		while (j!=-1 && s[j+1]!=a[i])	j=fail[j];
		if (s[j+1]==a[i])	j++;
		if (j==n-1)
		{
			return i-n+1;
		}
	}
	return -1;
}
int getkmp2(const char *a,const char *s,const int *fail)
{
	int j=-1;
	int ans=-1;
	for (int i=0;i<2*n;i++)
	{
		while (j!=-1 && s[j+1]!=a[i])	j=fail[j];
		if (s[j+1]==a[i])	j++;
		if (j==n-1)
		{
			if (i-n+1<n)	ans=i-n+1;
			j=fail[j];
		}
	}
	return ans;
}
bool xiao(const char *a,const char *b)
{
	for (int i=0;i<n;i++)
	{
		if (a[i]<b[i])	return true;
		if (a[i]>b[i])	return false;
	}
	return false;
}
int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		clear();
		scanf("%s",s);
		for (int i=0;i<n;i++)	s[i]='z'-(s[i]-'a');
		int q=minrep(s);
		for (int i=0;i<n;i++)	s1[i]=s[(q+i)%n];
		kmp(s1,fail1);
		for (int i=0;i<n;i++)	ss[i]=ss[i+n]=s[i];
		int pos1=getkmp(ss,s1,fail1);
		for (int i=0;i<n;i++)
		if (n-i-1>i)
		{
			swap(s[n-i-1],s[i]);
		}
		int p=minrep(s);
		for (int i=0;i<n;i++)	s2[i]=s[(p+i)%n];
		kmp(s2,fail2);
		for (int i=0;i<n;i++)	ss[i]=ss[i+n]=s[i];
		int pos2=getkmp2(ss,s2,fail2);
		pos2=n-pos2-1;
		if (xiao(s1,s2))
		{
			printf("%d %d\n",pos1+1,0);
			continue;
		}
		if (xiao(s2,s1))
		{
			printf("%d %d\n",pos2+1,1);
			continue;
		}
		if (pos1<=pos2)
		{
			printf("%d %d\n",pos1+1,0);
			continue;
		}	else
		{
			printf("%d %d\n",pos2+1,1);
			continue;
		}
	}
	return 0;
}
