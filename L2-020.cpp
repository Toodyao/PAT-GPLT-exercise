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
	if (good[n] == 1)
		sum += power[n] * v[n][0];
	for (size_t i = 0; i < v[n].size(); i++) {
		// printf("%d\n", v[n][i]);
		if (good[v[n][i]] == 1) {
			power[v[n][i]] = power[n] * v[v[n][i]][0] * (1.0 - r / 100.0);
			// printf("%d %lf %d\n", n, power[n] , v[v[n][i]][0]);
			sum += power[v[n][i]];
			continue;
		} else {
			power[v[n][i]] = power[n] * (1.0 - r / 100.0);
			dfs(v[n][i]);
		}
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
	// for (int i = 0; i < n; i++) {
	// 	for (size_t ii = 0; ii < v[i].size(); ii++) {
	// 		cout << v[i][ii] << " ";
	// 	}
	// 	cout << endl;
	// }
	// for (int i = 0; i < n; i++) {
	// 	printf("%d ", good[i]);
	// }
	// printf("\n");
	power[0] = z;
	dfs(0);
	cout << (int)sum;

	return 0;
}
