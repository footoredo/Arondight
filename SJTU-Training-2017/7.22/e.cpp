#include <bits/stdc++.h>
using namespace std;
int fr[300],d[300],q[300],a[300][300],n,t,x,ans;
bool exist[300];
void spfa(){
	for (int i = 0; i <= 2 * n + 1; i++)
		d[i] = 1000000;
	int l = 1;
	int r = 1;
	q[1] = 0;
	for (int i = 0; i <= 2 * n + 1; i++)
		exist[i] = true;
	d[0] = 0;
	exist[0] = false;
	while (l <= r){
		int x = q[l % (2 * n + 2)];
		exist[x] = true;
		l++;
		for (int i = 0; i <= 2 * n + 1; i++)
			if (d[x] + a[x][i] < d[i]){
				d[i] = d[x] + a[x][i];
				fr[i] = x;
				if (exist[i]){
					r++;
					q[r % (2 * n + 2)] = i;
					exist[i] = false;
				}
			}
	}
	int x = 2 * n + 1;
	ans += d[x];
	while (x != 0){
		swap(a[x][fr[x]],a[fr[x]][x]);
		a[x][fr[x]] = -a[x][fr[x]];
		x = fr[x];
	}
}
int main(){
	scanf("%d",&t);
	for (int tt = 1; tt <= t; tt++){
		scanf("%d",&n);
		for (int i = 0; i <= 2 * n + 1; i++)
			for (int j = 0; j <= 2 * n + 1; j++)
				a[i][j] = 1000000;
		for (int i = 1; i <= n; i++)
			for (int j = i + 1; j <= n; j++){
				scanf("%d",&x);
				a[j * 2 - 1][i * 2] = x;
				a[i * 2 - 1][j * 2] = x;
			}
		for (int i = 1; i <= n; i++)
			a[0][i * 2 - 1] = 0;
		for (int i = 1; i <= n; i++)
			a[i * 2][n * 2 + 1] = 0;
		ans = 0;
		for (int i = 1; i <= n; i++)
			spfa();
		printf("Case %d: %d\n",tt,ans);
	}
}
