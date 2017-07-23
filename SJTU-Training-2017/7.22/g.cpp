#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 110;
struct Car
{
	ll x,v;
}	a[maxn];
ll x,v,l;
ll now,nxt;
int n;
void clear()
{
	n=0;
	now=nxt=0;
	x=v=l=0;
	memset(a,0,sizeof(a));
}
ll getnxt()
{
	ll ans=-1;
	for (int i=1;i<=n;i++)
	if (a[i].v!=v)
	{
		if (a[i].x>x && a[i].v<v)
		{
			ll tmp=(a[i].x-x)/(v-a[i].v);
			if ((a[i].x-x)%(v-a[i].v)!=0)	tmp++;
			if (ans==-1 || ans>tmp)	ans=tmp;
		}
		if (a[i].x<x-4 && a[i].v>v)
		{
			ll tmp=(x-4-a[i].x)/(a[i].v-v);
			if ((x-4-a[i].x)%(v-a[i].v)!=0)	tmp++;
			if (ans==-1 || ans>tmp)	ans=tmp;
		}
		if (a[i].x<=x && a[i].x>=x-4)
		{
			ll ha=a[i].x+a[i].v;
			ll ha2=x+v;
			if (ha<=ha2 && ha>=ha2-4)	ans=1;
		}
	}
	return ans;
}
int main()
{
	int ca=0;
	while (true)
	{
		clear();
		ca++;
		scanf("%lld%lld%lld%d",&x,&v,&l,&n);
		if (x==0 && v==0 && l==0 && n==0)	break;
		x*=4;l*=4;
		for (int i=1;i<=n;i++)
		{
			scanf("%lld%lld",&a[i].x,&a[i].v);
			a[i].x*=4;
		}
		now=0;
		ll sum=v;
		ll cnt=1;
		for (int i=1;i<=n;i++)
		if (a[i].x<=x && a[i].x>=x-4)
		{
			sum+=a[i].v;
			cnt++;
		}
		v=sum/cnt;
		nxt=getnxt();
		while (true)
		{
			if (nxt==-1 || x+nxt*v>l)	break;
			for (int i=1;i<=n;i++)
				a[i].x+=a[i].v*nxt;
			x+=v*nxt;
			now+=nxt;
			sum=v;
			cnt=1;
			for (int i=1;i<=n;i++)
			if (a[i].x<=x && a[i].x>=x-4)
			{
				sum+=a[i].v;
				cnt++;
			}
			v=sum/cnt;
			nxt=getnxt();
		}
		double ans=now/4.0+(l-x)/(v*4.0);
		printf("Case %d: Anna reaches her destination at time %.4f at a speed of %lld\n",ca,ans,v);
	}
	return 0;
}
