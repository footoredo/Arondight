#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const double pi = acos(-1);
int sgn(double x){
	return (x > eps) - (x < -eps);
}
struct point{
	double x,y;
	point():x(0),y(0){}
	point(double x, double y): x(x), y(y) {}
	point operator + (const point &a) const{
		return point(x + a.x, y + a.y);
	}
	point operator - (const point &a) const{
		return point(x - a.x, y - a.y);
	}
	point operator * (const double &a) const{
		return point(x * a, y * a);
	}
	point operator / (const double &a) const{
		return point(x / a, y / a);
	}
};
double dot(const point &a,const point &b){
	return a.x * b.x + a.y * b.y;
}
double dis(point &a){
	return sqrt(dot(a,a));
}
point a1,a2,a3,b1,b2,b3,fx1,fx2,fx3,fx0,fx;
int w,l,r,h;
double d,sita,ans;
int main(){
	scanf("%d%d",&w,&l);
	scanf("%d%lf%lf%lf%lf%lf%lf%d",&r,&a1.x,&a1.y,&a2.x,&a2.y,&a3.x,&a3.y,&h);
	fx3 = point(w,l) - a3;
	d = dis(fx3);
	fx3 = fx3 / d;
	b3 = a3 - (fx3 * (2 * r));
	fx2 = point(0,l) - a2;
	d = dis(fx2);
	fx2 = fx2 / d;
	b2 = a2 - (fx2 * (2 * r));
	fx1 = b3 - a1;
	d = dis(fx1);
	fx1 = fx1 / d;
	b1 = a1 - (fx1 * (2 * r));
	fx0 = b2 - b1;
	d = dis(fx0);
	fx0 = fx0 / d;
	bool pd = true;
	if (sgn(b1.x) < 0 || sgn(b1.x - w) > 0 || sgn(b1.y -l) > 0)
		pd = false;
	if (sgn(b2.x) < 0 || sgn(b2.x - w) > 0 || sgn(b2.y -l) > 0)
		pd = false;
	if (sgn(b3.x) < 0 || sgn(b3.x - w) > 0 || sgn(b3.y -l) > 0)
		pd = false;/*
	if (sgn(dot(fx1, fx3)) < 0) pd = false;
	if (sgn(dot(fx1, fx0)) > 0) pd = false;
	if (sgn(dot(fx0, fx2)) < 0) pd = false;*/
	fx = fx1 * (-2 * dot(fx1,fx0)) + fx0;
	if (sgn(fx.y) <= 0) pd = false;
	sita = acos(fx.x) / pi * 180;
	ans = b1.x - fx.x * ((b1.y - h)/fx.y);
	if (sgn(ans - r) < 0 || sgn(ans + r - w)> 0)
		pd = false;/*
	printf("%.2f %.2f\n",ans,sita);
	printf("%.2lf %.2lf\n",b1.x,b1.y);
	printf("%.2lf %.2lf\n",b2.x,b2.y);
	printf("%.2lf %.2lf\n",b3.x,b3.y);
	printf("%.2lf %.2lf\n",fx.x,fx.y);
	printf("%.2lf %.2lf\n",fx0.x,fx0.y);
	printf("%.2lf %.2lf\n",fx1.x,fx1.y);
	printf("%.2lf %.2lf\n",fx2.x,fx2.y);
	printf("%.2lf %.2lf\n",fx3.x,fx3.y);*/
	if (!pd) printf("impossible\n");
	else printf("%.2f %.2f\n",ans,sita);
}
