#include <bits/stdc++.h>
typedef unsigned long long KEY;

const int N = 3e3 + 3;
const int M = 1e9 + 7;
KEY pw[N];
int A[N], B[N];
int where[N];

int main () {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	while (std::cin >> n, n) {
		for (int i = 0; i < n; ++ i) {
			std::cin >> A[i];
			where[A[i]] = i;
		}
		for (int i = 0; i < n; ++ i) {
			std::cin >> B[i];
		}

		KEY ans = 0;
		for (int i = 1; i < n; ++ i) {
			int left = n, right = -1;
			for (int j = i; j >= 0; -- j) {
				left = std::min(left, where[B[j]]);
				right = std::max(right, where[B[j]]);
				if (i - j + 1 >= 2 && right - left + 1 == i - j + 1)
					++ ans;
			}
		}

		std::cout << ans << std::endl;
	}
}
