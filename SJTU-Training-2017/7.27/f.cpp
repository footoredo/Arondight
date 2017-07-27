#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll que[110];
int cnt;
ll f[110][2][2];
ll n;
ll doit(ll n)
{
	if (n==0)	return 1;
	cnt=0;
	while (n)
	{
		que[++cnt]=n%5;
		n/=5;
	}
	memset(f,0,sizeof(f));
	f[cnt+1][1][0]=1;
	for (int i=cnt;i>=1;i--)
		for (int li=0;li<2;li++)
			for (int pre=0;pre<2;pre++)
			{
				for (int k=0;k<=4;k++)
				{
					if (li==1 && k>que[i])	continue;
					int tli=(li==1 && k==que[i]);
					int tpre=pre;
					if (i%2==0)	tpre=(tpre+k)%2;
					f[i][tli][tpre]+=f[i+1][li][pre];
				}
			}
	ll ans=f[1][0][0]+f[1][1][0];
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	while (true)
	{
		cin>>n;
		if (n==-1)	break;
		cout<<doit(n)<<endl;
	}
	return 0;
}
