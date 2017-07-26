#include <bits/stdc++.h>
using namespace std;
struct rec{
	int lc,rc,data;
};
string ans[2000];
rec a[2000];
int pp,t,n,q;
void tian(int x){
	pp++;
	a[pp].data = x;
	a[pp].lc = 0;
	a[pp].rc = 0;
	if (pp == 1){
		return;
	}
	int p = 1;
	while (1){
		if (x < a[p].data){
			ans[x] = ans[x] + "E";
			if (a[p].lc == 0) break;
			else p = a[p].lc;
		} else{
			ans[x] = ans[x] + "W";
			if (a[p].rc == 0) break;
			else p = a[p].rc;
		}
	}
	if (x < a[p].data)
		a[p].lc = pp;
	else
		a[p].rc = pp;
}
int main(){
	scanf("%d",&t);
	for (int tt = 1; tt <= t; tt++){
		pp = 0;
		scanf("%d",&n);
		for (int i = 1; i <= n; i++)
			ans[i] = "";
		for (int i = 1; i <= n; i++){	
			int x;
			scanf("%d",&x);
			tian(x);
		}
		scanf("%d",&q);
		for (int i = 1; i <= q; i++){	
			int x;
			scanf("%d",&x);
			cout << ans[x] << endl;
		}
	}
}
