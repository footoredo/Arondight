#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int a[10][10],z[10][10],f[10],zz[10];
long long n,m;
void jzksm(int n,long long k){
	while (k != 0){
		if (k % 2 == 1){
			for (int i = 1; i <= n; i++)
				zz[i] = 0;
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= n; j++)
					zz[j] = (zz[j] + 1LL * f[i] * a[i][j]) % mod;
			for (int i = 1; i <= n; i++)
				f[i] = zz[i];
		}
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				z[i][j] = 0;
		for (register int i = 1; i <= n; i++)
			for (register int k = 1; k <= n; k++) if (a[i][k])
				for (register int j = 1; j <= n; j++)
					z[i][j] = (z[i][j] + 1LL * a[i][k] * a[k][j]) % mod;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				a[i][j] = z[i][j];
		k /= 2;
	}
}
int main(){
	int t;
	scanf("%d",&t);
	for (int tt = 1; tt <= t; tt++){
		scanf("%lld%lld",&n,&m);
//		if (tt == 1) std::cout << n << " " << m << std::endl;
//		return 0;
		f[1] = 1;
		f[2] = 0;
		f[3] = 2;
		f[4] = (mod - 1) % mod;
		f[5] = 0;
		f[6] = 0;
		for (int i = 1; i <= 6; i++)
			for (int j = 1; j <= 6; j++)
				a[i][j] = 0;
		a[1][3] = 2;
		a[2][4] = 2;
		a[1][5] = 1;
		a[2][6] = 1;
		a[3][1] = 1;
		a[4][2] = 1;
		a[3][3] = 1;
		a[4][4] = 1;
		a[5][5] = 1;
		a[6][6] = 1;
		jzksm(6,n);
		int a2 = (f[5] + f[6]) % mod;
		if (m == 1){
			printf("%d\n",1);
			continue;
		}
		f[1] = 1;
		f[2] = 0;
		f[3] = 2;
		f[4] = (mod - n % 2) % mod;
		f[5] = 0;
		f[6] = 0;
		for (int i = 1; i <= 6; i++)
			for (int j = 1; j <= 6; j++)
				a[i][j] = 0;
		a[1][3] = 2;
		a[2][4] = 2;
		a[1][5] = 1;
		a[2][6] = 1;
		a[3][1] = 1;
		a[4][2] = 1;
		a[3][3] = 1;
		a[4][4] = 1;
		a[5][5] = 1;
		a[6][6] = 1;
		jzksm(6,n);
		f[1] = a2;
		f[2] = f[6];
		for (int i = 1; i <= 2; i++)
			for (int j = 1; j <= 2; j++)
				a[i][j] = 0;
		a[1][1] = f[5];
		a[2][2] = 1;
		a[2][1] = 1;
		jzksm(2,m - 2);
		printf("%d\n",f[1]);
	}
}
