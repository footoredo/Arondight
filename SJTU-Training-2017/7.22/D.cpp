#include <bits/stdc++.h>

const int N = 55;
std::vector<int> f[N][N];
bool solved[N][N];
std::string s;

std::vector<int> solve(int l, int r) {
	if (solved[l][r]) return f[l][r];
	solved[l][r] = true;
	std::vector<int>& ans = f[l][r];
	ans.clear();
	std::unordered_set<int> hash;
	if (l == r) {
//		std::cout << s << std::endl;
		if (s[l] == 'I') ans.push_back(1);
		else if (s[l] == 'V') ans.push_back(5);
		else if (s[l] == 'X') ans.push_back(10);
		else if (s[l] == 'L') ans.push_back(50);
		else if (s[l] == 'C') ans.push_back(100);
		return ans;
	}
	else {
		for (int i = l; i < r; ++ i) {
//			if (s == "IVX") {
//				std::cout << s.substr(i, s.length() - i) << std::endl;
//			}
			auto ansl = solve(l, i),
				ansr = solve(i + 1, r);
			for (auto x: ansl) {
				for (auto y: ansr) {
//					if (s == "IVX")
//					std::cout << s << ": "<< x << " "<< y << std::endl;
					int tmp = -1;
					if (x >= y) {
						tmp = x + y;
					}
					else {
						tmp = y - x;
					}
					if (!hash.count(tmp)) {
						hash.insert(tmp);
						ans.push_back(tmp);
					}
				}
			}
		}
	}
	return ans;
}

int main() {
	int caseno = 0;
	while (std::cin >> s, s != "0") {
		++ caseno;
		memset(solved, false, sizeof solved);
		auto ans = solve(0, s.length() - 1);
		std::cout << "Case " << caseno << ":";
		std::sort(ans.begin(), ans.end());
		for (auto x: ans) std::cout << ' ' << x;
		std::cout << '\n';
	}
}
