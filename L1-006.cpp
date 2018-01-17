#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;

int main ()
{
	ll n, ans;
	cin >> n;
	for (int len = 12; len >= 1; len--)
	{
		for (int i = 2; i <= sqrt(n); i++)
		{
			ans = 1;
			for (int j = i; j <= i+len-1; j++)
				ans *= j;
			if(n%ans == 0)
			{
				cout << len << endl;
				cout << i;
				for (int j = i + 1; j <= i+len-1; j++)
					cout << "*" << j;
				return 0;
			}
		}
	}
	cout << "1" << endl;
	cout << n;

	return 0;
}