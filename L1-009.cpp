#include <iostream>
#include <cstdio>
using namespace std;

typedef long long ll;

int gcd(ll a, ll b)
{
	return b == 0 ? a : gcd(b, a % b);
}

void simple(ll *a, ll *b)
{
	int temp = gcd(*a, *b);
	*a /= temp;
	*b /= temp;
}

int main()
{
	int n;
	ll suma = 0, sumb = 1;
	cin >> n;
	while (n--)
	{
		ll a, b;
		scanf("%lld/%lld", &a, &b);
		ll temp = sumb;
		sumb = sumb*b;
		suma = suma*b + temp*a;
		simple(&suma, &sumb);

	}
	if(sumb == 1)
		printf("%lld\n", suma);
	else if(suma > sumb)
		printf("%lld %lld/%lld\n", suma/sumb, suma%sumb, sumb);
	else
		printf("%lld/%lld\n", suma, sumb);


	return 0;
}