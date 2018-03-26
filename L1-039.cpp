// attention: index i and j mixed
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

char a[110][110];

int main() {
	// freopen("input.txt", "r", stdin);
	int n;
	string s;
	cin >> n;
	getchar();
	getline(cin, s);
	// cout << s.length();
	int col = s.length()%n == 0 ? s.length() / n-1:s.length() / n;
	string::iterator it = s.begin();
	for (int i = col; i >= 0; i--) {
		for (int j = 0; j < n; j++) {
			if (it != s.end())
				a[i][j] = *(it++);
			else
				a[i][j] = ' ';
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= col; j++) {
			cout << a[j][i];
		}
		cout << endl;
	}

	return 0;
}