#include <iostream>
using namespace std;

int weight[] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
char m[] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};

int main()
{
	// freopen("input.txt", "r", stdin);
	int n, sum, is_pass = 1;
	string a;
	cin >> n;
	while(n--)
	{
		sum = 0;
		cin >> a;
		for (int i = 0; i < 17; i++)
			sum += (a[i]-'0')*weight[i];
		int z = sum % 11;
		if (m[z] != a[17])
		{
			cout << a << endl;
			is_pass = 0;
		}
	}
	if (is_pass)
		cout << "All passed" << endl;

	return 0;
}