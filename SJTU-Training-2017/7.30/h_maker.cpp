#include<bits/stdc++.h>
using namespace std;

int main()
{
	printf("10\n");
	for (int ca=1;ca<=10;ca++)
	{
	printf("100 100\n");
	for (int i=1;i<=100;i++)
	{
		for (int j=1;j<=100;j++)
			printf("%d ",(i-1)*100+j);
		printf("\n");
	}
	printf("\n");
	}
	return 0;
}
