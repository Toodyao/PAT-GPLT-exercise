#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int n;
double z, r;
vector<int> v[100010];
double power[100010];
int good[100010];
double sum;

void dfs(int n) {
	if (good[n] == 1) {
		sum += power[n] * v[n][0];
		return;
	}
	for (int i = 0; i < v[n].size(); i++) {
		power[v[n][i]] = power[n] * (1.0 - r / 100.0);
		dfs(v[n][i]);
	}
}

int main() {
	// freopen("input.txt", "r", stdin);
	cin >> n >> z >> r;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		if (num == 0) {
			int temp;
			cin >> temp;
			v[i].push_back(temp);
			good[i] = 1;
		} else {
			int temp;
			while (num--) {
				cin >> temp;
				v[i].push_back(temp);
			}
		}
	}
	power[0] = z;
	dfs(0);
	cout << (int)sum;

	return 0;
}
