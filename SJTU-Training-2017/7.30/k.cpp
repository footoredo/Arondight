#include <bits/stdc++.h>
using namespace std;
map<pair<int,int>,int> Map;
pair<int,int> a[10000];
int n;
int main(){
	while (scanf("%d",&n) == 1){
		Map.clear();
		for (int i = 1; i <= n; i++){
			scanf("%d%d",&a[i].first,&a[i].second);
			Map[a[i]] = 1;
		}
		int ans = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (i != j){
					if (Map[make_pair(a[j].second - a[i].second + a[i].first,a[i].first - a[j].first + a[i].second)] == 1
					&& Map[make_pair(a[j].second - a[i].second + a[j].first,a[i].first - a[j].first + a[j].second)] == 1)
					ans++;
				}
		ans /= 4;
		printf("%d\n",ans);
	}
}
