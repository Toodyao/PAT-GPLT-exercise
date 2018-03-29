#include <bits/stdc++.h>
using namespace std;

int par[10010];
int set_rank[10010];

void init(int n) {
	for (int i = 0; i < n; i++) {
		par[i] = i;
		set_rank[i] = 0;
	}
}

int find(int x) {
	if (par[x] == x)
		return x;
	else
		return par[x] = find(par[x]);
}

void unite(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y)
		return;
	if (set_rank[x] < set_rank[y])
		par[x] = y;
	else {
		par[y] = x;
		if (set_rank[x] == set_rank[y])
			set_rank[x]++;
	}
}

bool same(int x, int y) {
	return find(x) == find(y);
}

int main () {
	// freopen("input.txt", "r", stdin);
	int n, q;
	set<int> v;
	cin >> n;
	init(10010);
	while (n--) {
		int k, temp, t;
		cin >> k;
		cin >> temp;
		v.insert(temp);
		k--;
		while (k--) {
			cin >> t;
			unite(temp, t);
			v.insert(t);
		}
	}
	set<int> s;
	int ssize = 0, count = 0;
	for (set<int>::iterator it = v.begin(); it != v.end(); ++it) {
		s.insert(find(*it));
		if (s.size() > ssize) {
			count++;
			ssize = s.size();
		}
	}
	printf("%d %d\n", v.size(), count);
	cin >> q;
	while (q--) {
		int a, b;
		cin >> a >> b;
		printf("%c\n", same(a, b) ? 'Y' : 'N');
	}
	
	return 0;
}