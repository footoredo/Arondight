#include <bits/stdc++.h>

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
const int N = 1e2 + 20;
int n, m;
char G[N][N];

int Qx[N * N], Qy[N * N];
int d[N][N];
int BFS() {
	int ret = 0;
	int l = 0, r = 0;
	memset(d, -1, sizeof d);
	for (int i = 0; i < n; ++ i)
		for (int j = 0; j < m; ++ j)
			if (G[i][j] == '.') {
				d[i][j] = 0;
				Qx[r] = i;
				Qy[r] = j;
				++ r;
			}
	while (l < r) {
		int x = Qx[l], y = Qy[l]; ++ l;
		for (int t = 0; t < 4; ++ t) {
			int nx = x + dx[t], ny = y + dy[t];
			if (nx < n && ny < m && nx >= 0 && ny >= 0 && !~d[nx][ny]) {
				d[nx][ny] = d[x][y] + 1;
				ret = std::max(ret, d[nx][ny]);
				Qx[r] = nx;
				Qy[r] = ny;
				++ r;
			}
		}
	}
	return ret;
}

void print(int x, int width) {
	if (x == 0) {
		for (int i = 0; i < width; ++ i)
			std::cout << '.';
	}
	else if (x < 10) {
		for (int i = 0; i < width - 1; ++ i)
			std::cout << '.';
		std::cout << x;
	}
	else if (x < 100) {
		for (int i = 0; i < width - 2; ++ i)
			std::cout << '.';
		std::cout << x;
	}
	else {
		for (int i = 0; i < width - 3; ++ i)
			std::cout << '.';
		std::cout << x;
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cin >> n >> m;
	for (int i = 0; i <= m + 1; ++ i)
		G[0][i] = G[n + 1][i] = '.';
	for (int i = 1; i <= n; ++ i) {
		std::cin >> (G[i] + 1);
		G[i][m + 1] = G[i][0] = '.';
	}
	n += 2; m += 2;
	int maxd = BFS();
	int width = maxd < 10 ? 2 : 3;
//	std::cout << maxd << std::endl;
	for (int i = 1; i < n - 1; ++ i) {
		for (int j = 1; j < m - 1; ++ j)
			print(d[i][j], width);
		std::cout << '\n';
	}
}
