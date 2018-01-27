#include <iostream>
#include <cstdio>
using namespace std;

typedef long long ll;

ll f(int n)
{
	if (n == 1 || n == 0)
		return 1;
	return n * f(n - 1);
}

int main()
{
	int n;
	cin >> n;
	ll ans = 0;
	for (int i = 1; i <= n; i++)
		ans += f(i);
	cout << ans;

	return 0;
}