#include <bits/stdc++.h>
using namespace std;
struct rec{
	int data,next;
} e[200000];
int ans,ansd,ansi,top,tt,n,m,a[200000],t[200000],d1[200000],d2[200000];
char ansfx,st[100];
void dfs1(int x,int k){
	if (d1[x] != 100000) return;
	d1[x] = k;
	if (t[x] != -1)
	dfs1(t[x],k + 1);
}
void dfs2(int x, int k){
	if (d2[x] != 100000) return;
	d2[x] = k;
	int p = a[x];
	while (p != 0){
		dfs2(e[p].data,k + 1);
		p = e[p].next;
	}
}
void tian(int x,int y){
	t[x] = y;
	top++;
	e[top].data = x;
	e[top].next = a[y];
	a[y] = top;
}
int main(){
	tt = 0;
	for (scanf("%d%d",&n,&m); n != 0 && m != 0; scanf("%d%d",&n,&m)){
		tt++;
		for (int i = 0; i < n * m; i++)
			a[i] = 0;
		for (int i = 0; i < n * m; i++)
			t[i] = -1;
		top = 0;
//		printf("%d %d\n",n,m);
		for (int i = 0; i < n * m - 1; i++){
			scanf("%s",st); 
			int len = strlen(st);
			char d = st[len - 1];
			st[len - 1] = 0;
			int x;
			sscanf(st, "%d", &x);
	//		printf("%d %c%d\n",i,d,x);
			if (d == 'E'){
				if (i % m + x < m)
					tian(i,i + x);
			}
			if (d == 'W'){
				if (i % m - x >= 0)
					tian(i,i - x);
			}
			if (d == 'N'){
				if (i - x * m >= 0)
					tian(i,i - x * m);
			}
			if (d == 'S'){
				if (i + x * m < n * m)
					tian(i,i + x * m);
			}
			d1[i] = 100000;
			d2[i] = 100000;
		}
		d1[n * m - 1] = 100000;
		d2[n * m - 1] = 100000;
		dfs1(0,0);
		dfs2(n * m - 1,0);
//		for (int i = 0; i < n * m; i++)
//			printf("%d ",d1[i]);
//		printf("\n");
		ans = d2[0];
		for (int i = 0; i < n * m - 1; i++)
			for (int j = 1; j < m + n; j++){
				if (i % m + j < m)
					if (d2[i + j] + d1[i] + 1 < ans){
						ans = d2[i + j] + d1[i] + 1;
						ansi = i;
						ansd = j;
						ansfx = 'E';
					}
				if (i - j * m >= 0)
					if (d2[i - j * m] + d1[i] + 1 < ans){
						ans = d2[i - j * m] + d1[i] + 1;
						ansi = i;
						ansd = j;
						ansfx = 'N';
					}
				if (i + j * m < n * m)
					if (d2[i + j * m] + d1[i] + 1 < ans){
						ans = d2[i + j * m] + d1[i] + 1;
						ansi = i;
						ansd = j;
						ansfx = 'S';
					}
				if (i % m - j >= 0)
					if (d2[i - j] + d1[i] + 1 < ans){
						ans = d2[i - j] + d1[i] + 1;
						ansi = i;
						ansd = j;
						ansfx = 'W';
					}
			}
		if (ans == 100000) printf("Case %d: impossible\n",tt);
		else if (ans == d2[0]) printf("Case %d: none %d\n",tt,ans);
			else printf("Case %d: %d %d %d%c %d\n",tt,ansi / m,ansi % m,ansd,ansfx,ans);
	}
}
