int zeller(int y,int m,int d)
{
	if (m<=2)	y--,m+=12;
	int c=y/100;
	y%=100;
	int w;
	if (y<1582 || (y==1582 && (m<10 || (m==10 && d<=4))))
		w=((c/4)-2*c+y+(y/4)+(13*(m+1)/5)+d-1)%7;
	else
		w=y+(y/4)+(c/4)-2*c+(13*(m+1)/5)+d+2;
	retur w;
}
