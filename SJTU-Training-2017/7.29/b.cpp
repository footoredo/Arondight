#include<bits/stdc++.h>
using namespace std;

char s[110],s1[110],s2[110],s3[110],t[110];
int n,n1,n2,n3,m;

bool check(char *s,int n,char *t,int m)
{
	if (n!=m)	return false;
	for (int i=0;i<n;i++)
	if (s[i]!=t[i])	return false;
	return true;
}
int main()
{
	int T;
	scanf("%d",&T);
	for (int ca=1;ca<=T;ca++)
	{
		scanf("%s",s);
		n=strlen(s);
		n1=n2=n3=0;
		for (int i=0;i<n;i++)
		{
			if (s[i]<='9' && s[i]>='0')
			{
				s2[n2++]=s[i];
			}
			if (s[i]<='z' && s[i]>='a')
			{
				s1[n1++]=s[i];
				s2[n2++]=s[i]-'a'+'A';
				s3[n3++]=s[i]-'a'+'A';
			}
			if (s[i]<='Z' && s[i]>='A')
			{
				s1[n1++]=s[i];
				s2[n2++]=s[i]-'A'+'a';
				s3[n3++]=s[i]-'A'+'a';
			}
		}
		//printf("%s %s %s\n",s1,s2,s3);
		scanf("%s",t);
		m=strlen(t);
		if (check(s,n,t,m))
		{
			printf("Case %d: Login successful.\n",ca);
			continue;
		}
		if (check(s1,n1,t,m))
		{
			printf("Case %d: Wrong password. Please, check your num lock key.\n",ca);
			continue;
		}
		if (check(s2,n2,t,m))
		{
			printf("Case %d: Wrong password. Please, check your caps lock key.\n",ca);
			continue;
		}
		if (check(s3,n3,t,m))
		{
			printf("Case %d: Wrong password. Please, check your caps lock and num lock keys.\n",ca);
			continue;
		}
		printf("Case %d: Wrong password.\n",ca);
	}
	return 0;
}
