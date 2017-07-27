#include <bits/stdc++.h>
typedef double DB;
const DB eps = 1e-8;
const DB PI = acos (-1);

__inline int sign (DB x) {
    return (x > eps) - (x < -eps);
}

struct Point {
    DB x, y;
    __inline void read () {
        int _x, _y;
        std::cin >> _x >> _y;
        x = _x; y = _y;
    }
    __inline DB len2 () const {
        return x * x + y * y;
    }
    __inline DB len () const {
        return sqrt (len2 ());
    }
    __inline Point operator + (const Point& rhs) const {
        return Point {x + rhs.x, y + rhs.y};
    }
    __inline Point operator - (const Point& rhs) const {
        return Point {x - rhs.x, y - rhs.y};
    }
    __inline Point operator * (DB k) const {
        return Point {x * k, y * k};
    }
    __inline DB ang () const {
        return atan2 (y, x);
    }
    __inline Point rotate (DB ang) const {
        return Point {cos (ang) * x - sin (ang) * y,
        cos (ang) * y + sin (ang) * x};
    }
};

__inline DB det (const Point& a, const Point& b) {
    return a.x * b.y - a.y * b.x;
}

__inline DB dot (const Point& a, const Point& b) {
    return a.x * b.x + a.y * b.y;
}

struct Circle {
    Point o;
    DB r;
    int sign;
};

struct Event {
    Point p;
    DB ang;
    int delta;
    Event (Point p = Point {0, 0}, DB ang = 0, int delta = 0): p(p), ang(ang), delta(delta) {}
};

__inline bool operator < (const Event& a, const Event& b) {
    return a.ang < b.ang;
}

__inline DB sqr (DB x) {
    return x * x;
}

void addEvent (const Circle& a, const Circle& b, std::vector<Event>& evt, int& cnt) {
    DB d2 = (a.o - b.o).len2 (),
       dRatio = ((a.r - b.r) * (a.r + b.r) / d2 + 1) / 2,
       pRatio = sqrt (-(d2 - sqr (a.r - b.r)) * (d2 - sqr (a.r + b.r)) / (d2 * d2 * 4));
    Point d = b.o - a.o, p = d.rotate (PI / 2),
          q0 = a.o + d * dRatio + p * pRatio,
          q1 = a.o + d * dRatio - p * pRatio;
    DB ang0 = (q0 - a.o).ang (),
       ang1 = (q1 - a.o).ang ();
    evt.push_back (Event (q1, ang1, b.sign));
    evt.push_back (Event (q0, ang0, -b.sign));
    cnt += (ang1 > ang0) * b.sign;
}

__inline bool issame (const Circle& a, const Circle& b) {
    return sign ((a.o - b.o).len ()) == 0 && sign (a.r - b.r) == 0;
}

__inline bool overlap (const Circle& a, const Circle& b) {
    return sign (a.r - b.r - (a.o - b.o).len ()) >= 0;
}

__inline bool intersect (const Circle& a, const Circle& b) {
    return sign ((a.o - b.o).len () - a.r - b.r) < 0;
}

const int N = 1e3 + 3;
Circle c[N];
DB area[N];
bool keep[N];
void add (int cnt, DB a) {
//    std::cout << cnt << ' ' << a << std::endl;
    area[cnt] += a;
}

void solve (int C) {
    for (int i = 1; i <= C; ++ i) {
        area[i] = 0;
    }
    for (int i = 0; i < C; ++ i) {
//        std::cout << "Circle #" << i << std::endl;
        int cnt = c[i].sign > 0 ? 1 : 0, _sign = c[i].sign;
        std::vector <Event> evt;
        for (int j = 0; j < i; ++ j) if (issame (c[i], c[j])) cnt += c[j].sign;
        for (int j = 0; j < C; ++ j) {
            if (j != i && !issame (c[i], c[j]) && overlap (c[j], c[i])) {
                cnt += c[j].sign;
            }
        }
        for (int j = 0; j < C; ++ j) {
            if (j != i && !overlap (c[j], c[i]) && !overlap (c[i], c[j]) && intersect (c[i], c[j])) {
//                std::cout << "add " << j << std::endl;
                addEvent (c[i], c[j], evt, cnt);
            }
        }
//        std::cout << cnt << std::endl;
 //       std::cout << evt.size () << std::endl;
        if (evt.size () == 0) {
            add (cnt, _sign * PI * c[i].r * c[i].r);
        }
        else {
            std::sort (evt.begin (), evt.end ());
            evt.push_back (evt.front ());
            for (int j = 0; j + 1 < (int) evt.size (); ++ j) {
                cnt += evt[j].delta;
//                std::cout << cnt << ' ';
                add (cnt, _sign * det (evt[j].p, evt[j + 1].p) / 2);
                DB ang = evt[j + 1].ang - evt[j].ang;
                if (ang < 0) {
                    ang += PI * 2;
                }
                if (sign (ang) == 0) continue;
                add (cnt, _sign * ang * c[i].r * c[i].r / 2);
                add (cnt, _sign * -sin (ang) * c[i].r * c[i].r / 2);
            }
//            std::cout << std::endl;
        }
    }
}

int main () {
    std::ios::sync_with_stdio (false);
    std::cin.tie (0);
    std::cout << std::fixed << std::setprecision (10);

    int T; std::cin >> T;
    for (int ca = 1; ca <= T; ++ ca) {
        int n; std::cin >> n;
        for (int i = 0; i < n; ++ i) {
            Point center; center.read ();
            int D, d; std::cin >> D >> d;
            c[i * 2] = Circle {center, DB(D + d), 1};
            c[i * 2 + 1] = Circle {center, DB(std::max(0, D - d)), -1};
        }

        solve (n * 2);

        std::cout << "Case " << ca << ": " << area[1] << std::endl;
    }
}
