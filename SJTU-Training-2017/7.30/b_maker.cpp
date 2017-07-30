#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
inline unsigned sfr(unsigned h, unsigned x) {
  return h >> x;
}
int f(LL i, LL j) {
  LL w = i * 1000000ll + j;
  int h = 0;
  for(int k = 0; k < 5; ++k) {
    h += (int) ((w >> (8 * k)) & 255);
    h += (h << 10);
    h ^= sfr(h, 6);
  }
  h += h << 3;
  h ^= sfr(h, 11);
  h += h << 15;
  return sfr(h, 27) & 1;
}

int main()
{
	srand(time(0));
	printf("1\n");
	int x=rand()%(1000000-1000+1);
	int y=rand()%(1000000-1000+1);
	x=123456,y=234567;
	for (int i=1;i<=1000;i++)
	{
		for (int j=1;j<=1000;j++)
			printf("%d",f(x+i-1,y+j-1));
		printf("\n");
	}
	cerr<<x<<" "<<y<<endl;
	return 0;
}
