#include <bits/stdc++.h>
using namespace std;
int h,m,s,dh,t,d;
char st[100];
int main(){
	scanf("%d",&t);
	for (int tt = 1; tt <= t; tt++){
		scanf("%d",&d);
		scanf("%s",st);
		scanf("%d",&h);
		if (st[0] == 'a'){
			d += h * 30;
			if (d <= 0) d= 360;
			if (d > 360) d -= 360;
			s = round(d * 120.0 / 11);
			m = s / 60;
			s = s % 60;
			h += m / 60;
			m = m % 60;
			if (h > 12) h -= 12;
			printf("Case %d: %d:%02d:%02d\n",tt,h,m,s);
		} else {
			d += h * 30;
			if (d >= 360) d -= 360;
			d = 360 - d;
			s = round(d * 120.0 / 11);
			m = (s + 59) / 60;
			s = m * 60 - s;
			dh = (m + 59) / 60;
			m = dh * 60 - m;
			h -= dh;
			if (h <= 0) h += 12;
			printf("Case %d: %d:%02d:%02d\n",tt,h,m,s);
		}
	}
}
