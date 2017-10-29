Point get_circle_center(const Point &a,const Point &b,const Point &c)
{
	Point center;
	double a1=b.x-a.x;
	double b1=b.y-a.y;
	double c1=(a1*a1+b1*b1)/2.0;
	double a2=c.x-a.x;
	double b2=c.y-a.y;
	double c2=(a2*a2+b2*b2)/2.0;
	double d=a1*b2-a2*b1;
	center.x=a.x+(c1*b2-c2*b1)/d;
	center.y=a.y+(a1*c2-a2*c1)/d;
	return center;
}
inline bool inCircle(const Point &p,const Circle &c){
	return sign((p-c.o).len()-c.r)<=0;
}
Circle Min_cover(vector<Point> p)
{//注意考虑没有点的情况
	random_shuffle(p.begin(),p.end());
	int n=p.size();
	Circle ans;
	ans.o=p[0];
	ans.r=0;
	for (int i=1;i<n;i++)
	if (!inCircle(p[i],ans))
	{
		ans.o=p[i];
		ans.r=0;
		for (int j=0;j<i;j++)
		if (!inCircle(p[j],ans))
		{
			ans.o=(p[j]+p[i])/2.0;
			ans.r=((p[j]-p[i]).len())/2.0;
			for (int k=0;k<j;k++)
			if (!inCircle(p[k],ans))
			{
				ans.o=get_circle_center(p[i],p[j],p[k]);
				ans.r=(p[i]-ans.o).len();
			}
		}
	}
	return ans;
}
