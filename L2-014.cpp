#include <iostream>
#include <cstdio>
#include <set>
using namespace std;

set<int> s;

int main()
{
	int n, temp;
	cin >> n;
	s.insert(0);
	for (int i = 0; i < n; i++) {
		cin >> temp;
		if (temp < *s.rbegin())
			s.erase(*s.upper_bound(temp));
		s.insert(temp);
	}
	cout << s.size()-1;

	return 0;
}
