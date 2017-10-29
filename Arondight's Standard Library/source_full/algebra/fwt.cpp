/*
 xor(A) = (xor(A0+A1),xor(A0-A1))
_xor(A) = (_xor((A0+A1)/2),_xor((A0-A1)/2))

 and(A) = (and(A0+A1),and(A1))
_and(A) = (_and(A0-A1),_and(A1))

 or(A) = (or(A0),or(A0+A1))
_or(A) = (_or(A0),_or(A1-A0))
*/

void FWT(int *a,int n)
{
	for (int h=2;h<=n;h<<=1)
		for (int j=0;j<n;j+=h)
			for (int k=j;k<j+h/2;k++)
			{
				int u=a[k],v=a[k+h/2];
				//xor : a[k]=(u+v)%mo; a[k+h/2]=(u-v+mo)%mo;
				//and : a[k]=(u+v)%mo; a[k+h/2]=v;
				//or : a[k]=u; a[k+h/2]=(u+v)%mo;
			}
}
void IFWT(int *a,int n)
{
	for (int h=2;h<=n;h<<=1)
		for (int j=0;j<n;j+=h)
			for (int k=j;k<j+h/2;k++)
			{
				int u=a[k],v=a[k+h/2];
				//xor : a[k]=((u+v)*1LL*inv_2)%mo; a[k+h/2]=((u-v)*1LL*inv_2 %mo + mo)%mo;
				//and : a[k]=(u-v+mo)%mo; a[k+h/2]=v;
				//or : a[k]=u; a[k+h/2]=(u-v+mo)%mo;
			}
} 
void cheng(int *a,int *b,int *c,int len)
{
	int l=1;
	while (l<len)	l<<=1;
	len=l;
	FWT(a,len);
	FWT(b,len);
	for (int i=0;i<len;i++)
		c[i]=(a[i]*1LL*b[i])%mo;
	IFWT(c,len);
}
