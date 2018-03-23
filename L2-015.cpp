#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<double> v;

bool cmp(double a, double b) {
	return a >= b;
}

int main()
{
	// freopen("input.txt", "r", stdin);
	int n, k, m;
	cin >> n >> k >> m;
	v.resize(n);
	for (int i = 0; i < n; i++) {
		int temp, minv = 999, maxv = -1;
		for (int j = 0; j < k; j++) {
			cin >> temp;
			minv = min(minv, temp);
			maxv = max(maxv, temp);
			v[i] += temp;
		}
		v[i] = (v[i] - minv - maxv) / (k - 2);
	}
	sort(v.begin(), v.end(), cmp);
	for (int i = m-1; i >= 0; i--) {
		if (i == m-1)
			printf("%.3lf", v[i]);
		else
			printf(" %.3lf", v[i]);
	}
	return 0;
}
