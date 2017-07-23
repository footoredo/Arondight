#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
int sign(double x){
	return (x > eps) - (x < -eps);
}
struct point{
	double x,y;
	point(): x(0), y(0) {};
	point(double x, double y): x(x), y(y) {}
	point operator + (const point & rhs) const {
		return point(x + rhs.x, y + rhs.y);
	}
	point operator - (const point & rhs) const {
		return point(x - rhs.x, y - rhs.y);
	}
	point operator * (const int & k) const {
		return point(x * k, y * k);
	}
	point operator / (const int & k) const {
		return point(x / k, y / k);
	}
};
struct line {
	point a,b;
	line(){}
	line(point a, point b): a(a), b(b) {};
};
int n,h,w;
double g1[200][200],g2[200][200],f[200][200];
point a[200];
line li[200],lb,rb,ub,db;
double dot(const point &a,const point &b){
	return a.x * b.x + a.y * b.y;
}
double det(const point &a,const point &b){
	return a.x * b.y - a.y * b.x;
}
double dis(const point &a){
	return sqrt(dot(a,a));
}
bool isLL(const line& l1, const line& l2,point& p){
	double s1 = det(l2.b - l2.a, l1.a- l2.a),
		s2 = -det(l2.b - l2.a, l1.b - l2.a);
	if (!sign(s1 + s2)) return false;
	p = (l1.a * s2 + l1.b * s1) / (s1 + s2);
	return true;
}
void update(double &x, double y){
	if (x > y) x = y;
}
int main(){
	while (scanf("%d%d%d",&n,&w,&h) == 3){
		for (int i = 1; i <= n; i++)
			scanf("%lf%lf",&a[i].x,&a[i].y);
		lb = line(point(0,0),point(0,h));
		rb = line(point(w,0),point(w,h));
		db = line(point(0,0),point(w,0));
		ub = line(point(0,h),point(w,h));
		for (int i = 1; i < n; i++)
			li[i] = line(a[i],a[i + 1]);
		li[n] = line(a[n],a[1]);
		for (int i = 1; i <= n; i++){
			double l = 0;
			double r = dis(point(w,h));
			point x1;
			point x2;
			if (isLL(lb,li[i],x1) && isLL(rb,li[i],x2)){
				if (dot(li[i].b - li[i].a,x1 - a[i]) < dot(li[i].b - li[i].a,x2 - a[i])){
					l = max(l,dot(li[i].b - li[i].a,x1 - a[i]));
					r = min(r,dot(li[i].b - li[i].a,x2 - a[i]));
				} else{
					l = max(l,dot(li[i].b - li[i].a,x2 - a[i]));
					r = min(r,dot(li[i].b - li[i].a,x1 - a[i]));
				}
			}
			if (isLL(db,li[i],x1) && isLL(ub,li[i],x2)){
				if (dot(li[i].b - li[i].a,x1 - a[i]) < dot(li[i].b - li[i].a,x2 - a[i])){
					l = max(l,dot(li[i].b - li[i].a,x1 - a[i]));
					r = min(r,dot(li[i].b - li[i].a,x2 - a[i]));
				} else{
					l = max(l,dot(li[i].b - li[i].a,x2 - a[i]));
					r = min(r,dot(li[i].b - li[i].a,x1 - a[i]));
				}
			}
			for (int j = 1; j <= n; j++)
				g1[i][j] =  1e18;
			for (int j = 1; j <= n; j++)
				g2[i][j] =  1e18;
			for (int j = 1; j <= n; j++){
				if (isLL(li[i],li[j],x1)){
					if (dot(li[i].b - li[i].a,x1 - a[i % n + 1]) > dot(li[i].b - li[i].a,a[i % n + 1] - a[i]))
						update(g1[i][j],(min(r,dot(a[i % n + 1],li[i].b - li[i].a)) - dot(li[i].b - li[i].a,a[i % n + 1] - a[i])) / (dis(li[i].b - li[i].a)));
				}
			}
			for (int j = 1; j <= n; j++){
				if (isLL(li[i],li[j],x1)){
					if (dot(li[i].b - li[i].a,x1 - a[i % n + 1]) < 0)
						update(g2[i][j],-min(l,dot(a[i % n + 1],li[i].b - li[i].a)));
				}
			}
			f[i][i % n + 1] = dis(a[i % n + 1] - a[i]);
		}
		for (int len = 2; len <= n; len++){
			for (int i = 1; i <= n; i++){
				int j = (i + len - 1) % n + 1;
				update(f[i][j],f[i % n + 1][j] + g1[i][(j + n - 2) % n + 1]);
				update(f[i][j],f[i][(j + n - 2) % n + 1] + g2[(j + n - 2) % n + 1][i]);
			}
		}
		double ans = 1e18;
		for (int i = 1; i <= n; i++) 
			update(ans,f[i % n + 1][i]);
		for (int i = 1; i <= n; i++)
			ans += dis(li[i].b - li[i].a);
		printf("%.6f\n",ans);
	}
}
