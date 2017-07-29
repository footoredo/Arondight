#include <bits/stdc++.h>
#define stack STACK
using namespace std;
const int N = 2000;
vector <int> edge[N];
int n;
char st[N];
bool pd[N];
int stamp, comps, top;
int dfn[N],low[N],comp[N],stack[N];
void tarjan(int x){
	dfn[x] = low[x] = ++stamp;
	stack[top++] = x;
	for (int i = 0; i < (int)edge[x].size(); ++i){
		int y = edge[x][i];
		if (!dfn[y]){
			tarjan(y);
			low[x] = min(low[x],low[y]);
		} else if (!comp[y]){
			low[x] = min(low[x],dfn[y]);
		}
	}
	if (low[x] == dfn[x]){
		comps++;
		do {
			int y = stack[--top];
			comp[y] = comps;
		} while (stack[top] != x);
	}
}
void solve(){
	stamp = comps = top = 0;
	fill(dfn, dfn + n, 0);
	fill(comp, comp + n, 0);
	for (int i = 0; i < n; i++){
		if (!dfn[i]){
			tarjan(i);
		}
	}
}
int main(){
	for (scanf("%d",&n); n != 0; scanf("%d",&n)){
		for (int i = 0; i < n - 1; i++){
			scanf("%s",st + 1);
			for (int j = 1; j < n - i; j++){
				if (st[j] == '1') edge[i].push_back(i + j);
				else edge[i + j].push_back(i);
			}
		}
		solve();
		for (int i = 1; i <= comps; i++)
			pd[i] = true;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < (int)edge[i].size(); ++j){
				if (comp[edge[i][j]] != comp[i])
					pd[comp[edge[i][j]]] = false;
			}
		int ans = 0;
		for (int i = 0; i < n; i++)
			if (pd[comp[i]])
				ans++;
		printf("%d\n",ans);
		for (int i = 0; i < n; i++)
			edge[i].clear();
	}
}
