const int mask=(1<<15)-1;
const int maxn=100010;
const int maxl=262144;

Complex A[maxl],B[maxl],C[maxl],D[maxl];
void multiply(int *x,int *y,int *z,int len)
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
	DFT(A,l);
	DFT(B,l);
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
	DFT(C,l);
	DFT(D,l);
	for (int i=0;i<l;i++)
	{
		ll _a=((ll)(C[i].i/l+0.5))%mo;
		ll _b=((ll)(C[i].r/l+0.5))%mo;
		ll _c=((ll)(D[i].i/l+0.5))%mo;
		ll _d=((ll)(D[i].r/l+0.5))%mo;
		z[i]=((_d<<30)+((_b+_c)<<15)+_a)%mo;
	}
}
