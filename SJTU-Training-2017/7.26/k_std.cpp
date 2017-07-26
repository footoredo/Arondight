#include <bits/stdc++.h>

char tmp[100];

long long abs (const long long &x) { return x > 0 ? x : -x; }

long long gcd (const long long &a, const long long &b) {
	if (!b) return a;
	long long x = a, y = b;
	while (x > y ? (x = x % y) : (y = y % x));
	return x + y;
}

long long mul_mod (const long long &a, const long long &b, const long long &mod) {
	long long d = (long long) floor (a * (double) b / mod + 0.5);
	long long ret = a * b - d * mod;
	if (ret < 0) ret += mod;
	return ret;
}

long long llfpm (const long long &x, const long long &n, const long long &mod) {
	long long ans = 1, mul = x, k = n;
	while (k) {
		if (k & 1) ans = mul_mod (ans, mul, mod);
		mul = mul_mod (mul, mul, mod);
		k >>= 1;
	}
	return ans;
}

__int128 gcd (__int128 x, __int128 y) {
	if (x == 0) return y;
	if (y == 0) return x;
	return gcd (y, x % y);
}

int BASE[12] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};

struct miller_rabin {
	bool check (const long long &prime, const long long &base) {
		long long number = prime - 1;
		for (; ~number & 1; number >>= 1);
		long long result = llfpm (base, number, prime);
		for (; number != prime - 1 && result != 1 && result != prime - 1; number <<= 1)
			result = mul_mod (result, result, prime);
		return result == prime - 1 || (number & 1) == 1;
	}
	bool solve (const long long &number) {
		if (number < 2) return false;
		if (number < 4) return true;
		if (~number & 1) return false;
		for (int i = 0; i < 12 && BASE[i] < number; ++i)
			if (!check (number, BASE[i]))
				return false;
		return true;
	}
};

struct pollard_rho {
	miller_rabin is_prime;
	const long long threshold = 13E9;
	long long factorize (const long long &number, const long long &seed) {
		long long x = rand () % (number - 1) + 1, y = x;
		for (int head = 1, tail = 2; ; ) {
			x = mul_mod (x, x, number);
			x = (x + seed) % number;
			if (x == y)
				return number;
			long long answer = gcd (abs (x - y), number);
			if (answer > 1 && answer < number)
				return answer;
			if (++head == tail) {
				y = x;
				tail <<= 1;
			}
		}
	}
	void search (const long long &number, std::vector <__int128> &divisor) {
		if (number > 1) {
			if (is_prime.solve (number))
				divisor.push_back (number);
			else {
				long long factor = number;
				for (; factor >= number; factor = factorize (number, rand () % (number - 1) + 1));
				search (number / factor, divisor);
				search (factor, divisor);
			}
		}
	}
	std::vector <__int128> solve (const long long &number) {
		std::vector <__int128> ans;
		if (number > threshold)
			search (number, ans);
		else {
			long long rem = number;
			for (long long i = 2; i * i <= rem; ++i)
				while (!(rem % i)) {
					ans.push_back (i);
					rem /= i;
				}
			if (rem > 1) ans.push_back (rem);
		}
		return ans;
	}
};

pollard_rho _p;

__int128 get_sqr (const __int128 &n) {
	__int128 l = 1, r = 1000000000000LL;
	while (l <= r) {
		__int128 m = (l + r) / 2;
		if (m * m == n) return m;
		if (m * m < n)
			l = m + 1;
		else
			r = m - 1;
	}
	return -1;
}

__int128 get_cub (const __int128 &n) {
	__int128 l = 1, r = 100000000LL;
	while (l <= r) {
		__int128 m = (l + r) / 2;
		if (m * m * m == n) return m;
		if (m * m * m < n)
			l = m + 1;
		else
			r = m - 1;
	}
	return -1;
}

int main () {
	std::ios::sync_with_stdio (0);
	std::cin.tie (0);
	std::cout.tie (0);
	int T;
	scanf ("%d", &T);
	for (int t = 0; t < T; ++t) {
		__int128 K1, K2;
		scanf (" %s", tmp);
		int L = strlen (tmp);
		K1 = 0;
		for (int i = 0; i < L; ++i)
			K1 = K1 * 10 + tmp[i] - '0';
		scanf (" %s", tmp);
		L = strlen (tmp);
		K2 = 0;
		for (int i = 0; i < L; ++i)
			K2 = K2 * 10 + tmp[i] - '0';
		__int128 K = gcd (K1, K2);
		std::vector <__int128> ans1, ans2;
		if (K <= 1000000) {
			for (__int128 i = 2; i <= 1000000; ++i) {
				while (K1 % i == 0) {
					ans1.push_back (i);
					K1 /= i;
				}
			}
			for (__int128 i = 2; i <= 1000000; ++i) {
				while (K2 % i == 0) {
					ans2.push_back (i);
					K2 /= i;
				}
			}
		} else if (K < 1000000000000000000LL) {
			_p.search ((long long) (K1 / K), ans1);
			_p.search ((long long) (K2 / K), ans2);
			_p.search ((long long) K, ans1);
			_p.search ((long long) K, ans2);
		} else {
			for (__int128 i = 2; i <= 1000000; ++i) {
				while (K1 % i == 0) {
					ans1.push_back (i);
					K1 /= i;
				}
			}
			for (__int128 i = 2; i <= 1000000; ++i) {
				while (K2 % i == 0) {
					ans2.push_back (i);
					K2 /= i;
				}
			}
			if (K1 > 1) {
				__int128 d = get_sqr (K1);
				if (d > 0) {
					ans1.push_back (d);
					ans1.push_back (d);
				} else {
					d = get_cub (K1);
					if (d > 0) {
						ans1.push_back (d);
						ans1.push_back (d);
						ans1.push_back (d);
					} else
						ans1.push_back (K1);
				}
			}
			if (K2 > 1) {
				__int128 d = get_sqr (K2);
				if (d > 0) {
					ans2.push_back (d);
					ans2.push_back (d);
				} else {
					d = get_cub (K2);
					if (d > 0) {
						ans2.push_back (d);
						ans2.push_back (d);
						ans2.push_back (d);
					} else
						ans2.push_back (K2);
				}
			}
		}
		std::sort (ans1.begin (), ans1.end ());
		std::sort (ans2.begin (), ans2.end ());
		__int128 r1 = 1, r2 = 1;
		for (int i = 0; i < ans1.size (); ++i) {
			__int128 tmp = 1;
			while (i < ans1.size () - 1 && ans1[i] == ans1[i + 1]) {
				++tmp;
				++i;
			}
			r1 *= tmp;
		}
		for (int i = 0; i < ans2.size (); ++i) {
			__int128 tmp = 1;
			while (i < ans2.size () - 1 && ans2[i] == ans2[i + 1]) {
				++tmp;
				++i;
			}
			r2 *= tmp;
		}
		std::cout << (long long) r1 << " " << (long long) r2 << std::endl;
	}
}
