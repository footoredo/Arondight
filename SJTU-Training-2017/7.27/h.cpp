#include <bits/stdc++.h>
using namespace std;
const int mod = 21092013;
char st1[200000],st2[200000];
int t,sl,sr,ans,n,pp;
int main(){
	scanf("%d",&t);
	for (int tt = 1; tt <= t; tt++){
		scanf("%s",st1);
		pp = -1;
		n = strlen(st1);
		for (int i = 0; i < n; i++){
			if (st1[i] == 'U'){
				if (pp != -1)
					pp--;
			} else {
				pp++;
				st1[pp] = st1[i];
			}
		}
		scanf("%s",st2);
		ans = 1;
		sl = 1;
		sr = 1;
		n = strlen(st2);
		for (int i = 0; i < n; i++){
			if (st2[i] == 'U'){
				if (pp != -1){
					ans++;
					if (st1[pp] == 'L') sr++;
					else sl++;
					pp--;
				}
			} else 
			if (st2[i] == 'L'){
				sr = (sl + sr) % mod;
				ans = (sl + ans) % mod;
			} else {
				sl = (sl + sr) % mod;
				ans = (sr + ans) % mod;
			}
			
		}
		printf("Case %d: %d\n",tt,ans);
	}
}
