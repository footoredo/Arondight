#include <bits/stdc++.h>
using namespace std;
struct rec{
	long long data,next;
};
long long a[112345],v[112345],size[112345],h[112345],fa[112345],pp,z[112345][21],n,t;
long long d[112345];
rec e[212345];
void tian(long long x,long long y){
	pp++;
	e[pp].data = y;
	e[pp].next = a[x];
	a[x] = pp;
}
void dfs1(long long x){
	long long p = a[x];
	size[x] = 1;
	while (p != 0){
		if (e[p].data != fa[x]){
			fa[e[p].data] = x;
			h[e[p].data] = h[x] + 1;
			dfs1(e[p].data);
			size[x] += size[e[p].data];
		}
		p = e[p].next;
	}
}
void dfs2(long long x){
	long long p = a[x];
	if (x != 0)
		d[x] += size[x] * 2 - 1;
	while (p != 0){
		if (e[p].data != fa[x]){
			d[e[p].data] = d[x];
			dfs2(e[p].data);
		}
		p = e[p].next;
	}
}
long long lca(long long x,long long y){
	if (h[x] < h[y]) swap(x,y);
	for (long long i = 20; i >= 0; i--)
		if (h[z[x][i]] >= h[y])
			x = z[x][i];
	if (x == y) return x;
	for (long long i = 20; i >= 0; i--)
		if (z[x][i] != z[y][i]){
			x = z[x][i];
			y = z[y][i];
		}
	return fa[x];
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	for (long long tt = 1; tt <= t; tt++){
		cin >> n;
		for (long long i = 0; i < n; i++){
			a[i] = 0;
		}
		pp = 0;
		for (long long i = 1; i < n; i++){
			long long x,y;
			cin >> x >> y;
			tian(x,y);
			tian(y,x);
		}
		fa[0] = 0;
		dfs1(0);
		d[0] = 0;
		h[0] = 0;
		dfs2(0);/*
		for (long long i = 0; i < n; i++)
			prlong longf("%d ",size[i]);
		prlong longf("\n");
		for (long long i = 0; i < n; i++)
			prlong longf("%lld ",d[i]);
		prlong longf("\n");*/
		for (long long i = 0; i < n; i++)
			z[i][0] = fa[i];
		for (long long k = 1; k <= 20; k++)
			for (long long i = 0; i < n; i++)
				z[i][k] = z[z[i][k - 1]][k - 1];
		long long q;
		cin >> q;
		for (long long k = 1; k <= q; k++){
			long long p;
			cin >> p;
			for (long long i = 0; i <= p; i++){
				cin >> v[i];
			}
			long long ans = 0;
			for (long long i = 0; i < p; i++){
				long long x = lca(v[i],v[i + 1]);
//				prlong longf("%d %d %d %lld %lld\n",x,v[i],v[i + 1],d[v[i]],d[v[i + 1]]);
				ans += d[v[i]] - d[v[i + 1]] + (n * 2 - 2) * (h[v[i + 1]] - h[x]);
//				cout << ans << ".0000\n";
			}
			cout << ans << ".0000\n";
		}
		if (t != tt)
			cout<<endl;
	}
}
