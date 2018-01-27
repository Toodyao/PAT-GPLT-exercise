#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main()
{
	string a;
	char ch;
	int b[129] = { 0 };
	getline(cin, a);
	while ((ch = getchar()) != '\n')
		b[ch] = 1;
	for (int i = 0; i < a.length(); i++)
		if (!b[a[i]])
			cout << a[i];

	return 0;
}