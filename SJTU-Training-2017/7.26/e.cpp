#include <bits/stdc++.h>
using namespace std;
struct rec{
	int x,y,c;
};
int size[112345],n,m,q,s,t,fa[112345],ans[1123456];
rec a[112345];
bool cmp(const rec &a,const rec &b){
	return a.c < b.c;
}
void bin(int x,int y){
	while (fa[x] != 0)
		x = fa[x];
	while (fa[y] != 0)
		y = fa[y];
	if (x == y) return;
	s -= size[x] * (size[x] - 1) + size[y] * (size[y] - 1);
	if (size[x] < size[y]){
		fa[x] = y;
		size[y] += size[x];
		s += size[y] * (size[y] - 1);
	} else {
		fa[y] = x;
		size[x] += size[y];
		s += size[x] * (size[x] - 1);
	}
}
int main(){
	scanf("%d",&t);
	for (int tt = 1; tt <= t; tt++){
		scanf("%d%d%d",&n,&m,&q);
		for (int i = 1; i <= m; i++)
			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].c);
		sort(a + 1,a + m + 1,cmp);
		for (int i = 1; i <= n; i++)
			fa[i] = 0;
		for (int i = 1; i <= n; i++)
			size[i] = 1;
		s = 0;
		int p = 1;
		for (int i = 0; i <= 1000000; i++){
			while (a[p].c <= i && p <= m){
				bin(a[p].x,a[p].y);
				p++;
			}
			ans[i] = s;
		}
		for (int i = 1; i <= q; i++){
			int x;
			scanf("%d",&x);
			if (x > 1000000) x = 1000000;
			printf("%d\n",ans[x]);
		}
	}
}
