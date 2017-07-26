#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n,m;
int k;
ll p[21],ans[21];
ll frac[100010],inv[100010];

ll powmod(ll a,ll b,ll p)
{
	ll ans=1;
	while (b)
	{
		if (b&1)	ans=(ans*a)%p;
		a=(a*a)%p;
		b>>=1;
	}
	return ans;
}
ll cheng(ll a,ll b,ll p)
{
	ll ans=0;
	while (b)
	{
		if (b&1)	ans=(ans+a)%p;
		a=(a+a)%p;
		b>>=1;
	}
	return ans;
}

void prepare(ll p)
{
	frac[0]=1;
	inv[0]=1;
	for (int i=1;i<p;i++)	frac[i]=(frac[i-1]*i)%p;
	inv[p-1]=powmod(frac[p-1],p-2,p);
	for (int i=p-2;i>=1;i--)
		inv[i]=(inv[i+1]*(i+1))%p;
}
ll calc(ll n,ll m,ll p)
{
	if (n<m)	return 0;
	ll ans=frac[n];
	ans=(ans*inv[n-m])%p;
	ans=(ans*inv[m])%p;
	return ans;
}
ll C(ll n,ll m,ll p)
{
	ll ans=1;
	while (n!=0 || m!=0)
	{
		ans=ans*calc(n%p,m%p,p);
		n/=p;
		m/=p;
	}
	return ans;
}
void ex_gcd(ll a,ll b,ll &x,ll &y)
{
	if (b==0)
	{
		x=1;
		y=0;
		return;
	}
	ll xx,yy;
	ex_gcd(b,a%b,xx,yy);
	y=xx-a/b*yy;
	x=yy;
}
ll invv(ll x,ll MODN)
{
	ll inv_x,y;
	ex_gcd(x,MODN,inv_x,y);
	return (inv_x%MODN+MODN)%MODN;
}
ll CRT()
{
	ll M=1,sum=0;
	for (int i=1;i<=k;i++)	M*=p[i];
	for (int i=1;i<=k;i++)
	{
		sum=(sum+cheng(cheng(M/p[i],ans[i],M),invv(M/p[i],p[i]),M))%M;
	}
	return sum;
}
int main()
{
	int T;
	cin>>T;
	while (T--)
	{
		cin>>n>>m>>k;
		for (int i=1;i<=k;i++)
		{
			cin>>p[i];
			prepare(p[i]);
			ans[i]=C(n,m,p[i]);
		}
		cout<<CRT()<<endl;
	}
	return 0;
}
