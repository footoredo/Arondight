#include <bits/stdc++.h>
using namespace std;
const int N = 112345;
int h[N],z[N][20],c[N],fa[N],n;
int lca(int x,int y){
	if (h[x] < h[y])
		swap(x,y);
	for (int k = 17; k >= 0; k--)
		if (h[z[x][k]] >= h[y]){
			x = z[x][k];
		}
	if (x == y) return x;
	for (int k = 17; k >= 0; k--)
		if (z[x][k] != z[y][k]){
			x = z[x][k];
			y = z[y][k];
		}
	return fa[x];
}
int dis(int x,int y){
	return h[x] + h[y] - 2 * h[lca(x,y)];
}
int main(){
	for (scanf("%d",&n); n != 0; scanf("%d",&n)){
		fa[1] = 1;
		h[1] = 1;
		for (int i = 2; i <= n; i++){
			scanf("%d%d",&fa[i],&c[i]);
			h[i] = h[fa[i]] + 1;
		}
		for (int i = 1; i <= n; i++)
			z[i][0] = fa[i];
		for (int k = 1; k <= 17; k++)
			for (int i = 1; i <= n; i++)
				z[i][k] = z[z[i][k - 1]][k - 1];
		int x = 1;
		int y = 1;
		int z = 1;
		long long ans = 0;
		for (int i = 2; i <= n; i++){
			if (dis(i,x) > dis(x,y))
				y = i;
			if (dis(i,y) > dis(x,y))
				x = i;
			if (c[i] != 0) z = i;
			ans += max(dis(x,z),dis(y,z));
//			printf("%d %d %d %d %lld\n",x,y,z,c[i],ans);
		}
		cout << ans << endl;
	}
}
