/* 
 * a^x = b (mod p)
 * p may not be a prime
 */
unordered_map<int,int> mp;

ll exbsgs(ll a,ll b,ll p)
{
	if (b == 1) return 0;
	ll t, d = 1, k = 0;
	while ((t = __gcd(a, p)) != 1) {
		if (b % t) return -1;
		++k, b /= t, p /= t, d = d * (a / t) % p;
		if (b == d) return k;
	}
	mp.clear();
	ll m = std::ceil(std::sqrt(p));
	ll a_m = powmod(a, m, p);
	ll mul = b;
	for (ll j = 1; j <= m; ++j) {
		mul = mul * a % p;
		mp[mul] = j;
	}
	for (ll i = 1; i <= m; ++i) {
		d = d * a_m % p;
		if (mp.count(d)) return i * m - mp[d] + k;
	}
	return -1;
}
