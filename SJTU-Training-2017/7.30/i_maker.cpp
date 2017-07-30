#include<bits/stdc++.h>
using namespace std;

int main()
{
	printf("10\n");
	for (int ca=1;ca<=10;ca++)
	{
	int n = 1e5;
	std::cout << n << std::endl;
	for (int i = 0; i < n; ++ i)
		std::cout << rand() % 10000 + 90000 << ' ';
	}
	std::cout << std::endl;
	return 0;
}
