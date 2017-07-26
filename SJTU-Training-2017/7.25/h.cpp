#include <bits/stdc++.h>
using namespace std;
double f[4001][4001],g[4001][4001];
bool visited[4001];
struct xiaoshu{
	double x;
	int w;
	xiaoshu(double x, int w): x(x), w(w) {}
	xiaoshu operator + (const xiaoshu &a){
		if (w - a.w > 10) return xiaoshu(x,w);
		if (w - a.w < -10) return a;
		if (w = a.w) {
			xiaoshu b = xiaoshu(x + a.x,w);
			if (b.x >= 10){
				b.w++;
				b.x /= 10;
			}
		}
	}
};
void search(int x){
	if (visited[x]) return;
	visited[x] = true;
	search(a[x]);
}
int main(){
	cout << sizeof(f)*2 / 1024 / 1024 <<endl;
	cout << fixed << setprecision(20);
	f[0][0] = 0;
	g[0][0] = 1;
	f[0][1] = 0;
	g[0][1] = 0;
	f[1][0] = 1;
	g[1][0] = 1;
	for (int s = 2; s <= maxn; s++){
		f[0][s] = (s - 1) * f[1][s - 2];
		g[0][s] = (s - 1) * g[1][s - 2];
		for (int i = 1; i <= s; i++){
			j = s - i;
			f[i][j] = i * f[i - 1][j] + g[i - 1][j] + j * f[i][j - 1];
			g[i][j] = i * g[i - 1][j] + j * g[i][j - 1];
		}
	}
	scanf("%d",&t);
	for (int tt = 1; tt <= t; tt++){
		scanf("%d",&n,&c);
		for (int i = 1; i <= n; i++)
			visited[i] = false;
		for (int i = 1; i <= n; i++)
			scanf("%d",&a[i]);
		int bian = 0;
		int dian = 0;
		int huan = 0;
		for (int i = 1; i <= n; i++)
			b[i] = 0;
		for (int i = 1; i <= n; i++)
			b[a[i]] = i;
		for (int i = 1; i <= n; i++)
			visited[i] = false;
		for (int i = 1; i <= n; i++)
			if (b[i] == 0)
				if (a[i] == 0){
					visited[i] = true;
					dian++;
				} else {
					search(i);
					bian++;
				}
		for (int i = 1; i <= n; i++)
			if (!visited[i]){
				search(i);
				huan++;
			}
		cout << f[bian][dian] / g[bian][dian] + huan << endl;
	}
}
