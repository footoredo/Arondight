#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn=100010;
char s[maxn];
int sa[maxn],t[maxn],t2[maxn],c[maxn],n,m;
int ra[maxn],he[maxn];
void clear()
{
	for (int i=0;i<=n;i++)	ra[i]=he[i]=sa[i]=0;
}

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
			x[sa[i]]=(y[sa[i-1]]==y[sa[i]] && y[sa[i-1]+k]==y[sa[i]+k]?p-1:p++);
		if (p>=n)	break;
		m=p;
	}
}
void build_height()
{
	int i,j,k=0;
	for (i=0;i<n;i++)	ra[sa[i]]=i;
	for (i=0;i<n;i++)
	{
		if (ra[i]==0)	continue;
		if (k)	k--;
		j=sa[ra[i]-1];
		while (s[i+k]==s[j+k])	k++;
		he[ra[i]]=k;
	}
}
struct Ques
{
	int x,y;
}	a[maxn];
int le[100010];
int seg[maxn<<2];
void build(int t,int l,int r)
{
	if (l==r)
	{
		seg[t]=he[l];
		return;
	}
	int mid=(l+r)>>1;
	build(t<<1,l,mid);
	build(t<<1|1,mid+1,r);
	seg[t]=min(seg[t<<1],seg[t<<1|1]);
}
int query(int t,int l,int r,int ql,int qr)
{
	if (ql<=l && qr>=r)	return seg[t];
	int mid=(l+r)>>1;
	if (qr<=mid)	return query(t<<1,l,mid,ql,qr);
	if (ql>mid)	return query(t<<1|1,mid+1,r,ql,qr);
	return min(query(t<<1,l,mid,ql,mid),query(t<<1|1,mid+1,r,mid+1,qr));
}
int main()
{
	le[0]=1;
	for (int i=1;i<=100000;i++)
	{
		int x=i;
		while (x)
		{
			le[i]++;
			x/=10;
		}
	}
	while (scanf("%s",s)!=EOF)
	{
		n=strlen(s);
		s[n++]='$';
		build_sa(300);
		build_height();
		build(1,1,n);
		scanf("%d",&m);
		ll sumx=0,sumy=0;
		for (int i=1;i<=m;i++)
		{
			scanf("%d%d",&a[i].x,&a[i].y);
			a[i].y--;
		}
		sumx+=a[1].y-a[1].x+1+1;
		sumy+=a[1].y-a[1].x+1+2+le[0];
		for (int i=2;i<=m;i++)
		{
			int xx=ra[a[i-1].x];
			int yy=ra[a[i].x];
			int tmp=0;
			if (xx==yy)
				tmp=min(a[i-1].y-a[i-1].x+1,a[i].y-a[i].x+1);
			else
			{
				if (xx>yy)	swap(xx,yy);
				xx++;
				tmp=query(1,1,n,xx,yy);
			}
			tmp=min(tmp,min(a[i-1].y-a[i-1].x+1,a[i].y-a[i].x+1));
			//printf("I %d %d\n",i,tmp);
			sumx+=a[i].y-a[i].x+1+1;
			sumy+=(a[i].y-a[i].x+1-tmp)+2+le[tmp];
		}
		cout<<sumx<<' '<<sumy<<endl;
		clear();
	}
	return 0;
}
/*
I 2 7
I 3 3
I 4 3
I 5 6
I 6 5
43 31
*/
