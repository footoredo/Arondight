#include<bits/stdc++.h>
using namespace std;

int main()
{
	for (int ca=1;ca<=10;ca++)
	{
	printf("%d\n",100);
	for (int i=1;i<=10000;i++)
	{
		int x=rand()%100;
		int y=rand()%100;
		while (x==y)
		{
			x=rand()%100;
			y=rand()%100;
		}
		printf("%d-%d\n",x+1,y+1);
	}
	}
	return 0;
}
