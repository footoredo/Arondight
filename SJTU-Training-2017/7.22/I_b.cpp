#include <bits/stdc++.h>
typedef double DB;
const double eps = 1e-8;
const int inf = 1e5;

__inline int sign(DB x) {
	return (x > eps) - (x < -eps);
}

__inline DB msqrt(DB x) {
	if (sign(x) <= 0) return 0;
	else return sqrt(x);
}

struct P {
	DB x, y;
	__inline P() {};
	__inline P(DB x, DB y): x(x), y(y) {}
	__inline void read() {
		int _x, _y; std::cin >> _x >> _y;
		x = _x; y = _y;
	}
	__inline void print(std::string prompt = "") {
		std::cout << prompt << x << " " << y << std::endl;
	}
	__inline P operator+(const P& rhs) const {
		return P(x + rhs.x, y + rhs.y);
	}
	__inline P operator-(const P& rhs) const {
		return P(x - rhs.x, y - rhs.y);
	}
	__inline P operator*(DB k) const {
		return P(x * k, y * k);
	}
	__inline P operator/(DB k) const {
		return P(x / k, y / k);
	}
	__inline P turn90() const {
		return P(y, -x);
	}
	__inline DB len2() const {
		return x * x + y * y;
	}
	__inline DB len() const {
		return msqrt(len2());
	}
	__inline P unit() const {
		return *this / len();
	}
};

__inline DB det(const P& a, const P& b) {
	return a.x * b.y - a.y * b.x;
}

__inline DB dot(const P& a, const P& b) {
	return a.x * b.x + a.y * b.y;
}

struct C {
	P o;
	DB r;
};

struct L {
	P a, b;
};

bool isLL(const L& l1, const L& l2, P& p) {
	DB s1 = det(l2.b - l2.a, l1.a - l2.a),
	   s2 = -det(l2.b - l2.a, l1.b - l2.a);
	if (!sign(s1 + s2)) return false;
	p = (l1.a * s2 + l1.b * s1) / (s1 + s2);
	return true;
}

bool onSeg(const L& l, const P& p) {
	return sign(det(p - l.a, l.b - l.a)) == 0 && sign(dot(p - l.a, p - l.b)) <= 0;
}

__inline bool between(const P& l, const P& r, const P& x) {
	int s1 = sign(det(l, r)), s2 = sign(det(l, x)), s3 = sign(det(x, r));
	if (s2 == 0) return sign(dot(l, x)) >= 0;
	if (s3 == 0) return sign(dot(r, x)) >= 0;
	return s1 == s2 && s2 == s3;
}

struct Arc {
	C c;
	P l, r;
	P mid;
	__inline Arc(const P& l, const P& r, const P& d): l(l), r(r) {
		L l1 = {l, l + d.turn90()};
		P umid = (l + r) / 2;
		L l2 = {umid, umid + (r - l).turn90()};
		isLL(l1, l2, c.o);
		c.r = (c.o - l).len();
//		c.o.print();
//		std::cout << c.r << std::endl;
		mid = (r - l).turn90();
		if (sign(dot(mid, d)) < 0) mid = mid * (-1);
//		mid.print();
	}
	__inline bool has(const P& p) const {
		return between(l - c.o, mid, p - c.o) || between(mid, r - c.o, p - c.o);
	}
};

bool isCL(const C& a, const L& l, P& p1, P& p2) {
	DB x = dot(l.a - a.o, l.b - l.a),
	   y = (l.b - l.a).len2(),
	   d = x * x - y * ((l.a - a.o).len2() - a.r * a.r);
	if (sign(d) < 0) return false;
	P p = l.a - ((l.b - l.a) * (x / y)), delta = (l.b - l.a) * (msqrt(d) / y);
	p1 = p + delta; p2 = p - delta;
	return true;
}

__inline bool cross(const L& l1, const L& l2) {
	P x;
	if (!isLL(l1, l2, x)) return false;
//	x.print();
	return onSeg(l1, x) && onSeg(l2, x);
}

__inline bool cross(const L& l, const Arc& a) {
	P p1, p2;
	if (!isCL(a.c, l, p1, p2)) return false;
//	p1.print("Checking "); std::cout << (onSeg(l, p1) && a.has(p1)) << std::endl;
//	p2.print("Checking "); std::cout << (onSeg(l, p2) && a.has(p2)) << std::endl;
	return (onSeg(l, p1) && a.has(p1)) 
		|| (onSeg(l, p2) && a.has(p2));
}

const int N = 2e2 + 2;
int n, a, g;
std::vector<L> lines;
std::vector<Arc> arcs;
P as[N], gs[N];
int numa[N], numg[N];
int cc, S, T, SS, TT;

const int NN = N + N + 4;
const int M = N * N * 4 + N * 4;
int adj[NN], v[M], nxt[M], f[M], e;
__inline void ins(int u0, int v0, int f0) {
	v[e] = v0; nxt[e] = adj[u0]; f[e] = f0; adj[u0] = e ++;
	v[e] = u0; nxt[e] = adj[v0]; f[e] =  0; adj[v0] = e ++;
}

int d[NN], Q[NN], cur[NN];
bool BFS(int S, int T) {
	memset(d, -1, sizeof (*d) * cc);
	int l = 0, r = 0; Q[r ++] = S; d[S] = 0;
	while (l < r) {
		int u = Q[l ++];
		for (int e = cur[u] = adj[u]; ~e; e = nxt[e])
			if (f[e] && !~d[v[e]]) {
				d[v[e]] = d[u] + 1;
				Q[r ++] = v[e];
			}
	}
	return ~d[T];
}

int DFS(int u, int T, int lim) {
	if (u == T) return lim;
	int rem = lim;
	for (int &e = cur[u]; rem && ~e; e = nxt[e])
		if (f[e] && d[v[e]] == d[u] + 1) {
			int flow = DFS(v[e], T, std::min(rem, f[e]));
			f[e] -= flow;
			f[e ^ 1] += flow;
			rem -= flow;
		}
	return lim - rem;
}

int dinic(int S, int T) {
	int ret = 0;
	while (BFS(S, T)) {
//		std::cout << "DFS " << std::endl;
		ret += DFS(S, T, inf);
//		std::cout << ret << std::endl;
	}
	return ret;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout << std::fixed << std::setprecision(3);
	int caseno = 0;
	while (std::cin >> n >> a >> g, n || a || g) {
		++ caseno;
		lines.clear(); arcs.clear();
		for (int i = 0; i < n; ++ i) {
			int k; std::cin >> k;
			static std::vector<P> ps; ps.resize(k);
			static std::vector<bool> type; type.resize(k);
			static std::vector<P> vec; vec.resize(k);
			for (int j = 0; j < k; ++ j) {
				ps[j].read();
				static char op[3];
				std::cin >> op;
				if (op[0] == 's') {
					type[j] = 0;
				}
				else {
					type[j] = 1;
					vec[j].read();
				}
			}
			for (int j = 0; j < k; ++ j) {
				P nxt = ps[(j + 1) % k];
				if (type[j] == 0) {/*
					std::cout << "new line: " << std::endl;;
					ps[j].print("----from ");
					nxt.print("----to ");*/
					lines.push_back(L{ps[j], nxt});
				}
				else {
					arcs.push_back(Arc(ps[j], nxt, vec[j]));
				}
			}
		}

		memset(adj, -1, sizeof adj);
		e = cc = 0; S = cc ++; T = cc ++; SS = cc ++; TT = cc ++;
		ins(T, S, inf);
		int sum = 0;
		for (int i = 0; i < a; ++ i) {
			as[i].read();
			int k; std::cin >> k;
			numa[i] = cc ++;
			sum += k;
			ins(numa[i], TT, k);
		}
		ins(SS, T, sum);
		for (int i = 0; i < g; ++ i) {
			gs[i].read();
			numg[i] = cc ++;
			int k; std::cin >> k;
			ins(S, numg[i], k);
		}

		for (int i = 0; i < g; ++ i) {
			for (int j = 0; j < a; ++ j) {
				L seg = {gs[i], as[j]};
				bool crossed = false;
				for (auto l: lines)
					if (cross(seg, l)) {
//						l.a.print("from -- ");
//						l.b.print("to -- ");
						crossed = true;
						break;
					}
				for (auto arc: arcs)
					if (cross(seg, arc)) {
						crossed = true;
						break;
					}
				for (int k = 0; k < g; ++ k)
					if (k != i && onSeg(seg, gs[k])) {
						crossed = true; break;
					}
				for (int k = 0; k < a; ++ k)
					if (k != j && onSeg(seg, as[k])) {
						crossed = true; break;
					}
				if (!crossed || sign((gs[i] - as[j]).len()) == 0) {
					ins(numg[i], numa[j], 1);
//					std::cout << i << " " << j << std::endl;
				}
			}
		}

//		std::cout << "done" << std::endl;
		int flow = dinic(SS, TT);
		std::cout << "Case " << caseno << ": ";
		if (flow == sum) {
			std::cout << "Yes" << std::endl;
		}
		else {
			std::cout << "No" << std::endl;
		}
	}
}
