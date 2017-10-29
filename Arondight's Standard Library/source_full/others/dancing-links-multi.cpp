#include<bits/stdc++.h>
using namespace std;
const int maxnode = 51111, MaxN = 55555, MaxM = 55555;
int n, m;
struct DLX{
	int n,m,SIZE;
	int U[maxnode],D[maxnode],R[maxnode],L[maxnode],Row[maxnode],Col[maxnode];
	int H[MaxN],S[MaxM];
	int ansd, ans[MaxN];
	void init(int _n,int _m) {
		n = _n;
		m = _m;
		for (int i = 0; i <= m; ++i) {
			S[i] = 0;
			U[i] = D[i] = i;
			L[i] = i - 1;
			R[i] = i + 1;
		}
		R[m] = 0; L[0] = m;
		SIZE = m;
		for (int i = 1; i <= n; ++i) H[i] = -1;
	}
	void Link(int r,int c) {
		++S[Col[++SIZE]=c];
		Row[SIZE] = r;
		D[SIZE] = D[c];
		U[D[c]] = SIZE;
		U[SIZE] = c;
		D[c] = SIZE;
		if (H[r] < 0) H[r] = L[SIZE] = R[SIZE] = SIZE;
		else {
			R[SIZE] = R[H[r]];
			L[R[H[r]]] = SIZE;
			L[SIZE] = H[r];
			R[H[r]] = SIZE;
		}
	}
	void repeat_remove(int c) {
		for (int i = D[c]; i != c; i = D[i])
			L[R[i]] = L[i], R[L[i]] = R[i];
	}
	void repeat_resume(int c) {
		for (int i = U[c]; i != c; i = U[i])
			L[R[i]] = R[L[i]] = i;
	}
	int f() {
		bool vv[MaxM];
		int ret = 0, c, i, j;
		for (c = R[0]; c != 0; c = R[c]) vv[c] = 1;
		for (c = R[0]; c != 0; c = R[c]) 
			if (vv[c]) {
				++ret, vv[c] = 0;
				for (i = D[c]; i != c; i = D[i])	
					for (j = R[i]; j != i; j = R[j]) vv[Col[j]] = 0;
			}
		
		return ret;
	}
	void repeat_dance(int d) {
		if (d + f() >= ansd) return;
		if (R[0] == 0) {
			if (d < ansd) ansd = d;
			return;
		}
		int c = R[0], i, j;
		for (i = R[0]; i; i = R[i]) if (S[i] < S[c]) c = i;
		for (i = D[c]; i != c; i = D[i]) {
			repeat_remove(i);
			for (j = R[i]; j != i; j = R[j]) repeat_remove(j);
			repeat_dance(d + 1);
			for (j = L[i]; j != i; j = L[j]) repeat_resume(j);
			repeat_resume(i);
		}
	}
};
DLX g;
void work() {
	g.init(n, m);
	for (int i = 1; i <= m; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		g.Link(x, i);
		g.Link(y, i);
	}
	g.ansd = n;
	g.repeat_dance(0);
	cout << g.ansd << endl;
}
int main() {
	while (~scanf("%d%d", &n, &m)) work();
	return 0;
}
