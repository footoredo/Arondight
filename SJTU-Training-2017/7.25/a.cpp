#include<bits/stdc++.h>
using namespace std;

const int maxn=10010;
const int maxm=100010;
struct Man
{
	int score;
	int mask;
}	a[maxn];
int st[maxn],mas[maxn];
struct Ques
{
	int mask;
	int man;
	int id;
	int ans;
}	b[maxm];
int n,m,k;
int all;
int f[1030];

bool cmp_mask(const Ques &a,const Ques &b)
{
	return a.mask<b.mask;
}
bool cmp_score(const Ques &a,const Ques &b)
{
	return st[a.man]>st[b.man];
}
bool cmp_a(const Man &a,const Man &b)
{
	return a.score>b.score;
}
bool cmp_id(const Ques &a,const Ques &b)
{
	return a.id<b.id;
}
int main()
{
	scanf("%d%d",&n,&k);
	all=(1<<k)-1;
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i].score);
		st[i]=a[i].score;
		int x,y;
		scanf("%d",&y);
		for (int j=1;j<=y;j++)
		{
			scanf("%d",&x);
			a[i].mask|=(1<<(x-1));
		}
		mas[i]=a[i].mask;
	}
	scanf("%d",&m);
	for (int i=1;i<=m;i++)
	{
		scanf("%d",&b[i].man);
		int x,y;
		scanf("%d",&y);
		for (int j=1;j<=y;j++)
		{
			scanf("%d",&x);
			b[i].mask|=(1<<(x-1));
		}
		b[i].id=i;
	}
	sort(b+1,b+m+1,cmp_mask);
	int pre=0;
	sort(a+1,a+n+1,cmp_a);
	for (int ma=0;ma<=all;ma++)
	{
		if (pre>=m)	break;
		if (b[pre+1].mask!=ma)	continue;
		int l=pre+1;
		int r=l;
		while (r<m && b[r+1].mask==ma)	r++;
		sort(b+l,b+r+1,cmp_score);
		for (int i=0;i<=all;i++)	f[i]=0;
		int now=1;
		for (int i=l;i<=r;i++)
		{
			while (now<=n && a[now].score>st[b[i].man])
			{
				f[a[now].mask&ma]++;
				now++;
			}
			b[i].ans=f[mas[b[i].man]&ma]+1;
		}
		pre=r;
	}
	sort(b+1,b+m+1,cmp_id);
	for (int i=1;i<=m;i++)
		printf("%d\n",b[i].ans);
	return 0;
}
