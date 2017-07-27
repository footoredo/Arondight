#include <bits/stdc++.h>
using namespace std;
char st[3000],s[30000];
int main(){
	s[1] = 'L';
	for (int i = 1; i <= 10; i++){
		s[1 << i] = 'L';
		for (int j = 1; j < 1 << i; j++)
			if (s[j] == 'L') s[(1 << (i + 1)) -  j] = 'R';
			else s[(1 << (i + 1)) - j] = 'L';
	}
	int t;
	scanf("%d",&t);
	for (int tt = 1; tt <= t; tt++){
		int n;
		scanf("%d%s",&n,st);
		if (n > 11) n = 11;
		int m = (1 << n) - 1;
		int len = strlen(st);
		bool ans = false;
/*		for (int i = 1; i <= m; i++)
			printf("%c",s[i]);
		printf("\n");
*/		for (int i = 1; i <= m - len + 1; i++){
			bool pd = true;
			for (int j = 0; j < len; j++)
				if (st[j] != s[i + j])
					pd = false;
			if (pd) ans = true;
		}
		if (ans) printf("Case %d: Yes\n",tt);
		else printf("Case %d: No\n",tt);
	}
}
