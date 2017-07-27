#include<bits/stdc++.h>
using namespace std;

char s[110];
struct Data
{
	int tm;
	string s;
}	tmps;
bool operator<(const Data &a,const Data &b)
{
	if (a.tm!=b.tm)	return a.tm>b.tm;
	return a.s<b.s;
}
bool operator==(const Data &a,const Data &b)
{
	return ((a.tm==b.tm) && (a.s==b.s));
}
set<Data> S;
set<Data>::iterator it;
map<string,int> M;
vector<string> a[1010];
string ss;
int n;

int main()
{
	//freopen("i.in","r",stdin);
	int day=0;
	while (scanf("%s",s)>0)
	{
		if (s[2]=='e')
		{
			day++;
			if (day-7>=1)
			{
				for (int i=0;i<a[day-7].size();i++)
				{
					int tmp=M[a[day-7][i]];
					tmps.s=a[day-7][i];
					tmps.tm=tmp;
					S.erase(tmps);
					tmps.tm=tmp-1;
					S.insert(tmps);
					M[a[day-7][i]]=tmp-1;
				}
			}
			scanf("%s",s);
			while (s[0]!='<')
			{
				ss=s;
				if (ss.length()>3)
				{
					a[day].push_back(ss);
					int tmp=M[ss];
					tmps.s=ss;
					tmps.tm=tmp;
					S.erase(tmps);
					tmps.tm=tmp+1;
					S.insert(tmps);
					M[ss]=tmp+1;
				}
				scanf("%s",s);
			}
		}	else
		if (s[2]=='o')
		{
			int x;
			scanf("%d",&x);
			printf("<top %d>\n",x);
			int now=0;
			int ci=0;
			for (it=S.begin();it!=S.end();it++)
			{
				now++;
				if (now>x && it->tm!=ci)	break;
				if (now==x)	ci=it->tm;
				printf("%s %d\n",it->s.c_str(),it->tm);
			}
			printf("</top>\n");
			scanf("%s",s);
		}
	}
	return 0;
}
