#include<bits/stdc++.h>
using namespace std;

const double eps=1e-8;
int sign(double x)
{
	return x<-eps?-1:(x>eps?1:0);
}
double msqrt(double x)
{
	return sign(x)>0?sqrt(x):0;
}
struct Point
{
	double x,y;
	Point():x(0),y(0){}
	Point(double x,double y):x(x),y(y){}
	Point operator+(const Point &rhs)	const
	{
		return Point(x+rhs.x,y+rhs.y);
	}
	Point operator-(const Point &rhs)	const
	{
		return Point(x-rhs.x,y-rhs.y);
	}
	Point operator*(double k)	const
	{
		return Point(x*k,y*k);
	}
	Point operator/(double k)	const
	{
		//assert(sign(k));
		return Point(x/k,y/k);
	}
	Point rotate(double ang)	const
	{
		return Point(cos(ang)*x-sin(ang)*y,cos(ang)*y+sin(ang)*x);
	}
	Point turn90()	const
	{
		return Point(-y,x);
	}
	double len()	const
	{
		return msqrt(x*x+y*y);
	}
};
struct Line
{
	Point a,b;
};
double dot(const Point &a,const Point &b)
{
	return a.x*b.x+a.y*b.y;
}
double det(const Point &a,const Point &b)
{
	return a.x*b.y-a.y*b.x;
}
bool isLL(const Line &l1,const Line &l2,Point &p)
{
	double s1=det(l2.b-l2.a,l1.a-l2.a),
		   s2=-det(l2.b-l2.a,l1.b-l2.a);
	if (!sign(s1+s2))	return false;
	p=(l1.a*s2+l1.b*s1)/(s1+s2);
	return true;
}
double dis(Point a,Point b)
{
	return (a-b).len();
}
const int maxn=110;
Point a[maxn<<1];
double f[maxn<<1][maxn<<1];
int n,w,h;

Line bk[4];
void clear()
{
	bk[0].a=Point(0,0);
	bk[0].b=Point(0,h);
	bk[1].a=Point(w,0);
	bk[1].b=Point(w,h);
	bk[2].a=Point(0,0);
	bk[2].b=Point(w,0);
	bk[3].a=Point(0,h);
	bk[3].b=Point(w,h);
}
double getd(const Line &l,int ql,int qr)
{
	double tm1=-10,tm2=-10;
	
double dp(int l,int r)
{
	
int main()
{
	while (scanf("%d%d%d",&n,&w,&h)!=EOF)
	{
		clear();
		for (int i=1;i<=n;i++)
		{
			scanf("%lf%lf",&a[i].x,&a[i].y);
			a[i+n]=a[i];
		}
		a[2*n+1]=a[1];
		a[0]=a[n];
		double ans=-10;
		for (int i=1;i<=n;i++)
		{
			Line tmp;
			tmp.a=a[i];
			tmp.b=a[i-1];
			double now=getd(tmp,0,0)+dp(i,i+n-1);
			if (ans<0 || now<ans)	ans=now;
		}
		printf("%.6lf\n",ans);
	}
	return 0;
}
