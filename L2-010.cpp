#include <iostream>
#include <cstdio>
using namespace std;

int par[110];
int set_rank[110];
int arr[110][110]; // save relationships

void init(int n)
{
	for (int i = 0; i < n; i++)
	{
		par[i] = i;
		set_rank[i] = 0;
	}
}

int find(int x)
{
	if (par[x] == x)
		return x;
	else
		return par[x] = find(par[x]);
}

void unite(int x, int y)
{
	x = find(x);
	y = find(y);

	if (x == y)
		return;

	if (set_rank[x] < set_rank[y])
		par[x] = y;
	else
	{
		par[y] = x;
		if (set_rank[x] == set_rank[y])
			set_rank[x]++;
	}
}

bool same(int x, int y)
{
	return find(x) == find(y);
}

int main()
{
	// freopen("input.txt", "r", stdin);
	int n, m, k;
	cin >> n >> m >> k;
	init(n);
	while (m--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (c == 1)
			unite(a, b);
		arr[a][b] = arr[b][a] = c;
	}
	while (k--)
	{
		int a, b;
		cin >> a >> b;
		if (arr[a][b] == 1)
			printf("No problem\n");
		else if (arr[a][b] == 0)
			printf("OK\n");
		else if (same(a, b) && arr[a][b] == -1)
			printf("OK but...\n");
		else if (!same(a, b) && arr[a][b] == -1)
			printf("No way\n");
	}

	return 0;
}