bool in(Point x,Point y,Point z)
{
	if (sign(det(x,y))>0)	swap(x,y);
	return sign(det(z,y))<=0 && sign(det(x,z))<=0;
}
bool jiao(Point &x,Point &y,Point l,Point r)
{
	if (!in(x,y,l) && !in(x,y,r))	swap(x,l),swap(y,r);
	if (!in(x,y,l) && !in(x,y,r))	return false;
	if (!in(x,y,l))	swap(l,r);
	if (in(x,y,l) && in(x,y,r))
	{
		x=l;
		y=r;
		return true;
	}
	bool xx=in(l,r,x),yy=in(l,r,y);
	if (xx && yy)
	{
		return true;
	}
	if (!xx && !yy)
	{
		x=l;
		y=r;
		return true;
	}
	if (xx && !yy)
	{
		y=l;
		return true;
	}
	x=l;
	return true;
}
