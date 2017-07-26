#include <bits/stdc++.h>
typedef double DB;
const DB eps = 1e-5;

__inline int sign(DB x) {
	return (x > eps) - (x < -eps);
}

std::vector<std::pair<DB, int> > pos, neg;
std::vector<int> ans;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);

	int n; std::cin >> n;
	int zero = -1;
	for (int i = 0; i < n; ++ i) {
		DB x; std::cin >> x;
		if (sign(x) > 0) pos.emplace_back(x, i);
		else if (sign(x) < 0) neg.emplace_back(-x, i);
		else zero = i;
	}

	std::sort(pos.begin(), pos.end());
	std::reverse(pos.begin(), pos.end());
	std::sort(neg.begin(), neg.end());
	std::reverse(neg.begin(), neg.end());

	if (pos.size() == 0) {
		if (neg.size() < 2u){
			if (~zero) {
				ans.push_back(zero);
			}
			else {
				ans.push_back(neg.back().second);
			}
		}
		else {
			ans.push_back(neg[0].second);
			ans.push_back(neg[1].second);
			for (int i = 2; i + 1 < (int) neg.size(); i += 2)
				if (neg[i].first * neg[i + 1].first> 1 + eps) {
					ans.push_back(neg[i].second);
					ans.push_back(neg[i + 1].second);
				}
		}
	}
	else {
		for (int i = 0; i < (int) pos.size(); ++ i)
			if (pos[i].first > 1 + eps) ans.push_back(pos[i].second);
		for (int i = 0; i + 1 < (int) neg.size(); i += 2)
			if (neg[i].first * neg[i + 1].first> 1 + eps) {
				ans.push_back(neg[i].second);
				ans.push_back(neg[i + 1].second);
			}
		if (!ans.size()) {
			if ((neg.size() >= 2 && pos[0].first + eps < neg[0].first * neg[1].first)) {
				ans.push_back(neg[0].second);
				ans.push_back(neg[1].second);
			}
			else {
				ans.push_back(pos[0].second);
			}
		}
	}

	std::cout << ans.size() << std::endl;
	std::sort(ans.begin(), ans.end());
	for (int x: ans)
		std::cout << x + 1 << " ";
	std::cout << std::endl;
}
