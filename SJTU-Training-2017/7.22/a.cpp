#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int n,m;
int a[100],b[100];
#define x1 xx1
#define y1 yy1
#define x2 xx2
#define y2 yy2
ll x1,x2,y1,y2;
void tmp(ll &x1,ll &x2)
{
	if (x1==0)
	{
		x2=1;
	}	else
	{
		if (x2<0)	x1=-x1,x2=-x2;
		bool bo=false;
		if (x1<0)
		{
			x1=-x1;
			bo=true;
		}
		ll g=__gcd(x1,x2);
		x1/=g;x2/=g;
		if (bo)	x1=-x1;
	}
}
void prin(ll x,ll y)
{
	ll tmp=x/y;
	x-=tmp*y;
	if (x<0)
	{
		x+=y;
		tmp--;
	}
	tmp+=x/y;
	x%=y;
	if (x==0)
	{
		printf("%lld\n",tmp);
		return;
	}
	else
	{
		printf("%lld ",tmp);
		prin(y,x);
	}
}
ll z1,z2;
int main()
{
	int ca=0;
	while (true)
	{
		ca++;
		scanf("%d%d",&n,&m);
		if (n==0 && m==0)	break;
		printf("Case %d:\n",ca);
		for (int i=1;i<=n;i++)	scanf("%d",&a[i]);
		for (int i=1;i<=m;i++)	scanf("%d",&b[i]);
		x1=a[n];x2=1;
		for (int i=n-1;i>=1;i--)
		{
			swap(x1,x2);
			x1+=a[i]*x2;
		}
		y1=b[m];y2=1;
		for (int i=m-1;i>=1;i--)
		{
			swap(y1,y2);
			y1+=b[i]*y2;
		}
		tmp(x1,x2);
		tmp(y1,y2);
		z1=x1*y2+x2*y1;
		z2=x2*y2;
		tmp(z1,z2);
		prin(z1,z2);
		
		z1=x1*y2-x2*y1;
		z2=x2*y2;
		tmp(z1,z2);
		prin(z1,z2);
		
		z1=x1*y1;
		z2=x2*y2;
		tmp(z1,z2);
		prin(z1,z2);
		
		z1=x1*y2;
		z2=x2*y1;
		tmp(z1,z2);
		prin(z1,z2);
	}
	return 0;
}
