#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
using namespace std;

vector<set<int> > v (60);

int main()
{
	int n, m, temp;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> m;
		while (m--)
		{
			cin >> temp;
			v[i].insert(temp);
		}
	}
	int q, a, b, nc, nt;
	cin >> q;
	while (q--)
	{
		nc = 0; nt = 0;
		cin >> a >> b;
		a--; b--;
		for (set<int>::iterator i = v[a].begin(); i != v[a].end(); i++)
			if (v[b].count(*i))
				nc++;
		nt = v[a].size() + v[b].size() - nc;
		printf("%.2lf%%\n", (1.0 * nc / nt) * 100);
	}

	return 0;
}