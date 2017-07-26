#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long N = 1e6 + 6;
long long a[N],l[N],r[N],s[N],ss[N];
long long qs(long long l,long long r){
	return (r - l + 1) * (l + r) / 2 % mod;
}
long long ef(long long ll,long long rr,long long x){
	if (ll == rr) return ll;
	if (r[(ll + rr) / 2] < x) return ef((ll + rr) / 2 + 1,rr,x);
	return ef(ll,(ll + rr) / 2,x);
}
int main() {
	a[1] = 1;
	a[2] = 2;
	long long pp = 0;
	r[0] = 0;
	ss[0] = 0;
	for (long long i = 1; i < N; i++){
		for (long long j = 1; j <= min(N - 1 - pp,a[i]); j++)
			a[j + pp] = i;
		pp += min(N - pp,a[i]);
		l[i] = r[i - 1] + 1;
		r[i] = r[i - 1] + a[i];
		s[i] = qs(l[i],r[i]) * i % mod;
		ss[i] = (s[i] + ss[i - 1]) % mod;
//		cout << i << " " << l[i] <<" " <<  r[i] <<" " <<  s[i] <<" " <<  ss[i] <<" " <<  endl;
	}/*
	for (int i = 1; i <= 1000; i++){
		printf("%d ",a[i]);
	}*/
//	printf("%lld\n",r[N - 1]);
	long long t,n;
	cin >> t;
	for (long long i = 1; i <= t; i++){
		cin >> n;
		long long x = ef(1,N,n);
//		cout << x << endl;
		cout << (ss[x - 1] + qs(l[x],n) * x) % mod << endl;
	}
}

