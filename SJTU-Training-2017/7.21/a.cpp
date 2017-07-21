#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
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
const int maxn=210;
struct Point
{
	ll m;
	ll x,y,z;
	ll vx,vy,vz;
}	a[maxn],b[maxn];
ll nx,ny,nz,now;
bool vis[maxn];	
int n,cnt;
pair<ll,ll> ti(ll a,ll m,ll b)
{
	if (a==0 && b==0)
	{
		return make_pair(0,1);
	}
	if (a==0 && b!=0)
	{
		return make_pair(-1,1);
	}
	ll g=__gcd(a,m);
	ll l=(a/g)*m;
	if (b%g!=0)	return make_pair(-1,1);
	ll rem = l / a;
	a/=g;m/=g;b/=g;
	ll k,t;
	ex_gcd(a,m,t,k);
	t*=b;
	k*=b;
	ll dt=rem;
	t%=dt;
	while (t<0)	t+=dt;
	return make_pair(t,dt);
}
ll gett(ll x,ll y)
{
	ll tmp,tmp2;
	tmp=(a[x].vx-a[y].vx);
	tmp%=nx;
	while (tmp<0)	tmp+=nx;
	tmp2=(a[y].x-a[x].x);
	tmp2%=nx;
	while (tmp2<0)	tmp2+=nx;
	pair<ll,ll> tx=ti(tmp,nx,tmp2);
	
	tmp=(a[x].vy-a[y].vy);
	tmp%=ny;
	while (tmp<0)	tmp+=ny;
	tmp2=(a[y].y-a[x].y);
	tmp2%=ny;
	while (tmp2<0)	tmp2+=ny;
	pair<ll,ll> ty=ti(tmp,ny,tmp2);
	
	tmp=(a[x].vz-a[y].vz);
	tmp%=nz;
	while (tmp<0)	tmp+=nz;
	tmp2=(a[y].z-a[x].z);
	tmp2%=nz;
	while (tmp2<0)	tmp2+=nz;
	pair<ll,ll> tz=ti(tmp,nz,tmp2);
	
	if (tx.first==-1 || ty.first==-1 || tz.first==-1)	return -1;
	
	if (tx.first>ty.first)	swap(tx,ty);
	pair<ll,ll> tm=ti(tx.second,ty.second,ty.first-tx.first);
	if (tm.first==-1)	return -1;
	tx.first=tx.first+tx.second*tm.first;
	tx.second=tx.second*tm.second;
	
	if (tx.first>tz.first)	swap(tx,tz);
	tm=ti(tx.second,tz.second,tz.first-tx.first);
	if (tm.first==-1)	return -1;
	tx.first=tx.first+tx.second*tm.first;
	tx.second=tx.second*tm.second;
	
	tx.first%=tx.second;
	while (tx.first<0)	tx.first+=tx.second;
	return tx.first;
}
struct Data
{
	ll ti;
	int x,y;
	Data(ll ti,int x,int y):ti(ti),x(x),y(y){};
};
bool operator<(const Data &a,const Data &b)
{
	if (a.ti!=b.ti)	return a.ti>b.ti;
	if (a.x!=b.x)	return a.x>b.x;
	return a.y>b.y;
}
priority_queue<Data> Q;
bool cmp(const Point &a,const Point &b)
{
	if (a.m!=b.m)	return a.m>b.m;
	if (a.x!=b.x)	return a.x<b.x;
	if (a.y!=b.y)	return a.y<b.y;
	return a.z<b.z;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	//scanf("%d%d%d%d",&n,&nx,&ny,&nz);
	cin>>n>>nx>>ny>>nz;
	for (int i=1;i<=n;i++)
		cin>>a[i].m>>a[i].x>>a[i].y>>a[i].z>>a[i].vx>>a[i].vy>>a[i].vz;
		//scanf("%d%d%d%d%d%d%d",&a[i].m,&a[i].x,&a[i].y,&a[i].z,&a[i].vx,&a[i].vy,&a[i].vz);
	for (int i=1;i<=n;i++)
		for (int j=i+1;j<=n;j++)
		{
			ll tm=gett(i,j);
			if (tm!=-1)
			{
				Q.push(Data(tm,i,j));
			}
		}
	now=0;
	while (!Q.empty())
	{
		Data da=Q.top();
		Q.pop();
		int u=da.x;
		int v=da.y;
		if (vis[u] || vis[v])	continue;
		ll ti=da.ti;
		//cerr<<":"<<u<<" "<<v<<" "<<ti<<endl;
		for (int i=1;i<=n;i++)
		if (!vis[i])
		{
			a[i].x=a[i].x+a[i].vx*(ti-now);
			a[i].y=a[i].y+a[i].vy*(ti-now);
			a[i].z=a[i].z+a[i].vz*(ti-now);
			a[i].x%=nx;
			a[i].y%=ny;
			a[i].z%=nz;
			while (a[i].x<0)	a[i].x+=nx;
			while (a[i].y<0)	a[i].y+=ny;
			while (a[i].z<0)	a[i].z+=nz;
		}
		n++;
		a[n].m=0;
		a[n].x=a[u].x;a[n].y=a[u].y;a[n].z=a[u].z;
		cnt=0;
		for (int i=1;i<n;i++)
		if (!vis[i])
		{
			if (a[i].x==a[u].x && a[i].y==a[u].y && a[i].z==a[u].z)
			{
				a[n].m+=a[i].m;
				a[n].vx+=a[i].vx;
				a[n].vy+=a[i].vy;
				a[n].vz+=a[i].vz;
				cnt++;
				vis[i]=true;
			}
		}
		a[n].vx/=cnt;
		a[n].vy/=cnt;
		a[n].vz/=cnt;
		now=ti;
		for (int i=1;i<n;i++)
		if (!vis[i])
		{
			ll tm=gett(i,n);
			if (tm!=-1)
			{
				tm+=now;
				Q.push(Data(tm,i,n));
			}
		}
	}
	int tot=0;
	for (int i=1;i<=n;i++)
	if (!vis[i])	b[++tot]=a[i];
	sort(b+1,b+tot+1,cmp);
	cout<<tot<<endl;
	//printf("%d\n",tot);
	for (int i=1;i<=tot;i++)
		cout<<"P"<<i-1<<": "<<b[i].m<<" "<<b[i].x<<" "<<b[i].y<<" "<<b[i].z<<" "<<b[i].vx<<" "<<b[i].vy<<" "<<b[i].vz<<endl;
		//printf("P%d: %lld %lld %lld %lld %lld %lld %lld\n",i-1,b[i].m,b[i].x,b[i].y,b[i].z,b[i].vx,b[i].vy,b[i].vz);
	return 0;
}
