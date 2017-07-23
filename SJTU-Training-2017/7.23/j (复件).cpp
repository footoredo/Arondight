#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
const int maxn = 205;
int u,d,a[maxn],b[maxn];
long long n,aa[maxn + 1][maxn + 1],z[maxn + 1][maxn + 1],f[maxn + 1],zz[maxn + 1];
void ksm(long long k){
	if (k == 0) return;
	if (k % 2 == 1) {
		for (int i = 1; i <= maxn; i++)
			zz[i] = 0;
		for (int i = 1; i <= maxn; i++)
			for (int j = 1; j <= maxn; j++)
				zz[j] = (f[i] * aa[i][j] + zz[j]) % mod;
		for (int i = 1; i <= maxn; i++)
			f[i] = zz[i];
	}
	for (int i = 1; i <= maxn; i++)
		for (int j = 1; j <= maxn; j++)
			z[i][j] = 0;
	for (int i = 1; i <= maxn; i++)
		for (int j = 1; j <= maxn; j++)
			for (int k = 1; k <= maxn; k++)
				z[i][k] = (z[i][k] + aa[i][j] * aa[j][k]) % mod;
	for (int i = 1; i <= maxn; i++)
		for (int j = 1; j <= maxn; j++)
			aa[i][j] = z[i][j];/*
	printf("\n");
	for (int i = 1; i <= maxn; i++){
		for (int j = 1; j <= maxn; j++)
			printf("%d ",aa[i][j]);
		printf("\n");
	}
	printf("\n");*/
	ksm(k / 2);
}
int main(){
	while (cin >> n){
		cin >> u;
		for (int i = 1; i <= maxn; i++)
			for (int j = 1; j <= maxn; j++)
				aa[i][j] = 0;
		for (int i = 1; i <= u; i++)
			cin >> a[i];
		cin >> d;
		for (int i = 1; i <= d; i++)
			cin >> b[i];
		for (int k = 1; k <= d; k++){
			for (int i = 1; i <= b[k]; i++)
				f[i] = 0;
			f[0] = 1;
			for (int i = 0; i <= b[k]; i++){
				for (int j = 1; j <= u; j++)
					if (i + a[j] <= b[k]) f[i + a[j]] = (f[i + a[j]] + f[i]) % mod;
			}
			aa[maxn + 1 - b[k]][maxn] += f[b[k]];
			//cout << f[b[k]] << endl;
		}
		for (int i = 1; i < maxn; i++)
			aa[i + 1][i] = 1;
		for (int i = 1; i <= maxn; i++)
			f[i] = 0;
		f[maxn] = 1;
		ksm(n);
		cout << f[maxn] << endl;;
	}
}
