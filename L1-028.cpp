#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

void solve()
{
	int a;
	cin >> a;
	if (a == 1 || a == 0)
	{
		printf("No\n");
		return;
	}
	for (int i = 2; i <= sqrt(a); ++i)
	{
		if (a % i == 0)
		{
			printf("No\n");
			return;
		}
	}
	printf("Yes\n");
}

int main()
{
	int n;
	cin >> n;
	while(n--)
		solve();

	return 0;
}