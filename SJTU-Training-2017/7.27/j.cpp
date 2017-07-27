#include<bits/stdc++.h>
using namespace std;

const int maxn=1010;
typedef double DB;
const DB eps=1e-8;
const DB pi=acos(-1.0);
int sign(DB x)
{
	return x<-eps ?-1:(x>eps?1:0);
}
DB msqrt(DB x)
{
	return sign(x) > 0?sqrt(x):0;
}
struct Point
{
	DB x,y;
	Point():x(0),y(0){}
	Point(DB x,DB y):x(x),y(y){};
	Point operator+(const Point &b)	const
	{
		return Point(x+b.x,y+b.y);
	}
	Point operator-(const Point &b)	const
	{
		return Point(x-b.x,y-b.y);
	}
	Point operator*(DB k)	const
	{
		return Point(x*k,y*k);
	}
	Point operator/(DB k)	const
	{
		return Point(x/k,y/k);
	}
	Point rotate(DB ang)	const
	{
		return Point(cos(ang)*x-sin(ang)*y,cos(ang)*y+sin(ang)*x);
	}
	Point turn90()	const
	{
		return Point(-y,x);
	}
	DB len2()	const
	{
		return x*x+y*y;
	}
	DB len()	const
	{
		return msqrt(x*x+y*y);
	}
	Point unit()	const
	{
		return *this/len();
	}
	DB ang() const
	{
		return atan2(y,x);
	}
};
DB dot(const Point &a,const Point &b)
{
	return a.x*b.x+a.y*b.y;
}
DB det(const Point &a,const Point &b)
{
	return a.x*b.y-a.y*b.x;
}
struct Circle
{
	Point o;
	DB r;
	int is;
}	c[maxn];
struct Event
{
	Point p;
	DB ang;
	int delta;
	Event(Point p=Point(0,0),DB ang=0,int delta=0):p(p),ang(ang),delta(delta){}
};
bool operator<(const Event &a,const Event &b)
{
	return a.ang<b.ang;
}
DB ang0,ang1;
void addEvent(const Circle &a,const Circle &b,vector<Event> &evt,int &cnt)
{
	DB d2=(a.o-b.o).len2();
	DB dRatio=((a.r-b.r)*(a.r+b.r)/d2+1)/2;
	DB pRatio=msqrt(-(d2-(a.r-b.r)*(a.r-b.r))*(d2-(a.r+b.r)*(a.r+b.r))/(d2*d2*4));
	Point d=b.o-a.o,p=d.rotate(pi/2);
	Point q0=a.o+d*dRatio+p*pRatio;
	Point q1=a.o+d*dRatio-p*pRatio;
	ang0=(q0-a.o).ang();
	ang1=(q1-a.o).ang();
	evt.push_back(Event(q1,ang1,b.is));
	evt.push_back(Event(q0,ang0,-b.is));
	cnt+=(ang1>ang0)*b.is;
}
bool issame(const Circle &a,const Circle &b)
{
	return sign((a.o-b.o).len())==0 && sign(a.r-b.r)==0;
}
bool overlap(const Circle &a,const Circle &b)
{
	return sign(a.r-b.r-(a.o-b.o).len())>=0;
}
bool intersect(const Circle &a,const Circle &b)
{
	return sign((a.o-b.o).len() -a.r-b.r)<0;
}
DB area[maxn];
Point centroid[maxn];
bool keep[maxn];
void add(int cnt,DB a)
{
	area[cnt]+=a;
	//centroid[cnt] = centroid[cnt]+c*a;
}
int n;
void clear()
{
	memset(area,0,sizeof(area));
	memset(keep,0,sizeof(keep));
}
void solve(int C)
{
	for (int i=1;i<=C;i++)
	{
		area[i]=0;
		centroid[i]=Point(0,0);
	}
	for (int i=0;i<C;i++)
	{
		int cnt=c[i].is;
		if (cnt<0)	cnt=0;
		vector<Event> evt;
		for (int j=0;j<i;j++)	if (issame(c[i],c[j]))	cnt+=c[j].is;
		for (int j=0;j<C;j++)
		{
			if (j!=i && !issame(c[i],c[j]) && overlap(c[j],c[i]))	cnt+=c[j].is;
		}
		for (int j=0;j<C;j++)
		{
			if (j!=i && !overlap(c[j],c[i]) && !overlap(c[i],c[j]) && intersect(c[i],c[j]))
				addEvent(c[i],c[j],evt,cnt);
		}
		if (evt.size()==0u)
		{
			add(cnt,pi*c[i].r*c[i].r*c[i].is);
		}	else
		{
			sort(evt.begin(),evt.end());
			evt.push_back(evt.front());
			for (int j=0;j+1<(int)evt.size();j++)
			{
				cnt+=evt[j].delta;
				add(cnt,det(evt[j].p,evt[j+1].p)/2*c[i].is);
				DB ang=evt[j+1].ang-evt[j].ang;
				if (ang<0)	ang+=2*pi;
				if (sign(ang)==0)	continue;
				add(cnt,ang*c[i].r*c[i].r/2*c[i].is);
				add(cnt,-sin(ang)*c[i].r*c[i].r/2*c[i].is);
			}
		}
	}
	for (int i=1;i<=C;i++)
	if (sign(area[i]))
	{
		centroid[i]=centroid[i]/area[i];
	}
}
int main()
{
	int te;
	scanf("%d",&te);
	for (int ca=1;ca<=te;ca++)
	{
		clear();
		scanf("%d",&n);
		for (int i=1;i<=n;i++)
		{
			int x,y,r,R;
			scanf("%d%d%d%d",&x,&y,&R,&r);
			c[i*2-2].o=c[i*2-1].o=Point(1.0*x,1.0*y);
			c[i*2-2].r=R+r;
			c[i*2-1].r=max(R-r,0);
			c[i*2-2].is=1;
			c[i*2-1].is=-1;
		}
		solve(n<<1);
		printf("Case %d: %.8f\n",ca,area[1]);
	}
	return 0;
}
