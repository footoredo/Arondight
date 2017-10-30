struct PAM
{
	int trans[maxn][maxc];
	int fail[maxn];
	int cnt[maxn];//出现次数
	int num[maxn];
	int len[maxn];
	int s[maxn];
	int last,n,tot;
	int newnode(int l)
	{
		for (int i=0;i<maxc;i++)	trans[tot][i]=0;
		cnt[tot]=num[tot]=len[tot]=0;
		len[tot]=l;
		return tot++;
	}
	void clear()
	{
		last=n=tot=0;
		newnode(0);newnode(-1);
		s[0]=-1;fail[0]=1;
	}
	int get_fail(int x)
	{
		while (s[n-len[x]-1]!=s[n])	x=fail[x];
		return x;
	}
	void add(int c)
	{
		s[++n]=c;
		int cur=get_fail(last);
		if (!trans[cur][c])
		{
			int now=newnode(len[cur]+2);
			fail[now]=trans[get_fail(fail[cur])][c];
			trans[cur][c]=now;
			num[now]=num[fail[now]]+1;
		}
		last=trans[cur][c];
		cnt[last]++;
	}
	void count()
	{
		for (int i=tot-1;i>=0;i--)	cnt[fail[i]]+=cnt[i];
	}
}	pam;
