#include <iostream>
using namespace std;

int main()
{
	string a;
	cin >> a;
	int is_minus = 0, is_even = 0, count = 0;
	int len = a.length();
	if (a[0] == '-')
	{
		is_minus = 1;
		len--;
	}
	if (a[a.length()-1] % 2 == 0)
		is_even = 1;
	for (int i = 0; i < a.length(); i++)
		if (a[i] == '2')
			count++;
	double ans = (double)count / len;
	if (is_minus)
		ans *= 1.5;
	if (is_even)
		ans *= 2;
	printf("%.2lf%%\n", ans*100);

	return 0;
}