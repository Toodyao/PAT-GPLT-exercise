#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

struct node {
	int num = -1;
	char sex;
	int fa = -1, mo = -1;
	node() {}
	node(int n, char s, int f, int m)
		: num(n), sex(s), fa(f), mo(m) {}
};
vector<node> v(100010);
int gender[100010];
bool visit[100010];

int n, q, flag;

void dfs(int a, int count) {
	if (count == 5 || a == -1)
		return;
	visit[a] = true;
	dfs(v[a].fa, count + 1);
	dfs(v[a].mo, count + 1);
}

void check(int b, int count) {
	if (count == 5 || b == -1)
		return;

	if (visit[b] == true) {
		flag = -1;
		return;
	}

	check(v[b].fa, count + 1);
	check(v[b].mo, count + 1);
}

int main() {
	// freopen("input.txt", "r", stdin);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num, f, m;
		char s;
		cin >> num >> s >> f >> m;
		v[num] = node(num, s, f, m);
		gender[num] = s == 'M' ? 1 : 2;
		gender[f] = 1;
		gender[m] = 2;
	}
	cin >> q;
	while (q--) {
		int a, b;
		cin >> a >> b;
		if (gender[a] == gender[b]) {
			printf("Never Mind\n");
			continue;
		}
		flag = 0;
		fill(visit, visit + 100010, false);
		dfs(a, 0);
		check(b, 0);
		if (flag == 0)
			printf("Yes\n");
		else if (flag == -1)
			printf("No\n");
	}

	return 0;
}
