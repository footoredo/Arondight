#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mo=1e9+7;
struct Matrix
{
	ll a[5][5];
}	ans;
ll a0,ax,ay,b0,bx,by;
ll n;
Matrix operator*(const Matrix &a,const Matrix &b)
{
	Matrix c;
	for (int i=0;i<5;i++)
		for (int j=0;j<5;j++)	c.a[i][j]=0;
	for (int i=0;i<5;i++)
		for (int j=0;j<5;j++)
			for (int k=0;k<5;k++)
				c.a[i][j]=(c.a[i][j]+(a.a[i][k]*b.a[k][j])%mo)%mo;
	return c;
}
Matrix operator^(const Matrix &a,ll k)
{
	Matrix ans,b;
	for (int i=0;i<5;i++)
		for (int j=0;j<5;j++)
		{
			ans.a[i][j]=0;
			b.a[i][j]=a.a[i][j];
		}
	for (int i=0;i<5;i++)	ans.a[i][i]=1;
	while (k)
	{
		if (k&1)	ans=ans*b;
		b=b*b;
		k>>=1;
	}
	return ans;
}
void init()
{
	for (int i=0;i<5;i++)
		for (int j=0;j<5;j++)	ans.a[i][j]=0;
	ans.a[0][0]=ax%mo;
	ans.a[0][4]=ay%mo;
	ans.a[1][1]=bx%mo;
	ans.a[1][4]=by%mo;
	ans.a[2][0]=(ax*by)%mo;
	ans.a[2][1]=(bx*ay)%mo;
	ans.a[2][2]=(ax*bx)%mo;
	ans.a[2][4]=(ay*by)%mo;
	
	ans.a[3][0]=(ax*by)%mo;
	ans.a[3][1]=(bx*ay)%mo;
	ans.a[3][2]=(ax*bx)%mo;
	ans.a[3][3]=1;
	ans.a[3][4]=(ay*by)%mo;
	
	ans.a[4][4]=1;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	while (cin>>n)
	{
		cin>>a0>>ax>>ay;
		cin>>b0>>bx>>by;
		if (n<=0)
		{
			cout<<"0\n";
			continue;
		}
		init();
		ans=ans^(n-1);
		ll sum=0;
		sum=(a0*ans.a[3][0])%mo;
		sum=(sum+(b0*ans.a[3][1])%mo)%mo;
		sum=(sum+(((a0*b0)%mo)*ans.a[3][2])%mo)%mo;
		sum=(sum+(((a0*b0)%mo)*ans.a[3][3])%mo)%mo;
		sum=(sum+ans.a[3][4])%mo;
		cout<<sum<<'\n';
	}
	return 0;
}
