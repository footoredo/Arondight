#include <bits/stdc++.h>
using namespace std;
struct rec{
	int v,s;
};
const int inf = 1000000000;
const int maxans = 50000;
rec a[5000],b[5000];
int f[51234],n,m,s,v,t,T,pp,ppp;
void update1(int &x,int y){
	x = min(x,y);
}
void update2(int &x,int y){
	x = max(x,y);
}
int main(){
	scanf("%d",&T);
	for (int tt = 1; tt <= T; tt++){
		scanf("%d%d%d",&n,&m,&ppp);
		pp = 0;
		for (int i = 1; i <= n; i++){
			scanf("%d%d%d",&v,&s,&t);
			int p = 1;
			while (t > p){
				pp++;
				a[pp].v = v * p;
				a[pp].s = s * p;
				t -= p;
				p *= 2;
			}
			if (t != 0){
				pp++;
				a[pp].v = v * t;
				a[pp].s = s * t;
			}
		}
		n = pp;
		pp = 0;
		for (int i = 1; i <= m; i++){
			scanf("%d%d%d",&s,&v,&t);
			int p = 1;
			while (t > p){
				pp++;
				b[pp].v = v * p;
				b[pp].s = s * p;
				t -= p;
				p *= 2;
			}
			if (t != 0){
				pp++;
				b[pp].v = v * t;
				b[pp].s = s * t;
			}
		}
		m = pp;
		for (int i = 1; i <= ppp; i++)
			f[i] = inf;
		f[0] = 0;
//		printf("%d\n",ppp);
		for (int i = 1; i <= n; i++)
			for (int j = ppp; j >= 0; j--)
				if (f[j] != inf){
					if (a[i].v + j <= ppp)
						update1(f[j + a[i].v],f[j] + a[i].s);
					else
						update1(f[ppp],f[j] + a[i].s);
				}
		s = f[ppp];
//		printf("%d\n",s);
		for (int i = 1; i <= maxans; i++)
			f[i] = 0;
		f[0] = 0;
//		printf("%d\n",m);
		for (int i = 1; i <= m; i++)
			for (int j = maxans; j >= 0; j--)
				if (f[j] != inf)
					if (b[i].v + j <= maxans)
						update2(f[j + b[i].v],f[j] + b[i].s);
		int ans = -1;
		for (int j = 0; j <= maxans; j++)
			if (f[j] >= s){
				ans = j;
				break;
			}
		if (ans == -1) printf("TAT\n");
		else printf("%d\n",ans);
	}
}
