#include<bits/stdc++.h>
using namespace std;

int main()
{
	srand(time(0));
	printf("40 123\n");
	for (int i=1;i<=123;i++)
	{
		int x=rand()%40,y=rand()%40;
		while (x==y)	x=rand()%40,y=rand()%40;
		printf("%d %d\n",x+1,y+1);
	}
	return 0;
}
