#include <bits/stdc++.h>
typedef unsigned long long KEY;

const int N = 3e3 + 3;
const int M = 1e9 + 7;
std::unordered_map<KEY, int> hash[N];
std::unordered_set<KEY> counted[N];
KEY pw[N];
int A[N], B[N];

int main () {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	while (std::cin >> n, n) {
		for (int i = 2; i <= n; ++ i) {
			hash[i].clear();
			counted[i].clear();
		}
		pw[0] = 1; for (int i = 1; i <= n; ++ i) pw[i] = M * pw[i - 1];
		for (int i = 0; i < n; ++ i) std::cin >> A[i];
		for (int i = 0; i < n; ++ i) std::cin >> B[i];

		for (int i = 1; i < n; ++ i) {
			KEY cur = 0;
			for (int j = i; j >= 0; -- j) {
				cur += pw[A[j]];
				++ hash[i - j + 1][cur];
			}
		}

		KEY ans = 0;
		for (int i = 1; i < n; ++ i) {
			KEY cur = 0;
			for (int j = i; j >= 0; -- j) {
				cur += pw[B[j]];
				if (i - j + 1 >= 2/* && !counted[i - j + 1].count(cur)*/) {
					ans += hash[i - j + 1][cur];
//					counted[i - j + 1].insert (cur);
				}
			}
		}

		std::cout << ans << std::endl;
	}
}
