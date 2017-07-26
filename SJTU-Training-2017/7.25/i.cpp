#include <bits/stdc++.h>
using namespace std;
int n,m,nd,md,s,sn,sm,ans;
int main(){
	scanf("%d%d",&n,&m);
	scanf("%d%d",&nd,&md);
	ans = (n / nd) * (m / md);
	s = 1;
	if (n % nd != 0){
		sn = nd / (n % nd);
		if ((m / md) % sn == 0) ans += (m / md) / sn;
		else {
			ans += (m / md) / sn + 1;
			s--;
		}
	}
	if (m % md != 0){
		sm = md / (m % md);
		if ((n / nd) % sm == 0) ans += (n / nd) / sm;
		else {
			ans += (n / nd) / sm + 1;
			s--;
		}
	}
	if (s == 1 && m % md != 0 && n % nd != 0) ans++;
	printf("%d\n",ans);
}
