#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
const int M = 205;
const int m = 200;
int u,d,aa[M * 2],b[M],f[M],a[M],c[M];
long long n;
int linear_recurrence(long long n, int m, int a[], int c[], int p){
	long long v[M] = {1 % p}, u[M << 1],msk = !!n;
	for (long long i(n); i > 1; i >>= 1)
		msk <<= 1;
	for (long long x(0); msk; msk >>= 1, x <<= 1){
		fill_n(u, m << 1, 0);
		int b(!!(n & msk));
		x |= b;
		if (x < m){
			u[x] = 1 % p;
		} else {
			for (int i(0); i < m; i++)
				for (int j(0), t(i + b); j < m; j++, t++)
					u[t] = (u[t] + v[i] * v[j]) % p;
			for (int i((m << 1) - 1); i >= m; i--)
				for (int j(0),t(i - m); j < m; j++, t++)
					u[t] = (u[t] + c[j] * u[i]) % p;
		}
		copy(u, u + m, v);
	}
	long long ans = 0;
	for (int i = 0; i < m; i++)
		ans += v[i] * a[i] % p;
	return ans % p;/*
	for (int i(m); i < 2 * m; i++){
		a[i] = 0;
		for (int j(0); j < m; j++){
			a[i] = (a[i] + (long long)c[j] * a[i + j - m]) % p;
		}
	}
	for (int j(0); j < m; j++){
		b[j] = 0;
		for (int i(0); i < m; i++){
			b[j] = (b[j] + v[i] * a[i + j]) % p;
		}
	}
	for (int j(0); j < m; j++)
		a[j] = b[j];
	long long ans = 0;
	for (int i = 0; i < m; i++)
		ans += v[i] * a[i] % p;
	return ans % p;*/
}
int main(){
	while (cin >> n){
		cin >> u;
		for (int i = 1; i <= u; i++)
			cin >> aa[i];
		cin >> d;
		for (int i = 1; i <= d; i++)
			cin >> b[i];
		for (int i = 0; i < m; i++)
			c[i] = 0;
		for (int k = 1; k <= d; k++){
			for (int i = 1; i <= b[k]; i++)
				f[i] = 0;
			f[0] = 1;
			for (int i = 0; i <= b[k]; i++){
				for (int j = 1; j <= u; j++)
					if (i + aa[j] <= b[k]) f[i + aa[j]] = (f[i + aa[j]] + f[i]) % mod;
			}
			c[m - b[k]] = f[b[k]];
		}
		for (int i = 0; i < m - 1; i++)
			a[i] = 0;
		a[m - 1] = 1;
		printf("%d\n",linear_recurrence(n + m - 1,m,a,c,mod));
	}
}
