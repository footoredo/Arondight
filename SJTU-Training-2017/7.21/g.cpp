#include <bits/stdc++.h>
using namespace std;
int n,m;
unsigned long long s[8][8],a[50],f[50][8];
double x,y;
int search(int i,int j,int k){
	if (i == 7){
		if (j == k) return 1;
		else return 0;
	}
	if ((i & 1) == 0){
		int ans = search(i + 1,j + 1,k) + search(i + 1,j,k);
		if ((i & 2) == 0)
		ans += search(i + 3,j,k);
		return ans;
	}
	if ((i & 2) == 0){
		int ans = search(i + 2,j + 2,k) + search(i + 2,j,k);
		if ((i & 4) == 0)
		ans += search(i + 6,j,k);
		return ans;
	}
	if ((i & 4) == 0){
		return search(i + 4,j + 4,k) + search(i + 4,j,k);
	}
	return 0;
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i = 1; i <= m; i++){
		scanf("%lf%lf",&x,&y);
		a[(int)x] |= (1 << (int)y);
	}
	f[0][0] = 1;
	for (int i = 0; i <= 7; i++)
		for (int j = 0; j <= 7; j++)
			s[i][j] = search(i,0,j);
	for (int i = 0; i < n; i++)
		for (int j = 0; j <= 7; j++)
			if ((j & a[i]) == 0)
				for (int k = 0; k <= 7; k++)
					f[i + 1][k] += f[i][j] * s[j | a[i]][k];
	cout << f[n][0] <<endl;
}
