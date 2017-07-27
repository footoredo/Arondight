#include<bits/stdc++.h>
using namespace std;

template <typename T>
__inline void qk(T & container)
{
	container.clear();
	T(container).swap(container);
}
struct Data
{
	int le;
	int a[6];
}	ha;
bool operator<(const Data &a,const Data &b)
{
	if (a.le!=b.le)	return a.le<b.le;
	for (int i=0;i<a.le;i++)
	if (a.a[i]!=b.a[i])	return a.a[i]<b.a[i];
	return false;
}
bool operator==(const Data &a,const Data &b)
{
	if (a.le!=b.le)	return false;
	for (int i=0;i<a.le;i++)
	if (a.a[i]!=b.a[i])	return false;
	return true;
}
set<Data> S;
map<string,int> M;
int tot;
vector<int> st;
string ss,seten;
int n;
char s[110];
void clear()
{
	qk(S);
	qk(M);
	tot=1;
	string tmp="joe";
	M[tmp]=1;
}

void study()
{
	int le=st.size();
	for (int l=2;l<=n;l++)
	{
		for (int i=0;i+l-1<le;i++)
		{
			ha.le=l;
			for (int j=0;j<l;j++)
				ha.a[j]=st[i+j];
			S.insert(ha);
		}
	}
	return;
}
void learn()
{
	while (true)
	{
		scanf("%s",s);
		if (s[0]=='.' || s[0]==',' || s[0]==':' || s[0]==';' || s[0]=='?' || s[0]=='!' || s[0]=='*')
		{
			study();
			qk(st);
		}	else
		{
			ss=s;
			for (int i=0;i<ss.length();i++)
			{
				if (ss[i]<='Z' && ss[i]>='A')	ss[i]=ss[i]-'A'+'a';
			}
			int tmp=M[ss];
			if (tmp==0)
			{
				tmp=++tot;
				M[ss]=tmp;
			}
			st.push_back(tmp);
		}
		if (s[0]=='*')	return;
	}
}
void check(bool bo)
{
	int le=st.size();
	if (le<=1)	return;
	if (bo)
	{
		printf("What does the sentence \"%s\" mean?\n",seten.c_str());
		return;
	}
	int l=min(n,le);
	for (int i=0;i+l-1<le;i++)
	{
		ha.le=l;
		for (int j=0;j<l;j++)
			ha.a[j]=st[i+j];
		if (!S.count(ha))
		{
			printf("What does the sentence \"%s\" mean?\n",seten.c_str());
			return;
		}
	}
	return;
}
void say()
{
	bool bo=false;
	while (true)
	{
		scanf("%s",s);
		if (s[0]=='.' || s[0]==',' || s[0]==':' || s[0]==';' || s[0]=='?' || s[0]=='!' || s[0]=='#')
		{
			check(bo);
			study();
			qk(st);
			qk(seten);
			bo=false;
		}	else
		{
			ss=s;
			for (int i=0;i<ss.length();i++)
			{
				if (ss[i]<='Z' && ss[i]>='A')	ss[i]=ss[i]-'A'+'a';
			}
			int tmp=M[ss];
			if (tmp==0)
			{
				tmp=++tot;
				M[ss]=tmp;
				printf("What does the word \"%s\" mean?\n",s);
				bo=true;
			}
			st.push_back(tmp);
			if (st.size()!=1)	seten+=' ';
			seten+=s;
		}
		if (s[0]=='#')	return;
	}
}
int main()
{
	int ca=0;
	while (scanf("%d",&n)==1)
	{
		ca++;
		if (ca!=1)	printf("\n");
		clear();
		printf("Learning case %d\n",ca);
		learn();
		say();
	}
	return 0;
}
