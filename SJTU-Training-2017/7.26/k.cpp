#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int BASE[12]={2,3,5,7,11,13,17,19,23,29,31,37};
int pri[80010],cnt;
ll multi(ll x,ll y,ll MODN)
{
	ll t=(x*y-(ll)((long double)x/MODN *y+1e-3)*MODN)%MODN;
	return t<0?t+MODN:t;
}
ll powmod(ll a,ll b,ll mo)
{
	ll ans=1;
	while (b)
	{
		if (b&1)	ans=multi(ans,a,mo);
		a=multi(a,a,mo);
		b>>=1;
	}
	return ans;
}
bool check(const ll &prime,const ll &base)
{
	ll number=prime-1;
	for (;~number&1;number>>=1);
	ll result=powmod(base,number,prime);
	for (; number!= prime-1 && result !=1 && result != prime -1;number<<=1)
	{
		result = multi(result,result,prime);
	}
	return result == prime-1 || (number & 1)==1;
}

bool miller_rabin(const ll &number)
{
	if (number<2)	return false;
	if (number<4)	return true;
	if (~number&1)	return false;
	for (int i=0;i<100 && pri[i+1]<number;i++)
	{
		if (!check(number,pri[i+1]))	return false;
	}
	return true;
}

ll pollard_rho(const ll &number,const ll &seed)
{
	ll x=rand()%(number-1)+1,y=x;
	for (int head=1,tail=2;;)
	{
		x=multi(x,x,number);
		x=(x+seed)%number;
		if (x==y)
		{
			return number;
		}
		ll answer= __gcd(abs(x-y),number);
		if (answer>1 && answer<number)	return answer;
		if (++head == tail)
		{
			y=x;
			tail<<=1;
		}
	}
}
void factorize(const ll &number,vector<ll> &divisor)
{
	if (number>1)
	{
		if (miller_rabin(number))
		{
			divisor.push_back(number);
		}	else
		{
			ll factor=number;
			for (;factor>=number;factor = pollard_rho(number,rand()%(number-1)+1));
			factorize(number/factor,divisor);
			factorize(factor,divisor);
		}
	}
}

__int128 x,y,g,xx,yy,g2;
void read(__int128 &digit)
{
	digit=0;
	char c;
	for (c=getchar();(c<'0' || c>'9') && c!='-';c=getchar());
	bool type=false;
	if (c=='-')
		type=true,c=getchar();
	for (;c>='0' && c<='9';digit=digit*10+c-'0',c=getchar());
	if (type==true)
		digit=-digit;
}
bool bo[1000010];
void prepare()
{
	for (int i=2;i<=1000000;i++)
	{
		if (!bo[i])	pri[++cnt]=i;
		for (int j=1;j<=cnt;j++)
		{
			if ((ll)pri[j]*i>1000000)	break;
			bo[pri[j]*i]=true;
			if (i%pri[j]==0)	break;
		}
	}
}
__int128 gcd(__int128 a,__int128 b)
{
	if (a<b)	swap(a,b);
	if (b==0)	return a;
	return gcd(b,a%b);
}
#define x1 xx1
#define x2 xx2
#define y1 yy1
#define y2 yy2
vector<ll> x1,x2,y1,y2;
long long ans1,ans2;
bool check3(__int128 a,__int128 &b)
{
	if (a==1)	return false;
	__int128 l=1,r=100000000,mid,tmp;
	while (l<r)
	{
		mid=(l+r)/2;
		if (mid*mid*mid<a)	l=mid+1;else r=mid;
	}
	if (r*r*r!=a)	return false;
	b=r;
	return true;
}
bool check2(__int128 a,__int128 &b)
{
	if (a==1)	return false;
	__int128 l=1,r=1000000000000LL,mid,tmp;
	while (l<r)
	{
		mid=(l+r)/2;
		if (mid*mid<a)	l=mid+1;else r=mid;
	}
	if (r*r!=a)	return false;
	b=r;
	return true;
}
void getans(ll &ans,vector<ll> &x,int op)
{
	ans=1;
	sort(x.begin(),x.end());
	int pre=1;
	for (int j=0;j<x.size();j++)
	{
		if (j==0 || x[j-1]!=x[j])
		{
			ans*=pre;
			pre=1;
		}	else	pre++;
	}
	ans*=pre;
	ans*=op;
}
int main()
{
	int T;
	scanf("%d",&T);
	prepare();
	while (T--)
	{
		x1.clear();
		y1.clear();
		x2.clear();
		y2.clear();
		read(x);read(y);
		g=gcd(x,y);
		xx=x/g;
		yy=y/g;
		g2=g;
		//cerr<<(ll)xx<<" " <<(ll)yy<<" "<<(ll)g<<endl;
		if (xx<=1000000 || g<=1000000)
		{
			for (int j=1;j<=cnt;j++)
			{
				while (xx%pri[j]==0)
				{
					xx/=pri[j];
					x1.push_back(pri[j]);
				}
				while (g%pri[j]==0)
				{
					g/=pri[j];
					x1.push_back(pri[j]);
				}
			}
			__int128 tmp;
			if (check3(g,tmp))
			{
				getans(ans1,x1,3);
			}	else
			if (check2(g,tmp))
			{
				getans(ans1,x1,2);
			}	else
			{
				getans(ans1,x1,1);
			}
		}	else
		{
			factorize(xx,x1);
			factorize(g,x2);
			for (int i=0;i<x2.size();i++)	x1.push_back(x2[i]);
			getans(ans1,x1,1);
		}
		g=g2;
		if (yy<=1000000 || g<=1000000)
		{
			for (int j=1;j<=cnt;j++)
			{
				while (yy%pri[j]==0)
				{
					yy/=pri[j];
					y1.push_back(pri[j]);
				}
				while (g%pri[j]==0)
				{
					g/=pri[j];
					y1.push_back(pri[j]);
				}
			}
			__int128 tmp;
			if (check3(g,tmp))
			{
				getans(ans2,y1,3);
			}	else
			if (check2(g,tmp))
			{
				getans(ans2,y1,2);
			}	else
			{
				getans(ans2,y1,1);
			}
		}	else
		{
			factorize(yy,y1);
			factorize(g,y2);
			for (int i=0;i<y2.size();i++)	y1.push_back(y2[i]);
			getans(ans2,y1,1);
		}
		cout<<ans1<<" "<<ans2<<endl;
	}
	return 0;
}
