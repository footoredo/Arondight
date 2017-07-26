#include <bits/stdc++.h>
using namespace std;
struct rec{
	int data,next;
};
rec e[300000];
int rd[20000],cd[20000],a[20000],q[20000],n,m,top;
double ll[20000],maxl[20000];
void tian(int x,int y){
	top++;
	e[top].data = y;
	e[top].next = a[x];
	a[x] = top;
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i = 1; i <= n; i++)
		scanf("%lf%lf",&maxl[i],&ll[i]);
	for (int i = 1; i <= n; i++)
		rd[i] = 0;
	for (int i = 1; i <= n; i++)
		cd[i] = 0;
	for (int i = 1; i <= n; i++)
		a[i] = 0;
	for (int i = 1; i <= m; i++){
		int x,y;
		scanf("%d%d",&x,&y);
		rd[y]++;
		cd[x]++;
		tian(x,y);
	}
	{
		int x,y;
		scanf("%d%d",&x,&y);
		ll[x] += y;
	}
	int l = 1;
	int r = 0;
	for (int i = 1; i <= n; i++)
		if (rd[i] == 0)
			q[++r] = i;
	while (l <= r){
		int p = a[q[l]];
		while (p != 0){
			ll[e[p].data] += max(ll[q[l]] - maxl[q[l]], 0.0) / cd[q[l]];
			rd[e[p].data]--;
			if (rd[e[p].data] == 0)
				q[++r] = e[p].data;
			p = e[p].next;
		}
		if (ll[q[l]] > maxl[q[l]])
			ll[q[l]] = maxl[q[l]];
		l++;
	}
	{
		int x;
		scanf("%d",&x);
		printf("%.10f\n",ll[x]);
	}
}
