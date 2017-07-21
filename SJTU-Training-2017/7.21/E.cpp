#include <bits/stdc++.h>

const int N = 1e2 + 2, M = N * N;
int n, m, s, t;
int adj[N], v[M], nxt[M], e;
__inline void ins(int u0, int v0) {
	v[e] = v0; nxt[e] = adj[u0]; adj[u0] = e ++;
}

long long num[N][20];
long long ans[20];

int main() {
	std::cin >> n >> m >> s >> t;
	num[s][0] = 1;
	memset(adj, -1, sizeof adj);
	for (int i = 0; i < m; ++ i) {
		int x, y; std::cin >> x >> y;
		ins(x, y); ins(y, x);
	}

	for (int i = 0; i < t; ++ i) {
//		for (int j = 0; j < n; ++ j)
//			std::cout << num[j][i] << " ";
//		std::cout << std::endl;
		for (int j = 0; j < n; ++ j) {
//			ans[i] += num[j][i];
//			num[j][i + 1] += num[j][i];
			for (int e = adj[j]; ~e; e = nxt[e]) {
				num[v[e]][i + 1] += num[j][i];
				ans[i] += num[j][i];
			}
		}
	}

	std::cout << ans[t - 1] << std::endl;
}
