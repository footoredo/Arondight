#include <bits/stdc++.h>
using namespace std;
int t,n,q,l,r,a[20000];
int main(){
	scanf("%d",&t);
	for (int tt = 1; tt <= t; tt++){
		scanf("%d",&n);
		for (int i = 1; i <= n; i++)
			scanf("%d",&a[i]);
		scanf("%d",&q);
		for (int i = 1; i <= q; i++){
			int ans = 0;
			scanf("%d%d",&l,&r);
			for (int j = l; j <= r; j++){
				ans = max(ans,a[j]);
			}
			printf("%d\n",ans);
		}
	}
}
