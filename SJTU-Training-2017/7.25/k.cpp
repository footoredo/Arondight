#include<bits/stdc++.h>
using namespace std;

char s[1000010];
int n,len,m;
string que[1000010];
int tot;
//map<string,int> M;
//map<pair<string,string>,int> M2;
string b[110];
vector<string> a;
map<int,int> M;
map<pair<int,int>,int> M2;
int main()
{
	//freopen("k.in","r",stdin);
	scanf("%d",&n);
	gets(s);
	for (int i=1;i<=n;i++)
	{
		gets(s+1);
		len=strlen(s+1);
		string pre="";
		for (int j=1;j<=len;j++)
		{
			if ((s[j]<='Z' && s[j]>='A') || (s[j]<='z' && s[j]>='a'))
			{
				if (s[j]<='Z' && s[j]>='A')	s[j]=s[j]-'A'+'a';
				pre+=s[j];
			}	else
			{
				if (pre.length()!=0)
				{
					a.push_back(pre);
					que[++tot]=pre;
					pre="";
				}
			}
		}
		if (pre.length()!=0)
		{
			a.push_back(pre);
			que[++tot]=pre;
		}
	}
	//for (int i=0;i<a.size();i++)
	//	cout<<a[i]<<endl;
	sort(que+1,que+tot+1);
	tot=unique(que+1,que+tot+1)-(que+1);
	scanf("%d",&m);
	for (int i=1;i<=m;i++)
	{
		cin>>b[i];
		for (int j=0;j<b[i].length();j++)
		if (b[i][j]<='Z' && b[i][j]>='A')
		{
			b[i][j]=b[i][j]-'A'+'a';
		}
	}
	int pre=0;
	int num1=0,num2=0;
	for (int i=0;i<a.size();i++)
	{
		bool bo=true;
		for (int j=1;j<=m;j++)
		if (a[i]==b[j])
		{
			bo=false;
			break;
		}
		if (bo)
		{
			int qaq=lower_bound(que+1,que+tot+1,a[i])-que;
			M[qaq]++;
			num1++;
			if (pre!=0)
			{
				int x=pre,y=qaq;
				if (x>y)	swap(x,y);
				M2[make_pair(x,y)]++;
				num2++;
			}
			pre=qaq;
		}
	}
	scanf("%d",&m);
	for (int i=1;i<=m;i++)
	{
		string l,r;
		cin>>l>>r;
		for (int j=0;j<l.length();j++)
		if (l[j]<='Z' && l[j]>='A')
		{
			l[j]=l[j]-'A'+'a';
		}
		for (int j=0;j<r.length();j++)
		if (r[j]<='Z' && r[j]>='A')
		{
			r[j]=r[j]-'A'+'a';
		}
		int ql=lower_bound(que+1,que+tot+1,l)-que;
		if (ql>tot || que[ql]!=l)	ql=0;
		int qr=lower_bound(que+1,que+tot+1,r)-que;
		if (qr>tot || que[qr]!=r)	qr=0;
		if (ql>qr)	swap(ql,qr);
		if (ql==0 || qr==0)
		{
			printf("0.0\n");
			continue;
		}
		double ans=(double)M2[make_pair(ql,qr)]/num2;
		ans/=((double)M[ql]/num1)*((double)M[qr]/num1);
		printf("%.15f\n",ans);
	}
	return 0;
}
