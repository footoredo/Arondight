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
	int i,k=0;
	for (i=0;i<n;i++)	ra[sa[i]]=i;
	for (i=0;i<n;i++)
	{
		if (ra[i]==0) continue;
		if (k) k--;
		int j=sa[ra[i]-1];
		while (s[i+k]==s[j+k]) k++;
		he[ra[i]]=k;
	}
}
set<int> S;
set<int>::iterator it,it2;
struct Ques
{
	int l,r;
	int id,ans;
}	ques[maxn];
bool cmp(const Ques &a,const Ques &b)
{
	return a.r<b.r;
}
bool cmp_id(const Ques &a,const Ques &b)
{
	return a.id<b.id;
}
vector<int> ev[maxn];
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
bool da(int x,int y,int &lc)
{
	if (ra[x]<ra[y])	return false;
	lc=query(1,1,n,ra[y]+1,ra[x]);
	return true;
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
		scanf("%d%d",&ques[i].l,&ques[i].r);
		ques[i].l--;
		ques[i].r--;
		ques[i].id=i;
	}
	sort(ques,ques+m+1,cmp);
	int now=1;
	for (int i=0;i<n-1;i++)
	{
		while (!S.empty())
		{
			it=S.end();
			it--;
			int pos;
			if (da(i,*it,pos))
			{
				if (pos!=0)
				{
					ev[i+pos].push_back(i);
					break;
				}	else
				{
					S.erase(it);
				}
			}	else	break;
		}
		S.insert(i);
		for (auto j:ev[i])
		if (S.count(j))
		{
			it=S.lower_bound(j);
			if (it==S.begin())	continue;
			it--;
			int pos;
			while (da(j,*it,pos))
			{
				if (j+pos>i)
				{
					ev[j+pos].push_back(j);
					break;
				}
				it2=it;
				if (it==S.begin())
				{
					S.erase(it);
					break;
				}
				it--;
				S.erase(it2);
			}
		}
		while (now<=m && ques[now].r==i)
		{
			it=S.lower_bound(ques[now].l);
			ques[now].ans=*it;
			now++;
		}
	}
	sort(ques+1,ques+m+1,cmp_id);
	for (int i=1;i<=m;i++)
		printf("%d\n",ques[i].ans+1);
	return 0;
}
