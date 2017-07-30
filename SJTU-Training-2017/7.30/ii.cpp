#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
const int maxn = 100000;
const int N = 100005;
struct rec{
	int x,y;
};
int p[N],mu[N],ny[N],a[N],t,pp,sp,n;
int v[N];
bool pd[N];
int ksm(int x,int k){
	if (k == 0) return 1;
	long long ans = ksm(x,k / 2);
	ans = ans * ans % mod;
	if (k % 2 == 1)
	ans = ans * x % mod;
	return ans;
}
template <typename T>
__inline void clear(T& container){
	container.clear();
	T(container).swap(container);
}
int main(){
	for(int i = 1; i <= maxn; i++)
		ny[i] = ksm(i, mod - 2);
	for(int i = 1; i <= maxn; i++)
		pd[i] = true;
	mu[1] = 1;
	pp = 0;
	for(int i = 2; i <= maxn; i++){
		if (pd[i]){
			p[++pp] = i;
			mu[i] = -1;
		}
		for (int j = 1; j <= pp; j++){
			if (i * p[j] > maxn) break;
			if (i % p[j] == 0){
				mu[i * p[j]] = 0;
				pd[i * p[j]] = false;
				break;
			}
			mu[i * p[j]] = -mu[i];
			pd[i * p[j]] = false;
		}
	}
//		v[i].clear();
	sp = pp;
	pp = 0;
	scanf("%d",&t);
	for (int tt = 1; tt <= t; tt++){
		for(int i = 1; i <= maxn; i++)
			v[i] = 1;
		scanf("%d",&n);
		long long s = 1;
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%d",&a[i]);
			//a[i] = 1e5;
		}
		int minai = 1000000;
		for (int i = 1; i <= n; i++)
			minai = min(a[i],minai);/*
		for (int i = 1; i <= n; i++){
			rec x;
			x.y = a[i] / 2;
			x.x = i;
			v[a[i] / (a[i] / 2) + 1].push_back(x);
		}*/
		for (int i = 1; i <= n; i++){
			s = s * (a[i] / 2) % mod;
		}
//		int tot = 0;
		for (int i = 1; i <= n; i++){
			register int last = a[i] / 2, aa = a[i];
			int x = sqrt(a[i]) + eps;
			for (register int j = 3; j <= x; j++){
				pp = j;
				++ tot;
//				int x = a[i] / pp;
				register int& vv = v[pp];
				vv = 1LL * vv * ny[last] % mod;
				vv = 1LL * vv * (last = aa / pp) % mod;
//				last = aa / pp;
			}
			x = sqrt(a[i]) - eps;
			for (register int j = x; j >= 1; j--){
				pp = a[i] / j;
				++ tot;
//				int x = a[i] / pp;
				register int& vv = v[pp];
				vv = 1LL * vv * ny[last] % mod;
				vv = 1LL * vv * (last = aa / pp) % mod;
//				last = aa / pp;
			}
		}
//		std::cout << tot << std::endl;
		ans = s;
//		printf("!!!!!!%d\n",ans);
		for (int i = 3; i <= minai; i++){
//			printf("!!!!!!%d\n",i);
			s = s * v[i] % mod;/*
			for (int j = 0; j < v[i].size(); j++){
				rec x = v[i][j];
				s = s * ny[x.y] % mod;
				s = s * (a[x.x] / i) % mod;
				x.y = a[x.x] / i;
				v[a[x.x] / (a[x.x] / i) + 1].push_back(x);
			}*/
			ans = (ans + (-mu[i]) * s + mod) % mod;
	//		clear(v[i]);
	//		printf("%d %d %lld\n",i,ans,s);
		}
		printf("Case #%d: %d\n",tt,ans);
	}
}


