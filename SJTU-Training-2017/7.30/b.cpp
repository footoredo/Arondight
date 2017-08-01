#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
inline unsigned sfr(unsigned h, unsigned x) {
  return h >> x;
}
int f(LL i, LL j) {
  LL w = i * 1000000ll + j;
  int h = 0;
  for(int k = 0; k < 5; ++k) {
    h += (int) ((w >> (8 * k)) & 255);
    h += (h << 10);
    h ^= sfr(h, 6);
  }
  h += h << 3;
  h ^= sfr(h, 11);
  h += h << 15;
  return sfr(h, 27) & 1;
}
vector<pair<int,int> > has[1050000];
void prepare()
{
	for (int i=1;i<=1000000;i+=950)
		for (int j=1;j<=1000000;j+=950)
		{
			int hass=0;
			if (j+19>1000000)	continue;
			for (int l=j;l<j+20;l++)
				hass=(hass<<1)+f(i,l);
			has[hass].push_back(make_pair(i,j));
		}
}

char s[1010][1010];
inline bool check(int x,int y)
{
	for (int i=1;i<=1000;i++)
		for (int j=1;j<=1000;j++)
		if (f(x+i-1,y+j-1)!=(s[i][j]-'0'))
			return false;
	return true;
}
void doit(int ca)
{
	for (int i=1;i<=1000;i++)
	{
		int hass=0;
		for (int l=1;l<=20;l++)
			hass=(hass<<1)+s[i][l]-'0';
		for (int j=1;j+20<1000;j++)
		{
			if (has[hass].size()>0)
			{
				for (int q=0;q<has[hass].size();q++)
				{
					int x=has[hass][q].first;
					int y=has[hass][q].second;
					if (check(x-i+1,y-j+1))
					{
						printf("Case #%d :%d %d\n",ca,x-i+1,y-j+1);
						return;
					}
				}
			}
			if (j+20!=1001)
				hass=((hass-(s[i][j]-'0')*(1<<19))<<1)+(s[i][j+20]-'0');
		}
	}
}
int main()
{
	//freopen("b.in","r",stdin);
	int T;
	prepare();
	scanf("%d",&T);
	for (int ca=1;ca<=T;ca++)
	{
		for (int i=1;i<=1000;i++)	scanf("%s",s[i]+1);
		//return 0;
		doit(ca);
	}
	return 0;
}
