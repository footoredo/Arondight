#include<bits/stdc++.h>
using namespace std;

const int maxn=150010;
struct Man
{
	string name;
	int v,ti;
}	a[maxn],tmp;
struct Ques
{
	int k,p;
}	ques[maxn];
string ans[maxn];
int n,m,q;
bool operator<(const Man &a,const Man &b)
{
	if (a.v!=b.v)	return a.v<b.v;
	return a.ti>b.ti;
}
bool cmp(const Ques &a,const Ques &b)
{
	return a.k<b.k;
}
priority_queue<Man> Q;
char s[210];
int main()
{
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	int T;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d%d",&n,&m,&q);
		for (int i=1;i<=n;i++)
		{
			scanf("%s",s);
			a[i].name=s;
			scanf("%d",&a[i].v);
			a[i].ti=i;
		}
		while (!Q.empty())	Q.pop();
		for (int i=1;i<=m;i++)	scanf("%d%d",&ques[i].k,&ques[i].p);
		sort(ques+1,ques+m+1,cmp);
		int now=1;
		int cnt=0;
		for (int i=1;i<=m;i++)
		{
			while (now<=ques[i].k)
			{
				Q.push(a[now]);
				now++;
			}
			for (int j=1;j<=ques[i].p && !Q.empty();j++)
			{
				ans[++cnt]=Q.top().name;
				Q.pop();
			}
		}
		while (now<=n)
		{
			Q.push(a[now]);
			now++;
		}
		while (!Q.empty())
		{
			ans[++cnt]=Q.top().name;
			Q.pop();
		}
		for (int i=1;i<=q;i++)
		{
			int x;
			scanf("%d",&x);
			printf("%s",ans[x].c_str());
			if (i!=q)	printf(" ");
		}
		printf("\n");
	}
	return 0;
}
