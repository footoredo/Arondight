#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mo=1e9+7;
const int maxn=100010;
struct Point
{
	ll x,y;
	Point():x(0),y(0){}
	Point(ll a,ll b)
	{
		x=(a%mo+mo)%mo;
		y=(b%mo+mo)%mo;
	}
	Point operator+(const Point &a)	const
	{
		return Point(x+a.x,y+a.y);
	}
	Point operator-(const Point &a)	const
	{
		return Point(x-a.x,y-a.y);
	}
	Point operator*(ll a)	const
	{
		return Point(x*a,y*a);
	}
}	a[maxn],sum;
ll det(const Point &a,const Point &b)
{
	ll sum=a.x*b.y-a.y*b.x;
	sum=(sum%mo+mo)%mo;
	return sum;
}
ll po[100010];
int n;
int main()
{
	int T;
	scanf("%d",&T);
	po[0]=1;
	for (int i=1;i<=100000;i++)	po[i]=(po[i-1]*2)%mo;
	while (T--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			a[i].x=x;
			a[i].y=y;
		}
		sum.x=0;
		sum.y=0;
		for (int i=2;i<=n;i++)
			sum=sum+a[i]*po[n-i];
		ll ans=0;
		for (int i=1;i<=n;i++)
		{
			ans=(ans+det(a[i],sum))%mo;
			if (i!=n)
			{
				sum=sum*2;
				sum=sum-a[i+1]*po[n-1];
				sum=sum+a[i];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
