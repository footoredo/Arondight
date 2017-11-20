#include<bits/stdc++.h>
using namespace std;

typedef long double db;
typedef long long ll;
const int mask=(1<<15)-1;
const int maxn=100010;
const int maxl=262144;
const db pi=acos(-1.0);
const int mo=998244353;

Complex A[maxl],B[maxl],C[maxl],D[maxl];

int a[maxn<<1],b[maxn<<1],c[maxn<<1];

int q;
void FFT(Complex *a,int n,int isdft)
{
	for (register int i=0,j=0;i<n;i++)
	{
		if (i>j)	swap(a[i],a[j]);
		for (int t=n>>1;(j^=t)<t;t>>=1);
	}
	for (int i=2;i<=n;i<<=1)
	{
		Complex wn(cos(isdft*2*pi/i),sin(isdft*2*pi/i));
		for (int j=0;j<n;j+=i)
		{
			Complex w(1,0),u,v;
			for (int k=j;k<j+i/2;k++)
			{
				u=a[k],v=a[k+i/2]*w;
				a[k]=u+v;
				a[k+i/2]=u-v;
				w=w*wn;
			}
		}
	}
	if (isdft==-1)
	for (int i=0;i<n;i++)	a[i].r/=n;
}
inline void cheng(int *x,int *y,int *z,int len)
{
//	len++;
	int l=1;
	q=0;
	while (l<len*2)	l*=2,q++;
	for (int i=0;i<len;i++)
		A[i]=Complex(x[i]>>15,x[i]&mask);
	for (int i=len;i<l;i++)
		A[i]=Complex(0,0);
	for (int i=0;i<len;i++)
		B[i]=Complex(y[i]>>15,y[i]&mask);
	for (int i=len;i<l;i++)
		B[i]=Complex(0,0);
	FFT(A,l,1);
	FFT(B,l,1);
	for (int i=0;i<l;i++)
	{
		int j=(l-i)%l;
		Complex _a=(A[i]-A[j].conj())*Complex(0,-0.5);
		Complex _b=(A[i]+A[j].conj())*Complex(0.5,0);
		Complex _c=(B[i]-B[j].conj())*Complex(0,-0.5);
		Complex _d=(B[i]+B[j].conj())*Complex(0.5,0);
		C[j]=_a*_d+_a*_c*Complex(0,1);
		D[j]=_b*_d+_b*_c*Complex(0,1);
	}
	FFT(C,l,1);
	FFT(D,l,1);
	for (int i=0;i<l;i++)
	{
		ll _a=((ll)(C[i].i/l+0.5))%mo;
		ll _b=((ll)(C[i].r/l+0.5))%mo;
		ll _c=((ll)(D[i].i/l+0.5))%mo;
		ll _d=((ll)(D[i].r/l+0.5))%mo;
		z[i]=((_d<<30)+((_b+_c)<<15)+_a)%mo;
	}
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	n++,m++;
	for (int i=0;i<n;i++)
		scanf("%d",&a[i]);
	for (int i=0;i<m;i++)
		scanf("%d",&b[i]);
	cheng(a,b,c,max(n,m));
	for (int i=0;i<n+m-1;i++)
		printf("%d\n",c[i]);
	return 0;
}
