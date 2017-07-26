#include<bits/stdc++.h>
using namespace std;

const int maxn=500010;
char s[maxn];
int sa[maxn],t[maxn],t2[maxn],c[maxn];
int ra[maxn],he[maxn];
int n,m;

void build_sa(int m)
{
	int i,*x=t,*y=t2;
	for (i=0;i<m;i++)	c[i]=0;
	for (i=0;i<n;i++)	c[x[i]=s[i]]++;
	for (i=1;i<m;i++)	c[i]+=c[i-1];
	for (i=n-1;i>=0;i--)	sa[--c[x[i]]]=i;
	for (int k=1;k<=n;k*=2)
	{
		int p=0;
		for (i=n-k;i<n;i++)	y[p++]=i;
		for (i=0;i<n;i++)
			if (sa[i]>=k)	y[p++]=sa[i]-k;
		for (i=0;i<m;i++)	c[i]=0;
		for (i=0;i<n;i++)	c[x[y[i]]]++;
		for (i=0;i<m;i++)	c[i]+=c[i-1];
		for (i=n-1;i>=0;i--)	sa[--c[x[y[i]]]]=y[i];
		swap(x,y);
		p=1;x[sa[0]]=0;
		for (i=1;i<n;i++)
			x[sa[i]]=(y[sa[i-1]]==y[sa[i]] && y[sa[i-1]+k]==y[sa[i]+k])?p-1:p++;
		if (p>=n)	break;
		m=p;
	}
}
void build_height()
{
	int i,j,k=0;
	for (i=0;i<n;i++)	ra[sa[i]]=i;
}
pair<int,int> seg[maxn<<2];
void build(int t,int l,int r)
{
	if (l==r)
	{
		seg[t]=make_pair(ra[l-1],l);
		return;
	}
	int mid=(l+r)>>1;
	build(t<<1,l,mid);
	build(t<<1|1,mid+1,r);
	if (seg[t<<1].first > seg[t<<1|1].first)
		seg[t]=seg[t<<1];
	else
		seg[t]=seg[t<<1|1];
}
pair<int,int> query(int t,int l,int r,int ql,int qr)
{
	if (ql<=l && qr>=r)	return seg[t];
	int mid=(l+r)>>1;
	if (qr<=mid)	return query(t<<1,l,mid,ql,qr);
	if (ql>mid)	return query(t<<1|1,mid+1,r,ql,qr);
	pair<int,int> tm1,tm2;
	tm1=query(t<<1,l,mid,ql,mid);
	tm2=query(t<<1|1,mid+1,r,mid+1,qr);
	if (tm1.first>tm2.first)
		return tm1;
	else
		return tm2;
}
int main()
{
	scanf("%s",s);
	n=strlen(s);
	s[n++]=' ';
	build_sa(300);
	build_height();
	build(1,1,n);
	scanf("%d",&m);
	for (int i=1;i<=m;i++)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		pair<int,int> ans=query(1,1,n,l,r);
		printf("%d\n",ans.second);
	}
	return 0;
}
