bool cmp(const Point &a,const Point &b)
{
	int tmp1=(a.y>0 || (a.y==0 && a.x>0))?1:2;
	int tmp2=(b.y>0 || (b.y==0 && b.x>0))?1:2;
	if (tmp1!=tmp2)	return tmp1<tmp2;
	return det(a,b)>0;
}
